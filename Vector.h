#include "Text.h"
#include "basis/SingleLinkedList.h"

#define MAX_SIZE 5

struct Vector {
    SingleLinkedList* source;
    int size;
};

void callMenuToVectorEdit(Vector* v);

Vector* initVector();
void clearVector(Vector* v);
int vectorIsEmpty(Vector* v);
int getVectorSize(Vector *v);
void printElement(Vector* v, int i);
Text* removeLast(Vector* v);
Text* remove(Vector* v, int i);
void changeElement(Vector* v, int i);
void addLast(Vector* v);
void terminateVector(Vector* v);
void printVector(Vector* v);
