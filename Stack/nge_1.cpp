#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> nge(n1);
        unordered_map<int , int> mpp;
        stack<int> st;
        for(int i = n2-1; i >=0; i--){
            while(!st.empty() && st.top() <= nums2[i]){
                st.pop();
            }
            if(st.empty()) mpp[nums2[i]] = -1;
            else mpp[nums2[i]] = st.top();
            st.push(nums2[i]);
        }
        for(int i = 0; i < n1; i++){
            nge[i] = mpp[nums1[i]];
        }
        return nge;
    }

int main(){
    cout << "Enter the number of elements in nums1" << endl;
    int n1;
    cin >> n1;
    cout << "Enter the number of elements in nums2" << endl;
    int n2;
    cin >> n2;
    vector<int> nums1(n1);
    vector<int> nums2(n2);
    vector<int> nge(n1);
    cout << "Enter the elements of nums1" << endl;
    for(int i = 0; i < n1; i++){
        cin >> nums1[i];
    }
    cout << "Enter the elements of nums2" << endl;
    for(int i = 0; i < n2; i++){
        cin >> nums2[i];
    }
    nge = nextGreaterElement(nums1, nums2);
    cout << "Printing out the next greater element array" << endl;
    for(int i = 0; i < n1; i++){
        cout << nge[i] << " ";
    }
    return 0;
}