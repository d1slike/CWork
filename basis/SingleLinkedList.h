//
// Created by Dislike on 30.11.2015.

struct SingleNode {
    SingleNode* next;
    void* data;
};

struct SingleLinkedList{
    SingleNode* first;
    SingleNode* current;
};

SingleLinkedList* initSList();
void clearSList(SingleLinkedList* list);
int SListIsEmpty(SingleLinkedList* list);
void setCurrentToFirst(SingleLinkedList* list);
int currentIsOnFirst(SingleLinkedList* list);
void moveCurrentToNextInSList(SingleLinkedList* list);
SingleNode* getNextElementInSList(SingleLinkedList* list);
SingleNode* removeNextElementInSList(SingleLinkedList* list);
void changeNextElementInSList(SingleLinkedList* list, void** newData);
void addAfterCurrentInSList(SingleLinkedList* list, void** newData);
void termnateSLIst(SingleLinkedList* list);
