#include "basis/DoubleLinkedList.h"

struct Text {
    DoubleLinkedList* list;
};

void callMenuToTextEdit(Text* text, int clearScr);
void terminateText(Text* text);
void printText(Text* text);
