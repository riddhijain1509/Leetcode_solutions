class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
      unordered_set<int> s(nums.begin(),nums.end());
      vector<vector<int>> result;
      for(int i=lower;i<=upper;i++)
      {
        int f=-1;
        int l=-1;
        while(i<=upper && !s.count(i))
        {
            if(f==-1)
            {
                f=i;
            }
            l=i;
            i++;
        }
        if(f!=-1 && l!=-1)
        {
            result.push_back({f,l});
        }
      }
return result;
    }
};