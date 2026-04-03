#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;
vector<int> findNse(vector<int>& arr){
    int n = arr.size();
    vector<int> nse(n);
    stack<int> st;
    for(int i = n-1; i >= 0; i--){
        while(!st.empty() && arr[st.top()] >= arr[i]){
            st.pop();
        }
        if(st.empty()){
            nse[i] = n;
        }
        else{
            nse[i] = st.top();
        }
        st.push(i);
    }
    return nse;
}

vector<int> findPse(vector<int>& arr){
    int n = arr.size();
    vector<int> pse(n);
    stack<int> st;
    for(int i = 0; i < n; i++){
        while(!st.empty() && arr[st.top()] > arr[i]){
            st.pop();
        }
        if(st.empty()){
            pse[i] = -1;
        }
        else{
            pse[i] = st.top();
        }
        st.push(i);
    }
    return pse;
}

int sumSubarrayMins(vector<int>& arr) {
    int n = arr.size();
    int sum = 0;
    int mod = 1e9 + 7;
    vector<int> nse = findNse(arr);
    vector<int> pse = findPse(arr);
    for(int i = 0; i < n; i++){
        int left = i - pse[i];
        int right = nse[i] - i;
        long long freq = left*right*1LL;
        int val = (freq*arr[i]*1LL) % mod;
        sum = (sum + val) % mod;
    }
    return sum;
}

int main(){
    int n; 
    cout << "Enter the number of elements" << endl;
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements of the array" << endl;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int ans = sumSubarrayMins(arr);
    cout << ans << endl;
    return 0;
}