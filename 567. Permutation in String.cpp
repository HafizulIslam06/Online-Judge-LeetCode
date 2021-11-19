/*
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.



Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
*/

class Solution {
public:
//     so the approach is like this...
//     we create a hashmap of string s1(storing frequency of each character) and now traversing the  string s2 while analysing the window of s1.size
//         for each window of s1.size we compare
//             if both hashmaps are equal or not
//                 if they are equal we got a hit
//                 else continue the search for upcoming window

//     basically a permutaion is essentially an annagram of string so...

    bool checkInclusion(string s1, string s) {
        int  ump[26]={0},tmp[26]={0};
        for(char ch:s1)ump[ch-'a']++;

        int i=0,j=0;

        while(j<s.length()){
            tmp[s[j++]-'a']++;

            if(j-i == s1.length()){
                bool f=1;
                for(int k=0;k<26;++k){
                    if(ump[k]!=tmp[k]){
                        f=0;
                        break;
                    }
                }
                if(f)return 1;
                --tmp[s[i++]-'a'] ;
            }
        }

        return 0;

    }
};
