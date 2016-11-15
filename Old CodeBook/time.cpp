#include <cstdlib>
#include <ctime>

srand(time(NULL));

// RAND_MAX = 32767

double random(){ // [0,1]
	return (double)rand()  / RAND_MAX;
}

int random(int m){ // [0,m-1]
	return (int)(random() * (m-1) + 0.5);
}