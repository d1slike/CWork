//
// Created by Dislike on 30.11.2015.
//

#include "DoubleLinkedList.h"
#include <stdlib.h>
#include <stdio.h>

#define list pList
/*���������� ������� ��������� ��������� �� �������*/
#define NO_BECAUSE_ON_HEAD "�������� �� ��������. ���������� ������ ������.\n"
#define NO_BECAUSE_ON_TAIL "�������� �� ��������. ��������� ����� ������.\n"
#define NO_BECAUSE_IS_EMPTY "�������� �� ��������. ������ ����.\n"
/*���������� ������� ��� ����� �������������� ����, ��� ��������� �������� ������ �� ������� � �������� ������� ���������, ��������� �� �� �� ������ ������
 * ���� ������� ������, �� ����������� ������ ��������� �� ������ � ������� �� �������, � ������� ������ ������ ������������*/
#define _CHECK_HEAD_    int empty = DListIsEmpty(pList);\
                        if (empty || currentIsOnHead(pList)) {\
                            printf(empty ? NO_BECAUSE_IS_EMPTY : NO_BECAUSE_ON_HEAD);\
                            return;\
                        }
/*���������� ������� ��� ����� �������������� ����, ��� ��������� �������� ������ �� ������� � �������� �������� ���������, ��������� �� �� �� ����� ������
 * ���� ������� ������, �� ����������� ������ ��������� �� ������ � ������� �� �������, � ������� ������ ������ ������������*/
#define _CHECK_TAIL_    int empty = DListIsEmpty(pList);\
                        if (empty || currentIsOnTail(pList)) {\
                            printf(empty ? NO_BECAUSE_IS_EMPTY : NO_BECAUSE_ON_TAIL);\
                            return;\
                        }
typedef DoubleNode Node;


DoubleLinkedList *initDList() {
    /*�������� ������ ��� ���������� ������*/
    DoubleLinkedList *list = (DoubleLinkedList *) malloc(sizeof(DoubleLinkedList));
    /*������������� �������� ��������� ������ �� NULL*/
    list->tail = list->current = list->head = NULL;
    return list;//���������� ������
}

void clearDList(DoubleLinkedList *list) {
    Node *cur = pList->head; //�������������� ������� ��������� ���������� �� ������ ������
    Node *tmp = NULL; //��������� ��������� ���������, ����������� NULL
    while (cur != NULL) //���� ������� ��������� �� NULL
    {
        tmp = cur->next; //����������� ���������� �������� ��������� �� ��������� ����� ��������
        if (cur->data != NULL)
            free(cur->data);
        free(cur); //����������� ������ �������� ��������
        cur = tmp; //����������� �������� �������� ��������� �� ��������� �� ��� �������
    }
    /*������������� ��� �������� ��������� ������ �� NULL*/
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
    _CHECK_TAIL_ //����������� ������� �� �������� �������� ��������, ��������� �� �� �� ����� ������
    pList->current = pList->current->next;
}

void moveCurrentToPrevInDList(DoubleLinkedList *list) {
    _CHECK_HEAD_ //����������� ������� �� �������� �������� ��������, ��������� �� �� �� ������ ������
    pList->current = pList->current->prev;
}

DoubleNode *getNextElementInDList(DoubleLinkedList *list) {
    /*���� ������ �� ��������������� ��� ������� ��������� ��������� �� ����� ������*/
    if (DListIsEmpty(list) || currentIsOnTail(pList)) {
        printf(DListIsEmpty(list) ? NO_BECAUSE_IS_EMPTY : NO_BECAUSE_ON_TAIL);//��������� ��������� � �������������� ��������
        return NULL;//��������� ���������� ���������� �������
    }

    if(pList->head == pList->tail)
        return pList->head;


    return list->current->next;
}

DoubleNode *getPrevElementInDList(DoubleLinkedList *list) {
    if (DListIsEmpty(list) || currentIsOnHead(pList)) {
        printf(DListIsEmpty(list) ? NO_BECAUSE_IS_EMPTY
                                  : NO_BECAUSE_ON_HEAD);//��������� ��������� � �������������� ��������
        return NULL;//��������� ���������� ���������� �������
    }
    if(pList->head == pList->tail)
        return pList->head;
    return list->current->prev;
}

DoubleNode *removeNextElementInDLIst(DoubleLinkedList *list) {
    /*���� ������ �� ��������������� ��� ������� ��������� ��������� �� ����� ������*/
    if (DListIsEmpty(list) || currentIsOnTail(pList)) {
        printf(DListIsEmpty(list) ? NO_BECAUSE_IS_EMPTY : NO_BECAUSE_ON_TAIL);//��������� ��������� � �������������� ��������
        return NULL;//��������� ���������� ���������� �������
    }

    if(pList->head == pList->tail) {
        DoubleNode* toRet =  pList->head;
        pList->head = pList->tail = pList->current = NULL;
        return toRet;
    }

    /*��������� � �������������� ��������� �� �������� �������*/
    Node *toDel = pList->current->next;
    /*���� ��������� ���������� ������� ������*/
    if (toDel == pList->tail) {
        pList->tail = toDel->prev; //����� ��������� ��������� ���������� ���������� ������� ����� ���������
        pList->tail->next = NULL; //� ���������� �������� ��������� �� ��������� ����������� 0
        return toDel; //��������� �� ������� ��������� �� ������ �������
    }
    /*���� ����� ������� �� �������� ������*/
    pList->current->next = toDel->next;//� �������� �������� ������� �� ��������� ����������� �������� ��������� ���������� �������� � �������
    toDel->next->prev = pList->current;//����������� ��������� �� ���������� ������� � ���������� �� ����� �������� ��������� �������� ��������

    return toDel; //��������� �� ������� ��������� �� ������ �������
}

