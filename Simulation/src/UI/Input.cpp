#include "Input.h"
#include <DxLib.h>

void Input::update()
{
	memcpy(previous, current, sizeof(current));

	for (int i = 0; i < KeyCount; i++)
	{
		current[i] = CheckHitKey(i);
	}
}

bool Input::isPressed(GameKey key) const
{
	switch (key)
	{
	case GameKey::Up:
		return current[KEY_INPUT_UP] != 0;
	case GameKey::Down:
		return current[KEY_INPUT_DOWN] != 0;
	case GameKey::Enter:
		return current[KEY_INPUT_RETURN] != 0;
	}
	return false;
}

bool Input::isTriggered(GameKey key) const
{
	switch (key)
	{
	case GameKey::Up:
		return current[KEY_INPUT_UP] != 0
			&& previous[KEY_INPUT_UP] == 0;
	case GameKey::Down:
		return current[KEY_INPUT_DOWN] != 0
			&& previous[KEY_INPUT_DOWN] == 0;
	case GameKey::Enter:
		return current[KEY_INPUT_RETURN] != 0
			&& previous[KEY_INPUT_RETURN] == 0;
	}
	return false;
}