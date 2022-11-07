#define _USE_MATH_DEFINES

#include "math3d.h"
#include <string.h>
#include <math.h>

namespace math3d
{
	float func_angle_to_rad(float angle_value)
	{
		return (angle_value*M_PI / 180);
	}

	// Конструктор
	mat4::mat4(float m11, float m12, float m13,
		float m21, float m22, float m23,
		float m31, float m32, float m33,
		float dx, float dy, float dz)
	{
		_matrix[0][0] = m11;
		_matrix[0][1] = m12;
		_matrix[0][2] = m13;
		_matrix[0][3] = 0.0f;

		_matrix[1][0] = m21;
		_matrix[1][1] = m22;
		_matrix[1][2] = m23;
		_matrix[1][3] = 0.0f;

		_matrix[2][0] = m31;
		_matrix[2][1] = m32;
		_matrix[2][2] = m33;
		_matrix[2][3] = 0.0f;

		_matrix[3][0] = dx;
		_matrix[3][1] = dy;
		_matrix[3][2] = dz;
		_matrix[3][3] = 1.0f;
	}

	// Операция присваивания
	mat4 & mat4::operator = (const mat4 &right)
	{
		memcpy(_matrix, right._matrix, _rank * _rank * sizeof(float));
		return *this;
	}

	// Операция умножения на матрицу
	mat4 mat4::operator * (const mat4 &right)
	{
		mat4 res_mat;
		for (int i = 0; i < _rank; i++)
		{
			for (int j = 0; j < _rank; j++)
			{
				res_mat._matrix[i][j] = 0.0f;

				for (int k = 0; k < _rank; k++)
				{
					res_mat._matrix[i][j] += _matrix[i][k]*right._matrix[k][j];
				}
			}
		}
		return res_mat;
	}

	// Сброс матрицы в единичную
	void mat4::reset()
	{
		memset(_matrix, 0, _rank * _rank * sizeof(float));
		for (int i = 0; i < _rank; i++)
		{
			_matrix[i][i] = 1.0f;
		}
	}

	// Поворот относительно оси Z. Угол в градусах!
	mat4 &mat4::rotateZ(float angle)
	{
		mat4 res(
			cosf(func_angle_to_rad(angle)), sinf(func_angle_to_rad(angle)), 0.0f,
			-sinf(func_angle_to_rad(angle)), cosf(func_angle_to_rad(angle)), 0.0f,
			0.0f, 0.0f, 1.0f
			);

		*this = *this * res;
		return (*this);
	}

	// Поворот относительно оси Y. Угол в градусах!
	mat4 &mat4::rotateY(float angle)
	{
		mat4 res(
			cosf(func_angle_to_rad(angle)), 0.0f, -sinf(func_angle_to_rad(angle)),
			0.0f, 1.0f, 0.0f,
			sinf(func_angle_to_rad(angle)), 0.0f, cosf(func_angle_to_rad(angle))
			);

		*this = *this * res;
		return (*this);
	}

	// Поворот относительно оси X. Угол в градусах!
	mat4 &mat4::rotateX(float angle)
	{
		mat4 res(
			1.0f, 0.0f, 0.0f,
			0.0f, cosf(func_angle_to_rad(angle)), sinf(func_angle_to_rad(angle)),
			0.0f , - sinf(func_angle_to_rad(angle)), cosf(func_angle_to_rad(angle))
			);

		*this = *this * res;
		return (*this);
	}

	// Перенос (сдвиг)
	mat4 &mat4::translate(float x, float y, float z)
	{
		mat4 res;
		res._matrix[3][0] = x;
		res._matrix[3][1] = y;
		res._matrix[3][2] = z;

		*this = *this * res;
		return (*this);
	}

	// Масштабирование
	mat4 &mat4::scale(float x, float y, float z)
	{
		mat4 res(
			x, 0.0f, 0.0f,
			0.0f, y, 0.0f,
			0.0f, 0.0f, z
			);

		*this = *this * res;
		return (*this);
	}

	// Перспективное преобразование вдоль оси X
	mat4 &mat4::perspective(float center)
	{
		mat4 res;
		res._matrix[0][3] = -1/center;
		*this = *this * res;
		return (*this);
	}

	// Конструктор
	vec4::vec4(float x, float y, float z)
	{
		_vector[0] = x;
		_vector[1] = y;
		_vector[2] = z;
		_vector[3] = 1;
	}

	// Операция присваивания
	vec4 & vec4::operator = (const vec4 &right)
	{
		memcpy(_vector, right._vector, _size* sizeof(float));
		return *this;
	}

	// Операция умножения на матрицу
	vec4 vec4::operator * (const mat4 &right)
	{
		vec4 res;
		for (int i = 0; i < _size; i++)
		{
			res._vector[i] = 0;
			for (int j = 0; j < right._rank; j++)
			{
				res._vector[i] += _vector[j] * right._matrix[j][i];
			}
		}
		
		for (int i = 0; i < _size; i++)
		{
			res._vector[i] /= res._vector[_size-1];
		}

		return res;
	}
}