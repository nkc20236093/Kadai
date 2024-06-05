#include <iostream>
using namespace std;

//main.cppに書いて提出
//
//int型の配列StudentA, B, Cを作成する。
//StudentAは5つの要素を持つ。60, 80, 70, 50, 40
//StudentBは3つの要素を持つ。100, 90, 60
//StudentCは1つの要素を持つ。70

//int型のポインタの配列StudentTableを作成し、
//StudentA, StudentB, StudentCのポインタを要素として持たせる。

//StudentTableを多重ループを用いて使用し、
//StudentA, B, Cの要素を全て表示。
//※
//表示例
//60, 80, 70, 50, 40,
//100, 90, 60,
//70,

int main()
{
    int studentA[5] = { 80,50,20,10,5 };
    int studentB[3] = { 80,50,20, };
    int studentC[1] = { 0, };

    int sA = sizeof(studentA) / sizeof(studentA[0]);
    int sB = sizeof(studentB) / sizeof(studentB[0]);
    int sC = sizeof(studentC) / sizeof(studentC[0]);

    int* StudentTable[3] =
    {
        studentA,
        studentB,
        studentC,
    };
    
    int size[3] = { sA,sB,sC };
    int h = sizeof(StudentTable) / sizeof(*StudentTable);
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < size[i]; j++)
        {
            cout << StudentTable[i][j] << ",";
        }
        cout << endl;
    }
}