#include "Matrix.h"

Matrix::Matrix()
{
	rows = 0;
	cols = 0;
}

Matrix::Matrix(int a, int b)
{
	if ((a > 0) && (b > 0))
	{
		rows = a;
		cols = b;
	}
	else
	{
		rows = 0;
		cols = 0;
	}
	
	matrix = new double*[rows];
	for (int i = 0; i < rows; i++)
	{
		matrix[i] = new double[cols];
		for (int j = 0; j < cols; j++)
			matrix[i][j] = 0;
	}
}

Matrix::Matrix(const Matrix &m)
{
	rows = m.rows;
	cols = m.cols;
	matrix = new double*[rows];
	for (int i = 0; i < rows; i++)
	{
		matrix[i] = new double[cols];
		for (int j = 0; j < cols; j++)
			matrix[i][j] = m.matrix[i][j];
	}	
}

Matrix::~Matrix()
{
	cout << "Destruktor" << endl;
	for (int i = 0; i < rows; i++)
		delete[]matrix[i];
	delete[]matrix;
	matrix = NULL;
}

ostream& operator<<(ostream &out, const Matrix &m)
{
	for (int i = 0; i < m.rows; i++)
	{
		for (int j = 0; j < m.cols; j++)
			out << m.matrix[i][j] << " ";
		out << endl;
	}
	return out;
}

istream& operator>>(istream &in, Matrix &m)
{
	cout << "Wpisz liczbe wierszy macierzy: ";
	in >> m.rows;
	cout << "Wpisz liczbe kolumn macierzy: ";
	in >> m.cols;
	m.matrix = new double*[m.rows];
	for (int i = 0; i < m.rows; i++)
	{
		m.matrix[i] = new double[m.cols];
		for (int j = 0; j < m.cols; j++)
		{
			cout << " Wpisz element [" << i << "][" << j << "] macierzy: ";
			in >> m.matrix[i][j];
		}
	}
	return in;
}

Matrix& Matrix::operator=(const Matrix &m)
{
	if (this == &m)
		return *this;
	for (int i = 0; i < rows; i++)
		delete[]matrix[i];
	delete[]matrix;
	rows = m.rows;
	cols = m.cols;
	matrix = new double*[rows];
	for (int i = 0; i < rows; i++)
	{
		matrix[i] = new double[cols];
		for (int j = 0; j < cols; j++)
			matrix[i][j] = m.matrix[i][j];
	}
	return *this;
}

Matrix Matrix::operator+(const Matrix &m)
{
	if ((cols == m.cols) && (rows == m.rows))
	{
		Matrix temp(rows, cols);
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
				temp.matrix[i][j] = matrix[i][j] + m.matrix[i][j];
		}
		return temp;
	}
	else
		return Matrix();
}

Matrix Matrix::operator-(const Matrix &m)
{
	if ((cols == m.cols) && (rows == m.rows))
	{
		Matrix temp(rows, cols);
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
				temp.matrix[i][j] = matrix[i][j] - m.matrix[i][j];
		}
		return temp;
	}
	else
		return Matrix();
}

ofstream& operator<<(ofstream &out, const Matrix &m)
{
	out << m.rows << endl;
	out << m.cols << endl;
	for (int i = 0; i < m.rows; i++)
	{
		for (int j = 0; j < m.cols; j++)
			out << m.matrix[i][j] << " ";
		out << endl;
	}
	return out;
}

ifstream& operator>>(ifstream &in, Matrix &m)
{
	in >> m.rows;
	in >> m.cols;
	m.matrix = new double*[m.rows];
	for (int i = 0; i < m.rows; i++)
	{
		m.matrix[i] = new double[m.cols];
		for (int j = 0; j < m.cols; j++)
			in >> m.matrix[i][j];
	}
	return in;
}

Matrix Matrix::operator*(const Matrix &m)
{
	if (cols == m.rows)
	{
		Matrix temp(rows, m.cols);
		for (int i = 0; i < rows; ++i)
			for (int j = 0; j < m.cols; ++j)
				for (int k = 0; k < cols; ++k)
				{
					temp.matrix[i][j] += matrix[i][k] * m.matrix[k][j];
				}
		return temp;
	}
	else
		return Matrix();
}

Matrix Matrix::operator*(const int &x)
{
	Matrix temp(rows, cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			temp.matrix[i][j] = matrix[i][j] * x;
	}
	return temp;
}

Matrix operator*(const int &x, const Matrix &m)
{
	Matrix temp(m.rows, m.cols);
	for (int i = 0; i < m.rows; i++)
	{
		for (int j = 0; j < m.cols; j++)
			temp.matrix[i][j] = m.matrix[i][j] * x;
	}
	return temp;
}

void Matrix::random()
{
	srand(time(NULL));
	int liczba = (std::rand() % 50) + 7;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			matrix[i][j] = (std::rand() % 10);
		}
	}
}

void Matrix::loadA()
{
	ifstream file;
	file.open("matrixA.txt", ios::in);
	file >> *this;
	file.close();
	cout << "Pomyslnie wczytano macierz a\n";
}

void Matrix::saveA()
{
	ofstream file;
	file.open("matrixA.txt", ios::out);
	file << *this;
	file.close();
	cout << "Pomyslnie zapisano macierz a\n";
}

void Matrix::loadB()
{
	ifstream file;
	file.open("matrixB.txt", ios::in);
	file >> *this;
	file.close();
	cout << "Pomyslnie wczytano macierz b\n";
}

void Matrix::saveB()
{
	ofstream file;
	file.open("matrixB.txt", ios::out);
	file << *this;
	file.close();
	cout << "Pomyslnie zapisano macierz a\n";
}