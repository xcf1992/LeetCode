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
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size();
        int n = maze[0].size();
        
        queue<pair<int, int>> position;
        vector<vector<int>> distance(m, vector<int>(n, INT_MAX));
        position.push(make_pair(start[0], start[1]));
        distance[start[0]][start[1]] = 0;
        
        int result = INT_MAX;
        while (!position.empty()) {
            pair<int, int> curPos = position.front();
            position.pop();
            
            int curX = curPos.first;
            int curY = curPos.second;
            int curDis = distance[curX][curY];
            if (curX == destination[0] && curY == destination[1]) {
                result = min(result, curDis);
                continue;
            }
            
            // move down
            int move = 0;
            while (curX + 1 < m && maze[curX + 1][curY] != 1) {
                curX += 1;
                move += 1;
            }
            if (distance[curX][curY] > curDis + move) {
                distance[curX][curY] = curDis + move;
                position.push(make_pair(curX, curY));
            }
            
            //move up
            curX = curPos.first;
            move = 0;
            while (curX - 1 >= 0 && maze[curX - 1][curY] != 1) {
                curX -= 1;
                move += 1;
            }
            if (distance[curX][curY] > curDis + move) {
                distance[curX][curY] = curDis + move;
                position.push(make_pair(curX, curY));
            }
            
            // move left
            curX = curPos.first;
            move = 0;
            while (curY + 1 < n && maze[curX][curY + 1] != 1) {
                curY += 1;
                move += 1;
            }
            if (distance[curX][curY] > curDis + move) {
                distance[curX][curY] = curDis + move;
                position.push(make_pair(curX, curY));
            }
            
            //move right
            curY = curPos.second;
            move = 0;
            while (curY - 1 >= 0 && maze[curX][curY - 1] != 1) {
                curY -= 1;
                move += 1;
            }
            if (distance[curX][curY] > curDis + move) {
                distance[curX][curY] = curDis + move;
                position.push(make_pair(curX, curY));
            }
        }
        
        return result == INT_MAX ? -1 : result;
    }
};

int main() {
    Solution s;
    vector<string> v({"ABD","BCE","DEF","FFF"});
    vector<int> v1({4,4});
    vector<int> v2({0,4});
    vector<char> chars({'a','a','a','a','a','b','b','c'});
    vector<vector<int>> matrix({{0,0,1,0,0}, {0,0,0,0,0}, {0,0,0,1,0}, {1,1,0,1,1}, {0,0,0,0,0}});
    vector<pair<int, int>> fuxk;
    fuxk.push_back(make_pair(4,3));
    fuxk.push_back(make_pair(2,3));
    fuxk.push_back(make_pair(2,1));
    fuxk.push_back(make_pair(5,0));
    
    s.shortestDistance(matrix, v2, v1);
}
