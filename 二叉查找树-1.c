#include<stdio.h>
#include<stdlib.h>
#define ARRAYLEN 10
int source[]={54,90,6,69,12,37,92,28,65,83};
typedef struct bst{
	int data;
	struct bst *left;
	struct bst *right;
}BSTree;


void Insert(BSTree *t,int key){
	BSTree *p,*h,*parent;
	if(!(p=(BSTree *)malloc(sizeof(BSTree)))){
		printf("内存分配失败\n");
		exit(0);
	}
	p->data=key;
	p->left=p->right=NULL;
	h=t;
	while(h){
		if(key<h->data){
			parent=h;
			h=h->left;
		}else{
			parent=h;
			h=h->right;
		}
	}
	if(key<parent->data)
		parent->left=p;
	else
		parent->right=p;
	
}

void LDR(BSTree *r){
	if(r){
		LDR(r->left);
		printf("%d ",r->data);
		LDR(r->right);
	}
}
void Create(BSTree *r,int data[],int n){
	r->data=data[0];
	r->left=r->right=NULL;
	int i;
	for(i=1;i<n;i++)
		Insert(r,data[i]);
}

void Search(BSTree *r,int key){
	if(r==NULL || r->data==key)
		printf("存在\n");
	else if(key<r->data)
		Search(r->left,key);
	else
		Search(r->right,key);
}

void Del(BSTree *r,int key){
	BSTree *p,*parent,*h,*p1,*p2;
	int child=0;
	p=r;
	while(p){
		if(p->data==key){
			if(p->left==NULL && p->right==NULL){
				if(p==r)
					free(p);
				else if(child==0)
					parent->left=NULL;
				else
					parent->right=NULL;
				free(p);		
			}
			else if(p->left==NULL){
				if(child==0)
					parent->left=p->right;
				else
					parent->right=p->right; 
				free(p);
			}else if(p->right==NULL){
				if(child==0)
					parent->left=p->left;
				else
					parent->right=p->left;
				free(p);
			}else{
				p1=p;//p1作为p2的父节点
				p2->right;
				while(p2->left){
					p1=p2;
					p2=p2->left;
				} 
				p->data=p2->data;
				p1->left=NULL;
				free(p1);
				
			}		
			p=NULL;	
		}else if(key<p->data){
			parent=p;
			child=0;
			p=p->left;
		}else{
			parent=p;
			child=1;
			p=p->right;
		}
	}
}


int main(){
	BSTree bst;
	int i,s,d;
	printf("排序之前的数据: ");
	for(i=0;i<ARRAYLEN;i++)
		printf("%d ",source[i]);
	printf("创建二叉排序树\n");
	Create(&bst,source,ARRAYLEN);
	printf("中序遍历二叉排序树:\n");
	LDR(&bst);
	printf("你要查找的数:\n");
	scanf("%d",&s);
	Search(&bst,s); 
	printf("你要删除的数:\n");
	scanf("%d",&d);
	Del(&bst,d);
	printf("中序遍历二叉排序树:\n");
	LDR(&bst);
}
