// topo sort

#include <cstdio>
#include <cstring>

const int MAXN = 10;

const int DOING = -1;
const int DONE = 1;

int state[MAXN];
int topo[MAXN];

int graph[MAXN][MAXN];

int n,m;
int t;

void init(){
	scanf("%d %d",&n,&m);

	memset(graph,0,sizeof(graph));

	for(int i=0;i<m;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		graph[x][y] = 1;
	}
}

int dfs(int x){
	state[x] = DOING;

	for(int i=0;i<n;i++) if(graph[x][i]){
		if(state[i] == DOING) return false;
		else if(state[i] == 0 && !dfs(i)) return false;
	}

	state[x] = DONE;
	topo[--t] = x;
	return true;
}

int toposort(){
	t = n;

	memset(topo,0,sizeof(topo));
	memset(state,0,sizeof(state));

	for(int i=0;i<n;i++)
		if(state[i] == 0 && !dfs(i)) return false;
	return true;
}

int main(){
	init();

	if(toposort()){
		for(int i=0;i<n;i++) printf("%d ",topo[i]);
		printf("\n");
	}
	else printf("Circle\n");

	return 0;
}
