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
private:
    vector<int> root;
    
    int findRoot(int island) {
        if (island != root[island]) {
            island = root[island];
        }
        return island;
    }
    
    void check(int x, int y, int m, int n, int island, int &count) {
        if (x < 0 || y < 0 || x >= m || y >= n) {
            return;
        }
        
        int newIsland = x * m + y;
        if (root[newIsland] != -1) {
            int newRoot = findRoot(newIsland);
            int curRoot = findRoot(island);
            if (curRoot != newRoot) {
                root[curRoot] = newRoot;
                count -= 1;
            }
        }
    }
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<int> result;
        root = vector<int>(m * n, -1);
        int count = 0;
        for (pair<int, int>& pos : positions) {
            int row = pos.first;
            int col = pos.second;
            int island = row * m + col;
            root[island] = island;
            count += 1;
            
            check(row - 1, col, m, n, island, count);
            check(row + 1, col, m, n, island, count);
            check(row, col - 1, m, n, island, count);
            check(row, col + 1, m, n, island, count);
            result.push_back(count);
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<string> v({"ABD","BCE","DEF","FFF"});
    vector<int> v2({4,2});
    vector<char> chars({'a','a','a','a','a','b','b','c'});
    vector<vector<int>> matrix({{4,3}, {2,3}, {2,1}, {5,0}, {0,1}});
    vector<pair<int, int>> fuxk;
    fuxk.push_back(make_pair(4,3));
    fuxk.push_back(make_pair(2,3));
    fuxk.push_back(make_pair(2,1));
    fuxk.push_back(make_pair(5,0));
    
    s.numIslands2(6, 5, fuxk);
}
