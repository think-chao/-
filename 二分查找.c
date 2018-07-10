#include<stdio.h>
#include<stdlib.h>

typedef struct Seq{
	int key;
}SeqList;

int BinarySearch(SeqList *s,int n,int data){
	int start=0,end=n-1;
	while(start<=end){
		if(s[start].key==data)
			return start;
		if(s[end].key==data)
			return end;
		int mid=(start+end)/2;
		if(s[mid].key==data)
			return mid;
		else if(data<s[mid].key)
			end=mid-1;
		else
			start=mid+1;
	}
	return -1;
		
}
