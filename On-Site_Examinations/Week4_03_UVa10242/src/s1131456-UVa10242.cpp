// Email: s1131456@mail.yzu.edu.tw
#include <iostream>
#include <iomanip>

using namespace std;

struct Point {
    double x, y;
};

int main() {
    Point p[4];
    
    // 持續讀取四個點的座標 (x1, y1, x2, y2, x3, y3, x4, y4)
    while (cin >> p[0].x >> p[0].y >> p[1].x >> p[1].y >> p[2].x >> p[2].y >> p[3].x >> p[3].y) {
        double resX, resY;

        // 判斷哪兩個點是重複的（共同頂點 B）
        // 情況 1: p[0] 是共同點
        if (p[0].x == p[2].x && p[0].y == p[2].y) {
            resX = (p[1].x + p[3].x) - p[0].x;
            resY = (p[1].y + p[3].y) - p[0].y;
        }
        else if (p[0].x == p[3].x && p[0].y == p[3].y) {
            resX = (p[1].x + p[2].x) - p[0].x;
            resY = (p[1].y + p[2].y) - p[0].y;
        }
        // 情況 2: p[1] 是共同點
        else if (p[1].x == p[2].x && p[1].y == p[2].y) {
            resX = (p[0].x + p[3].x) - p[1].x;
            resY = (p[0].y + p[3].y) - p[1].y;
        }
        else { // p[1] == p[3]
            resX = (p[0].x + p[2].x) - p[1].x;
            resY = (p[0].y + p[2].y) - p[1].y;
        }

        // 格式化輸出到小數點後三位
        cout << fixed << setprecision(3) << resX << " " << resY << endl;
    }

    return 0;
}