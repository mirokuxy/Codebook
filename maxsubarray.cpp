#include <cstdio>
#include <cstdlib>


int maxSub(int a[],int n){
	int *sum;
	sum = (int*) malloc(n * sizeof(int) );

	int minSum,maxSum;
	if (n <= 0) return 0;
	sum[0] = minSum = maxSum = a[0];
	if(minSum > 0) minSum = 0;
	for(int i=1;i<n;i++){
		sum[i] = sum[i-1] + a[i];
		if(maxSum < sum[i] - minSum)
			maxSum = sum[i] - minSum;
		if(minSum > sum[i])
			minSum = sum[i];
	}

	free(sum);

	return maxSum;
}

int maxSubNonContinous(int a[],int n){
	int sum = 0;
	int hasPositive = false;

	for(int i=0;i<n;i++) if(a[i] >= 0){
		hasPositive = true;
		sum += a[i];
	}

	if(hasPositive) return sum;

	int max=a[0];
	for(int i=1;i<n;i++) if(max < a[i])
		max = a[i];
	return max;
}

const int MAXN = 100000 + 5;

int array[MAXN];

int main(){
	int t;
	int n;

	scanf("%d",&t);
	for(int k=0;k<t;k++){
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d",&array[i]);
		printf("%d %d\n",maxSub(array,n),maxSubNonContinous(array,n));
	}

	return 0;
}

