/*
Given a string s, find the length of the longest substring without repeating characters.



Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>dict(256,-1);
        int mxlen=0,start=-1;
        for(int i=0;i<s.length();i++)
        {
            if(dict[s[i]]>start)
                start=dict[s[i]];
            dict[s[i]]=i;
            mxlen=max(mxlen,i-start);
        }
        return mxlen;
    }
};
