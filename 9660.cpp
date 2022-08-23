#include <iostream>
using namespace std;

int main() {
    long long N;
    cin >> N;
    switch ((N-1) % 7) {
        case 0:
        case 2:
        case 3:
        case 4:
        case 5:
            cout << "SK";
            break;
        case 1:
        case 6:
            cout << "CY";
            break;
    }
    return 0;
}
