#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main() {
    int sum = 0;
    string str;
    int c;
    while ((c = getc(stdin)) != EOF) {
        switch (c) {
            case ',':
                sum += stoi(str);
                str = "";
                break;
            case '\n':
                break;
            default:
                str.push_back(c);
                break;
        }
    }
    cout << sum + stoi(str);
    return 0;
}
