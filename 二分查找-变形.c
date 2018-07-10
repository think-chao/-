#include<stdio.h>
#include<stdlib.h>

//查找第一个与key相等的元素

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

//查找最后一个与key相等的元素
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

//查找最后一个小于或等于key的数
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

//查找最后一个小于key的数
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

//查找第一个大于或等于key的数 
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

//查找第一个大于key的数 
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
 

 

