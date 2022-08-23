#include <iostream>
using namespace std;

int main() {
    int V;
    cin >> V;
    int cnt = 0;
    for (int i = 0; i < V; ++i) {
        char vote;
        cin >> vote;
        switch (vote) {
            case 'A':
                --cnt;
                break;
            case 'B':
                ++cnt;
                break;
        }
    }
    if (cnt < 0) {
        cout << 'A';
    } else if (cnt > 0) {
        cout << 'B';
    } else {
        cout << "Tie";
    }
    return 0;
}
