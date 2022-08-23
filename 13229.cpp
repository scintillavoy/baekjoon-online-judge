#include <cstdio>
#include <vector>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> vec(n+1);
    int sum = 0;
    for (int i = 1; i < n+1; ++i) {
        int num;
        scanf("%d", &num);
        sum += num;
        vec[i] = sum;
    }
    int m;
    scanf("%d", &m);
    while (m--) {
        int start, end;
        scanf("%d %d", &start, &end);
        printf("%d\n", vec[end+1] - vec[start]);
    }
    return 0;
}
