#include <stdio.h>
#include <string.h>

#define MAX 100010

int main() {
    int N, D;
    char num[MAX];
    
    while (scanf("%d %d", &N, &D) && (N || D)) {
        scanf("%s", num);
        
        char stack[MAX];
        int top = 0;
        int toRemove = D;

        for (int i = 0; i < N; i++) {
            while (top > 0 && toRemove > 0 && stack[top - 1] < num[i]) {
                top--;
                toRemove--;
            }
            stack[top++] = num[i];
        }

        // Caso não tenha removido todos, remove do final
        top -= toRemove;

        // Imprime os N-D primeiros
        for (int i = 0; i < top; i++) {
            putchar(stack[i]);
        }
        putchar('\n');
    }
    return 0;
}
