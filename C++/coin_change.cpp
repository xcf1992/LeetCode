/*
 You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
 
 Example 1:
 
 Input: coins = [1, 2, 5], amount = 11
 Output: 3
 Explanation: 11 = 5 + 5 + 1
 Example 2:
 
 Input: coins = [2], amount = 3
 Output: -1
 Note:
 You may assume that you have an infinite number of each kind of coin.
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
using namespace std;

/*
 dynamic problem
 dp[i] means minimum number coins used to make amount i
 dp[j] = min{dp[j - coins[x]]}, while x >= 0 && x < coins.size() && j >= coins[x]
 */
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        sort(coins.begin(), coins.end());
        for (int i = 1; i <= amount; i++) {
            for (int j = coins.size() - 1; j >= 0; j--) {
                if (i >= coins[j] && dp[i - coins[j]] != INT_MAX) {
                    dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
                }
            }
        }
        return dp.back() == INT_MAX ? -1 : dp.back();
    }
};