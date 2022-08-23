#include <iostream>
#include <utility>
#include <cmath>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;
    if (A > B) {
        swap(A, B);
    }
    int distance = 0;
    while ((A - 1) / 4 < (B - 1) / 4) {
        ++distance;
        A += 4;
    }
    distance += abs(A - B);
    cout << distance;
    return 0;
}
