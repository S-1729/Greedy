class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>mp;
        int ans=0;
        for(auto &ch:s){
            mp[ch]++;
            if(mp[ch]%2==0){
                ans+=mp[ch];
                mp[ch]=0;
            }
        }
        for(auto &it:mp){
            if(it.second%2==1){
                ans++;
                break;
            }
        }
        return ans;
    }
};

/*
    Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.
    Letters are case sensitive, for example, "Aa" is not considered a palindrome.
    
    Example 1:
    Input: s = "abccccdd"
    Output: 7
    Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.
    
    Example 2:
    Input: s = "a"
    Output: 1
    Explanation: The longest palindrome that can be built is "a", whose length is 1.
    
    Example 3:
    Input: s = "aabbbccc"
    Output: 7
    Explanation: The longest palindrome that can be built is "abcccba" or "acbbbca", whose length is 7.

    T.C : O(n)
    S.C : O(52)
*/
