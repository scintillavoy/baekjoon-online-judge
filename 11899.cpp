#include <cstdio>
using namespace std;

int main() {
    int input, left = 0, answer = 0;
    while (true) {
        switch (getc(stdin)) {
            case '(':
                ++left;
                break;
            case ')':
                if (left > 0) {
                    --left;
                } else {
                    ++answer;
                }
                break;
            default:
                answer += left;
                printf("%d", answer);
                return 0;
        }
    }
}
