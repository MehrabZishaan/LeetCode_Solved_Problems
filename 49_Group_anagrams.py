# https://leetcode.com/problems/group-anagrams/
# 49. Group Anagrams

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagram_groups = defaultdict(list)

        for s in strs:
            sorted_s = ''.join(sorted(s))
            anagram_groups[sorted_s].append(s)

        return list(anagram_groups.values())