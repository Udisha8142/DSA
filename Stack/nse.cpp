#include<iostream>
#include<vector>
#include<stack>
using namespace std;

 vector<int> nextSmallerEle(vector<int>& nums) {
        int n = nums.size();
        vector<int> nse(n);
        stack<int> st;
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && st.top() >= nums[i]){
                st.pop();
            }
            if(st.empty()) nse[i] = -1;
            else nse[i] = st.top();
            st.push(nums[i]);
        }
        return nse;
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
    vector<int> nse(n);
    nse = nextSmallerEle(nums);
    cout << "Printing the Next Smaller Element Array" << endl;
    for(int i = 0; i < n; i++){
        cout << nse[i] << " ";
    }
    return 0; 
}