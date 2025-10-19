#include <iostream>

using namespace std;

struct node {
    char data[10];
    node *left, *right;
};

void dfs(node *root, int d) {
    if (root == nullptr) return ;
    else if (root->left == nullptr && root->right == nullptr)
        printf("%s", root->data); // 如果为叶子节点直接打印
    else {
        if (d > 1) printf("(");  // 打印左操作数前打印左括号
        // 中序遍历
        dfs(root->left, d + 1);
        printf("%s", root->data);
        dfs(root->right, d + 1);
        if (d > 1) printf(")"); // 打印右操作数后打印又括号 

        // 要求大于1是防止给整个式子加上左右括号与单个操作数加上不必要的括号
    }
}

void BtreeToExpression(node *root) {
    dfs(root, 1);
}
