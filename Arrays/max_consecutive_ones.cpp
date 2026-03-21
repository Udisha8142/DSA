#include<iostream>
#include<climits>
#include<vector>
using namespace std;
int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int maxCons = 0;
        int cons = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == 1){
                cons++;
                maxCons = max(maxCons , cons);
            }
            else{
                cons = 0;
            }
        }
        return maxCons;
}
int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    int maxCons = findMaxConsecutiveOnes(nums);
    cout << maxCons << endl;
    return 0;
}