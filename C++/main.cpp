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
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<vector<pair<int, int>>> distance;
        for (vector<int>& time : times) {
            distance[time[0]].push_back(make_pair(time[1], time[2]));
        }
        
        vector<int> delay(N + 1, INT_MAX);
        queue<pair<int, int>> nodes;
        
        nodes.push(make_pair(K, 0));
        while (!nodes.empty()) {
            int curNode = nodes.front().first;
            int curTime = nodes.front().second;
            delay[curNode] = min(delay[curNode], curTime);
            nodes.pop();
            
            for (pair<int, int>& next : distance[curNode]) {
                if (delay[next.first] > curTime + next.second) {
                    nodes.push(make_pair(next.first, curTime + next.second));
                }
            }
        }
        
        int result = 0;
        for (int i = 1; i < delay.size(); i++) {
            if (delay[i] == INT_MAX) {
                return -1;
            }
            result = max(result, delay[i]);
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<string> v({"ahjpjau","ja","ahbwzgqnuk","tnmlanowax"});
    vector<int> v1({1,0,0,0,0,1});
    vector<int> v2({0,4});
    vector<char> chars({'a','a','a','a','a','b','b','c'});
    vector<vector<int>> matrix({{2,1,1}, {2,3,1}, {3,4,1}});
    vector<pair<int, int>> fuxk;
    fuxk.push_back(make_pair(4,3));
    fuxk.push_back(make_pair(2,3));
    fuxk.push_back(make_pair(2,1));
    fuxk.push_back(make_pair(5,0));
    
    s.networkDelayTime(matrix, 4, 2);
}
