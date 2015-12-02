//
// Created by Dislike on 01.12.2015.
//

#include <ctype.h>
#include "Util.h"

char *scanNewWord() {
    fflush(stdin);

    const size_t CHAR_SIZE = sizeof(char);

    char *word = (char *) malloc(CHAR_SIZE * 11);
    int count = 0;
    int i = 0;
    char c = '1';
    printf("������� ����� ����� -> ");
    while (!isspace((c = getchar()))) {
        word[count++] = c;
        i++;
        if (i == 10) {
            word = (char *) realloc(word, ((count + 11) * CHAR_SIZE));
            if (word == NULL)
                fail();
            i = 0;
        }
    }
    word[count] = '\0';

    return word;
}

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
