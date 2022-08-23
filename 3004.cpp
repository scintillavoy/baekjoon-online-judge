#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    cout << (N / 2 + 1) * (N / 2 + (N % 2 ? 2 : 1));
    return 0;
}
