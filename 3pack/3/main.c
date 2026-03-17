#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void Init(const int *arr, int n);
int Query(int l, int64_t sum);

int main() {
    int n, m, i;
    int *arr;
    int l;
    int64_t s;
    int r;
    FILE *fin, *fout;


    fin = fopen("input.txt", "r");
    if (!fin) return 0;
    
    fout = fopen("output.txt", "w");
    if (!fout) {
        fclose(fin);
        return 0;
    }

    if (fscanf(fin, "%d %d", &n, &m) != 2) {
        fclose(fin);
        fclose(fout);
        return 0;
    }

    arr = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; ++i) {
        fscanf(fin, "%d", &arr[i]); 
    }

    Init(arr, n);


    for (i = 0; i < m; ++i) {
        fscanf(fin, "%d %lld", &l, &s); 
        r = Query(l, s); 
        fprintf(fout, "%d\n", r); 
    }

    free(arr);
    fclose(fin);
    fclose(fout);
    return 0;
}