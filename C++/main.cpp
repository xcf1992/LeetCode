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
    string reorganize(string str) {
        int n = str.size();
        string result = "";
        
        int start = 0;
        int mid = (n - 1) / 2 + 1;
        while (start <= (n - 1) / 2) {
            result.push_back(str[start]);
            if (mid < n) {
                result.push_back(str[mid]);
            }
            start += 1;
            mid += 1;
        }
        return result;
    }
public:
    string reorganizeString(string S) {
        int n = S.size();
        vector<int> letter(26);
        for (char c: S) {
            letter[c - 'a'] += 1;
        }
        
        vector<pair<char, int>> charCounts;
        for (int i = 0; i < 26; i++) {
            if (letter[i] * 2 - 1 > n) {
                return "";
            }
            if (letter[i] > 0) {
                charCounts.push_back(make_pair(i + 'a', letter[i]));
            }
        }
        
        sort(charCounts.begin(), charCounts.end(), [](pair<char, int>& p1, pair<char, int>& p2) {
            return p1.second < p2.second;
        });
        string strSorted = "";
        for (int i = charCounts.size() - 1; i >= 0; i--) {
            strSorted += string(charCounts[i].second, charCounts[i].first);
        }
        return reorganize(strSorted);
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
    
    s.reorganizeString("aab");
}
