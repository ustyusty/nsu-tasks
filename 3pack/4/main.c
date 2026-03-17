#include <stdio.h>

typedef struct Factors {
    int k;
    int primes[32];
    int powers[32];
} Factors;

// Объявляем прототип функции
void Factorize(int X, Factors *res);

int main() {
    int M;
    // Считываем количество запросов
    if (scanf("%d", &M) != 1) return 0;

    for (int i = 0; i < M; i++) {
        int X;
        if (scanf("%d", &X) != 1) break;

        Factors res;
        Factorize(X, &res);

        printf("%d=", X);
        
        if (res.k == 0) {
            printf("1\n");
        } else {
            // Иначе выводим степени через знак умножения
            for (int j = 0; j < res.k; j++) {
                printf("%d^%d", res.primes[j], res.powers[j]);
                // Знак умножения ставим только между токенами
                if (j < res.k - 1) {
                    printf("*"); 
                }
            }
            printf("\n");
        }
    }
    return 0;
}