#include <iostream>
#include <string>
#include <vector>

int getAllX(std::vector<std::vector<char>> &matrix)
{
    int counter = 0;

    for (int i = 1; i < matrix.size() - 1; i++)
    {
        for (int j = 1; j < matrix[i].size() - 1; j++)
        {
            if (matrix[i][j] == 'A')
            {
                int counter_m = 0, counter_s = 0;

                if (matrix[i - 1][j - 1] == 'M')
                {
                    counter_m++;
                }
                else if (matrix[i - 1][j - 1] == 'S')
                {
                    counter_s++;
                }

                if (matrix[i + 1][j - 1] == 'M')
                {
                    counter_m++;
                }
                else if (matrix[i + 1][j - 1] == 'S')
                {
                    counter_s++;
                }

                if (matrix[i - 1][j + 1] == 'M')
                {
                    counter_m++;
                }
                else if (matrix[i - 1][j + 1] == 'S')
                {
                    counter_s++;
                }

                if (matrix[i + 1][j + 1] == 'M')
                {
                    counter_m++;
                }
                else if (matrix[i + 1][j + 1] == 'S')
                {
                    counter_s++;
                }

                if (counter_s == counter_m && counter_s == 2 && matrix[i - 1][j - 1] != matrix[i + 1][j + 1])
                    counter++;
            }
        }
    }

    return counter;
}

int main()
{
    std::freopen("./input/input.txt", "r", stdin);
    std::string s;

    std::vector<std::vector<char>> matrix;
    while (std::getline(std::cin, s))
    {
        std::vector<char> chars;
        for (int i = 0; i < s.size(); i++)
        {
            chars.push_back(s[i]);
        }

        matrix.push_back(chars);
    }

    int ans = 0;

    ans += getAllX(matrix);

    std::cout << ans << std::endl;
}