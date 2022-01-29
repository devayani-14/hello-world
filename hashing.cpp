#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data; struct Node *next;
};
void sortedinsert(Node **ptr, int data){
    Node* p = *ptr; Node* prev; Node*  curr;Node* t = new Node;
    if (*ptr == NULL) *ptr = t; 
    else{
        while (curr != NULL && data>curr->data){
            prev = curr; curr = curr->next; 
        }
        if (curr == *ptr) {t->next = *ptr; *ptr = t; }
        else{t->next = prev->next; prev->next = t; }
    } 
} 
struct Node *search(Node* h[], int key){
    int hash = key%10; 
    Node* p = h[hash]; 
    while (p!= NULL){
        if (key == p->data) return p; 
        p = p->next;
    }
    return NULL; 
}

void insert(Node* h[], int key){
    int hsh = key%10; 
    sortedinsert(&h[hsh], key); 
}
int main(){
    //creating the core hash table which is basically an array of pointers.
    Node* ht[10]; 
    int num;
    cout<<"enter value to be inputted "<<endl; cin>>num;
    insert(ht, num); 

}