//
// Created by Dislike on 30.11.2015.
//

#pragma once

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

void listenAnswer();
int scanRequaredIndex();
int scanIntValue();
void printLine();
void failMemoryAllocate();

void setDefaultColorText();

void setYellowColorText();

char *scanNewWord(int printMessage);


