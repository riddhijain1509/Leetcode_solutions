class Solution {
public:

    vector<vector<int>> verticalTraversal(TreeNode* root) {

        map<int, map<int, multiset<int>>> mpp;

        vector<vector<int>> ans;

        queue<pair<TreeNode*, pair<int,int>>> q;

        q.push({root, {0,0}});

        while(!q.empty())
        {
            auto it = q.front();
            q.pop();

            TreeNode* cur = it.first;

            int row = it.second.first;
            int col = it.second.second;

            mpp[col][row].insert(cur->val);

            if(cur->left != nullptr)
            {
                q.push({cur->left, {row + 1, col - 1}});
            }

            if(cur->right != nullptr)
            {
                q.push({cur->right, {row + 1, col + 1}});
            }
        }

        for(auto it : mpp)
        {
            vector<int> temp;

            for(auto it2 : it.second)
            {
                for(auto val : it2.second)
                {
                    temp.push_back(val);
                }
            }

            ans.push_back(temp);
        }

        return ans;
    }
};