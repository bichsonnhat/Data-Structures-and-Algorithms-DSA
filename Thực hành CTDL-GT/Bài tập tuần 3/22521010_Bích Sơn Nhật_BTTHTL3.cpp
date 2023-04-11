#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* nextNode;
};

struct ListNode{
    Node* pHead;
    Node* pTail;
};

ListNode L, rL;
ListNode A, B, AB, C;

Node* getNode(int value){
    Node* p = new Node();
    p -> data = value;
    p -> nextNode = nullptr;
    return p;
}

void addHead(ListNode &L, Node* p){
    if (L.pHead == nullptr){
        L.pHead = L.pTail = p;
        return;
    }

    p -> nextNode = L.pHead;
    L.pHead = p;
}

void addTail(ListNode &L, Node* p){
    if (L.pHead == nullptr){
        L.pHead = L.pTail = p;
        return;
    }

    L.pTail -> nextNode = p;
    L.pTail = p;
}

void insertAfter(ListNode &L, Node* p, Node* q){
    if (p == nullptr){ // List is empty
        addHead(L, q); // or addTail(L, q);
        return;
    }

    if (p == L.pTail){
        addTail(L, q);
        return;
    }

    q -> nextNode = p -> nextNode;
    p -> nextNode = q;
}

void deleteNodeAfter(ListNode &L, Node *p){
    Node* q = p -> nextNode;
    p -> nextNode = q -> nextNode;
    delete q;
}

void deleteHead(ListNode &L){
    if (L.pHead == nullptr) {
        return;
    }
    Node* cur = L.pHead;
    L.pHead = L.pHead -> nextNode;
    delete cur;
}

void deleteTail(ListNode &L){
    if (L.pTail == nullptr){
        return;
    }

    Node* tmp = L.pHead;

    while (tmp -> nextNode -> nextNode != nullptr){
        tmp = tmp -> nextNode;
    }

    Node* cur = tmp -> nextNode;
    tmp -> nextNode = nullptr;
    delete cur;
}

void printfLinkedList(ListNode L){
    while (L.pHead != nullptr){
        cout << L.pHead -> data << ' ';
        L.pHead = L.pHead -> nextNode;
    }
    cout << endl;
}

void Bai6(ListNode L){
    int k; cin >> k;
    Node* tmp = L.pHead;
    while (tmp != nullptr){
        if (tmp -> data == k){
            break;
        } else {
            tmp = tmp -> nextNode;
        }
    }

    int x; cin >> x;
    Node* newNode = getNode(x);
    insertAfter(L, tmp, newNode);
    printfLinkedList(L);
}

void Bai7(ListNode L){
    int n; cin >> n;
    Node* tmp = L.pHead;
    int count = -1;
    while (tmp != nullptr){
        count += 1;
        if (count == n - 1){
            break;
        }
        tmp = tmp -> nextNode;
    }
    int x; cin >> x;
    Node* cur = getNode(x);
    insertAfter(L, tmp, cur);
    printfLinkedList(L);
}

ListNode Bai8(ListNode L){
    while (L.pHead != nullptr){
        addHead(rL, getNode(L.pHead -> data));
        L.pHead = L.pHead -> nextNode;
    }
    // printfLinkedList(rL);
    return rL;
}
    
bool Bai9(ListNode &L, int x){
    Node* tmp = L.pHead;

    while (tmp != nullptr){
        if (tmp -> nextNode -> data == x){
            // cout << tmp -> data << endl; return 1;
            deleteNodeAfter(L, tmp);
            return 1;
        } else {
            tmp = tmp -> nextNode;
        }
    }

    return 0;
}

void Bai10(ListNode &L){
    deleteHead(L);
    printfLinkedList(L);
}

void Bai11(ListNode &L){
    deleteTail(L);
    printfLinkedList(L);
}

void deleteLL(ListNode &L){
    while (L.pHead != nullptr){
        Node* q = L.pHead;
        L.pHead = L.pHead -> nextNode;
        delete q;
    }

    if (L.pHead == nullptr){
        L.pTail = nullptr;
    }
}

void Bai12(ListNode &L){
    deleteLL(L);
}


