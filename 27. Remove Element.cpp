/*
Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The relative order of the elements may be changed.
Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.

If all assertions pass, then your solution will be accepted.



Example 1:

Input: nums = [3,2,2,3], val = 3
Output: 2, nums = [2,2,_,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 2.
It does not matter what you leave beyond the returned k (hence they are underscores).
*/

public class Solution {
    public int RemoveElement(int[] nums, int val) {

        if(nums.Length==0 || nums.Length==null)
         {
             return 0;
         }
        int i = 0;
        for (int j = 0; j < nums.Length; j++)
            {
                if (val != nums[j])
                {
                    nums[i] = nums[j];
                    i++;
                }
            }
        return i;
    }
}
