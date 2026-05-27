#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

int priority(char ch) {
    if(ch == '+' || ch == '-') return 1;
    if(ch == '*' || ch == '/') return 2;
    if(ch == '^') return 3;
    return 0;
}

string infix_to_postfix(string infix) {
    string postfix = " ";
    stack<char> st;
    for(int i = 0; i < infix.length(); ++i) {
        if(infix[i] == ' ') {
            continue;
            }
        char ch = infix[i];
        if(isalnum(ch)) {
            postfix += ch;
        } else if(ch == '(') {
            st.push(ch);
        } else if(ch ==')') {
            while(!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            } st.pop();
        } else {
            while(!st.empty() && priority(st.top()) >= priority(ch)) {
                postfix += st.top();
                st.pop();
            } st.push(ch);
        }
    } while(!st.empty()) {
        postfix += st.top();
        st.pop();
    } return postfix;
}

int main() {
    string x;
    cout << "Enter Infix Expression: ";
    getline(cin, x);
    cout << "Postfix Expression: " << infix_to_postfix(x) << endl;
}