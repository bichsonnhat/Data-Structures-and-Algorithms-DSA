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
    int t = n;
    Stack st;
    while (t){
        st.push(t % 2);
        t /= 2;
    }

    cout << "He nhi phan:\n";
    while (!st.empty()){
        cout << st.top(); st.pop();
    }

    cout << endl;
    t = n;
    while (t){
        st.push(t % 16);
        t /= 16;
    }

    cout << "He thap luc phan:\n";
    while (!st.empty()){
        int cur = st.top(); st.pop();
        if (cur < 10) cout << cur;
        if (cur == 10) cout << 'A';
        if (cur == 11) cout << 'B';
        if (cur == 12) cout << 'C';
        if (cur == 13) cout << 'D';
        if (cur == 14) cout << 'E';
        if (cur == 15) cout << 'F';
    }
    return 0;
}