#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*
	这个函数就是根据指定范围给每个坐席分配一定的接待能力（即接待人数） 
*/ 
int CreateData(int s[],int s_count[],int count[],int n,int min,int max) //创建一个随机数组，a保存生成的数据，n为数组元素的数量 
{
    int i,j,flag;
    srand(time(NULL));
    //if((max-min+1)<n) return 0; //最大数与最小数之差小于产生数组的数量，生成数据不成功 
    for(i=0;i<n;i++)
    {
        s[i]=(max-min+1)*rand()/(RAND_MAX+1)+min;   
        s_count[i]=0;
        count[i]=0;
    }
    return 1;
}

// 获取所有坐席里接待能力最强的那一个坐席的目的是：
// 当所有坐席都完成了一轮接待，但是还有学生还没有全部分配完毕，所以根据坐席数是否达到max来判断是否完成第一轮分配 
int Max(int s[],int n){
	int max=-1,i;
	for(i=0;i<n;i++){
		if(s[i]>max)
			max=s[i];
	}
	return max;
}

/*
	这个函数作用就是为坐席分配学生，
	需要注意的是，当完成第一轮分配非时候，临时数组s_count需要全部置0 
*/ 
void Serve(int i,int s[],int s_count[],int count[],int *stu_id,int n){
	int j;
	if(*(s_count+i)==Max(s,n)){
		printf("坐席%d接待学生%d\n",i+1,*stu_id);
		*stu_id=*stu_id+1;
		*(count+i)=*(count+i)+1;

		for(j=0;j<n;j++){
			s_count[j]=0;
		}
		return;
	} 
	if((*(s_count+i)+1)<=*(s+i)){
		printf("坐席%d接待学生%d\n",i+1,*stu_id);
		*stu_id=*stu_id+1;
		*(s_count+i)=*(s_count+i)+1;
		*(count+i)=*(count+i)+1;
	}else{
		return;
	}		
} 

/*
参数说明: stu是学生总人数，seat是总的坐席数，min和max分别对应了每个坐席接待能力的最小最大值，然后坐席的接待能力在这个范围里取
		  stu_id用来标记学生的序号
		  s_count是一个中间数组
		  count数组记录了最终每个坐席所接待了的学生人数的总和 
*/
int main(){
	int stu,seat,min,max,i,j,stu_id=1,flag=0;	
	printf("请输入一共多少学生\n");
	scanf("%d",&stu);
	printf("一共有多少坐席？\n");
	scanf("%d",&seat);
	int *s=(int *)malloc(seat*sizeof(int));
	int *s_count=(int *)malloc(seat*sizeof(int));
	int *count=(int *)malloc(seat*sizeof(int));
	printf("请指定坐席接待能力的最小值\n");
	scanf("%d",&min); 
	printf("请指定坐席接待能力的最大值\n");
	scanf("%d",&max); 
	printf("随机分配坐席接待能力...\n");
	CreateData(s,s_count,count,seat,min,max);
	printf("各个坐席的接待能力比例:\n");
		for(i=0;i<seat;i++){
		//hash[i]=0;
		printf("%d ",*(s+i));
		if((i+1)%20==0)
			printf("\n");
	}
	printf("\n");

	while(stu_id<=stu){
		for(i=0;i<seat;i++){
			if(stu_id>stu)
				break;
			Serve(i,s,s_count,count,&stu_id,seat);
		}
	}
	printf("统计各个坐席接待了多少人数\n");
	for(i=0;i<seat;i++){
		printf("坐席%d一共接待了%d名学生\n",i+1,*(count+i));
	}
	
}



