#include<stdio.h>
#include<string.h> 
double dp[15][10][10];
double ra[15];
double rb[15];
int f(int x){
	return x < 0? -x:x;
}
int main(){
	int ca = 1;
	while(scanf("%lf", &ra[1]) != EOF){
		for(int i = 2; i <= 5; ++i) scanf("%lf", &ra[i]);
		for(int i = 1; i <= 5; ++i) scanf("%lf", &rb[i]);
		int wa, wb;
		scanf("%d-%d", &wa, &wb);
		memset(dp, 0, sizeof(dp));
		dp[0][0][0] = 1;
		for(int i = 0; i < 10; ++i){
			for(int a = 0; a <= wa; ++a){
				for(int b = 0; b <= wb; ++b){
					if(a+b > i) continue;
					if(i%2 == 0){
						int sa, sb;
						sa = sb = (10-i+1)/2;
						if(a-b > sb){
							dp[10][a][b] += dp[i][a][b];
							continue;
						}
						else if(a-b == sb){
							dp[10][a+1][b] += dp[i][a][b]*ra[(i+1)/2+1];
							dp[i+1][a][b] += dp[i][a][b]*(1-ra[(i+1)/2+1]);
							continue;
						}
						if(b-a > sa){
							dp[10][a][b] += dp[i][a][b];
							continue;
						}
						dp[i+1][a][b] += dp[i][a][b]*(1-ra[(i+1)/2+1]);
						dp[i+1][a+1][b] += dp[i][a][b]*ra[(i+1)/2+1];
					}
					else{
						int sa, sb;
						sa = (10-i)/2, sb = (10-i)/2+1;
						if(b-a > sa){
							dp[10][a][b] += dp[i][a][b];
							continue;
						}
						else if(b-a == sa){
							dp[10][a][b+1] += dp[i][a][b]*rb[(i+1)/2];
							dp[i+1][a][b] += dp[i][a][b]*(1-rb[(i+1)/2]);
							continue;
						}
						if(a-b > sb){
							dp[10][a][b] += dp[i][a][b];
							continue;
						}
						dp[i+1][a][b] += dp[i][a][b]*(1-rb[(i+1)/2]);
						dp[i+1][a][b+1] += dp[i][a][b]*rb[(i+1)/2];
					}
				}
			}
		}
		printf("Case %d: %.2f%%\n", ca++ ,100*(dp[10][wa][wb]));
	}
}
