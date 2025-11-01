#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
    Node(): data(0), next(nullptr){}
};

Node* head; // Global Var

void Insert(int data, int n){  // 更健壮
    Node* temp1 = new Node();
    temp1->data = data;
    temp1->next = nullptr;
    if(n <= 0 || (head == nullptr && n != 1)){
        delete temp1;
        return;
    }
    if(n == 1){
        temp1->next = head;
        head = temp1;
        return;
    }
    Node* temp2 = head;
    for(int i = 1; i <= n-2; i++){
        temp2 = temp2->next;
        if(temp2 == nullptr){
            delete temp1;
            return;
        }
    }
    temp1->next = temp2->next;
    temp2->next = temp1;
}

void Delete(int n){    // 更健壮的代码，每次遇到都复习
    if(head == nullptr || n <= 0){
        return;
    }
    Node* temp1 = head;
    if(n == 1){
        head = temp1->next;
        delete temp1;
        return;
    }
    
    for(int i = 1; i <= n-2; i++){
        temp1 = temp1->next;
        if(temp1 == nullptr){
            return;
        }
    }

    Node* temp2 = temp1->next; // n
    if(temp2 == nullptr){
        return;
    }
    temp1->next = temp2->next;
    delete temp2;
    return;
}

void Print(){
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

int main(){
    head = nullptr;
    Insert(2, 1);  // List:2
    Insert(3, 2);  // List:2 3
    Insert(4, 1);  // List:4 2 3
    Insert(5, 2);  // List:4 5 2 3
    Delete(3);     // List:4 5 3
    Delete(1);     // List:5 3
    Print();
    return 0;
}