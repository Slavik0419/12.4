#include "pch.h" 
#include "CppUnitTest.h"
#include "../lab_12_4_it/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:

		TEST_METHOD(Test_isPartOf)
		{
			
			Elem* L1 = nullptr;
			Elem* L2 = nullptr;

			
			insert(L1, 1);
			insert(L1, 2);
			insert(L1, 3);

			insert(L2, 1);
			insert(L2, 2);
			insert(L2, 3);
			insert(L2, 4);
			insert(L2, 5);

			
			bool result1 = isPartOf(L1, L2);

			remove(L1);
			remove(L1);
			remove(L1);

			insert(L1, 2);
			insert(L1, 1);

			bool result2 = isPartOf(L1, L2);

			
			Assert::IsTrue(result1);
			Assert::IsFalse(result2);

			
			while (L1 != nullptr) {
				remove(L1);
			}
			while (L2 != nullptr) {
				remove(L2);
			}
		}
	};
}
