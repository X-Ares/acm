#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int min(int a,int b)
{
	return a>b?b:a;
}
char s[422222],str[422222];
int  p[422222];
int ma=0,l,r;
void manacher(int len) { //manacher ����
	l=r=ma=0;
	for(int i=len; i>=0; --i) { //��s�����м��#����ͷ��*
		s[i+i+2]=s[i];
		s[i+i+1]='#';
	}
	s[0]='$';
	int id,mx=0;  //mx������idΪ����ʱ��������Զ��λ��
	for(int i=1; i<len+len+1; ++i) {
		if(mx>i) p[i]=min(p[2*id-i],mx-i); //���������Զλ�ô��ڵ�ǰƥ��ĵط�����p[i]ȡmin��id�ĶԳƵ��p��������Զ����-i��
		else p[i]=1; //���i��mx�ҷ�����p[i]=-1;
		while(s[i-p[i]] == s[i+p[i]])++p[i];   //�ж�i���ĳ���
		if(i+p[i]>mx) { //���Ƿ�Ҫ������Զ���룬���Ҫ�����˵���Ϊ���ġ�
			id=i;
			mx=p[i]+i;
		}
		if(ma<p[i]-1) {
			ma=p[i]-1;
			l=(id-p[i])/2;
			r=(id+p[i]-1)/2-1;
		}
	}
}
int main() {
	char n,m;

	while(scanf("%c",&n)!=EOF) {
		      scanf("%s",s);
		      getchar();

		int len=strlen(s);
		for(int i=0; i<len; i++) {
			s[i]=s[i]-n+'a';
			if(s[i]<97)
				s[i]+=26;
			str[i]=s[i];

		}
		//cout<<len<<endl;
		manacher(len);
		if(ma==1)
			printf("No solution!\n");
		else {
			printf("%d %d\n",l,r);
			for(int i=l; i<=r; i++) {

				printf("%c",str[i]);
			}
			puts("");
		}


	}
	return 0;
}
