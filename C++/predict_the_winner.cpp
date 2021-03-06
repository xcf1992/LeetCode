/*
486. Predict the Winner
https://leetcode.com/problems/predict-the-winner/

Given an array of scores that are non-negative integers.
Player 1 picks one of the numbers from either end of the array
followed by the player 2 and then player 1 and so on.
Each time a player picks a number,
that number will not be available for the next player.
This continues until all the scores have been chosen.
The player with the maximum score wins.

Given an array of scores, predict whether player 1 is the winner.
You can assume each player plays to maximize his score.

Example 1:
Input: [1, 5, 2]
Output: False
Explanation: Initially, player 1 can choose between 1 and 2.
If he chooses 2 (or 1), then player 2 can choose from 1 (or 2) and 5. If player 2 chooses 5, then player 1 will be left with 1 (or 2).
So, final score of player 1 is 1 + 2 = 3, and player 2 is 5.
Hence, player 1 will never be the winner and you need to return False.

Example 2:
Input: [1, 5, 233, 7]
Output: True
Explanation: Player 1 first chooses 1. Then player 2 have to choose between 5 and 7. No matter which number player 2 choose, player 1 can choose 233.
Finally, player 1 has more score (234) than player 2 (12), so you need to return True representing player1 can win.

Note:
1 <= length of the array <= 20.
Any scores in the given array are non-negative integers and will not exceed 10,000,000.
If the scores of both players are equal, then player 1 is still the winner.
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
#include <stdio.h>
using namespace std;
/*
Given an array of scores that are non-negative integers.
 Player 1 picks one of the numbers from either end of the array followed by the player 2 and then player 1 and so on.
 Each time a player picks a number, that number will not be available for the next player.
 This continues until all the scores have been chosen. The player with the maximum score wins.
DP formula:
dp(i, j) = max(sum(i, j-1) - dp(i, j-1) + nums[j], sum(i+1, j) - dp(i+1, j) + nums[i])

Because sum(i, j-1) + nums[j] = sum(i, j) = nums[i] + sum(i+1, j), the formula can be simplified to
dp(i, j) = max(sum(i, j) - dp(i, j-1), sum(i, j) - dp(i+1, j))

If we do more deduction, we can eliminate the sum(i, j) from the formula:
Instead of storing the maximum score that player 1 can get in each sub array, we can store the diff between player1 and player 2. For example: if player 1 get A, player 2 get B, we can use dp' to store A-B.

if A = dp(i, j), then B = sum(i, j) - dp(i, j)

So dp'(i, j) = dp(i, j) - ( sum(i, j) - dp(i, j) ) = 2*dp(i, j) - sum(i, j), so
2*dp(i, j) = dp'(i, j) + sum(i, j) (this will be used below)

dp'(i, j) = dp(i, j) - ( sum(i, j) - dp(i, j) ) = 2dp(i, j) - sum(i, j)
= 2 * max( sum(i, j) - dp(i, j-1), sum(i, j) - dp(i+1, j) ) - sum(i, j)
= max(sum(i, j) - 2*dp(i, j-1), sum(i, j) - 2*dp(i+1, j) )
= max(sum(i, j) - ( dp'(i, j-1) + sum(i, j-1) ), sum(i, j) - ( dp'(i+1, j) + sum(i+1, j)))
= max(sum(i, j) - sum(i, j-1) - dp'(i, j-1), sum(i, j) - sum(i+1, j) - dp'(i+1, j))
= max(nums[j] - dp'(i, j-1), nums[i] - dp'(i+1, j))

Final formula: dp(i, j) = max(nums[j] - dp(i, j-1), nums[i] - dp(i+1, j))
*/
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            dp[i][i] = nums[i];
        }
        for (int len = 1; len < n; len++) {
            for (int i = 0; i + len < n; i++) {
                dp[i][i + len] = max(nums[i + len] - dp[i][i + len - 1], nums[i] - dp[i + 1][i + len]);
            }
        }
        return dp[0][n - 1] >= 0;
    }
};
