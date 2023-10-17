// 125. Valid Palindrome
// https://leetcode.com/problems/valid-palindrome/

/**
 * @param {string} s
 * @return {boolean}
 */
var isPalindrome = function(s) {
    new_string = s.replace(/[^A-Z0-9]/ig, "");
    new_string = new_string.toLowerCase();
    reversed_string = new_string.split('').reverse().join('');
    return new_string == reversed_string
};