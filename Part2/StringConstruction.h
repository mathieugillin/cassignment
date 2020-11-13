#ifndef STRINGCONSTRUCTION_H
#define STRINGCONSTRUCTION_H

#include <string>
using std::string;


// TODO: your code goes here:

#include <iostream>
#include <string>
#include <vector>
int stringConstruction(std::string inputStr, int cloneCost, int appendCost)
{
    std::vector<std::string> subStringList;
    std::string newStr;
    std::string currentStr;
    int i = 0;
    int cheapestCost = 0;
    int totalAppendCost = 0;

    while (i < inputStr.size())
    {
        currentStr = "";
        for (int a = 0; a < subStringList.size(); ++a)
        {
            std::string newSubStr = subStringList[a];
            std::string inputSubStr = inputStr.substr(i, subStringList[a].length());
            if (inputSubStr.compare(newSubStr) == 0)
            {
                currentStr = subStringList[a];
            }
        }
        if (currentStr.empty())
        {
            currentStr = inputStr.substr(i, 1);
        }

        totalAppendCost = currentStr.length() * appendCost;

        if (cloneCost  < totalAppendCost)
        {
            newStr.append(currentStr);
            i += currentStr.length();
            cheapestCost += cloneCost;
        }
        else
        {
            for (int x = 0; x < currentStr.length(); ++x)
            {
                newStr.append(currentStr.substr(x, 1));
                ++i;
                cheapestCost += appendCost;
            }
        }
        subStringList.push_back(newStr);
    }
    return cheapestCost;
}

// do not write or edit anything below this line

#endif
