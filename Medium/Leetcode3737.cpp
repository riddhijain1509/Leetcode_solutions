class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        unordered_map<int,int> mpp;
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            mpp.clear();
            for(int j=i;j<n;j++)
            {
               mpp[nums[j]]++;
               int len=(j-i+1);
               if(mpp[target]>len/2)
               {
                ans++;
               }
            }
        }
        return ans;
    }
};