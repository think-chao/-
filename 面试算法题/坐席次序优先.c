#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int CreateData(int s[],int n,int min,int max) //����һ��������飬a�������ɵ����ݣ�nΪ����Ԫ�ص����� 
{
    int i,j,flag;
    srand(time(NULL));
    //if((max-min+1)<n) return 0; //���������С��֮��С�ڲ���������������������ݲ��ɹ� 
    for(i=0;i<n;i++)
    {
        s[i]=(max-min+1)*rand()/(RAND_MAX+1)+min;   
    }
    return 1;
}
int main(){
	int stu,seat,min,max,i,j,stu_id=1,flag=0;	
	printf("������һ������ѧ��\n");
	scanf("%d",&stu);
	printf("һ���ж�����ϯ��\n");
	scanf("%d",&seat);
	int *s=(int *)malloc(seat*sizeof(int));
	int hash[100000];
	printf("��ָ����ϯ�Ӵ���������Сֵ\n");
	scanf("%d",&min); 
	printf("��ָ����ϯ�Ӵ����������ֵ\n");
	scanf("%d",&max); 
	printf("���������ϯ�Ӵ�����...\n");
	CreateData(s,seat,min,max);
	printf("������ϯ�ĽӴ�����չʾ:\n");
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
				printf("��ϯ%d�Ӵ�ѧ��%d\n",i,stu_id++);
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
		printf("��ϯ%dһ���Ӵ���%dѧԱ\n",i+1,hash[i]);
	}
} 
