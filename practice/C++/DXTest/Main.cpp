#include "DxLib.h"
#include <list>
#include <random>
#include <string>
#include <windows.h>
using namespace std;

// 列挙体
enum CharNo { CrossBow, One, Five, Back, Bow, Num };
// データ読みこみ用のパスの配列
static const char* filePathTable[CharNo::Num] =
{
	"sprite/crossbow.png",
	"sprite/1ten_mato.png",
	"sprite/5ten_mato.png",
	"sprite/back.jpg",
	"sprite/bow.png"
};

// 前方宣言
class Object;
class Player;
class PLShell;
void HitControl(Object* pl, Object* em);

// オブジェクトクラスのポインタのリスト
std::list<Object*> objList;
// グラフィックハンドルテーブル
int gHandleTable[CharNo::Num];
int HitPoint = 0;

// オブジェクトクラス（基底）
class Object {
private:
	int gHandle;					// グラフィックハンドル
	int x = 0, y = 0;				// 座標
	int cx = 0, cy = 0;				// 回転の元となる座標
	double sclX = 1.0, sclY = 1.0;	// 拡大率
	double radian = 0;				// 回転値
	bool turnFlag = false;			// 反転フラグ
	bool deleteFlag = false;		// 消去用フラグ
public: // ヒット関連を仮で実装（面倒なのでpublic)
	// ヒット用幅、高さ
	int hitWide = 180, hitHeight = 180;
	bool hitAbleFlag = false;	// ヒット可能フラグ
	int hitType;				// 当たり判定のタイプ(0:プレイヤー,1が敵）
	int score = 0;
	// コンストラクタ
	Object(int _gHandle) : gHandle(_gHandle) {}
	// アクセサ
	int getGHandle() { return gHandle; }
	void setX(int value) { x = value; } int getX() { return x; }
	void setY(int value) { y = value; } int getY() { return y; }
	void setCX(int value) { cx = value; }
	void setCY(int value) { cy = value; }
	void setSclX(double value) { sclX = value; } double getSclX() { return sclX; }
	void setSclY(double value) { sclY = value; } double getSclY() { return sclY; }
	void setRadian(double value) { radian = value; } double getRadian() { return radian; }
	void setTurnFlag(bool value) { turnFlag = value; } bool getTrunFlag() { return turnFlag; }
	void setDeleteFlag() { deleteFlag = true; }
	bool getDeleteFlag() { return deleteFlag; }
	// 描画処理
	void Draw() {
		// 回転拡大対応描画
		DrawRotaGraph3(x, y,
			cx, cy, sclX, sclY, radian,
			gHandle, TRUE, turnFlag);
	}
	// ヒット用の矩形描画
	void DebugHitDraw() {
		// ヒット確認用矩形描画
		int lx, rx, uy, dy;
		lx = getX(); rx = lx + hitWide;
		uy = getY(); dy = uy + hitHeight;
		DrawBox(lx, uy, rx, dy,
			GetColor(255, 0, 0),
			TRUE);
	}

	// 更新処理（仮想関数）
	virtual void Update() {}
};

// プレイヤー弾クラス
class PLShell : public Object {
public:
	// コンストラクタ
	PLShell(int _gHandle) : Object(_gHandle) {
		hitWide = 40; hitHeight = 40;
		hitAbleFlag = true;	// 有効
		hitType = 0;		// プレイヤー
	}
	// アップデート関数オーバーライド
	void Update() {
		// 上に移動
		setY(getY() - 10);
		// 画面上部へ行ったら消える処理
		if (getY() < -100) {	// -100より↑の座標に行ったら消える
			// 消える
			setDeleteFlag();		// 消去フラグオン
			return;					// これ以上の処理は行わない
		}

		DebugHitDraw();
	}
};

