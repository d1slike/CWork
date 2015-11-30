//
// Created by Dislike on 29.11.2015.
//

#include <stdlib.h>
#include <stdio.h>
#include "Vector.h"
#include "Util.h"
#define VECTOR_MENU "1. Начать работу с вектором.\n"\
                    "2. Сделать вектор пустым.\n"\
                    "3. Вектор пуст?\n"\
                    "4. Вывести количество элементов в векторе.\n"\
                    "5. Показать значение i-ого элемента.\n"\
                    "6. Удалить элемент с конца вектора.\n"\
                    "7. Взять i-ый элемент.\n"\
                    "8. Изменить значение i-ого элемента.\n"\
                    "9. Добавить новый элемент в конец списка.\n"\
                    "10. Закончить работу с вектором.\n"\
                    "11. Выход из программы."



void callMenuToVectorEdit(Vector *v) {
    Vector* vector = v;
    int cmd;

    while(true)
    {
        system("cls");//очищаем консоль от предыдущий записей
        printf(VECTOR_MENU);//печатаем все пункты меню
        printVector(v);
        printf("\n->"); //печатаем стрелку
        scanf("%d", &cmd); //считываем команду с консоли

        if(cmd == 11)
            return;

        if(cmd != 1 && vector == NULL)
        {
            printf("Операция не допустима!\n"); //выводим сообщение о недопустимости операции
            listenAnswer();//ожидаем нажатие любой клавиши от пользователя
            continue; //продолжаем итерации цикла
        }

        switch (cmd)
        {
            case 1:
                if(vector != NULL)
                    printf("Вектор уже инициализирован\n");
                else
                    vector = initVector();
                break;
            case 2:
                clearVector(vector);
                break;
            case 3:
                printf(vectorIsEmpty(vector) ? "Вектор пуст.\n" : "Вектор НЕ пуст.\n");
                break;
            case 4:
                printf("Количество элементов в векторе равно: %d\n", getVectorSize(vector));
                break;
            case 5:
                printElement(vector, scanRequaredIndex());
                break;
            case 6:
                removeLast(vector);
                break;
            case 7:
                Text* text = remove(vector, scanRequaredIndex());
                if(text != NULL) {
                    printf("Значение взятого элемента: ");
                    printText(text);
                    terminateText(text);
                    free(text);
                }
                break;
            case 8:
                changeElement(vector, scanRequaredIndex());
                break;
            case 9:
                addLast(vector);
                break;
            case 10:
                terminateVector(vector);
                break;
            listenAnswer();
            default:
                //если не выполняется ни одна из предыдцщх веток, выводим сообщение о неизвестной команде
                printf("Неизвестная команда.\n");
                break;
        }
    }

}
