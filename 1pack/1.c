#include <stdio.h>

// Функция быстрого возведения в степень по модулю
// Вычисляет (base^exp) % mod
long long power(long long base, long long exp, long long mod) {
    long long res = 1;
    base %= mod;
    
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

int main(void) {
    int T;
    long long M; // M может быть большим, лучше использовать long long для безопасности
    
    if (scanf("%d %lld", &T, &M) != 2) return 0;

    for(int i = 0; i < T; i++) {
        long long A;
        scanf("%lld", &A);

        // Обратного элемента для 0 не существует
        if (A == 0) {
            printf("-1\n");
            continue;
        }

        // По Малой теореме Ферма обратный элемент = A^(M-2) % M
        long long result = power(A, M - 2, M);
        printf("%lld\n", result);
    }
    return 0;
}