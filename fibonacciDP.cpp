/*
compute the niosto fibonacci number
using dynamic programming
*/

#include <iostream>
#include <map>
#include <iterator>

int computeFn(int n,std::map<int,int> dict){
	std::map<int, int>::iterator cursor;
	int fn,key;
	//search for n in dictionary
	for(cursor = dict.begin(); cursor!=dict.end(); cursor++){ 
		key=cursor->first;
		if (key == n){
			return cursor->second;
		}
	}
	if (n<=1)
		return 1;
	else 
		fn=computeFn(n-1,dict)+computeFn(n-2,dict);
	//when i compute a fibonacci number , store it at dictionary
	dict[n]=fn;
	return fn;
}

main(){
	int n,fn;
	std::map<int,int> memo;
	memo[0]=0;
	memo[1]=1;
	std::cout << "compute n-th fibonacci number: " ;
	std::cin >> n ;
	fn=computeFn(n,memo);
	std::cout << fn; 
}