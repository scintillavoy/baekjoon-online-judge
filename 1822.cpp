#include <cstdio>
#include <set>
using namespace std;

int main() {
    int nA, nB;
    scanf("%d %d", &nA, &nB);
    set<int> S;
    while (nA--) {
        int num;
        scanf("%d", &num);
        S.insert(num);
    }
    while (nB--) {
        int num;
        scanf("%d", &num);
        S.erase(num);
    }
    
    printf("%d\n", S.size());
    for (auto const &x : S) {
        printf("%d ", x);
    }
    return 0;
}
