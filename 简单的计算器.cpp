#include<iostream>
#include<cstring>
#include<stack>
using namespace std;
stack<char>arr;
char str[100],s[100],ss[100];
double sstack[100];
int len=0;
void clear(double a[])
{
	for(int i=0;i<sizeof a;i++)
	a[i]='\0';
}
void ppush(double a)
{
	sstack[len++]=a;
}
double ppop(double sstack[])
{
	double e=sstack[len-1];
	sstack[len-1]='\0';
	len--;
	return e;
}
double work(char s[])
{
	clear(sstack);
	double sum,a,b;
	int lens=strlen(s);
	for(int i=0;i<lens;i++)
	{
		if(s[i]-'0'>=0&&s[i]-'0'<=9)
		ppush(s[i]-'0');
		else
		{
			a=ppop(sstack);b=ppop(sstack);
			if(s[i]=='+')
			{
				sum=a+b;
			//	printf("%d ",sum);
				ppush(sum);
			}
			if(s[i]=='-')
			{
				sum=b-a;
				ppush(sum);
			}
			if(s[i]=='*')
			{
				sum=a*b;
			//	printf("%d ",sum);
				ppush(sum);
			}
			if(s[i]=='/')
			{
				sum=b/a*1.0;
				ppush(sum);
			}
		}
	}
		
	return ppop(sstack);
}
int main()
{
	while(~scanf("%s",ss))
	{
		memset(str,0,sizeof str);
		int j=1;
		int l=strlen(ss);
		str[0]=ss[0];
		arr.push(ss[1]);
		for(int i=2;i<l;i++)
		{
			
			if(ss[i]-'0'>=0&&ss[i]-'0'<=9)
			str[j++]=ss[i];
			else
			{
			/*if(arr.top()==')')
			{
				arr.pop();
				while(arr.top()=='(')
				{
					str[j++]=arr.top();
					arr.pop();
				}
				arr.pop();
			}*/
			if(arr.top()=='*'||arr.top()=='/'||(arr.top()=='-'&&(ss[i]!='*'&&ss[i]!='/')))
			{
			str[j++]=arr.top();
			arr.pop();
			}
			arr.push(ss[i]);
			}			
		}
			while(!arr.empty())
				{
						str[j++]=arr.top();
						arr.pop();
				}
			//cout<<str<<endl; 
		printf("%.2lf\n",work(str));
	} 
	
}


/*
6523+8*+3+*    2+3*8+5+3*6
*/
