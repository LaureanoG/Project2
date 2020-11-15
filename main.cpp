#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, r, c;

	// Gets inputs
	std::cout << "Input n: ";
	cin >> n;
	std::cout << "Input r: ";
	cin >> r;
	std::cout << "Input c: ";
	cin >> c;

	// Intializes the data struct for interative dp
	vector<vector<vector<int>>> validStates (n, vector<vector<int> >(r, vector <int>(c, 0)));

	// Iterates through the data struct {i:n  j:r  k:c}
	int sum = 0;
	for (int i = 0; i < n; i++) { 
		for (int j = 0; j < r; j++) { 
			for (int k = 0; k < c; k++) { 
				// Base cases
				// Other work
			
			}
		}
	}


	return 0;
}