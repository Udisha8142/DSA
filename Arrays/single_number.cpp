#include<iostream>
#include<vector>
using namespace std;
int singleNumber(vector<int>& nums) {
    int n = nums.size();
    int singleone  = 0;
    for(int i = 0; i < n; i++){
        singleone = singleone ^ nums[i];
    }
    return singleone;
}
int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    int ans = singleNumber(nums);
    cout << ans;
    return 0;
     
}