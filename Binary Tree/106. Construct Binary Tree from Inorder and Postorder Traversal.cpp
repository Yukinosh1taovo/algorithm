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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        function<TreeNode*(vector<int>, vector<int>)> traversal = [&](vector<int> inorder, vector<int> postorder) -> TreeNode*
        {
            
            if (postorder.size() == 0)
                return NULL;
            
            // 后序遍历数组最后一个元素 为当前中间结点
            int rootvalue = postorder[postorder.size() - 1];
            TreeNode* root = new TreeNode(rootvalue);

            // 叶子结点
            if(postorder.size() == 1)
                return root;

            // 找到中序遍历的切割点
            int delimiterindex;
            for (delimiterindex = 0; delimiterindex < inorder.size(); delimiterindex++)
                if(inorder[delimiterindex] == rootvalue)
                    break;

            // 切割中序遍历数组
            // 左开右闭 
            vector<int> leftinorder(inorder.begin(), inorder.begin() + delimiterindex);
            vector<int> rightinorder(inorder.begin() + delimiterindex + 1, inorder.end());

            postorder.pop_back();

            //切割后续遍历数组
            vector<int> leftpostorder(postorder.begin(), postorder.begin() + leftinorder.size());
            vector<int> rightpostorder(postorder.begin() + leftinorder.size(), postorder.end());

            root->left = traversal(leftinorder, leftpostorder);
            root->right = traversal(rightinorder, rightpostorder);

            return root;
        } ;




        if (inorder.size() == 0 || postorder.size() == 0)
            return NULL;
        return traversal(inorder, postorder);
    }
};