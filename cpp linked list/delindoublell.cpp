#include<bits/stdc++.h>
using namespace std;

//STRUCTURE OF THE DOUBLY LINKED LIST 
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

//DELETING THE HEAD
Node* deleteHead(Node* head){
    if(head == NULL || head -> next == NULL){
        return NULL;
    }
    Node* prev = head;
    head = head -> next;
    head -> back = nullptr;
    prev -> next = nullptr; 
    delete(prev);
    return head;
}

//DELELTING THE TAIL

Node* deleteTail(Node* head){
    if(head == NULL || head -> next == NULL){
        delete head;
        return NULL;
    }
    Node* temp = head;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    Node* prev = temp -> back;
    prev -> next = nullptr;
    temp -> back = nullptr;
    delete temp;
    return head;
}

//DELETION AT KTH VALUE
Node* deleteKthel(Node* head , int k){
    if(head == NULL){
        return NULL;
    }
    int count = 0;
    Node* temp = head;
    while(temp != NULL){
        count ++;
        temp = temp -> next;
        if(count == k) break;
    }
    Node* prev = temp -> back;
    Node* Next = temp -> next;
    if(prev == NULL && Next == NULL){
        delete temp;
        return NULL;
    }
    else if( prev == NULL){
        deleteHead(head);
    }
    else if( Next == NULL){
        deleteTail(head);
    }
    prev -> next = Next;
    Next -> back = prev;
    temp -> back = nullptr;
    temp -> next = nullptr;
    delete(temp);
    return head;
}

// DELETION OF THE GIVEN NODE
void deleteNode(Node* node){
    Node* temp = node;
    Node* prev = temp -> back;
    Node* Next = temp -> next;

    if(Next == NULL){
        prev -> next = nullptr;
        temp -> back = nullptr;
        delete(temp);
        return;
    }

    prev -> next = Next;
    Next -> back = prev;
    temp -> back = temp -> next = nullptr;
    delete(temp);
    return;
}
int main(){
    int k;
    cin >> k;
    vector<int> arr ={1, 3, 5, 4, 2};
    Node* head = ConvertArrtoLL(arr);
    deleteNode(head->next->next);
    print(head);
}