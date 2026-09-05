class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int> mini(nums.size(),INT_MAX);
        vector<int> maxi(nums.size(),INT_MIN);
        mini[nums.size()-1]=nums[nums.size()-1];
        maxi[0]=nums[0];
        for(int i=1;i<nums.size();i++)
        {
           maxi[i]=max(maxi[i-1],nums[i]);
        }
        for(int i=nums.size()-2;i>=0;i--)
        {
            mini[i]=min(mini[i+1],nums[i]);
        }
        for(int i=0;i<nums.size();i++)
        {
            if(maxi[i]-mini[i]<=k)return i;
        }
        return -1;
    }
};