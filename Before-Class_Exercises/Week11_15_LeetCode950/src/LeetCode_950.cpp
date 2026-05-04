// Email: s1131456@mail.yzu.edu.tw
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        
        // 將卡牌從小到大排序
        sort(deck.begin(), deck.end());

        // 建立索引佇列
        queue<int> q;
        for(int i = 0; i < n; i++) {
            q.push(i);
        }

        vector<int> ans(n);
        for(int c : deck) {
            // 將對應的卡牌放到正確的位置
            ans[q.front()] = c;
            q.pop();

            // 模擬將頂部的卡牌移到底部
            if(!q.empty()){
                q.push(q.front());
                q.pop();
            }
        }
        return ans;
    }
};