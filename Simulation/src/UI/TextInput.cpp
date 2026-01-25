#include "TextInput.h"
#include <DxLib.h>

TextInput::TextInput(int maxLength)
{
	handle_ = MakeKeyInput(maxLength, FALSE, FALSE, FALSE);
}

void TextInput::activate()
{
	SetActiveKeyInput(handle_);
}

void TextInput::deactivate()
{
	SetActiveKeyInput(-1);
}

void TextInput::update()
{
	char buf[256] = {};
	GetKeyInputString(buf, handle_);
	text_ = buf;
}

const std::string& TextInput::getText() const
{
	return text_;
}

bool TextInput::isDecided() const
{
	return CheckKeyInput(handle_) == TRUE;
}

int TextInput::getTextWidth() const
{
	return GetDrawStringWidth(
		text_.c_str(),
		static_cast<int>(text_.length())
	);
}
