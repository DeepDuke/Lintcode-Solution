/*
带所有空节点的层序遍历序列可以重建二叉树
*/
/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */


class Solution {
public:
    /**
     * This method will be invoked first, you should design your own algorithm 
     * to serialize a binary tree which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    string serialize(TreeNode * root) {
        // write your code here
        if(!root) return "";
        string str = "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            if(node){
                str += to_string(node->val);
                q.push(node->left);
                q.push(node->right);
            }else{
                str += "#";
            }
            if(q.size() > 0) str += ",";
        }
        return str;
    }

    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in 
     * "serialize" method.
     */
    TreeNode * deserialize(string &data) {
        // write your code here
        if(data == "") return nullptr;
        // split str into a vector 
        vector<string> tree;
        int lastPos = -1, nowPos = 0;
        for(int i = 0; i < data.size(); i++){
            if(data[i] == ','){
                nowPos = i;
                tree.push_back(data.substr(lastPos+1, nowPos-lastPos-1));
                lastPos = nowPos;
            }
        }
        tree.push_back(data.substr(nowPos+1));
        // rebuild a tree from level order
        TreeNode* root = new TreeNode(stoi(tree[0]));
        queue<TreeNode*> q;
        q.push(root);
        for(int i = 1; i < tree.size(); i += 2){
            auto now = q.front();
            q.pop();
            if(tree[i] == "#"){
                now->left = nullptr;
            }else{
                now->left = new TreeNode(stoi(tree[i]));
                q.push(now->left);
            }
            if(tree[i+1] == "#"){
                now->right = nullptr;
            }else{
                now->right = new TreeNode(stoi(tree[i+1]));
                q.push(now->right);
            }
        }
        return root;
    }
};
