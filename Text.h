#include "basis/DoubleLinkedList.h"

struct Text {
    DoubleLinkedList* list;
};

Text *callMenuToTextEdit(Text *tx);

void printText(Text *text, int showCurrent);
void terminateText(Text* text);
Text* initText();
void clearText(Text *text);
