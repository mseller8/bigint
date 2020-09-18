#include "bigint.hpp"

bigint::bigint()
{	
	
}

bigint::bigint(int chi)
{
	for (int i = 0; chi != 0; i++) {
		arr[i] = chi % 10;
		chi = chi / 10;
	}
}

bigint::bigint(const char f[])
{
	int i = 0;
	for (; f[i] != '\0'; i++) {
	}
	i--;
	for (int j = 0; i > -1; i--,j++) {
		arr[j] = f[i]-48;
	}
}

void bigint::debugPrint(std::ostream& c) const
{
	for (int i = CAPACITY - 1; i >= 0 ; i--)
		c << arr[i] << "|";
}

bool bigint::operator==(bigint t)
{
	for (int i = CAPACITY - 1; i >= 0; i--) {
		if (t.arr[i] != arr[i])
			return false;
	}
	return true;
}

bigint bigint::operator+(const bigint&) const
{
	return bigint();
}

std::ostream& operator<<(std::ostream& c, const bigint& re)
{
	bool foundNum = false;
	int count = 0;
	for (int i = CAPACITY - 1; i >= 0; i--) {
		if (re.arr[i] != 0) {
			foundNum = true;
		}
		if (foundNum) {
			c << re.arr[i];
			++count;
			if (count % 80 == 0)
				c << "\n";
		}
		if (!foundNum && i == 0) {
			c << 0;
		}
	}
	return c;
}

std::istream& operator>>(std::istream& input, bigint& er)
{
	int x;
	int size;
	for(int i = CAPACITY - 1; i >= 0; i--){
		input >> x;
		if (x == 59)
			break;
		er.arr[i] = x;
		size = CAPACITY - i;
	}	
	for (int i = 0; i < size; i++) {
		er.arr[i] = er.arr[i +(CAPACITY - size)];
	}
	return input;
}
