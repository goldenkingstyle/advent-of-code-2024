#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

int main()
{
    std::freopen("input/input.txt", "r", stdin);
    std::string s;
    std::unordered_map<int, std::vector<int>> mp;

    while (std::getline(std::cin, s))
    {
        if (s == "")
            break;

        int pos = s.find('|');
        int a = stoi(s.substr(0, pos));
        int b = stoi(s.substr(pos + 1));

        mp[a].push_back(b);
    }

    for (auto &p : mp)
    {
        std::sort(p.second.begin(), p.second.end());
    }

    long long ans = 0;
    while (std::getline(std::cin, s))
    {
        std::vector<int> v;

        int pos;
        while ((pos = s.find(',')) != std::string::npos)
        {
            int n = stoi(s.substr(0, pos));
            v.push_back(n);
            s = s.substr(pos + 1);
        }
        v.push_back(stoi(s));

        bool b = true;
        for (int i = 0; i < v.size() - 1; ++i)
        {
            std::vector<int> &next = mp[v[i + 1]];

            auto it = std::lower_bound(next.begin(), next.end(), v[i]);

            if (it != next.end() && *it == v[i])
            {
                b = false;
                break;
            }
        }

        if (b)
        {
            ans += v[v.size() / 2];
        }
    }

    std::cout << ans << std::endl;
}