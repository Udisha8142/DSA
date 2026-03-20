// i >= 0 means present and -1 means not present
#include<iostream>
#include<vector>
using namespace std;
int linearSearch(vector<int>& nums, int target){
    int n = nums.size();
    for(int i = 0; i < n; i++){
        if(nums[i] == target){
            return i;
        }
    }
    return -1;
}
int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    int target;
    cin >> target;
    int ans = linearSearch(nums, target);
    cout << ans;
    return 0;
}