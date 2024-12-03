#include <iostream>
#include <string>
#include <sstream>
#include <regex>

std::pair<int, int> getIntegers(std::string s)
{
    std::pair<int, int> p;

    int delimeter_pos = s.find(',');

    p.first = std::stoi(s.substr(4, delimeter_pos - 4));
    p.second = std::stoi(s.substr(delimeter_pos + 1, s.size() - delimeter_pos));

    return p;
}

int main()
{

    std::freopen("./input/input.txt", "r", stdin);
    std::string s;

    std::vector<std::string> strings;

    while (std::getline(std::cin, s))
    {
        strings.push_back(s);
    }

    bool enabled = true;

    long long ans = 0;
    for (int i = 0; i < strings.size(); ++i)
    {
        std::smatch match;
        std::regex r("mul\\(\\d+,\\d+\\)|don't|do");

        std::regex_token_iterator<std::string::iterator> rend;
        std::regex_token_iterator<std::string::iterator> it(strings[i].begin(), strings[i].end(), r);

        while (it != rend)
        {
            std::string temp = *it;

            if (temp == "do")
                enabled = true;
            else if (temp == "don't")
                enabled = false;
            else if (enabled)
            {
                std::pair<int, int> p = getIntegers(temp);
                ans += p.first * p.second;
            }
            it++;
        }
    }

    std::cout << ans << std::endl;
}