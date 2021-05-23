//----------------------------------
//����T��
//----------------------------------
//
#include "DxLib.h"


// �萔�錾
#define SCREEN_SIZE_X	800
#define SCREEN_SIZE_Y	600

// �ϐ��錾
int GameCounter;

// �v���g�^�C�v�錾
void GameMain(void);
void GameDraw(void);

int WINAPI WinMain(HINSTANCE , HINSTANCE , LPSTR, int)
{
	// �V�X�e������
	SetWindowText("1916017_����T��");
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 16);
	ChangeWindowMode(true);

	// DxLib������
	if (DxLib_Init() == -1)
	{
		return -1;
	}

	SetDrawScreen(DX_SCREEN_BACK);

	// �O���t�B�b�N�̓o�^

	// �ϐ��̏�����
	GameCounter = 0;

	// �Q�[�����[�v
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		ClsDrawScreen();

		GameMain();
		GameDraw();

		ScreenFlip();
	}

	DxLib_End();     

	return 0; 
}

void GameMain(void)
{
	GameCounter++;
}

void GameDraw(void)
{
	int Color = GetColor(255, 255,255);
	DrawFormatString(0, 0, Color, "�Q�[���J�E���^�[  %d",GameCounter);
}