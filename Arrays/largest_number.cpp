#include<vector>
#include<climits>
#include<iostream>
using namespace std;

int LargestNum(vector<int>& arr){
    int n = arr.size();
    int largest = INT_MIN;
    for(int i = 0; i < n; i++){
        if(arr[i] > largest){
            largest = arr[i];
        }
    }
    return largest;
}
int main(){
    int n;
    cout << "enter the size of arr";
    cin >> n;
    vector<int> arr(n);
    cout << "enter the values of arr";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int largestNum = LargestNum(arr);
    cout <<"largest number is" << largestNum;
}