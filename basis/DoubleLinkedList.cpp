//
// Created by Dislike on 30.11.2015.
//

#include "DoubleLinkedList.h"
#include <stdlib.h>
#include <stdio.h>

#define list pList
/*Определние макроса текстовых сообщений об ошибках*/
#define NO_BECAUSE_ON_HEAD "Операция не доступна. Достигнуто начало списка.\n"
#define NO_BECAUSE_ON_TAIL "Операция не доступна. Достигнут конец списка.\n"
#define NO_BECAUSE_IS_EMPTY "Операция не доступна. Список пуст.\n"
/*Определние макроса для часто повторяющегося кода, код выполняет проверку списка на пустоту и проверку текущий указателя, указывает ли он на начало списка
 * если условие ИСТИНА, то выполняется печать сообщения об ощибке и возврат из функции, в которой данный макрос встраивается*/
#define _CHECK_HEAD_    int empty = DListIsEmpty(pList);\
                        if (empty || currentIsOnHead(pList)) {\
                            printf(empty ? NO_BECAUSE_IS_EMPTY : NO_BECAUSE_ON_HEAD);\
                            return;\
                        }
/*Определние макроса для часто повторяющегося кода, код выполняет проверку списка на пустоту и проверка текущего указателя, указывает ли он на конец списка
 * если условие ИСТИНА, то выполняется печать сообщения об ощибке и возврат из функции, в которой данный макрос встраивается*/
#define _CHECK_TAIL_    int empty = DListIsEmpty(pList);\
                        if (empty || currentIsOnTail(pList)) {\
                            printf(empty ? NO_BECAUSE_IS_EMPTY : NO_BECAUSE_ON_TAIL);\
                            return;\
                        }
typedef DoubleNode Node;


DoubleLinkedList *initDList() {
    /*Выделяем память для двусзяного списка*/
    DoubleLinkedList *list = (DoubleLinkedList *) malloc(sizeof(DoubleLinkedList));
    /*Устанавливаем ключевые указатели списка на NULL*/
    list->tail = list->current = list->head = NULL;
    return list;//возвращаем список
}

void clearDList(DoubleLinkedList *list) {
    Node *cur = pList->head; //Инициализируем рабочий указатель указателем на начало списка
    Node *tmp = NULL; //Объявляем временный указатель, присваиваем NULL
    while (cur != NULL) //Пока рабочий указатель не NULL
    {
        tmp = cur->next; //Присваиваем временному казателю указатель на следующий после рабочего
        free(cur->data);
        free(cur); //Освобождаем память рабочего элемента
        cur = tmp; //Присваиваем рабочему казателю указатель на следующий за ним элемент
    }
    /*Устанавливаем все ключевые указателя списка на NULL*/
    pList->tail = pList->head = pList->current = NULL;
}

int DListIsEmpty(DoubleLinkedList *list) {
    return pList != NULL && pList->head == pList->tail && pList->head == NULL;
}

void setCurrentToHead(DoubleLinkedList *list) {
    pList->current = pList->head;
}

void setCurrentToTail(DoubleLinkedList *list) {
    pList->current = pList->tail;
}

int currentIsOnHead(DoubleLinkedList *list) {
    return pList->current != NULL && pList->current == pList->head;
}

int currentIsOnTail(DoubleLinkedList *list) {
    return pList->current != NULL && pList->current == pList->tail;
}

void moveCurrentToNextInDList(DoubleLinkedList *list) {
    _CHECK_TAIL_ //Встраивание макроса на проверку текущего элемента, указывает ли он на конец списка
    pList->current = pList->current->next;
}

void moveCurrentToPrevInDList(DoubleLinkedList *list) {
    _CHECK_HEAD_ //Встраивание макроса на проверку текущего элемента, указывает ли он на начало списка
    pList->current = pList->current->prev;
}

DoubleNode *getNextElementInDList(DoubleLinkedList *list) {
    /*Если список не инициализирован или текущий указатель указывает на конец списка*/
    if (DListIsEmpty(list) || currentIsOnTail(pList)) {
        printf(DListIsEmpty(list) ? NO_BECAUSE_IS_EMPTY : NO_BECAUSE_ON_TAIL);//перчатаем сообщение о недопустимости операции
        return NULL;//возвращем управление вызывающей функции
    }
    return list->current->next;
}

DoubleNode *getPrevElementInDList(DoubleLinkedList *list) {
    if (DListIsEmpty(list) || currentIsOnHead(pList)) {
        printf(DListIsEmpty(list) ? NO_BECAUSE_IS_EMPTY : NO_BECAUSE_ON_HEAD);//перчатаем сообщение о недопустимости операции
        return NULL;//возвращем управление вызывающей функции
    }
    return list->current->prev;
}

DoubleNode *removeNextElementInDLIst(DoubleLinkedList *list) {
    /*Если список не инициализирован или текущий указатель указывает на конец списка*/
    if (DListIsEmpty(list) || currentIsOnTail(pList)) {
        printf(DListIsEmpty(list) ? NO_BECAUSE_IS_EMPTY : NO_BECAUSE_ON_TAIL);//перчатаем сообщение о недопустимости операции
        return NULL;//возвращем управление вызывающей функции
    }
    /*Объявляем и инициализируем указатель на удалемый элемент*/
    Node *toDel = pList->current->next;
    /*Если удаляется полсдедний элемент списка*/
    if (toDel == pList->tail) {
        pList->tail = toDel->prev; //новым последним элементом становится предыдущий элемент переж удаляемым
        pList->tail->next = NULL; //у последнего элемента указателю на следующий присваиваем 0
        return toDel; //возаращем из функции указаетль на взятый элемент
    }
    /*Если берем элемент из середины списка*/
    pList->current->next = toDel->next;//у текущего элемента укателю на следующий присваиваем значение указателя следующего элемента у взятого
    toDel->next->prev = pList->current;//присваиваем указателю на предыдущий элемент у следующего за взяты значение указателя текущего элемента

    return toDel; //возаращем из функции указаетль на взятый элемент
}

