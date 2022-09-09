#include <cstdio>
using namespace std;

int main() {
  int K, D, A;
  scanf("%d/%d/%d", &K, &D, &A);
  printf(K + A < D || D == 0 ? "hasu" : "gosu");
  return 0;
}
