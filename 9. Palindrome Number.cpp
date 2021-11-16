/*
9. Palindrome Number
Easy

4388

1917

Add to List

Share
Given an integer x, return true if x is palindrome integer.

An integer is a palindrome when it reads the same backward as forward. For example, 121 is palindrome while 123 is not.



Example 1:

Input: x = 121
Output: true
*/

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || (x % 10 == 0 && x != 0))
        {
            return false;
        }
        else if(x==0)
        {
            return true;
        }

        int reverse=0;

        while(x>reverse)
        {
            reverse=(reverse*10)+(x%10);
            x=x/10;
        }
        if(reverse==x)
        {
            return true;
        }
        else if(reverse/10==x)
        {
            return true;
        }
        else
        {
          return false;
        }
    }
};
