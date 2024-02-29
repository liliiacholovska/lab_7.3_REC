#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab7.3(2)/lab7.3(2).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(TestCreateRows)
        {
            int n = 2;
            int Low = 1, High = 2;
            int** a = new int* [n];
            for (int i = 0; i < n; i++)
                a[i] = new int[n];
            CreateRows(a, n, n, Low, High, 0);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    Assert::IsTrue(a[i][j] >= Low && a[i][j] <= High);
                }
            }
            for (int i = 0; i < n; i++) delete[] a[i];
            delete[] a;
        }

        TEST_METHOD(TestPrintRows)
        {
            int n = 2;
            int Low = 1, High = 2;
            int** testMatrix = new int* [n];
            for (int i = 0; i < n; i++)
                testMatrix[i] = new int[n];
            CreateRows(testMatrix, n, n, Low, High, 0);
            stringstream buffer;
            streambuf* prevCoutBuf = cout.rdbuf(buffer.rdbuf());
            PrintRows(testMatrix, n, n, 0);
            cout.rdbuf(prevCoutBuf);
            for (int i = 0; i < n; i++) delete[] testMatrix[i];
            delete[] testMatrix;
        }

        TEST_METHOD(TestRotate90DegreesRec)
        {
            const int n = 4; 
            int numberOfRepetitions = 1;
            int** matrix = new int* [n];
            for (int i = 0; i < n; i++) {
                matrix[i] = new int[n];
                for (int j = 0; j < n; j++) {
                    matrix[i][j] = i * n + j; 
                }
            }
            int expected[n][n] = { {12, 8, 4, 0}, {13, 9, 5, 1}, {14, 10, 6, 2}, {15, 11, 7, 3} };
            Rotate90DegreesRec(matrix, n, numberOfRepetitions);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    Assert::AreEqual(expected[i][j], matrix[i][j]);
                }
            }
            for (int i = 0; i < n; i++) delete[] matrix[i];
            delete[] matrix;
        }

        TEST_METHOD(TestColumnWithMostZerosRec)
        {
            const int n = 3; 
            int** matrix = new int* [n];
            for (int i = 0; i < n; i++) {
                matrix[i] = new int[n];
                for (int j = 0; j < n; j++) {
                    matrix[i][j] = 1; 
                }
            }
            matrix[0][1] = 0;
            matrix[1][1] = 0;
            matrix[2][2] = 0; 
            int colWithMostZeros = ColumnWithMostZerosRec(matrix, n);
            Assert::AreEqual(1, colWithMostZeros); 
            for (int i = 0; i < n; i++) delete[] matrix[i];
            delete[] matrix;
        }
	};
}