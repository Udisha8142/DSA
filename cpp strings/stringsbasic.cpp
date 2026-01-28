#include<bits/stdc++.h>
#include <algorithm> 
using namespace std;
void stringInitialization(){
    string str = "HELLO";
    string str2("world");
    cout << str + " " + str2 << endl;
}

void stringinputoutput(){
    string name;
    cout << "Enter your name";
    getline(cin , name);
    cout << " Your name is:" << name << endl;
} 

void stringlength(){
    string str;
    cout << "Enter the string" << endl;
    getline(cin , str);
    int length = str.length();
    cout << length;
}

void accessingCharacters(){
    string str;
    cout << " Enter the string" << endl;
    getline(cin ,str);
    for(int i = 0 ; i < str.length() ; i++){
        cout << str[i] << endl;
    }
}

string strconcatenation(string str1 , string str2){
       string result = str1 + " " + str2;
       cout << result << endl;
}

string strComparison(string str1 , string str2 , string str3){
       if(str1 == str2){
        cout << " EQUAL " << endl;
       }
       else{
        cout << " NOT EQUAL " << endl;
       }
       if(str1 == str3){
        cout << " EQUAL " << endl;
       }
       else{
        cout << " NOT EQUAL " << endl;
       }
}

string findSubstring(string str1, string str2){
    int pos = str1.find(str2);
    if(pos != string::npos){
        cout << " Found at position " << pos << endl;
    }
}

void stringExtraction(string str1){
     string sub1 = str1.substr(0,5);
     string sub2 = str1.substr(6);
     cout << " Substring 1 is: " << sub1 << endl;
     cout << " Substring 2 is: " << sub2 << endl;
}

void stringModification(string str1 , string str2 , string str3){
    string M1 = str1.insert(5 , " World");
    string M2 = str2.erase(0 , 5);
    string M3 = str3.replace(0 , 5 , " hi ");
    cout << M1 << endl;
    cout << M2 << endl;
    cout << M3 << endl;
}

void caseConversion( string str1 , string str2){
    transform(str1.begin() , str1.end() , str1.begin() , ::toupper);
    transform(str2.begin() , str2.end() , str2.begin() , ::tolower);
    cout << str1 << endl;
    cout << str2 << endl;
}

void stringMethods(string str1){
    cout << str1.empty() << endl;
    int pos = str1.find_first_of("o");
    int pos2 = str1.find_last_of("o");
    cout << pos << endl;
    cout << pos2 << endl;
    reverse(str1.begin() , str1.end());
    cout << str1 << endl;
    str1.clear();
    cout << str1 << endl;
}

void stringLoop(string str){
    for(int i = 0 ; i < str.length() ; i++){
        cout << str[i] << " " << endl;
    }

    for (char c : str){
        cout << c << " " << endl;
    }
}
int main(){
    string str1;
    string str2;
    string str3;
    cout << " Enter string 1" << endl;
    getline(cin , str1);
    cout << "Enter strign 2" << endl;
    getline(cin , str2);
    cout << "Enter string 3" << endl;
    getline(cin , str3);
    stringLoop(str1);
    
}   


 string result = "";
    int i = 0;
    while( i < s .length){
        int  j = i + 1;
    if(s[i] == '(' && s[j] == s[i]){
        result += s[j];
        i = j + 1;
    }
    else if(s[i] == ')' && s[j] == s[i]){
        result += s[j];
        i = j + 1;
    }
    else if(s[i] == ')' && s[j] == '('){
        result += s[i];
        result += s[j];
        i = j + 1;
    }
    else{
        result += s[i];
        result += s[j];
        i = j + 1;
    }
}
return result;

   string result = "";
        int balance = 0;
        for(char c : s){
            if( c == '('){
                if(balance > 0) result += c;
                balance ++;
            }
            else{
                balance --;
                if(balance > 0) result += c;
            }
        }
        return result;