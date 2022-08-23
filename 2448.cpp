#include <iostream>
using namespace std;

void printStar(int N, int M) {
    if (N == 3) {
        switch (M) {
            case 0:
                cout << "  *  ";
                break;
            case 1:
                cout << " * * ";
                break;
            case 2:
                cout << "*****";
                break;
        }
    } else {
        if (M < N / 2) {
            for (int i = 0; i < N / 2; ++i) {
                cout << ' ';
            }
            printStar(N / 2, M);
            for (int i = 0; i < N / 2; ++i) {
                cout << ' ';
            }
        } else {
            printStar(N / 2, M - N / 2);
            cout << ' ';
            printStar(N / 2, M - N / 2);
        }
    }
}

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        printStar(N, i);
        cout << '\n';
    }
    return 0;
}
