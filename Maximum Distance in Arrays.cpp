class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int minm=arrays[0].front(),maxm=arrays[0].back(),ans=0;
        for(int i=1;i<arrays.size();i++){
            int currMin=arrays[i].front();
            int currMax=arrays[i].back();
            ans=max(ans,abs(currMax-minm));
            ans=max(ans,abs(maxm-currMin));
            minm=min(minm,currMin);
            maxm=max(maxm,currMax);
        }
        return ans;
    }
};

/*
    You are given m arrays, where each array is sorted in ascending order.  
    You can pick up two integers from two different arrays (each array picks one) and calculate the distance. We define the distance between two integers a and b to be their absolute difference |a - b|.
    Return the maximum distance.
    
    Example 1:
    Input: arrays = [[1,2,3],[4,5],[1,2,3]]
    Output: 4
    Explanation: One way to reach the maximum distance 4 is to pick 1 in the first or third array and pick 5 in the second array.
    
    Example 2:
    Input: arrays = [[1],[1]]
    Output: 0
    
    T.C : O(n)
*/
