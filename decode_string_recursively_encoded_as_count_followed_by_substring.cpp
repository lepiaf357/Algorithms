#include <iostream>
#include <string>
#include <stack>
#include <utility>

// utility za pair
// 2[ab3[te]r]ew4[a]
// num[ --> push (num, curr_pos)
// ] --> pop --> str = str[0-curr_pos) + num * str[curr_pos-end)


void PrintStringFromPattern(const std::string& strPattern)
{
    std::stack<std::pair<int,int>> stckprNumPosition;
    int iNum = 0;
    std::string strFromPattern;

    for (auto it = strPattern.begin(); it != strPattern.end(); ++it)
    {
        if (*it >= '0' && *it <= '9')
        {
            if (iNum != 0)
            {
                iNum = iNum * 10;
            }
            iNum += *it - '0';
        }
        else if (*it == '[')
        {
            if (iNum == 0)
            {
                std::cout << "Invalid pattern (" << strPattern << ")!" << std::endl;
                std::cout << "Specify num before open a square bracket" << std::endl;
                return;
            }
            else
            {
                stckprNumPosition.push(std::make_pair(iNum, strFromPattern.size()));
                iNum = 0;
            }
        }
        else if (*it == ']')
        {
            if (iNum != 0)
            {
                strFromPattern += std::to_string(iNum);
                iNum = 0;
            }

            if (stckprNumPosition.empty())
            {
                std::cout << "Invalid pattern (" << strPattern << ")!" << std::endl;
                std::cout << "Check if square brackets are properly open/close..." << std::endl;
                return;
            }

            std::pair<int,int> prNumPosition = stckprNumPosition.top();
            std::string strAdd = strFromPattern.substr(prNumPosition.second);
            while (--prNumPosition.first)
            {
                strFromPattern += strAdd;
            }
            stckprNumPosition.pop();
        }
        else
        {
            if (iNum != 0)
            {
                strFromPattern += std::to_string(iNum);
                iNum = 0;
            }

            strFromPattern.push_back(*it);
        }
    }

    if (!stckprNumPosition.empty())
    {
        std::cout << "Invalid pattern (" << strPattern << ")!" << std::endl;
        std::cout << "Check if square brackets are properly open/close..." << std::endl;
        return;
    }

        std::cout << "From given pattern (" << strPattern << ") string is: " << std::endl << strFromPattern << std::endl;
}

int main()
{
    std::string strPattern;
    std::cin >> strPattern;

    PrintStringFromPattern(strPattern);

    return 0;
}

