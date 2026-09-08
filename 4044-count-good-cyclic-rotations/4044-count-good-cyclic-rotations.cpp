class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int count =0;
        long long sum=0;
        int n=nums.size();
        long long total=0;
        for(int i=0;i<n/2;i++)
        {
            sum+=nums[i];
        }
        total=sum;
        for(int i=n/2;i<n;i++)
        {
            total+=nums[i];
        }
        for(int i=0;i<n;i++)
        {
            if(sum>(total-sum))count++;
            sum-=nums[i];
            sum+=nums[(i + n / 2) % n];

        }

return count;
    }
};