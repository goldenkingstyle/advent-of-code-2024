#include <iostream>
#include <string>
#include <sstream>
#include <vector>

bool checkIncrease(const std::vector<int> &v)
{
    for (int i = 1; i < v.size(); ++i)
    {
        if (v[i] <= v[i - 1])
            return false;
    }

    return true;
}

bool checkDecrease(const std::vector<int> &v)
{
    for (int i = 1; i < v.size(); ++i)
    {
        if (v[i] >= v[i - 1])
            return false;
    }

    return true;
}

bool checkDifference(const std::vector<int> &v)
{
    for (int i = 1; i < v.size(); ++i)
    {
        int diff = abs(v[i] - v[i - 1]);

        if (diff < 1 || diff > 3)
            return false;
    }

    return true;
}

int main()
{
    std::string s;

    std::freopen("./input/input.txt", "r", stdin);

    std::vector<std::vector<int>> matrix;
    while (std::getline(std::cin, s))
    {
        std::istringstream str_stream(s);

        int n;
        std::vector<int> v;

        while (str_stream >> n)
        {
            v.push_back(n);
        }

        matrix.push_back(v);
    }

    int counter = 0;
    for (int i = 0; i < matrix.size(); i++)
    {
        if (checkDifference(matrix[i]) && (checkIncrease(matrix[i]) || checkDecrease(matrix[i])))
            counter++;
    }

    std::cout << counter << std::endl;
}