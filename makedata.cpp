#include <cstdio>
#include <ctime>
#include <cstdlib>

#include <iostream>
using namespace std;

const int RANGE = 100;

double Random(){ // [0,1]
	return (double)rand()  / RAND_MAX;
}

int Random(int m){ // [0,m-1]
	return (int)(random() % (m-1) + 0.5);
}

int main(){
	int n;

	scanf("%d",&n);

	srand(time(NULL));
	printf("1\n");
	printf("%d\n",n);
	for(int i=0;i<n;i++){
		printf("%d ",Random(RANGE));

	}
	printf("\n");

	return 0;
}
