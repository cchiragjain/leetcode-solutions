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
        if(root == nullptr || root == p || root == q) return root;

        TreeNode* left = lowestCommonAncestor(root -> left, p, q);
        TreeNode* right = lowestCommonAncestor(root -> right, p, q);

        // if using this root p and q both were found then that means this is the lowest common 
        if(left && right) return root;
        if(left && !right) return left; // take second one as example if we are standing at 3 and found 5 in left and in the right call were not able to find 4 then 5 is lca only since 4 will be in some part in left
        if(right && !left) return right;

        return nullptr;
        
        // brute force approach
        // it is T.C => O(N) but uses two traversals and extra space to store

        // get the path from root to p and q nodes
        // then check the last element that is equal
        // vector<TreeNode*> pPath;
        // vector<TreeNode*> qPath;

        // findPath(root, p, pPath);
        // findPath(root, q, qPath);

        // int i = 0;
        // while(i < pPath.size() && i < qPath.size() && pPath[i] == qPath[i]){
        //     i++;
        // }

        // return pPath[i - 1];
    }
};