// プレイヤークラス	
class Player : public Object {
	bool sButtonFlag = false;	// 発射ボタン用フラグ
	float timer = 10;
public:
	// コンストラクタ
	Player(int _gHandle) : Object(_gHandle) {
		//		setCX(175); setCY(175);
	}
	// アップデート関数オーバーライド
	void Update() {
		// プレイヤーの操作
		if (CheckHitKey(KEY_INPUT_UP)) { setY(getY() - 8); }
		if (CheckHitKey(KEY_INPUT_DOWN)) { setY(getY() + 8); }
		if (CheckHitKey(KEY_INPUT_LEFT)) {
			setX(getX() - 8); setTurnFlag(true);
		}
		if (CheckHitKey(KEY_INPUT_RIGHT)) {
			setX(getX() + 8); setTurnFlag(false);
		}
		// 拡大縮小のチェック
		//if (CheckHitKey(KEY_INPUT_UP)) { setSclY(getSclY() - 0.1); }
		//if (CheckHitKey(KEY_INPUT_DOWN)) { setSclY(getSclY() + 0.1); }
		//if (CheckHitKey(KEY_INPUT_LEFT)) { setSclX(getSclX() - 0.1); }
		//if (CheckHitKey(KEY_INPUT_RIGHT)) { setSclX(getSclX() + 0.1); }
		// 回転のチェック
		double rad = 2 * 3.14 / 180;	// ディグリーをラジアンに変換（2度）
		if (CheckHitKey(KEY_INPUT_Q)) { setRadian(getRadian() - rad); }
		if (CheckHitKey(KEY_INPUT_E)) { setRadian(getRadian() + rad); }

		// Zキー入力で弾を発射
		if (timer > 30)
		{
			if (CheckHitKey(KEY_INPUT_Z)) {
				// 発射ボタンが初回に押されたとき
				if (sButtonFlag == false) {
					// 弾クラスを生成（newをしてポインタを取得）
					auto ptr = new PLShell(gHandleTable[CharNo::Bow]);
					ptr->setX(this->getX());
					ptr->setY(this->getY());
					ptr->setSclX(0.1f);
					ptr->setSclY(0.1f);
					objList.push_back(ptr);
					timer = 0;
				}
				sButtonFlag = true;	// 発射ボタンが押された
			}
			else {// Zキーが押されていないとき
				sButtonFlag = false;
			}
		}
		else {// Zキーが押されていないとき
			++timer;
		}
	}
};

// 敵クラス
class Enemy : public Object {
	int moveType = 0;		// 移動タイプ
public:
	// コンストラクタ
	Enemy(int _gHandle, int mType) :
		Object(_gHandle), moveType(mType)
	{
		hitAbleFlag = true;	// 有効
		hitType = 1;		// 敵
	}
	// アップデートのオーバーライド
	void Update() {
		switch (moveType) {
		case 0:
			score = 1;
			if (getTrunFlag())
			{
				if (getX() >= 0)
				{
					setX(getX() - 5);
				}
				else
				{
					setDeleteFlag(); break;
				}
			}
			else
			{
				if (getX() <= 1100)
				{
					setX(getX() + 5);
				}
				else
				{
					setDeleteFlag(); break;
				}
			}
			break;
		case 1:
			score = 5;
			if (getTrunFlag())
			{
				if (getX() <= 1100)
				{
					setX(getX() - 15);
				}
				else
				{
					setDeleteFlag(); break;
				}
			}
			else
			{
				if (getX() >= 0)
				{
					setX(getX() + 15);
				}
				else
				{
					setDeleteFlag(); break;
				}
			}
			break;
		}

		// 画面外で消える
		if (getY() > 800) {
			setDeleteFlag(); return;
		}

		DebugHitDraw();
	}
	int GetMoveType()
	{
		return moveType;
	}
};

