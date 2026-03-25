#include<iostream>
#include <algorithm>
#include<vector>
#include<stack>
using namespace std;

// Function which checks the priority
int priority(char c){
    if(c == '^') return 3;
    else if(c == '*' || c == '/') return 2;
    else if(c == '+' || c == '-') return 1;
    else return 0;
} 

// Function to convert from infix to postfix
string infixToPostfix(string&s){
    int n = s.length();
    int i = 0;
    stack<char> st;
    string ans;
    while(i<n){
            
        // In case s[i] is an operand 
        if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')){
            ans += s[i];
        } 
           
        // In case s[i] is an opening bracket '('
        else if(s[i] == '('){
            st.push(s[i]);
        }
           
        // In case s[i] is an closing bracket ')'
        else if(s[i] == ')'){
            while(!st.empty() && st.top() != '('){
                ans += st.top();
                st.pop();
            }
            st.pop(); // Removing unnecessary opening breacket
        }
           
        // In case s[i] is an operator
        else{
            if(s[i] == '^'){
                while(!st.empty() && priority(s[i]) <= priority(st.top())){
                    ans += st.top();
                    st.pop();
                }
            }
            else{
                while(!st.empty() && priority(s[i]) < priority(st.top())){
                    ans += st.top();
                    st.pop();
                }
            }
            st.push(s[i]);
        }
        i++;
    }
    while(!st.empty()){
        ans += st.top();
        st.pop();
    } 
    return ans;
}
    
    // Function that converts infix to prefix 
    string infixToPrefix(string &s) {
        int n = s.length();
        
        // Reversing the string for its conversion to postfix
        reverse(s.begin() , s.end());
        
        // Reversing the '(' to ')' and vice versa
        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                s[i] = ')';
            }
            else if(s[i] == ')'){
                s[i] = '(';
            }
        }
        
        //storing the result 
        string result = infixToPostfix(s);
        
        // Reversing the result produced
        reverse(result.begin() , result.end());
        
        // Final return 
        return result;
    }

int main(){
    string s;
    cin >> s;
    string result = infixToPrefix(s);
    cout << result ; 
}

