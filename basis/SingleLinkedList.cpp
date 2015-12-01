//
// Created by Dislike on 30.11.2015.
//

#include "SingleLinkedList.h"

#define NO_BECAUSE_ON_TAIL "Операция не доступна. Достигнут конец списка.\n"
#define NO_BECAUSE_IS_EMPTY "Операция не доступна. Список пуст.\n"

/*Определние макроса для часто повторяющегося кода, код выполняет проверку списка на пустоту и проверка текущего указателя, указывает ли он на конец списка
 * если условие ИСТИНА, то выполняется печать сообщения об ощибке и возврат из функции, в которой данный макрос встраивается*/
#define _CHECK_TAIL_    int empty = SListIsEmpty(list);\
                        if (empty || list->current->next == NULL) {\
                            printf(empty ? NO_BECAUSE_IS_EMPTY : NO_BECAUSE_ON_TAIL);\
                            return;\
                        }

typedef SingleNode Node;

SingleLinkedList *initSList() {
    SingleLinkedList* list = (SingleLinkedList*) malloc(sizeof(SingleLinkedList));
    list->current = list->first = NULL;
    return list;
}

void clearSList(SingleLinkedList *list) {
    Node *cur = list->first; //Инициализируем рабочий указатель указателем на начало списка
    Node *tmp = NULL; //Объявляем временный указатель, присваиваем NULL
    while (cur != NULL) //Пока рабочий указатель не NULL
    {
        tmp = cur->next; //Присваиваем временному казателю указатель на следующий после рабочего
        if(cur->data != NULL)
            free(cur->data);
        free(cur); //Освобождаем память рабочего элемента
        cur = tmp; //Присваиваем рабочему казателю указатель на следующий за ним элемент
    }
    /*Устанавливаем все ключевые указателя списка на NULL*/
    list->first = list->current = NULL;
}

int SListIsEmpty(SingleLinkedList *list) {
    return list != NULL && list->first == NULL;
}

void setCurrentToFirst(SingleLinkedList *list) {
    list->current = list->first;
}

int currentIsOnTail(SingleLinkedList *list) {
    return list->current == list->first;
}

void moveCurrentToNextInSList(SingleLinkedList *list) {
    _CHECK_TAIL_
    list->current = list->current->next;
}

SingleNode *getNextElementInSList(SingleLinkedList *list) {
    if ((SListIsEmpty(list) || list->current->next == NULL)) {
        printf(SListIsEmpty(list) ? NO_BECAUSE_IS_EMPTY : NO_BECAUSE_ON_TAIL);//перчатаем сообщение о недопустимости операции
        return NULL;//возвращем управление вызывающей функции
    }

    return list->current->next;
}

SingleNode *removeNextElementInSList(SingleLinkedList *list) {
    if (SListIsEmpty(list) || list->current->next == NULL) {
        printf(SListIsEmpty(list) ? NO_BECAUSE_IS_EMPTY : NO_BECAUSE_ON_TAIL);//перчатаем сообщение о недопустимости операции
        return NULL;//возвращем управление вызывающей функции
    }
    //TODO fixme
}

void changeNextElementInSList(SingleLinkedList *list, void **newData) {
    _CHECK_TAIL_
    list->current->next->data = *newData;

}

void addAfterCurrentInSList(SingleLinkedList *list, void **newData) {

}

void termnateSLIst(SingleLinkedList *list) {
    clearSList(list);
    free(list);
}
