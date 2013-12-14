#include "Matrix4.h"
#include <cmath>
#include <cstring>
#include "ToStdString.h"

const double PI = 3.1415926535;

Matrix4::Matrix4()
{
	memset(m_coef,0,nb_coef*sizeof(double));
}

Matrix4::Matrix4(double* coef)
{
	memcpy(m_coef,coef,nb_coef*sizeof(double));
}


Matrix4::Matrix4(const Matrix4& mat)
{
	memcpy(m_coef,mat.m_coef,nb_coef*sizeof(double));
}


Matrix4& Matrix4::operator=(const Matrix4& mat)
{
	memcpy(m_coef,mat.m_coef,nb_coef*sizeof(double));
	return *this;
}


Matrix4 Matrix4::operator+(const Matrix4& mat) const
{
	Matrix4 tmp(*this);
	tmp += mat;
	return tmp;
}


Matrix4 Matrix4::operator-(const Matrix4& mat) const
{
	Matrix4 tmp(*this);
	tmp -= mat;
	return tmp;
}


Matrix4& Matrix4::operator+=(const Matrix4& mat)
{
	for(int i=0;i<nb_coef;i++)
	{
		m_coef[i] += mat.m_coef[i];
	}
	return *this;
}


Matrix4& Matrix4::operator-=(const Matrix4& mat)
{
	for(int i = 0 ; i<nb_coef ; i++ )
	{
		m_coef[i] -= mat.m_coef[i];
	}
	return *this;
}

bool Matrix4::operator==(const Matrix4& mat) const
{
	bool ret = true;
	for(int i = 0 ; ( i<nb_coef && ret==true ) ; i++ )
	{
		if(m_coef[i] != mat.m_coef[i]) ret = false;
	}
	return ret;
}

bool Matrix4::operator!=(const Matrix4& mat) const
{
	bool ret = true;
	for(int i = 0 ; ( i<nb_coef && ret==true ) ; i++ )
	{
		if(m_coef[i] == mat.m_coef[i]) ret = false;
	}
	return ret;

}


Matrix4 Matrix4::operator*(const Matrix4& mat) const
{
	Matrix4 tmp(*this);

	for(int k =0 ; k < matrix_dim; k++)
	{
		for(int j = 0 ; j < matrix_dim; j++)
		{
			tmp.m_coef[matrix_dim * j + k] = 0;

			for(int i = 0 ; i < matrix_dim; i++)
			{
				tmp.m_coef[matrix_dim * j + k] += m_coef[matrix_dim * j + i] * mat.m_coef[matrix_dim * i + k];
			}
		}
	}

	return tmp;
}


Matrix4& Matrix4::operator*=(const Matrix4& mat)
{
	(*this) = this->operator*(mat);
	return (*this);
}

Vector3 Matrix4::operator*(const Vector3& vect) const
{
	Vector3 ret;
	Matrix4 left(*this);
	Matrix4 right;
	right.m_coef[matrix_dim * 0] = vect.x;
	right.m_coef[matrix_dim * 1] = vect.y;
	right.m_coef[matrix_dim * 2] = vect.z;
	right.m_coef[matrix_dim * 3] = 1.0;

	left*= right;

	ret.x = left.m_coef[matrix_dim * 0];
	ret.y = left.m_coef[matrix_dim * 1];
	ret.z = left.m_coef[matrix_dim * 2];

	ret /= left.m_coef[matrix_dim * 3];

	return ret;
}

Point3 Matrix4::operator*(const Point3& point) const
{
	Point3 ret;
	Matrix4 left(*this);
	Matrix4 right;
	right.m_coef[matrix_dim * 0] = point.x;
	right.m_coef[matrix_dim * 1] = point.y;
	right.m_coef[matrix_dim * 2] = point.z;
	right.m_coef[matrix_dim * 3] = 1.0;

	left*= right;

	double w = left.m_coef[matrix_dim * 3];

	ret.x = left.m_coef[matrix_dim * 0]/w;
	ret.y = left.m_coef[matrix_dim * 1]/w;
	ret.z = left.m_coef[matrix_dim * 2]/w;

	return ret;
}

Matrix4 Matrix4::operator/(double scalar) const
{
	Matrix4 tmp(*this);
	tmp /= scalar;
	return tmp;
}


Matrix4& Matrix4::operator/=(double scalar)
{
	for(int i = 0 ; i<nb_coef ; i++ )
	{
		m_coef[i] /= scalar;
	}
	return *this;
}


