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
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = 0;
        int n = matrix[0].size();
        for (vector<int>& row : matrix) {
            for (int i = 1; i < n; ++i) {
                row[i] += row[i - 1];
            }
        }
        
        int result = 0;
        for (int col1 = 0; col1 < n; col1++) {
            for (int col2 = col1; col2 < n; ++col2) {
                unordered_map<int, int> sumCount;
                sumCount[0] = 1;
                int sum = 0;
                for (int row = 0; row < m; row++) {
                    sum += matrix[row][col2] - (col1 == 0 ? 0 : matrix[row][col1 - 1]);
                    result += sumCount[sum - target];
                    sumCount[sum] += 1;
                }
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> temp({0,1,3,50,75});
    vector<vector<int>> matrix({
        {0,1,0},
        {1,1,1},
        {0,1,0}
    });
    s.numSubmatrixSumTarget(matrix, 0);
}
