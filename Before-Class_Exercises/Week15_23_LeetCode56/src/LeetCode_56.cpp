// Email: s1131456@mail.yzu.edu.tw
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // 安全檢查：若為空陣列則直接回傳
        if(intervals.empty()) return {};

        // 1. 依照起始時間進行升冪排序
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;
        // 先將第一個區間放入作為初始比較基準
        merged.push_back(intervals[0]);
        
        int n = intervals.size();
        for(int i = 1; i < n; i++){
            // 取得前一個合併區間的結束點，與當前區間的起迄點
            int last_end = merged.back()[1];
            int current_start = intervals[i][0];
            int current_end = intervals[i][1];

            // 2. 判斷是否重疊
            if(last_end >= current_start){
                // 若重疊，將前一個區間的結束點向右延展（取兩者最大值）
                merged.back()[1] = max(last_end, current_end);
            } else {
                // 若未重疊，則將當前區間作為新的獨立區間加入
                merged.push_back(intervals[i]);
            }
        }
        
        return merged;
    }
};