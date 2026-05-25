# LeetCode 110 - Balanced Binary Tree

## 題目描述
給定一個二元樹，判斷它是否為 **高度平衡 (Height-Balanced)** 的二元樹。
- **定義**：一個二元樹每個節點的左右兩個子樹的高度差的絕對值不超過 1。

[題目連結](https://leetcode.com/problems/balanced-binary-tree/)

## 學習重點
- [x] 理解 **平衡二元樹 (Balanced Binary Tree)** 的定義與性質。
- [x] 掌握 **由底向上 (Bottom-up)** 的遞迴優化技巧。
- [x] 學習如何利用特殊回傳值（如 `-1`）來進行「剪枝 (Pruning)」。

---

## 解法思路：優化的深度優先搜尋 (DFS)

### 1. 傳統解法的缺點
傳統解法會對每個節點呼叫 `getHeight` 函式，這會導致重複遍歷子節點，時間複雜度高達 $O(N^2)$。

### 2. 優化邏輯：Bottom-up
我們在計算高度的同時就進行平衡判斷：
- **基礎情況 (Base Case)**：空節點的高度為 `0`。
- **遞迴計算**：分別取得左子樹與右子樹的高度。
- **早期終止 (Early Return)**：
  - 如果左子樹或右子樹已經不平衡（回傳 `-1`），則直接向上回傳 `-1`。
  - 如果當前節點的左右子樹高度差 `abs(left - right) > 1`，代表不平衡，回傳 `-1`。
- **正常回傳**：若平衡，則回傳當前節點的真實高度 `max(leftHeight, rightHeight) + 1`。

## Code Structure
```cpp
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

/**
 * LeetCode 110 - Balanced Binary Tree
 * 邏輯：由底向上檢查高度，若不平衡則回傳 -1 進行剪枝
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        // 若最終回傳值不是 -1，代表整棵樹皆符合平衡條件
        return checkHeight(root) != -1;
    }

private:
    int checkHeight(TreeNode* node) {
        // 1. 基礎情況：空節點高度為 0
        if (node == nullptr) return 0;

        // 2. 遞迴檢查左子樹
        int leftHeight = checkHeight(node->left);
        if (leftHeight == -1) return -1; // 左子樹不平衡，直接向上回報

        // 3. 遞迴檢查右子樹
        int rightHeight = checkHeight(node->right);
        if (rightHeight == -1) return -1; // 右子樹不平衡，直接向上回報

        // 4. 檢查當前節點是否平衡
        if (abs(leftHeight - rightHeight) > 1) {
            return -1; // 左右高度差超過 1，標記為不平衡
        }

        // 5. 若平衡，回傳當前節點的實際高度
        return max(leftHeight, rightHeight) + 1;
    }
};
```

## 複雜度分析
- **時間複雜度**: $O(N)$
  每個節點僅被訪問一次，計算高度與判斷平衡同步完成。
- **空間複雜度**: $O(H)$
  $H$ 為樹的高度，代表遞迴堆疊 (Recursive Stack) 的深度。



## 筆記與心得
- **剪枝技巧**：這題展示了如何用一個特殊的數字（`-1`）來傳遞「錯誤/不符合條件」的訊息，避免不必要的後續計算。
- **期中考應考點**：考試時若被要求實作 $O(N)$ 的版本，務必記得將高度計算與平衡判斷結合在一起，不要分開寫。