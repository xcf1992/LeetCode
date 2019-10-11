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
    int getMatchedCount(string target, string guess) {
        int result = 0;
        for (int i = 0; i < target.size(); ++i) {
            result += target[i] == guess[i] ? 1 : 0;
        }
        return result;
    }
public:
    string guestNumber(string target) {
        int n = target.size();
        vector<int> count(10, 0);
        string noMatched = "";
        for (int i = 0; i <= 9; ++i) {
            int matched = getMatchedCount(target, string(4, '0' + i));
            count[i] = matched;
            if (count[i] == 0 and noMatched == "") {
                noMatched = string(4, '0' + i);
            }
        }

        string result = noMatched;
        for (int i = 0; i <= 9; ++i) if (count[i] != 0) {
            string temp = result;
            int curMatched = getMatchedCount(target, temp);
            for (int k = 0; k < temp.size() and count[i] > 0; ++k) {
                temp[k] = '0' + i;
                int cur = getMatchedCount(target, temp);
                if (cur == curMatched + 1) {
                    count[i] -= 1;
                    curMatched = cur;
                }
                else {
                    temp[k] = result[k];
                }
            }
            result = temp;
        }
        return result;
    }
};

int main() {
    vector<int> temp1({1,2,3,5,6,6,6,6,6,8});
    Solution s;
    s.guestNumber("1223");

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
