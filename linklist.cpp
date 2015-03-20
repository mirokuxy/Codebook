#include <cstdio>

struct Link{
	int val;
	Link *next;
};

Link *list;

void insert(Link *head, int x){
	if(head == NULL) return;

	Link *p = head;
	for(; p->next!=NULL && p->next->val < x; p = p->next);
	if(p->next == NULL){
		p->next = new Link;
		p->next->next = NULL;
		p->next->val = x;
	}
	else{
		Link *tmp = new Link;
		tmp->val = x;
		tmp->next = p->next;
		p->next = tmp;
	}
}

void dele(Link *head,int x){
	Link *p = head;
	for(; p->next != NULL && p->next->val != x; p=p->next);
	if(p->next != NULL) {
		Link *tmp = p->next->next;
		delete p->next;
		p->next = tmp;
	}
}

void clean(Link *p){
	if(p->next != NULL) {
		clean(p->next);
		delete p->next;
		p->next = NULL;
	}
}

void output(Link *head){
	for(Link *p=head; p->next != NULL; p=p->next){
		printf("%d ",p->next->val);
	}
	printf("\n");	
}

void InsertSort(Link *head,int a[],int n){
	clean(head);
	for (int i = 0; i < n; ++i){
		insert(head,a[i]);
	}
	output(head);
}


int main(){
	int n;

	int a[20];

	list = new Link;
	list->next = NULL;

	while(1){
		scanf("%d",&n);
		if(n==0) break;
		if(n==-1) {
			int x;
			scanf("%d",&x);
			dele(list,x);
			output(list);
			continue;
		}
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		InsertSort(list,a,n);
	}

	return 0;
}
