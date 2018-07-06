
#include<stdio.h>
#include<stdlib.h>

void HeapConstruct(int a[],int s,int n){
	int l,t;
	while(2*s+1<n){
		l=2*s+1;
		if(l+1<n && a[l]<a[l+1])
			l++;
		if(a[s]<a[j]){
			t=a[s];
			a[s]=a[l];
			a[l]=t;
			s=l;
		}else
			break;
	}
}
void HeapSort(int a[],int n){
	int i,t;
	for(i=n/2-1;i>=0;i--)
		HeapConstruct(a,i,n);
	for(i=n-1;i>=0;i--){
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
