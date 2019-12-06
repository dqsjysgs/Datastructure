#include <iostream>
using namespace std;

typedef struct node {
    char data;
    struct node* next;
} LinkNode;

void createlist(LinkNode* &head) {
    char str[1000];
    LinkNode* pnow, *ppre;
    cin >> str;
    int p = 0;
    head = NULL;
    while (str[p] != '\0') {
        pnow = new LinkNode;
        pnow->data = str[p];
        pnow->next = NULL;
        if (head == NULL)
            head = pnow;
        else
            ppre->next = pnow;
        ppre = pnow;
        p++;
    }
}

void split(LinkNode* strlist, LinkNode* &letter, 
        LinkNode* &num, LinkNode* &other) {
    letter = num = other = NULL;
    LinkNode* pstr = strlist, *post;
    while (pstr) {
        post = pstr->next;
        char temp = pstr->data;
        if (temp >= '0' && temp <= '9') {
            pstr->next = num;
            num = pstr;
        }
        else if ((temp >= 'A' && temp <= 'Z') ||
                (temp >= 'a' && temp <= 'z')) {
            pstr->next = letter;
            letter= pstr;
        }
        else {
            pstr->next = other;
            other = pstr;
        }
        pstr = post;
    }
}

void printlist(LinkNode* head) {
    LinkNode* p = head;
    while (p) {
        cout << p->data;
        p = p->next;
    }
    cout << endl;
}

int main(void) {
    
    LinkNode* strlist;
    cout << "Please enter a string:";
    createlist(strlist);
    cout << "All characters:";
    printlist(strlist);

    LinkNode *letter, *num, *other;
    split(strlist, letter, num, other);
    
    cout << "Letter characters:";
    printlist(letter);
    cout << "Number characters:";
    printlist(num);
    cout << "Other characters:";
    printlist(other);
    return 0;
}
