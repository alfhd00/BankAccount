#ifndef __ARRAY_H__
#define __ARRAY_H__

#include "HighCreditMember.h"
#include <cstdlib>

using std::cout;
using std::endl;

typedef Member * MEM_PTR;

class Array
{
	private:
		MEM_PTR * arr;
		int arrlen;

		Array(const Array& arr) {}
		Array& operator=(const Array& arr) {}

	public:
		Array(int arrlen = 50) : arrlen(arrlen)
		{
			arr = new MEM_PTR[arrlen];
		}

		MEM_PTR& operator[] (int idx)
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
