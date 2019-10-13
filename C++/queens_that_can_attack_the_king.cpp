/*
1222. Queens That Can Attack the King
https://leetcode.com/problems/queens-that-can-attack-the-king/

On an 8x8 chessboard, there can be multiple Black Queens and one White King.

Given an array of integer coordinates queens that represents the positions of the Black Queens,
and a pair of coordinates king that represent the position of the White King,
return the coordinates of all the queens (in any order) that can attack the King.

Example 1:
Input: queens = [[0,1],[1,0],[4,0],[0,4],[3,3],[2,4]], king = [0,0]
Output: [[0,1],[1,0],[3,3]]
Explanation:
The queen at [0,1] can attack the king cause they're in the same row.
The queen at [1,0] can attack the king cause they're in the same column.
The queen at [3,3] can attack the king cause they're in the same diagnal.
The queen at [0,4] can't attack the king cause it's blocked by the queen at [0,1].
The queen at [4,0] can't attack the king cause it's blocked by the queen at [1,0].
The queen at [2,4] can't attack the king cause it's not in the same row/column/diagnal as the king.

Example 2:
Input: queens = [[0,0],[1,1],[2,2],[3,4],[3,5],[4,4],[4,5]], king = [3,3]
Output: [[2,2],[3,4],[4,4]]

Example 3:
Input: queens = [[5,6],[7,7],[2,1],[0,7],[1,6],[5,1],[3,7],[0,3],[4,0],[1,2],[6,3],[5,0],[0,4],[2,2],[1,1],[6,4],[5,4],[0,0],[2,6],[4,5],[5,2],[1,4],[7,5],[2,3],[0,5],[4,2],[1,0],[2,7],[0,1],[4,6],[6,1],[0,6],[4,3],[1,7]], king = [3,4]
Output: [[2,3],[1,4],[1,6],[3,7],[4,3],[5,4],[4,5]]

Constraints:
1 <= queens.length <= 63
queens[0].length == 2
0 <= queens[i][j] < 8
king.length == 2
0 <= king[0], king[1] < 8
At most one piece is allowed in a cell.
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
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<bool>> grid(9, vector<bool>(9, false));
        for (vector<int>& queen : queens) {
            grid[queen[0]][queen[1]] = true;
        }

        vector<vector<int>> result;
        vector<vector<int>> moves({{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}});
        for (int i = 0; i < moves.size(); ++i) {
            int kr = king[0];
            int kc = king[1];
            while (kr + moves[i][0] >= 0 and kc + moves[i][1] >= 0 and kr + moves[i][0] < 8 and kc + moves[i][1] < 8) {
                kr += moves[i][0];
                kc += moves[i][1];
                if (grid[kr][kc]) {
                    result.push_back({kr, kc});
                    break;
                }
            }
        }
        return result;
    }
};

// wrong: consider that some black queen will block others to attack
class Solution1 {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> result;
        int kr = king[0];
        int kc = king[1];
        for (vector<int>& queen : queens) {
            if (queen[0] == kr or queen[1] == kc) {
                result.push_back(queen);
            }
            if (kr + kc == queen[0] + queen[1]) {
                result.push_back(queen);
            }
            if (8 + kr - kc == 8 + queen[0] - queen[1]) {
                result.push_back(queen);
            }
        }
        return result;
    }
};
