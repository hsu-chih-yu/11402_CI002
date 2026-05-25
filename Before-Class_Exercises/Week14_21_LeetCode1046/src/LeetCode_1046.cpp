// Email: s1131456@mail.yzu.edu.tw
#include <vector>
#include <queue>

using namespace std;

/**
 * LeetCode 1046 - Last Stone Weight
 * 邏輯：利用 Priority Queue (Max-Heap) 始終獲取兩顆最重的石頭進行模擬。
 */
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // 1. 初始化優先權佇列 (預設為最大堆)
        priority_queue<int> pq;

        for(int s : stones){
            pq.push(s);
        }

        // 2. 當石頭數量大於 1 時持續進行碰撞
        while(pq.size() > 1){
            int y = pq.top(); // 最重
            pq.pop();
            int x = pq.top(); // 第二重
            pq.pop();

            // 3. 若重量不等，產生新碎石並放回堆中
            if(x != y){
                pq.push(y - x);
            }
        }

        // 4. 回傳最後一顆石頭重量或 0
        return pq.empty() ? 0 : pq.top();
    }
};