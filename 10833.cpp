#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int R = 0;
    for (int i = 0; i < N; ++i) {
        int student, apple;
        cin >> student >> apple;
        R += apple % student;
    }
    cout << R;
    return 0;
}
