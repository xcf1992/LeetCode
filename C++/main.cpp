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
#include <numeric>
using namespace std;

class Solution {
private:
    vector<int> mergeArray(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> result(k);
        int idx1 = 0, idx2 = 0;
        int idx = 0;
        while(idx < k){
            if(compareArray(nums1, nums2, idx2, idx1)){
                result[idx] = nums1[idx1++];
            }else{
                result[idx] = nums2[idx2++];
            }
            idx++;
        }
        return result;
    }

    bool compareArray(vector<int>& nums1, vector<int>& nums2, int index1, int index2) {
        int len1 = nums1.size() - index1;
        if (len1 <= 0) {
            return false;
        }
        int len2 = nums2.size() - index2;
        if (len2 <= 0) {
            return true;
        }

        int len = max(len1, len2);
        for (int i = 0; i < len; ++i) {
            int d1 = index1 + i < nums1.size() ? nums1[index1 + i] : 0;
            int d2 = index2 + i < nums2.size() ? nums2[index2 + i] : 0;
            if (d1 != d2) {
                return d1 > d2;
            }
        }
        return true;
    }

    //get the largest k numbers when keeping the relative order
    vector<int> maxSubArray(vector<int>& nums, int k) {
        vector<int> result(k, 0);
        if (k == 0) {
            return result;
        }
        int n = nums.size();
        int index = 0;
        for (int i = 0; i < n; i++) {
            while (n - i + index > k and index > 0 and nums[i] > result[index - 1]) {
                index -= 1;
            }
            if (index < k) {
                result[index] = nums[i];
                index += 1;
            }
        }
        return result;
    }
public:
    vector<int> maxNumber(vector<int> nums1, vector<int> nums2, int k) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if (k == n1 + n2) {
            return mergeArray(nums1, nums2, k);
        }

        vector<int> result(k, 0);
        for (int i = 0; i <= k; i++) {
            if (i <= n1 and k - i <= n2) {
                vector<int> maxNums1 = maxSubArray(nums1, i);
                vector<int> maxNums2 = maxSubArray(nums2, k - i);
                vector<int> temp = mergeArray(nums1, nums2, k);
                if (compareArray(temp, result, 0, 0)) {
                    result = temp;
                }
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    s.maxNumber({3,4,6,5}, {9,1,2,5,8,3}, 5);
    return 0;
}
