#pragma once
#include "UI/GameKey.h"

class Input
{
public:
	void update();
	bool isPressed(GameKey key) const;
	bool isTriggered(GameKey key) const;

private:
	static constexpr int KeyCount = 256; // DxLib仕様
	int current[KeyCount];
	int previous[KeyCount];
};