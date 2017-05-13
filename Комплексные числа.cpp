#include<iostream>
#include<conio.h>
using namespace std;

class Complex         
{
private:
	double re, im;      

public:

	Complex(double real, double imaginary) :re(real), im(imaginary) {}
	
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
		cout << re*c << "," << im*c << endl;
	}

	void operator / (double c)
	{
		cout << re*pow(c, -1) << "," << im*pow(c, -1) << endl;
	}

	Complex operator * (const Complex &c)
	{
		return Complex(re * c.re - im * c.im, re * c.im + im * c.re);
	}
	

	Complex operator / (const Complex &c)
	{
		Complex temp{ 0.0,0.0 };

		double r = c.re * c.re + c.im * c.im;
		if (r == 0)
			exit(1);
	
		temp.re = (re * c.re + im * c.im) / r;
		temp.im = (im * c.re - re * c.im) / r;

		return temp;
	}
	
private:
	
	Complex& operator = (Complex &c)
	{
		re = c.re;
		im = c.im;

		return (*this);
	}
	
	void print(ostream &)
	{
	cout<<"(" << re << ", " << im << ")";
	}
	
	friend ostream & operator << (ostream &,  Complex &);

};


ostream& operator<< (ostream &out,  Complex &c)
{
	c.print(out);
	return out;
}






int main()
{
	double re=0.0, im=0.0;
	int constant=0;
	
	try
	{
		cout << "re=";
		if (scanf_s("%lf", &re))
			cout << endl;
		else throw 1;
	}
	catch (int error)
	{
		exit(1);
	}
	try
	{
		cout << "im=";
		if (scanf_s("%lf", &im))
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
		cout << "re=";
		if (scanf_s("%lf", &re))
			cout << endl;
		else throw 1;
	}
	catch (int error)
	{
		exit(1);
	}
	try
	{
		cout << "im=";
		if (scanf_s("%lf", &im))
			cout << endl;
		else throw 1;
	}
	catch (int error)
	{
		exit(1);
	}
	Complex b(re, im);

	cout << "a = " << a << "; b =" << b << endl;
	
	cout <<"a+b=" << a + b << endl;
	cout <<"a*b=" << a*b << endl;
	cout <<"a-b=" << a - b << endl;
	cout <<"a/b=" << a / b << endl;
	cout << "multiplication and division" << endl;
	cout << "const=" << endl;
	cin >> constant;
	cout << "mult on const" << endl;
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
	cout << "div on const" << endl;
	a / constant;
	
	
	_getch();
	return 0;
}
