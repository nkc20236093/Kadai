#include "DxLib.h"

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

    // �񋓑�
    enum CharaNo 
    {
        Luffy,Zoro,Enel,Back,Num
    };
    // �f�[�^�ǂݍ��ݗp�̔z��
    static const char* filePathTable[CharaNo::Num] =
    {
        "sprite/onepiece01_luffy.png",
        "sprite/onepiece02_zoro_bandana.png",
        "sprite/onepiece14_enel.png",
        "sprite/Nyaoha.png",
    };
    int gHandleTable[CharaNo::Num];
    for (int i = 0; i < CharaNo::Num; i++)
    {
        gHandleTable[i] = LoadGraph(filePathTable[i]);
    }
    // �O���t�B�b�N���������֓ǂݍ���
    // �ǂݍ��񂾌�̎��ʔԍ�(�O���t�B�b�N�o���h��)�Ƃ��ĕۑ�
    int graphHandle1 = LoadGraph("sprite/onepiece14_enel.png");

    class Object
    {
        int x, y, gHandle;
    public:
        // �R���X�g���N�^
        Object(int _gHandle) :x(0), y(0), gHandle(_gHandle){}
        // �A�N�Z�T
        void SetX(int value) { x = value; }
        int GetX() { return x; }
        void SetY(int value) { y = value; }
        int GetY() { return y; }
        int GetgHandle() { return gHandle; }
    };
    // �N���X�̎��̍쐬
    Object pl = Object(CharaNo::Luffy); pl.SetX(400); pl.SetY(600);
    Object pl2 = Object(CharaNo::Zoro); pl2.SetX(200); pl2.SetY(100);
    Object em = Object(CharaNo::Enel); em.SetX(800); em.SetY(100);
    Object back = Object(CharaNo::Back); back.SetX(0); back.SetY(0);

    int x = 0, y = 0;
    // �Q�[�����[�v
    while (true)
    {
        // ��ʂ���x����
        ClearDrawScreen();
        // �v���C���[�̑���
        if (CheckHitKey(KEY_INPUT_W)) { pl.SetY(pl.GetY() - 8); }
        if (CheckHitKey(KEY_INPUT_S)) { pl.SetY(pl.GetY() + 8); }
        if (CheckHitKey(KEY_INPUT_A)) { pl.SetX(pl.GetX() - 8); }
        if (CheckHitKey(KEY_INPUT_D)) { pl.SetX(pl.GetX() + 8); }
        // �w�i���\��
        DrawGraph(back.GetX(), back.GetY(), gHandleTable[CharaNo::Back], TRUE);
        // �O���t�B�b�N�n���h������\��
        DrawGraph(pl.GetX(), pl.GetY(), gHandleTable[CharaNo::Luffy], TRUE);
        DrawGraph(pl2.GetX(), pl2.GetY(), gHandleTable[CharaNo::Zoro], TRUE);
        DrawGraph(em.GetX(), em.GetY(), gHandleTable[CharaNo::Enel], TRUE);

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