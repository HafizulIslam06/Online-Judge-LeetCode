/*
Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once.
The relative order of the elements should be kept the same.
Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.

If all assertions pass, then your solution will be accepted.



Example 1:

Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
*/

public class Solution {
    public int RemoveDuplicates(int[] nums) {

         if(nums.Length==0 || nums.Length==null)
         {
             return 0;
         }
            int i = 0;
            for (int j = 1; j < nums.Length; j++)
            {
                if (nums[i] != nums[j])
                {
                    i++;
                    nums[i] = nums[j];
                }
            }
        return i + 1;
    }
}
