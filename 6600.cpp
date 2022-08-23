#include <iostream>
#include <cmath>
using namespace std;

#define PI 3.141592653589793

int main() {
    cout.precision(2);
    cout << fixed;
    double x1, y1, x2, y2, x3, y3;
    while (cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3) {
        if (y2-y1 == 0) {
            double tempX = x2, tempY = y2;
            x2 = x3; y2 = y3;
            x3 = tempX; y3 = tempY;
        } else if (y3-y2 == 0) {
            double tempX = x1, tempY = y1;
            x1 = x2; y1 = y2;
            x2 = tempX; y2 = tempY;
        }
        double d1 = (x2-x1) / (y2-y1), d2 = (x3-x2) / (y3-y2);
        double cx = ((y3-y1) + (x2+x3)*d2 - (x1+x2)*d1) / (2*(d2-d1));
        double cy = -d1*(cx - (x1+x2)/2) + (y1+y2)/2;
        double r = sqrt((x1-cx)*(x1-cx) + (y1-cy)*(y1-cy));
        double circumference = 2 * PI * r;
        cout << floor(circumference * pow(10, 2) + 0.5) / pow(10, 2) << '\n';
    }
    return 0;
}
