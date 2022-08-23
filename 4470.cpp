#include <iostream>
#include <string>
#include <limits>
using namespace std;

int main() {
    int N;
    cin >> N;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (int i = 0; i < N; ++i) {
        string str;
        getline(cin, str);
        cout << i + 1 << ". " << str << '\n';
    }
    return 0;
}
