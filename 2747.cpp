#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int prev = 0, curr = 0, next = 1;
    for (int i = 0; i < n; ++i) {
        prev = curr;
        curr = next;
        next = prev + curr;
    }
    cout << curr;
    return 0;
}