// 敵生成クラス
class EnemyGenerator {
	float timer = 0;
	int MaxY = 0, MinY = 300, SecondY = 100, ThirdY = 200;
	int randomValueX = 0, randomValueY = 0;
public:
	EnemyGenerator() {}		// コンストラクタ
	// 更新処理
	void Update() {
		++timer;
		if (timer > 60) 
		{	// 60フレーム毎
			// 敵を起動
			int EnemyType = GetRand(1);
			int EnemyDirection = GetRand(1);
			Object* ptr = nullptr;
			switch (EnemyType) {
			case 0:
				ptr = new Enemy(gHandleTable[CharNo::One], 0);
				break;
			case 1:
				ptr = new Enemy(gHandleTable[CharNo::Five], 1);
				break;
			}
			// 乱数生成器と分布を設定
			std::random_device rd;  // 非決定的な乱数生成器
			std::mt19937 gen(rd()); // メルセンヌ・ツイスタ
			std::uniform_int_distribution<> dis(0, 3); // 0または1の一様分布

			int randomIndexY = dis(gen); // 0, 1, 2, 3 のいずれかを生成

			switch (randomIndexY) 
			{
			case 0: randomValueY = MaxY; break;
			case 1: randomValueY = SecondY; break;
			case 2: randomValueY = ThirdY; break;
			case 3: randomValueY = MinY; break;
			}			

			std::random_device rdB;  // 非決定的な乱数生成器
			std::mt19937 genB(rdB()); // メルセンヌ・ツイスタ
			std::uniform_int_distribution<> disB(0, 1); // 0または1の一様分布
			int randomIndexX = disB(genB); // 0, 1のどちらかを生成

			switch (randomIndexX)
			{
			case 0: randomValueX = 0; break;
			case 1: randomValueX = 1100; break;
			}

			ptr->setX(randomValueX);	// x座標もランダム
			if (randomValueX == 0)
			{
				ptr->setTurnFlag(false);
			}
			else
			{
				ptr->setTurnFlag(true);
			}
			ptr->setY(randomValueY);
			ptr->setSclX(0.5f);
			ptr->setSclY(0.5f);
			objList.push_back(ptr);		// リストに登録
			timer = 0;					// タイマー初期化
		}
	}
};

// ゲームモード（開始画面、ゲーム中、終了）
enum GameState { StartScreen, InGame, GameOver };
GameState currentState = StartScreen;  // 現在のゲーム状態を管理

// ゲームタイマー
int gameStartTime = 0;  // ゲーム開始時の時間（ミリ秒）

