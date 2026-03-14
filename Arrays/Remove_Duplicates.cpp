#include<iostream>
#include<vector>
using namespace std;
int removeDuplicates(vector<int>& nums){
    int n = nums.size();
    if(n == 0) return 0;
    int i = 0;
    for(int j = 1; j < n; j++){
        if(nums[i] != nums[j]){
            nums[i+1] = nums[j];
            i++;
        }
    }
    return i+1;
}
int main(){
    int n;
    cout << "Enter the number of element" << endl;
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements of the array" << endl;
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    int k = removeDuplicates(nums);
    for(int i = 0; i < k; i++){
        cout << nums[i] << " ";
    }
    return 0;
}