#include <iostream>
#include <string>
using namespace std;

int main() {
    int cnt = 0;
    string str;
    while (getline(cin, str)) {
        ++cnt;
    }
    cout << cnt;
    return 0;
}
