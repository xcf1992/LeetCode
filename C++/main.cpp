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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        int n = nums.size();
        vector<int> result;
        double mid = 0 - b / (2 * a);
        int left = 0;
        int right = n - 1;
        while (left < n - 1 && ((double)nums[left + 1]) < mid) {
            left += 1;
        }
        while (right > 0 && ((double)nums[right - 1]) >= mid) {
            right -= 1;
        }
        
        while (left >= 0 && right < n) {
            double rightVal = nums[right];
            double leftVal = nums[left];
            if (abs(rightVal - mid) > abs(leftVal - mid)) {
                result.push_back(a * nums[left] * nums[left] + b * nums[left] + c);
                left -= 1;
            }
            else {
                result.push_back(a * nums[right] * nums[right] + b * nums[right] + c);
                right += 1;
            }
        }
        
        while (left >= 0) {
            result.push_back(a * nums[left] * nums[left] + b * nums[left] + c);
            left -= 1;
        }
        while (right < n) {
            result.push_back(a * nums[right] * nums[right] + b * nums[right] + c);
            right += 1;
        }
        if (a < 0) {
            reverse(result.begin(), result.end());
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<string> v({"ABD","BCE","DEF","FFF"});
    vector<int> v2({-4,-2,2,4});
    vector<char> chars({'a','a','a','a','a','b','b','c'});
    vector<vector<int>> matrix({{0,1},{1,2},{3,4}});
    vector<pair<int, int>> fuxk;
    fuxk.push_back(make_pair(0, 1));
    fuxk.push_back(make_pair(1, 2));
    fuxk.push_back(make_pair(3, 4));
    
    s.sortTransformedArray(v2, 1, 3, 5);
}
