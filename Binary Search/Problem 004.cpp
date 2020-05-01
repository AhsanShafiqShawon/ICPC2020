/*
Problem 004
Search in Rotated Sorted Array

Algorithm

As in the normal binary search, we keep two pointers (i.e. start and end) to track the search scope.
At each iteration, we reduce the search scope into half, by moving either the start or end pointer
to the middle (i.e. mid) of the previous search scope.

Here are the detailed breakdowns of the algorithm:

    Initiate the pointer start to 0, and the pointer end to n - 1.

    Perform standard binary search. While start <= end:

        Take an index in the middle mid as a pivot.

        If nums[mid] == target, the job is done, return mid.

        Now there could be two situations:
            Pivot element is larger than the first element in the array, i.e. the subarray from the first element
            to the pivot is non-rotated.
            
            - If the target is located in the non-rotated subarray: go left: `end = mid - 1`.
            - Otherwise: go right: `start = mid + 1`.
            
            Pivot element is smaller than the first element of the array, i.e. the rotation index is somewhere between
            0 and mid. It implies that the sub-array from the pivot element to the last one is non-rotated.
            
            - If the target is located in the non-rotated subarray: go right: `start = mid + 1`.
            - Otherwise: go left: `end = mid - 1`.
         
         We're here because the target is not found. Return -1.
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int L=0;
        int R=n-1;
        int mid;
        while(L<=R)
        {
            mid=L+(R-L)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[L]<=nums[mid])
            {
                if(target>=nums[L] && target<nums[mid])
                    R=mid-1;
                else
                    L=mid+1;
            }
            else
            {
                if(target<=nums[R] && target>nums[mid])
                    L=mid+1;
                else
                    R=mid-1;
            }
        }
        return -1;
    }
};
