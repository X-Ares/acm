#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<map>
#include<set>
using namespace std;
set<string> ans;
map<string,int>hashh;
//char a[1002],b[122][30];
void s(string &s1)
{
	for(int i=0;i<s1.size();i++)
	{
		s1[i]=tolower(s1[i]);
	}
	sort(s1.begin(),s1.end());
}
int main()
{
	string b[1000],a;
	int len=0,l=0;
	while(cin>>a&&a[0]!='#')
	{
	
		b[l++]=a;
		s(a);
		hashh[a]++;
	//	cout<<b[l-1]<<endl;
	}
	for(int i=0;i<l;i++)
	{
		string tmp=b[i];
		s(tmp);
		if(hashh[tmp]==1)
		ans.insert(b[i]);
	}
	for(set<string>::iterator it=ans.begin();it!=ans.end();it++)
	{
		cout<<*it<<endl;
	}
}
