#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int cnt = 0;
    for (int i = 0; i < N; ++i) {
        int response;
        cin >> response;
        if (response) {
            ++cnt;
        } else {
            --cnt;
        }
    }
    cout << "Junhee is" << (cnt > 0 ? " " : " not ") << "cute!";
    return 0;
}
