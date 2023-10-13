// https://leetcode.com/problems/group-anagrams/
// 49. Group Anagrams

class Solution
{
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> &strs)
    {
        std::unordered_map<std::string, std::vector<std::string>> anagramGroups;

        for (const std::string &s : strs)
        {
            std::string sorted_s = s;
            std::sort(sorted_s.begin(), sorted_s.end());
            anagramGroups[sorted_s].push_back(s);
        }

        std::vector<std::vector<std::string>> result;
        for (const auto &entry : anagramGroups)
        {
            result.push_back(entry.second);
        }

        return result;
    }
};