#include<stdio.h>
#include<stdlib.h>
#define max 1000
int minu(int a,int b){
    return a<b?a:b;
}
int minimumDeleteSum(char* s1, char* s2) {
    int m=strlen(s1),n=strlen(s2),i,j,mi=0;
    // int **dp=(int **)malloc((strlen(s1)+1)*sizeof(int *));
    // for(i=0;i<strlen(s1)+1;i++)
    //     *(dp+i)=(int *)malloc((strlen(s2)+1)*sizeof(int));
    int dp[m+1][n+1];
    for(i=0;i<=m;i++){
    	for(j=0;j<=n;j++){
    		dp[m][n]=0;
    		printf("%d ",dp[m][n]); 
		}
		printf("\n");
	}
	dp[0][0]=0;
    for(i=1;i<=m;i++){
    	dp[i][0]=dp[i-1][0]+s1[i-1];
    	printf("dp[%d][0]=%d \n",i,dp[i][0]);
	}
        
    for(i=1;i<=n;i++){
    	dp[0][i]=dp[0][i-1]+s2[i-1];
    	printf("dp[0][%d]=%d \n",i,dp[0][i]);
	}
        
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            if(s1[i-1]==s2[j-1]){
            	dp[i][j]=dp[i-1][j-1];
            	printf("dp[%d][%d]=%d \n",i,j,dp[i][j]);
			}
                
            else{
            	dp[i][j]=minu(dp[i-1][j]+s1[i-1],dp[i][j-1]+s2[j-1]);
                printf("dp[%d][%d]=%d \n",i,j,dp[i][j]);
			}
                
        //mi=mi>dp[i][j]?dp[i][j]:mi;
        }
    }
    for(i=0;i<=m;i++){
    	for(j=0;j<=n;j++){
    		printf("%d ",dp[i][j]);
		}
		printf("\n");
	}
    return dp[m][n];
}

int main(){
	char *s1=(char *)malloc(max*sizeof(char));
	char *s2=(char *)malloc(max*sizeof(char));
	printf("输入第一个字符串\n");
	scanf("%s",s1);
	printf("输入第二个字符串\n");
	scanf("%s",s2);
	int ans=minimumDeleteSum(s1,s2);
	printf("%d",ans);
	
}
