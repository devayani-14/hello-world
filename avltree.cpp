#include <bits/stdc++.h>
using namespace std;
struct Node{//tree part
    int data; Node *lchild; Node *rchild; int height;
}; Node* root = new Node; ///recursive insert
int Nodeheight(struct Node* p){ //to find height of a node.
//cout<<"entered nodehgt"<<endl;
    if(p->lchild && p->rchild){
            if (p->lchild->height < p->rchild->height)
                return p->rchild->height + 1;
            else return  p->lchild->height + 1;
            }
            else if(p->lchild && p->rchild == NULL){
               return p->lchild->height + 1;
            }
            else if(p->lchild ==NULL && p->rchild){
               return p->rchild->height + 1;
            }
            return 0;

    //int hl,hr;
    //if (p != NULL && p->lchild != NULL) hl =p->lchild->height;
    //else hl = 0;
    //if (p != NULL && p->rchild != NULL) hr =p->rchild->height;
    //else hr = 0;
    //int hgt = hl>hr?hl+1:hr+1;
    //cout<<"data "<<p->data<<" hgt "<<hgt<<endl;
    //return hl>hr?hl+1:hr+1; //height of a subtree is the maximum height of the left subtree and the right subtree.
}
int balancefactor(Node* n){
    //cout<<"enetered bf"<<endl;
    if(n->lchild && n->rchild){
                return n->lchild->height - n->rchild->height; 
            }
            else if(n->lchild && n->rchild == NULL){
                return n->lchild->height; 
            }
            else if(n->lchild== NULL && n->rchild ){
                return -n->rchild->height;
            }

    //int hl,hr;if (p != NULL && p->lchild != NULL) hl =p->lchild->height;
    //else hl = 0;
    //if (p != NULL && p->rchild != NULL) hr =p->rchild->height;else hr = 0;
    //cout<<"data "<<p->data<<" bf "<<hl-hr<<endl; return hl-hr; 
}
Node* llrotation(Node* n){
    struct Node *p;
        struct Node *tp;
        p = n;
        tp = p->lchild;

        p->lchild = tp->rchild;
        tp->rchild = p; 
        if (n ==root) root = tp;
        return tp; 
} 
Node* lrrotation(Node* n){
    struct Node *p;
        struct Node *tp;
        p = n;
        tp = p->lchild;

        p->lchild = tp->rchild;
        tp->rchild = p; 
        if (n ==root) root = tp;
        return tp; 
} 
Node* rrrotation(Node* n){
    struct Node *p;
        struct Node *tp;
        p = n;
        tp = p->rchild;

        p->rchild = tp->lchild;
        tp->lchild = p;
        if (p ==root) root = tp;
        return tp; 
} 
Node* rlrotation(Node* n){
    struct Node *p;
        struct Node *tp;
        struct Node *tp2;
        p = n;
        tp = p->rchild;
        tp2 =p->rchild->lchild;

        p -> rchild = tp2->lchild;
        tp ->lchild = tp2->rchild;
        tp2 ->lchild = p;
        tp2->rchild = tp; 
        if (n ==root) root = tp2;
        return tp2; 
} 
Node* rinsert(Node* p,int key){ //inserting recursively when values are given
    if (p==NULL){
        Node* t = new Node; 
        t->data = key; t->lchild = t->rchild = NULL; 
        t->height = 1;p=t;  //starting height from 1 (single node's height is taken as 1 here. can take 0 too)
        return t;
    }
    if (key< p->data) p->lchild = rinsert(p->lchild,key);
    else if (key> p->data) p->rchild = rinsert(p->rchild, key);
    p->height =  Nodeheight(p); //cout<<"p data " <<p->data<<" p- hgt "<<p->height<<" p- bf "<<balancefactor(p)<<endl;
    if (balancefactor(p) == 2 && balancefactor(p->lchild) ==1) llrotation(p);
    else if (balancefactor(p) ==2 && balancefactor(p->lchild) ==-1) lrrotation(p);
    else if (balancefactor(p) == -2 && balancefactor(p->rchild) == -1) rrrotation(p);
    else if (balancefactor(p) == -2 && balancefactor(p->rchild) ==1) rlrotation(p); 
    return p;
}
void itr_insert(Node *p, int key){ Node* tail=new Node; 
    while (p!= NULL){ tail = p;
        if (key<p->data) { p = p->lchild;}
        else {p = p->rchild;} 
    }
    Node *t = new Node; t->data = key; t->lchild =t->rchild=NULL; 
    if (t->data > tail->data) tail->rchild = t;
    else tail->lchild = t;
}
void inorder(Node *p){
    if (p){ 
    inorder(p->lchild); cout<<p->data<<" ";inorder(p->rchild); }
}
int main(){
    root->lchild = root->rchild = NULL;cout<<"root data"; cin>>root->data; root->height=1; 
    rinsert(root,20);
    rinsert(root,30); inorder(root); cout<<endl;
    rinsert(root,25); inorder(root); cout<<endl;
    rinsert(root,28); inorder(root); cout<<endl;
    //rinsert(root,27); 
    //rinsert(root,5);
    //inorder(root); //cout<<root->data<<endl; //cout<<"hgt "<<root->height; 
}