void Bai13(){
    cout << "Nhap DSLK sap xep tang\n";
    int n; cin >> n;

    for (int i = 0; i < n; ++i){
        int val; cin >> val;
        Node* newNode = getNode(val);
        addTail(L, newNode);
    }

    printfLinkedList(L);

    int x; cin >> x;

    Node* tmp = L.pHead;
    Node* NodeX = getNode(x);
    if (tmp -> data > x){
        addHead(L, NodeX);
        return;
    }

    while (tmp != nullptr){
        if (tmp -> data <= x && tmp -> nextNode == nullptr){
            addTail(L, NodeX);
            return;
        }
        if (tmp -> data <= x && x <= (tmp -> nextNode -> data)){
            insertAfter(L, tmp, NodeX);
            return;
        } else {
            tmp = tmp -> nextNode;
        }
    }
    
}


void Bai14(){
    int n; cin >> n;
    for (int i = 0; i < n; ++i){
        int val; cin >> val;
        addTail(A, getNode(val));
    }
    int m; cin >> m;
    for (int i = 0; i < m; ++i){
        int val; cin >> val;
        addTail(B, getNode(val));
    }
    printfLinkedList(A);
    printfLinkedList(B);

    Node* p = A.pHead;
    while (p != nullptr){
        addTail(AB, p);
        p = p -> nextNode;
    }

    AB.pTail -> nextNode = B.pHead;
    printfLinkedList(AB);
}

void Bai15(){
    deleteLL(A); deleteLL(B);
    int n; cin >> n;
    for (int i = 0; i < n; ++i){
        int val; cin >> val;
        addTail(A, getNode(val));
    }
    // printfLinkedList(A);
    // cout << (B.pTail == nullptr) << endl; return;
    Node* p = A.pHead;
    int cnt = 0;
    for (int i = 0; i < n; ++i){
        if (n % 2 == 0){
            if (i < n / 2){
                addTail(B, getNode(p -> data));
            } else {
                addTail(C, getNode(p -> data));
            }
        } else {
            if (i <= n / 2){
                addTail(B, getNode(p -> data));
            } else {
                addTail(C, getNode(p -> data));
            }
        }
        p = p -> nextNode;
    }
    printfLinkedList(B);
    printfLinkedList(C);
}

void Bai16(){
    deleteLL(A); deleteLL(B); deleteLL(C);
    int n; cin >> n;
    for (int i = 0; i < n; ++i){
        int val; cin >> val;
        addTail(A, getNode(val));
    }
    Node* p = A.pHead;
    while (p != nullptr){
        if ((p -> data) % 2 == 0){
            addTail(C, getNode(p -> data));
        } else {
            addTail(B, getNode(p -> data));
        }
        p = p -> nextNode;
    }
    printfLinkedList(B);
    printfLinkedList(C);
}

void Bai17(){
    deleteLL(A); deleteLL(B); deleteLL(C);
    int n; cin >> n;
    for (int i = 0; i < n; ++i){
        int val; cin >> val;
        addTail(A, getNode(val));
    }
    int m; cin >> m;
    for (int i = 0; i < m; ++i){
        int val; cin >> val;
        addTail(B, getNode(val));
    }

    Node* i = A.pHead;
    Node* j = B.pHead;

    while (i != nullptr && j != nullptr){
        if (i -> data <= j -> data){
            addTail(C, getNode(i -> data));
            i = i -> nextNode;
        } else {
            addTail(C, getNode(j -> data));
            j = j -> nextNode;
        }
    }

    while (i != nullptr){
        addTail(C, getNode(i -> data));
        i = i -> nextNode;
    }

    while (j != nullptr){
        addTail(C, getNode(j -> data));
        j = j -> nextNode;
    }
    printfLinkedList(C);

}

int main(){
    int val; 
    while (true){
        cin >> val;
        if (val == 0){
            break;
        }
        Node* newNode = getNode(val);
        addTail(L, newNode);

    }

    Bai6(L);
    Bai7(L);
    rL = Bai8(L);
    printfLinkedList(rL);

    int x; cin >> x;
    if (Bai9(L, x)){
        cout << 1 << endl;
        printfLinkedList(L);
    } else {
        cout << 0 << endl;
    }
    
    Bai10(L);
    Bai11(L);
    Bai12(L);

    Bai13();
    printfLinkedList(L);
    
    Bai14();
    Bai15();
    Bai16();
    Bai17();
    return 0;
}

/*
    Sample Input For This Format:
    1 2 3 4 5 0
    3
    7
    3 11
    11

    7
    1 2 3 4 5 6 7
    8

    3
    1 2 3
    2
    8 9

    5
    1 2 3 4 5

    5
    1 2 3 4 5

    4
    2 8 9 10
    3
    1 4 5
*/