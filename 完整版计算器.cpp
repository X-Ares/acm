#include "stdio.h"
#include "string.h"
#include "ctype.h"
#include "math.h"

//expression evaluate
#define iMUL 0
#define iDIV 1
#define iADD 2
#define iSUB 3
#define iCap 4
//#define LtKH 5
//#define RtKH 6

#define MaxSize 100
void iPush(float);
float iPop();
float StaOperand[MaxSize];
int iTop=-1;
//
char Srcexp[MaxSize];
char Capaexp[MaxSize];
char RevPolishexp[MaxSize];
float NumCapaTab[26];
char validexp[]="*/+-()";
char NumSets[]="0123456789";
char StackSymb[MaxSize];
int operands;
//
void NumsToCapas(char [], int , char [], float []);
int CheckExpress(char);
int PriorChar(char,char);
int GetOperator(char [], char);
void counterPolishexp(char INexp[], int slen, char Outexp[]);
float CalcRevPolishexp(char [], float [], char [], int);

int  main() {
	int ilen;
	float iResult=0.0;
	printf("输入一串数字\n");
	memset(StackSymb,0,MaxSize);
	memset(NumCapaTab,0,26); //A--NO.1, B--NO.2, etc.
	gets(Srcexp);
	ilen=strlen(Srcexp);
	//printf("source expression:%s\n",Srcexp);
	NumsToCapas(Srcexp,ilen,Capaexp,NumCapaTab);
	printf("数字有\n");
	int i;
	for (i=0; i<operands; ++i)
		printf("%.2f ",NumCapaTab[i]);
	printf("\n基本表达式:\n");
	printf("%s\n",Capaexp);
	ilen=strlen(Capaexp);
	counterPolishexp(Capaexp,ilen,RevPolishexp);
	printf("前缀表达式:\n%s\n",RevPolishexp);
	ilen=strlen(RevPolishexp);
	iResult=CalcRevPolishexp(validexp, NumCapaTab, RevPolishexp,ilen);
	printf("\n计算结果:\n%s\n%.6f\n",Srcexp,iResult);

}

void iPush(float value) {
	if(iTop<MaxSize) StaOperand[++iTop]=value;

}

float iPop() {
	if(iTop>-1)
		return StaOperand[iTop--];
	return -1.0;
}

void NumsToCapas(char Srcexp[], int slen, char Capaexp[], float NumCapaTab[]) {
	char ch;
	int i, j, k, flg=0;
	int sign;
	float val=0.0,power=10.0;
	i=0;
	j=0;
	k=0;
	while (i<slen) {
		ch=Srcexp[i];
		if (i==0) {
			sign=(ch=='-')?-1:1;
			if(ch=='+'||ch=='-') {
				ch=Srcexp[++i];
				flg=1;
			}
		}
		if (isdigit(ch)) {
			val=ch-'0';
			while (isdigit(ch=Srcexp[++i])) {
				val=val*10.0+ch-'0';
			}
			if (ch=='.') {
				while(isdigit(ch=Srcexp[++i])) {
					val=val+(ch-'0')/power;
					power*=10;
				}
			} //end if
			if(flg) {
				val*=sign;
				flg=0;
			}
		} //end if
	//	if(val) {
	if(Srcexp[i]=='(')
	{
		Capaexp[k++]=ch;
	}
	else
	{
			Capaexp[k++]='A'+j;
			if(ch==')')
			{
			Capaexp[k++]=ch;
			Capaexp[k++]=Srcexp[++i];
			}
			else
			{
				Capaexp[k++]=ch;
			}
			NumCapaTab[j++]=val; //A--0, B--1,and C, etc.
	}
	//} else {
		//	Capaexp[k++]=ch;
	//	}
		val=0.0;
		power=10.0;
		//
		i++;
	}
	Capaexp[k]='\0';
	operands=j;
}

float CalcRevPolishexp(char validexp[], float NumCapaTab[], char RevPolishexp[], int slen) {
	float sval=0.0, op1,op2;
	int i, rt;
	char ch;
//recursive stack
	i=0;
	while((ch=RevPolishexp[i]) && i<slen) {
		switch(rt=GetOperator(validexp, ch)) {
			case iMUL:
				op2=iPop();
				op1=iPop();
				sval=op1*op2;
				iPush(sval);
				break;
			case iDIV:
				op2=iPop();
				op1=iPop();
				if(!fabs(op2)) {
					printf("overflow\n");
					iPush(0);
					break;
				}
				sval=op1/op2;
				iPush(sval);
				break;
			case iADD:
				op2=iPop();
				op1=iPop();
				sval=op1+op2;
				iPush(sval);
				break;
			case iSUB:
				op2=iPop();
				op1=iPop();
				sval=op1-op2;
				iPush(sval);
				break;
			case iCap:
				iPush(NumCapaTab[ch-'A']);
				break;
			default:
				;
		}
		++i;
	}
	while(iTop>-1) {
		sval=iPop();
	}
	return sval;
}

int GetOperator(char validexp[],char oper) {
	int oplen,i=0;
	oplen=strlen(validexp);
	if (!oplen) return -1;
	if(isalpha(oper)) return 4;
	while(i<oplen && validexp[i]!=oper) ++i;
	if(i==oplen || i>=4) return -1;
	return i;
}

int CheckExpress(char ch)
 {
	int i=0;
	char cc;
	while((cc=validexp[i]) && ch!=cc) ++i;
	if (!cc)
		return 0;
	return 1;

}

int PriorChar(char curch, char stach) {
//栈外优先级高于(>)栈顶优先级时，才入栈
//否则(<=)，一律出栈
	if (curch==stach) return 0; //等于时应该出栈
	else if (curch=='*' || curch=='/') {
		if(stach!='*' && stach!='/')
			return 1;
	} else if (curch=='+' || curch=='-') {
		if (stach=='(' || stach==')')
			return 1;
	} else if (curch=='(') {
		if (stach==')')
			return 1;
	}
	return 0;
}

void counterPolishexp(char INexp[], int slen, char Outexp[]) {
	int i, j, k,pr;
	char t;
	i=0;
	j=k=0;
	while (INexp[i]!='=' && i<slen) {
		if (INexp[i]=='(')
			StackSymb[k++]=INexp[i];

		else if(INexp[i]==')') {

			while((t=StackSymb[k-1])!='(') {
				Outexp[j++]=t;
				k--;
			}
			k--;
		} else if (CheckExpress(INexp[i])) { 

			while (k) {

				if(pr=PriorChar(INexp[i],StackSymb[k-1]))
					break;
				else {

					t=StackSymb[k-1];
					k--;
					Outexp[j++]=t;
				}
			} 
			StackSymb[k++]=INexp[i]; 
		} else { 

			Outexp[j++]=INexp[i];
		}
		i++; 
	}
	while (k) {
		t=StackSymb[k-1];
		k--;
		Outexp[j++]=t;
	}
	Outexp[j]='\0';
}
