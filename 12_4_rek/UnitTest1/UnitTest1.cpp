#include "pch.h"
#include "CppUnitTest.h"
#include "../12_4_rek/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MyUnitTests
{
    TEST_CLASS(MyTests)
    {
    public:

        TEST_METHOD(TestIsPartOf)
        {
           
            Elem* L1 = NULL;
            insert(L1, 2);
            insert(L1, 4);
            insert(L1, 6);

           
            Elem* L2 = NULL;
            insert(L2, 1);
            insert(L2, 2);
            insert(L2, 3);
            insert(L2, 4);
            insert(L2, 5);
            insert(L2, 6);
            insert(L2, 7);

       
            bool result = isPartOf(L1, L2);

            
            Assert::IsTrue(result);

            
            while (L1 != NULL) {
                remove(L1);
            }
            while (L2 != NULL) {
                remove(L2);
            }
        }

    };
}
