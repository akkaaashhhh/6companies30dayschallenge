class Solution {
public:
    void inorder(TreeNode* root,vector<int> &elements)
    {
        if(root == NULL)
            return;
        inorder(root->left,elements);
        elements.push_back(root->val);
        inorder(root->right,elements);
    }
    vector <int> solve(vector<int> tree1,vector<int>tree2)
    {
            vector<int> sol;
            for(int i=0;i<tree1.size();i++)
            {
                sol.push_back(tree1[i]);
            }
            for(int i=0;i<tree2.size();i++)
            {
                sol.push_back(tree2[i]);
            }
            sort(sol.begin(),sol.end());
            return sol;
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) 
    {
        vector<int> tree1,tree2;
        inorder(root1,tree1);
        inorder(root2,tree1);
        vector<int> sol = solve(tree1,tree2);
        return sol;

    }
};