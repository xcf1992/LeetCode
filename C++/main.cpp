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
private:
    bool isBorder(int r, int c, int m, int n, vector<vector<int>>& grid) {
        if (r == 0 or r == m - 1 or c == 0 or c == n - 1) {
            return true;
        }

        int color = grid[r][c];
        if (color == grid[r - 1][c] and color == grid[r + 1][c] and color == grid[r][c - 1] and color == grid[r][c + 1]) {
            return false;
        }
        return true;
    }
public:
    vector<vector<int>> colorBorder(vector<vector<int>> grid, int r0, int c0, int color) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<pair<int, int>> border;
        queue<pair<int, int>> bfs;
        bfs.push({r0, c0});
        visited[r0][c0] = true;

        vector<int> rDiff = {0, 0, 1, -1};
        vector<int> cDiff = {1, -1, 0, 0};
        while (!bfs.empty()) {
            int row = bfs.front().first;
            int col = bfs.front().second;
            bfs.pop();

            if (isBorder(row, col, m, n, grid)) {
                border.push_back({row, col});
            }

            for (int i = 0; i < 4; ++i) {
                int nRow = row + rDiff[i];
                int nCol = col + cDiff[i];
                if (nRow >= 0 and nRow < m and nCol >= 0 and nCol < n and !visited[nRow][nCol] and grid[nRow][nCol] == grid[r0][c0]) {
                    visited[nRow][nCol] = true;
                    bfs.push({nRow, nCol});
                }
            }
        }

        for (pair<int, int>& b : border) {
            grid[b.first][b.second] = color;
        }
        return grid;
    }
};

int main() {
    Solution s;
    s.colorBorder({{1,1,1}, {1,1,1}, {1,1,1}}, 1, 1, 2);
    return 0;
}
