#include "myblas.h"

// вычислить вектор (alpha*A*X + beta*Y) длины m, и записать его в Y
void dgemv(
    int m, int n,
    double alpha, const double *A, const double *X,
    double beta, double *Y
) {
    for (int i = 0; i < m; ++i) {
        // Сначала считаем произведение i-ой строки матрицы A на вектор X
        double ax_sum = 0.0;
        for (int j = 0; j < n; ++j) {
            ax_sum += A[i * n + j] * X[j];
        }
        // Затем обновляем i-ый элемент вектора Y
        Y[i] = alpha * ax_sum + beta * Y[i];
    }
}

// вычислить матрицу (alpha*X*Yt + A) и записать её в A
void dger(
    int m, int n,
    double alpha, const double *X, const double *Y,
    double *A
) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {

            // Элемент (X * Yt)_{i,j} равен X[i] * Y[j]
            A[i * n + j] += alpha * X[i] * Y[j];
        }
    }
}