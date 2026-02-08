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
    std::string currentText;
    std::vector<Choice> currentChoices;

    const std::string  NodePrefix = "[node ";
    const std::string  TextPrefix = "text=";
    const std::string  ChoicePrefix = "choice=";

    auto flushNode = [&]()
        {
            if (currentNodeId.empty())
                return;

            data.addNode({
                currentNodeId,
                currentText,
                currentChoices
                });

            currentNodeId.clear();
            currentText.clear();
            currentChoices.clear();
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
            currentText = line.substr(TextPrefix.size());
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