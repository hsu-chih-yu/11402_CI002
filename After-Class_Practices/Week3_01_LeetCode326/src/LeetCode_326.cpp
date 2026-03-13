class Solution {
public:
    bool isPowerOfThree(int n) {
        // 1. 處理邊界條件：3 的冪次方必定是正整數
        if (n <= 0) {
            return false;
        }

        // 2. 當 n 能被 3 整除時，持續縮小 n
        while (n % 3 == 0) {
            n /= 3;
        }

        // 3. 檢查最後剩下的值是否為 1
        // 若 n 原本是 3 的冪次方，最後一定會除到剩下 1
        if (n == 1) {
            return true;
        } else {
            return false;
        }
    }
};