/*
1704. Determine if String Halves Are Alike
https://leetcode.com/problems/determine-if-string-halves-are-alike/

You are given a string s of even length.
Split this string into two halves of equal lengths,
and let a be the first half and b be the second half.

Two strings are alike if they have the same number of vowels
('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U').
Notice that s contains uppercase and lowercase letters.

Return true if a and b are alike. Otherwise, return false.

Example 1:
Input: s = "book"
Output: true
Explanation: a = "bo" and b = "ok". a has 1 vowel and b has 1 vowel. Therefore, they are alike.
Example 2:
Input: s = "textbook"
Output: false
Explanation: a = "text" and b = "book". a has 1 vowel whereas b has 2. Therefore, they are not alike.
Notice that the vowel o is counted twice.
Example 3:
Input: s = "MerryChristmas"
Output: false
Example 4:
Input: s = "AbCdEfGh"
Output: true

Constraints:
2 <= s.length <= 1000
s.length is even.
s consists of uppercase and lowercase letters.
*/
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <stdio.h>
#include <set>
#include <numeric>
using namespace std;

class Solution {
public:
    bool halvesAreAlike(string s) {
        unordered_set<char> set = {'a', 'e', 'i', 'o', 'u', 'A', 'I', 'E', 'O', 'U'};
        int i = 0, j = s.size() / 2, cnt = 0;
        while (j < s.size()) {
            if (set.find(s[i]) != set.end()) {
                cnt++;
            }
            if (set.find(s[j]) != set.end()) {
                cnt--;
            }
            i++;
            j++;
        }
        return cnt == 0;
    }
};