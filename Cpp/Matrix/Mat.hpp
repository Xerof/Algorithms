#ifndef MAT_HPP
#define MAT_HPP
namespace roadmap{
class Mat{
	public:
		//Constructor
		Mat(unsigned int rows=1, unsigned int colums=1);
		// Copy Constructor
		Mat(const Mat& m);
		Mat& operator =(const Mat& m);
		Mat operator *(const Mat& m);
		Mat operator +(const Mat& m);
		Mat operator -(const Mat& m);
		~Mat();
	protected:
		void cpy(const Mat& m);
		double at(unsigned int i, unsigned int j)const;
		double *m_mat;
		unsigned int m_rows;
		unsigned int m_colums;
		
};
}
#endif
