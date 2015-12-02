//
// Created by Dislike on 29.11.2015.
//

#include "Vector.h"
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
                    "11. Выход из программы.\n\n"



int checkIndex(Vector* vector ,int i) {
    int ok = i > 0 && i < vector->size;
    if(!ok)
        printf("Неверный индекс!\n");
    return ok;
}


void moveToRequaredIndex(Vector* vector, int i) {
    setCurrentToFirst(vector->source);
    int cur = 0;
    while(cur++ < i)
        moveCurrentToNextInSList(vector->source);

}

void callMenuToVectorEdit(Vector *v) {
    Vector* vector = v;
    int cmd;

    while(true)
    {
        system("cls");//очищаем консоль от предыдущий записей
        printf(VECTOR_MENU);//печатаем все пункты меню
        printVector(vector);
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
            case 6: {
                Text *text = removeLast(vector);
                if(text != NULL)
                {
                    terminateText(text);
                    free(text);
                }
            }
                break;
            case 7: {
                Text *text = remove(vector, scanRequaredIndex());
                if (text != NULL) {
                    printf("Значение взятого элемента: ");
                    printText(text);
                    terminateText(text);
                    free(text);
                }
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
                vector = NULL;
                break;
            default:
                //если не выполняется ни одна из предыдцщх веток, выводим сообщение о неизвестной команде
                printf("Неизвестная команда.\n");
                break;
        }

        listenAnswer();
    }

}

Vector *initVector() {
    Vector* vector = (Vector*) malloc(sizeof(Vector));
    if(vector == NULL)
        fail();
    vector->source = initSList();
    addAfterCurrentInSList(vector->source, NULL);
    vector->size = 0;

    return vector;
}

void clearVector(Vector *v) {
    if (vectorIsEmpty(v))
        return;
    setCurrentToFirst(v->source);
    while(v->source->current->next != NULL)
    {
        SingleNode* node = removeNextElementInSList(v->source);
        terminateText((Text*) node->data);
        free(node);
        moveCurrentToNextInSList(v->source);
    }
    v->source->first->next = NULL;
    setCurrentToFirst(v->source);
    v->size = 0;
}

int vectorIsEmpty(Vector *v) {
    return !v->size;
}

int getVectorSize(Vector *v) {
    return v->size;
}

void printElement(Vector *v, int i) {
    if (!checkIndex(v, i))
        return;
    moveToRequaredIndex(v, i);
    SingleNode *node = getNextElementInSList(v->source);
    if (node != NULL)
        printText((Text *) node->data);

}

Text *removeLast(Vector *v) {
    return remove(v, v->size - 1);
}

Text *remove(Vector *v, int i) {
    if (!checkIndex(v, i))
        return NULL;
    moveToRequaredIndex(v, i);
    SingleNode *node = removeNextElementInSList(v->source);
    return node == NULL ? NULL : (Text *) node->data;
}

void changeElement(Vector *v, int i) {
    if (!checkIndex(v, i))
        return;
    moveToRequaredIndex(v, i);
    SingleNode *text = getNextElementInSList(v->source);
    if (text != NULL)
        callMenuToTextEdit((Text *) text->data);
}

void addLast(Vector *v) {
    if(v->size == MAX_SIZE)
    {
        printf("Невозможно добавить больше элементов в вектор\n");
        return;
    }
    void* text = callMenuToTextEdit(NULL);
    if(text != NULL) {
        moveToRequaredIndex(v, v->size - 1);
        addAfterCurrentInSList(v->source,  &text);
        v->size++;
    }
}

void terminateVector(Vector *v) {
    clearVector(v);
    terminateSLIst(v->source);
    free(v->source);
    v->source = NULL;
    free(v);
}

void printVector(Vector *v) {
    if(v == NULL)
    {
        printf("Вектор не инициализирован.\n");
        return;
    }

    if(vectorIsEmpty(v))
    {
        printf("Вектор пуст.\n");
        return;
    }

    setCurrentToFirst(v->source);
    moveCurrentToNextInSList(v->source);
    int i = 0;
    while(v->source->current->next != NULL)
    {
        printf("[%d]\t", i);
        printText((Text*) v->source->current->data);
        moveCurrentToNextInSList(v->source);
    }
    printf("\n");
}

