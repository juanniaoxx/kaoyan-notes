#include <iostream>
#include <string>

/**
 * BF（Brute Force）算法实现字符串模式匹配
 * 
 * @param S 主串
 * @param P 模式串
 * @return 如果找到匹配的子串，返回模式串在主串中的起始位置（从0开始）；
 *         如果未找到，返回 -1
 */
int PatternMathBF(const std::string& S, const std::string& P) {
    int m = S.length(); // 主串长度
    int n = P.length(); // 模式串长度

    if (n > m) {
        return -1;
    }

    // 遍历主串，从第0个字符开始，最多到 m - n 的位置
    for (int i = 0; i <= m - n; ++i) {
        int j;

        for (j = 0; j < n; ++j) {
            if (S[i + j] != P[j]) {
                break;
            }
        }

        if (j == n) {
            return i; // 返回匹配的起始位置
        }
    }
    
    return -1;
}

int main() {
    std::string s, t;
    std::cin >> s >> t;
    if (PatternMathBF(s, t)) std::cout << "Success" << std::endl;
    else std::cout << "Failure" << std::endl;
}