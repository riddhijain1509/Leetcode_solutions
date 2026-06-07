class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mpp;
        unordered_set<int> childs;

        for (auto &vec : descriptions) {
            int parent = vec[0];
            int child = vec[1];
            int isLeft = vec[2];

            if (mpp.find(parent) == mpp.end())
                mpp[parent] = new TreeNode(parent);

            if (mpp.find(child) == mpp.end())
                mpp[child] = new TreeNode(child);

            if (isLeft)
                mpp[parent]->left = mpp[child];
            else
                mpp[parent]->right = mpp[child];

            childs.insert(child);
        }

        for (auto &[val, node] : mpp) {
            if (childs.find(val) == childs.end())
                return node;  
        }

        return nullptr;
    }
};