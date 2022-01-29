#include <bits/stdc++.h>
using namespace std;
struct Node{//tree part
    int data; Node *left; Node *right; int height;
}; Node* root = new Node; 
int calheight(struct Node *p){

            if(p->left && p->right){
            if (p->left->height < p->right->height)
                return p->right->height + 1;
            else return  p->left->height + 1;
            }
            else if(p->left && p->right == NULL){
               return p->left->height + 1;
            }
            else if(p->left ==NULL && p->right){
               return p->right->height + 1;
            }
            return 0;

}
int bf(struct Node* n){
    if(n->left && n->right){
                return n->left->height - n->right->height; 
            }
            else if(n->left && n->right == NULL){
                return n->left->height; 
            }
            else if(n->left== NULL && n->right ){
                return -n->right->height;
            }
}
struct Node * llrotation(struct Node *n){
        struct Node *p;
        struct Node *tp;
        p = n;
        tp = p->left;

        p->left = tp->right;
        tp->right = p;
        if (root ==n) root=tp;
        return tp; 
}
struct Node * rrrotation(struct Node *n){
        struct Node *p;
        struct Node *tp;
        p = n;
        tp = p->right;

        p->right = tp->left;
        tp->left = p;
        if (root ==n) root=tp;
        return tp; 
}
struct Node * rlrotation(struct Node *n){
        struct Node *p;
        struct Node *tp;
        struct Node *tp2;
        p = n;
        tp = p->right;
        tp2 =p->right->left;

        p -> right = tp2->left;
        tp ->left = tp2->right;
        tp2 ->left = p;
        tp2->right = tp; 
        if (root ==n) root=tp;
        return tp2; 
}
struct Node * lrrotation(struct Node *n){
        struct Node *p;
        struct Node *tp;
        struct Node *tp2;
        p = n;
        tp = p->left;
        tp2 =p->left->right;

        p -> left = tp2->right;
        tp ->right = tp2->left;
        tp2 ->right = p;
        tp2->left = tp; 
        if (root ==n) root=tp2;
        return tp2; 
}
struct Node* insert(struct Node *r,int data){
    if(r==NULL){
            struct Node *n;
            n = new struct Node;
            n->data = data;
            //r = n;
            n->left = n->right = NULL;
            n->height = 1; 
            return n;             
        }
        else{
            if(data < r->data)
            r->left = insert(r->left,data);
            else
            r->right = insert(r->right,data);
        }
        r->height = calheight(r);

        if(bf(r)==2 && bf(r->left)==1){
            r = llrotation(r);
        }
        else if(bf(r)==-2 && bf(r->right)==-1){
            r = rrrotation(r);
        }
        else if(bf(r)==-2 && bf(r->right)==1){
            r = rlrotation(r);
        }
        else if(bf(r)==2 && bf(r->left)==-1){
            r = lrrotation(r);
        }        

        return r;
}
void inorder(Node *p){
    if (p){ 
    inorder(p->left); cout<<p->data<<" ";inorder(p->right); }
}
int main(){
    root->left = root->right = NULL;cout<<"root data"; cin>>root->data; root->height=1; 
    insert(root,20);
    insert(root,30); //inorder(root); cout<<endl;
    insert(root,25); //inorder(root); cout<<endl;
    insert(root,28); //inorder(root); cout<<endl;
    insert(root,27); 
    insert(root,5);
    inorder(root); //cout<<root->data<<endl; //cout<<"hgt "<<root->height; 
}
