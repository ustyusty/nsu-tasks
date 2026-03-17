#include <stdint.h>


extern int global_n;
int64_t Sum(int l, int r);


int Query(int l, int64_t sum) {
    int left = l;
    int right = global_n;
    int ans = l;
    int mid;


    while (left <= right) {
        mid = left + (right - left) / 2;
        
        if (Sum(l, mid) <= sum) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ans;
}