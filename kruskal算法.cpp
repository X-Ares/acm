#include<iostream>  
#include<cstring>  
#include<string>  
#include<cstdio>  
#include<algorithm>  
using namespace std;  
#define MAX 1000  
int father[MAX], son[MAX];  
int v, l;  
  
typedef struct Kruskal //�洢�ߵ���Ϣ  
{  
    int a;  
    int b;  
    int value;  
};  
  
bool cmp(const Kruskal & a, const Kruskal & b)  
{  
    return a.value < b.value;  
}  
  
int unionsearch(int x) //���Ҹ����+·��ѹ��  
{  
    return x == father[x] ? x :unionsearch(father[x]);  
}  
  
bool join(int x, int y) //�ϲ�  
{  
    int root1, root2;  
    root1 = unionsearch(x);  
    root2 = unionsearch(y);  
    if(root1 == root2) //Ϊ��  
        return false;  
    else if(son[root1] >= son[root2])  
        {  
            father[root2] = root1;  
            son[root1] += son[root2];  
        }  
        else  
        {  
            father[root1] = root2;  
            son[root2] += son[root1];  
        }  
    return true;  
}  
  
int main()  
{  
    int ncase, ltotal, sum, flag;  
    Kruskal edge[MAX];  
   
    
       while(~ scanf("%d%d", &v, &l))
		{ 
        ltotal = 0, sum = 0, flag = 0;  
        for(int i = 1; i <= v; ++i) //��ʼ��  
        {  
            father[i] = i;  
            son[i] = 1;  
        }  
        for(int i = 1; i <= l ; ++i)  
        {  
            scanf("%d%d%d", &edge[i].a, &edge[i].b, &edge[i].value);  
        }  
        sort(edge + 1, edge + 1 + l, cmp); //��Ȩֵ��С��������  
        for(int i = 1; i <= l; ++i)  
        {  
            if(join(edge[i].a, edge[i].b))  
            {  
                ltotal++; //������1  
                sum += edge[i].value; //��¼Ȩֵ֮��  
                //cout<<edge[i].a<<"->"<<edge[i].b<<endl;  
            }  
            if(ltotal == v - 1) //��С����������������=������-1  
            {  
                flag = 1;  
                break;  
            }  
        }  
        if(flag) printf("%d\n", sum);  
        else printf("data error.\n");  
    }  
    return 0;  
}  
