class Solution {
public:
    int numberOfSubstrings(string s) {
        int a=-1,b=-1,c=-1;
        int ans=0;
        int i=0;
        for(char ch:s)
        {
            if(ch=='a')
            {
                a=i;
            }
            if(ch=='b')
            {
                b=i;
            }
            if(ch=='c')
            {
                c=i;
            }
            ans+=min({a,b,c})+1;
            i++;
        }
        return ans;
    }
};
