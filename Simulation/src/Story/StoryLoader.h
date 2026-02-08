#pragma once
#include "StoryData.h"

class StoryLoader
{
public:
	static StoryData LoadFromString(const std::string& text);
	static StoryData LoadFromFile(const std::string& path);
};