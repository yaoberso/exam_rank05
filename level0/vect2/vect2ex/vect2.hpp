#ifndef VECT2_HPP
#define VECT2_HPP

#include <iostream>

class vect2 {
	public:
		vect2();
		vect2(int x, int y);
		~vect2();
		vect2(vect2 &other);
		vect2 &operator=(vect2 &other);
		int &operator[](int index);
		int operator[](int index) const;
		vect2 &operator++();
		vect2 operator++(int);
		vect2 &operator--();
		vect2 operator--(int);
		vect2 &operator+=(vect2 &other);
		vect2 operator+(vect2 &other);
		vect2 &operator-=(vect2 &other);
		vect2 operator-(vect2 &other);
		vect2 operator*(vect2 &other);
		vect2 &operator*=(int num);
	private:
		int _x;
		int _y;
};

std::ostream &operator<<(std::ostream &os, vect2 &other);
vect2 operator*(int num, vect2 &other);
#endif

