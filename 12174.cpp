#include <iostream>
#include <bitset>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        int B;
        cin >> B;
        cout << "Case #" << i << ": ";
        bitset<8> bs;
        while (B--) {
            for (int j = 7; j >= 0; --j) {
                char ch;
                cin >> ch;
                bs[j] = (ch == 'I' ? 1 : 0);
            }
            cout << char(bs.to_ulong());
        }
        cout << '\n';
    }
    return 0;
}
