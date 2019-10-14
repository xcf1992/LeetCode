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
private:
    void dfs(unordered_set<int>& result, vector<unordered_set<int>>& graph, unordered_set<int>& visited, unordered_set<int>& curPath, int cur, int start) {
        curPath.insert(cur);
        visited.insert(cur);
        for (int nxt: graph[cur]) {
            if (result.find(nxt) != result.end() and nxt != start) {
                result.erase(cur);
            }
            if (curPath.find(nxt) == curPath.end()) {
                dfs(result, graph, visited, curPath, nxt, start);
            }
        }
    }
public:
    vector<int> getMinimumVetricesCount(vector<vector<int>>& edges, int n) {
        vector<unordered_set<int>> graph(n);
        for (vector<int>& edge : edges) {
            graph[edge[0]].insert(edge[1]);
        }

        unordered_set<int> result;
        unordered_set<int> visited;
        for (int i = 0; i < n; ++i) {
            if (visited.find(i) == visited.end()) {
                result.insert(i);
                visited.insert(i);
                unordered_set<int> curPath;
                dfs(result, graph, visited, curPath, i, i);
            }
        }
        return vector<int>(result.begin(), result.end());
    }
};

int main() {
    vector<int> temp1({1,2,3});
    Solution s;

    vector<vector<int>> matrix({
        {2,9},
        {3,3},
        {3,5},
        {3,7},
        {4,8},
        {5,8},
        {6,6},
        {7,4},
        {8,7},
        {9,3},
        {9,6}
    });
    s.getMinimumVetricesCount(matrix, 10);

    vector<vector<int>> matrix2({
        {1,2,2,3,5},
        {3,2,3,4,4},
        {2,4,5,3,1},
        {6,7,1,4,5},
        {5,1,1,2,4}
    });
    vector<string> words({"hot","dot","dog","lot","log","cog"});
    TreeNode* r1 = new TreeNode(0);
    TreeNode* r2 = new TreeNode(1);
    TreeNode* r3 = new TreeNode(3);
    r1 -> left = r2;
}
