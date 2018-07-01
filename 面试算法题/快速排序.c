#include<stdio.h>
#include<stdlib.h>


int Div(int a[],int left,int right){
	int base;
	base=a[left];
	while(left<right){
		while(left<right && a[right]>base)
			--right;
		a[left]=a[right];
		while(left<right && a[left]<base)
			++left;
		a[right]=a[left];
	}
	a[left]=base;
	return left;
}

void QuickSort(int a[],int left,int right){
	
	int i;
	if(left<right){
		i=Div(a,left,right);
		QuickSort(a,left,i-1);
		QuickSort(a,i+1,right);
	}
} 


int main(){
    int a[10]={3,5,6,7,2,1,9,0,4,8};
    int n;
    QuickSort(a,0,9);
    for(n=0;n<10;n++)
        printf("%d",a[n]);
}
