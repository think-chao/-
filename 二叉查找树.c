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
	BSTree *h,*p,*parent;
	p=t;
	if(!(h=(BSTree *)malloc(sizeof(BSTree)))){
		printf("内存分配失败\n");
		exit(0); 
	}
	h->data=key;
	h->left=h->right=NULL;
	while(p){
		parent=p;
		if(key<p->data)
			p=p->left;
		else
			p=p->right;
	}
	if(key<parent->data)
		parent->left=h;
	else
		parent->right=h;
	
}

void Create(BSTree *r,int data[],int n){
	int i;
	r->data=data[0];
	r->left=r->right=NULL;
	for(i=1;i<n;i++){
		Insert(r,data[i]);
	}
}

void LDR(BSTree *r){
	if(r){
		LDR(r->left);
		printf("%d ",r->data);
		LDR(r->right);
	}
}

void Search(BSTree *r,int key){

	if(r->data==key)
		printf("存在!\n");
	else if(r==NULL)
		printf("不存在\n");
	else if(key<r->data)
		Search(r->left,key);
	else
		Search(r->right,key);		
}
void Del(BSTree *r,int key){
	BSTree *p=r,*parent,*p1,*p2;
	int child=0;
	parent=p;
	while(p){
		if(p->data==key){
			printf("找到了\n");
			if(p->left==NULL && p->right==NULL){
				if(child==0)
					parent->left=NULL;
				else
					parent->right=NULL;
			}else if(p->left==NULL){
				if(child==0){
					parent->left=p->right;
				}else
					parent->right=p->right;
				free(p); //释放被删除结点
			}else if(p->right==NULL){
				if(child==0)
					parent->left=p->left;
				else
					parent->right=p->left;
				free(p); //释放被删除结点
			}else{
				p1=p;
				p2=p->right;
				while(p2->left){
					p1=p2;
					p2=p2->left;
				}
				p->data=p2->data;
				p2->left=NULL;
				free(p2);
				
			}
			p=NULL;
		}else if(key<p->data){
			child=0;
			parent=p;
			p=p->left;
		}else{
			child=1;
			parent=p;
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
