class Solution {
  public:
    string smallestNumber(int s, int d) {
        if(s>(9*d))
            return "-1";
        string num(d,'0');
        for(int i=1;i<=9;i++){
            int diff=s-i;
            if(diff<=(9*(d-1))){
                num[0]='0'+i;
                s-=i;
                break;
            }
        }

        for(int i=d-1;i>=1;i--){
            if(s>9){
                num[i]='9';
                s-=9;
            }
            else{
                num[i]='0'+s;
                s=0;
            }
        }
        return num;
    }
};

/*
    Given two integers s and d. The task is to find the smallest number such that the sum of its digits is s and the number of digits in the number are d. 
    Return a string that is the smallest possible number. If it is not possible then return -1.
    
    Examples:
    
    Input: s = 9, d = 2
    Output: 18 
    Explanation: 18 is the smallest number possible with the sum of digits = 9 and total digits = 2.
    
    Input: s = 20, d = 3 
    Output: 299 
    Explanation: 299 is the smallest number possible with the sum of digits = 20 and total digits = 3.
    
    T.C : O(d)
*/
