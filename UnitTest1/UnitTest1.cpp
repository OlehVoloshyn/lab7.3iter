#include "pch.h"
#include "CppUnitTest.h"
#include "../lab7.3/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int t,k;
			const int rowCount = 15;
				const int colCount=15;
			int** a = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				a[i] = new int[colCount];

			t = ZeroElem(a, rowCount, colCount, 0);
			Assert::AreEqual(t, 0);


		}

	};
}
