/*
213. House Robber II

You are a professional robber planning to rob houses along a street.
Each house has a certain amount of money stashed.
All houses at this place are arranged in a circle.
That means the first house is the neighbor of the last one.
Meanwhile, adjacent houses have security system connected and it will automatically contact the police
if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house,
determine the maximum amount of money you can rob tonight without alerting the police.

Example 1:
Input: [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2),
             because they are adjacent houses.

Example 2:
Input: [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.
*/
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <stdio.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return nums.front();
        }
        if (n == 2) {
            return max(nums[0], nums[1]);
        }

        int oneBefore = nums[0];
        int twoBefore = 0;
        int result = max(oneBefore, twoBefore);
        for (int i = 1; i < n - 1; i++) {
            int cur = max(twoBefore + nums[i], oneBefore);
            result = max(result, cur);
            twoBefore = oneBefore;
            oneBefore = cur;
        }

        oneBefore = nums[1];
        twoBefore = 0;
        for (int i = 2; i < n; i++) {
            int cur = max(twoBefore + nums[i], oneBefore);
            result = max(result, cur);
            twoBefore = oneBefore;
            oneBefore = cur;
        }
        return result;
    }
};
