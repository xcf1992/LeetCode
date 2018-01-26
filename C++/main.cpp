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
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int length = s.size();
        for (int i = 1; i <= length / 2; i++) {
            if (s[i] == s[0] && length % i == 0) {
                string pattern = s.substr(0, i);
                bool match = true;
                for (int j = 1; j < length / i; j++) {
                    string sub = s.substr(j * i, i);
                    if (sub != pattern) {
                        match = false;
                        break;
                    }
                    if (match) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<string> v({"ABD","BCE","DEF","FFF"});
    vector<int> v2({7,2,5,10,8});
    cout << s.repeatedSubstringPattern("aabaaba") << endl;
}
