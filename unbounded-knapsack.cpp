#include <cstdio>

const int MAXK = 2000 + 5;
const int MAXN = 2000 + 5;

bool DP[MAXK];

int knapsack(int w[],int n,int k){
	for(int i=0;i<=k;i++) DP[i] = false;
	DP[0] = true;
	
	for(int i=0;i<n;i++){
		for(int j=k;j>=w[i];j--) if(!DP[j])  {
			//printf("Calculating %d\n",j);
			for(int c=1;c<=(j/w[i]);c++){
				//printf("  try %d : ",c);
				if(DP[j-c*w[i]]){
					DP[j] = true;
					//printf(" true\n");
					break;
				}
				//else printf(" false\n");
			}
		}
	}

	//for(int i=0;i<=k;i++) printf("%d ",DP[i]?1:0);
	//printf("\n");

	int max = 0;
	for(int i=k;i>0;i--) if(DP[i]){
		max = i;
		break;
	}

	return max;
}

int weight[MAXN];

int main(){
	int t;
	int n,k;

	scanf("%d",&t);
	for(int i=0;i<t;i++){
		scanf("%d %d",&n,&k);
		for(int j=0;j<n;j++) scanf("%d",&weight[j]);
		//for(int j=0;j<n;j++) printf("%d ",weight[j]);
		//printf("\n");
		printf("%d\n",knapsack(weight,n,k));
	}

	return 0;
}




