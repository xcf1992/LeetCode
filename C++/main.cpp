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
using namespace std;

class Solution {
private:
    string longestCommonSubsequence(string& str1, string& str2) {
        int n1 = str1.size();
        int n2 = str2.size();
        vector<vector<string>> dp(n1 + 1, vector<string>(n2 + 1, ""));
        for (int i = 1; i <= n1; ++i) {
            for (int j = 1; j <= n2; ++j) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + str1[i - 1];
                }
                else {
                    dp[i][j] = dp[i - 1][j].size() > dp[i][j - 1].size() ? dp[i - 1][j] : dp[i][j - 1];
                }
            }
        }
        return dp[n1][n2];
    }
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int i = 0;
        int j = 0;
        string lcs = longestCommonSubsequence(str1, str2);
        string result = "";
        for (char c : lcs) {
            while (i < str1.size() and c != str1[i]) {
                result.push_back(str1[i]);
                i += 1;
            }
            while (j < str2.size() and c != str2[j]) {
                result.push_back(str2[j]);
                j += 1;
            }
            result.push_back(c);
            i += 1;
            j += 1;
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> temp({5,4,3,2,1});
    vector<int> temp1({1,3,3,3,2});
    vector<vector<int>> matrix({
        {0,1},
        {1,0}
    });
    s.shortestCommonSupersequence("abac", "cab");
}
