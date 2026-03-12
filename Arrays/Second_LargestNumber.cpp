#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int second_Largest(vector<int>& nums){
    int n = nums.size();
    int largest = nums[0];
    int secondLargest = INT_MIN;
    for(int i = 1; i < n; i++){
        if(nums[i] > largest){
            secondLargest = largest;
            largest = nums[i];
        }
        else if(nums[i] > secondLargest && nums[i] < largest){
            secondLargest = nums[i];
        }
    }
    if(secondLargest != INT_MIN) return secondLargest;
    return -1;
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
    int secondLargest = second_Largest(nums);
    cout << "Second Largest is" << secondLargest << endl;
}