#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    cout << char('A' + (N % 12 + 8) % 12) << (N % 10 + 6) % 10;
}
