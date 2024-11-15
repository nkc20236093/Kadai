#include "DxLib.h"

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

    // 列挙体
    enum CharaNo 
    {
        Luffy,Zoro,Enel,Back,Num
    };
    // データ読み込み用の配列
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
    // グラフィックをメモリへ読み込み
    // 読み込んだ後の識別番号(グラフィックバンドル)として保存
    int graphHandle1 = LoadGraph("sprite/onepiece14_enel.png");

    class Object
    {
        int x, y, gHandle;
    public:
        // コンストラクタ
        Object(int _gHandle) :x(0), y(0), gHandle(_gHandle){}
        // アクセサ
        void SetX(int value) { x = value; }
        int GetX() { return x; }
        void SetY(int value) { y = value; }
        int GetY() { return y; }
        int GetgHandle() { return gHandle; }
    };
    // クラスの実体作成
    Object pl = Object(CharaNo::Luffy); pl.SetX(400); pl.SetY(600);
    Object pl2 = Object(CharaNo::Zoro); pl2.SetX(200); pl2.SetY(100);
    Object em = Object(CharaNo::Enel); em.SetX(800); em.SetY(100);
    Object back = Object(CharaNo::Back); back.SetX(0); back.SetY(0);

    int x = 0, y = 0;
    // ゲームループ
    while (true)
    {
        // 画面を一度消す
        ClearDrawScreen();
        // プレイヤーの操作
        if (CheckHitKey(KEY_INPUT_W)) { pl.SetY(pl.GetY() - 8); }
        if (CheckHitKey(KEY_INPUT_S)) { pl.SetY(pl.GetY() + 8); }
        if (CheckHitKey(KEY_INPUT_A)) { pl.SetX(pl.GetX() - 8); }
        if (CheckHitKey(KEY_INPUT_D)) { pl.SetX(pl.GetX() + 8); }
        // 背景も表示
        DrawGraph(back.GetX(), back.GetY(), gHandleTable[CharaNo::Back], TRUE);
        // グラフィックハンドルから表示
        DrawGraph(pl.GetX(), pl.GetY(), gHandleTable[CharaNo::Luffy], TRUE);
        DrawGraph(pl2.GetX(), pl2.GetY(), gHandleTable[CharaNo::Zoro], TRUE);
        DrawGraph(em.GetX(), em.GetY(), gHandleTable[CharaNo::Enel], TRUE);

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