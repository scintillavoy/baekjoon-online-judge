#include <iostream>
#include <deque>
#include <cstdio>
using namespace std;

void convert(deque<char> &deq) {
    for (int i = 0; i < deq.size(); ++i) {
        switch (deq.front()) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                return;
            default:
                deq.push_back(deq.front());
                deq.pop_front();
        }
    }
}

int main() {
    while (true) {
        deque<char> deq;
        char c;
        while ((c = getc(stdin)) != '\n') {
            if (c == '#') {
                return 0;
            }
            deq.push_back(c);
        }
        convert(deq);
        for (auto const &x : deq) {
            cout << x;
        }
        cout << "ay\n";
    }
    return 0;
}
