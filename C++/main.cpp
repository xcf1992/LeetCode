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
    int minX;
    int maxX;
    int minY;
    int maxY;
    
    void dfs(vector<vector<bool>>& visited, vector<vector<char>>& image, int x, int y) {
        int m = image.size();
        int n = image[0].size();
        if (x < 0 || y < 0 || x >= m || y >= n || visited[x][y] || image[x][y] == 0) {
            return;
        }
        
        minX = min(x, minX);
        minY = min(y, minY);
        maxX = max(x, maxX);
        maxY = max(y, maxY);
        visited[x][y] = true;
        dfs(visited, image, x - 1, y);
        dfs(visited, image, x + 1, y);
        dfs(visited, image, x, y - 1);
        dfs(visited, image, x, y + 1);
        return;
    }
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        int m = image.size();
        if (m == 0) {
            return 0;
        }
        int n = image[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        minX = maxX = x;
        minY = maxY = y;
        return (maxX - minX) * (maxY - minY);
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
    
    s.canMeasureWater(22003, 31237, 1);
}
