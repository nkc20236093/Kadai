#include "DxLib.h"
#include <list>

class Object;

// �I�u�W�F�N�g�N���X�̃��X�g
std::list<Object*> objList;
// �񋓑�
enum CharaNo
{
    Luffy, Zoro, Enel, Back, Shell, Num
};
// �O���t�B�b�N�n���h���e�[�u��
int gHandleTable[CharaNo::Num];

class Object
{
    int x = 0, y = 0, gHandle;      // ���W�A�O���t�B�b�N�n���h��
    int cx = 0, cy = 0;             // ��]�̌��ƂȂ���W
    double sclX = 1.0, sclY = 1.0;  // �g�嗦
    double radian = 0;              // ��]��
    bool turnflag = false;          // ���]�t���O
public:
    // �R���X�g���N�^
    Object(int _gHandle) :x(0), y(0), gHandle(_gHandle) {}
    // �A�N�Z�T
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

    // �`�揈��
    void Draw()
    {
        DrawRotaGraph3(x, y, cx, cy, sclX, sclY, radian, gHandle, TRUE, turnflag);
    }
    // �X�V����(�����֐�)
    virtual void Update() {}
};
// �v���C���[�e�N���X
class PLShell :public Object
{
public:
    // �R���X�g���N�^
    PLShell(int _gHandle) : Object(_gHandle) {}
    // �A�b�v�f�[�g�֐��I�[�o�[���C�h
    void Update() {
        SetY(GetY() - 10);
    }
};


class Player :public Object
{
public:
    // �R���X�g���N�^
    Player(int _gHandle) :Object(_gHandle) {}

