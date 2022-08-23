#include <iostream>
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    cout << (A+B >= C*2 ? A+B-C*2 : A+B);
    return 0;
}
