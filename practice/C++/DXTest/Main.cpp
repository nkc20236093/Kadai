#include "DxLib.h"
#include <list>

class Object;

// オブジェクトクラスのリスト
std::list<Object*> objList;
// 列挙体
enum CharaNo
{
    Luffy, Zoro, Enel, Back, Shell, Num
};
// グラフィックハンドルテーブル
int gHandleTable[CharaNo::Num];

class Object
{
    int x = 0, y = 0, gHandle;      // 座標、グラフィックハンドル
    int cx = 0, cy = 0;             // 回転の元となる座標
    double sclX = 1.0, sclY = 1.0;  // 拡大率
    double radian = 0;              // 回転率
    bool turnflag = false;          // 反転フラグ
    bool deleteFlag = false;        // 消去型フラグ
public:
    int hWide = 200, hHeight = 200; // ヒット用幅、高さ
    bool hitAbleFlag = false;       // ヒット可能フラグ
    int hitType;                    // 当たり判定のタイプ(0:プレイヤー,1;敵)

    // コンストラクタ
    Object(int _gHandle) :x(0), y(0), gHandle(_gHandle) {}
    // アクセサ
    void SetX(int value) { x = value; }
    int GetX() { return x; }
    void SetY(int value) { y = value; }
    int GetY() { return y; }
    int GetgHandle() { return gHandle; }
    void SetCX(int value) { cx = value; }
    void SetCY(int value) { cy = value; }
    void SetSclX(double value) { sclX = value; }double GetSclX() { return sclX; }
    void SetSclY(double value) { sclY = value; }double GetSclY() { return sclY; }
    void SetRadian(double value) { radian = value; }double GetRadian() { return radian; }
    void SetTurnFlag(bool value) { turnflag = value; }bool GetTurnFlag() { return turnflag; }
    void SetDeleteFlag() { deleteFlag = true; }bool GetDeletFlag() { return deleteFlag; }
    // 描画処理
    void Draw()
    {
        DrawRotaGraph3(x, y, cx, cy, sclX, sclY, radian, gHandle, TRUE, turnflag);
    }
    // 更新処理(仮数関数)
    virtual void Update() {}

    void DebugHitDraw(int h, int w)
    {
        // ヒット確認用短形描画
        int lx, rx, uy, dy;
        lx = GetX(); rx = lx + w;
        uy = GetY(); dy = uy + h;
        DrawBox(lx, uy, rx, dy, GetColor(255, 0, 0), TRUE);
    }
};
// プレイヤー弾クラス
class PLShell :public Object
{
public:
    // コンストラクタ
    PLShell(int _gHandle) : Object(_gHandle) {}
    // アップデート関数オーバーライド
    void Update() {
        SetY(GetY() - 10);
        DebugHitDraw(40, 40);
        hitAbleFlag = true;
        hitType = 0;

        // 画面上部へ行ったら消える処理
        if (GetY() < 100)
        {
            // 自分も消える
            SetDeleteFlag();
            return;
        }
    }
};


class Player :public Object
{
private:
    bool sButtonFlag = false; // 弾発射フラグ
public:
    // コンストラクタ
    Player(int _gHandle) :Object(_gHandle) {}

    // アップデート関数オーバーライド
    void Update()
    {
        // プレイヤーの操作
        if (CheckHitKey(KEY_INPUT_UP)) { SetY(GetY() - 8); }
        if (CheckHitKey(KEY_INPUT_DOWN)) { SetY(GetY() + 8); }
        if (CheckHitKey(KEY_INPUT_LEFT)) { SetX(GetX() - 8); SetTurnFlag(false); }
        if (CheckHitKey(KEY_INPUT_RIGHT)) { SetX(GetX() + 8); SetTurnFlag(true); }

        // 拡大縮小のチェック
        //if (CheckHitKey(KEY_INPUT_UP)) { SetSclY(2.0); }
        //if (CheckHitKey(KEY_INPUT_DOWN)) { SetSclY(1.0); }
        //if (CheckHitKey(KEY_INPUT_LEFT)) { SetSclX(1.0); }
        //if (CheckHitKey(KEY_INPUT_RIGHT)) { SetSclX(2.0); }

        // 回転のチェック
        double rad = 2 * 3.14 / 180; // ディグリーをラジアンに変換(2度)
        if (CheckHitKey(KEY_INPUT_Q)) { SetRadian(GetRadian() - rad); }
        if (CheckHitKey(KEY_INPUT_E)) { SetRadian(GetRadian() + rad); }

        // Zキー入力で弾を発射
        if (CheckHitKey(KEY_INPUT_Z))
        {
            // 発射ボタンが初回に押されたとき
            if (!sButtonFlag)
            {
                auto ptr = new PLShell(gHandleTable[CharaNo::Shell]);
                ptr->SetX(this->GetX());
                ptr->SetY(this->GetY());
                ptr->SetSclX(0.1);
                ptr->SetSclY(0.1);
                objList.push_back(ptr);
            }
            sButtonFlag = true;
        }
        else
        {
            // Zキーが押されてないとき
            sButtonFlag = false;
        }
        DebugHitDraw(200,200);
    }
};

