#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
        int m = nums.size();
        int n = m + m;
        vector<int> nge(m);
        stack<int> st;
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && st.top() <= nums[i % m]){
                st.pop();
            }
            if(i < m){ // if the index is in the range so nge will be filled else not.
            if(st.empty()) nge[i] = -1;
            else nge[i] = st.top();
            }
            st.push(nums[i % m]);
        }
        return nge;
    }

int main(){
    int n;
    cout << "Enter the size of the array" << endl;
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements of the array" << endl;
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    vector<int> nge(n);
    nge = nextGreaterElements(nums);
    cout << "Printing the Next Greater Elements array" << endl;
    for(int i = 0; i < n; i++){
        cout << nge[i] << " ";
    }
    return 0;
}