DoubleNode *removePrevElementInDList(DoubleLinkedList *list) {
    /*���� ������ �� ��������������� ��� ������� ��������� ��������� �� ������ ������*/
    if (pList->current == NULL || currentIsOnHead(pList)) {
        printf(NO_BECAUSE_ON_HEAD);//��������� ��������� � �������������� ��������
        return NULL; //��������� ���������� ���������� �������
    }

    if(pList->head == pList->tail) {
        DoubleNode* toRet =  pList->head;
        pList->head = pList->tail = pList->current = NULL;
        return toRet;
    }

    /*��������� � �������������� ��������� �� �������� �������*/
    Node *toDel = pList->current->prev;
    /*���� ��������� ������ ������� ������*/
    if (toDel == pList->head) {
        pList->head = toDel->next; //����� ������ ��������� ���������� �������� ������� �� ���������
        pList->head->prev = NULL; //� ������� �������� ��������� �� ���������� ����������� 0
        return toDel; //��������� �� ������� ��������� �� ������ �������
    }

    /*���� ����� ������� �� �������� ������*/
    pList->current->prev = toDel->prev;//� �������� �������� ������� �� ���������� ����������� �������� ��������� ����������� �������� � �������
    toDel->prev->next = pList->current;//����������� ��������� �� �������� ������� � ����������� �� ������ �������� ��������� �������� ��������

    return toDel; //��������� �� ������� ��������� �� ������ �������
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
    /*�������� ������ ��� ����� �������*/
    Node *newElement = (Node *) malloc(sizeof(Node));
    /*���� ������ �������� �� �������*/
    if (newElement == NULL) {
        printf("�� ������� �������� ������. ����� �� ���������...");//�������� ���������
        exit(1);//��������� ���������
    }
    /*������������� ������ � ������ �������� �� NULL �� ���������*/
    newElement->next = newElement->prev = NULL;

    newElement->data = *newData;

    /*���� ������ ����*/
    if (DListIsEmpty(pList)) {
        /*����� ������� ���������� �������, ������ � ������� ��������� ������*/
        pList->head = pList->current = pList->tail = newElement;
        return;//��������� ���������� ���������� �������
    }
    /*������������� ����� � ������ �������� � ����� ������*/
    newElement->prev = pList->current;//�������� ��������� �� ���������� ������� ����������� ������� ��������� ������
    newElement->next = pList->current->next; //�������� ��������� �� ��������� ������� ����������� �������� ��������� ���������� �������� � ��������
    /*���� ������� ��������� ��������� �� ����� ������*/
    if (currentIsOnTail(pList)) {
        /*����� ������� ���������� ������ ������*/
        pList->tail = newElement;
        /*�������� ��������� �� ��������� ������� � �������� ����������� ��������� �� ����� �������*/
        pList->current->next = newElement;
        return;//��������� ���������� ���������� �������
    }
    /*������������� ����� � ������ �������� � ����� ������*/
    pList->current->next->prev = newElement;//� ���������� �������� �� ������� ������� ����������� �������� ����������� ��������� �� ����� �������
    pList->current->next = newElement;//�������� ���������� �������� � �������� ����������� ��������� �� ����� �������
}

void addBeforeCurrentInDList(DoubleLinkedList *list, void **newData) {
    /*�������� ������ ��� ����� �������*/
    Node *newElement = (Node *) malloc(sizeof(Node));
    /*���� ������ �������� �� �������*/
    if (newElement == NULL) {
        printf("�� ������� �������� ������. ����� �� ���������..."); //������� ���������
        exit(1);//��������� ���������
    }
    /*������������� ������ � ������ �������� �� NULL �� ���������*/
    newElement->next = newElement->prev = NULL;

    newElement->data = *newData;

    /*���� ������ ����*/
    if (DListIsEmpty(pList)) {
        /*����� ������� ���������� �������, ������ � ������� ��������� ������*/
        pList->head = pList->current = pList->tail = newElement;
        return;//��������� ���������� ���������� �������
    }
    /*������������� ����� � ������ �������� � ����� ������*/
    newElement->next = pList->current;//�������� ��������� �� �������� ������� ����������� ������ ��������� ������
    newElement->prev = pList->current->prev;//�������� ��������� �� ���������� ������� ����������� �������� ����������� �������� �� ��������
    /*���� ������� �������� ��������� �� ������ ������*/
    if (currentIsOnHead(pList)) {
        /*����� ������� ���������� ������� ������*/
        pList->head = newElement;
        /*�������� ����������� �������� � �������� ����������� ��������� �� ����� ������� */
        pList->current->prev = newElement;
        return;//��������� ���������� ���������� �������
    }
    /*��������� ������ � ����� ������*/
    pList->current->prev->next = newElement;//� ����������� �������� ����� ������� ������� ���������� �������� ������������� ��������� �� ����� �������
    pList->current->prev = newElement; //�������� ����������� �������� � �������� ����������� ��������� �� ����� �������
}

void terminateDList(DoubleLinkedList *list) {
    clearDList(pList);//������� ������
    free(pList);//����������� ������, ���������� �������
}