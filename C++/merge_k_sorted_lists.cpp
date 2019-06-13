/*
23. Merge k Sorted Lists

Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:

Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6
*/
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

class myComp {
public:
    bool operator()(ListNode* a, ListNode* b) {
        return a -> val > b -> val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, myComp> minHeap;
        for (int i = 0; i != lists.size(); i++) {
            if (lists[i] != nullptr) {
                minHeap.push(lists[i]);
            }
        }
        
        ListNode* dummy = new ListNode(-1);
        ListNode* pre = dummy;
        while (!minHeap.empty()) {
            ListNode* cur = minHeap.top();
            minHeap.pop();

            pre -> next = cur;
            pre = pre -> next;
            if (cur -> next) {
                minHeap.push(cur -> next);
            }
        }
        return dummy->next;
    }
};