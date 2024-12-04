#include <iostream>
#include <string>
#include <vector>

std::string charsToString(std::vector<char> &chars);

int getHorizontal(std::vector<std::vector<char>> &matrix, std::string s)
{
    int counter = 0;

    for (int i = 0; i < matrix.size(); i++)
    {
        int index = 0;
        std::string row = charsToString(matrix[i]);

        int pos = row.find(s, index);
        while (pos != std::string::npos)
        {
            counter++;
            index = pos + 1;
            pos = row.find(s, index);
        }
    }

    return counter;
}

int getVertical(std::vector<std::vector<char>> &matrix, std::string s)
{
    int counter = 0;

    for (int i = 0; i < matrix.size() - s.size() + 1; i++)
    {
        int index = 0;

        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (matrix[i][j] == s[index])
            {
                index++;
                bool b = true;
                for (int k = i + 1; k < matrix.size(); ++k)
                {
                    if (matrix[k][j] == s[index])
                    {
                        index++;
                    }
                    else
                    {
                        b = false;
                        break;
                    }

                    if (index == s.size())
                    {
                        break;
                    }
                }

                if (b)
                    counter++;

                index = 0;
            }
        }
    }

    return counter;
}

bool topRight(std::vector<std::vector<char>> &matrix, std::string s, int i, int j)
{
    int index = 0;
    while (i >= 0 && j < matrix[0].size())
    {
        if (matrix[i][j] == s[index])
        {
            index++;
        }
        else
        {
            return false;
        }

        if (index == s.size())
        {
            return true;
        }

        i--, j++;
    }

    return false;
}

bool topLeft(std::vector<std::vector<char>> &matrix, std::string s, int i, int j)
{
    int index = 0;
    while (i >= 0 && j >= 0)
    {
        if (matrix[i][j] == s[index])
        {
            index++;
        }
        else
        {
            return false;
        }

        if (index == s.size())
        {
            return true;
        }

        i--, j--;
    }

    return false;
}

int getDiagonal(std::vector<std::vector<char>> &matrix, std::string s)
{
    int counter = 0;

    for (int i = 0; i < matrix.size(); i++)
    {
        int index = 0;
        for (int j = 0; j < matrix[i].size(); j++)
        {
            if (matrix[i][j] == s[index])
            {
                counter += topRight(matrix, s, i, j);
                counter += topLeft(matrix, s, i, j);
            }
        }
    }

    return counter;
}

std::string charsToString(std::vector<char> &chars)
{
    std::string s;
    for (int i = 0; i < chars.size(); i++)
    {
        s += chars[i];
    }
    return s;
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

    ans += getHorizontal(matrix, "XMAS");
    ans += getHorizontal(matrix, "SAMX");

    ans += getVertical(matrix, "XMAS");
    ans += getVertical(matrix, "SAMX");

    ans += getDiagonal(matrix, "XMAS");
    ans += getDiagonal(matrix, "SAMX");

    std::cout << ans << std::endl;
}