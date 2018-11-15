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
    vector<int> rDiff{0, 0, 1, -1};
    vector<int> cDiff{1, -1, 0, 0};
public:
    int shortestPathAllKeys(vector<string> grid) {
        int m = grid.size();
        if (m == 0) {
            return -1;
        }
        int n = grid[0].size();
        
        unordered_map<int, unordered_set<int>> visited;
        queue<pair<int, int>> bfs;
        int target = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '@') {
                    bfs.push({i * n + j, 0});
                    visited[i * n + j].insert(0);
                }
                else if (grid[i][j] >= 'A' and grid[i][j] <= 'F') {
                    target |= (1 << (grid[i][j] - 'A'));
                }
            }
        }
        
        int step = 0;
        while (!bfs.empty()) {
            int curSize = bfs.size();
            for (int i = 0; i < curSize; i++) {
                int row = bfs.front().first / n;
                int col = bfs.front().first % n;
                int keyMap = bfs.front().second;
                bfs.pop();
                
                if (keyMap == target) {
                    return step;
                }
                
                for (int d = 0; d < 4; d++) {
                    int nr = row + rDiff[d];
                    int nc = col + cDiff[d];
                    int have = keyMap;
                    if (nr < 0 or nr >= m or nc < 0 or nc >= n or grid[nr][nc] == '#') {
                        continue;
                    }
                    if (grid[nr][nc] >= 'A' and grid[nr][nc] <= 'F') {
                        int key = 1 << (grid[nr][nc] - 'A');
                        if (!(have & key)) {
                            continue;
                        }
                    }
                    else if (grid[nr][nc] >= 'a' and grid[nr][nc] <= 'f') {
                        int key = 1 << (grid[nr][nc] - 'a');
                        have |= key;
                    }
                    int pos = nr * n + nc;
                    if (visited.find(pos) == visited.end() or visited[pos].find(have) == visited[pos].end()) {
                        visited[pos].insert(have);
                        bfs.push({pos, have});
                    }
                }
            }
            step += 1;
        }
        return -1;
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
    
    int x = s.shortestPathAllKeys({"@...a",".###A","b.BCc"});
    return 0;
}
