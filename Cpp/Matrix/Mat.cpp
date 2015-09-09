#include "Mat.hpp"
#include <fstream>
#include <string>
#include <sstream>

namespace roadmap{
Mat::Mat(unsigned int rows, unsigned int colums):
m_rows(rows), m_colums(colums)
{
	m_mat = new double(m_rows * m_colums);
}
Mat::Mat(const Mat& m)
{
	cpy(m);
}

Mat::~Mat()
{
	if(m_mat)
		delete[] m_mat; 
}

Mat& Mat::operator =(const Mat& m){
	cpy(m);
	return *this;
}

Mat Mat::operator *(const Mat& m){
	Mat tmp(m_rows * m.m_colums);

	for(unsigned int i = 0; i < m_rows; ++i)
		for(unsigned int j = 0; j < m_colums; j++){
			for(unsigned int k = 0; k < m_rows; ++k){
				tmp.m_mat[i*m_colums+j] = at(i,j) + m.at(k,j);
		}
			}
	return tmp;
}

Mat Mat::operator +(const Mat& m){
	Mat tmp(m_rows * m.m_colums);
	for(unsigned int i = 0; i < m_rows; ++i)
		for(unsigned int j = 0; j < m_colums; j++)
			tmp.m_mat[i*m_colums+j] = at(i,j) + m.at(i,j);

	
}

Mat Mat::operator -(const Mat& m){
	Mat tmp(m_rows * m.m_colums);
	for(unsigned int i = 0; i < m_rows; ++i)
		for(unsigned int j = 0; j < m_colums; j++)
			tmp.m_mat[i*m_colums+j] = at(i,j) - m.at(i,j);
}

void Mat::cpy(const Mat& m)
{
	this->m_rows = m.m_rows;
	this->m_colums = m.m_colums;

	m_mat = new double(m_rows * m_colums);
	for(int i = 0; i < (m_rows * m_colums); ++i)
		m_mat[i] = m.m_mat[i];	
}

double Mat::at(unsigned int i, unsigned int j) const
{
	return m_mat[i*m_colums+j];
}
}
