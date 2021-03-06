/*
829. Consecutive Numbers Sum
https://leetcode.com/problems/consecutive-numbers-sum/

Given a positive integer N,
how many ways can we write it as a sum of consecutive positive integers?

Example 1:
Input: 5
Output: 2
Explanation: 5 = 5 = 2 + 3

Example 2:
Input: 9
Output: 3
Explanation: 9 = 9 = 4 + 5 = 2 + 3 + 4

Example 3:
Input: 15
Output: 4
Explanation: 15 = 15 = 8 + 7 = 4 + 5 + 6 = 1 + 2 + 3 + 4 + 5

Note:
1 <= N <= 10 ^ 9.
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
The thought process goes like this- Given a number N,
we can possibly write it as a sum of 2 numbers, 3 numbers, 4 numbers and so on.
Let's assume the fist number in this series be x. Hence, we should have

x + (x+1) + (x+2)+...+ k terms = N
kx + k*(k-1)/2 = N implies
kx = N - k*(k-1)/2

So, we can calculate the RHS for every value of k and
if it is a multiple of k then we can construct a sum of N using k terms starting from x.

Now, the question arises, till what value of k should we loop for?
That's easy. In the worst case, RHS should be greater than 0. That is
N - k*(k-1)/2 > 0 which implies
k*(k-1) < 2N which can be approximated to
k*k < 2N ==> k < sqrt(2N)
Hence the overall complexity of the algorithm is O(sqrt(N))

PS: OJ expects the answer to be 1 greater than the number of possible ways
because it considers N as being written as N itself.
It's confusing since they ask for sum of consecutive integers which implies at least 2 numbers.
But to please OJ, we should start count from 1.
*/
class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int result = 0;
        for (int k = 1; k * (k - 1) < 2 * N; k++) {
            if ((2 * N - k * k + k) % (2 * k) == 0) {
                result += 1;
            }
        }
        return result;
    }
};
