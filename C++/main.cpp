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

class MyCalendar {
private:
    vector<pair<int, int>> events;
public:
    MyCalendar() {
    }
    
    bool book(int start, int end) {
        if (events.empty()) {
            events.push_back(pair<int, int>(start, end));
            return true;
        }
        if (end <= events.front().first) {
            events.insert(events.begin(), pair<int, int>(start, end));
            return true;
        }
        if (start >= events.back().second) {
            events.insert(events.end(), pair<int, int>(start, end));
            return true;
        }
        
        int st = 0;
        int en = events.size();
        while (st < en) {
            int mi = st + (en - st) / 2;
            if (start == events[mi].first) {
                return false;
            }
            if (start < events[mi].first) {
                en = mi;
            }
            else {
                st = mi + 1;
            }
        }
        
        if (end <= events[en].first && start >= events[en - 1].second) {
            events.insert(events.begin() + en, pair<int, int>(start, end));
            return true;
        }
        return false;
    }
};

int main() {
    MyCalendar calendar = MyCalendar();
    calendar.book(47, 50);
    calendar.book(33, 41);
    calendar.book(39, 45);
    calendar.book(33, 42);
    calendar.book(25, 32);
    calendar.book(26, 35);
    calendar.book(19, 25);
    calendar.book(3, 8);
    calendar.book(8, 13);
}
