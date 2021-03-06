/*
1787. Make the XOR of All Segments Equal to Zero
https://leetcode.com/problems/make-the-xor-of-all-segments-equal-to-zero/

You are given an array nums​​​ and an integer k​​​​​.
The XOR of a segment [left, right]
where left <= right is the XOR of all the elements with indices between left and right,
inclusive: nums[left] XOR nums[left+1] XOR ... XOR nums[right].

Return the minimum number of elements to change in the array such that the XOR of all segments of size k​​​​​​ is equal to zero.

Example 1:
Input: nums = [1,2,0,3,0], k = 1
Output: 3
Explanation: Modify the array from [1,2,0,3,0] to from [0,0,0,0,0].
Example 2:
Input: nums = [3,4,5,2,1,7,3,4,7], k = 3
Output: 3
Explanation: Modify the array from [3,4,5,2,1,7,3,4,7] to [3,4,7,3,4,7,3,4,7].
Example 3:
Input: nums = [1,2,4,1,2,5,1,2,6], k = 3
Output: 3
Explanation: Modify the array from [1,2,4,1,2,5,1,2,6] to [1,2,3,1,2,3,1,2,3].

Constraints:
1 <= k <= nums.length <= 2000
​​​​​​0 <= nums[i] < 210
*/
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <stdio.h>
#include <set>
#include <numeric>
using namespace std;
/*
First K length subarray:
						a1^a2^a3^.....^ak=0 ;

Second K length subarray :
					    a2^a3^a4^....^ak+1=0 ;

On combining both :
						a1^(a2^a3^....^ak)^(a2^a3^....^ak)^a[k+1] =0
						a1^a[k+1]=0
Therefore it is easy to see that for any i and j :

						a[i%k]^a[j%k] = 0 ;
					->  a[i%k]=a[j%k] ;

Hence, a[1] = a[k+1] = a[2k+1] = ...
	   a[2] = a[k+2] = a[2k+2] = ...
	   a[3] = a[k+3] = a[2k+3] = ...
	   .
	   .
	   .
	   a[k] = a[2k] = a[3k] = ...

So we just need to obtain the first k length subarray and the rest would be determined by it.

for 0 <= i < k

Let set S[i] : { a[i] , a[i+k],a[i+2k],a[i+3k],.... }

Let freq[] be the array storing frequencies of all the elements of this set

Now to change a[i] to any value, we must change all the elements of S[i] to the new value

Let we wish to change a[i] to X

Then Cost/changes required = (count of elements in set S[i])-freq[X] ;

Now for each a[i], we can convert it to any non-negative number less than 1025

so we will use 2-D DP

dp[i][j] : minimum number of changes required in first i elements such that the xor value = j

For any a[i], we can either convert it to one of the element from set S[i] or to any other number less than 1025
*/
class Solution
{
public:
    int minChanges(vector<int> &nums, int k)
    {

        int freq[k][1025];
        memset(freq, 0, sizeof freq);

        for (int i = 0; i < nums.size(); i++)
            freq[i % k][nums[i]]++;

        int dp[k + 1][1025];

        for (int i = 0; i <= k; i++)
            for (int j = 0; j < 1025; j++)
                dp[i][j] = 1e9 + 5;

        dp[0][0] = 0;
        int prevMin = 0; // it stores the min changes done till now, to obtain any xor value
        int n = nums.size();

        for (int i = 0; i < k; i++)
        { // iterate through each a[i]

            // changing a[i] to one of the values from the Set S[i]

            for (int j = 0; j < 1025; j++) // the previous xor value till (i-1)th element

                for (int z = i; z < n; z += k) // convert a[i] to any value from set S[i] (nums[z])

                    if ((j ^ nums[z]) < 1025)
                        //int(ceil((n-i)*1.0/k)) : count of elements in set S[i]
                        dp[i + 1][j ^ nums[z]] = min(dp[i + 1][j ^ nums[z]], dp[i][j] + int(ceil((n - i) * 1.0 / k)) - freq[i][nums[z]]);

            int prevMin2 = 1e9 + 5;

            // Change a[i] to any other value so as to get the xor value = j

            for (int j = 0; j < 1025; j++)
            {

                // prevMin is the min change done till i-1 elements

                // we are changing a[i] to a value such that the overall xor value is now equal to j

                dp[i + 1][j] = min(dp[i + 1][j], int(ceil((n - i) * 1.0 / k) + prevMin));

                prevMin2 = min(prevMin2, dp[i + 1][j]);
            }

            prevMin = prevMin2; // update prevMin for next iteration
        }
        return dp[k][0];
    }
};
