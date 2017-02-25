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
void manacher(int len) { //manacher 函数
	l=r=ma=0;
	for(int i=len; i>=0; --i) { //将s扩大，中间加#，开头加*
		s[i+i+2]=s[i];
		s[i+i+1]='#';
	}
	s[0]='$';
	int id,mx=0;  //mx代表以id为中心时，到达最远的位置
	for(int i=1; i<len+len+1; ++i) {
		if(mx>i) p[i]=min(p[2*id-i],mx-i); //如果到达最远位置大于当前匹配的地方，则p[i]取min（id的对称点的p，到达最远距离-i）
		else p[i]=1; //如果i在mx右方，则p[i]=-1;
		while(s[i-p[i]] == s[i+p[i]])++p[i];   //判断i回文长度
		if(i+p[i]>mx) { //看是否要更新最远距离，如果要，将此点作为中心。
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
