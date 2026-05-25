# LeetCode 1022 - Sum of Root To Leaf Binary Numbers

## 題目描述
給定一棵二元樹，每個節點的值為 `0` 或 `1`。每一條從根節點到葉子節點的路徑都代表一個從最高有效位元開始的二進位數。
- 例如，路徑 `0 -> 1 -> 1` 代表二進位數 `011`，即十進位的 `3`。

請回傳所有這些路徑代表的數字之和。

[題目連結](https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/)

## 學習重點
- [x] 掌握 **二元樹的深度優先搜尋 (DFS)** 遞迴實作。
- [x] 理解如何動態建構位元數值：`current_val = (current_val << 1) | node->val`。
- [x] 識別 **葉子節點 (Leaf Node)** 的判斷條件：`!node->left && !node->right`。



## 解法思路：遞迴遍歷法 (DFS)

### 1. 位元累加邏輯
當我們從父節點移動到子節點時，原本的數值會向左移一位（相當於乘以 2），然後加上當前節點的值。
- 公式：`sum = (sum * 2) + node->val` 或使用位元運算 `(sum << 1) | node->val`。

### 2. 遞迴過程
- **終止條件**：如果遇到空節點，回傳 `0`。
- **累加數值**：更新當前的路徑總和。
- **抵達葉子**：如果當前是葉子節點，代表路徑結束，直接回傳當前的路徑總和。
- **分支計算**：若非葉子，則繼續往左、右子樹遞迴，並將兩者的結果加總。



## Code Structure
```cpp
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
```

## 複雜度分析
- **時間複雜度**: $O(N)$，每個節點剛好被訪問一次。
- **空間複雜度**: $O(H)$，其中 $H$ 為樹的高度，代表遞迴堆疊的深度。



## 筆記與心得
- **位元運算優勢**：在期中考或開發中，使用 `(sum << 1) | node->val` 會比 `sum * 2 + node->val` 更具「程式感」且在底層運算上稍快。
- **遞迴基礎**：這題是練好二元樹遞迴的基本功，建議熟練此類路徑加總的模式。