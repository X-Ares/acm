#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const  int maxn = 100000+50;
int js;
struct node
{
    int Next[27];//ÿһ���ڵ������չ������ĸ
    int fail; //ÿһ������ʧ��ָ��
    int count;//��¼ÿһ�����Թ��ɵ��ʵ��ַ���
    int pos;
    void init()//����
    {
        memset(Next,-1,sizeof(Next));//next��ʼ��Ϊ-1�����������κ�ֵ
        fail = 0; //ʧ��ָ��Ϊ��
        count = 0;//һ��ʼû�е��ʣ�Ϊ0.
        pos=0;
    }
}s[maxn];

int sind;//��¼���ı��
char str[11111];//ģ�洮�������ʡ���
char des[111111][11111];//�����¡�
int q[maxn],qin,qout;//����

void cas_init()//����������ǰ����root
{
    s[0].init();//��ʼ��ͷ���
    sind = 1; //��ǰ��һ�����
}

void ins(int p)//�����в�����ĸ
{
    int len = strlen(str);
    int i, j, ind;
    for(i = ind = 0;i < len;i++)
    {
        j = str[i]-97;//�����ĸ��next�еı��
        if(s[ind].Next[j]== -1)//����������ӽڵ�j�������µ�
        {
            s[sind].init();//��ʼ��
            s[ind].Next[j] = sind++;//����ǰ��㣬��sind++�����ܽ����
        }
        ind = s[ind].Next[j]; //������
    }
    s[ind].count++;//��������������·�����ַ����ĸ�����һ��·�Ͽ��ܲ�ֹһ������
    s[ind].pos=p;
}

 void make_fail()//����ʧ��ָ��
 {
     qin = qout = 0;//��ʼ������
     int i,ind,ind_f;
     for(i=0;i<27;i++)
     {
         if(s[0].Next[i]!=-1)
             q[qin++]=s[0].Next[i];//�ȿ��Ǹ���㣬�͸���������Ķ����
     }
       while(qin!=qout)
       {
           ind = q[qout++];//��¼���׽��
        for(i = 0;i < 27; i++)//�������׽���Next
        {
            if(s[ind].Next[i]!=-1)//������Next��Ϊ��
            {
                q[qin++] = s[ind].Next[i];//�����ӽڵ����
                ind_f = s[ind].fail;//��¼�ڵ��ʧ��ָ��ָ��
                while(ind_f>0 && s[ind_f].Next[i]==-1)
                /*��ʧ��ָ�벻Ϊrootʱ��һֱѭ��ֱ���ҵ�һ������Ƕ�����iֵ���ߵ���root*/
                    ind_f = s[ind_f].fail;
                if(s[ind_f].Next[i]!=-1) //�����ǰ����ж��ӵĻ���¼��������
                    ind_f = s[ind_f].Next[i];
                s[s[ind].Next[i]].fail = ind_f; //ʹ��ǰ����ʧ��ָ��ָ��ղż�¼�Ľ�����ʧ��ָ���Ѱ�ҹ���
            }
        }
       }
 }

 int fd(int ii)
 {
     int ct = 0; //��¼�����ʵĸ�����
     int di,i,ind ,p; //diΪָ�����¡���ָ�룬indΪָ��ʧ�����ָ�루��trie����ʧ���ָ�룩
     int len = strlen(des[ii]);//���µĳ���
     for(di = ind =0; di < len ; di++)
     {
         i = des[ii][di]-97;
         while(ind>0 && s[ind].Next[i] == -1)
     /*��indָ�벻��root���Ҳ������Ķ�����iʱһֱ����ȥ(������KMP��whileѭ��)*/
             ind = s[ind].fail; //һֱѰ��ʧ��ָ��

         if(s[ind].Next[i]!= -1)//�ҵ��˺��ʵ�ʧ��ָ��
         {
             ind = s[ind].Next[i]; //ָ��������ӵĽڵ㣬����ind��ֵ������һ��ƥ��

             p = ind; //��p����ʱ����ind
             while(p>0 && s[p].count!=-1)
             /* p>0 ��ʾ��û��root��count��=-1��ʾָ��ǰ���е���*/
             {
                     if(s[p].count>0)
                                {
                 ct+=s[p].count;//�����еĵ��ʵĸ���
                                }
                 s[p].count = -1;//���ظ����㣬ע���������Ҫ
                 p = s[p].fail;//һֱѰ��ʧ��ָ��
             }
         }
     }
     return ct;//���ص��ʸ���
 }


 int main()
 {
         int test;
         cin>>test;
         while(test--){
                int n,m;
                js=0;
                scanf("%d%d",&n,&m);
                 cas_init();//��ʼ��trie��
                 for(int i = 1;i<=n;i++)
                         scanf("%s",des[i]);
                for(int i=1;i<=m;i++)
                {
                    scanf("%s",str);
                    ins(i);//����trie��
                }
                make_fail(); //����ʧ��ָ��
                for(int i = 1;i<=n;i++)
                        printf("%d\n",fd(i));
         }
     return 0;
 }
