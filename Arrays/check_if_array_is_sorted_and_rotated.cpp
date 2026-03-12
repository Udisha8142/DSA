#include<iostream>
#include<vector>
using namespace std;

bool isSortedRotated(vector<int>& nums){
    int n = nums.size();
    int drop = 0;
    for(int i = 0; i < n; i++){
        if(nums[i] > nums[i + 1 % n]){
            drop += 1;
            if(drop > 1) return false;
        }
    }
    return true;
}

int main(){
    int n;
    cout << "Enter the number of elements you want in an array" << endl;
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements of the array" << endl;
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    
    if(isSortedRotated(nums)){
        cout << "Array is sorted and rotated" << endl;
    }
    else{
    cout << "Array is not sorted and rotated" << endl;
    }
    
    return 0;
}