#include <stdio.h> 
#include <stdlib.h> 
#define QUEUE_MAXSIZE 50

typedef char DATA;   //定义元素数据类型
typedef struct  ChainTree{
	DATA data;
	struct ChainTree *left;
	struct ChainTree *right;
}ChainBinTree;

int BinTree_Dep(ChainBinTree *bt){
	int dep1,dep2;
	if(bt==NULL){
		return 0;
	}else{
		dep1=BinTree_Dep(bt->left);
		dep2=BinTree_Dep(bt->right);
		if(dep1>dep2){
			return dep1+1;
		}else{
			return dep2+1;
		}
	}
}

//前序--根左右
//中序--左根右
//后序--左右根
void LDR(ChainBinTree *bt,void (*oper)(ChainBinTree *p)){
	if(bt){
		LDR(bt->left,oper);
		oper(bt);
		LDR(bt->right,oper);
	}
	
}


void BinTree_Level(ChainBinTree *bt,void (*oper)(ChainBinTree *p)){
	ChainBinTree *p;
	ChainBinTree *q[QUEUE_MAXSIZE];
	int head=tail=0;
	if(bt){
		tail=(tail+1)%QUEUE_MAXSIZE;
		q[tail]=bt;
	}
	while(head!=tail){
		head=(head+1)%QUEUE_MAXSIZE;
		p=q[head];
		oper(q);
		if(p>left!=NULL){
			tail=(tail+1)%QUEUE_MAXSIZE;
			q[tail]=p->left;
		}
		if(p->right!=NULL){
			tail=(tail+1)%QUEUE_MAXSIZE;
			q[tail]=p->right;
		}
		
	}
	return;
} 
