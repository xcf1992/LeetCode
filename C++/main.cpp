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
    int maxProfit(vector<int>& prices, int fee) {
        int haveStockProfit = INT_MIN;
        int noStockProfit = 0;
        for (int price : prices) {
            int temp = noStockProfit;
            noStockProfit = max(noStockProfit, haveStockProfit + price);
            haveStockProfit = max(haveStockProfit, temp - price - fee);
        }
        return noStockProfit;
    }
};



int main() {
    Solution s;
    vector<int> v{1,3,2,8,4,9};
    s.maxProfit(v, 2);
}
