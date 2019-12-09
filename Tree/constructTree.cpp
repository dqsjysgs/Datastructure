#include <iostream>
using namespace std;
typedef struct node {
    char ch;
    struct node *left, *right;
} *Btree, Bnode;

void construct(Btree &root) {
    char c;
    cin >> c;
    if (c == '#') {
        root = NULL;
    }
    else {
        root = new Bnode;
        root->ch = c;
        construct(root->left);
        construct(root->right);
    }
}

void mypreorder(Btree &root) {
    if (root == NULL) return;
    Btree p = root;
    cout << p->ch << " ";
    mypreorder(p->left);
    mypreorder(p->right);
}

void preorder(Btree &root) {
    if (root) {
        cout << root->ch << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(Btree &root) {
    if (root) {
        inorder(root->left);
        cout << root->ch << " ";
        inorder(root->right);
    }
}

void postorder(Btree &root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        cout << root->ch << " ";
    }
}

int main(void) {

    Btree mytree;
    construct(mytree);
    
    mypreorder(mytree);
    cout << endl;

    inorder(mytree);
    cout << endl;

    postorder(mytree);
    cout << endl;
    return 0;
}
