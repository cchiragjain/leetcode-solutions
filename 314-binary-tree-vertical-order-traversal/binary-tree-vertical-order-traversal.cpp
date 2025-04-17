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
// we use the concept of horizontal distance in this
// first node is at 0, 0 {col, row}
// then the left will be at -1, 1 and right will be at 1, 1
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if(root == nullptr){
            return {};
        }

        vector<vector<int>> result;
        // we want to store on the basis of cols to be based on col so storing on that basis
        // store col vs row vs all nodes at that [col, row]
        // in gfg we even need to sort in case of clash but in this we only want to store left to right so vector can be used

        map<int, map<int, vector<int>>> allNodes;
        queue<pair<TreeNode*, pair<int, int>>> q; // stores node vs row vs col

        q.push({root, {0, 0}});

        while(!q.empty()){
            auto current = q.front();
            q.pop();

            TreeNode* currentNode = current.first;
            int currentCol = current.second.first;
            int currentRow = current.second.second;

            allNodes[currentCol][currentRow].push_back(currentNode -> val);

            if(currentNode -> left != nullptr){
                q.push({
                    currentNode -> left,
                    {
                        currentCol - 1,
                        currentRow + 1
                    }
                });
            }

            if(currentNode -> right != nullptr){
                q.push({
                    currentNode -> right,
                    {
                        currentCol + 1,
                        currentRow + 1
                    }
                });
            }
        }

        // important how to iterate
        for(auto& [col, rowVsNodes]: allNodes){
            vector<int> cols;
            for(auto& [row, nodes]: rowVsNodes){
                cols.insert(cols.end(), nodes.begin(), nodes.end());
            }
            result.push_back(cols);
        }
        
        return result;
    }
};