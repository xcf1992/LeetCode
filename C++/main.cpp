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
    string pushDominoes(string dominoes) {
        int count = dominoes.size();
        if (count <= 1) {
            return dominoes;
        }
        
        vector<int> distance(count, INT_MAX);
        for (int i = 0; i < dominoes.size(); i++) {
            if (dominoes[i] == 'R') {
                distance[i] = 0;
            }
            else if (dominoes[i - 1] == 'R' && dominoes[i] == '.') {
                dominoes[i] = 'R';
                distance[i] = distance[i - 1] + 1;
            }
        }
        
        int dis = INT_MAX;
        for (int i = count - 1; i >= 0; i--) {
            if (dominoes[i] == 'L') {
                dis = 0;
            }
            else if (dominoes[i + 1] == 'L') {
                dis += 1;
                if (dominoes[i] == '.') {
                    dominoes[i] = 'L';
                }
                else if (dominoes[i] == 'R') {
                    if (dis == distance[i]) {
                        dominoes[i] = '.';
                    }
                    if (dis < distance[i]) {
                        dominoes[i] = 'L';
                    }
                }
            }
        }
        return dominoes;
    }
};

int main() {
    Solution s;
    vector<string> v({"ahjpjau","ja","ahbwzgqnuk","tnmlanowax"});
    vector<int> v1({10,5,2,6});
    vector<int> v2({0,4});
    vector<char> chars({'a','a','a','a','a','b','b','c'});
    vector<vector<int>> matrix({{1,2,2,3,5}, {3,2,3,4,4}, {2,4,5,3,1}, {6,7,1,4,5}, {5,1,1,2,4}});
    vector<pair<int, int>> fuxk;
    fuxk.push_back(make_pair(4,3));
    fuxk.push_back(make_pair(2,3));
    fuxk.push_back(make_pair(2,1));
    fuxk.push_back(make_pair(5,0));
    
    s.pushDominoes("RL");
}
