#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int trap(vector<int>& height) {
    int n = height.size();
    int leftMax = 0;
    int rightMax = 0;
    int total = 0;
    int l = 0;
    int r = n-1;
    while(l < r){
        if(height[l] <= height[r]){
            if(height[l] < leftMax){
                total += leftMax - height[l];
            }
            else{
                leftMax = height[l]; //As height[l] is bigger than lMax so we do not need to do max
            }
            l++;
        }
        else{
            if(height[r] < rightMax){
                total += rightMax - height[r];
            }
            else{
                rightMax = height[r];//As height[r] is bigger than rMax so we do not need to do max
            }
            r--;
        }
    }
return total;
}

int main(){
    int n ; 
    cout << "Enter the number of elements of array" << endl;
    cin >> n;
    vector<int> height(n);
    cout << "Enter the elements of the array" << endl;
    for(int i = 0; i < n; i++){
        cin >> height[i];
    }
    int total = trap(height);
    cout << "The total trapping rain water is:" << total << endl;
    return 0;
}