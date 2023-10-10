/// https://leetcode.com/problems/contains-duplicate/
/// 217. Contains Duplicate

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_set<int> hashset;

        for (int n : nums) {
            if (hashset.find(n) != hashset.end()) {
                return true;  // Found a duplicate
            }
            hashset.insert(n);
        }

        return false;  // No duplicates found
    }
};