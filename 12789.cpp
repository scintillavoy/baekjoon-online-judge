#include <cstdio>
#include <stack>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    stack<int> stk;
    int currNum = 1;
    while (N--) {
        int num;
        scanf("%d", &num);
        if (num == currNum) {
            ++currNum;
        } else {
            while (!stk.empty() && stk.top() == currNum) {
                ++currNum;
                stk.pop();
            }
            stk.push(num);
        }
    }
    while (!stk.empty()) {
        if (stk.top() == currNum) {
            ++currNum;
            stk.pop();
        } else {
            printf("Sad\n");
            return 0;
        }
    }
    printf("Nice\n");
    return 0;
}
