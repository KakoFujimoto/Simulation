#include "Renderer.h"
#include <DxLib.h>

void Renderer::drawText(int x, int y, const std::string& text)
{
	DrawString(x, y, text.c_str(), GetColor(255, 255, 255));
}
