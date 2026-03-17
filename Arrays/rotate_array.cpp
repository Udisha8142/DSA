#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;
void rotateArray(vector<int>& nums, int k){
     int n = nums.size();
     reverse(nums.begin() , nums.begin() + (n - k % n));
     reverse(nums.begin() + (n - k % n) , nums.end());
     reverse(nums.begin(), nums.end());
}
int main(){
    int n;
    cout << "Enter the number of elements" << endl;
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements of the array" << endl;
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    int k;
    cout << "Enter the steps to rotate array by k steps" << endl;
    cin >> k;
    rotateArray(nums, k);
    for(int i = 0; i < n; i++){
        cout << nums[i] << " ";
    }
    return 0;
}