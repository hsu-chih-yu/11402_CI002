//Email: s1131456@email.yzu.edu.tw
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int cases;
    if (!(cin >> cases)) return 0;
    
    vector<string> countries;
    string country, name;

    while (cases--) {
        cin >> country;
        getline(cin, name); // 讀完剩下的部分
        countries.push_back(country);
    }

    // 先把所有國家按字典序排好
    sort(countries.begin(), countries.end());

    // 遍歷排好序的 vector 進行計數輸出
    int len = countries.size();
    for (int i = 0; i < len; i++) {
        int count = 1;
        // 檢查後面是否有相同的國家
        while (i + 1 < len && countries[i] == countries[i + 1]) {
            count++;
            i++;
        }
        cout << countries[i] << " " << count << endl;
    }

    return 0;
}