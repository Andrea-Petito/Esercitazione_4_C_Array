#include <iostream>
#include <iostream>
#include <iomanip>
#include "Utils.hpp"

using namespace std;

int main() {
	double S;
	int n;
	double* w;
	double* r;
	
	if (!read_data("data.txt", S, n, w, r)) {
        cerr << "Errore nella lettura dei dati" << endl;
        return 1;
    }
	
	double portfolioReturn = calculate_portfolio_return(w, r, n);
	
	double finalValue = calculate_final_value(S, portfolioReturn);
	
	print_results(S, n, w, r, portfolioReturn, finalValue);
	
	write_results("result.txt", S, n, w, r, portfolioReturn, finalValue);
	
	delete[] w;
	delete[] r;
	
    return 0;
}

