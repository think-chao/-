#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define MAX 100
#define max(x,y) (x>y?x:y)
#define min(x,y) (x>y?y:x)
char tmp[MAX<<1];
int Len[MAX<<1];

char *CreateData(){
	char c;
	int i=0;
	char *res=(char *)malloc(MAX*sizeof(char));
	printf("输入字符串:\n");
//	do{
//		scanf("%c",&res[i]);
//		i++;
//	}while(res[i-1]!='0');
//	res[i-1]='\0';
	scanf("%s",res);
	for(i=0;i<strlen(res);i++)
		printf("%c ",res[i]); 
	printf("\n------------------创建数据完成---------------------\n"); 
	return res;
}

/*
返回补全后数组的长度 
*/
char *Transfer(char *s){
	int len=strlen(s),i;
	tmp[0]='@';
	for(i=1;i<=2*len;i+=2){
		tmp[i]='#';
		tmp[i+1]=s[i/2];
	}
	tmp[2*len+1]='#';
	tmp[2*len+2]='$';
	tmp[2*len+3]=0;
	for(i=0;i<strlen(tmp);i++)
		printf("s[%d]=%c ",i,tmp[i]);
	printf("\n");
	return tmp;	
}
/*
参数介绍：mx为当前所计算过的回文字符串的右断电的最大值
		  pos为回文子字符串右端点最大的时候中心所在位置 
*/
void Manacher(char *s,int l){
	int mx=0,ans=0,pos=0,i;
	for(i=1;i<=l;i++){
		printf("第%d次循环 mx=%d pos=%d\n",i,mx,pos);
		if(i<mx){
			Len[i]=min(mx-i,Len[2*pos-i]);	
		}else{
			Len[i]=1;	
		}
		while(s[i-Len[i]]==s[i+Len[i]]){
			Len[i]++;		
		}			
		if(Len[i]+i>mx){
			mx=Len[i]+i;
			pos=i;
		}
		
	}
	printf("每一个位置对应的最大回文数长度为：\n");
	for(i=1;i<=l;i+=2)
		Len[i]=0;
	for(i=0;i<=l;i++)
		printf("%d ",Len[i]);
	return;
}

int main(){
	int len,i;
	char* data=CreateData();
	char* t=Transfer(data);
	len=2*strlen(data)+1;
	Manacher(t,len);
	return 1;
}
	
