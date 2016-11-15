#include <cstdio>
#include <cstring>

using namespace std;

struct Linked{
	int val;
	Linked* next;

	Linked(){
		val = 0;
		next = NULL;
	}

	Linked(int v, Linked* n): val(v), next(n) {}

	void insert(int v){
		Linked *p = new Linked(v,this->next);
		this->next = p;
	}

	Linked* search(int v){
		for(Linked *p = this->next; p != NULL; p=p->next){
			if(p->val == v) 
				return p;
		}
		return NULL;
	}

	bool remove(int v){
		Linked *parent = this;
		for(Linked *p = parent->next; p != NULL; parent = p, p = parent->next){
			if(p->val == v){
				parent->next = p->next;
				delete p;
				return true;
			}
		}
		return false;
	}

	void print(){
		for(Linked *p = this->next; p != NULL; p=p->next)
			printf("%d ", p->val);
		printf("\n");
	}
};

Linked L;

int main(){
	int x;

	while(1){
		scanf("%d",&x);
		if(x == -1 ) break;

		L.insert(x);
		//L.print();
	}

	L.print();

	while(1){
		scanf("%d",&x);
		if(x == -1) break;

		Linked *p = L.search(x);
		if(p) printf("Found: %d\n", p->val);
		else printf("NULL: \n");
	}

	while(1){
		scanf("%d",&x);
		if(x == -1) break;

		int f = L.remove(x);
		L.print();
		if(f) printf("Removed: \n");
		else printf("Not Found: \n");
	}

	return 0;
}

