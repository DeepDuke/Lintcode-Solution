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
     * @param root: A Tree
     * @return: Level order a list of lists of integer
     */
    vector<vector<int>> levelOrder(TreeNode * root) {
        // write your code here
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int levelLength = q.size();
            vector<int> levelVec;
            for(int i = 0; i < levelLength; i++){
                TreeNode* temp = q.front();
                levelVec.push_back(temp->val);
                if(temp->left != NULL) q.push(temp->left);
                if(temp->right != NULL) q.push(temp->right);
                q.pop();
            }
            ans.push_back(levelVec);
        }
        return ans;
    }
};