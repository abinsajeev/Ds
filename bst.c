#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data) {
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->left=newnode->right=NULL;
    return newnode;
}

struct node* insertion(struct node* root, int data) {
    if(root==NULL)
        return createNode(data);
    
    if(data < root->data)
        root->left=insertion(root->left,data);
    else if(data > root->data) 
        root->right=insertion(root->right,data);
    
    return root;
}
int search(struct node* root,int key) {
    if(root== NULL)
        return 0;
    else if(root->data==key)
        return 1;
    if(key<root->data)
        return search(root->left,key);
    else 
        return search(root->right,key);
    
}
void preorder(struct node* root) {
    if(root!=NULL) {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct node* root) {
    if(root!=NULL) {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void postorder(struct node* root) {
    if(root!=NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

struct node* findMin(struct node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

struct node* deletion(struct node* root,int key) {
    struct node* temp;
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deletion(root->left, key);
    else if (key > root->data)
        root->right = deletion(root->right, key);
    else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        } else if (root->left == NULL) {
            temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            temp = root->left;
            free(root);
            return temp;
        } else {
            temp = findMin(root->right);
            root->data = temp->data;
            root->right = deletion(root->right, temp->data);
        }
    }

    return root;
}


void main() {
    struct node* root=NULL;
    int ch,data;
    while(1) {
        printf("\n1. Insertion\n2. Search\n3. Preorder\n4. Inorder\n5. Postorder\n6. Deletion\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch) {
            case 1: 
                printf("Enter the data: ");
                scanf("%d",&data);
                root=insertion(root,data);
                break;
            case 2:
                printf("Enter element to search: ");
                scanf("%d",&data);
                if(search(root,data))
                    printf("Element found in the BST\n");
                else
                    printf("No such element in the BST\n");
                break;
            case 3:
                printf("Preorder Traversal\n");
                preorder(root);
                break;
            case 4:
                printf("Inorder Traversal\n");
                inorder(root);
                break;
            case 5:
                printf("Postorder Traversal\n");
                postorder(root);
                break;
            case 6:
                printf("Enter element to delete: ");
                scanf("%d",&data);
                root=deletion(root,data);
            case 7: 
                printf("Program has stopped");
                exit(0);
                break;
            default: printf("Invalid Input\n");
        }
    }
}