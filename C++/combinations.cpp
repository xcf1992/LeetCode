/*
 77. Combinations

 Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

 Example:

 Input: n = 4, k = 2
 Output:
 [
 [2,4],
 [3,4],
 [2,3],
 [1,2],
 [1,3],
 [1,4],
 ]
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
    void GetResult(int n, int k, int level, vector <int> &solution, vector <vector <int>> &result) {
        if (solution.size() == k) {
            result.push_back(solution);
        }

        for (int i = level; i != n + 1; i++) {
            solution.push_back(i);
            GetResult(n, k, i + 1, solution, result);
            solution.pop_back();
        }
    }

    vector<vector<int> > combine(int n, int k) {
        vector <vector <int>> result;
        vector <int> solution;
        GetResult(n, k, 1, solution, result);
        return result;
    }
};