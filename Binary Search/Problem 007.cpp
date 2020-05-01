/*
Problem 007
Find Minimum in Rotated Sorted Array

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

Find the minimum element.
You may assume no duplicate exists in the array.

Input: [3,4,5,1,2] 
Output: 1

Input: [4,5,6,7,0,1,2]
Output: 0
*/

/*
Algorithm

If the array is not rotated and the array is in ascending order, then last element > first element.

All the elements to the left of inflection point > first element of the array.
All the elements to the right of inflection point < first element of the array.

1. Find the mid element of the array.
2. If mid element > first element of array this means that we need to look for the inflection point on the right of mid.
3. If mid element < first element of array this that we need to look for the inflection point on the left of mid.
4. We stop our search when we find the inflection point, when either of the two conditions is satisfied:
    nums[mid] > nums[mid + 1] Hence, mid+1 is the smallest.
    nums[mid - 1] > nums[mid] Hence, mid is the smallest.
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int L=0;
        int R=n-1;
        int mid;
        if(n==1)
            return nums[0];
        if(nums[0]<nums[R])
            return nums[0];
        while(L<=R)
        {
            mid=L+(R-L)/2;
            if(nums[mid]>nums[mid+1])
                return nums[mid+1];
            else if(nums[mid-1]>nums[mid])
                return nums[mid];
            else if(nums[0]<nums[mid])
                L=mid+1;
            else
                R=mid-1;
        }
        return -1;
    }
};
