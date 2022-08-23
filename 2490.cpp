#include <iostream>
using namespace std;

int main() {
    for (int i = 0; i < 3; ++i) {
        int cnt = 0;
        for (int j = 0; j < 4; ++j) {
            int num;
            cin >> num;
            if (num) {
                ++cnt;
            }
        }
        switch (cnt) {
            case 0:
                cout << 'D';
                break;
            case 1:
                cout << 'C';
                break;
            case 2:
                cout << 'B';
                break;
            case 3:
                cout << 'A';
                break;
            case 4:
                cout << 'E';
                break;
        }
        cout << '\n';
    }
    return 0;
}
