#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*
	����������Ǹ���ָ����Χ��ÿ����ϯ����һ���ĽӴ����������Ӵ������� 
*/ 
int CreateData(int s[],int s_count[],int count[],int n,int min,int max) //����һ��������飬a�������ɵ����ݣ�nΪ����Ԫ�ص����� 
{
    int i,j,flag;
    srand(time(NULL));
    //if((max-min+1)<n) return 0; //���������С��֮��С�ڲ���������������������ݲ��ɹ� 
    for(i=0;i<n;i++)
    {
        s[i]=(max-min+1)*rand()/(RAND_MAX+1)+min;   
        s_count[i]=0;
        count[i]=0;
    }
    return 1;
}

// ��ȡ������ϯ��Ӵ�������ǿ����һ����ϯ��Ŀ���ǣ�
// ��������ϯ�������һ�ֽӴ������ǻ���ѧ����û��ȫ��������ϣ����Ը�����ϯ���Ƿ�ﵽmax���ж��Ƿ���ɵ�һ�ַ��� 
int Max(int s[],int n){
	int max=-1,i;
	for(i=0;i<n;i++){
		if(s[i]>max)
			max=s[i];
	}
	return max;
}

/*
	����������þ���Ϊ��ϯ����ѧ����
	��Ҫע����ǣ�����ɵ�һ�ַ����ʱ����ʱ����s_count��Ҫȫ����0 
*/ 
void Serve(int i,int s[],int s_count[],int count[],int *stu_id,int n){
	int j;
	if(*(s_count+i)==Max(s,n)){
		printf("��ϯ%d�Ӵ�ѧ��%d\n",i+1,*stu_id);
		*stu_id=*stu_id+1;
		*(count+i)=*(count+i)+1;

		for(j=0;j<n;j++){
			s_count[j]=0;
		}
		return;
	} 
	if((*(s_count+i)+1)<=*(s+i)){
		printf("��ϯ%d�Ӵ�ѧ��%d\n",i+1,*stu_id);
		*stu_id=*stu_id+1;
		*(s_count+i)=*(s_count+i)+1;
		*(count+i)=*(count+i)+1;
	}else{
		return;
	}		
} 

/*
����˵��: stu��ѧ����������seat���ܵ���ϯ����min��max�ֱ��Ӧ��ÿ����ϯ�Ӵ���������С���ֵ��Ȼ����ϯ�ĽӴ������������Χ��ȡ
		  stu_id�������ѧ�������
		  s_count��һ���м�����
		  count�����¼������ÿ����ϯ���Ӵ��˵�ѧ���������ܺ� 
*/
int main(){
	int stu,seat,min,max,i,j,stu_id=1,flag=0;	
	printf("������һ������ѧ��\n");
	scanf("%d",&stu);
	printf("һ���ж�����ϯ��\n");
	scanf("%d",&seat);
	int *s=(int *)malloc(seat*sizeof(int));
	int *s_count=(int *)malloc(seat*sizeof(int));
	int *count=(int *)malloc(seat*sizeof(int));
	printf("��ָ����ϯ�Ӵ���������Сֵ\n");
	scanf("%d",&min); 
	printf("��ָ����ϯ�Ӵ����������ֵ\n");
	scanf("%d",&max); 
	printf("���������ϯ�Ӵ�����...\n");
	CreateData(s,s_count,count,seat,min,max);
	printf("������ϯ�ĽӴ���������:\n");
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
	printf("ͳ�Ƹ�����ϯ�Ӵ��˶�������\n");
	for(i=0;i<seat;i++){
		printf("��ϯ%dһ���Ӵ���%d��ѧ��\n",i+1,*(count+i));
	}
	
}



