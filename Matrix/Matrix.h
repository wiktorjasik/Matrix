#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Matrix
{
private:
	int rows, cols;
	double **matrix;

public:
	Matrix();
	Matrix(int, int);
	Matrix(const Matrix&);
	~Matrix();
	friend ostream& operator<<(ostream&, const Matrix&);
	friend istream& operator>>(istream&, Matrix&);
	Matrix& operator=(const Matrix&);
	Matrix operator+(const Matrix&);
	Matrix operator-(const Matrix&);
	friend ofstream& operator<<(ofstream&, const Matrix&);
	friend ifstream& operator>>(ifstream&, Matrix&);
	Matrix operator*(const Matrix&);
	Matrix operator*(const int&);
	friend Matrix operator*(const int&, const Matrix&);
	void random();
	void loadA();
	void saveA();
	void loadB();
	void saveB();
};