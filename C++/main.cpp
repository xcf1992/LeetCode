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
    int findMaximumXOR(vector<int>& nums) {
        int result = 0;
        int mask = 0;
        unordered_set<int> values;
        for (int i = 31; i >= 0; i--) {
            values.clear();
            mask |= (1 << i);
            for (int num : nums) {
                values.insert(mask & num);
            }
            
            int temp = result | (1 << i);
            for (int value : values) {
                if (values.find(temp ^ value) != values.end()) {
                    result = temp;
                    break;
                }
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> v = {3,10,5,25,2,8};
    s.findMaximumXOR(v);
}
