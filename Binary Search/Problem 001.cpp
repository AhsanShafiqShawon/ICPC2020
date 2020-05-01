/*Problem 001
Given a sorted (in ascending order) integer array nums of n elements and a target value,
write a function to search target in nums. If target exists, then return its index, otherwise return -1.*/

/*
Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4
*/

class Solution {
  public:
  int search(vector<int>& nums, int target) {
    int pivot, left = 0, right = nums.size() - 1;
    while (left <= right) {
      pivot = left + (right - left) / 2;
      if (nums[pivot] == target) return pivot;
      if (target < nums[pivot]) right = pivot - 1;
      else left = pivot + 1;
    }
    return -1;
  }
};

/*
Algorithm

    Initialise left and right pointers : left = 0, right = n - 1.

    While left <= right :

        Compare middle element of the array nums[pivot] to the target value target.

            If the middle element is the target target = nums[pivot] : return pivot.

            If the target is not yet found :

                If target < nums[pivot], continue the search on the left right = pivot - 1.

                Else continue the search on the right left = pivot + 1.
*/
