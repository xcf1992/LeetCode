/*
1052. Grumpy Bookstore Owner
https://leetcode.com/problems/grumpy-bookstore-owner/

Today, the bookstore owner has a store open for customers.length minutes.
Every minute, some number of customers (customers[i]) enter the store,
and all those customers leave after the end of that minute.

On some minutes, the bookstore owner is grumpy.
If the bookstore owner is grumpy on the i-th minute, grumpy[i] = 1, otherwise grumpy[i] = 0.
When the bookstore owner is grumpy, the customers of that minute are not satisfied,
otherwise they are satisfied.

The bookstore owner knows a secret technique to keep themselves not grumpy for X minutes straight,
but can only use it once.
Return the maximum number of customers that can be satisfied throughout the day.

Example 1:
Input: customers = [1,0,1,2,1,1,7,5], grumpy = [0,1,0,1,0,1,0,1], X = 3
Output: 16
Explanation: The bookstore owner keeps themselves not grumpy for the last 3 minutes.
The maximum number of customers that can be satisfied = 1 + 1 + 1 + 1 + 7 + 5 = 16.

Note:
1 <= X <= customers.length == grumpy.length <= 20000
0 <= customers[i] <= 1000
0 <= grumpy[i] <= 1
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
#include <map>
#include <set>
#include <numeric>
using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int n = customers.size();
        int satisfied = 0;
        for (int i = 0; i < n; ++i) {
            if (grumpy[i] == 0) {
                satisfied += customers[i];
            }
        }

        int result = satisfied;
        for (int i = 0; i < X; i++) {
            if (grumpy[i] == 1) {
                result += customers[i];
            }
        }

        satisfied = result;
        for (int i = X; i < n; ++i) {
            if (grumpy[i - X] == 1) {
                satisfied -= customers[i - X];
            }
            if (grumpy[i] == 1) {
                satisfied += customers[i];
            }
            result = max(result, satisfied);
        }
        return result;
    }
};
