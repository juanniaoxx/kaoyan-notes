// 寻找两个可能具有公共后缀的字符串的后缀起点

struct Node {
    char data;
    Node* next;
};

int listlen(Node *head) {
    // 求链表长度
    int lens = 0;
    for (Node *p = head; p->next != nullptr; p = p->next) {
        lens++;
    }
    return lens;
}

Node *findlist(Node *str1, Node *str2) {
    int m = listlen(str1);
    int n = listlen(str2);

    Node *p , *q;
    for (p = str1; m > n; m--) p = p->next;
    for (q = str2; m < n; n--) q = q->next;

    for (; p->next != nullptr && p->next != q->next; p = p->next, q = q->next) ;

    return p->next; 
}

