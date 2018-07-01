
#include<stdio.h>
#include<string.h>
void reverse(char* str)
{	
	char tmp = *str;//��tmp���� �ַ����ĵ�һ���ַ�
	int len = strlen(str);//��ǰ�ַ����ĳ��� ps:ÿ�εݹ飬���ȶ���仯
	*str = *(str+len-1);//��'\0'��ǰһ��Ԫ�ظ�����һ��
	*(str+len-1) = '\0';//��'\0'��ǰһ��Ԫ���ȸ���'\0'
	if(strlen(str)>1)//���ַ������ȴ���1���ݹ�  ps:ÿ���滻һֱ���м�ƽ�����û���ַ���ֻ��һ���ַ���ʱ�򶼲��ؼ���
		reverse(str+1);//���еݹ飬�׵�ַָ�����
	*(str+len-1) = tmp;//ȫ���ݹ���ɺ󣬽�'\0'��ԭ��ԭ�����м�Ԫ��	
}
int main()
{		
	char str[] = "!gnosoahoah olleH";
	reverse(str);
	printf("%s\n",str); 
	return 0;
} 
