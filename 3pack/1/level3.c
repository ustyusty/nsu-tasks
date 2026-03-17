#include "myblas.h"

// вычислить матрицу (alpha*A*B + beta*C) и записать её в C
void dgemm(
    int m, int n, int k,
    double alpha, const double *A, const double *B,
    double beta, double *C
) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            // Вычисляем скалярное произведение i-ой строки A и j-го столбца B
            double ab_sum = 0.0;
            for (int p = 0; p < k; ++p) {
                ab_sum += A[i * k + p] * B[p * n + j];
            }
            
            // Обновляем элемент матрицы C с учетом коэффициентов
            C[i * n + j] = alpha * ab_sum + beta * C[i * n + j];
        }
    }
}