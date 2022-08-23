#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    long long circumference = 4, curr = 1, next = 2, next2 = 3;
    while (--N) {
        circumference += curr * 2;
        curr = next;
        next = next2;
        next2 = curr + next;
    }
    cout << circumference;
    return 0;
}
