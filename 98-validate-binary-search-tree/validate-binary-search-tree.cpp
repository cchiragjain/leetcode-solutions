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
private:
    // using long long since question asks for that
    bool isValidBST(TreeNode* root, long long minVal, long long maxVal){
        if(root == nullptr) return true;

        if(root -> val >= maxVal || root -> val <= minVal) return false;
        // har node ke liye uski range define ki h
        return isValidBST(root -> left, minVal, root -> val) && isValidBST(root -> right, root -> val, maxVal);
    }
public:
    // ek tarika aur h agar inorder nikal le aur us array ko check karle ki sorted h ki nahi lekin O(N) space aur lega voh
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LLONG_MIN, LLONG_MAX); // root node ki range ye hogi
    }
};