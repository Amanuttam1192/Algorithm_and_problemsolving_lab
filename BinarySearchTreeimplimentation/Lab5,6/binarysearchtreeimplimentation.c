#include<stdio.h>
#include<stdlib.h>

struct TreeNode
{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* makeEmpty(struct TreeNode* root)
{
    if(root != NULL)
    {
        makeEmpty(root->left);
        makeEmpty(root->right);
        free(root);
    }
    return NULL;
}

struct TreeNode* insert(struct TreeNode* root, int x)
{
    if(root == NULL)
    {
        root = malloc(sizeof(struct TreeNode));
        root->data = x;
        root->left = root->right = NULL;
    }
    else if(x < root->data)
        root->left = insert(root->left, x);
    else if(x > root->data)
        root->right = insert(root->right, x);
    return root;
}

struct TreeNode* findMin(struct TreeNode* root)
{
    if(root == NULL)
    	return NULL;
    else if(root->left == NULL)
    	return root;
    else
    	return findMin(root->left);
}

struct TreeNode* findMax(struct TreeNode* root)
{
    if(root == NULL)
    	return NULL;
    else if(root->right == NULL)
    	return root;
    else
    	return findMax(root->right);
}

struct TreeNode* find(struct TreeNode* root, int x)
{
    if(root == NULL)
        return NULL;
    else if(x < root->data)
        return find(root->left, x);
    else if(x > root->data)
        return find(root->right, x);
    else
        return root;
}

int findHeight(struct TreeNode* root)
{
    int lefth, righth;
    if(root == NULL)
        return -1;
    lefth = findHeight(root->left);
    righth = findHeight(root->right);
    return (lefth > righth ? lefth : righth)+1;
}

struct TreeNode* delete(struct TreeNode* root, int x)
{
    struct TreeNode* temp;
    if(root == NULL)
        return NULL;
    else if(x < root->data)
        root->left = delete(root->left, x);
    else if(x > root->data)
        root->right = delete(root->right, x);
    else if(root->left && root->right)
    {
        temp = findMin(root->right);
        root->data = temp->data;
        root->right = delete(root->right, root->data);
    }
    else
    {
        temp = root;
        if(root->left == NULL)
            root = root->right;
        else if(root->right == NULL)
            root = root->left;
        free(temp);
    }
    return root;
}

void inorder(struct TreeNode* root)
{
    if(root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main()
{
    struct TreeNode *root;
    struct TreeNode *temp;
    root = NULL;
    root = insert(root, 15);
    root = insert(root, 10);
    root = insert(root, 25);
    root = insert(root, 7);
    printf("Height: %d\n", findHeight(root));
    root = insert(root, 13);
    root = insert(root, 18);
    root = insert(root, 30);
    printf("Height: %d\n", findHeight(root));
    root = insert(root, 3);
    root = insert(root, 8);
    root = insert(root, 16);
    printf("Height: %d\n", findHeight(root));
    root = insert(root, 22);
    root = insert(root, 35);
    inorder(root); printf("\n");
    temp = findMax(root);
    printf("Max Element: %d\n", temp->data);
    temp = findMin(root);
    printf("Min Element: %d\n", temp->data);
    root = delete(root, 8);
    root = delete(root, 16);
    inorder(root); printf("\n");
    root = delete(root, 18);
    inorder(root); printf("\n");
    root = delete(root, 10);
    inorder(root); printf("\n");
    root = delete(root, 35);
    inorder(root); printf("\n");
    root = makeEmpty(root);
    return 0;
}

