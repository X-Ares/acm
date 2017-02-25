#include<stdio.h>
#include<string.h>
const int sco[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int s1, s2;
int st, et;
char tmp[500];
int f[128];
int getime(char s[]){
	int h = f[s[0]]*10 + f[s[1]];
	int m = f[s[3]]*10 + f[s[4]];
	int sec = f[s[6]]*10 + f[s[7]];
	return h*3600+m*60+sec;
}
int getsco(int x){
	int res = 0;
	do{
		res += sco[x%10];
		x /= 10;
	}while(x);
	return res;
}
int main(){
	int ca = 1;
	for(char i = '0'; i <= '9'; ++i) f[i] = i-'0';
	while(scanf("%s", tmp), strcmp("START", tmp) == 0){
		int ans = 0;
		s1 = s2 = 0;
		scanf("%s", tmp);
		st = getime(tmp);
		while(scanf("%s", tmp), strcmp("END", tmp) != 0){
			scanf("%s", tmp);
			int nt = getime(tmp);
			scanf("%s", tmp);
			int delt = nt - st;
			ans += getsco(s1)*delt + getsco(s2)*delt;
			int ttmp;
			scanf("%d", &ttmp);
			if(tmp[0] == 'h') s1 +=ttmp;
			else s2 += ttmp;
			st = nt;
		}
		scanf("%s", tmp);
		int nt = getime(tmp);
		int delt = nt-st;
		ans += getsco(s1)*delt + getsco(s2)*delt;
		printf("Case %d: %d\n", ca++, ans);
	} 
}
