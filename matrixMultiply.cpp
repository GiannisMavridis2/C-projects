#include <iostream>
#include <thread>
#include <cstdlib>
#include <ctime>

#define N 10 //the number of rows and columns

void fn(int row,int A[][N],int B[][N],int C[][N]){
	int sum=0,j,k;
	for (j=0;j<N;j++){
		for(k=0;k<N;k++){
			sum+=A[row][k]*B[k][j];
		}
	    C[row][j]=sum;
		sum=0;
	}	
}

int main(){
	int i,j;
	int A[N][N],B[N][N],C[N][N];
	std::thread t[N];//an array with N thread objects
	
	srand((int)time(0)); //seed the random number generator
	//assign random values to A and B 
	for (i=0;i<N;i++){
		for(j=0;j<N;j++){
			A[i][j] = (rand() % 100) + 1; //range [1-100]
			B[i][j] = (rand() % 100) + 1;
		}
	}
	//cout A
	for (i=0;i<N;i++){
		for(j=0;j<N;j++){
			std::cout << A[i][j] << " " ; 
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	//cout B 
	for (i=0;i<N;i++){
		for(j=0;j<N;j++){
			std::cout << B[i][j] << " " ; 
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	//start the N threads
	//each thread's task is to calculate a row of C
	for(i=0;i<N;i++){
		t[i]=std::thread(fn,i,A,B,std::ref(C));
	}
	for(i=0;i<N;i++){
		t[i].join();
	}
	//cout C 
	for (i=0;i<N;i++){
		for(j=0;j<N;j++){
			std::cout << C[i][j] << " " ; 
		}
		std::cout << std::endl;
	}
	return 0;
}