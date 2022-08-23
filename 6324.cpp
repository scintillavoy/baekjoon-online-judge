#include <cstdio>
#include <cstring>
using namespace std;

#define MAXLEN  61

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        char protocol[MAXLEN];
        char host[MAXLEN];
        char port[MAXLEN] = "<default>";
        char path[MAXLEN] = "<default>";

        scanf(" %[^:]%*[:/]%s", protocol, host);
        if (strstr(host, "/")) {
            sscanf(host, "%*[^/]/%s", path);
            sscanf(host, "%[^/]", host);
        }
        if (strstr(host, ":")) {
            sscanf(host, "%*[^:]:%s", port);
            sscanf(host, "%[^:]", host);
        }

        printf("URL #%d\n", i);
        printf("Protocol = %s\n", protocol);
        printf("Host     = %s\n", host);
        printf("Port     = %s\n", port);
        printf("Path     = %s\n\n", path);
    }
    return 0;
}
