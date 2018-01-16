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
    int minSwapsCouples(vector<int>& row) {
        int result = 0;
        vector<int> pos;
        
        for (int i = 0; i < row.size(); i++) {
            pos[row[i]] = i;
        }
        for (int i = 0; i < row.size(); i += 2) {
            int odd = row[i] % 2 == 0 ? 1 : -1;
            if (row[i] + odd != row[i + 1]) {
                int couple = pos[row[i] + odd];
                swap(pos[row[i] + odd], pos[row[i + 1]]);
                swap(row[i + 1], row[couple]);
                result += 1;
            }
        }
        
        return result;
    }
};

int main() {
    Solution s;
    vector<int> v{0,2,1,3};
    s.minSwapsCouples(v);
}
