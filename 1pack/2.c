#include <stdio.h>
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

long long factor(long long A, long long M){
    long long n =1;
    for (int i = 1; i <= A; i++) {
        n = (n * i) %M;
    }
    return n;
}

long long biamKof(int N, int K, long long M) {
    if (K > N || K < 0) return 0;
    if (K == 0 || K == N) return 1;

    long long res = 1;
    long long nN = factor(N, M);
    long long nK = factor(K, M);
    long long NmK= factor(N-K, M);
    res = nN * power((nK*NmK)%M, M-2, M);
    return res%M;

}

int main(void) {
    int T;
    long long M; 
    
    if (scanf("%lld %d", &M, &T) != 2) return 0;

    for(int i = 0; i < T; i++) {
        int N, K;
        scanf("%d %d", &N, &K);

        long long result = biamKof(N, K ,M);
        printf("%lld\n", result);
    }
    return 0;
}