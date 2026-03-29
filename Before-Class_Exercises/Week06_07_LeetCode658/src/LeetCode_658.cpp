// Email: s1131456@mail.yzu.edu.tw
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // 根據與 x 的距離進行排序
        // 使用 stable_sort 可以確保距離相等時，原本較小的元素仍在前面
        stable_sort(arr.begin(), arr.end(), [x](int a, int b) {
            return abs(a - x) < abs(b - x);
        });

        // 取前 k 個最接近的元素
        vector<int> result(arr.begin(), arr.begin() + k);

        // 題目要求結果必須是升冪排列
        sort(result.begin(), result.end());

        return result;
    }
};