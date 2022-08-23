#include <iostream>
using namespace std;

int main() {
    unsigned int S;
    cin >> S;
    unsigned int N = 0;
    for (int i = 1; i <= S; ++i) {
        S -= i;
        ++N;
    }
    cout << N;
    return 0;
}
