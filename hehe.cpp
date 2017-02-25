#include<cstring>
#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
map<string, int>mp;
char a[1005], b[1005];
char s[500][1005];
const char mtc[] = "he";
int check(char *p, int &ans){
	int flag = 0, i;
	for(i = 0; p[i] && p[i] != ' '; ++i){
		if(p[i] != mtc[i%2]) break;
		else if(p[i+1] == 0 || p[i+1] == ' ') flag = 1;
	}
	if(i%2 == 0 && i>=4 && flag) return 1;
	return 0;
}
int main(){
	int tot = 0, pcnt = 1;
	while(scanf("%s", a) != EOF && a[0] != '-'){
		gets(b);
		sort(a, a+strlen(a));
		for(int i = 0; b[i]; ++i){
			if(b[i] >= 'a' && b[i] <= 'z') continue;
			if(b[i] >= 'A' && b[i] <= 'Z') b[i] = b[i]-'A'+'a';
			else b[i] = ' ';
		}
		if(!mp[a]) mp[a] = pcnt++;
		strcpy(s[mp[a]], b);
	}
	int ans = 0;
	for(int i = 1; i < pcnt; ++i){
		int flag = 0;
		for(int j = 0; s[i][j]; ++j){
			if(s[i][j] != ' '){
				if(check(&s[i][j], ans)) flag = 1;
				while(s[i][j] && s[i][j] != ' ') j += 1;
			}
		}
		if(flag) ans += 1; 
	}
	double dans = ans*1.0/(pcnt-1);
	sprintf(a, "%.5f", dans);
	ans = (a[2]-'0')*10+a[3]-'0';
	if(a[4]>='5') ans += 1;
	if(a[0] == '1') ans = 100;
	printf("%d%%\n", ans); 
} 
/*
A->B: HeHe
B->C: ABC
B->A: HeHe
C->B: HeHeHe
*/
