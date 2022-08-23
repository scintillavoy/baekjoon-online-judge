#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    bool check[1000000] = {false};
    while (N--) {
        int A;
        cin >> A;
        check[A-1] = true;
    }
    for (int i = 0; i < 1000000; ++i) {
        if (!check[i]) {
            cout << i+1 << '\n';
            break;
        }
    }
    return 0;
}
