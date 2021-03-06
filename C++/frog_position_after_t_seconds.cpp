/*
1377. Frog Position After T Seconds
https://leetcode.com/problems/frog-position-after-t-seconds/

Given an undirected tree consisting of n vertices numbered from 1 to n.
A frog starts jumping from the vertex 1.
In one second, the frog jumps from its current vertex to another unvisited vertex
if they are directly connected.
The frog can not jump back to a visited vertex.
In case the frog can jump to several vertices it jumps randomly to one of them with the same probability,
otherwise, when the frog can not jump to any unvisited vertex it jumps forever on the same vertex.

The edges of the undirected tree are given in the array edges, where edges[i] = [fromi, toi]
means that exists an edge connecting directly the vertices fromi and toi.

Return the probability that after t seconds the frog is on the vertex target.

Example 1:
Input: n = 7, edges = [[1,2],[1,3],[1,7],[2,4],[2,6],[3,5]], t = 2, target = 4
Output: 0.16666666666666666
Explanation: The figure above shows the given graph. The frog starts at vertex 1, jumping with 1/3 probability to the vertex 2 after second 1 and then jumping with 1/2 probability to vertex 4 after second 2. Thus the probability for the frog is on the vertex 4 after 2 seconds is 1/3 * 1/2 = 1/6 = 0.16666666666666666.

Example 2:
Input: n = 7, edges = [[1,2],[1,3],[1,7],[2,4],[2,6],[3,5]], t = 1, target = 7
Output: 0.3333333333333333
Explanation: The figure above shows the given graph. The frog starts at vertex 1, jumping with 1/3 = 0.3333333333333333 probability to the vertex 7 after second 1.

Example 3:
Input: n = 7, edges = [[1,2],[1,3],[1,7],[2,4],[2,6],[3,5]], t = 20, target = 6
Output: 0.16666666666666666

Constraints:
1 <= n <= 100
edges.length == n-1
edges[i].length == 2
1 <= edges[i][0], edges[i][1] <= n
1 <= t <= 50
1 <= target <= n
Answers within 10^-5 of the actual value will be accepted as correct.
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
#include <cfloat>
#include <stdio.h>
#include <map>
using namespace std;
/*
The answer lies in the examples.
We can use a simple DFS to reach the target node while storing the probablity of reaching that node at t by multiplying by the number of children that node has.
Once we reach that target and depth required in the problem we can return that probablity.
Edge cases:

When when either the node is somewhere in the middle and we reach that node but not in target time, we simply return 0.
When it's a leaf node but the time is less than the required one, it'll simply jump until the goal time, thus we can return the same probablity.
*/
class Solution {
private:
    vector<vector<int>> G;
    vector<bool> seen;
    int target;

    double dfs(int cur, int t) {
        if (cur != 1 && G[cur].size() == 1 || t == 0) {
            return cur == target;
        }

        seen[cur] = true;
        double res = 0;
        for (int nex : G[cur]) {
            if (!seen[nex]) {
                res += dfs(nex, t - 1);
            }
        }
        return res / (G[cur].size() - (cur != 1));
    }
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        if (n == 1) {
            return 1.0;
        }

        this -> target = target;
        G = vector<vector<int>>(n + 1);
        for (auto e : edges) {
            G[e[0]].push_back(e[1]);
            G[e[1]].push_back(e[0]);
        }
        seen = vector<bool>(n + 1, false);
        return dfs(1, t);
    }
};
