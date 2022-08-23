#include <iostream>
#include <string>
using namespace std;

int main() {
    int sum[4] = {0};
    int check[4][13] = {0};
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); i += 3) {
        int idx;
        switch (str[i]) {
            case 'P':
                idx = 0;
                break;
            case 'K':
                idx = 1;
                break;
            case 'H':
                idx = 2;
                break;
            case 'T':
                idx = 3;
                break;
        }
        if (check[idx][stoi(str.substr(i + 1, 2)) - 1]) {
            cout << "GRESKA";
            return 0;
        } else {
            ++check[idx][stoi(str.substr(i + 1, 2)) - 1];
        }
        ++sum[idx];
    }
    for (auto const &x : sum) {
        cout << 13 - x << ' ';
    }
    return 0;
}
