#include "StoryData.h"

void StoryData::addNode(const ScriptNode& node)
{
	nodes_[node.id] = node;
}

const ScriptNode* StoryData::getNode(const std::string& id) const
{
	auto it = nodes_.find(id);
	if (it == nodes_.end())
	{
		return nullptr;
	}
	return &it->second;
}
