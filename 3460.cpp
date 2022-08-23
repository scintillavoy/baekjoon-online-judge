#include <iostream>
#include <bitset>
#include <climits>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int num;
        cin >> num;
        bitset<sizeof(int) * CHAR_BIT> bs(num);
        for (int i = 0; i < bs.size(); ++i) {
            if (bs.test(i)) {
                cout << i << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}
