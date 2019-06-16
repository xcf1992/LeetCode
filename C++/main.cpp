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
private:
    int n = 0;
    
    bool isValid(int r, int c, vector<vector<int>>& grid) {
        return r >= 0 and c >= 0 and r < n and c < n and grid[r][c] == 0;
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        n = grid.size();
        if (grid[0][0] == 1 or grid[n - 1][n - 1] == 1) {
            return -1;
        }
        
        queue<pair<int, int>> bfs;
        bfs.push({0, 0});
        vector<vector<int>> diff({{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {-1, -1}, {1, -1}, {1, 1}, {-1, 1}});
        while (!bfs.empty()) {
            int r = bfs.front().first;
            int c = bfs.front().second;
            bfs.pop();
            if (r == n - 1 and c == n - 1) {
                return grid[r][c] + 1;
            }
            
            for (int i = 0; i < diff.size(); ++i) {
                int nr = r + diff[i][0];
                int nc = c + diff[i][1];
                if (!isValid(r, c, grid)) {
                    continue;
                }
                grid[nr][nc] = grid[r][c] + 1;
                bfs.push({nr, nc});
            }
        }
        return -1;
    }
};

int main() {
    Solution s;
    vector<int> temp({5,4,3,2,1});
    vector<int> temp1({1,3,3,3,2});
    vector<vector<int>> matrix({
        {0,1},
        {1,0}
    });
    s.shortestPathBinaryMatrix(matrix);
}
