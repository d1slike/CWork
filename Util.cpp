//
// Created by Dislike on 01.12.2015.
//

#include "Util.h"

void listenAnswer()
{
    printf("������� ����� ������� ��� �����������..."); //������� ���������
    fflush(stdin);
    getch();//����� ������, ��������� ����� �������
}

int scanRequaredIndex()
{
    printf("����� ������ �����c: -> ");
    int i;
    scanf("%d", &i);
    return  i;
}

void fail()
{
    printf("�� ������� �������� ������, ���������� ���������!");
    exit(-1);
}
