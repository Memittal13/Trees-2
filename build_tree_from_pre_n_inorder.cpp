//Time O(n)
 //Space O(n)
 //Leetcode yes
 //Issue seen: none
class Solution {
public:
     map<int,int> inorder_map;
    int pre_idx = 0;
    void convert_inorder_to_map(vector<int> &inorder) {
        for(int i = 0; i < inorder.size(); i++) {
            inorder_map[inorder[i]] = i;
        }    
    }
    
    TreeNode* helper(vector<int> &preorder, int start, int end) {
            if(start > end) {
                return NULL;
            }
        
            TreeNode *node = new TreeNode(preorder[pre_idx]);
            ++pre_idx;
            int split = inorder_map[node->val];
            node->left = helper(preorder, start, split-1);
            node->right = helper(preorder, split+1, end);
            
            return node;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        convert_inorder_to_map(inorder);
        return helper(preorder, 0, inorder.size()-1);
    }

};
