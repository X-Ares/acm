#include<iostream>
#include<cstdio>
#include<cstring>
char stack[1000],a[1000],e;
int i=1,len;
using namespace std;
void cs(char s[])
{
	memset(s,'\0',sizeof s);
}
int isempty(char s[])
{
	if(s[1]=='\0')
	return 1;
	else
	return 0;
 } 
 void push(char s[],char str)
 {
 	s[i++]=str;
 }
 int top(char s[])
 {
 	return s[i-1];
 }
 void pop(char s[])
 {
 	e=s[i-1];
 	s[i-1]='\0';
	 i--; 
  } 
  int work(char a[],int len)
  {
  	int j,jj;
  	char c;
  	for( j=1;j<=len;j++)
	{
	//	printf("%c",a[j]);
	if(a[j]=='('||a[j]=='{'||a[j]=='[')
	push(stack,a[j]);
	else
	{
		if(stack[i-1]=='('&&a[j]==')'||stack[i-1]=='['&&a[j]==']'||stack[i-1]=='{'&&a[j]=='}')
		pop(stack);
		else
		return 0;	
	}
	}
	return 1;
  }
int main()
{
	bool ans;
	cs(stack); 
	while(scanf("%s",a+1)!=EOF)
	{	
	len=strlen(a+1);
	//printf("%d",len); 
    ans=work(a,len);
    if(len%2)
    ans=0;
    if(ans)
    printf("YES\n");
    else
    printf("NO\n");
   cs(stack); 
	}
   return 0;
 } 
