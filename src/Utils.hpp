#pragma once
#include <string>



double calculate_portfolio_return(const double w[], const double r[], int n);

double calculate_final_value(double S, double portfolio_return);

double read_value(const std::string& value_str);

bool read_data(const std::string& filename, double& S, int& n, double*& w, double*& r);

void write_results(const std::string& filename, double S, int n, const double w[], const double r[], double portfolio_return, double V);

void print_results(double S, int n, const double w[], const double r[], double portfolio_return, double V);