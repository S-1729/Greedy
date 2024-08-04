class Solution {
  public:
    int maxMeetings(int n, int start[], int end[]) {
        vector<pair<int,int>>arr;
        for(int i=0;i<n;i++)
            arr.push_back({start[i],end[i]});
        auto lambda=[&](pair<int,int>&p1,pair<int,int>&p2){
            return ((p1.second<p2.second) || (p1.second==p2.second && p1.first<=p2.first));
        };
        sort(arr.begin(),arr.end(),lambda);
        int ans=1,endTime=arr[0].second;
        for(int i=1;i<n;i++){
            if(endTime<arr[i].first){
                ans++;
                endTime=arr[i].second;
            }
        }
        return ans;
    }
}

/*
    You are given timings of n meetings in the form of (start[i], end[i]) where start[i] is the start time of meeting i and end[i] is the finish time of meeting i. 
    Return the maximum number of meetings that can be accommodated in a single meeting room, when only one meeting can be held in the meeting room at a particular time.     
    Note: The start time of one chosen meeting can't be equal to the end time of the other chosen meeting.
    
    Examples :
    
    Input: n = 6, start[] = [1, 3, 0, 5, 8, 5], end[] =  [2, 4, 6, 7, 9, 9]
    Output: 4
    Explanation: Maximum four meetings can be held with given start and end timings. The meetings are - (1, 2), (3, 4), (5,7) and (8,9)
    
    Input: n = 3, start[] = [10, 12, 20], end[] = [20, 25, 30]
    Output: 1
    Explanation: Only one meetings can be held with given start and end timings.
    
    T.C : O(nlogn)
    S.C : O(n)
*/
