#pragma once


class bint {
public:
	bint();
	bint(const bint&);
	bint(const bint&,bool);

	~bint();

	bint operator+(bint&);
	short& operator[](unsigned short);

	void setSize(short);
	void setValue(const char*);
	void print();
	void allocate(short);

private:

	short* value;
	bool isNegative;
	short size;
};
