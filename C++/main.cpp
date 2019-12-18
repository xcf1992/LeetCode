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
#include "extra_data_types.hpp"
using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>> arr) {
        int m = arr.size();
        if (m == 0) {
            return 0;
        }
        int n = arr[0].size();

        int leastVal = INT_MAX;
        int leastCol = -1;
        int lessVal = INT_MAX;
        int lessCol = -1;
        for (int j = 0; j < n; ++j) {
            if (arr[0][j] < leastVal) {
                leastVal = arr[0][j];
                leastCol = j;
            }
            else if (arr[0][j] < lessVal) {
                lessVal = arr[0][j];
                leastCol = j;
            }
        }

        for (int i = 1; i < m; ++i) {
            int newLeastVal = INT_MAX;
            int newLeastCol = -1;
            int newLessVal = INT_MAX;
            int newLessCol = -1;
            for (int j = 0; j < n; ++j) {
                int sum = arr[i][j];
                if (j != leastCol) {
                    sum += leastVal;
                }
                else {
                    sum += lessVal;
                }

                if (sum < newLeastVal) {
                    newLeastVal = sum;
                    newLeastCol = j;
                }
                else if (sum < newLessVal) {
                    newLessVal = sum;
                    newLessCol = j;
                }
            }
            leastVal = newLeastVal;
            leastCol = newLeastCol;
            lessVal = newLessVal;
            lessCol = newLessCol;
        }
        return leastVal;
    }
};

int main() {
    vector<vector<int>> matrix({{-73,61,43,-48,-36},{3,30,27,57,10},{96,-76,84,59,-15},{5,-49,76,31,-7},{97,91,61,-46,67}});
    
    Solution s;
    s.minFallingPathSum(matrix);
}
