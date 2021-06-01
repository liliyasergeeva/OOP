#include "pch.h"
#include "CppUnitTest.h"

#include "../Lab/Container.h"
#include "../Lab/Matrix.h"
#include "../Lab/Diagonal_matrix.h"
#include "../Lab/Two_dimensional_array.h"
#include "../Lab/Triangular_matrix.h"

#include "../Lab/Container.cpp"
#include "../Lab/Matrix.cpp"
#include "../Lab/Diagonal_matrix.cpp"
#include "../Lab/Two_dimensional_array.cpp"
#include "../Lab/Triangular_matrix.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:

		TEST_METHOD(In_Two_Dim_Test) //Тест проверки ввода двумерного массива
		{
			int** Array = new int* [3];

			for (int i = 0; i < 3; i++) {
				Array[i] = new int[3];
			}

			Array[0][0] = 1;
			Array[0][1] = 2;
			Array[0][2] = 3;
			Array[1][0] = 4;
			Array[1][1] = 0;
			Array[1][2] = 6;
			Array[2][0] = 7;
			Array[2][1] = 5;
			Array[2][2] = 9;

			Two_dimensional_array* T_d_a_Exp = new Two_dimensional_array();

			T_d_a_Exp->Set_Array(Array);

			Two_dimensional_array* T_d_a_Act = new Two_dimensional_array();

			ifstream ifst("../Lab/in_two_dim.txt");

			T_d_a_Act->In_Array(3, ifst);

			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					Assert::AreEqual(T_d_a_Exp->Get_Array()[i][j], T_d_a_Act->Get_Array()[i][j]);
				}
			}
		}
		TEST_METHOD(In_Diagonal_Test) //Тест проверки ввода диагональной матрицы
		{
			int* Array = new int[4];

			Array[0] = 9;
			Array[1] = 7;
			Array[2] = 2;
			Array[3] = 1;

			Diagonal_matrix* D_m_Exp = new Diagonal_matrix();

			D_m_Exp->Set_Array(Array);

			Diagonal_matrix* D_m_Act = new Diagonal_matrix();

			ifstream ifst("../Lab/in_diagonal.txt");

			D_m_Act->In_Array(4, ifst);

			for (int i = 0; i < 4; i++) {
				Assert::AreEqual(D_m_Exp->Get_Array()[i], D_m_Act->Get_Array()[i]);
			}
		}
		TEST_METHOD(In_Triangular_Test) //Тест проверки ввода треугольной матрицы
		{
			int* Array = new int[10];

			Array[0] = 1;
			Array[1] = 2;
			Array[2] = 3;
			Array[3] = 4;
			Array[4] = 5;
			Array[5] = 6;
			Array[6] = 7;
			Array[7] = 8;
			Array[8] = 9;
			Array[9] = 0;

			Triangular_matrix* T_m_Exp = new Triangular_matrix();

			T_m_Exp->Set_Array(Array);

			Triangular_matrix* T_m_Act = new Triangular_matrix();

			ifstream ifst("../Lab/in_triangular.txt");

			T_m_Act->In_Array(4, ifst);

			for (int i = 0; i < 10; i++) {
				Assert::AreEqual(T_m_Exp->Get_Array()[i], T_m_Act->Get_Array()[i]);
			}
		}
		TEST_METHOD(In_Matrix_Test) //Тест проверки ввода матрицы
		{
			int* Array = new int[4];

			Array[0] = 9;
			Array[1] = 7;
			Array[2] = 2;
			Array[3] = 1;

			Matrix* M_Exp = new Diagonal_matrix();

			M_Exp->Set_K_o(BY_COLUMN);
			M_Exp->Set_N(4);

			ifstream ifst("../Lab/in_matrix.txt");

			Matrix* M_Act = Matrix::In_Matrix(ifst);

			Assert::AreEqual((int)M_Exp->Get_K_o(), (int)M_Act->Get_K_o());
			Assert::AreEqual(M_Exp->Get_N(), M_Act->Get_N());

			for (int i = 0; i < 4; i++) {
				Assert::AreEqual(Array[i], ((Diagonal_matrix*)M_Act)->Get_Array()[i]);
			}
		}
		TEST_METHOD(Out_Two_dim_Test)
		{
			int** Array = new int* [3];

			for (int i = 0; i < 3; i++) {
				Array[i] = new int[3];
			}

			Array[0][0] = 1;
			Array[0][1] = 2;
			Array[0][2] = 3;
			Array[1][0] = 4;
			Array[1][1] = 0;
			Array[1][2] = 6;
			Array[2][0] = 7;
			Array[2][1] = 5;
			Array[2][2] = 9;

			Two_dimensional_array* T_d_a_Act = new Two_dimensional_array();

			T_d_a_Act->Set_Array(Array);

			ofstream ofst("../Lab/out_two_dim_act.txt");

			T_d_a_Act->Out_Array(BY_LINE, 3, ofst);

			ifstream ifst_exp("../Lab/out_two_dim_exp.txt");
			ifstream ifst_act("../Lab/out_two_dim_act.txt");

			string Expected;
			getline(ifst_exp, Expected, '\0');
			string Actual;
			getline(ifst_act, Actual, '\0');

			Assert::AreEqual(Expected, Actual);
		}
		TEST_METHOD(Out_Diagonal_Test)
		{
			int* Array = new int[4];

			Array[0] = 9;
			Array[1] = 7;
			Array[2] = 2;
			Array[3] = 1;

			Diagonal_matrix* D_m_Act = new Diagonal_matrix();

			D_m_Act->Set_Array(Array);

			ofstream ofst("../4lab/out_diagonal_act.txt");

			D_m_Act->Out_Array(BY_COLUMN, 4, ofst);

			ifstream ifst_exp("../Lab/out_diagonal_exp.txt");
			ifstream ifst_act("../Lab/out_diagonal_act.txt");

			string Expected;
			getline(ifst_exp, Expected, '\0');
			string Actual;
			getline(ifst_act, Actual, '\0');

			Assert::AreEqual(Expected, Actual);
		}
		TEST_METHOD(Out_Triangular_Test)
		{
			int* Array = new int[9];

			Array[0] = 1;
			Array[1] = 2;
			Array[2] = 3;
			Array[3] = 4;
			Array[4] = 5;
			Array[5] = 6;
			Array[6] = 7;
			Array[7] = 8;
			Array[8] = 9;
			Array[9] = 0;

			Triangular_matrix* T_m_Act = new Triangular_matrix();

			T_m_Act->Set_Array(Array);

			ofstream ofst("../4lab/out_triangular_act.txt");

			T_m_Act->Out_Array(BY_LINE, 4, ofst);

			ifstream ifst_exp("../Lab/out_triangular_exp.txt");
			ifstream ifst_act("../Lab/out_triangular_act.txt");

			string Expected;
			getline(ifst_exp, Expected, '\0');
			string Actual;
			getline(ifst_act, Actual, '\0');

			Assert::AreEqual(Expected, Actual);
		}
		TEST_METHOD(Sum_Test)
		{
			int* Array = new int[4];

			Array[0] = 9;
			Array[1] = 7;
			Array[2] = 2;
			Array[3] = 1;

			Diagonal_matrix* D_m = new Diagonal_matrix();

			D_m->Set_Array(Array);

			Matrix* M = D_m;

			int Sum_Exp = 19;
			int Sum_Act = M->Sum(4);

			Assert::AreEqual(Sum_Exp, Sum_Act);
			Assert::AreEqual(Sum_Exp, Sum_Act);
		}
		TEST_METHOD(Compare_Test)
		{
			int** Array_First = new int* [3];
			int** Array_Second = new int* [3];

			for (int i = 0; i < 3; i++) {
				Array_First[i] = new int[3];
				Array_Second[i] = new int[3];
			}

			Array_Second[0][0] = 0;
			Array_First[0][0] = 1;

			Array_Second[0][1] = Array_First[0][1] = 2;
			Array_Second[0][2] = Array_First[0][2] = 3;
			Array_Second[1][0] = Array_First[1][0] = 4;
			Array_Second[1][1] = Array_First[1][1] = 0;
			Array_Second[1][2] = Array_First[1][2] = 6;
			Array_Second[2][0] = Array_First[2][0] = 7;
			Array_Second[2][1] = Array_First[2][1] = 5;
			Array_Second[2][2] = Array_First[2][2] = 9;

			Two_dimensional_array* T_d_a_First = new Two_dimensional_array();
			Two_dimensional_array* T_d_a_Second = new Two_dimensional_array();

			T_d_a_First->Set_Array(Array_First);
			T_d_a_Second->Set_Array(Array_Second);

			Matrix* M_First = T_d_a_First;

			M_First->Set_N(3);

			Matrix* M_Second = T_d_a_Second;

			M_Second->Set_N(3);

			bool Act = M_First->Compare(*M_Second);
			bool Exp = true;

			Assert::AreEqual(Exp, Act);
		}
		TEST_METHOD(Sort_Test)
		{
			ifstream ifst("../Lab/input.txt");

			Container Cont;

			Cont.In_Container(ifst);

			ofstream ofst("../Lab/sort_act.txt");

			Cont.Sort();

			Cont.Out_Container(ofst);

			ifstream ifst_exp("../Lab/sort_exp.txt");
			ifstream ifst_act("../Lab/sort_act.txt");

			string Exp;
			getline(ifst_exp, Exp, '\0');
			string Act;
			getline(ifst_act, Act, '\0');

			Assert::AreEqual(Exp, Act);
		}
	};
}
