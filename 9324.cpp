#include <iostream>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        string str;
        cin >> str;
        int arr[26] = {0};
        bool isFake = false;
        for (int i = 0; i < str.size(); ++i) {
            if (++arr[str[i] - 'A'] == 3) {
                if (i+1 < str.size() && str[i+1] == str[i]) {
                    arr[str[i] - 'A'] = 0;
                    ++i;
                } else {
                    isFake = true;
                    break;
                }
            }
        }
        cout << (isFake ? "FAKE" : "OK") << '\n';
    }
    return 0;
}
