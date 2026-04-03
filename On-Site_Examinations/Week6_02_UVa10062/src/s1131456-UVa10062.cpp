// Email: s1131456@mail.yzu.edu.tw
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    // 使用 getline 讀取含空白的完整列
    while(getline(cin, s)){
        int a[130] = {0};
        int maxi = 0;
        int length = s.length();

        // 統計每個字元的出現次數
        for(int i = 0; i < length; i++){
            a[s[i]]++;
            if(a[s[i]] > maxi){
                maxi = a[s[i]];
            }
        }

        // 依照排序規則輸出
        // 外層迴圈控制頻率
        for(int t = 1; t <= maxi; t++){
            // 內層迴圈控制 ASCII 碼
            for(int i = 128; i >= 32; i--){
                if(a[i] == t){
                    cout << i << " " << t << "\n";
                }
            }
        }
        // 每組測資後輸出一個額外換行
        cout << "\n";
    }

    return 0;
}