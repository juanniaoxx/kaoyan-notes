/**
 *  求两个等长升序序列的中位数
 */

#include <iostream>
#include <vector>

using namespace std;
// O(log n) O(1) 的解法

int Solution1(vector<int> A, vector<int> B, int n) {
    int s1, d1, m1, s2, d2, m2;
    s1 = 0, d1 = n - 1;
    s2 = 1, d2 = n - 1;

    while (s1 != d1 || s2 != d2) {
        m1 = (s1 + d1) >> 1;
        m2 = (s2 + d2) >> 1;
        if (A[m1] == B[m2]) return A[m1]; // 如果a == b 则直接返回
        if (A[m1] < B[m2]) {
            // 此时 ....a...b.... 中位数只看出现在 a...b 之间
            // 要分奇偶考虑, 使得剩余序列仍然等长
            if ((s1+d1) % 2 == 0) {
                // 如果是奇数
                s1 = m1; // 舍去小于a的所有的数
                d2 = m2; // 舍去大于b的所有的数
            } else {
                // 如果是偶数
                s1 = m1 + 1; // 舍去 0...a 包括a的所有数
                d2 = m2;
            }
        } else {
            // 此时 ....b...a.... 中位数只能落在 b...a之间 
            if ((s1+d1) % 2 == 0) {
                d1 = m1; // 舍弃比a大1的数
                s2 = m2;  // 舍去比b小的数
            } else {
                d1 = m1; 
                s2 = m2 + 1; 
            }
        }
        return A[s1] < B[s2] ? A[s1] : B[s2];
    }
}

// 考场上好想的O(n) O(1)解法
// 并不真正归并,而是假装进行归并,则当访问到第n个元素的时候就是中位数

int findMedian(vector<int>& A, vector<int>& B, int n) {
    int i = 0, j = 0, k = 0;
    int median = 0;
    while (k < n) {         
        if (i < n && (j == n || A[i] <= B[j]))
            median = A[i++];
        else
            median = B[j++];
        ++k;
    }
    return median;
}
