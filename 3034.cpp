#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N, W, H;
    cin >> N >> W >> H;
    int upper_bound = sqrt(W*W + H*H);
    for (int i = 0; i < N; ++i) {
        int length;
        cin >> length;
        cout << (length <= upper_bound ? "DA" : "NE") << '\n';
    }
    return 0;
}
