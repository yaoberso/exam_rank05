#include "vect2.hpp"

vect2::vect2(): _x(0), _y(0){}
vect2::vect2(int x, int y): _x(x), _y(y){}
vect2::~vect2(){}
vect2::vect2(vect2 &other): _x(other._x), _y(other._y){}
vect2 &vect2::operator=(vect2 &other)
{
	if (this != &other)
	{
		_x = other._x;
		_y = other._y;
	}
	return (*this);
}
int &vect2::operator[](int index)
{
	if(index == 0)
	{
		return (_x);
	}
	return (_y);
}
int vect2::operator[](int index) const
{
	if(index == 0)
	{
		return (_x);
	}
	return (_y);
}
vect2 &vect2::operator++()
{
	_x++;
	_y++;
	return (*this);
}
vect2 vect2::operator++(int)
{
	vect2 temp = *this;
	temp._x++;
	temp._y++;
	return (temp);
}
vect2 &vect2::operator--()
{
	_x--;
	_y--;
	return (*this);
}
vect2 vect2::operator--(int)
{
	vect2 temp = *this;
	temp._x--;
	temp._y--;
	return (temp);
}
vect2 &vect2::operator+=(vect2 &other)
{
	_x += other._x;
	_y += other._y;
	return (*this);
}
vect2 vect2::operator+(vect2 &other)
{
	vect2 temp = *this;
	temp._x += other._x;
	temp._y += other._y;
	return (temp);
}
vect2 &vect2::operator-=(vect2 &other)
{
	_x -= other._x;
	_y -= other._y;
	return (*this);
}
vect2 vect2::operator-(vect2 &other)
{
	vect2 temp = *this;
	temp._x -= other._x;
	temp._y -= other._y;
	return (temp);
}
vect2 &vect2::operator*=(int num)
{
	vect2 temp = *this;
	temp._x *= num;
	temp._y *= num;
	return (temp);
}
vect2 vect2::operator*(vect2 &other)
{
	vect2 temp = *this;
	temp._x *= other._x;
	temp._y *= other._y;
	return (temp);
}
std::ostream &operator<<(std::ostream &os,const vect2 other)
{
	os << "{" << other[0] << ", " << other[1] << "}" << std::endl;
	return (os);
}
vect2 operator*(int num, vect2 &other)
{
	vect2 temp (other);
	temp *= num;
	return (temp);
}