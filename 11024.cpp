#include <iostream>
#include <string>
#include <limits>
#include <sstream>
using namespace std;

int main() {
    int T;
    cin >> T;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (int i = 0; i < T; ++i) {
        int sum = 0;
        string str;
        getline(cin, str);
        istringstream iss(str);
        int num;
        while (iss >> num) {
            sum += num;
        }
        cout << sum << '\n';
    }
    return 0;
}
