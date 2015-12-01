//
// Created by Dislike on 30.11.2015.
//

#include "SingleLinkedList.h"

#define NO_BECAUSE_ON_TAIL "�������� �� ��������. ��������� ����� ������.\n"
#define NO_BECAUSE_IS_EMPTY "�������� �� ��������. ������ ����.\n"

/*���������� ������� ��� ����� �������������� ����, ��� ��������� �������� ������ �� ������� � �������� �������� ���������, ��������� �� �� �� ����� ������
 * ���� ������� ������, �� ����������� ������ ��������� �� ������ � ������� �� �������, � ������� ������ ������ ������������*/
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
    Node *cur = list->first; //�������������� ������� ��������� ���������� �� ������ ������
    Node *tmp = NULL; //��������� ��������� ���������, ����������� NULL
    while (cur != NULL) //���� ������� ��������� �� NULL
    {
        tmp = cur->next; //����������� ���������� �������� ��������� �� ��������� ����� ��������
        if(cur->data != NULL)
            free(cur->data);
        free(cur); //����������� ������ �������� ��������
        cur = tmp; //����������� �������� �������� ��������� �� ��������� �� ��� �������
    }
    /*������������� ��� �������� ��������� ������ �� NULL*/
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
        printf(SListIsEmpty(list) ? NO_BECAUSE_IS_EMPTY : NO_BECAUSE_ON_TAIL);//��������� ��������� � �������������� ��������
        return NULL;//��������� ���������� ���������� �������
    }

    return list->current->next;
}

SingleNode *removeNextElementInSList(SingleLinkedList *list) {
    if (SListIsEmpty(list) || list->current->next == NULL) {
        printf(SListIsEmpty(list) ? NO_BECAUSE_IS_EMPTY : NO_BECAUSE_ON_TAIL);//��������� ��������� � �������������� ��������
        return NULL;//��������� ���������� ���������� �������
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
