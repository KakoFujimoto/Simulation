#include "StoryLoader.h"
#include <sstream>

StoryData StoryLoader::LoadFromString(const std::string& text)
{
    StoryData data;

    std::istringstream stream(text);
    std::string line;

    std::string currentNodeId;
    std::string currentText;
    std::vector<Choice> currentChoices;

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

        if (line.rfind("[node ", 0) == 0)
        {
            flushNode();

            auto end = line.find(']');
            currentNodeId = line.substr(6, end - 6);
        }
        else if (line.rfind("text=", 0) == 0)
        {
            currentText = line.substr(5);
        }
        else if (line.rfind("choice=", 0) == 0)
        {
            auto body = line.substr(7);
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