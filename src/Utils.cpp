#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cctype>
#include <string>
#include "Utils.hpp"

using namespace std;

double calculate_portfolio_return(const double w[], const double r[], int n) {
    double portfolio_return = 0.00;
    for (int i = 0; i < n; i++) {
        portfolio_return += w[i] * r[i];
    }
    return portfolio_return;
}

double calculate_final_value(double S, double portfolio_return) {
    return (1 + portfolio_return) * S;
}

double read_value(const string& value_str) {
    string cleaned;
    for (size_t i = 0; i < value_str.size(); i++) {
        char c = value_str[i];
        if (isdigit(c) || c == '-' || c == '.') {
            cleaned += c;
        }		
    }

    stringstream ss(cleaned);
    double value;
    if (!(ss >> value)) {
        cerr << "Errore nella conversione del valore: " << cleaned << endl;
        return 0.0;
    }
    return value;
}


bool read_data(const string& filename, double& S, int& n, double*& w, double*& r) {
    ifstream infile(filename);
    if (infile.fail()) {
        cerr << "Impossibile aprire il file" << filename << endl;
        return false;
    }

    string tmp;
    getline(infile, tmp);
    S = read_value(tmp);

    getline(infile, tmp);
    n = static_cast<int>(read_value(tmp));
	
	w = new double[n];
    r = new double[n];
	
	getline(infile,tmp);

    for (int i = 0; i < n; ++i) {
        getline(infile, tmp);
        stringstream ss(tmp);
        string w_str, r_str;

        if (!getline(ss, w_str, ';') || !getline(ss, r_str, ';')) {
            cerr << "Errore nella lettura dei dati per l'asset " << i << endl;
            return false;
        }

        w[i] = read_value(w_str);
        r[i] = read_value(r_str);
    }

    infile.close();
    return true;
}

void write_results(const string& filename, double S, int n, const double w[], const double r[], double portfolio_return, double V) {
    ofstream outfile(filename);
    if (outfile.fail()) {
        cerr << "Impossibile aprire il file di output" << endl;
        return;
    }

    outfile << fixed << setprecision(2);
    outfile << "S = " << S << ", n = " << n << endl;
    outfile << "w = [ ";
    for (int i = 0; i < n; ++i) {
        outfile << w[i] << " ";
    }
    outfile << "]" << endl;

    outfile << "r = [ ";
    for (int i = 0; i < n; ++i) {
        outfile << r[i] << " ";
    }
    outfile << "]" << endl;

    outfile << "Rate of return of the portfolio: " << fixed << setprecision(4) << portfolio_return << endl;
    outfile << "V: " << fixed << setprecision(2) << V << endl;

    outfile.close();
}

void print_results(double S, int n, const double w[], const double r[], double portfolio_return, double V) {
    cout << fixed << setprecision(2);

    cout << "S = " << S << ", n = " << n << endl;
    cout << "w = [ ";
    for (int i = 0; i < n; ++i) {
        cout << w[i] << " ";
    }
    cout << "]" << endl;

    cout << "r = [ ";
    for (int i = 0; i < n; ++i) {
        cout << r[i] << " ";
    }
    cout << "]" << endl;

    cout << "Rate of return of the portfolio: " << fixed << setprecision(4) << portfolio_return << endl;
    cout << "V: " << fixed << setprecision(2) << V << endl;
}