#include <locale.h>
#include "Vector.h"

int main()
{
    setlocale(LC_ALL, ".1251"); //���������� ������ � ���������� �������� ����� ��� �����/������
    setDefaultColorText();
    callMenuToVectorEdit(0);
    return 0;
}