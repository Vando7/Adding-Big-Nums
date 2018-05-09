#include"bint.h"
#include<iostream>
#include<cstring>

//
// Construction work.
//
bint::bint()
	:
	isNegative(false),
	value(nullptr),
	size(0)
{
	value = new short[1];
	value[0] = 0;
}


bint::bint(const bint& a)
	:
	value(nullptr)
{
	if (this != &a) {
		this->value = new short[a.size];
		this->size = a.size;

		for (int i = 0; i < size; ++i)
			this->value[i] = a.value[i];
	}
}


bint::bint(const bint &a, bool rem)

	:
	value(nullptr)
{

		this->value = new short[a.size+1];
		this->size = a.size+1;

		for (int i = 1; i < size; ++i)
			this->value[i] = a.value[i-1];

		this->value[0] = 1;
}


bint::~bint() {
	delete[] value;
	value = nullptr;
}


bint bint::operator+(bint &a)
{
	bint& b = *this;
	bint temp;
	short
		sizeA = a.size ,
		sizeB = b.size ,
		sizeTmp = sizeA > sizeB ? sizeA : sizeB;

	temp.allocate(sizeTmp);
	for (int i = 0;i < sizeTmp; ++i)
		temp[i] = 0;

	--sizeTmp;
	--sizeA;
	--sizeB;

	bool rem = 0;

	while (sizeA >= 0 && sizeB >= 0 && sizeTmp >= 0) {
		temp[sizeTmp] = b[sizeB] + a[sizeA] + rem;
		rem = 0;

		if (temp[sizeTmp] >= 10) {
			rem = 1;
			temp[sizeTmp] %= 10;
		}

		--sizeA;
		--sizeB;
		--sizeTmp;
	}

	if (rem) {
		bint c(temp, rem);
 		return c;
	}

	return temp;
}


short & bint::operator[](unsigned short index)
{
	return value[index];
}


void bint::setSize(short _size)
{
	size = _size;
}


//
// Set value.
//
void bint::setValue(const char* input) {
	if (input[0] == '-')
		isNegative = true;

	size = strlen(input)- isNegative;

	delete[] value;
	value = nullptr;
	value = new short[size];

	for (short i = size-1+isNegative; i >= isNegative; --i) {
		value[i-isNegative] = input[i] - '0';
	}

	if (isNegative)
		value[0] *= -1;
}


//
// Get value.
//
void bint::print()
{
	for (int i = 0; i < size; ++i)
		std::cout << value[i];
}


void bint::allocate(short _size)
{
	delete[] value;
	value = nullptr;
	value = new short[_size];
	size = _size;
}
