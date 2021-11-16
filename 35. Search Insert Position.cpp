/*
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.



Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int middle,left=0, right=nums.size()-1;

        while(left<=right)
        {
            middle=(left+right)/2;

            if(nums[middle]==target)
            {
                return middle;
            }
            else if(nums[middle]<target)
            {
                left=middle+1;
            }
            else
            {
                right=middle-1;
            }
        }

        return left;
    }
};
