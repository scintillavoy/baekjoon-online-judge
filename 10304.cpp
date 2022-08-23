#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    while (N--) {
        string str;
        cin >> str;
        int check[6] = {0};
        for (auto const &x : str) {
            switch (x) {
                case 'G':
                    ++check[0];
                    break;
                case 'O':
                    ++check[1];
                    break;
                case 'L':
                    ++check[2];
                    break;
                case 'D':
                    ++check[3];
                    break;
                case 'E':
                    ++check[4];
                    break;
                case 'N':
                    ++check[5];
                    break;
            }
        }
        cout << *min_element(check, check + 6) << '\n';
    }
    return 0;
}
