#pragma once
#include <string>
#include <vector>
#include <unordered_map>

struct Choice
{
	std::string text;
	std::string nextNodeId;
};

struct ScriptNode
{
	std::string id;
	std::vector<std::string> texts;
	std::vector<Choice> choices;
};

struct StoryFlags
{
	bool readMemo = false;
};

class StoryData
{
public:
	void addNode(const ScriptNode& node);
	const ScriptNode* getNode(const std::string& id) const;

private:
	std::unordered_map<std::string, ScriptNode> nodes_;
};