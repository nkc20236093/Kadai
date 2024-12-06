#include "DxLib.h"
#include <list>
#include <random>
#include <string>
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
			if (getX() >= 0)
			{
				setX(getX() + 5);
			}
			break;
		case 1:
			score = 5;
			if (getX() <= 1100)
			{
				setX(getX() - 15);
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
			Object* ptr = nullptr;
			switch (EnemyType) {
			case 0:
				ptr = new Enemy(gHandleTable[CharNo::One], 0);
				randomValueX = 0;
				break;
			case 1:
				ptr = new Enemy(gHandleTable[CharNo::Five], 1);
				randomValueX = 1100;
				break;
			}
			// ����������ƕ��z��ݒ�
			std::random_device rd;  // �񌈒�I�ȗ���������
			std::mt19937 gen(rd()); // �����Z���k�E�c�C�X�^
			std::uniform_int_distribution<> dis(0, 3); // 0�܂���1�̈�l���z

			int randomIndex = dis(gen); // 0, 1, 2, 3 �̂����ꂩ�𐶐�

			switch (randomIndex) 
			{
			case 0: randomValueY = MaxY; break;
			case 1: randomValueY = SecondY; break;
			case 2: randomValueY = ThirdY; break;
			case 3: randomValueY = MinY; break;
			}			
			ptr->setX(randomValueX);	// x���W�������_��
			ptr->setY(randomValueY);
			ptr->setSclX(0.5f);
			ptr->setSclY(0.5f);
			objList.push_back(ptr);		// ���X�g�ɓo�^
			timer = 0;					// �^�C�}�[������
		}
	}
};



// �E�B���h�E�Y�A�v���P�[�V�����p�̃��C���֐�
int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	SetGraphMode(1280, 720, 32);// ��ʃ��[�h�̐ݒ�
	ChangeWindowMode(TRUE);		// �E�B���h�E���[�h�ɕύX
	// DX���C�u�����������i���s������I���j
	if (DxLib_Init() == -1) { return -1; }
	// �`���𗠉�ʂɁi�_�u���o�b�t�@�����O�j
	SetDrawScreen(DX_SCREEN_BACK);

	// �O���t�B�b�N���������֓ǂݍ���
	// �ǂݍ��񂾌�̎��ʔԍ��i�O���t�B�b�N�n���h���j�Ƃ��ĕۑ�
	for (int i = 0; i < CharNo::Num; ++i) {
		gHandleTable[i] = LoadGraph(filePathTable[i]);
	}

	// �N���X�̎��̍쐬
	//Object bg = Object(gHandleTable[CharNo::Bg1]);
	//objList.push_back(&bg);

	Player pl = Player(gHandleTable[CharNo::CrossBow]);
	pl.setX(400); pl.setY(600); pl.setSclX(0.5); pl.setSclY(0.5);
	Object back = Object(gHandleTable[CharNo::Back]);
	back.setX(0); back.setY(0); back.setSclX(0.4); back.setSclY(0.3);
	objList.push_back(&back);
	objList.push_back(&pl);
	// �G�̐����N���X�쐬
	EnemyGenerator emGene;

	/*
		Object obj;	 // �I�u�W�F�N�g�N���X
		Object�N���X�̋@�\���g����

		Player pl; �@// �I�u�W�F�N�g���p������PL
		Player��Object�N���X�̋@�\���g����

		Object test = pl;
		Player��Object�N���X�ɃL���X�g
		test��Player�̋@�\�͎g���Ȃ�

		Object* ptr = &pl;
		Player�̃|�C���^��Object�N���X�̃|�C���^�ɃL���X�g
		ptr��Player���w���Ă���
		���N���X�̃|�C���^�����ǁA�v���C���[�̋@�\���g����

		Object* ptr2 = &pshl;
		ptr2��PLShell���w���Ă���
		���N���X�̃|�C���^�����ǁA�e�̋@�\���g����
	*/


	// �Q�[�����[�v
	while (true) {
		ClearDrawScreen();		// ��ʂ���x����
		emGene.Update();		// �G��������

		// ���X�g���g�����X�V����
		for (auto iObj = objList.begin(); iObj != objList.end(); ) {
			(*iObj)->Update();

			// �A�b�v�f�[�g�ŏ����t���O��ON�ɂȂ������`�F�b�N
			if ((*iObj)->getDeleteFlag() == true) {
				delete* iObj;	// ����������폜
				// ���X�g����폜���āA���̗v�f���C�e���[�^�ɓ����
				iObj = objList.erase(iObj);
			}
			else {
				++iObj;	// ���̗v�f��
			}
		}

		// �`��֘A�i��ɕ`�悵������D��x��j
		for (auto iObj = objList.begin();
			iObj != objList.end(); ++iObj) {
			(*iObj)->Draw();
		}

		// �q�b�g�̃`�F�b�N������
		std::list<Object*> plHitList;
		std::list<Object*> emHitList;
		int plNum = 0, emNum = 0;
		for (auto iObj = objList.begin();iObj != objList.end(); ++iObj)
		{
			if ((*iObj)->hitAbleFlag == true) 
			{ // �q�b�g�L�����`�F�b�N
				if ((*iObj)->hitType == 0) 
				{
					// �^�C�v�ʊm�F
					plHitList.push_back(*iObj);					
				}
				else
				{
					emHitList.push_back(*iObj);
				}	
			}
		}
		// �q�b�g�̃`�F�b�N
		for (auto pltr = plHitList.begin(); pltr != plHitList.end(); ++pltr)
		{
			for (auto eItr = emHitList.begin(); eItr != emHitList.end(); ++eItr)
			{
				HitControl(*pltr, *eItr);
			}
		}
		string text = to_string(HitPoint);
		DrawFormatString(0, 80, GetColor(255, 255, 255), text.c_str());
		ScreenFlip();			// ����ʂ�\�ɕ\���i�_�u���o�b�t�@�����O�j
		WaitTimer(20);			// �ҋ@�i20ms�҂�
		if (ProcessMessage() == -1) { break; }	// X�̃{�^���������ꂽ�I��
		if (CheckHitKey(KEY_INPUT_ESCAPE)) { break; }	// ESC�L�[�ŏI��
	}
	// DX���C�u�����I��
	DxLib_End();
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