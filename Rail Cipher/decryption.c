#include"railcipher.h"

static char** sentences[MAX_NUM_SENTENCES];
static int nwordsArray[MAX_NUM_SENTENCES];


char wordSort(char* msg) {
	int c, i;
	char mssg[24];
	while ((c = getchar()) != '\n' && c !=EOF)
		if (!isspace(msg[i++])) {
			mssg[i] = c;
		}else {
			
		}
	return 't';
}

int printing(int column, int row) {
	printf("C: %d R: %d\n", column, row);
	
	printf(" |   ");
	for (int j = 0; j<column; j++) {
		printf("%d   |   ", j);
	}
	printf("\n");
	for (int i = 0; i<row; i++) {
		printf(" |\n");
	}
	return 'Y';
}

void handleDecryption(void) {

	int wordNum, key, sortedKey[MAX_KEY_LENGTH], k, columns, rows, i=0, keys[MAX_KEY_LENGTH], nwords, maxwords = -1;
	char temp, givenEncrypt[MAX_LINE_LENGTH];
	char *lastArray[rows][columns];
	
	//printf("Enter a key...\n");
	k = getKeys(keys);
	if (getchar() != '\n' || k < 1) {
		printf("Error: syntax of encryption command is not valid!\n");
	}
	if (!isvalidkey(keys,k)) {
		printf("Error: invalid key! key of length %d must be a permutation of non-negative integers less than %d\n", k, k);
	}
	
	for (int i = 0; i<k; i++) {// key in sorted order
		sortedKey[i]=i;
		//printf("%d ", sortedKey[i]);
	}
	
	
	//printf("\nEnter a sentence...\n");
	i=0;
	while (1) {
		temp = getLine(givenEncrypt, MAX_LINE_LENGTH);
		if (i == MAX_NUM_SENTENCES)
			break;
		nwords = wordCount(givenEncrypt);
		//printf("has %d words.\n", nwords);
		if (!nwords) {
			i--;
			if (temp == EOF)
				break;
			continue;
		}
		if (maxwords < nwords)
			maxwords = nwords;
		nwordsArray[i] = nwords;
		sentences[i] = (char**)malloc(nwords * sizeof(char*));
		tokenize(givenEncrypt, sentences[i++]);
		if (temp == EOF){
			wordNum = nwords;
			break;
		}
	}
	
	/*for (int i = 0; i<wordNum; i++) {
		temp = wordCount(&givenEncrypt[1]);
	}*/ 
	//printing amount of words in the message
	printf("\n has %d words.\n", wordNum);
	rows = (wordNum/k);
	columns = k;

	
	printing(columns, rows);
	
	
	for (int i = 0; i<rows; i++) {
		key = keys[i];
		printf("%d\n", key);
		for (int j = 0; j<columns; j++) {
			printf("%s ", givenEncrypt);
			strcpy(lastArray[i][key], strtok(givenEncrypt, " "));

		}
	}

}