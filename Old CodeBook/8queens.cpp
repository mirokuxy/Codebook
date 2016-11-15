// 8 queens

#include <cstdio>
#include <cstring>

const int MAXN = 20;

int pos[MAXN];
int vis[3][MAXN];

int n=5;

void dfs(int p){
	if(p==n){
		for(int i=0;i<n;i++) printf("%d ",pos[i]);
		printf("\n");
		return ;
	}
	for(int i=0;i<n;i++)
		if(!vis[0][i] && !vis[1][p+i] && !vis[2][p-i+(n-1)]){
			pos[p] = i;
			vis[0][i] = vis[1][p+i] = vis[2][p-i+(n-1)] = 1;
			dfs(p+1);
			vis[0][i] = vis[1][p+i] = vis[2][p-i+(n-1)] = 0;
		}
}

void eight_queens(){
	memset(pos,0,sizeof(pos));
	memset(vis,0,sizeof(vis));
	dfs(0);
}

int main(){
	eight_queens();

	return 0;
}
