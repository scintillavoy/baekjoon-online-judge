#include <iostream>
#include <cstdio>
#include <limits>
using namespace std;

int main() {
    int K, h;
    cin >> K;
    char c;
    for (int i = 1; i <= K; ++i) {
        cin >> h;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        do {
            switch (c = getc(stdin)) {
                case 'c':
                    ++h;
                    break;
                case 'b':
                    --h;
                    break;
            }
        } while(c != '\n');
        cout << "Data Set " << i << ":\n" << h << "\n\n";
    }
    return 0;
}
