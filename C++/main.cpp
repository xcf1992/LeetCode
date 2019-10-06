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
public:
    int longestSubstringLength(string s) {
        int n = s.size();
        if (n < 3) {
            return n;
        }

        int result = 2;
        int cur = 2;
        for (int i = 2; i < n; ++i) {
            if (s[i] != s[i - 1] or s[i] != s[i - 2]) {
                cur += 1;
            }
            else {
                result = max(result, cur);
                cur = 2;
            }
        }
        return max(result, cur);
    }
};

int main() {
    Solution s;
    s.longestSubstringLength("babba");

    vector<int> temp1({1,3,3,3,2});
    vector<vector<int>> matrix({
        {0,1},
        {1,2},
        {2,1},
        {1,0},
        {0,2},
        {0,0},
        {1,1}
    });
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
