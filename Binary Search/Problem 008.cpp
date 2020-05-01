/*
Problem 008
Search for a Range

Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
*/

/*
Algorithm

The overall algorithm works fairly similarly to the linear scan approach, except for the subroutine used to find the left and rightmost
indices themselves. Here, we use a modified binary search to search a sorted array, with a few minor adjustments. First, because we are
locating the leftmost (or rightmost) index containing target (rather than returning true iff we find target), the algorithm does not
terminate as soon as we find a match. Instead, we continue to search until lo == hi and they contain some index at which target can be
found.

The other change is the introduction of the left parameter, which is a boolean indicating what to do in the event that
target == nums[mid]; if left is true, then we "recurse" on the left subarray on ties. Otherwise, we go right. To see why this is
correct, consider the situation where we find target at index i. The leftmost target cannot occur at any index greater than i, so we
never need to consider the right subarray. The same argument applies to the rightmost index.
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(binary_search(nums.begin(),nums.end(),target) == 0)
        {
            return vector<int>{-1,-1};
        }
        int up = upper_bound(nums.begin(),nums.end(),target) - nums.begin() - 1;
        int lp = lower_bound(nums.begin(),nums.end(),target) - nums.begin();
        return vector<int>{lp,up};
    }
};
