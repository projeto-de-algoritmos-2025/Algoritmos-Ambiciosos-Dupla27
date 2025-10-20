#include <stdio.h>
#include <stdlib.h>

#define MAX_FUROS 1000
#define INFINITO 1000000000

// Função para comparação usada no qsort
int comparar(const void *a, const void *b) {
    int x = *(int*)a;
    int y = *(int*)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int main() {
    int N, C, T1, T2;
    int furos[MAX_FUROS*2];  // vetor para armazenar os furos e o "duplicado"
    
    // Enquanto houver dados (EOF)
    while (scanf("%d %d %d %d", &N, &C, &T1, &T2) != EOF) {
        // Leitura dos furos
        for (int i = 0; i < N; i++) {
            scanf("%d", &furos[i]);
        }
        
        // Ordenar furos em ordem crescente
        qsort(furos, N, sizeof(int), comparar);
        
        // Criar vetor duplicado para simular a circunferência linear
        for (int i = 0; i < N; i++) {
            furos[i + N] = furos[i] + C;
        }
        
        int custo_minimo = INFINITO;
        
        // Testar cada posição como início da cobertura
        for (int inicio = 0; inicio < N; inicio++) {
            
            // dp[j] será o custo mínimo para cobrir furos do índice j até o fim (no intervalo linearizado)
            int dp[MAX_FUROS + 1];
            dp[N] = 0; // custo para cobrir "depois do último" é zero
            
            // Calcular dp de trás para frente, do último para o primeiro
            for (int j = N - 1; j >= 0; j--) {
                dp[j] = INFINITO;
                
                // Tentar cobrir com remendo T1
                
                // O remendo cobre intervalo de comprimento T1 a partir de furos[inicio + j]
                int limite_t1 = furos[inicio + j] + T1;
                int k = j;
                // avançar k até o último furos dentro do limite
                while (k < N && furos[inicio + k] <= limite_t1) {
                    k++;
                }
                // Atualiza dp[j] tentando cobrir até k-1 com remendo T1
                if (dp[k] + T1 < dp[j]) {
                    dp[j] = dp[k] + T1;
                }
                
                // Tentar cobrir com remendo T2
                int limite_t2 = furos[inicio + j] + T2;
                k = j;
                while (k < N && furos[inicio + k] <= limite_t2) {
                    k++;
                }
                if (dp[k] + T2 < dp[j]) {
                    dp[j] = dp[k] + T2;
                }
            }
            
            // Atualiza o custo minimo global
            if (dp[0] < custo_minimo) {
                custo_minimo = dp[0];
            }
        }
        
        printf("%d\n", custo_minimo);
    }
    
    return 0;
}
