class Solution {
public:

    bool check(string &a, string &b)
    {
        if(b.size()!=a.size()+1)
            return false;

        int i=0,j=0;

        while(j<b.size())
        {
            if(i<a.size() && a[i]==b[j])
            {
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }

        return i==a.size();
    }

    int longestStrChain(vector<string>& words) {

        int n=words.size();

        sort(words.begin(),words.end(),
        [](string &a,string &b)
        {
            return a.size()<b.size();
        });

        vector<int> dp(n,1);

        int ans=1;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(check(words[j],words[i]))
                {
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }

            ans=max(ans,dp[i]);
        }

        return ans;
    }
};