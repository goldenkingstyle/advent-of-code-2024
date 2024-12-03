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

    long long ans = 0;
    int index = 0;
    for (int i = 0; i < strings.size(); ++i)
    {
        std::smatch match;
        std::regex r("mul\\(\\d+,\\d+\\)");

        std::regex_token_iterator<std::string::iterator> rend;
        std::regex_token_iterator<std::string::iterator> it(strings[i].begin(), strings[i].end(), r);

        while (it != rend)
        {
            std::pair<int, int> p = getIntegers(*it++);
            ans += p.first * p.second;
        }
    }

    std::cout << ans << std::endl;
}