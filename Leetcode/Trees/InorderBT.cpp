// https://leetcode.com/problems/binary-tree-inorder-traversal/

/**
 Binary Tree Inorder Traversal
Easy

5189

222

Add to List

Share
Given the root of a binary tree, return the inorder traversal of its nodes' values.

 

Example 1:


Input: root = [1,null,2,3]
Output: [1,3,2]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]
Example 4:


Input: root = [1,2]
Output: [2,1]
Example 5:


Input: root = [1,null,2]
Output: [1,2]
 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
**/

// Recursive Approach
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
    vector<int> traversal;
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == nullptr) return traversal;
        if(root->left) inorderTraversal(root->left);
        traversal.push_back(root->val);
        if(root->right) inorderTraversal(root->right);
        
        return traversal;
    }
};

// Iterative Approach
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> traversal;
        if(root == nullptr) return traversal;
        stack<TreeNode* > st;
        TreeNode* curr = root;
        while(curr != nullptr || !st.empty()){
            
            while(curr != nullptr){
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            traversal.push_back(curr->val);
            st.pop();
            curr = curr->right;
        }
        return traversal;
    }
};
