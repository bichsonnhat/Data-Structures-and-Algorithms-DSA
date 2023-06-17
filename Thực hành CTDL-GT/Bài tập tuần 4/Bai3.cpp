#include <iostream>
using namespace std;

const int N = 1000;

class Stack{
    private:
        int cur_val;
        int len;
    public:
        int a[N];
        Stack();
        void push(int u);
        void pop();
        int top();
        bool empty();
        int size();
};

Stack::Stack(){
    cur_val = -1;
    len = 0;
}

int Stack::size(){
    return len;
}

int Stack::top(){
    return cur_val;
}

bool Stack::empty(){
    return (cur_val == -1);
}
void Stack::push(int u){
    a[++len] = cur_val = u;
}

void Stack::pop(){
    if (len == 0){
        cout << "Error\n";
        return;
    }

    len--;
    cur_val = (len == 0 ? -1 : a[len]);
}

int main(){
    int n; cin >> n;
    Stack st;
    while (n){
        st.push(n % 10);
        n /= 10;
    }
    int kq = 0;
    int i = 1;
    while (!st.empty()){
        int cur = st.top(); st.pop();
        kq = cur * i + kq;
        i = i * 10;
    }
    cout << kq;
    return 0;
}