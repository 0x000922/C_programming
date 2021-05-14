#include<iostream>
using namespace std;

bool old_isPrime(int n){
	if(n == 1)
	    return false;
	else if ( n == 2)
	    return true;
	else{
		for(int i = 2; i < n; i++)
		{
		    
		    if(n % i == 0){
			return false;
		    }

		}

	}
	return true;

}


int main(){
	int n;




}

