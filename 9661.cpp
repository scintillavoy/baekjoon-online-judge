#include <iostream>
using namespace std;

int main() {
    long long N;
    cin >> N;
    switch (N % 5) {
        case 0:
        case 2:
            cout << "CY";
            break;
        case 1:
        case 3:
        case 4:
            cout << "SK";
            break;
    }
    return 0;
}
