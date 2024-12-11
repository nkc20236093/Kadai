#include "DxLib.h"
#include <list>
#include <random>
#include <string>
#include <windows.h>
using namespace std;

// �񋓑�
enum CharNo { CrossBow, One, Five, Back, Bow, Num };
// �f�[�^�ǂ݂��ݗp�̃p�X�̔z��
static const char* filePathTable[CharNo::Num] =
{
	"sprite/crossbow.png",
	"sprite/1ten_mato.png",
	"sprite/5ten_mato.png",
	"sprite/back.jpg",
	"sprite/bow.png"
};

// �O���錾
class Object;
class Player;
class PLShell;
void HitControl(Object* pl, Object* em);

// �I�u�W�F�N�g�N���X�̃|�C���^�̃��X�g
std::list<Object*> objList;
// �O���t�B�b�N�n���h���e�[�u��
int gHandleTable[CharNo::Num];
int HitPoint = 0;

// �I�u�W�F�N�g�N���X�i���j
class Object {
private:
	int gHandle;					// �O���t�B�b�N�n���h��
	int x = 0, y = 0;				// ���W
	int cx = 0, cy = 0;				// ��]�̌��ƂȂ���W
	double sclX = 1.0, sclY = 1.0;	// �g�嗦
	double radian = 0;				// ��]�l
	bool turnFlag = false;			// ���]�t���O
	bool deleteFlag = false;		// �����p�t���O
public: // �q�b�g�֘A�����Ŏ����i�ʓ|�Ȃ̂�public)
	// �q�b�g�p���A����
	int hitWide = 180, hitHeight = 180;
	bool hitAbleFlag = false;	// �q�b�g�\�t���O
	int hitType;				// �����蔻��̃^�C�v(0:�v���C���[,1���G�j
	int score = 0;
	// �R���X�g���N�^
	Object(int _gHandle) : gHandle(_gHandle) {}
	// �A�N�Z�T
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
	// �`�揈��
	void Draw() {
		// ��]�g��Ή��`��
		DrawRotaGraph3(x, y,
			cx, cy, sclX, sclY, radian,
			gHandle, TRUE, turnFlag);
	}
	// �q�b�g�p�̋�`�`��
	void DebugHitDraw() {
		// �q�b�g�m�F�p��`�`��
		int lx, rx, uy, dy;
		lx = getX(); rx = lx + hitWide;
		uy = getY(); dy = uy + hitHeight;
		DrawBox(lx, uy, rx, dy,
			GetColor(255, 0, 0),
			TRUE);
	}

	// �X�V�����i���z�֐��j
	virtual void Update() {}
};

// �v���C���[�e�N���X
class PLShell : public Object {
public:
	// �R���X�g���N�^
	PLShell(int _gHandle) : Object(_gHandle) {
		hitWide = 40; hitHeight = 40;
		hitAbleFlag = true;	// �L��
		hitType = 0;		// �v���C���[
	}
	// �A�b�v�f�[�g�֐��I�[�o�[���C�h
	void Update() {
		// ��Ɉړ�
		setY(getY() - 10);
		// ��ʏ㕔�֍s����������鏈��
		if (getY() < -100) {	// -100��聪�̍��W�ɍs�����������
			// ������
			setDeleteFlag();		// �����t���O�I��
			return;					// ����ȏ�̏����͍s��Ȃ�
		}

		DebugHitDraw();
	}
};

