#ifndef __ARRAY_H__
#define __ARRAY_H__

#include "HighCreditMember.h"
#include <cstdlib>

using std::cout;
using std::endl;

template <class T>
class Array
{
	private:
		T * arr;
		int arrlen;

		Array(const Array& arr) {}
		Array& operator=(const Array& arr) {}

	public:
		Array(int arrlen = 50) : arrlen(arrlen)
		{
			arr = new T[arrlen];
		}

		T& operator[] (int idx)
		{
			if(idx < 0 || idx >= arrlen)
			{
				cout << "exception : out of index boundary!" << endl;
				exit(1);
			}

			return arr[idx];
		}

		~Array()
		{
			delete []arr;
		}
};
#endif
