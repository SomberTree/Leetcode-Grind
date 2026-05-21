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
    map<pair<int,int>,vector<int>> res;
    void traverse(TreeNode* root, int x, int y){
        if(root == NULL) return;
        res[{x,y}].push_back(root->val);
        // cout << "pos = " << pos << " , val = " << root->val << "\n";
        traverse(root->left, x+1, y-1);
        traverse(root->right, x+1, y+1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        traverse(root, 0, 0);
        vector<vector<int>> ans;
        map<int,vector<int>> resy;
        for(auto pair: res){
            sort(pair.second.begin(), pair.second.end());
           for(int i:pair.second) resy[pair.first.second].push_back(i);
        }
        for(auto pair:resy) ans.push_back(pair.second);
        return ans;
    }
};