// �v���C���[�N���X	
class Player : public Object {
	bool sButtonFlag = false;	// ���˃{�^���p�t���O
	float timer = 10;
public:
	// �R���X�g���N�^
	Player(int _gHandle) : Object(_gHandle) {
		//		setCX(175); setCY(175);
	}
	// �A�b�v�f�[�g�֐��I�[�o�[���C�h
	void Update() {
		// �v���C���[�̑���
		if (CheckHitKey(KEY_INPUT_UP)) { setY(getY() - 8); }
		if (CheckHitKey(KEY_INPUT_DOWN)) { setY(getY() + 8); }
		if (CheckHitKey(KEY_INPUT_LEFT)) {
			setX(getX() - 8); setTurnFlag(true);
		}
		if (CheckHitKey(KEY_INPUT_RIGHT)) {
			setX(getX() + 8); setTurnFlag(false);
		}
		// �g��k���̃`�F�b�N
		//if (CheckHitKey(KEY_INPUT_UP)) { setSclY(getSclY() - 0.1); }
		//if (CheckHitKey(KEY_INPUT_DOWN)) { setSclY(getSclY() + 0.1); }
		//if (CheckHitKey(KEY_INPUT_LEFT)) { setSclX(getSclX() - 0.1); }
		//if (CheckHitKey(KEY_INPUT_RIGHT)) { setSclX(getSclX() + 0.1); }
		// ��]�̃`�F�b�N
		double rad = 2 * 3.14 / 180;	// �f�B�O���[�����W�A���ɕϊ��i2�x�j
		if (CheckHitKey(KEY_INPUT_Q)) { setRadian(getRadian() - rad); }
		if (CheckHitKey(KEY_INPUT_E)) { setRadian(getRadian() + rad); }

		// Z�L�[���͂Œe�𔭎�
		if (timer > 30)
		{
			if (CheckHitKey(KEY_INPUT_Z)) {
				// ���˃{�^��������ɉ����ꂽ�Ƃ�
				if (sButtonFlag == false) {
					// �e�N���X�𐶐��inew�����ă|�C���^���擾�j
					auto ptr = new PLShell(gHandleTable[CharNo::Bow]);
					ptr->setX(this->getX());
					ptr->setY(this->getY());
					ptr->setSclX(0.1f);
					ptr->setSclY(0.1f);
					objList.push_back(ptr);
					timer = 0;
				}
				sButtonFlag = true;	// ���˃{�^���������ꂽ
			}
			else {// Z�L�[��������Ă��Ȃ��Ƃ�
				sButtonFlag = false;
			}
		}
		else {// Z�L�[��������Ă��Ȃ��Ƃ�
			++timer;
		}
	}
};

// �G�N���X
class Enemy : public Object {
	int moveType = 0;		// �ړ��^�C�v
public:
	// �R���X�g���N�^
	Enemy(int _gHandle, int mType) :
		Object(_gHandle), moveType(mType)
	{
		hitAbleFlag = true;	// �L��
		hitType = 1;		// �G
	}
	// �A�b�v�f�[�g�̃I�[�o�[���C�h
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

		// ��ʊO�ŏ�����
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

// �G�����N���X
class EnemyGenerator {
	float timer = 0;
	int MaxY = 0, MinY = 300, SecondY = 100, ThirdY = 200;
	int randomValueX = 0, randomValueY = 0;
public:
	EnemyGenerator() {}		// �R���X�g���N�^
	// �X�V����
	void Update() {
		++timer;
		if (timer > 60) 
		{	// 60�t���[����
			// �G���N��
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
			// ����������ƕ��z��ݒ�
			std::random_device rd;  // �񌈒�I�ȗ���������
			std::mt19937 gen(rd()); // �����Z���k�E�c�C�X�^
			std::uniform_int_distribution<> dis(0, 3); // 0�܂���1�̈�l���z

			int randomIndexY = dis(gen); // 0, 1, 2, 3 �̂����ꂩ�𐶐�

			switch (randomIndexY) 
			{
			case 0: randomValueY = MaxY; break;
			case 1: randomValueY = SecondY; break;
			case 2: randomValueY = ThirdY; break;
			case 3: randomValueY = MinY; break;
			}			

			std::random_device rdB;  // �񌈒�I�ȗ���������
			std::mt19937 genB(rdB()); // �����Z���k�E�c�C�X�^
			std::uniform_int_distribution<> disB(0, 1); // 0�܂���1�̈�l���z
			int randomIndexX = disB(genB); // 0, 1�̂ǂ��炩�𐶐�

			switch (randomIndexX)
			{
			case 0: randomValueX = 0; break;
			case 1: randomValueX = 1100; break;
			}

			ptr->setX(randomValueX);	// x���W�������_��
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
			objList.push_back(ptr);		// ���X�g�ɓo�^
			timer = 0;					// �^�C�}�[������
		}
	}
};

// �Q�[�����[�h�i�J�n��ʁA�Q�[�����A�I���j
enum GameState { StartScreen, InGame, GameOver };
GameState currentState = StartScreen;  // ���݂̃Q�[����Ԃ��Ǘ�

// �Q�[���^�C�}�[
int gameStartTime = 0;  // �Q�[���J�n���̎��ԁi�~���b�j

int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	SetGraphMode(1280, 720, 32);  // ��ʃ��[�h�̐ݒ�
	ChangeWindowMode(TRUE);       // �E�B���h�E���[�h�ɕύX
	if (DxLib_Init() == -1) { return -1; }  // DX���C�u�����������i���s������I���j
	SetDrawScreen(DX_SCREEN_BACK);          // �`���𗠉�ʂɁi�_�u���o�b�t�@�����O�j

	// �O���t�B�b�N���������֓ǂݍ���
	for (int i = 0; i < CharNo::Num; ++i) {
		gHandleTable[i] = LoadGraph(filePathTable[i]);
	}