int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	SetGraphMode(1280, 720, 32);  // 画面モードの設定
	ChangeWindowMode(TRUE);       // ウィンドウモードに変更
	if (DxLib_Init() == -1) { return -1; }  // DXライブラリ初期化（失敗したら終了）
	SetDrawScreen(DX_SCREEN_BACK);          // 描画先を裏画面に（ダブルバッファリング）

	// グラフィックをメモリへ読み込み
	for (int i = 0; i < CharNo::Num; ++i) {
		gHandleTable[i] = LoadGraph(filePathTable[i]);
	}

	// クラスの実体作成
	Player pl = Player(gHandleTable[CharNo::CrossBow]);
	pl.setX(400); pl.setY(600); pl.setSclX(0.5); pl.setSclY(0.5);
	Object back = Object(gHandleTable[CharNo::Back]);
	back.setX(0); back.setY(0); back.setSclX(0.4); back.setSclY(0.3);
	objList.push_back(&back);
	objList.push_back(&pl);

	EnemyGenerator emGene; // 敵の生成クラス作成

	// フォントハンドルをゲーム開始時に作成
	int fontHandle = CreateFontToHandle(NULL, 200, -1, DX_FONTTYPE_ANTIALIASING);
	int fontHandle2 = CreateFontToHandle(NULL, 50, -1, DX_FONTTYPE_ANTIALIASING);

	// ゲームループ
	while (true) {
		ClearDrawScreen();  // 画面を一度消す

		// 開始画面処理
		if (currentState == StartScreen) {
			// 開始画面の表示
			DrawString(500, 300, "Press SPACE to Start", GetColor(255, 255, 255));
			ScreenFlip();

			// スペースキーでゲーム開始
			if (CheckHitKey(KEY_INPUT_SPACE)) {
				currentState = InGame;
				gameStartTime = GetNowCount();  // ゲーム開始時の時間を記録
			}
			continue;
		}

		// ゲーム中の処理
		if (currentState == InGame) {
			// 60秒経過でゲーム終了
			int elapsedTime = GetNowCount() - gameStartTime;
			if (elapsedTime > 60000) {  // 60秒経過
				currentState = GameOver;
				continue;
			}

			// 敵生成処理
			emGene.Update();

			// リストを使った更新処理
			for (auto iObj = objList.begin(); iObj != objList.end(); ) {
				(*iObj)->Update();

				// アップデートで消去フラグがONになったかチェック
				if ((*iObj)->getDeleteFlag() == true) {
					delete* iObj;  // メモリから削除
					iObj = objList.erase(iObj);
				}
				else {
					++iObj;
				}
			}

			// 描画処理
			for (auto iObj = objList.begin(); iObj != objList.end(); ++iObj) {
				(*iObj)->Draw();
			}

			// ヒット判定チェック
			std::list<Object*> plHitList;
			std::list<Object*> emHitList;
			for (auto iObj = objList.begin(); iObj != objList.end(); ++iObj) {
				if ((*iObj)->hitAbleFlag == true) {
					if ((*iObj)->hitType == 0) {
						plHitList.push_back(*iObj);
					}
					else {
						emHitList.push_back(*iObj);
					}
				}
			}

			// ヒット判定
			for (auto pltr = plHitList.begin(); pltr != plHitList.end(); ++pltr) {
				for (auto eItr = emHitList.begin(); eItr != emHitList.end(); ++eItr) {
					HitControl(*pltr, *eItr);
				}
			}

			// スコア描画
			string text = to_string(HitPoint);
			DrawStringToHandle(620, 500, text.c_str(), GetColor(255, 0, 255), fontHandle);

			// 残り時間表示
			string timeLeft = "Time: " + to_string(60 - elapsedTime / 1000) + "s";
			//DrawString(50, 20, timeLeft.c_str(), GetColor(0, 0, 255));
			DrawStringToHandle(50, 20, timeLeft.c_str(), GetColor(0, 0, 255), fontHandle2);

			ScreenFlip();  // 裏画面を表に表示（ダブルバッファリング）
			WaitTimer(20); // 待機（20ms待つ）
			if (ProcessMessage() == -1) { break; }  // Xボタンで終了
			if (CheckHitKey(KEY_INPUT_ESCAPE)) { break; }  // ESCキーで終了
		}

		// ゲームオーバー画面処理
		if (currentState == GameOver) {
			ClearDrawScreen();
			DrawString(500, 300, ("Your Score: " + to_string(HitPoint)).c_str(), GetColor(255, 255, 255));
			DrawString(500, 400, "Press ESC to Exit", GetColor(255, 255, 255));
			ScreenFlip();

			// ESCキーで終了
			if (CheckHitKey(KEY_INPUT_ESCAPE)) { break; }
		}
	}

	DxLib_End();  // DXライブラリ終了
}


void HitControl(Object* pl, Object* em)
{
	if (pl != nullptr && em != nullptr) {
		int plxl = pl->getX();
		int plxr = plxl + pl->hitWide;
		int emxl = em->getX();
		int emxr = emxl + em->hitWide;
		int plyu = pl->getY();
		int plyd = plyu + pl->hitHeight;
		int emyu = em->getY();
		int emyd = emyu + pl->hitHeight;
		// PL右が敵左より大きいかつ、PL左が敵右より小さい
		if (plxr > emxl && plxl < emxr && plyd > emyu && plyu < emyd)
		{
			HitPoint += em->score;
			em->setDeleteFlag();
			pl->setDeleteFlag();
			//DrawFormatString(0, 80, GetColor(255, 255, 255),"当たり判定は成功");
		}
	}
}