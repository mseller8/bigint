#ifndef BIGINT_HPP_
#define BIGINT_HPP_
#include <iostream>


const int CAPACITY = 400;
class bigint {
public:
	bigint();
	bigint(int chi);
	bigint(const char f[]);
	void debugPrint(std::ostream& c) const;
	friend std::ostream& operator<<(std::ostream& c, const bigint& re);
	bool operator ==(bigint t);
	friend std::istream& operator>>(std::istream& input, bigint& er);
	bigint operator+(const bigint&) const;
private:
	int arr[CAPACITY] = {};
	
};
#endif /* BIGINT_HPP_ */
