template<typename T>
class Matrix44
{
public:
	Matrix44() {}
	
	const T* operator [] (uint8_t i) const { return m[i]; }
	T* operator [] (uint8_t i) { return m[i]; }
	
	Matrix44 operator * (const Matrix44& rhs) const
	{
		Matrix mult;
		for (uint8_t i = 0; i<4; ++i) {
			for (uint8_t j = 0; j<4; ++j) {
				mult[i][j] = m[i][0] * rhs[0][j] +
							 m[i][1] * rhs[1][j] +
							 m[i][2] * rhs[2][j] +
							 m[i][3] * rhs[3][j];
			}
		}
		
		return mult;
	}
	
	void multVecMatrix(const Vec3<T> &src, Vec3<T> &dst) const; // transform point in vector form
	void multDirMatrix(const Vec3<T> &src, Vec3<T> &dst) const; // transport direction in vector form

private:
		T m[4][4] = {{1,0,0,0},
				 {0,1,0,0},
				 {0,0,1,0},
				 {0,0,0,1}};
};

typedef Matrix44<float> Matrix44f;


