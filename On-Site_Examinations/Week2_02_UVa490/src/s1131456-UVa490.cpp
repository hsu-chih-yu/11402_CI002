// Email: s1131456@mail.yzu.edu.tw
#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    vector<string> lines;
    string input;
    size_t maxlen = 0;
    while(getline(cin, input)){

        int len = input.length();
        lines.push_back(input);
        if(len > maxlen){
            maxlen = len;
        }
        
    }
    int row = lines.size();
    for(int i = 0; i < maxlen; i++){
        for(int j = row-1; j >= 0; j--){
            if(i >= lines[j].length()){
                cout << " ";
            }else{
                cout << lines[j][i];
            }

        }
        cout << endl;
    }


    return 0;
}
