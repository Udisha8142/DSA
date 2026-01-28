#include<bits/stdc++.h>
using namespace std;
struct Node{
    public:
    int data;
    Node* next;
    
    public:
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};


Node* ConvertArrtoLL(vector<int> &arr){ // it is of node type because we have to always return head of an linked list
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1 ; i < arr.size() ; i++){
        Node* temp = new Node(arr[i]);
        mover-> next = temp;
        mover = temp;
    }
    return head;
}

int LengthOfLL(Node* head){
    int count = 0;
    Node* temp = head;
    while(temp){
        count += 1;
        temp = temp->next;
    }
    return count;
}

int CheckifPresent(Node* head , int value){
    Node* temp = head;
    while(temp){
        if(temp->data == value) return 1;
            temp = temp->next;
    }
    return 0;
}

void print(Node* head){
    Node* temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* deleteHead(Node* head){  // we always have to return head of the linked list while deleting head
    if(head == NULL) return head;
    Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

Node* deleteTail(Node* head){ // we always have to return head of linked list while deleting tail
    if(head == NULL || head->next == NULL) return head; // if there only one element or LL is empty
    Node* temp = head;
    while(temp->next->next){
        temp = temp->next;
    }
    free(temp->next);
    temp->next = nullptr;
    return head;
}

Node* deleteK(Node* head , int k){
    if(head == NULL) return head; // EDGE CASE 
    if(k == 0){ // when k is == head 
        Node* temp = head;
        head = head -> next;
        free(temp);
        return head;
    }
    int count = -1; // when k is equal to any number greater than zero 
    Node* temp = head;
    Node* prev = NULL;
    while(temp){
        count++;
        if(count == k){
            prev->next = prev->next->next;
            free(temp); 
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node* deleteEL(Node* head , int el){
    if(head == NULL) return head; // EDGE CASE 
    if(head->data == el){ // when k is == head 
        Node* temp = head;
        head = head -> next;
        delete temp;
        return head;
    }
    Node* temp = head;
    Node* prev = NULL;
    while(temp){
        if(temp->data == el){
            prev->next = prev->next->next;
            delete temp; 
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node* insertHead(Node* head , int val){
    Node* temp = new Node(val , head);
    return temp;
}

Node* insertLast(Node* head , int val){
    if(head == NULL) return new Node(val);
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    Node* newNode = new Node(val);
    temp->next = newNode;
    return head;
}

Node* insertEl(Node* head , int val , int k){
    if(head == NULL){ // for the case when head == NULL and you want to insert on the first place 
        if(k == 1) return new Node(val);
        else return NULL;
    }
    if(k == 1){ // this for the insertion before head
        Node* newNode = new Node(val , head);
        return newNode;
    }
    int count = 0; // instertion at any kth position it inlcudes the case of inserting at the last of linked list 
    Node* temp = head;
    while(temp != NULL){
        count++;
        if(count == k-1){
            Node* newNode = new Node(val);
            newNode->next = temp->next;
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
    return head;
}

Node* insertBeforeValue(Node* head , int val , int el){
    if(head == NULL){ // for the case when head == NULL and you want to insert on the first place 
        return NULL;
    }
    if(head->data == val){ // this for the insertion before head
        Node* newNode = new Node(el , head);
        return newNode;
    }
 // instertion at any kth position it inlcudes the case of inserting at the last of linked list 
    Node* temp = head;
    while(temp->next != NULL){
        if(temp->next->data == val){
            Node* newNode = new Node(el);
            newNode->next = temp->next;
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
    return head;
}

int main(){
    vector<int> arr = { 2 ,3 ,4 ,5 ,6};
    Node* head = ConvertArrtoLL(arr);
    head = insertBeforeValue(head , 5 , 10);
    print(head);
}
