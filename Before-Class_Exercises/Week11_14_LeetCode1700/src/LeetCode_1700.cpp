// Email: s1131456@mail.yzu.edu.tw
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int i = 0;
        int s = students.size();
        int count = 0;
        queue<int> q;
        
        // 將所有學生加入佇列
        for(int k : students) {
            q.push(k);
        }
        
        // 持續模擬取三明治的過程
        while (count < s && !q.empty()) {
            if (q.front() == sandwiches[i]) {
                // 學生喜歡當前三明治
                i++;
                q.pop();
                s--;
                count = 0; // 重置計數
            } else {
                // 學生不喜歡當前三明治，移至隊尾
                count++;
                int temp = q.front();
                q.pop();
                q.push(temp);
            }
        }
        
        // 剩餘無法拿到三明治的學生數
        return q.size();
    }
};