// 众数问题

#include <vector>

using namespace std;

// 方法一 摩尔投票法
int majority(vector<int> A, int n) {
    int i = 0, c = A[0], count = 1;

    for (i = 1; i <  n; ++i) {
        if (A[i] == c) count++; // 如果是当前记录元素计数加一
        else if (count > 0) count--; // 如果不是当前计数元素就减一
        else { 
            // 如果count已经耗尽,则更改遍历到的元素为众数
            c = A[i];
            count = 1;
        }
    }

    // 由于题目不保证存在众数,需要重新遍历一遍记录具体出现的次数
    if (count > 0)
        for (i = count = 0; i < n; ++i)
            if (A[i] == c)
                count++;
    
    return count > n/2 ? c : -1;
}


// 方法二 计数排序 

int majority(vector<int> A, int n) {
    int max = 0;
    int *p = (int *)malloc(sizeof(int) * n);

    memset(p, 0, n); // 清空计数数组

    for (int k = 0; k < n; ++k) {
        p[A[k]]++;
        if (p[A[k]] > p[max]) max = A[k];
    }

    return p[max] > n / 2 ? max : -1;
}



