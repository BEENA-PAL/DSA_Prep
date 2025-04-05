// https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/?envType=daily-question&envId=2025-04-04

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    public:
    
        TreeNode* solve(TreeNode* root, TreeNode* l, TreeNode* r) {
            if(root == NULL || root == l || root == r) return root;
            
            TreeNode* left = solve(root -> left, l, r);
            TreeNode* right = solve(root -> right, l, r);
    
            if(left and right) return root;
            if(left) return left;
            return right;
            
        }
        TreeNode* lcaDeepestLeaves(TreeNode* root) {
            vector<vector<TreeNode*>> ans;
            int i=0;
            queue<TreeNode*> q;
            q.push(root);
    
            while(!q.empty()) {
                int size = q.size();
                vector<TreeNode*> level;
                while(size--) {
                    TreeNode* node = q.front();
                    q.pop();
                    level.push_back(node);
                    if(node->left) q.push(node->left);
                    if(node->right) q.push(node->right);
                }
                ans.push_back(level);
                i++;
            }
    
            int index = ans.size()-1;
    
            TreeNode* l = ans[index][0];
            TreeNode* r = ans[index][ans[index].size() - 1];
           return solve(root,l,r);
        }
    };