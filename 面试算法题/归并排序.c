#include<stdio.h>
#include<stdlib.h>

//归并排序的思想：
//采用了典型的分治策略，先把一串长的数组，不断对半分成更小的数组，直到数组元素只有一个的时候
//因为此时各个子序列大小都为1，那么所有子序列都是有序的
//治的操作就是：
//不断把有序的子序列合并成更大的子序列，知道序列大小与原数组一致 

void Merge(int a[],int t[],int start,int mid,int end){
	int i=start,j=mid+1,k=start;
	while(i!=mid+1 && j!=end+1){
		if(a[i]<a[j]) t[k++]=a[i++];
		else		  t[k++]=a[j++];
	}
	while(i!=mid+1) t[k++]=a[i++];
	while(j!=end+1) t[k++]=a[j++];
	for(i=0;i<=end;i++){
		a[i++]=t[i++];
	}
	
}
void MergeSort(int a[],int t,int start,int end){
	int mid;
	if(start<end){
		mid=(start+end)/2;
		MergeSort(a,t,start,mid);
		MergeSort(a,t,mid+1,end);
		Merge(a,t,start,mid,end);
	}
} 

void main(){
    int a[10]={3,5,6,7,2,1,9,0,4,8};
    int t[10],j;
    MergeSort(a,t,0,9);
    for(j=0;j<10;j++)
        printf("%d",a[j]);
}
