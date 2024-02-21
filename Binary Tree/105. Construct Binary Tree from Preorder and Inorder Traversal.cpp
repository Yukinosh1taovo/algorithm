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
    TreeNode* traversal(vector<int>& preorder, vector<int>& inorder, int preorderBegin, int preorderEnd, int inorderBegin, int inorderEnd) 
    {
        // [preorderBegin, preorderEnd), [inorderBegin, inorderEnd)

        if (preorderBegin == preorderEnd)
            return nullptr;

        // 前序遍历数组第一个元素 为当前的中间结点
        int rootvalue = preorder[preorderBegin];
        TreeNode* root = new TreeNode(rootvalue);

        //叶子结点
        if (preorderBegin + 1 == preorderEnd)
            return root;

        //找到中序遍历的切割点
        int delimiterindex;
        for (delimiterindex = inorderBegin; delimiterindex < inorderEnd; delimiterindex++)
            if (inorder[delimiterindex] == rootvalue)
                break;
        
        // 切割中序数组
        // 左闭右开区间 [0, delimiterindex)
        int leftinorderBegin = inorderBegin;
        int leftinorderEnd = delimiterindex;

        int rightinorderBegin = delimiterindex + 1;
        int rightinorderEnd = inorderEnd;


        

        // preorder 舍弃开头元素
        preorderBegin++;

        // 切割前序数组
        // 左闭右开
        //[0, leftinorder.size)
        
        int leftpreorderBegin = preorderBegin;
        int leftpreorderEnd = preorderBegin + leftinorderEnd - leftinorderBegin;

        int rightpreorderBegin = preorderBegin + leftinorderEnd - leftinorderBegin;
        int rightpreorderEnd = preorderEnd;



        root->left = traversal(preorder, inorder, leftpreorderBegin, leftpreorderEnd, leftinorderBegin, leftinorderEnd);
        root->right = traversal(preorder, inorder, rightpreorderBegin, rightpreorderEnd, rightinorderBegin, rightinorderEnd);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        if (inorder.size() == 0 || preorder.size() == 0)
            return nullptr;
        return traversal(preorder, inorder, 0, preorder.size(), 0, inorder.size());
    }
};