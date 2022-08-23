#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<double> vec(4);
    for (auto &x : vec) {
        cin >> x;
    }
    double maxVal = 0, numOfRotates;
    for (int i = 0; i < 4; ++i) {
        double val = vec[0] / vec[2] + vec[1] / vec[3];
        if (val > maxVal) {
            maxVal = val;
            numOfRotates = i;
        }
        vec = {vec[2], vec[0], vec[3], vec[1]};
    }
    cout << numOfRotates;
    return 0;
}
