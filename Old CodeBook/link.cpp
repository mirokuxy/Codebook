// link
#include <cstdio>

struct link{
	link* left;
	link* right;
	int val;
};

link l[10];

void flink(link *x,link *y){
	x->right = y;
	y->left = x;
}

void left(link *x,link *y){
	flink(x->left,x->right);
	flink(y->left,x);
	flink(x,y);
}

void right(link *x,link *y){
	flink(x->left,x->right);
	flink(x,y->right);
	flink(y,x);
}

void print(link *x){
	for(;x!=NULL;x=x->right)
		printf("%d ",x->val);
	printf("\n");
}

int main(){

	int n;
	
	n = 5;
	for(int i=1;i<=n;i++){
		l[i].left = &l[i-1];
		l[i].right = &l[i+1];
		l[i].val = i;
	}
	l[0].left = l[n+1].right = NULL;
	l[0].right = &l[1]; l[n+1].left = &l[n];
	l[0].val = 0; l[n+1].val = n+1;

	print(&l[0]);

	left(&l[1],&l[5]);
	right(&l[2],&l[1]);
	right(&l[3],&l[5]);

	print(&l[0]);

	return 0;
}
