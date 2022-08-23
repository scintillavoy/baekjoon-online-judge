#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    --N;
    switch (N % 14) {
        case 0:
        case 12:
            cout << "baby";
            break;
        case 1:
        case 13:
            cout << "sukhwan";
            break;
        case 4:
            cout << "very";
            break;
        case 5:
            cout << "cute";
            break;
        case 8:
            cout << "in";
            break;
        case 9:
            cout << "bed";
            break;
        case 2:
        case 6:
        case 10:
            if (N / 14 >= 3) {
                cout << "tu+ru*" << 2 + N / 14;
            } else {
                cout << "tururu";
                for (int i = 0; i < N / 14; ++i) {
                    cout << "ru";
                }
            }
            break;
        case 3:
        case 7:
        case 11:
            if (N / 14 >= 4) {
                cout << "tu+ru*" << 1 + N / 14;
            } else {
                cout << "turu";
                for (int i = 0; i < N / 14; ++i) {
                    cout << "ru";
                }
            }
            break;
    }
    return 0;
}
