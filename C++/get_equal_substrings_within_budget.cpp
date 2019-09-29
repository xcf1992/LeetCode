/*
1208. Get Equal Substrings Within Budget
https://leetcode.com/problems/get-equal-substrings-within-budget/

You are given two strings s and t of the same length.
You want to change s to t.
Changing the i-th character of s to i-th character of t costs |s[i] - t[i]| that is,
the absolute difference between the ASCII values of the characters.

You are also given an integer maxCost.
Return the maximum length of a substring of s
that can be changed to be the same as the corresponding substring of twith a cost less than or equal to maxCost.

If there is no substring from s that can be changed to its corresponding substring from t, return 0.

Example 1:
Input: s = "abcd", t = "bcdf", cost = 3
Output: 3
Explanation: "abc" of s can change to "bcd". That costs 3, so the maximum length is 3.

Example 2:
Input: s = "abcd", t = "cdef", cost = 3
Output: 1
Explanation: Each charactor in s costs 2 to change to charactor in t, so the maximum length is 1.

Example 3:
Input: s = "abcd", t = "acde", cost = 0
Output: 1
Explanation: You can't make any change, so the maximum length is 1.

Constraints:
1 <= s.length, t.length <= 10^5
0 <= maxCost <= 10^6
s and t only contain lower case English letters.
*/
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <numeric>
using namespace std;

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        vector<int> cost(n, 0);
        for (int i = 0; i < n; ++i) {
            cost[i] = abs(s[i] - t[i]);
        }

        int left = 0;
        int result = 0;
        int curCost = 0;
        for (int i = 0; i < n; ++i) {
            curCost += cost[i];
            while (curCost > maxCost) {
                curCost -= cost[left];
                left += 1;
            }
            result = max(result, i - left + 1);
        }
        return result;
    }
};
