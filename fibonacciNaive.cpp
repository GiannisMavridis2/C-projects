#include <iostream>

int computeFn(int n){
	if (n<=1)
		return 1;
	else 
		return computeFn(n-1)+computeFn(n-2);
}

main(){
	int n,fn;
	std::cout << "compute n-th fibonacci number: " ;
	std::cin >> n ;
	fn=computeFn(n);
	std::cout << fn; 
}

