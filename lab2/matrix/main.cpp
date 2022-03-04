#include "matrixConstructors.h"
#include "matrixMethods.h"
#include "matrixOperators.h"
#include "matrixFriendOperators.h"

#include <iostream>
using namespace std;

void constructors();
void methods();
void operators();
void iterators();

int main()
{
    int choose = 0;
    while (choose != 5) {
        cout << "Конструкторы......1\n";
        cout << "Методы............2\n";
        cout << "Оперторы..........3\n";
        cout << "Итераторы.........4\n";
        cout << "Выход.............5\n";

        cin >> choose;

        if (choose == 1) {
            constructors();
        }

        if (choose == 2) {
            methods();
        }

        if (choose == 3) {
            operators();
        }

        if (choose == 4) {
            iterators();
        }
    }
    return 0;
}

void constructors()
{
    cout << "________Конструкторы________\n";

    try {
        cout << "Инициализация с параметрами\n";
        Matrix<double> matrPar(2, 3);
        cout << matrPar;

        cout << "Инициализация вектором\n";
        Matrix<double> matrListSimple({1.3, 3.5, 2.8, 8.4});
        cout << matrListSimple;

        cout << "Инициализация списком\n";
        Matrix<int> matrList({ {1, 0, 12}, {6, 2, 8}, {2, 6, 2} });
        cout << matrList;

        cout << "Инициализация итераторами\n";
        IteratorMatr<int> begin = matrList.begin();
        IteratorMatr<int> end = matrList.end();
        Matrix<int> matr(begin, end);
        cout << matr;

        cout << "Конструктор копирования\n";
        Matrix<int> matrCopy(matrList);
        cout << matrCopy;
    }

    catch(MatrixErrors& error) {
        cout << endl << error.what() << endl;
    }
}

void methods()
{
    cout << "________Методы________\n";

    try {
        Matrix<double> matr({ {4.2, 5.2, 6.9}, {2.8, 4.2, 6.2} });
        Matrix<double> matr1({ {1, 2}, {7, 3} });

        cout << "Элемент\n";
        matr.setElem(1, 2, 14);
        matr.output();
        cout << "matr[0][1] = " << matr.getElem(0, 1) << endl;
        cout << "matr[0][0] = " << matr(0, 0) << endl;
        cout << "matr[1][2] = " << matr[1][2] << endl << endl;

        cout << "Размеры\n";
        if (matr.isSquare()) {
            cout << "Квадратная\n";
        } else {
            cout << "Прямоугольная\n";
        }
        cout << "n = " << matr.getRowsNum();
        cout << " m = " << matr.getColumnsNum() << endl;

        cout << "Определитель: " << matr1.determinant() << endl << endl;

        cout << "Транспонирование\n";
        matr1.transponse();
        cout << matr1;

        cout << "Обратная\n";
        matr1.inverse();
        cout << matr1;
    }

    catch(MatrixErrors& error) {
        cout << endl << error.what() << endl;
    }
}

