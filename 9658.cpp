#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    switch ((N-1) % 7) {
        case 0:
        case 2:
            cout << "CY";
            break;
        case 1:
        case 3:
        case 4:
        case 5:
        case 6:
            cout << "SK";
            break;
    }
    return 0;
}
