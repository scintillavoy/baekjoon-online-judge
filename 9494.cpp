#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (!n) {
            break;
        }
        int answer = 0;
        while (n--) {
            string str;
            getline(cin, str);
            int i;
            for (i = answer; i < str.size(); ++i) {
                if (str[i] == ' ') {
                    break;
                }
            }
            answer = i;
        }
        cout << answer + 1 << '\n';
    }
    return 0;
}
