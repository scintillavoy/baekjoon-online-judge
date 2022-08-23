#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        string str;
        cin >> str;
        if (str[str.size()/2 - 1] == str[str.size()/2]) {
            cout << "Do-it\n";
        } else {
            cout << "Do-it-Not\n";
        }
    }
    return 0;
}