DoubleNode *removePrevElementInDList(DoubleLinkedList *list) {
    /*Если список не инициализирован или текущий указатель указывает на начало списка*/
    if (pList->current == NULL || currentIsOnHead(pList)) {
        printf(NO_BECAUSE_ON_HEAD);//перчатаем сообщение о недопустимости операции
        return NULL; //возвращем управление вызывающей функции
    }
    /*Объявляем и инициализируем указатель на удалемый элемент*/
    Node *toDel = pList->current->prev;
    /*Если удаляется первый элемент списка*/
    if (toDel == pList->head) {
        pList->head = toDel->next; //новым первым элементом становится следуюий элемент за удаляемым
        pList->head->prev = NULL; //у первого элемента указателю на предыдущий присваиваем 0
        return toDel; //возаращем из функции указаетль на взятый элемент
    }
    /*Если берем элемент из середины списка*/
    pList->current->prev = toDel->prev;//у текущего элемента укателю на предыдущий присваиваем значение указателя предыдущего элемента у взятого
    toDel->prev->next = pList->current;//присваиваем указателю на следущий элемент у предыдущего за взятым значение указателя текущего элемента

    return toDel; //возаращем из функции указаетль на взятый элемент
}

void changeNextElementInDLIst(DoubleLinkedList *list, void **newData) {
    _CHECK_TAIL_
    if(list->current->next->data != NULL)
        free(list->current->next->data);
    list->current->next->data = *newData;
}

void changePrevElementInDList(DoubleLinkedList *list, void **newData) {
    _CHECK_HEAD_
    if(list->current->prev->data != NULL)
        free(list->current->prev->data);
    list->current->prev->data = *newData;
}

void addAfterCurrentInDList(DoubleLinkedList *list, void **newData) {
    /*Выделяем память под новый элемент*/
    Node *newElement = (Node *) malloc(sizeof(Node));
    /*Если память выделить не удалось*/
    if (newElement == NULL) {
        printf("Не удалось выделить память. Выход из программы...");//печатаем сообщение
        exit(1);//завершаем программу
    }
    /*Устанавливаем свзяли у нового элемента на NULL по умолчанию*/
    newElement->next = newElement->prev = NULL;

    newElement->data = *newData;

    /*Если список пуст*/
    if (DListIsEmpty(pList)) {
        /*Новый элемент становится началом, концом и текущим элементом списка*/
        pList->head = pList->current = pList->tail = newElement;
        return;//возвращем управление вызывающей функции
    }
    /*Устанавливаем связи у нового элемента в общем случае*/
    newElement->prev = pList->current;//Значению указателя на предыдущий элемент присваиваем текущий указтаель списка
    newElement->next = pList->current->next; //Значению указаетля на соедубщий элемент присваиваем значение указателя следующего элемента у текущего
    /*Если текущий указатель указывает на конец списка*/
    if (currentIsOnTail(pList)) {
        /*Новый элемент становится концом списка*/
        pList->tail = newElement;
        /*Значению указателя на следующий элемент у текущего присваиваем указатель на новый эдемент*/
        pList->current->next = newElement;
        return;//возвращем управление вызывающей функции
    }
    /*Устанавливаем связи у нового элемента в общем случае*/
    pList->current->next->prev = newElement;//У следующего элемента за текущим значнию предыдущего элемента присваиваем указатель на новый элемент
    pList->current->next = newElement;//Значению следующего элемента у текущего присваиваем указатель на новый элемент
}

void addBeforeCurrentInDList(DoubleLinkedList *list, void **newData) {
    /*Выделяем память под новый элемент*/
    Node *newElement = (Node *) malloc(sizeof(Node));
    /*Если память выделить не удалось*/
    if (newElement == NULL) {
        printf("Не удалось выделить память. Выход из программы..."); //печатам сообщение
        exit(1);//завершаем программу
    }
    /*Устанавливаем свзяли у нового элемента на NULL по умолчанию*/
    newElement->next = newElement->prev = NULL;

    newElement->data = *newData;

    /*Если список пуст*/
    if (DListIsEmpty(pList)) {
        /*Новый элемент становится началом, концом и текущим элементом списка*/
        pList->head = pList->current = pList->tail = newElement;
        return;//возвращем управление вызывающей функции
    }
    /*Устанавливаем связи у нового элемента в общем случае*/
    newElement->next = pList->current;//Значению указателя на следущий элемент присваиваем текщий указатель списка
    newElement->prev = pList->current->prev;//Значению указателя на предыдущий элемент присваиваем значение предыдущего элемента до текущего
    /*Если текущий казатель указывает на начало списка*/
    if (currentIsOnHead(pList)) {
        /*Новый элемент становится началом списка*/
        pList->head = newElement;
        /*Значению предыдущего элемента у текущего присваиваем указатель на новый элемент */
        pList->current->prev = newElement;
        return;//возвращем управление вызывающей функции
    }
    /*Установка связей в общем случае*/
    pList->current->prev->next = newElement;//У предыдущего элемента перед текущим значнию следующего элемента устанавливаем указатель на новый элемент
    pList->current->prev = newElement; //Значение предыдущего элемента у текущего присваиваем указатель на новый элемент
}

void terminateDList(DoubleLinkedList *list) {
    clearDList(pList);//очищаем список
    free(pList);//освобождаем память, занимаемую списком
}