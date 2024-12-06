#include <iostream>
#include <string>
#include <vector>

void goTop(std::vector<std::string> &v, int &x, int &y);
void goRight(std::vector<std::string> &v, int &x, int &y);
void goBottom(std::vector<std::string> &v, int &x, int &y);
void goLeft(std::vector<std::string> &v, int &x, int &y);

enum Facing
{
    top,
    right,
    bottom,
    left
};

int main()
{
    std::freopen("input/input.txt", "r", stdin);
    std::string s;
    std::vector<std::string> v;

    while (std::getline(std::cin, s))
    {
        v.push_back(s);
    }

    int x, y;
    Facing facing;
    for (int i = 0; i < v.size(); ++i)
    {
        for (int j = 0; j < v[i].size(); ++j)
        {
            if (v[i][j] == '^')
            {
                facing = top;
                x = i, y = j;
                break;
            }
            else if (v[i][j] == 'v')
            {
                facing = bottom;
                x = i, y = j;
                break;
            }
            if (v[i][j] == '<')
            {
                facing = left;
                x = i, y = j;
                break;
            }
            if (v[i][j] == '>')
            {
                facing = right;
                x = i, y = j;
                break;
            }
        }
    }

    while (x != -1 && y != -1)
    {

        if (facing == top)
        {
            goTop(v, x, y);
            facing = right;
        }
        else if (facing == right)
        {
            goRight(v, x, y);
            facing = bottom;
        }
        else if (facing == bottom)
        {
            goBottom(v, x, y);
            facing = left;
        }
        else if (facing == left)
        {
            goLeft(v, x, y);
            facing = top;
        }
    }

    int ans = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        for (int j = 0; j < v[i].size(); ++j)
        {
            if (v[i][j] == 'X')
                ans++;
        }
    }

    std::cout << ans << std::endl;
}

void goTop(std::vector<std::string> &v, int &x, int &y)
{
    while (x >= 0)
    {
        v[x][y] = 'X';
        if (x == 0)
        {
            x = -1;
            break;
        }

        if (v[x - 1][y] == '#')
        {
            break;
        }
        else
        {
            x--;
        }
    }
}

void goRight(std::vector<std::string> &v, int &x, int &y)
{
    while (y < v[x].size())
    {
        v[x][y] = 'X';
        if (y == v[x].size() - 1)
        {
            y = -1;
            break;
        }

        if (v[x][y + 1] == '#')
        {
            break;
        }
        else
        {
            y++;
        }
    }
}

void goBottom(std::vector<std::string> &v, int &x, int &y)
{
    while (x < v.size())
    {
        v[x][y] = 'X';
        if (x == v.size() - 1)
        {
            x = -1;
            break;
        }

        if (v[x + 1][y] == '#')
        {
            break;
        }
        else
        {
            x++;
        }
    }
}

void goLeft(std::vector<std::string> &v, int &x, int &y)
{
    while (y >= 0)
    {
        v[x][y] = 'X';
        if (y == 0)
        {
            y = -1;
            break;
        }

        if (v[x][y - 1] == '#')
        {
            break;
        }
        else
        {
            y--;
        }
    }
}