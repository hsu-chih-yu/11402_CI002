// Email: s1131456@mail.yzu.edu.tw
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    // 讀入 n，當 n 為 0 時停止
    while(cin >> n && n != 0){
        vector<int> a;
        int c = 0; // 用於計算 1 的個數 (Parity)
        
        // 十進位轉二進位
        while(n > 0){
            int ans = n % 2;
            a.push_back(ans);
            if(ans == 1){
                c++;
            }
            n /= 2;
        }
        
        // 輸出指定格式
        cout << "The parity of ";
        int s = a.size();
        // 反向輸出 vector 內容以呈現正確的二進位順序
        for(int i = s - 1; i >= 0; i--){
            cout << a[i];
        }
        printf(" is %d (mod 2).\n", c);
    }

    return 0;
}