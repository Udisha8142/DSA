#include<iostream>
#include<vector>
#include<string>
#include<climits>
using namespace std;

 string minWindow(string s, string t) {
      int n = s.length();
      int m = t.length();
      int left = 0;
      int right = 0;
      vector<int> hash (256,0);
      int minLen = INT_MAX;
      int sIndex = -1;
      int count = 0;
      for(int i = 0; i < m ; i++){
        hash[t[i]] ++;
      }
      while(right < n){
        if(hash[s[right]] > 0) count ++;
        hash[s[right]] --;
        while(count == m){
            if(right - left + 1 < minLen){
                minLen = right - left + 1;
                sIndex = left;
            }
            hash[s[left]] ++;
            if(hash[s[left]] > 0){
                count --;
            }
            left ++;
        }
        right ++;
      } 
      if(sIndex == -1) return ""; 
      return s.substr(sIndex , minLen);
    }
int main(){
    string s , t;
    cout << "Enter string 1" << endl;
    cin >> s;
    cout << "Enter string2" << endl;
    cin >> t;
    string ans = minWindow(s,t);
    cout << ans << endl;
    return 0;
}