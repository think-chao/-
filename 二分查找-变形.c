#include<stdio.h>
#include<stdlib.h>

//���ҵ�һ����key��ȵ�Ԫ��

int BinarySearch(int data[],int n,int key){
	int left=0,right=n-1;
	while(left<=right){
		int mid=(left+right)/2;
		if(key<=data[mid])
			right=mid-1;
		else
			left=mid+1;
	}
	if(left<n && data[left]==key)
		return left;
	return -1;
} 

//�������һ����key��ȵ�Ԫ��
int BinarySearch(int data[],int n,int key){
	int left=0,right=n-1;
	while(left<=right){
		mid=(left+right)/2;
		if(key>=data[mid])
			left=mid+1;
		else
			right=mid-1;
	}
	if(right<n && data[right]==key)
		return right
	return -1;
} 

//�������һ��С�ڻ����key����
int BinarySearch(int data[],int n,int key){
	int left=0,right=n-1;
	while(left<=right){
		mid=(left+right)/2
		if(data[mid]>key)
			right=mid-1;
		else
			left=mid+1;
	} 
	return right;

}

//�������һ��С��key����
int BinarySearch(int data[],int n,int key){
	int left=0,right=n-1;
	while(left<=right){
		mid=(left+right)/2
		if(data[mid]>=key)
			right=mid-1;
		else
			left=mid+1;
	} 
	return right;
}

//���ҵ�һ�����ڻ����key���� 
int BinarySearch(int data[],int n,int key){
	int left=0,right=n-1;
	while(left<=right){
		mid=(left+right)/2
		if(data[mid]>=key)
			right=mid-1;
		else
			left=mid+1;
	} 
	return left;
}

//���ҵ�һ������key���� 
int BinarySearch(int data[],int n,int key){
	int left=0,right=n-1;
	while(left<=right){
		mid=(left+right)/2
		if(data[mid]>key)
			right=mid-1;
		else
			left=mid+1;
	} 
	return left;

}
 

 

