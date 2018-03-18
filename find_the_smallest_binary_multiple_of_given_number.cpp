#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>

int StringModInt(std::string strBinary, int iNum)
{
    int iResult = 0;
    for (auto it = strBinary.begin(); it != strBinary.end(); ++it)
    {
        iResult = iResult * 10 + (*it - '0');
        iResult = iResult % iNum;
    }
    return iResult;
}

std::string BinaryMultiple(int iNum)
{
    std::string strBinary;
    std::unordered_set<int> usetVisited; // for optimization
    std::queue<std::string> qBinary;

    qBinary.push("1");
    while (!qBinary.empty())
    {
        strBinary = qBinary.front();
        qBinary.pop();

        int iMod = StringModInt(strBinary, iNum);
        if (iMod == 0)
        {
            break;
        }
        else if (usetVisited.find(iMod) == usetVisited.end()) // optimization
        {
            // only if that mod isn't in a set, add it and add to queue
            // else cut that branch
            // if mod is same than if we can add to bigger num to be multiple we also can do it for smaller with the same mod
            // so if we didn't find that smaller one is multiple then it is not possible for bigger one with the same remainder
            usetVisited.insert(iMod);
            qBinary.push(strBinary + "0");
            qBinary.push(strBinary + "1");
        }
    }

    return strBinary;
}

int main()
{
    int iNum;
    std::cin >> iNum;

    std::cout << BinaryMultiple(iNum) << std::endl;

    return 0;
}