void operators()
{
    cout << "________Операторы________\n";

    try {
        Matrix<double> matrD({ {1.23, 4.21, 5.4}, {2.45, 9.04, 6.86} });
        Matrix<int> matrI(3, 5);

        cout << "Оператор присваивания\n";
        Matrix<double> matrCopy(1, 1);
        matrCopy = matrD;
        cout << matrCopy;

        cout << "Оператор +\n";
        Matrix<int> matrAdd1({ {1, 3, 6}, {5, 9, 2} });
        Matrix<int> matrAdd2({ {1, 1, 1}, {1, 1, 1} });

            cout << "\tМатрица\n";
            matrAdd1.sum(matrAdd2);
            matrAdd1 + matrAdd2;
            matrAdd1 += matrAdd2;
            matrI = matrAdd1 + matrAdd2;

            cout << "\tЧисло\n";
            matrI.sum(3);
            matrI + 4;
            matrI += 1;
            matrI = matrAdd2 + 3;

        cout << "Оператор -\n";

            cout << "\tМатрица\n";
            matrAdd1.sub(matrAdd2);
            matrAdd1 - matrAdd2;
            matrAdd1 -= matrAdd2;
            matrI = matrAdd1 - matrAdd2;

            cout << "\tЧисло\n";
            matrI.sub(2);
            matrI - 4;
            matrI -= 1;
            matrI = matrAdd2 - 2;

        cout << "Оператор *\n";
        Matrix<double> matrMul1({ {1, 3, 6}, {5, 9, 2}, {2, 4, 0} });
        Matrix<double> matrMul2({ {2, 2, 2}, {2, 2, 2}, {2, 2, 2} });

            cout << "\tМатрица\n";
            matrMul1.mul(matrMul2);
            matrMul1 * matrMul2;
            matrMul1 *= matrMul2;
            matrD = matrMul1 * matrMul2;

            cout << "\tЧисло\n";
            matrMul1.mul(2);
            matrMul1 * 0.5;
            matrMul1 *= 2;
            matrD = matrMul2 * 0.5;

        cout << "Оператор /\n";
        Matrix<double> matrDiv({ {1, 3, 6}, {5, 9, 2}, {2, 4, 0} });
        matrDiv.div(0.5);
        matrDiv / 2;
        matrDiv /= 0.5;
        matrDiv = matrMul2 / 2;

        cout << "Оператор ^\n";
        matrDiv.pow(2);
        matrD = matrDiv^2;

        cout << "Эквивалентность\n";
        Matrix<int> matr1(2, 3);
        Matrix<int> matr2(2, 3);
        Matrix<int> matr3({ {1, 1, 1}, {1, 1, 1} });

        if (matr1 == matr2) {
            cout << "Are equal\n";
        }
        if (matr1 != matr3) {
            cout << "Are not equal\n";
        }
        if (matr1.areEqual(matr2)) {
            cout << "Are equal\n";
        }
    }

    catch(MatrixErrors& error) {
        cout << endl << error.what() << endl;
    }
}

void iterators()
{
    cout << "________Итераторы________\n";

    try {
        //IteratorMatr<int> it;
        Matrix<double> matr({ {1, 2}, {3.2, 5} });
        IteratorMatr<double> it1 = matr.createIterator();
        cout << it1.value() << " ";
        it1++;
        ++it1;
        cout << it1.value() << " ";

        IteratorMatr<double> itCopy(it1);
        itCopy.begin();
        cout << itCopy.value() << " ";

        itCopy.next();
        cout << itCopy.value() << " ";

        itCopy.previous();
        cout << itCopy.value() << " ";

        itCopy--;
        cout << itCopy.value() << " ";

        itCopy.end();
        --itCopy;
        cout << itCopy.value() << endl;

        cout << itCopy.isEnd() << " ";
        cout << itCopy.isRowEnd() << endl;

        IteratorMatr<double> it2 = itCopy;
        //it2 = itCopy;
        if (it2 == itCopy) {
            cout << "Equal\n";
        }
        if (it1 != itCopy) {
            cout << "Not equal\n";
        }

        const Matrix<double> matrConst({{1, 2}, {9, 3}});
        ConstIteratorMatr<double> itConst1 = matrConst.createIterator();
        cout << itConst1.value() << " ";

        itConst1.next();
        cout << itConst1.value() << " ";

        itConst1.begin();
        cout << itConst1.value() << " ";

        itConst1.end();
        itConst1.previous();
        cout << itConst1.value() << endl;

        cout << itConst1.isEnd() << " " << itConst1.isRowEnd() << endl;

        ConstIteratorMatr<double> itConst2(itConst1);
        if (itConst2 == itConst1) {
            cout << "Equal\n";
        }
        itConst1.next();
        if (itConst2 != itConst1) {
            cout << "Not equal\n";
        }

        IteratorMatr<double> itm = matr.createIterator();
        cout << itm.value() << " ";
        ConstIteratorMatr<double> itmc = matrConst.createIterator();
        cout << itmc.value() << " ";

        IteratorMatr<double> itmb = matr.begin();
        cout << itmb.value() << " ";

        IteratorMatr<double> itme = matr.end();
        itme--;
        cout << itme.value() << " ";
        //ConstIteratorMatr<double> itmce = matr.end();

        ConstIteratorMatr<double> itmccb = matr.c_begin();
        cout << itmccb.value() << " ";
        ConstIteratorMatr<double> itmcce = matr.c_end();
        itmcce.previous();
        cout << itmcce.value() << endl;
    }

    catch(MatrixErrors& error) {
        cout << endl << error.what() << endl;
    }
}
