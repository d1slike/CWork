#include <locale.h>
#include "Vector.h"

int main()
{
    setlocale(LC_ALL, ".1251"); //���������� ������ � ���������� �������� ����� ��� �����/������
    callMenuToVectorEdit(0);
    return 0;
}