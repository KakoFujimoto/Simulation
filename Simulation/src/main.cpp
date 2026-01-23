#include <DxLib.h>
#include "System/GameManager.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    DxLib_Init();
    ChangeWindowMode(TRUE);

    GameManager gm;
    gm.initialize();

    while (ProcessMessage() == 0)
    {
        gm.update();
        gm.draw();
        ScreenFlip();
    }

    DxLib_End();
    return 0;
}
