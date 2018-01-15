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
    vector<int> partitionLabels(string S) {
        vector<int> result;
        int sum = 0;
        unordered_map<char, int> labels;
        for (int i = 0; i < S.size(); i++) {
            char c = S[i];
            if (labels.find(c) == labels.end()) {
                labels[c] = i;
                result.push_back(1);
                sum += 1;
            }
            else {
                int pos = labels[c];
                int temp = i;
                while (temp > pos) {
                    temp -= result.back();
                    sum -= result.back();
                    result.pop_back();
                }
                result.push_back(i - sum + 1);
                sum += result.back();
                labels[c] = i;
            }
        }
        return result;
    }
};


int main() {
    Solution s;
    vector<int> v{3,4,5,1,2};
    s.partitionLabels("ababcbacadefegdehijhklij");
}
