/* VALID PARANTHESIS */
class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        stack<char> st;
        for(int i = 0 ; i < n ; i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
            }
            else{
                if(st.empty()) return false;
                if(s[i] == ')' && st.top() != '(') return false;
                if(s[i] == ']' && st.top() != '[') return false;
                if(s[i] == '}' && st.top() != '{') return false;
                st.pop();
            }
        }
        return st.empty();
    }
};

/*NEXT GREATER ELEMENT 2*/
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge(n , -1);
        stack<int> st;
        for(int i = (2*n)-1 ; i >= 0; i--){
            while(!st.empty() && nums[i % n] >= st.top()){
                st.pop();
            }
            if(i < n){
                nge[i] = st.empty() ? -1 : st.top();
            }
            st.push(nums[i % n]);
        }
        return nge;
    }
};