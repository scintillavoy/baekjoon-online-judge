#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    --N;
    int level;
    for (level = 1; N > 0; ++level) {
        N -= level * 6;
    }
    cout << level;
    return 0;
}
