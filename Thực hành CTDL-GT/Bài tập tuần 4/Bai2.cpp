#include <iostream>
using namespace std;

const int N = 1000;

class Stack{
    private:
        char cur_val;
        int len;
    public:
        char a[N];
        Stack();
        void push(char u);
        void pop();
        char top();
        bool empty();
        int size();
};

Stack::Stack(){
    cur_val = '#';
    len = 0;
}

int Stack::size(){
    return len;
}

char Stack::top(){
    return cur_val;
}

bool Stack::empty(){
    return (cur_val == '#');
}
void Stack::push(char u){
    a[++len] = cur_val = u;
}

void Stack::pop(){
    if (len == 0){
        cout << "Error\n";
        return;
    }

    len--;
    cur_val = (len == 0 ? '#' : a[len]);
}

int main(){
    string s; cin >> s;
    Stack st;
    for (int i = 0; i < (int) s.size(); ++i){
        st.push(s[i]);
    }
    while (!st.empty()){
        cout << st.top(); st.pop();
    }
    return 0;
}