/************************************************************
 * 堆排序的重要一步就是把无序的数组构造成一个堆
 * 堆就是一个完全二叉树，而且对于任意一个非叶子节点，其值要大于左子树和右子树的
*****************************************************************/
#include<stdio.h>
#include<stdlib.h>
//参数说明，s表示的是当前节点
void Heap_Construct(int a[],int s,int n){
    int l,t;
    //2*s+1<n表示的当前节点有左右子节点（从完全二叉树的定义可以得知，如果2*s+1<=n,那么右子节点的标号就为2*s+1）
    //有左右子节点也就说明了是非叶子节点，如果没有右节点的话，那么左子节点肯定就是叶子节点了（因为这是完全二叉树）
    while(2*s+1<n){
        l=2*s+1;
        if(l+1<n){
            if(a[l]>a[l+1])
            l++;
        }
        if(a[s]<a[l]){
            t=a[s];
            a[s]=a[l];
            a[l]=a[s];
            //加入左子节点也是一个根节点，那么就需要重新调整左子节点作为根节点的那一个小堆
            s=l;
        }else
            break;
    }
}

/********************************************************************
 * 堆排序
 * 其主要思想是对于构造的堆，其根节点就是最大值了，我们就把根节点存放到要输出的数组的最后去
 * 然后把堆的最后一个节点和根节点互换位置，这是堆的结果就破坏了，然后又重新把这个被破坏的堆整理成一个
 * 正确的堆，这样又可以很容易的得到这个堆里的最大值，这样不断的重复下去
 * 
 *****************************************************************/
void Head_Sort(int a[],int n){
    int i,j;
    //从第一个非叶子节点开始，构造堆
    for(i=n/2-1;i>=0;i--){
        Heap_Construct(a,i,n);
    }
    for(j=n-1;j>=0;i--){
        j=a[0];
        a[0]=a[j];
        a[j]=j;
        Heap_Construct(a,0,j);
    }
}


/*********************************************
 * 快速排序
 * 快速排序也分为两个部分
 * 首先要实现对一块数组的分割，分割成两部分，其中一部分比另外一部分大或者小
 * 然后对这两部分再进行之前的操作
 * /
*************************************************/

int Div(int a[],int left,int right){
    int base,t;
    base=a[left];
    while(left<right){
        while(left<right && a[right]>=base)
            --right;
        a[left]=a[right];
        while(left<right && a[left]<=base)
            ++left;
        a[right]=a[left];
    }
    a[left]=base;
    return left;
}

void Quick_Sort(int a[],int left,int right){
    int i;
    if(left<right){
        i=Div(a,left,right);
        Quick_Sort(a,left,i-1);
        Quick_Sort(a,i+1,right);
    }
}

/***************************************************************
 * 二叉排序树
 * *************************************************************/

typedef struct bst{
    int data;
    struct bst *left;
    struct bst *right;
}BSTree;

void Insert(BSTree *t,int key){
    BSTree *p,*head,*parent;
    if(p!=((BSTree *)malloc(sizeof(BSTree)))){
        printf("申请内存失败\n");
        exit(0);
    }
    p->data=key;
    p->left=p->right=NULL;          //插入到末尾
    head=t;
    while(head){
        parent=head;
        if(key<head->data)
            head=head->left;
        else
            head=head->right;
    }
    if(key<parent->data)
        parent->left=p;
    else
        parent->right=p;
}

void Creat_BST(BSTree *t,int data[],int n){
    int i;
    t->data=data[0];
    t->left=t->right=NULL;
    for(i=1;i<n;i++)
        Insert(t,data[i]);
}

void BST_LDR(BSTree *t){
    if(t){
        BST_LDR(t->left);
        printf("%d",t->data);
        BST_LDR(t->right);
    }
    return;
}

BSTree *Search(BSTree *t,int key){
    if(!t || t->data==key){
        return t;
    }else if(key>t->data)
        return(Search(t->right,key));
    else{
        return(Search(t->left,key));
    }

}

void Delete(BSTree *t,int key){
    BSTree *p,*parent,*l,*l1;
    int child=0;
    if(!t) return;
    p=t;
    parent=p;
    while(p){
        if(p->data==key){
            //左右子树都为空，代表是叶子节点
            if(!p->left && !p->right){
                if(p==t) free(p);
                    else if(child==0){   //父节点为左子树
                        parent->left=NULL;
                        free(p);
                    }else{
                        parent->right=NULL;
                        free(p);
                }
            }
            //左子树为空，右子树不为空
            else if(!p->left){
                if(child==0)        //表示左子树
                    parent->left=p->right;
                else
                    parent->left=p->left;
                free(p);
            }
            //右子树为空，左子树不为空
            else if(!p->right){
                if(child==0)
                    parent->right=p->right;
                else
                    parent->right=p->left;
                free(p);
            }
            //左右子树都不为空
            else{
                l1=p;
                l=p->right;
                while(l->left){
                    l1=l;
                    l=l->left;
                }
                p->data=l->data;
                l1->left=NULL;
                free(l1);
            }
            p=NULL;
        }else if(key<p->data){
            child=0;        //标记在当前节点的左子树进行查找
            parent=p;
            p=p->left;
        }else{
            child=1;
            parent=p;
            p=p->right;
        }
    }
}


