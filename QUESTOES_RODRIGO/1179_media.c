#include <stdio.h>

//Nessa questão, ao receber dois números, temos que retornar um número que faça com que a média E a mediana entre esses três 
// tenha o exato mesmo valor. A maior dor de cabeça foram alguns problemas de timeout e a lógica matemática por trás.

// Ao A sempre ser a média e a mediana, o ideal para o valor C é manter essa propriedade válida. 
// Se A for a média, então para achar o C, precisamos do valor total (2*A) menos o que não o representa (B). Logo:
// C=2A−B

int main() {
    long long a, b;
    while (1) {
        if (scanf("%lld %lld", &a, &b) != 2) break;
        if (a == 0 && b == 0) break;

        long long c = 2LL * a - b;
        printf("%lld\n", c);
    }
    return 0;
}