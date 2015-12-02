#include "basis/SingleLinkedList.h"

struct Sentence {
    SingleLinkedList* list;
};

Sentence* callMenuToSentenceEdit(Sentence* sentence);

void printSentence(Sentence *sentence, int showCurrent);
void terminateSentence(Sentence* sentence);
Sentence* initSentence();