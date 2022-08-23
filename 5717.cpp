#include <iostream>
using namespace std;

int main() {
    while (true) {
        int M, F;
        cin >> M >> F;
        if (!M && !F) {
            break;
        }
        cout << M + F << '\n';
    }
    return 0;
}
