//John Hua
//3.19.2019


#include <iostream>
#include <string>
using namespace std;

template <class T>
class MyComplex {

	public:

		MyComplex(); // Constructor (Default)
		MyComplex(T r, T i); // Constructor (Real | Imag)
		MyComplex(T r); // Constructor (Real)

		MyComplex<T> getComplexReal(); // Accessor
		MyComplex<T> getComplexImag(); // Accessor

		void setReal(T r); // Mutator
		void setImag(T i); // Mutator

		void barComplex() { _imag = -_imag; }

		// Math Operations
		MyComplex<T> operator+(const MyComplex<T> data) {
			return MyComplex<T>(_real + data._real,
								_imag + data._imag);
		}

		MyComplex<T> operator-(const MyComplex<T> data) {
			return MyComplex<T>(_real - data._real,
							    _imag - data._imag);
		}

		MyComplex<T> operator*(const MyComplex<T> data) {
			return MyComplex<T>(_real * data._real,
							    _imag * data._imag);
		}


		friend ostream& operator<< (ostream& output, MyComplex<T> c) {
			if (c._imag < 0.0 && c._real != 0.0) {
				output << c._real << "-" << (c._imag = abs(c._imag)) << 'i';
				return output;
			}
			if (c._imag == 0.0 && c._real == 0.0) {
				output << c._real;
				return output;
			}
			else if (c._imag == 0.0) {
				output << c._real;
				return output;
			}
			else if (c._real == 0.0) {
				output << c._imag << 'i';
				return output;
			}
			output << c._real << "+" << c._imag << 'i';
			return output;
		}

		friend istream& operator>> (istream& input, MyComplex<T> &c) {
			input >> c._real;
			input >> c._imag;
			return input;
		}

	private:
		T _real, _imag;
};


// Constructors
template <class T>  MyComplex<T>::MyComplex() { 
	_real = 0.0;
	_imag = 0.0;
}

template <class T>  MyComplex<T>::MyComplex(T r, T i) {
	this->_real = r;
	this->_imag = i;
}

template <class T>  MyComplex<T>::MyComplex(T r) {
	this->_real = r;
	_imag = 0.0;
}

// Accessor and Mutator Functions
template <class T> void  MyComplex<T>::setReal(T r) {
	_real = r;
}

template <class T> void  MyComplex<T>::setImag(T i) {
	_imag = i;
}
template <class T> MyComplex<T> MyComplex<T>::getComplexReal()  {
	return _real;
}
template <class T> MyComplex<T> MyComplex<T>::getComplexImag() {
	return _imag;
}


int main() {

	// Testing Constructors
	MyComplex<int>
		c1,
		c2(1, 2),
		c3(3),
		c4(0, -5),
		c5(2, 3);


	cout << "c1 == " << c1 << endl;
	cout << "c2 == " << c2 << endl;
	cout << "c3 == " << c3 << endl;
	cout << "c4 == " << c4 << endl;
	cout << "c5 == " << c5 << endl << endl;

	// Testing Mutator Functions
	c3.setReal(5);
	c3.setImag(-4);

	cout << c3 << endl << endl;

	// Testing Accessor Functions
	cout << "c2 Real == " << c2.getComplexReal() << ", " << "c2 Imag == " << c2.getComplexImag() << endl << endl;


	// Testing Math Functions
	MyComplex<int> c6, c7, c8;
	c6 = c4 + c5;
	cout << "c4 + c5 == " << c6 << endl;
	c7 = c4 - c5;
	cout << "c4 - c5 == " << c7 << endl;
	c8 = c4 * c5;
	cout << "c4 * c5 == " << c8 << endl << endl;


	// Testing istream operator and conjugate function
	MyComplex<int> c9;
	cout << "Enter a complex number: ";
	cin >> c9;

	cout << "c9 == " << c9 << endl;

	c9.barComplex();
	cout << "Conjugate of c9 == " << c9 << endl << endl;

	MyComplex<double> c10(4.5, 3.7);
	cout << "Testing template class with data-type of double: " << c10 << endl;

	//MyComplex<string> c11("Hi", "me");
	//cout << "Testing template class with data-type of double: " << c11 << endl;

	return 0;
}
