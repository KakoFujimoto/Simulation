#include <DxLib.h>
#include "System/GameManager.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    SetUseCharCodeFormat(DX_CHARCODEFORMAT_UTF8);
    ChangeWindowMode(TRUE);
    SetGraphMode(800, 700, 32);
    DxLib_Init();

    GameManager gm;
    gm.initialize();

    while (ProcessMessage() == 0)
    {
        gm.update();
        ClearDrawScreen();
        gm.draw();
        ScreenFlip();
    }

    DxLib_End();
    return 0;
}