#include <iostream>
#include <cstdio>
#include <limits>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    int cnt = 0, check = 0;
    for (int i = 0; i < n; ++i) {
        switch (getc(stdin)) {
            case 'A':
                if (check == 2) {
                    ++check;
                } else {
                    check = 0;
                }
                break;
            case 'P':
                if (check == 1) {
                    ++check;
                } else {
                    check = 0;
                }
                break;
            case 'p':
                if (check == 3) {
                    ++cnt;
                    check = 0;
                } else {
                    check = 1;
                }
                break;
        }
    }
    cout << cnt;
    return 0;
}
