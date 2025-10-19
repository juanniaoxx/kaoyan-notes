#include <iostream> 

using namespace std;

// 最简单的想法是快排之后遍历

void qs(int *q, int l,int r) {
    if (l >= r) return ;

    int i = l - 1, j = r + 1, x = q[l + r >> 1];
    while (i < j) {
        do i++; while (q[i] < x);
        do j--; while (q[j] >= x);
        if (q[i] > q[j]) swap(q[i], q[j]);
    }

    qs(q, l, j);
    qs(q, j + 1, r);
}

int solution(int A[], int n) {
    qs(A, 0, n - 1);

    for (int i = 0; i < n - 1; ++i) {
        if (A[i] <0 && A[i + 1] > 1) return 1;
        else if (A[i] > 0 && A[i + 1] - A[i] > 1) return A[i] + 1;
        else ; 
    }

    return A[n - 1] > 0 ? A[n - 1] + 1 : 1;
}


// O(n) hash

// 有鸽巢原理容易证明未出现的正整数最小值只能为[1....n+1]
// 只需要使用一个N元素大小的元素作为映射存储其是否出现即可

int hash(int A[], int n) {
    bool st[n];
    memset(st, 0, sizeof st); // 情况状态数组

    for (int i = 0; i < n; ++i) {
        if (A[i] > 0 && A[i] <= n) st[A[i]] = true; 
    }

    int count = 0;
    while (!st[count]) count++;

    return count + 1;
}

