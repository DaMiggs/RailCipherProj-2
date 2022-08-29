
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX_COMMAND_TOKEN_LENGTH 25
#define MAX_KEY_LENGTH 100
#define MAX_LINE_LENGTH 2500
#define MAX_NUM_SENTENCES 5000
#define IN 1
#define OUT 0

char getCommandWord(char command[], int maxLength, char* delimiter);
void handleEncryption(void);
void handleDecryption(void);
char getLine(char* line, int limit);
void handleDecryption(void);
int wordCount(char* line);
int getKeys(int* keys);
void tokenize(char* line, char** tokens);
int getKeys(int* keys);
int isvalidkey(int* keys, int k);