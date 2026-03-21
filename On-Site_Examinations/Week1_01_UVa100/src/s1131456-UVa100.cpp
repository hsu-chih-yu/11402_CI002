// Email: s1131456@mail.yzu.edu.tw
#include <iostream>

using namespace std;

int main(){
    int a, b;
    while(cin >> a >> b){
        cout << a << ' ' << b << ' ' ;

        // 確保範圍是從小到大，避免 a > b 時迴圈不跑
        if(a > b){
            int temp = a;
            a = b;
            b = temp;
        }

        int max = -1;

        for(int i = a; i <= b; i++){
            long long temp = i;  // 使用 long long 防止 3n+1 運算溢位
            int num = 1;

            // 執行 3n+1 邏輯直到變為 1
            while(temp != 1){
                if(temp % 2 == 1){
                    temp = temp * 3 + 1;
                }else{
                    temp /= 2;
                }
                num++;
            }

            // 更新最大長度
            if(num > max) max = num;
        }
        cout << max << endl;
    }
    return 0;
}