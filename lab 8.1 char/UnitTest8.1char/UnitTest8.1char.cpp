#include "pch.h"
#include "CppUnitTest.h"
#include "../lab 8.1 char/lab 8.1 char.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest81char
{
	TEST_CLASS(UnitTest81char)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			char str1[] = "abc.def.ghi.jkl.mno"; // �������� � ���� ������ �� ������ 3
			int index1 = FindFourthDotFromEnd(str1);
			Assert::AreEqual(3, index1);

			char str2[] = "abc.def.ghi"; // ����� �� 4 ������, �� ��������� -1
			int index2 = FindFourthDotFromEnd(str2);
			Assert::AreEqual(-1, index2);

			char str3[] = "a.b.c.d.e.f.g.h"; // �������� � ���� ������ �� ������ 6
			int index3 = FindFourthDotFromEnd(str3);
			Assert::AreEqual(6, index3);
		}
	};
}
