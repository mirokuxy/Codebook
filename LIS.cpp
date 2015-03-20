#include  <cstdio>

const int MAXLEN = 10;

// n^2

int DP[MAXLEN];
int sstring[MAXLEN];

int a[MAXLEN];
int n;

void dp(){
	for(int i=0;i<n;i++) DP[i] = 0;
	DP[0] = 1;
	for(int i=1;i<n;i++){
		int max = 0;
		for(int j=0;j<i;j++)
			if(a[j] < a[i] && max < DP[j]) max = DP[j];
		DP[i] = max + 1;
	}
}

void output(){
	int maxj = 0;
	for(int j=1;j<n;j++)
		if(DP[j] > DP[maxj]) maxj = j;
	printf("%d\n",DP[maxj]);

	int parent = maxj;
	sstring[DP[parent] - 1] = a[parent];
	for(int j=maxj-1;j>=0;j--)
		if(a[j] < a[parent] && DP[j] == DP[parent] -1 ){
			sstring[DP[j] -1] = a[j];
			parent = j;
		}
	for(int j = 0;j<DP[maxj]; j++)
		printf("%d ",sstring[j]);
	printf("\n");
}

// ----------------------------

// n*lgn

int minNum[MAXLEN];
int index[MAXLEN];
int len;
int pre[MAXLEN];

int bsearch(int a[],int p,int q,int x){ // [p,q)
	if(p == q-1){
		if(a[p] < x) return p+1;
		else return p;
	}
	else{
		int mid = (p+q) /2;
		if(a[mid] < x) return bsearch(a,mid,q,x);
		else return bsearch(a,p,mid,x);
	}
}

void DP2(int a[],int n){
	minNum[0] = a[0];
	index[0] = 0;
	len = 1;
	pre[0] = -1;

	for(int i=1;i<n;i++){
		int k = bsearch(minNum,0,len,a[i]);

		/*
		printf("minNum:\n");
		for(int j=0;j<len;j++) printf("%d ",minNum[j]);
		printf("\n");
		printf("Insert %d at minNum[%d]\n",a[i],k);
		*/
		
		if(k == len){
			minNum[len] = a[i];
			index[len] = i;
			len++;
			pre[i] = index[k-1];
		}
		else if(a[i] < minNum[k]){
			minNum[k] = a[i];
			index[k] = i;
			pre[i] = k>0?index[k-1]:-1;
		}
	}

	printf("%d\n",len);

	//output
	int tail = minNum[len-1];
	int tailIndex = index[len-1];
	for(int i=len-1; i>=0; i--){
		sstring[i] = tail;
		if(i==0) continue;
		tailIndex = pre[tailIndex];
		tail = a[tailIndex];
	}
	for(int i=0;i<len;i++)
		printf("%d ",sstring[i]);
	printf("\n");
}

// ------------------------

int main(){

	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);

	//dp();
	//output();
	DP2(a,n);

	return 0;
}
