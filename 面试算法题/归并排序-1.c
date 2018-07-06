#include<stdlib.h>

void Merge(int a[],int t[],int start,int mid;int end){
	int i=start,j=mid+1,k=start;
	while(i!=mid+1 && j!=end+1){
		if(a[i]>a[j]){
			t[k++]=a[j++];
		}else{
			t[k++]=a[i++];
		}
	}
	while(i!=mid+1)
		t[k++]=a[i++];
	while(j!=end+1)
		t[k++]=a[j++];
	for(i=0;i<end;i++){
		a[i]=t[i];
	}
}

void MergeSort(int a[],int t[],int start,int end){
	int mid;
	if(start<end){
		mid=(start+end)/2;
		MergeSort(a,t,start,mid);
		MergeSort(a,t,mid+1,end);
		Merge();
	}
}

int main(){
    int a[10]={3,5,6,7,2,1,9,0,4,8};
    int t[10];
    int n;
    MergeSort(a,t,0,9);
    for(n=0;n<10;n++)
        printf("%d",a[n]);
}
