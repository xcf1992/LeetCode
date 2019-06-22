/*
135. Candy
There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?

Example 1:

Input: [1,0,2]
Output: 5
Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.
Example 2:

Input: [1,2,2]
Output: 4
Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
             The third child gets 1 candy because it satisfies the above two conditions.

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
#include <numeric>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n <= 1) {
            return ratings.size();
        }

        vector<int> candy(n, 1);
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i - 1] and candy[i] <= candy[i - 1]) {
                candy[i] = candy[i - 1] + 1;
            }
        }

        int result = n;
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1] and candy[i] <= candy[i + 1]) {
                candy[i] = candy[i + 1] + 1;
            }
            result += candy[i] - 1;
        }
        result += candy.back() - 1;
        return result;
    }
};