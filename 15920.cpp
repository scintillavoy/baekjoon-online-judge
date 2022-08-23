#include <cstdio>
using namespace std;

int main() {
    int N;
    scanf("%d\n", &N);
    int phase = 0, score = 0;
    bool lever = false;
    for (int i = 0; i < N; ++i) {
        switch (getc(stdin)) {
            case 'P':
                switch (phase) {
                    case 0:
                        lever = !lever;
                        break;
                    case 1:
                        score = 6;
                        break;
                }
                break;
            case 'W':
                switch (phase) {
                    case 1:
                        if (score != 6) {
                            score = (lever ? 1 : 5);
                        }
                    case 0:
                        ++phase;
                        break;
                }
                break;
        }
    }
    printf("%d", (phase == 2 ? score : 0));
    return 0;
}
