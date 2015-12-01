#include "basis/DoubleLinkedList.h"

struct Text {
    DoubleLinkedList* list;
};

Text* callMenuToTextEdit(Text* text);
void terminateText(Text* text);
void printText(Text* text);
Text* initText();
void clearText(Text *text);
