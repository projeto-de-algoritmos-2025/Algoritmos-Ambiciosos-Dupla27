#include <stdio.h>
#include <stdlib.h>  

int main() {
    int n;
    while (scanf("%d", &n) && n) {
        long long trabalho = 0;
        long long saldo = 0;
        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            saldo += x;
            trabalho += llabs(saldo); 
        }
        printf("%lld\n", trabalho);
    }
    return 0;
}
