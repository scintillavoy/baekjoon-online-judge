#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int cnt = 0;
    for (int i = 1; N > 0; ++i) {
        if (i > N) {
            i = 0;
        } else {
            N -= i;
            ++cnt;
        }
    }
    cout << cnt;
    return 0;
}
