#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdint>
#include <unordered_map>

int main()
{
    std::ifstream file("./input/input.txt");
    std::string s;

    std::vector<int> left;
    std::unordered_map<int, int> mp;

    while (std::getline(file, s))
    {
        size_t pos = s.find(' ');

        int num_1 = stoi(s.substr(0, pos));
        int num_2 = stoi(s.substr(pos + 1));

        left.push_back(num_1);
        mp[num_2]++;
    }

    sort(left.begin(), left.end());

    long long ans = 0;
    for (size_t i = 0; i < left.size(); ++i)
    {
        ans += left[i] * mp[left[i]];
    }

    std::cout << ans << std::endl;
}