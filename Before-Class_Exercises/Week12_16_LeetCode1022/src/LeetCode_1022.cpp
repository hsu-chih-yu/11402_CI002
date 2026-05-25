// Email: s1131456@mail.yzu.edu.tw
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
    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, 0);
    }

private:
    int dfs(TreeNode* node, int currentSum) {
        // 1. 基底情況：節點為空
        if (node == nullptr) return 0;

        // 2. 更新當前的路徑值
        // 左移一位等於乘以 2，再加上當前節點的值
        currentSum = (currentSum << 1) | node->val;

        // 3. 如果是葉子節點，回傳目前計算的結果
        if (node->left == nullptr && node->right == nullptr) {
            return currentSum;
        }

        // 4. 遞迴左右子樹並加總
        return dfs(node->left, currentSum) + dfs(node->right, currentSum);
    }
};