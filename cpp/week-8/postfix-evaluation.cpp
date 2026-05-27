#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

int evaluate(string postfix) {
    stack<int> st;
    char ch;
    for(int i = 0; i < postfix.length(); ++i) {
        ch = postfix[i];
        if(isdigit(ch)) {
            st.push(ch - '0');
        } else {
            int val2 = st.top(); st.pop();
            int val1 = st.top(); st.pop();
            switch(ch) {
                case '+': st.push(val1 + val2);
                        break;
                case '-': st.push(val1 - val2);
                        break;
                case '*': st.push(val1 * val2);
                        break;
                case '/': st.push(val1 / val2);
                        break;
                case '^': st.push(val1 ^ val2);
                        break;
            } 
        }
    } return st.top();
}

int main() {
    string x;
    cout << "Enter Postfix Expression: ";
    getline(cin, x);
    cout << "After Evaluation: " << evaluate(x) << endl;
}