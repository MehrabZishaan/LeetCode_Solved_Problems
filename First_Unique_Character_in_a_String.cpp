// First_Unique_Character_in_a_String
// https://leetcode.com/problems/first-unique-character-in-a-string/
class Solution {
public:
    int firstUniqChar(string s) {
        int count[26] = {0};
        for (char c : s) {
            count[c - 'a'] += 1;
        }
        for (int i = 0; i < s.length(); ++i) {
            if (count[s[i] - 'a'] == 1) {
                return i;  // Return the correct index of the unique character
            }
        }
        return -1;
    }
};

