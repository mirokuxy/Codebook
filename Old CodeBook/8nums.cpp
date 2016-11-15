// 8nums

#include <cstdio>
#include <cstring>

typedef int State[9];

const int MAXN = 1000;
State st[MAXN],goal;
int dist[MAXN],pre[MAXN];


int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

int fact[9];
int vis[400000];

void init_lookup_table(){
	fact[0] = 1;
	for(int i=1;i<9;i++) fact[i] = fact[i-1] * i;
	memset(vis,0,sizeof(vis));
}

int try_to_insert(State& g){
	int code = 0;
	for(int i=0;i<9;i++){
		int cnt = 0;
		for(int j=i+1;j<9;j++) if(g[j] < g[i]) cnt++;
		code += fact[8-i] * cnt;
	}
	if(vis[code]) return 0;
	return vis[code] = 1;
}

int bfs(){
	int front=0,rear=1;

	if(memcmp(goal,st[front],sizeof(goal))==0) return front;

	init_lookup_table();
	
	while(front < rear){
		State &t = st[front];
		int z;
		for(z=0;z<9;z++) if(!t[z]) break;
		int x=z/3,y=z%3;
		for(int i=0;i<4;i++){
			int newx=x + dx[i],newy=y+dy[i];
			int newz = newx*3 + newy;
			if(newx <0 || newx >2 || newy <0 || newy >2) continue;
			State &g = st[rear];
			memcpy(&g,&t,sizeof(t));
			g[newz] = t[z];
			g[z] = t[newz];
			dist[rear] = dist[front] + 1;
			pre[rear] = front;
			if(try_to_insert(g)){
				if(memcmp(goal,g,sizeof(g))==0) return rear;
				rear++;
			}
		}
		front++;
	}

	return -1;
}

void output(int p){
	while(p!=-1){
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++)
				printf("%d ",st[p][i*3+j]);
			printf("\n");
		}
		printf("\n");

		p = pre[p];
	}
}

int main(){
	for(int i=0;i<9;i++)
		scanf("%d",&st[0][i]);
	for(int i=0;i<9;i++)
		goal[i] = i;

	pre[0] = -1;
	dist[0] = 0;

	int ans = bfs();

	if(ans != -1){
		printf("dist = %d\n",dist[ans]);
		output(ans);
	}
	else printf("-1\n");

	return 0;
}
