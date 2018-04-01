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
    string addBoldTag(string s, vector<string>& dict) {
        if (s.empty() || dict.empty()) {
            return s;
        }
        
        vector<pair<int, int>> pos;
        for (string word : dict) {
            for (int i = 0; (i = s.find(word, i)) != string::npos; i++) {
                pos.push_back(make_pair(i, i + word.size()));
            }
        }
        
        sort(pos.begin(), pos.end(), [](pair<int, int>& a, pair<int, int>& b) {
            return a.first < b.first || (a.first == b.first && a.second < b.second);
        });
        
        vector<pair<int, int>> merge;
        for (int i = 0, j = -1; i < pos.size(); i++) {
            if (j < 0 || pos[i].first > merge[j].second) {
                merge.push_back(pos[i]);
                j += 1;
            }
            else {
                merge[j].second = max(merge[j].second, pos[i].second);
            }
        }
        
        for (int i = merge.size(); i >= 0; i--) {
            s.insert(merge[i].second, "</b>");
            s.insert(merge[i].first, "<b>");
        }
        return s;
    }
};

int main() {
    Solution s;
    vector<string> v({"abc","123"});
    vector<int> v1({1,0,0,0,0,1});
    vector<int> v2({0,4});
    vector<char> chars({'a','a','a','a','a','b','b','c'});
    vector<vector<int>> matrix({{1,2,3}, {4,5}, {1,2,3}});
    vector<pair<int, int>> fuxk;
    fuxk.push_back(make_pair(4,3));
    fuxk.push_back(make_pair(2,3));
    fuxk.push_back(make_pair(2,1));
    fuxk.push_back(make_pair(5,0));
    
    s.addBoldTag("abcxyz123", v);
}
