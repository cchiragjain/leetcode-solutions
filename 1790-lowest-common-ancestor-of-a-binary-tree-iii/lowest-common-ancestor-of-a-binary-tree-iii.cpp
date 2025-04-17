/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
private:
    bool findPath(Node* node, vector<Node*>& path){
        if(node -> parent == nullptr) {
            path.push_back(node);
            return true;
        }

        path.push_back(node);
        if(findPath(node -> parent, path)) {
            return true;
        }

        path.pop_back();
        return false;
    }
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        vector<Node*> pPath;
        vector<Node*> qPath;

        findPath(p, pPath);
        findPath(q, qPath);

        int i = pPath.size() - 1;
        int j = qPath.size() - 1;

        while(i >= 0 && j >= 0 && pPath[i] == qPath[j]){
            i--;
            j--;
        }

        return pPath[i + 1];
    }
};