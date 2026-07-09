class DSU{
   public:
   vector<int> par;
   vector<int> size;
   DSU(int n)
   {
    par.resize(n+1);
    size.resize(n+1);
    for(int i=0;i<=n;i++)
    {
        par[i]=i;
        size[i]=1;
    }
   }
   int parent(int u)
   {
    if(par[u]==u)return u;
    return par[u]=parent(par[u]);
   }
   void unite(int u,int v)
   {
    int pu=parent(u);
    int pv=parent(v);
    if(pu==pv)return;
    if(size[pu]>size[pv])
    {
        par[pv]=pu;
        size[pu]+=size[pv];
    }
    else
    {
        par[pu]=pv;
        size[pv]+=size[pu];
    }
   }
};
class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                      vector<vector<int>>& queries) {
        DSU dsu(n);

       
        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i - 1] <= maxDiff)
                dsu.unite(i, i - 1);
        }

        vector<bool> ans;
        for (auto &q : queries) {
            ans.push_back(dsu.parent(q[0]) == dsu.parent(q[1]));
        }

        return ans;
    }
};