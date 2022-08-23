#include <iostream>
#include <string>
using namespace std;

int main() {
    int arr[9];
    char firstChar[8] = {'a', 'd', 'g', 'j', 'm', 'p', 't', 'w'};
    for (int i = 1; i <= 9; ++i) {
        int num;
        cin >> num;
        arr[num - 1] = i + '0';
    }
    string input, output;
    cin >> input;
    for (auto const &x : input) {
        int cnt = 0;
        switch (x) {
            case 'z':
            case 'y':
            case 'x':
            case 'w':
                ++cnt;
            case 'v':
            case 'u':
            case 't':
                ++cnt;
            case 's':
            case 'r':
            case 'q':
            case 'p':
                ++cnt;
            case 'o':
            case 'n':
            case 'm':
                ++cnt;
            case 'l':
            case 'k':
            case 'j':
                ++cnt;
            case 'i':
            case 'h':
            case 'g':
                ++cnt;
            case 'f':
            case 'e':
            case 'd':
                ++cnt;
            case 'c':
            case 'b':
            case 'a':
                break;
        }
        if (!output.empty() && output.back() == arr[cnt + 1]) {
            output.push_back('#');
        }
        output.append(x - firstChar[cnt] + 1, arr[cnt + 1]);
    }
    cout << output;
    return 0;
}
