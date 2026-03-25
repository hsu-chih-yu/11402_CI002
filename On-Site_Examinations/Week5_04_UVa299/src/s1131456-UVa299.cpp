//Email: s1131456@email.yzu.edu.tw
#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main() {
    int cases;
    // 讀取測試資料組數
    if (!(cin >> cases)) return 0;

    while (cases--) {
        int n;
        cin >> n;
        vector<int> a;
        int num, ans = 0;

        // 讀取車廂初始順序
        for (int i = 0; i < n; i++) {
            cin >> num;
            a.push_back(num);
        }

        // 執行泡沫排序 (Bubble Sort)
        // 外層代表已經排好序的元素個數
        for (int i = 0; i < n - 1; i++) {
            // 內層進行相鄰元素比較與交換
            for (int j = 0; j < n - 1 - i; j++) {
                if (a[j] > a[j+1]) {
                    // 交換相鄰元素
                    int temp = a[j];
                    a[j] = a[j+1];
                    a[j+1] = temp;
                    // 累加交換次數
                    ans++;
                }
            }
        }

        // 依照題目要求的格式輸出
        printf("Optimal train swapping takes %d swaps.\n", ans);
    }

    return 0;
}