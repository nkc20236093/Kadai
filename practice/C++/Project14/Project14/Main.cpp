#include <iostream>
using namespace std;

//main.cpp�ɏ����Ē�o
//
//int�^�̔z��StudentA, B, C���쐬����B
//StudentA��5�̗v�f�����B60, 80, 70, 50, 40
//StudentB��3�̗v�f�����B100, 90, 60
//StudentC��1�̗v�f�����B70

//int�^�̃|�C���^�̔z��StudentTable���쐬���A
//StudentA, StudentB, StudentC�̃|�C���^��v�f�Ƃ��Ď�������B

//StudentTable�𑽏d���[�v��p���Ďg�p���A
//StudentA, B, C�̗v�f��S�ĕ\���B
//��
//�\����
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