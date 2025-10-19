#include <iostream>

using namespace std;

// 我的建议是直接默写快排模版就能拿11分
// O(nlogn) O(log n)
void quick_sort(int *q, int l, int r) {
    if (l >= r) return;

    int i = l - 1, j = r + 1, x = q[l + r >> 1];

    while (i < j) {
        do i++; while (q[i] < x);
        do j--; while (q[j] >= x);
        if (i < j) swap(q[i], q[j]);
    }

    quick_sort(q, l, j);
    quick_sort(q, j + 1, r);
}

int solution(int *q, int n) {
    quick_sort(q, 0, n - 1);

    int s1 = 0, s2 = 0;

    for (int i = 0; i < n / 2 ; ++i) s1 += q[i];
    for (int j = n / 2; j < n; ++j) s2 += q[j];

    return abs(s1 - s2);
}

// O(n)的满分答案

int setPartition(int a[], int n) {
    int pivot_key, low = 0, low0 = 0, high = n - 1, high0 = n - 1, flag = 1, k = n/2, i = 0;
    int s1 = 0, s2 = 0;

    while (flag) {
        pivot_key = a[low];
        while (low < high) {
            while (low < high && a[high] >= pivot_key) -- high;
            if (low != high) a[low] = a[high];
            while (low < high && a[high] <= pivot_key) ++ low;
            if (low != high) a[high] = a[low];
        } 
        a[low] = pivot_key;
        if (low == k - 1)
            flag = 0;
        else {
            if (low < k - 1) {
                low0 = ++low;
                high = high0;
            } else {
                high0 =--high;
                low = low0;
            }
        }
    }

    for (int i = 0; i < k; ++i) s1 += a[i];
    for (int i = k; i < n; ++i) s2 += a[i];

    return s2 - s1;
