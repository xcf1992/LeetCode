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
    vector<int> dr{-1, 0, 1, 0};
    vector<int> dc{0, -1, 0, 1};
    int N = 0;
    
    int getArea(vector<vector<int>>& grid, int r, int c, int index) {
        int area = 1;
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr < 0 or nc < 0 or nr >= N or nc >= N) {
                continue;
            }
            if (grid[nr][nc] == 1) {
                grid[nr][nc] = index;
                area += getArea(grid, nr, nc, index);
            }
        }
        return area;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        N = grid.size();
        if (N == 0) {
            return 0;
        }
        
        vector<int> area(N * N + 2, 0);
        int index = 2;
        int result = 0;
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                if (grid[r][c] == 1) {
                    area[index] = getArea(grid, r, c, index);
                    result = max(result, area[index]);
                    index += 1;
                }
            }
        }
        
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                if (grid[r][c] == 0) {
                    unordered_set<int> visited;
                    for (int i = 0; i < 4; i++) {
                        int nr = r + dr[i];
                        int nc = c + dc[i];
                        if (nr < 0 or nc < 0 or nr >= N or nc >= N) {
                            continue;
                        }
                        if (grid[nr][nc] > 1) {
                            visited.insert(grid[nr][nc]);
                        }
                    }
                    int temp = 1;
                    for (int i : visited) {
                        temp += area[i];
                    }
                    result = max(result, temp);
                }
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<string> v({"ahjpjau","ja","ahbwzgqnuk","tnmlanowax"});
    vector<int> va({4,5,8,2});
    vector<vector<int>> vb({{3,0}});
    vector<string> v2({"a","cd"});
    vector<char> chars({'a','a','a','a','a','b','b','c'});
    
    vector<vector<int>> matrix1({
        {1,1,1,0,1,1,1,1},
        {1,0,0,0,0,1,1,1},
        {1,1,1,0,0,0,1,1},
        {1,1,0,0,0,0,0,0},
        {1,0,0,0,0,0,0,0},
        {1,0,0,0,0,0,0,0}
    });
    vector<vector<char>> matrix2({
        {'1','1','1','1','1','1','1','1'},
        {'1','1','1','1','1','1','1','0'},
        {'1','1','1','1','1','1','1','0'},
        {'1','1','1','1','1','0','0','0'},
        {'0','1','1','1','1','0','0','0'}
    });
    vector<vector<int>> matrix3({
        {1,0},
        {0,1}
    });
    
    s.largestIsland(matrix3);
    return 0;
}
