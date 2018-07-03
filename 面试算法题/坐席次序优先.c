#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int CreateData(int s[],int n,int min,int max) //创建一个随机数组，a保存生成的数据，n为数组元素的数量 
{
    int i,j,flag;
    srand(time(NULL));
    //if((max-min+1)<n) return 0; //最大数与最小数之差小于产生数组的数量，生成数据不成功 
    for(i=0;i<n;i++)
    {
        s[i]=(max-min+1)*rand()/(RAND_MAX+1)+min;   
    }
    return 1;
}
int main(){
	int stu,seat,min,max,i,j,stu_id=1,flag=0;	
	printf("请输入一共多少学生\n");
	scanf("%d",&stu);
	printf("一共有多少坐席？\n");
	scanf("%d",&seat);
	int *s=(int *)malloc(seat*sizeof(int));
	int hash[100000];
	printf("请指定坐席接待能力的最小值\n");
	scanf("%d",&min); 
	printf("请指定坐席接待能力的最大值\n");
	scanf("%d",&max); 
	printf("随机分配坐席接待能力...\n");
	CreateData(s,seat,min,max);
	printf("各个坐席的接待能力展示:\n");
	for(i=0;i<seat;i++){
		hash[i]=0;
		printf("%d ",*(s+i));
		if((i+1)%20==0)
			printf("\n");
	}
	printf("\n");
	i=1;
	while(stu_id<=stu){
		for(j=0;j<*(s+i-1);j++){
			if(stu_id<=stu)
			{
				printf("坐席%d接待学生%d\n",i,stu_id++);
				hash[i-1]=hash[i-1]+1;
			}
			else
				flag=1;
		}
		if(flag==1) break;
		if((i+1)%seat!=0)
			i=(i+1)%seat;
		else
			i=i+1;
	}
	for(i=0;i<seat;i++){
		printf("坐席%d一共接待了%d学员\n",i+1,hash[i]);
	}
} 
