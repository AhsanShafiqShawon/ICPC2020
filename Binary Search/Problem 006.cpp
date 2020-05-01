/*
Problem 006
Find Peak Element

A peak element is an element that is greater than its neighbors.
Given an input array nums, where nums[i] ≠ nums[i+1], find a peak element and return its index.
The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
You may imagine that nums[-1] = nums[n] = -∞.

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.

Input: nums = [1,2,1,3,5,6,4]
Output: 1 or 5 
Explanation: Your function can return either index number 1 where the peak element is 2, 
             or index number 5 where the peak element is 6.
*/

/*
Algorithm

We can view any given sequence in nums array as alternating ascending and descending sequences. By making use of this,
and the fact that we can return any peak as the result, we can make use of Binary Search to find the required peak element.

In case of simple Binary Search, we work on a sorted sequence of numbers and try to find out the required number by reducing the
search space at every step. In this case, we use a modification of this simple Binary Search to our advantage. We start off by finding
the middle element, mid from the given nums array. If this element happens to be lying in a descending sequence of numbers. or a local
falling slope(found by comparing nums[i] to its right neighbour), it means that the peak will always lie towards the left of this
element. Thus, we reduce the search space to the left of mid(including itself) and perform the same process on left subarray.

If the middle element, mid lies in an ascending sequence of numbers, or a rising slope(found by comparing nums[i] to its right
neighbour), it obviously implies that the peak lies towards the right of this element. Thus, we reduce the search space to the right
of midmidmid and perform the same process on the right subarray.

In this way, we keep on reducing the search space till we eventually reach a state where only one element is remaining in the search
space. This single element is the peak element. To see how it works, let's consider the three cases:

Case 1. [5, 4, 3, 2, 1]
In this case, we firstly find 3 as the middle element. Since it lies on a falling slope, we reduce the search space to [5, 4, 3].
For this subarray, 4 happens to be the middle element, which again lies on a falling slope, reducing the search space to [5, 4].
Now, 5 acts as the middle element and it lies on a falling slope, reducing the search space to [5] only. Thus, 5 is returned as the
peak correctly.

Case 2. [1, 2, 3, 4, 5]
In this case, we firstly find 3 as the middle element. Since it lies on a rising slope, we reduce the search space to [4, 5]. Now, 4
acts as the middle element for this subarray and it lies on a rising slope, reducing the search space to [5] only. Thus, 5 is returned
as the peak correctly.

Case 3. [2, 3, 4, 5, 1]
In this case, the peak lies somewhere in the middle. The first middle element is 4. It lies on a rising slope, indicating that the peak
lies towards its right. Thus, the search space is reduced to [5, 1]. Now, 5 happens to be the on a falling slope(relative to its right
neighbour), reducing the search space to [5] only. Thus, 5 is identified as the peak element correctly.
*/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int L=0;
        int R=n-1;
        int mid;
        while(L<R)
        {
            mid=L+(R-L)/2;
            if(nums[mid]>nums[mid+1])
                R=mid;
            else
                L=mid+1;
        }
        return L;
    }
};
