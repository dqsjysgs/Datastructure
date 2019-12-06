#include <iostream>
using namespace std;
typedef struct Node {
    char data;
    struct Node* next;
}LNode, *LinkList;

void createlist_head(LinkList &head) {
//尾插法建立链表
    char str[1000];
    head = NULL;
    LinkList pnow, ppre;
    cin >> str;
    int p = 0;
    while (str[p] != '\0') {
        pnow = new LNode;
        pnow->data = str[p];
        if (head == NULL)
            head = pnow;
        else
            ppre->next = pnow;
        ppre = pnow;
        p++;
    }
}

void createlist_tail(LinkList &head) {
//头插法建立链表，本程序无用
    char str[1000];
    head = NULL;
    LinkList pnow;
    cin >> str;
    int p = 0;
    while (str[p] != '\0') {
        pnow = new LNode;
        pnow->data = str[p];
        pnow->next = head;
        head = pnow;
        p++;
    }
}

void printlist(const LinkList &head) {
//打印链表
    LinkList p = head;
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void merge(const LinkList& a, const LinkList& b, LinkList& c) {
//将a链表和b链表的字符合并，a和b中无重复元素，相同的字符只取一个
    c = NULL;
    LinkList pa = a, pb = b, pc = NULL;
    while (pa != NULL && pb != NULL) {
        if (pa->data < pb->data) {
            if (c == NULL) {
                c = pc = pa;
            }
            else {
                pc->next = pa;
                pc = pc->next;
            }
            pa = pa->next;
        }
        else if (pb->data < pa->data) {
            if (c == NULL) {
                c = pc = pb;
            }
            else {
                pc->next = pb;
                pc = pc->next;
            }
            pb = pb->next;
        }
        else {
            if (c == NULL) {
                c = pc = pa;
            }
            else {
                pc->next = pa;
                pc = pc->next;
            }
            pa = pa->next;
            LinkList q = pb;
            pb = pb->next;
            delete q;
        }
    }
    if (pa > 0)
        pc->next = pa;
    if (pb > 0)
        pc->next = pb;
}
int main(void) {

    LinkList mylist;

    cout << "Enter a string to build mylist: ";
    createlist_head(mylist);
    cout << "The values of mylist: ";
    printlist(mylist);
    cout << endl;

    LinkList yourlist;
    cout << "Enter a string to build yourlist: ";
    createlist_head(yourlist);
    cout << "The values of yourlist: ";
    printlist(yourlist);
    cout << endl;

    LinkList total;
    merge(mylist, yourlist, total);
    cout << "The values of totallist: ";
    printlist(total);

    return 0;
}
