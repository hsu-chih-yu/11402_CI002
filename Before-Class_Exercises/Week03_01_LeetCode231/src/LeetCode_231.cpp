class Solution {
public:
    bool isPowerOfTwo(int n) {
        // 1. 2 的冪次方必定是正整數，若為負數或 0 則回傳 false
        if (n < 1) return false;

        // 2. 持續檢查 n 是否能被 2 整除，直到 n 變為 1
        while (n > 1) {
            if (n % 2 == 0) {
                // 如果是偶數，就除以 2 繼續檢查下一位
                n /= 2;
            } else {
                // 一旦出現奇數（且不為 1），代表不是 2 的冪次方
                return false;
            }
        }

        // 3. 若能一路除到 1，則代表它是 2 的冪次方
        return true;
    }
};