//TreeUsingLinkedList
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
struct node{
  int data;
  struct node *left;
  struct node *right;
};
struct node *tree=NULL;
struct node *crtree(struct node *tree)
{
    struct node *ptr,*new_ptr;
    ptr=tree;
    int i=1,val;
    new_ptr= (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data for the node of the tree : ");
    scanf("%d",&val);
    new_ptr->data=val;
    new_ptr->left=NULL;
    new_ptr->right=NULL;
    if (tree==NULL)
    {
        tree=new_ptr;
    }
    else
    {
       while(i!=0 && ptr->data!=val)
       {
       if (val<ptr->data && ptr->left!=NULL)
           ptr=ptr->left;
       else if(val>ptr->data && ptr->right!=NULL)
           ptr=ptr->right;
       else
           i=0;
       }
       if (ptr->data==val)
       {
           printf("\nThis number is already present in the tree.\n");
       }
       else{
         if (val<ptr->data)
             ptr->left=new_ptr;
         else
             ptr->right=new_ptr;
        }
    }
    return tree;
}
void preorder(struct node *tree)
{
    if(tree!=NULL)
    {
         printf(" %d ",tree->data);
         preorder(tree->left);
         preorder(tree->right);
    }
}
void postorder(struct node *tree)
{
    if(tree!=NULL)
    {
         postorder(tree->left);
         postorder(tree->right);
         printf(" %d ",tree->data);
    }
}
void inorder(struct node *tree)
{
    if(tree!=NULL)
    {
         inorder(tree->left);
         printf(" %d ",tree->data);
         inorder(tree->right);
    }
}
struct node *Smallest(struct node *tree)
{
    if( (tree == NULL) || (tree->left == NULL))
            return tree;
    else
            return Smallest(tree ->left);
}
struct node *Largest(struct node *tree)
{
    if( (tree == NULL) || (tree->right == NULL))
             return tree;
    else
             return Largest(tree->right);
}
void delete(struct node *tree,struct node *ptree, int val)
{
  int cou;
    if(tree==NULL)
      printf("\nTree is empty");
    else if(val<tree->data)
    {
       // cou=1;
         delete(tree->left, tree, val);
    }
    else if(val>tree->data)
    {
         delete(tree->right,tree, val);
    }
    else if(tree->left!=NULL && tree->right!=NULL && val==tree->data)
      {
          struct node *temp;
          temp=Largest(tree->left);
          tree->data=temp->data;
          delete(tree->left,tree,temp->data);
      }
    else 
    {
        if(ptree->data<tree->data)
         {
             cou=2;
         }
         else
         {
             cou=1;
         }
        if (val==tree->data)
        {
         struct node *temp;
         temp=tree;
         if(tree->left==NULL && tree->right==NULL)
           tree=NULL;
         else if(tree->left!=NULL)
            tree=tree->left;
         else if(tree->right!=NULL)
            tree=tree->right;
         if(cou==1)
         {
             ptree->left=tree;
         }
         if(cou==2)
         {
             ptree->right=tree;
         }
         free(temp); 
        }
        else
         printf("\nNo such element is present in the tree.");
    }
}
int totalNodes(struct node *tree)
{
  if(tree==NULL)
      return 0;
   else
     return(totalNodes(tree->left) + totalNodes(tree->right) + 1);
}
int totalExternalNodes(struct node *tree)
{
   if(tree==NULL)
      return 0;
   else if((tree->left==NULL) && (tree->right==NULL))
      return 1;
   else
      return (totalExternalNodes(tree->left) + totalExternalNodes(tree->right));
}
int totalInternalNodes(struct node *tree)
{
   if( (tree==NULL) || ((tree->left==NULL) && (tree->right==NULL)))
       return 0;
   else
       return (totalInternalNodes(tree->left) + totalInternalNodes(tree->right) + 1);
}
int Height(struct node *tree)
{
  int leftheight, rightheight;
  if(tree==NULL)
    return -1;
  else
   {
      leftheight = Height(tree->left);
      rightheight = Height(tree->right);
      if(leftheight > rightheight)
          return (leftheight + 1);
       else
           return (rightheight + 1);
}
}
struct node *deleteTree(struct node *tree)
{
    if(tree!=NULL)
    {
          deleteTree(tree->left);
          deleteTree(tree->right);
          free(tree);
}
}
int main()
{
    struct node *mptr;
    int opt,val;
    do
    {
         printf("\n***OPTIONS***\n1. Insert an element\n2. Preorder Traversal\n3. Postorder Traversal\n4. Inorder Traversal\n5. Largest Element in the tree\n6. Smallest Element in the tree\n7. Delete an Element\n8. Total number of nodes in the tree\n9. Total number of external nodes in the tree\n10. Total number of Internal nodes in the tree\n11. Height of the tree\n12. Delete the tree\n13. EXIT\n");
         scanf("%d",&opt);
        switch (opt)
        {
         case 1:
            tree=crtree(tree);
            break;
         case 2:
            if(tree==NULL){
                printf("\nTree is empty");
                break;
            }
            else
            preorder(tree);
            printf("\n");
            break;
         case 3:
            if(tree==NULL){
                printf("\nTree is empty");
                break;
            }
            else
            postorder(tree);
            printf("\n");
            break;
         case 4:
            if(tree==NULL){
                printf("\nTree is empty");
                break;
            }
            else
            inorder(tree);
            printf("\n");
            break;
         case 5:
            if(tree==NULL){
                printf("\nTree is empty");
                break;
            }
            else
            mptr=Largest(tree);
            printf("\nThe Largest element present in the tree is %d\n",mptr->data);
            break;
         case 6:
            if(tree==NULL){
                printf("\nTree is empty");
                break;
            }
            else
            mptr=Smallest(tree);
            printf("\nThe Smallest element present in the tree is %d\n",mptr->data);
            break;
         case 7:
            if(tree==NULL){
                printf("\nTree is empty");
                break;
            }
            else
            printf("\nEnter the value you want to delete: ");
            scanf("%d",&val);
            delete(tree,tree,val);
            break;
         case 8:
            if(tree==NULL){
                printf("\nTree is empty");
                break;
            }
            else
            printf("\nThe total number of nodes present in the tree is %d\n",totalNodes(tree));
            break;
         case 10:
            if(tree==NULL){
                printf("\nTree is empty");
                break;
            }
            else
            printf("\nThe total number of internal nodes present in the tree is %d\n",totalInternalNodes(tree));
            break;
         case 9:
            if(tree==NULL){
                printf("\nTree is empty");
                break;
            }
            else
            printf("\nThe total number of external nodes present in the tree is %d\n",totalExternalNodes(tree));
            break;
         case 11:
            if(tree==NULL){
                printf("\nTree is empty");
                break;
            }
            else
            printf("\nThe height of the tree is %d\n",Height(tree));
            break;
         case 12:
            tree=deleteTree(tree);
            tree=NULL;
            printf("\nTree successfully deleted\n");
            break;
         default:
            printf("\nThank You!!\n");
            break;
        }
    }while(opt!=13);
    return 0;
}