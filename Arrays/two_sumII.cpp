#include<iostream>
#include<vector>
using namespace std;

vector<int> twoSumII(vector<int>& nums , int target){
    int n = nums.size();
    int left = 0;
    int right = n-1;
    while(left < right){
          if(nums[left] + nums[right] == target){
                return {left+1 , right+1};
            }
            else if(nums[left] + nums[right] > target){
                right--;
            }
            else{
                left++;
            }
    }
}
int main(){
    int n;
    cout << "Enter the number of elements of the array" << endl;
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements of the array" << endl;
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    int target;
    cout << "Enter the target" << endl;
    cin >> target;
    vector<int> answer = twoSumII(nums, target);
    for(int x: answer){
        cout << x << " ";
    }
    return 0;
}