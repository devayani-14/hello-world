#include <bits/stdc++.h>
using namespace std; 
//HEAPIFY: maintains the heap property by reordering the heap. function not written for it yet. 
void insert_maxheap(int ar[], int pos){
    int temp = ar[pos]; 
    int i=pos; 
    while (i>1 && temp>ar[i/2]){
        ar[i]=ar[i/2]; 
        i=i/2; 
    }
    ar[i]=temp; 
}
void create(int num, int ar[]){ 
    cout<<"enter elements "<<endl; 
    for (int i=1;i<num+1;i++){
        cin>>ar[i]; 
        insert_maxheap(ar,i) ;
    }
}
void swap(int *a, int*b){
    //cout<<"swapping "<<*a<<" "<<*b<<endl; 
    int temp = *a; *a = *b; *b = temp; 
}
void del(int n, int ar[]){
    int i=1; int temp = ar[i]; 
    ar[1]=ar[n-1];  ar[n-1]=temp; n = n-1; //cout<<"n -"<<n<<endl; 
    while (2*i<n-1){ //condition correct but check why its correct
        if (ar[2*i] > ar[2*i +1] ) {
            swap(&ar[2*i], &ar[i]); i = i*2; //cout<<"i= "<<i<<endl; 
        }
        else{
            swap(&ar[2*i +1], &ar[i]); i = i*2 +1;
        }
    }
}
void heapsort(int n, int ar[]){
    if (n<0) return; 
    del(n, ar); 
    heapsort(n-1, ar); 
    swap(&ar[0], &ar[1]); 
}
void display(int num, int ar[]){
    for (int i=1;i<num+1;i++) cout<<ar[i]<<" "; cout<<endl; 
}
int main(){
    int n; cout<<"enter number of elements "; cin>>n; int ar[n+1]; 
    create(n,ar);  heapsort(n+1, ar); 
    display(n,ar); 
}