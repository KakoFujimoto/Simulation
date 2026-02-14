#include "StoryLoader.h"
#include <sstream>
#include <fstream>
#include <cassert>

StoryData StoryLoader::LoadFromString(const std::string& text)
{
    StoryData data;

    std::istringstream stream(text);
    std::string line;

    std::string currentNodeId;
    std::vector<std::string> currentTexts;
    std::vector<Choice> currentChoices;
    std::string currentSetFlag;
    std::string currentIfFlag;
    std::string currentIfFlagNextNode;
    std::optional<std::string> currentEndingType;

    const std::string NodePrefix = "[node ";
    const std::string TextPrefix = "text=";
    const std::string ChoicePrefix = "choice=";
    const std::string SetFlagPrefix = "setflag=";
    const std::string IfFlagPrefix = "ifflag=";
    const std::string EndPrefix = "end=";

    auto flushNode = [&]()
        {
            if (currentNodeId.empty())
                return;

            data.addNode({
                currentNodeId,
                currentTexts,
                currentChoices,
                currentEndingType,
                currentSetFlag,
                currentIfFlag,
                currentIfFlagNextNode
                });

            currentNodeId.clear();
            currentTexts.clear();
            currentChoices.clear();
            currentSetFlag.clear();
            currentIfFlag.clear();
            currentIfFlagNextNode.clear();
            currentEndingType.reset();
        };

    while (std::getline(stream, line))
    {
        if (line.empty())
            continue;

        if (line.rfind(NodePrefix, 0) == 0)
        {
            flushNode();

            auto end = line.find(']');
            currentNodeId = line.substr(
                NodePrefix.size(),
                end - NodePrefix.size());
        }
        else if (line.rfind(TextPrefix, 0) == 0)
        {
            currentTexts.push_back(line.substr(TextPrefix.size()));
        }
        else if (line.rfind(ChoicePrefix, 0) == 0)
        {
            auto body = line.substr(ChoicePrefix.size());
            auto comma = body.find(',');

            Choice choice;
            choice.text = body.substr(0, comma);
            choice.nextNodeId = body.substr(comma + 1);

            currentChoices.push_back(choice);
        }
        else if (line.rfind(SetFlagPrefix, 0) == 0)
        {
            currentSetFlag = line.substr(SetFlagPrefix.size());
        }
        else if (line.rfind(IfFlagPrefix, 0) == 0)
        {
            auto body = line.substr(IfFlagPrefix.size());
            auto comma = body.find(',');

            currentIfFlag = body.substr(0, comma);
            currentIfFlagNextNode = body.substr(comma + 1);
        }
        else if (line.rfind(EndPrefix, 0) == 0)
        {
            currentEndingType = line.substr(EndPrefix.size());
        }
    }

    flushNode();
    return data;
}

StoryData StoryLoader::LoadFromFile(const std::string& path)
{
    std::ifstream file(path);
    if (!file)
    {
        assert(false && "story.story が見つかりません");
        return {};
    }

    std::ostringstream buffer;
    buffer << file.rdbuf();
    const std::string text = buffer.str();

    return LoadFromString(text);
}