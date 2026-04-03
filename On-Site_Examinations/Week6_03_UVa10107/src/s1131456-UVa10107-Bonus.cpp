// Email: s1131456@mail.yzu.edu.tw
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    vector<int> a;
    
    // 持續讀入數字直到輸入結束 (EOF)
    while(cin >> n){
        // 1. 將新數字加入向量
        a.push_back(n);
        
        // 2. 重新排序以尋找中位數
        sort(a.begin(), a.end());
        
        int leng = a.size();
        
        // 3. 判斷長度為奇數或偶數
        if(leng % 2 == 0){
            // 偶數個：取中間兩個數的平均值
            int div = leng / 2;
            int ans = a[div] + a[div-1];
            ans /= 2;
            cout << ans << endl;
        } else {
            // 奇數個：直接取最中間的數
            int div = leng / 2;
            cout << a[div] << endl;
        }
    }

    return 0;
}