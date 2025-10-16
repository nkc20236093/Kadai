#include <Windows.h>		// Windows�v���O�����ŕK�v�ɂȂ���̂������Ă���
#include <time.h>
#include "App.h"
#include "Input.h"
#include "SceneManager.h"
#include "StartScene.h"
#include "GameScene.h"
#include "ClearScene.h"

#pragma comment(lib,"winmm.lib")


// �V�[������
SceneManager* pScene;
STATUS status = INIT;
SCENE  scene = START;
// FPS����
float frameTime = 0;
LARGE_INTEGER timeStart = { 0 };
LARGE_INTEGER timeEnd = { 0 };
LARGE_INTEGER timeFreq = { 0 };

void GameLoop();
void FpsSleep();

// �G���g���[�|�C���g
int32_t WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int32_t nCmdShow)
{
	// ������
	if (!App::GetInstance()->InitApp())return 1;

	MSG hMsg = {};
	ZeroMemory(&hMsg, sizeof(hMsg));

	// ���C�����[�v
	while (hMsg.message != WM_QUIT)
	{
		if (PeekMessage(&hMsg, nullptr, 0, 0, PM_REMOVE))// ���b�Z�[�W���擾����B�o���Ȃ��Ă��J��Ԃ��������s��
		{
			TranslateMessage(&hMsg);// �L�[�{�[�h���b�Z�[�W���當�����b�Z�[�W�𐶐�����
			DispatchMessage(&hMsg);	// �E�B���h�E�v���V�[�W���Ƀ��b�Z�[�W��n��
		}
		else
		{
			Input::GetInstance()->SetInputState();		// �L�[���͎擾
			QueryPerformanceFrequency(&timeFreq);		// FPS����
			QueryPerformanceCounter(&timeStart);		// FPS����
			GameLoop();									// �Q�[������
			FpsSleep();									// FPS����
			Input::GetInstance()->SetInputStateOld();	// �L�[���͕ۑ�
		}
	}

	// �I��
	App::GetInstance()->TermApp();

	return 0;
}

// �Q�[�����[�v
void GameLoop()
{
	switch (status)
	{
	case INIT:

		// �V�[���̐؂�ւ�
		switch (scene)
		{
		case START:
		default:
			pScene = new StartScene();
			break;
		case GAME:
			pScene = new GameScene();
			break;
		case CLEAR:
			pScene = new ClearScene();
			break;
		}
		pScene->Init();
		// ���������I�������X�V��
		status = UPDATE;
		break;
	case UPDATE:
		scene = pScene->Update();

		pScene->Render();

		// �����V�[�������[�v����ꍇSCENE_MAX��Ԃ��BSCENE_MAX�ȊO���Ԃ��Ă�����V�[���J��
		if (scene != SCENE_MAX)
		{
			status = TERM;
		}
		break;
	case TERM:
		pScene->Term();
		delete pScene;
		status = INIT;
		break;
	}
}

// FPS����p�X���[�v����
void FpsSleep()
{
	// ���݂̎��Ԏ擾
	QueryPerformanceCounter(&timeEnd);
	// (���̎��� - �O�t���[���̎���) / ���g�� = �o�ߎ���(�b�P��)
	frameTime = static_cast<float>(timeEnd.QuadPart - timeStart.QuadPart) / static_cast<float>(timeFreq.QuadPart);

	if (frameTime < MIN_FRAME_TIME) { // ���Ԃɗ]�T������
		// �~���b�ɕϊ�
		DWORD sleepTime = static_cast<DWORD>((MIN_FRAME_TIME - frameTime) * 1000);

		timeBeginPeriod(1); // ����\���グ��(�������Ȃ���Sleep�̐��x�̓K�^�K�^)
		Sleep(sleepTime);   // �ҋ@
		timeEndPeriod(1);   // �߂�

		return;
	}
	timeStart = timeEnd; // ����ւ�
}