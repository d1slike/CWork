//
// Created by Dislike on 01.12.2015.
//

#include "Util.h"

void listenAnswer()
{
    printf("Нажмите любую клавишу для продолжения..."); //выводим сообщение
    fflush(stdin);
    getch();//вызов функци, ожидающей любое нажатие
}

int scanRequaredIndex()
{
    printf("Введи нужный индекc: -> ");
    int i;
    scanf("%d", &i);
    return  i;
}

void fail()
{
    printf("Не удалось выделить память, завершение программы!");
    exit(-1);
}
