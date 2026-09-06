class Solution {
public:
   int  helper(int i,int j,string s,string t,vector<vector<int>>& dp)
   {
    if(j<0)return 1;
     if(i<0)return 0;
     if(dp[i][j]!=-1)return dp[i][j];
    int cnt=0;
         if(s[i]==t[j])
         {
            cnt=helper(i-1,j,s,t,dp)+helper(i-1,j-1,s,t,dp);
         }
         else 
         {
            cnt=helper(i-1,j,s,t,dp);
         }
         return dp[i][j]=cnt;
   }
    int numDistinct(string s, string t) {
        int m=s.size();
        int n=t.size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        helper(m-1,n-1,s,t,dp);
        return dp[m-1][n-1];
    }
};