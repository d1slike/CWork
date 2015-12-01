#include "basis/DoubleLinkedList.h"

struct Text {
    DoubleLinkedList* list;
};

Text* callMenuToTextEdit(Text* text, int clearScr);
void terminateText(Text* text);
void printText(Text* text);
