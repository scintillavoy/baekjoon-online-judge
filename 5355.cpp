#include <iostream>
#include <string>
#include <sstream>
#include <limits>
using namespace std;

int main() {
    int T;
    cin >> T;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (int i = 0; i < T; ++i) {
        string str;
        getline(cin, str);
        istringstream ss(str);
        double num;
        ss >> num;
        char op;
        while (ss >> op) {
            switch (op) {
                case '@':
                    num *= 3;
                    break;
                case '%':
                    num += 5;
                    break;
                case '#':
                    num -= 7;
                    break;
            }
        }
        cout.precision(2);
        cout << fixed << showpoint << num << '\n';
    }
    return 0;
}
