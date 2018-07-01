#include<stdio.h>
#include<stdlib.h>

typedef struct bst{
    int data;
    struct bst *left;
    struct bst *right;
}BSTree;

void Insert(BSTree *t,int key){
    BSTree *p;
    if(!p=((BSTree *)malloc(sizeof(BSTree))))
        printf("申请内存失败\n");
    p->data=key;
    p->left=p->right=NULL;
    head=t;
    while(head){
        parent=head;
        if(key<head->data)
            head=head->left;
        else
            head=head->right;
    }
    if(key<parent->data)
        parent->left=head;
    else
        parent->right=head;
}

//中序遍历
void LDR(BSTree *t){
    if(bt){
        LDR(t->left);
        printf("%d",t->data);
        LDR(t->right);
    }
    return;
}

void construct(BSTree *t,int data,int n){
    t->data=data[0];
    t->left=t->right=NULL;
    for(i=1;i<n;i++){
        Insert(t,data[i]);
    }
}

BSTree *Search(BSTree *t,int key){
    if(!t || t->data==key)  return t;
    else if(key<t->data)    return (Search(t->left,key));
    else return (Search(t->right,key));
}

/****************************************************
 * 删除操作首先需要找到关键字
 * 然后根据关键字所在的位置更改二叉树的结构
 * 
 * 1. 如果关键字所在位置没有左右子节点，也就是说是叶子节点
 *    那么就直接删除。在删除的时候需要判断这个节点是其父节点的左子树（parent->left=NULL）还是右子树(parent->right=NULL)
 * 2. 如果关键字所在位置只有右子树，没有左子树，这个也很容易，就直接把其右子树提上来就可以了
 *    在这之前需要判断关键字所在位置是其父节点的左子树还是右子树
 * 3. 关键字所在位置只有左子树，没有右子树
 *    同上面
 * 4. 关键字所在位置左右子树都有
 *    这种情况的重点就是将关键字所在的位置替换为关键字的右子树里面的最小值
 * **************************************************/
void Delet(BSTree *t,int key){
    BSTree *p,*parent;
    p=t;
    while(p){
        if(p->data==key){
            //没有左右子节点
            if(!p->left && !p->right){
                if(p==t) free(p);
                else if(p=parent->left){
                    parent->left=NULL;
                    free(p);
                }else{
                    parent->right=NULL;
                    free(p);
                }
            }
            // 只有右子树
            else if(!p->left){
                if(parent->left=p)
                    parent->left=p->right;
                else    
                    parent->right=p->right;
                free(p);
            }
            //只有左子树
            else if(!p->right){
                if(parent->left=p)
                    parent->left=p->left;
                else    
                    parent->right=p->left;
                free(p);
            }
            //左右子树都有
            else{
                BSTree *s,*sp;
                sp=p;
                s=p->right;
                while(s->left){
                    sp=s;
                    s=s->left;
                }
                p->data=s->data;
                sp->left=NULL;
                free(sp);
            }

        }else if(key<p->data){
            parent=p;
            p=p->left;
        }else{
            parent=p;
            p=p->right;
        }
    }
}