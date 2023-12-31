// 389. Find the Difference
// https://leetcode.com/problems/find-the-difference/
class Solution {
public:
    char findTheDifference(string s, string t) {
        char c = 0;
        for(char cs : s)
        {
            c ^= cs;
        }
        for(char ct : t)
        {
            c ^= ct;
        }
        return c;
    }
};