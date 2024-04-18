#include "pch.h"
#include "CppUnitTest.h"
#include "../ap_12.2/Source.cpp"
#include <cassert>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Elem* first = NULL;
			Elem* last = NULL;

			for (int i = 1; i <= 5; i++)
				enqueue(first, last, i);

			Info valueToRemove = 1;
			removeValue(first, last, valueToRemove);

			assert(count(first, valueToRemove) == 0);
		}
	};
}
