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
    int n = (int) s.size();
    bool res = 1;
    for (int i = 0; i < n; ++i){
        if (s[i] == '(' || s[i] == '{' || s[i] == '['){
            st.push(s[i]);
        } else {
            char open = st.top();
            if (open == '('){
                if (s[i] == ')'){
                    if (!st.empty()){
                        st.pop();
                    } else {
                        res = 0;
                        break;
                    }
                } else {
                    res = 0;
                    break;
                }
            }
            if (open == '{'){
                if (s[i] == '}'){
                    if (!st.empty()){
                        st.pop();
                    } else {
                        res = 0;
                        break;
                    }
                } else {
                    res = 0;
                    break;
                }
            }
            if (open == '['){
                if (s[i] == ']'){
                    if (!st.empty()){
                        st.pop();
                    } else {
                        res = 0;
                        break;
                    }
                } else {
                    res = 0;
                    break;
                }
            }
        }
    }

    if (st.empty()) res = 1;
        else res = 0;
    cout << (res == 1 ? "true" : "false");
    return 0;
}