    // �A�b�v�f�[�g�֐��I�[�o�[���C�h
    void Update()
    {
        // �v���C���[�̑���
        if (CheckHitKey(KEY_INPUT_W)) { SetY(GetY() - 8); }
        if (CheckHitKey(KEY_INPUT_S)) { SetY(GetY() + 8); }
        if (CheckHitKey(KEY_INPUT_A)) { SetX(GetX() - 8); SetTurnFlag(true); }
        if (CheckHitKey(KEY_INPUT_D)) { SetX(GetX() + 8); SetTurnFlag(false); }

        // �g��k���̃`�F�b�N
        if (CheckHitKey(KEY_INPUT_UP)) { SetSclY(2.0); }
        if (CheckHitKey(KEY_INPUT_DOWN)) { SetSclY(1.0); }
        if (CheckHitKey(KEY_INPUT_LEFT)) { SetSclX(1.0); }
        if (CheckHitKey(KEY_INPUT_RIGHT)) { SetSclX(2.0); }

        // ��]�̃`�F�b�N
        double rad = 2 * 3.14 / 180; // �f�B�O���[�����W�A���ɕϊ�(2�x)
        if (CheckHitKey(KEY_INPUT_Q)) { SetRadian(GetRadian() - rad); }
        if (CheckHitKey(KEY_INPUT_E)) { SetRadian(GetRadian() + rad); }

        // Z�L�[���͂Œe�𔭎�
        if (CheckHitKey(KEY_INPUT_Z))
        {
            auto ptr = new PLShell(gHandleTable[CharaNo::Shell]);
            ptr->SetX(this->GetX());
            ptr->SetY(this->GetY());
            objList.push_back(ptr);
        }

    }
};

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // ��ʃ��[�h�̐ݒ�
    SetGraphMode(1280, 720, 32);
    // �E�B���h�E���[�h�ɕύX
    ChangeWindowMode(TRUE);

    if (DxLib_Init() == -1)        // �c�w���C�u��������������
    {
        return -1;            // �G���[���N�����璼���ɏI��
    }

    // �`���𗠉�ʂ�(�_�u���o�b�t�@�����O)
    SetDrawScreen(DX_SCREEN_BACK);

    // �f�[�^�ǂݍ��ݗp�̔z��
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
    // �O���t�B�b�N���������֓ǂݍ���
    // �ǂݍ��񂾌�̎��ʔԍ�(�O���t�B�b�N�o���h��)�Ƃ��ĕۑ�
    int graphHandle1 = LoadGraph("sprite/onepiece14_enel.png");

    // �N���X�̎��̍쐬
    Player pl = Player(gHandleTable[CharaNo::Luffy]); pl.SetX(400); pl.SetY(600); pl.SetCX(200); pl.SetCY(200);
    Object pl2 = Object(gHandleTable[CharaNo::Zoro]); pl2.SetX(200); pl2.SetY(100);
    Object em = Object(gHandleTable[CharaNo::Enel]); em.SetX(800); em.SetY(100);
    Object back = Object(gHandleTable[CharaNo::Back]); back.SetX(0); back.SetY(0);

    // ��
    PLShell pshl = PLShell(gHandleTable[CharaNo::Shell]);
    pshl.SetX(400); pshl.SetY(600);

    // ���X�g�o�^
    objList.push_back(&back);
    objList.push_back(&pl);
    objList.push_back(&pl2);
    objList.push_back(&em);
    objList.push_back(&pshl);

    /*
    Object obj // �I�u�W�F�N�g�N���X
    Object�N���X�̋@�\���g����

    Player pl; // �I�u�W�F�N�g�@�\���p������PL
    Player��Object�N���X�̋@�\���g����

    Object test = pl;
    Player���I�u�W�F�N�g�N���X�ɃL���X�g
    test��Player�̍���͎g���Ȃ�

    Object* ptr =&pl;
    Player�̃|�C���^��Object�N���X�̃|�C���^�ɃL���X�g
    ptr��Player���w���Ă���
    ���N���X�̃|�C���^�����ǃv���C���[�̋@�\���g����

    Object* prt2 &pshel;
    ptr2��PLShell���w���Ă���
    ���N���X�̃|�C���^������PLShell�̋@�\���g����
    */

    int x = 0, y = 0;
    // �Q�[�����[�v
    while (true)
    {
        // ��ʂ���x����
        ClearDrawScreen();

        // ���X�g���g�����X�V����
        for (auto iObj = objList.begin(); iObj != objList.end(); ++iObj)
        {
            (*iObj)->Update();
        }

        // ���X�g���g�����`��֘A(��ɕ`�悵������D��x��)
        for (auto iObj = objList.begin(); iObj != objList.end(); ++iObj)
        {
            (*iObj)->Draw();
        }

        //// �w�i���\��
        //DrawGraph(back.GetX(), back.GetY(), gHandleTable[CharaNo::Back], TRUE);
        //// �O���t�B�b�N�n���h������\��
        //DrawGraph(pl.GetX(), pl.GetY(), gHandleTable[CharaNo::Luffy], TRUE);
        //DrawGraph(pl2.GetX(), pl2.GetY(), gHandleTable[CharaNo::Zoro], TRUE);
        //DrawGraph(em.GetX(), em.GetY(), gHandleTable[CharaNo::Enel], TRUE);

        // �摜�ǂݍ��݂��ĕ\��
        //LoadGraphScreen(x, y, "sprite/onepiece14_enel.png", FALSE);
        // ����ʂ�\�ɕ\��
        ScreenFlip();
        // �ҋ@(20ms�҂�)
        WaitTimer(20);
        // X�̃{�^���������ꂽ��I��
        if (ProcessMessage() == -1) { break; }
        // ESC�L�[�ŏI��
        if (CheckHitKey(KEY_INPUT_ESCAPE)) { break; }
    }

    //DrawPixel(320, 240, GetColor(255, 255, 255));    // �_��ł�

    //WaitKey();                // �L�[���͑҂�

    DxLib_End();                // �c�w���C�u�����g�p�̏I������

    return 0;                // �\�t�g�̏I�� 
}