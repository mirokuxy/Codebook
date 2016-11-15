#include <cstdio>
#include <cstring>

const int N = 10;

struct Set{
	int group[N];

	void make(){
		for(int i=0;i<N;i++)
			group[i] = i;
	}

	int find(int k){
		if(group[k] == k) return k;
		else return group[k] = findSet(group[k])
	}

	void union(int a,int b){
		int pa = findSet(a);
		int pb = findSet(b);
		if(pa != pb){
			group[pa] = pb;
		}
	}

	void print(){
		for(int i=0;i<N;i++)
			printf("%d ", i);
		printf("\n");

		for(int i=0;i<N;i++)
			printf("%d ", group[i]);
		printf("\n");
	}
};

Set S;

int main(){
	S.make();

	int a,b;

	while(1){
		scanf("%d %d", &a, &b);
		if(a == -1) break;

		S.union(a,b);
		S.print();
	}

	return 0;
}

