// Email: s1131456@mail.yzu.edu.tw
#include <iostream>

using namespace std;

int main()
{
    int n;
    while(cin >> n && n != 0){
        int sum = 0;
        for(int i = 1; i <= n; i++){
            int left = n - i;
            int row = 1 + left;
            sum += row * row;
        }
        cout << sum << endl;
    }
    return 0;
}
