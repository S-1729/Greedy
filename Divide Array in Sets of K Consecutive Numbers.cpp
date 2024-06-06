class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if(nums.size()%k!=0)
            return false;
        sort(begin(nums),end(nums));
        unordered_map<int,int>mp;
        for(auto &x:nums)
            mp[x]++;
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i])!=mp.end()){
                for(int j=0;j<k;j++){
                    if(mp.find(nums[i]+j)==mp.end())
                        return false;
                    else
                        mp[nums[i]+j]--;
                    if(mp[nums[i]+j]==0)
                        mp.erase(nums[i]+j);
                }
            }
        }
        return true;
    }
};

/*
    Given an array of integers nums and a positive integer k, check whether it is possible to divide this array into sets of k consecutive numbers.
    Return true if it is possible. Otherwise, return false.

    Example 1:
    Input: nums = [1,2,3,3,4,4,5,6], k = 4
    Output: true
    Explanation: Array can be divided into [1,2,3,4] and [3,4,5,6].

    Example 2:
    Input: nums = [3,2,1,2,3,4,3,4,5,9,10,11], k = 3
    Output: true
    Explanation: Array can be divided into [1,2,3] , [2,3,4] , [3,4,5] and [9,10,11].

    Example 3:
    Input: nums = [1,2,3,4], k = 3
    Output: false
    Explanation: Each array should be divided in subarrays of size 3.

    T.C : O(nlogn)
    S.C : O(n)
*/