	// �N���X�̎��̍쐬
	Player pl = Player(gHandleTable[CharNo::CrossBow]);
	pl.setX(400); pl.setY(600); pl.setSclX(0.5); pl.setSclY(0.5);
	Object back = Object(gHandleTable[CharNo::Back]);
	back.setX(0); back.setY(0); back.setSclX(0.4); back.setSclY(0.3);
	objList.push_back(&back);
	objList.push_back(&pl);

	EnemyGenerator emGene; // �G�̐����N���X�쐬

	// �t�H���g�n���h�����Q�[���J�n���ɍ쐬
	int fontHandle = CreateFontToHandle(NULL, 200, -1, DX_FONTTYPE_ANTIALIASING);
	int fontHandle2 = CreateFontToHandle(NULL, 50, -1, DX_FONTTYPE_ANTIALIASING);

	// �Q�[�����[�v
	while (true) {
		ClearDrawScreen();  // ��ʂ���x����

		// �J�n��ʏ���
		if (currentState == StartScreen) {
			// �J�n��ʂ̕\��
			DrawString(500, 300, "Press SPACE to Start", GetColor(255, 255, 255));
			ScreenFlip();

			// �X�y�[�X�L�[�ŃQ�[���J�n
			if (CheckHitKey(KEY_INPUT_SPACE)) {
				currentState = InGame;
				gameStartTime = GetNowCount();  // �Q�[���J�n���̎��Ԃ��L�^
			}
			continue;
		}

		// �Q�[�����̏���
		if (currentState == InGame) {
			// 60�b�o�߂ŃQ�[���I��
			int elapsedTime = GetNowCount() - gameStartTime;
			if (elapsedTime > 60000) {  // 60�b�o��
				currentState = GameOver;
				continue;
			}

			// �G��������
			emGene.Update();

			// ���X�g���g�����X�V����
			for (auto iObj = objList.begin(); iObj != objList.end(); ) {
				(*iObj)->Update();

				// �A�b�v�f�[�g�ŏ����t���O��ON�ɂȂ������`�F�b�N
				if ((*iObj)->getDeleteFlag() == true) {
					delete* iObj;  // ����������폜
					iObj = objList.erase(iObj);
				}
				else {
					++iObj;
				}
			}

			// �`�揈��
			for (auto iObj = objList.begin(); iObj != objList.end(); ++iObj) {
				(*iObj)->Draw();
			}

			// �q�b�g����`�F�b�N
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

			// �q�b�g����
			for (auto pltr = plHitList.begin(); pltr != plHitList.end(); ++pltr) {
				for (auto eItr = emHitList.begin(); eItr != emHitList.end(); ++eItr) {
					HitControl(*pltr, *eItr);
				}
			}

			// �X�R�A�`��
			string text = to_string(HitPoint);
			DrawStringToHandle(620, 500, text.c_str(), GetColor(255, 0, 255), fontHandle);

			// �c�莞�ԕ\��
			string timeLeft = "Time: " + to_string(60 - elapsedTime / 1000) + "s";
			//DrawString(50, 20, timeLeft.c_str(), GetColor(0, 0, 255));
			DrawStringToHandle(50, 20, timeLeft.c_str(), GetColor(0, 0, 255), fontHandle2);

			ScreenFlip();  // ����ʂ�\�ɕ\���i�_�u���o�b�t�@�����O�j
			WaitTimer(20); // �ҋ@�i20ms�҂j
			if (ProcessMessage() == -1) { break; }  // X�{�^���ŏI��
			if (CheckHitKey(KEY_INPUT_ESCAPE)) { break; }  // ESC�L�[�ŏI��
		}

		// �Q�[���I�[�o�[��ʏ���
		if (currentState == GameOver) {
			ClearDrawScreen();
			DrawString(500, 300, ("Your Score: " + to_string(HitPoint)).c_str(), GetColor(255, 255, 255));
			DrawString(500, 400, "Press ESC to Exit", GetColor(255, 255, 255));
			ScreenFlip();

			// ESC�L�[�ŏI��
			if (CheckHitKey(KEY_INPUT_ESCAPE)) { break; }
		}
	}

	DxLib_End();  // DX���C�u�����I��
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
		// PL�E���G�����傫�����APL�����G�E��菬����
		if (plxr > emxl && plxl < emxr && plyd > emyu && plyu < emyd)
		{
			HitPoint += em->score;
			em->setDeleteFlag();
			pl->setDeleteFlag();
			//DrawFormatString(0, 80, GetColor(255, 255, 255),"�����蔻��͐���");
		}
	}
}