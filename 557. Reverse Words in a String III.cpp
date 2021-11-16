/*
Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.



Example 1:

Input: s = "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
*/

class Solution {
public:

    string reverseWords(string s) {
         int beg=0,end;char temp;
        for(int i=0;i<=s.size();i++)
        {
            if(s[i]==' ' || s[i]==NULL)
            {
                end=i-1;
                while(beg<end)
                {
                    temp=s[beg];
                    s[beg]=s[end];
                    s[end]=temp;
                    beg++;
                    end--;
                }
                beg=i+1;
            }
        }
        return s;
    }
};
