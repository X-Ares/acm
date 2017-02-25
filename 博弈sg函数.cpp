#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
//f[]������ȡ�ߵ�ʯ�Ӹ���
//sg[]:0~n��SG����ֵ
//hash[]:mex{}
const int N=10005;
int f[108],sg[N];
bool hash1[N];     
void getSG(int n,int t)
{
    int i,j;
    memset(sg,0,sizeof(sg));
    for(i=1;i<=n;i++)
    {
        memset(hash1,0,sizeof(hash1));
        for(j=0;j<t;j++)
        if(i-f[j]>=0)
            hash1[sg[i-f[j]]]=1;
        for(j=0;j<=n;j++)    //��mes{}��δ���ֵ���С�ķǸ�����
        {
            if(hash1[j]==0)
            {
                break;
            }
        }
        sg[i]=j;
    }
}
int main()
{
	int n,m,t;
	while(scanf("%d",&n),n)
	{
		for(int i=0;i<n;i++)
		scanf("%d",&f[i]);
		getSG(N,n);
		scanf("%d",&m);
		string ans="";
		while(m--)
		{
			scanf("%d",&t);
			int x,a=0;
			for(int i=1;i<=t;i++)
			{
			scanf("%d",&x);
			a^=sg[x];
			}
			ans+=a?"First player wins.":"Second player wins.";
		}
		cout<<ans<<endl;
	}
	
}
