// 考察带权路径和的计算

// WPL = 全部叶节点权值 * 带权路径长度
// WPL = 全部非也结点的权值之和
#include <queue>

using namespace std;

struct Tnode {
    int weight;
    Tnode *left, *right;
};


// WPL = 全部叶节点权值 * 带权路径长度
int dfs(Tnode *root, int d) {
    if (root->left == nullptr && root->right == nullptr)
        return (root->weight * d);
    else 
        return (dfs(root->left, d + 1) + dfs(root->right, d + 1));
}
int WPL(Tnode *root) {
    return dfs(root, 0);
}

// WPL = 全部非也结点的权值之和

int WPL2(Tnode *root) {
    int w_l, w_r;
    if (root->left == nullptr && root->right == nullptr)
        return 0;
    else {
        w_l = WPL2(root->left); // 计算左子树
        w_r = WPL(root->right); // 计算右子树
        root->weight = root->left->weight + root->right->weight; // 填写当前节点的权值

        return (w_l + w_r + root->weight);
    }
}

// 层序遍历

int cal_wpl(Tnode *root) {
    if (root == nullptr) return 0;

    int depth = 1, wpl = 0;

    queue<Tnode *> q;
    q.push(root); // 根节点入队

    while (!q.empty()) {
        int lens = q.size();
        while (lens > 0) {
            --lens;
            Tnode *t = q.front();
            if (t->left == nullptr && t->right == nullptr) {
                // 如果是叶节点记录答案
                wpl += depth * (t->weight);
            }

            if (t->left != nullptr) q.push(t->left);
            if(t->right != nullptr) q.push(t->right);
        }
        depth++;
    }

    return wpl;
}

