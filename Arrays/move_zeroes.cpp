#include<iostream>
#include<vector>
using namespace std;
void moveZeroes(vector<int>& nums){
    int n = nums.size();
    int i = 0;
    for(int j = 0; j < n; j++){
        if(nums[j] != 0){
            swap(nums[i] , nums[j]);
            i++;
        }
    }
}
int main(){
    int n; 
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    moveZeroes(nums);
    for(int i = 0; i < n; i++){
        cout << nums[i] << " ";
    }
}