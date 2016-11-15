// 8nums

#include <cstdio>
#include <cstring>

typedef int State[9];

const int MAXN = 1000;
State st[MAXN],goal;
int dist[MAXN],pre[MAXN];


int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

const int HASHSIZE = 1000003;
int head[HASHSIZE],next[MAXN];

void init_lookup_table(){
	memset(head,0,sizeof(head));
	memset(next,0,sizeof(next));
}

int hash(State &g){
	int sum=0;
	for(int i=0;i<9;i++) sum = sum*10 + g[i];
	return sum % HASHSIZE;
}

int try_to_insert(int s){
	int h = hash(st[s]);
	int u = head[h];
	while(u){
		if(memcmp(st[u],st[s],sizeof(st[s]))==0) return 0;
		u = next[u];
	}
	next[s] = head[h];
	head[h] = s;
	return 1;
}

int bfs(){
	int front=1,rear=2;

	init_lookup_table();

	if(memcmp(goal,st[front],sizeof(goal))==0) return front;

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
			if(try_to_insert(rear)){
				if(memcmp(goal,g,sizeof(g))==0) return rear;
				rear++;
			}
		}
		front++;
	}

	return 0;
}

void output(int p){
	while(p!=0){
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
		scanf("%d",&st[1][i]);
	for(int i=0;i<9;i++)
		goal[i] = i;

	pre[1] = 0;
	dist[1] = 0;

	int ans = bfs();

	if(ans != 0){
		printf("dist = %d\n",dist[ans]);
		output(ans);
	}
	else printf("-1\n");

	return 0;
}
