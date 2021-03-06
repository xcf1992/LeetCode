/*
284. Peeking Iterator
https://leetcode.com/problems/peeking-iterator/

Given an Iterator class interface with methods:
next() and hasNext(),
design and implement a PeekingIterator that support the peek() operation --
it essentially peek() at the element that will be returned by the next call to next().

Here is an example.
Assume that the iterator is initialized to the beginning of the list: [1, 2, 3].

Call next() gets you 1, the first element in the list.
Now you call peek() and it returns 2, the next element. Calling next() after that still return 2.
You call next() the final time and it returns 3, the last element.
Calling hasNext() after that should return false.

Follow up:
How would you extend your design to be generic and work with all types, not just integer?
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
#include <set>
using namespace std;

class Iterator {
    struct Data;
    Data* data;
public:
    Iterator(const vector<int>& nums);
    Iterator(const Iterator& iter);
    virtual ~Iterator();
    // Returns the next element in the iteration.
    int next();
    // Returns true if the iteration has more elements.
    bool hasNext() const;
};

class PeekingIterator : public Iterator {
private:
    int m_next;
    bool m_hasnext;
public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        m_hasnext = Iterator::hasNext();
        if (m_hasnext) {
            m_next = Iterator::next();
        }
    }

    int peek() {
        return m_next;
    }

    int next() {
        int t = m_next;
        m_hasnext = Iterator::hasNext();
        if (m_hasnext) {
            m_next = Iterator::next();
        }
        return t;
    }

    bool hasNext() const {
        return m_hasnext;
    }
};
