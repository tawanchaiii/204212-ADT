#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int value;
    struct node *left;
    struct node *right;
} node_t;
typedef node_t bst_t;

int find(bst_t *head, int x)
{
    if (head != NULL && head->value == x)
        return 1;
    if (head != NULL && x < head->value)
        return find(head->left, x);
    if (head != NULL && x > head->value)
        return find(head->right, x);
    return 0;
}
bst_t *newNode(int x)
{
    bst_t *node = (bst_t *)malloc(sizeof(bst_t));
    node->value = x;
    node->left = NULL;
    node->right = NULL;
    return node;
}
bst_t *minValueNode(bst_t *node)
{
    bst_t *current = node;

    while (current && current->left != NULL)
        current = current->left;

    return current;
}
bst_t *insert(bst_t *head, int x)
{
    if (head == NULL)
        return newNode(x);
    if (x < head->value)
        head->left = insert(head->left, x);
    else
        head->right = insert(head->right, x);
    return head;
}

bst_t *delete(bst_t *root, int x)
{
    if (root == NULL)
        return root;
    if (x < root->value)
        root->left = delete (root->left, x);
    else if (x > root->value)
        root->right = delete (root->right, x);
    else
    {
        if (root->left == NULL)
        {
            bst_t *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            bst_t *temp = root->left;
            free(root);
            return temp;
        }
        struct node *temp = minValueNode(root->right);
        root->value = temp->value;
        root->right = delete (root->right, temp->value);
    }
    return root;
}

int find_min(bst_t *head)
{
    while (head->left != NULL)
        head = head->left;
    return head->value;
}
int find_max(bst_t *head)
{
    while (head->right != NULL)
        head = head->right;
    return head->value;
}
void inorder(bst_t *t)
{
    if (t != NULL)
    {
        inorder(t->left);
        printf("%d ", t->value);
        inorder(t->right);
    }
}
int main(void)
{
    bst_t *t = NULL;
    int n, i;
    int command, data;

    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &command);
        switch (command)
        {
        case 1:
            scanf("%d", &data);
            t = insert(t, data);
            break;
        case 2:
            scanf("%d", &data);
            t = delete (t, data);
            break;
        case 3:
            scanf("%d", &data);
            printf("%d\n", find(t, data));
            break;
        case 4:
            printf("%d\n", find_min(t));
            break;
        case 5:
            printf("%d\n", find_max(t));
            break;
        }
    }
    return 0;
}