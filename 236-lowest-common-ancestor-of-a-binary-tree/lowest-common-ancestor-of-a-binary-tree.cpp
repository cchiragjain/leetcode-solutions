/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    bool findPath(TreeNode* root, TreeNode* target, vector<TreeNode*>& path){
        if(root == nullptr) return false;

        path.push_back(root);
        if(root == target) return true;

        if(findPath(root -> left, target, path) || findPath(root -> right, target, path)){
            return true;
        }

        path.pop_back();
        return false;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // brute force approach
        // get the path from root to p and q nodes
        // then check the last element that is equal

        vector<TreeNode*> pPath;
        vector<TreeNode*> qPath;

        findPath(root, p, pPath);
        findPath(root, q, qPath);

        int i = 0;
        while(i < pPath.size() && i < qPath.size() && pPath[i] == qPath[i]){
            i++;
        }

        return pPath[i - 1];
    }
};