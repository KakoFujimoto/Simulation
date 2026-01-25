#pragma once
#include<string>

namespace GameMessage
{
	struct TitleSceneMessage
	{
		static constexpr char PressEnter[] = "Press Enter";
	};

	struct NameInputSceneMessage
	{
		static constexpr char EnterName[] = "名前を入力してください(全角8文字以内)";
	};
}