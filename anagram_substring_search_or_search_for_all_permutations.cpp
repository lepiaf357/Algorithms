
#include <iostream>
#include <string>
#include <cstring>

const int MAXSIZE = 256;

bool Equal(char cCharsPattern[], char cCharsText[])
{
    for (int  i = 0; i < MAXSIZE; ++i)
    {
        if (cCharsPattern[i] != cCharsText[i])
        {
            return false;
        }
    }
    return true;
}

void Search(const char cPattern[], const char cText[])
{
    int n = strlen(cText);
    int m = strlen(cPattern);

    char cCharsText[MAXSIZE] = {0};
    char cCharsPattern[MAXSIZE] = {0};

    int i = 0;
    for (; i < m; i++)
    {
        --cCharsText[cText[i]];
        --cCharsPattern[cPattern[i]];
    }
    if (Equal(cCharsPattern, cCharsText))
    {
        std::cout << "Found at position " << i - m << std::endl;
    }

    for (; i < n; i++)
    {
        --cCharsText[cText[i - m]];
        ++cCharsText[cText[i]];

        if (Equal(cCharsPattern, cCharsText))
        {
            std::cout << "Found at position " << i - m << std::endl;
        }
    }
}

int main()
{
    std::string strText;
    std::cin >> strText;

    std::string strPattern;
    std::cin >> strPattern;

    Search(strPattern.c_str(), strText.c_str());

    return 0;
}
