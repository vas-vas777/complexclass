#include<iostream>
#include<cmath>
#include<conio.h>
using namespace std;

class Complex         
{
private:
	double re, im;      

public:

	Complex()
	{
	};


	Complex(double r, double i)
	{
		re = r;
		im = i;
	}

	Complex(const Complex &c)  
	{
		re = c.re;
		im = c.im;
	}

	

	

	
	Complex& operator = (Complex &c)
	{
		re = c.re;
		im = c.im;

		return (*this);
	}


	
	
	
	Complex operator + (const Complex &c)
	{
		return Complex(re + c.re, im + c.im);
	}

	
	Complex operator - (const Complex &c)
	{
		return Complex(re - c.re, im - c.im);
	}

	
	void operator * (int c)
	{
		std::cout << re*c << "," << im*c << std::endl;
	}

	void operator / (double c)
	{
		std::cout << re*pow(c, -1) << "," << im*pow(c, -1) << std::endl;
	}

	Complex operator * (const Complex &c)
	{
		return Complex(re * c.re - im * c.im, re * c.im + im * c.re);
	}
	

	Complex operator / (const Complex &c)
	{
		Complex temp;

		double r = c.re * c.re + c.im * c.im;
		temp.re = (re * c.re + im * c.im) / r;
		temp.im = (im * c.re - re * c.im) / r;

		return temp;
	}

	
	friend ostream & operator<< (ostream &, const Complex &);
	friend istream & operator >> (istream &, Complex &);

};


ostream& operator<< (ostream &out, const Complex &c)
{
	out << "(" << c.re << ", " << c.im << ")";
	return out;
}


istream& operator >> (istream &in, Complex &c)
{
	in >> c.re >> c.im;
	return in;
}

int main()
{
	auto re=0, im=0;
	int constant;
	
	try
	{
		cout << "re=" << endl;
		if (scanf_s("%d", &re))
			cout << endl;
		else throw 1;
	}
	catch (int error)
	{
		exit(1);
	}
	try
	{
		cout << "im=" << endl;
		if (scanf_s("%d", &im))
			cout << endl;
		else throw 1;
	}
	catch (int error)
	{
		exit(1);
	}
	Complex a(re, im);
	try
	{
		cout << "re=" << endl;
		if (scanf_s("%d", &re))
			cout << endl;
		else throw 1;
	}
	catch (int error)
	{
		exit(1);
	}
	try
	{
		cout << "im=" << endl;
		if (scanf_s("%d", &im))
			cout << endl;
		else throw 1;
	}
	catch (int error)
	{
		exit(1);
	}
	Complex b(re, im);

	cout << "a = " << a << "; b =" << b << endl;
	
	cout << a + b << endl;
	cout << a*b << endl;
	cout << a - b << endl;
	cout << "multiplication and devision" << endl;
	cout << "const=" << endl;
	cin >> constant;
	a*constant;
	try
	{
		
		if (constant != 0)
			cout << endl;
		else throw 1;
	}
	catch (int error)
	{
		_getch();
		exit(1);
	}
	
	a / constant;
	
	
	_getch();
	return 0;
	
}
