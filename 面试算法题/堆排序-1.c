#include<stdio.h>
#include<stdlib.h>

HeapConstruct(int a[],int s,int n){
	int left,t;
	while(2*s+1<n){
		left=2*s+1;
		if(left+1<n && a[left]<a[left+1])
			left++;
		if(a[s]<a[left]){
			t=a[s];
			a[s]=a[left];
			a[left]=t;
			s=left;
		}else
			break;
	}
}
void HeapSort(int a[],int n){
	int i,t;
	//���ȹ���� 
	for(i=n/2-1;i>=0;i--)
		HeapConstruct(a,i,n);
	//���ݶѵ��ص㣺���һ���ڵ�����С�ģ�����ÿ��Ҫ�����һ���ڵ����
	for(i=n-1;i>=0;i--){
		//������һ��Ԫ�غ����һ��Ԫ�� �������ѵĽṹ�϶����ƻ��� 
		t=a[0];
		a[0]=a[i];
		a[i]=t;
		HeapConstruct(a,0,i);
	}	
}

int main(){
    int a[10]={3,5,6,7,2,1,9,0,4,8};
    int t[10];
    int n=10;
    HeapSort(a,n);
    for(n=0;n<10;n++)
        printf("%d",a[n]);
}
