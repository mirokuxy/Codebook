// euler path
#include <cstdio>
#include <cstring>

const int MAXN = 10;

int graph[MAXN][MAXN];
int vis[MAXN][MAXN];

int n,m;

void init(){
	scanf("%d %d",&n,&m);

	memset(graph,0,sizeof(graph));
	memset(vis,0,sizeof(vis));

	for(int i=0;i<m;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		graph[x][y] = graph[y][x] = 1;
	}
}

int has_euler(){
	int odds=0;
	int head=0;
	for(int i=0;i<n;i++){
		int count = 0;
		for(int j=0;j<n;j++) if(graph[i][j]) 
			count++;
		if(count%2) { 
			odds++; 
			head = i; 
			if(odds>2) return -1;
		}
	}
	return head;
}

void euler(int u){

	for(int i=0;i<n;i++) if(graph[u][i] && !vis[u][i]){
		vis[u][i] = vis[i][u] = 1;
		euler(i);
	}
	printf("%d <----",u);
}

int main(){
	init();
	
	int head = has_euler();
	if(head != -1){
		euler(head);
		printf("\n");
	}
	else printf("No Euler Path\n");

	return 0;
}

