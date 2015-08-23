//Language: GNU C++11


#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
	
	long input_num;
	unsigned long maximum = 0;
	
	char action;
	long id;

	cin >> input_num;

	std::vector<long>v;
	std::vector<long>minus;

	for (long i = 0; i < input_num; ++i)
	{
		cin >> action >> id;

		if(std::find(v.begin(), v.end(), id) != v.end()) {
		    if (action == '-') v.erase(std::remove(v.begin(), v.end(), id));		
		} else {
		    if (action == '+') {
		    	v.push_back(id);
		    	if(std::find(minus.begin(), minus.end(), id) != minus.end()) {
		    		minus.erase(std::remove(minus.begin(), minus.end(), id));
		    	}
		    }
		    else {
		    	minus.push_back(id);
		    	maximum++;
		    }
		}

		if ((v.size()) > maximum) maximum = v.size(); 
	}

	cout << maximum << endl;

	return 0;
}