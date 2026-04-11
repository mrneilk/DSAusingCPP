#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> arr={1,-5,6,-4,-4,-10,5,3,87};        //initialising vector
	stable_partition(arr.begin(),arr.end(),[](int x){   //partition algorithm to partition using the given condition
	    return x<0;
	});
	for(int &x: arr)cout<<x<<" ";     //output the vector
	
	
}

// -5 -4 -4 -10 1 6 5 3 87 //output