// 敵クラスの作成
class Enemy :public Object
{
    int moveType = 0;
public:
    Enemy(int _gHandle, int mType):Object(_gHandle),moveType(mType)
    {
        hitAbleFlag = true;
        hitType = 1;
    }
    // アップデートのオーバーライド
    void Update()
    {
        switch (moveType)
        {
            case 0: //直線移動
                //SetY(GetY() + 4);
                break;
        }

        // 画面外で消える
        if (GetY() > 500)
        {
            SetDeleteFlag();
            return;
        }
        DebugHitDraw(200, 200);
    }
};

// 敵生成クラス
class EnemyGenerator
{
    float timer = 0;
    //コンストラクタ
public:EnemyGenerator(){}
      // 更新処理
      void Update()
      {
          ++timer;
          // 60フレーム毎
          if (timer < 60)
          {
              // 敵を起動
              int EnemyType = GetRand(1);
              Object* ptr = nullptr;
              switch (EnemyType)
              {
              case 0:
                  ptr = new Enemy(gHandleTable[CharaNo::Enel], 0); break;
              case 1:
                  ptr = new Enemy(gHandleTable[CharaNo::Enel], 0); break;
              }
              // x座標もランダム
              ptr->SetX(GetRand(1280)); // x座標もランダム
              ptr->SetCX(100); ptr->SetCY(100);
              objList.push_back(ptr);   // リストに登録
              timer = 0;                // タイマー初期化
          }
      }
};

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // 画面モードの設定
    SetGraphMode(1280, 720, 32);
    // ウィンドウモードに変更
    ChangeWindowMode(TRUE);

    if (DxLib_Init() == -1)        // ＤＸライブラリ初期化処理
    {
        return -1;            // エラーが起きたら直ちに終了
    }

    // 描画先を裏画面に(ダブルバッファリング)
    SetDrawScreen(DX_SCREEN_BACK);

    // データ読み込み用の配列
    static const char* filePathTable[CharaNo::Num] =
    {
        "sprite/onepiece01_luffy.png",
        "sprite/onepiece02_zoro_bandana.png",
        "sprite/onepiece14_enel.png",
        "sprite/Nyaoha.png",
        "sprite/shell01.png"
    };

    for (int i = 0; i < CharaNo::Num; i++)
    {
        gHandleTable[i] = LoadGraph(filePathTable[i]);
    }
    // グラフィックをメモリへ読み込み
    // 読み込んだ後の識別番号(グラフィックバンドル)として保存
    int graphHandle1 = LoadGraph("sprite/onepiece14_enel.png");

    // クラスの実体作成
    Player pl = Player(gHandleTable[CharaNo::Luffy]); pl.SetX(400); pl.SetY(600); pl.SetCX(100); pl.SetCY(100);
    Object pl2 = Object(gHandleTable[CharaNo::Zoro]); pl2.SetX(200); pl2.SetY(100); pl2.SetSclX(200); pl2.SetCY(200);
    Object em = Object(gHandleTable[CharaNo::Enel]); em.SetX(800); em.SetY(100);
    //Object back = Object(gHandleTable[CharaNo::Back]); back.SetX(0); back.SetY(0);

    // リスト登録
    //objList.push_back(&back);
    objList.push_back(&pl);
    objList.push_back(&pl2);
    //objList.push_back(&em);

    /*
    Object obj // オブジェクトクラス
    Objectクラスの機能を使える

    Player pl; // オブジェクト機能を継承したPL
    PlayerとObjectクラスの機能を使える

    Object test = pl;
    Playerをオブジェクトクラスにキャスト
    testはPlayerの昨日は使えない

    Object* ptr =&pl;
    PlayerのポインタをObjectクラスのポインタにキャスト
    ptrはPlayerを指している
    基底クラスのポインタだけどプレイヤーの機能が使える

    Object* prt2 &pshel;
    ptr2はPLShellを指している
    基底クラスのポインタだけどPLShellの機能が使える
    */

    //int x = 0, y = 0;
    
    EnemyGenerator emGene;

    // ゲームループ
    while (true)
    {
        // 画面を一度消す
        ClearDrawScreen();

        emGene.Update();

        // リストを使った更新処理
        for (auto iObj = objList.begin(); iObj != objList.end();)
        {
            (*iObj)->Update();
            // アップデートで消去フラグがONになったかチェック
            if ((*iObj)->GetDeletFlag())
            {
                // メモリから削除
                delete* iObj;
                // リストから削除して次の要素をイテレータに入れる
                iObj = objList.erase(iObj);
            }
            else
            {
                // 次の要素へ
                ++iObj;
            }
        }

        // リストを使った描画関連(先に描画したやつが優先度低)
        for (auto iObj = objList.begin(); iObj != objList.end(); ++iObj)
        {
            (*iObj)->Draw();
        }

        // ヒットのチェック
        int plNum = 0, emNum = 0;
        Object* emHit = nullptr, * plHit = nullptr;
        for (auto iObj = objList.begin(); iObj != objList.end(); ++iObj)
        {
            // ヒットが有効かチェック
            if ((*iObj)->hitAbleFlag)
            {
                // プレイヤー
                ++plNum;
                plHit = *iObj; // 登録
            }
            else
            {
                // 敵
                ++emNum;
                emHit = *iObj; // 登録
            }
        }
        DrawFormatString(0, 0, GetColor(255, 255, 255), "PLヒットタイプの数%d\n", plNum);
        DrawFormatString(0, 30, GetColor(255, 255, 255), "敵ヒットタイプの数%d\n", emNum);
        // 登録されたヒットの情報を表示
        if (plHit != nullptr)
        {
            DrawFormatString(0, 40, GetColor(255, 255, 255), "登録されたヒットのX座標%d,Y座標%d\n", plHit->GetX(), plHit->GetY());
        }
        if (emHit != nullptr)
        {
            DrawFormatString(0, 50, GetColor(255, 255, 255), "登録されたヒットのX座標%d,Y座標%d\n", emHit->GetX(), emHit->GetY());
        }
        // 実際に当たってるか確認
        if (plHit != nullptr && emHit != nullptr)
        {
            int plxl = plHit->GetX();
            int plxr = plxl + emHit->hHeight;
            int emxl = emHit->GetX();
            int emxr = emxl + emHit->hHeight;
            // PL右が敵左より大きいかつPL左が敵右より小さい
            if (plxr > emxl && plxl < emxr)
            {
                DrawFormatString(0, 60, GetColor(255, 255, 255), "X軸はヒット\n");
            }
        }

        //// 背景も表示
        //DrawGraph(back.GetX(), back.GetY(), gHandleTable[CharaNo::Back], TRUE);
        //// グラフィックハンドルから表示
        //DrawGraph(pl.GetX(), pl.GetY(), gHandleTable[CharaNo::Luffy], TRUE);
        //DrawGraph(pl2.GetX(), pl2.GetY(), gHandleTable[CharaNo::Zoro], TRUE);
        //DrawGraph(em.GetX(), em.GetY(), gHandleTable[CharaNo::Enel], TRUE);

        // 画像読み込みして表示
        //LoadGraphScreen(x, y, "sprite/onepiece14_enel.png", FALSE);
        // 裏画面を表に表示
        ScreenFlip();
        // 待機(20ms待つ)
        WaitTimer(20);
        // Xのボタンが押されたら終了
        if (ProcessMessage() == -1) { break; }
        // ESCキーで終了
        if (CheckHitKey(KEY_INPUT_ESCAPE)) { break; }
    }

    //DrawPixel(320, 240, GetColor(255, 255, 255));    // 点を打つ

    //WaitKey();                // キー入力待ち

    DxLib_End();                // ＤＸライブラリ使用の終了処理

    return 0;                // ソフトの終了 
}