#include<bits/stdc++.h>
using namespace std;

struct Node{
    public:
    int data;
    Node* next;
    Node* back;

    public:
    Node(int data1 , Node* next1 , Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};


//CONVERTING THE ARRAY TO THE DOUBLY LINKED LIST 
Node* ConvertArrtoLL(vector<int> &arr){
    int n = arr.size();
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i = 1 ; i < n ; i++){
        Node* temp = new Node(arr[i] , nullptr , prev);
        prev -> next = temp;
        prev = temp;
    }
    return head; 
}

//PRINTING THE DOUBLY LINKED LIST 
void print(Node* head){
    Node* temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// INSERTION BEFORE HEAD

Node* insertBeforeHead(Node* head , int value){
    Node* newHead = new Node(value , head , nullptr);
    head -> back = newHead;
    return newHead;
}

// INSERTION BEFORE TAIL

Node* insertBeforeTail(Node* head , int value){
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp -> next;
    }
    Node* prev = temp -> back;
    Node* newNode = new Node(value , temp , prev);
    prev -> next = newNode;
    temp -> back = newNode;
    newNode -> back = prev;
    newNode -> next = temp;
    return head;
}

//INSERTION AT KTH POSITION 

Node* insertKthel(Node* head , int k , int value){
    if(k == 1){
        return insertBeforeHead(head , value);
    }
    int count = 0;
    Node* temp = head;
    while(temp){
        count ++;
        if(count == k) break;
        temp = temp -> next;
    }
    Node* prev = temp -> back;
    Node* newNode = new Node( value , temp , prev);
    prev -> next = newNode;
    temp -> back = newNode;
    return head;
}

//INSERTION AT A GIVEN NODE 
\
void insertAtNode( Node* node , int value){
    Node* temp = node;
    Node* prev = temp -> back;
    Node* newNode = new Node( value , node , prev);
    prev -> next = newNode;
    node -> back = newNode;
}
int main(){
   vector<int> arr = {1, 2, 3, 4, 5, 7};
   Node* head = ConvertArrtoLL(arr);
   insertAtNode(head->next , 4);
   print(head);
}
