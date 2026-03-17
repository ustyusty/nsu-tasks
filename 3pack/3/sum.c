#include <stdint.h>

int64_t pref[100005];
int global_n;

void Init(const int *arr, int n) {
    int i;
    global_n = n;
    pref[0] = 0;
    for (i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + arr[i];
    }
}

// Найти сумму элементов arr на отрезке [l..r)
int64_t Sum(int l, int r) {
    return pref[r] - pref[l];
}