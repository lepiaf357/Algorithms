#include <iostream>
#include <vector>

void ReplaceSurroundedO(std::vector<std::vector<char>>& matrixXO)
{
    int n = matrixXO.size();
    int m = matrixXO[0].size();

    int i, j;

    for (int k = 1; k <= (n - 1) / 2; ++k)
    {
        i = k;
        j = k;
        for (; j < m - 1 - k; ++j)
        {
            //std::cout << matrixXO[i][j] << " ";
            if (matrixXO[i][j] == 'o' && matrixXO[i][j - 1] == 'x' && matrixXO[i - 1][j] == 'x')
            {
                matrixXO[i][j] = 'x';
            }
        }
        for (; i < n - 1 - k; ++i)
        {
            //std::cout << matrixXO[i][j] << " ";
            if (matrixXO[i][j] == 'o' && matrixXO[i - 1][j] == 'x' && matrixXO[i][j + 1] == 'x')
            {
                matrixXO[i][j] = 'x';
            }
        }
        for (j = m - 1 - k; j > k; --j)
        {
            //std::cout << matrixXO[i][j] << " ";
            if (matrixXO[i][j] == 'o' && matrixXO[i][j + 1] == 'x' && matrixXO[i + 1][j] == 'x')
            {
                matrixXO[i][j] = 'x';
            }
        }
        for (i = n - 1 - k; i > k; --i)
        {
            //std::cout << matrixXO[i][j] << " ";
            if (matrixXO[i][j] == 'o' && matrixXO[i + 1][j] == 'x' && matrixXO[i][j - 1] == 'x')
            {
                matrixXO[i][j] = 'x';
            }
        }

        if (m - 1 - k == k)
        {
            //std::cout << matrixXO[k][k] << " ";
            if (matrixXO[k][k] == 'o' && matrixXO[k][k + 1] == 'x' && matrixXO[k][k - 1] == 'x' && matrixXO[k + 1][k] == 'x' && matrixXO[k - 1][k] == 'x')
            {
                matrixXO[i][j] = 'x';
            }
        }
    }
}

int main()
{
    int n;
    std::cin >> n;

    int m;
    std::cin >> m;

    std::vector<std::vector<char>> matrixXO(n, std::vector<char>(m));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            std::cin >> matrixXO[i][j];
        }
    }

    ReplaceSurroundedO(matrixXO);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            std::cout << matrixXO[i][j] << " ";
        }
        std::cout << std::endl;
    }

        return 0;
}

