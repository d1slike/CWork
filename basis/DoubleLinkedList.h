//
// Created by Dislike on 30.11.2015.
//

struct DoubleNode {
    DoubleNode* next;
    DoubleNode* prev;
    void* data;
};

struct DoubleLinkedList{
    DoubleNode* head;
    DoubleNode* tail;
    DoubleNode* current;
};

DoubleLinkedList* initDList();
void clearList(DoubleLinkedList* list);
int DListIsEmpty(DoubleLinkedList* list);
void setCurrentToHead(DoubleLinkedList* list);
void setCurrentToTail(DoubleLinkedList* list);
int currentIsOnHead(DoubleLinkedList* list);
int currentIsOnTail(DoubleLinkedList* list);
void moveCurrentToNextInDList(DoubleLinkedList* list);
void moveCurrentToPrevInDList(DoubleLinkedList* list);
DoubleNode* getNextElementInDList(DoubleLinkedList* list);
DoubleNode* getPrevElementInDList(DoubleLinkedList* list);
DoubleNode* removeNextElementInDLIst(DoubleLinkedList* list);
DoubleNode* removePrevElementInDList(DoubleLinkedList* list);
void changeNextElementInDLIst(DoubleLinkedList* list, void** newData);
void changePrevElementInDList(DoubleLinkedList *list, void** newData);
void addAfterCurrentInDList(DoubleLinkedList* list, void** newData);
void addBeforeCurrentInDList(DoubleLinkedList* list, void** newData);
void terminateDList(DoubleLinkedList* list);