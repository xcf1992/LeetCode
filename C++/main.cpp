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
    int numMatchingSubseq(string S, vector<string>& words) {
        vector<vector<int>> position(26, vector<int>());
        for (int i = 0; i < S.size(); i++) {
            position[S[i] - 'a'].push_back(i);
        }
        
        int result = 0;
        for (string word : words) {
            if (word.size() == 1 && !position[word[0] - 'a'].empty()) {
                result += 1;
                continue;
            }
            
            int curPos = 0;
            for (int i = 0; i < word.size(); i++) {
                if (position[word[i] - 'a'].empty()) {
                    break;
                }
                
                if (i == 0) {
                    curPos = position[word[i] - 'a'].front();
                }
                else {
                    bool find = false;
                    for (int newPos : position[word[i] - 'a']) {
                        if (newPos > curPos) {
                            find = true;
                            curPos = newPos;
                        }
                    }
                    if (find) {
                        if (i == word.size() - 1) {
                            result += 1;
                        }
                    }
                    else {
                        break;
                    }
                }
            }
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
    vector<vector<int>> matrix({{1,2,3}, {4,5}, {1,2,3}});
    vector<pair<int, int>> fuxk;
    fuxk.push_back(make_pair(4,3));
    fuxk.push_back(make_pair(2,3));
    fuxk.push_back(make_pair(2,1));
    fuxk.push_back(make_pair(5,0));
    
    s.numMatchingSubseq("dsahjpjauf", v);
}
