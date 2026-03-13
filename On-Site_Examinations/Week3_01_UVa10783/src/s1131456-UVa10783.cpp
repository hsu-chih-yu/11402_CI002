#include <iostream>

using namespace std;

int main()
{
    int cases;
    cin >> cases;
    for(int j = 1; j <= cases; j++){
        int a , b, sum =0;
        cin >> a >> b;
        for(int i = a; i <= b; i++){
            if(i % 2 == 1){
                sum += i;
            }
        }
        cout << "Case " << j << ": " << sum << endl;
    }
    return 0;
}
