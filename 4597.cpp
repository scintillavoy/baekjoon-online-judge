#include <iostream>
#include <string>
using namespace std;

int main() {
    while (true) {
        string str;
        cin >> str;
        if (str == "#") {
            break;
        }
        bool isEven = true;
        for (auto const &x : str) {
            switch (x) {
                case '1':
                    isEven = !isEven;
                case '0':
                    cout << x;
                    break;
                case 'e':
                    cout << (isEven ? '0' : '1') << '\n';
                    break;
                case 'o':
                    cout << (isEven ? '1' : '0') << '\n';
                    break;
            }
        }
    }
    return 0;
}
