#include<iostream>
#include<queue>

using namespace std;

struct list{
    char data;
    struct list *left, *right;
};
typedef struct list node;


void level_traverse(node* root)
{
    queue<node*> q;
    node *temp_node;

    if(!root){
        return;
    }
    for(q.push(root); !q.empty() ; q.pop()) {
        temp_node = q.front();
        cout<<temp_node->data<<" ";

        if (temp_node->left) {
            q.push(temp_node->left);
        }
        if (temp_node->right) {
            q.push(temp_node->right);
        }
    }
}

void createBTree(node *root){
    node *left, *right;
    char ch;
    cout<<"\nDoes "<<root->data<<" has any left child ? <y/n> ";
    cin>>ch;
    if(ch=='y'){
        root->left=new node;
        root->left->left=NULL;
        root->left->right=NULL;
        cout<<"Enter left child data : ";
        cin>>root->left->data;
        createBTree(root->left);
    }
    cout<<"\nDoes "<<root->data<<" has any Right child ? <y/n> ";
    cin>>ch;
    if(ch=='y'){
        root->right=new node;
        root->right->left=NULL;
        root->right->right=NULL;
        cout<<"Enter right child data : ";
        cin>>root->right->data;
        createBTree(root->right);
    }

}



int main(){
    node *root;
    root=new node();
    root->right=NULL;
    root->left=NULL;
    cout<<"Input root : ";
    cin>>root->data;
    createBTree(root);
    level_traverse(root);
return 0;
}

