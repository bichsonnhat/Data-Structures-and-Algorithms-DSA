#include <iostream>
using namespace std;

struct date{
    int dd, mm, yy;
};

struct info{
    string seri;
    string name_cpt;
    date d;
    int cost;
};

void readDate(date &t){
    cout << "Nhap ngay:\n"; cin >> t.dd;
    cout << "Nhap thang:\n"; cin >> t.mm;
    cout << "Nhap nam:\n"; cin >> t.yy;
}
void showDate(date t){
    cout << t.dd << '/' << t.mm << '/' << t.yy << endl;
}
void readInput(info &t){
    cout << "Nhap Ma may:\n"; cin >> t.seri;
    cout << "Nhap ten may:\n"; cin >> t.name_cpt;
    cout << "Nhap ngay xuat hang:\n"; readDate(t.d);
    cout << "Nhap gia xuat hang di:\n"; cin >> t.cost;
}

void showOutput(info t){
    cout << "Ma may: " << t.seri << endl;
    cout << "Ten may: " << t.name_cpt << endl;
    cout << "Ngay xuat hang: "; showDate(t.d);
    cout << "Gia xuat hang di: " << t.cost << endl; 
}
struct pNode{
    info data;
    pNode* nextNode;
};

struct listNode{
    pNode* pHead;
    pNode* pTail;
};

class cQueue{
    private:
        listNode q;
        int len_q;
    public:
        cQueue();
        void push(info u);
        pNode* getNode(info u);
        info front();
        info back();
        void pop();
        bool empty();
};

cQueue::cQueue(){
    q.pHead = q.pTail = nullptr;
    len_q = 0;
}

info cQueue::back(){
    return q.pTail -> data;
}

bool cQueue::empty(){
    return q.pHead == nullptr;
};

pNode* cQueue::getNode(info u){
    pNode* p = new pNode();
    p -> data = u;
    p -> nextNode = nullptr;
    return p;
}

void cQueue::push(info u){
    pNode* p = getNode(u);
    if (q.pHead == nullptr){
        q.pHead = q.pTail = p;
        return;
    }

    q.pTail -> nextNode = p;
    q.pTail = p;
    len_q++;
}

info cQueue::front(){
    return q.pHead -> data;
}

void cQueue::pop(){
    pNode* cur = q.pHead;
    q.pHead = q.pHead -> nextNode;
    delete cur;
    len_q--;
    if (len_q == 0){
        q.pHead = q.pTail = nullptr;
    }
}

int main(){
    // Câu 1
    info t; readInput(t); showOutput(t);

    // Câu 2
    cQueue q, tq;
    int n; cin >> n;
    for (int i = 0; i < n; ++i){
        info u; readInput(u);
        q.push(u);
        tq.push(u);
    }

    // Câu 3
    cout << "Thong tin tat ca cac may tinh trong hang doi co ma hang la 007:\n";
    while (!tq.empty()){
        info u = q.front(); q.pop();
        if (u.seri == "007"){
            showOutput(u);
        }
    }

    // Câu 4
    cout << "Thong tin cac may da boc xep:\n";
    while (!q.empty()){
        showOutput(q.front()); q.pop();
    }
    return 0;
}