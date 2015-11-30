//
// Created by Dislike on 30.11.2015.
//

#ifndef CWORK_UTIL_H
#define CWORK_UTIL_H

#include <conio.h>
#include <stdio.h>

#define true 1
#define false 0

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

#endif //CWORK_UTIL_H
