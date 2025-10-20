#include <stdio.h>

int main() {
    int N;

    while (scanf("%d", &N) != EOF) {
        int contador[101] = {0}; // Contador de cada tamanho 1..100

        for (int i = 0; i < N; i++) {
            int inicio, fim;
            scanf("%d %d", &inicio, &fim);
            for (int tamanho = inicio; tamanho <= fim; tamanho++) {
                contador[tamanho]++;
            }
        }

        int Num;
        scanf("%d", &Num);

        // Construir rack (implicitamente)
        // rack: tamanhos em ordem crescente, repetidos contador[tamanho] vezes

        int pos_inicial = -1;
        int pos_final = -1;
        int pos = 0;

        for (int tamanho = 1; tamanho <= 100; tamanho++) {
            if (contador[tamanho] > 0) {
                if (tamanho == Num) {
                    pos_inicial = pos;
                    pos_final = pos + contador[tamanho] - 1;
                }
                pos += contador[tamanho];
            }
        }

        if (pos_inicial == -1) {
            printf("%d not found\n", Num);
        } else {
            printf("%d found from %d to %d\n", Num, pos_inicial, pos_final);
        }
    }

    return 0;
}
