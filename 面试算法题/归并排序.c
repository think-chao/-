#include<stdio.h>
#include<stdlib.h>

//�鲢�����˼�룺
//�����˵��͵ķ��β��ԣ��Ȱ�һ���������飬���϶԰�ֳɸ�С�����飬ֱ������Ԫ��ֻ��һ����ʱ��
//��Ϊ��ʱ���������д�С��Ϊ1����ô���������ж��������
//�εĲ������ǣ�
//���ϰ�����������кϲ��ɸ���������У�֪�����д�С��ԭ����һ�� 

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
