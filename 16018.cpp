#include <cstdio>
#include <vector>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    getc(stdin);
    vector<char> vec(N);
    for (auto &x : vec) {
        x = getc(stdin);
    }
    getc(stdin);
    int cnt = 0;
    for (auto const &x : vec) {
        if (getc(stdin) == 'C' && x == 'C') {
            ++cnt;
        }
    }
    printf("%d\n", cnt);
    return 0;
}