Matrix4 Matrix4::operator*(double scalar) const
{
	Matrix4 tmp(*this);
	tmp *= scalar;
	return tmp;
}


Matrix4& Matrix4::operator*=(double scalar)
{
	for(int i = 0 ; i<nb_coef ; i++ )
	{
		m_coef[i] *= scalar;
	}
	return *this;
}


Matrix4& Matrix4::loadIdentity()
{
	for(int j = 0 ; j < matrix_dim; j++)
	{
		for(int i = 0 ; i < matrix_dim; i++)
		{
			if(i==j) m_coef[matrix_dim * j + i] = 1.0;
			else     m_coef[matrix_dim * j + i] = 0.0;
		}
	}
	return (*this);
}


Matrix4& Matrix4::translate(const Vector3& vect)
{
	return ((*this)*=translationMatrix(vect));
}


Matrix4& Matrix4::rotate(double angle,const Vector3& axe)
{
	return ((*this)*=rotationMatrix(angle,axe));
}


Matrix4& Matrix4::scale(double scaleX,double scaleY,double scaleZ)
{
	return ((*this)*=scaleMatrix(scaleX,scaleY,scaleZ));
}

Matrix4 Matrix4::translationMatrix(const Vector3& vect)
{
	Matrix4 translationMatrix;
	translationMatrix.loadIdentity();
	translationMatrix.m_coef[matrix_dim * 0 + 3] = vect.x;
	translationMatrix.m_coef[matrix_dim * 1 + 3] = vect.y;
	translationMatrix.m_coef[matrix_dim * 2 + 3] = vect.z;
	return translationMatrix;

}

Matrix4 Matrix4::rotationMatrix(double angle,const Vector3& axe)
{
	    Matrix4 rotationMatrix;
	    rotationMatrix.loadIdentity();
	    angle = angle * PI / 180.0;

	    Vector3 normalize_axe = axe / axe.norme();
		//printf("axe \n%s\n",axe.toStdString().c_str());

	    double c = cos(angle);
	    double t = 1 - c;
	    double s = sin(angle);
	    double x = normalize_axe.x;
	    double y = normalize_axe.y;
	    double z = normalize_axe.z;


	    rotationMatrix.m_coef[ 0]  = x*x*t + c;
	    rotationMatrix.m_coef[ 1]  = x*y*t - z*s;
	    rotationMatrix.m_coef[ 2]  = x*z*t + y*s;
	    rotationMatrix.m_coef[ 3]  = 0;

	    rotationMatrix.m_coef[ 4]  = x*y*t + z*s;
	    rotationMatrix.m_coef[ 5]  = y*y*t + c;
	    rotationMatrix.m_coef[ 6]  = y*z*t - x*s;
	    rotationMatrix.m_coef[ 7]  = 0;

	    rotationMatrix.m_coef[ 8]  = x*z*t - y*s;
	    rotationMatrix.m_coef[ 9]  = y*z*t + x*s;
	    rotationMatrix.m_coef[10]  = z*z*t + c;
	    rotationMatrix.m_coef[11]  = 0;

	    rotationMatrix.m_coef[12]  = 0;
	    rotationMatrix.m_coef[13]  = 0;
	    rotationMatrix.m_coef[14]  = 0;
	    rotationMatrix.m_coef[15]  = 1;

		//printf("rot \n%s\n",rotationMatrix.toStdString().c_str());

	    return rotationMatrix;
}

Matrix4 Matrix4::scaleMatrix(double scaleX,double scaleY, double scaleZ)
{
	Matrix4 scaleMatrix;
	scaleMatrix.loadIdentity();
	scaleMatrix.m_coef[matrix_dim * 0 + 0] = scaleX;
	scaleMatrix.m_coef[matrix_dim * 1 + 1] = scaleY;
	scaleMatrix.m_coef[matrix_dim * 2 + 2] = scaleZ;
	return scaleMatrix;
}


Matrix4 Matrix4::identityMatrix()
{
	return Matrix4().loadIdentity();
}

std::string Matrix4::toStdString() const
{
	std::string out;
	for(int j = 0 ; j < matrix_dim; j++)
	{
		for(int i = 0 ; i < matrix_dim; i++)
		{
			out+= "coef["+tostr(i)+","+tostr(j)+"]="+tostr(m_coef[matrix_dim * j + i])+" ";
		}
		out+= "\n";
	}

	return out;
}
