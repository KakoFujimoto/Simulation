#pragma once
#include <string>

class TextInput
{
public:
	TextInput(int maxLength);

	void activate();
	void deactivate();
	void update();
	const std::string& getText() const;
	bool isDecided() const;
	int getTextWidth() const;

private:
	int handle_;
	std::string text_;
};