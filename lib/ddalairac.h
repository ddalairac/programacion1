
/**********************************************
*
*  Libreria de funciones genericas.
*
***********************************************/

int inputInt(char message[]);
float inputFloat(char message[]);
char inputChar(char message[]);
void inputStr(char message[],char str[]);

int getRandomNumber(int from, int to, int init);

int calcAddition(int a, int b);
int calcSubtraction(int a, int b);
int calcMultiplication(int a, int b);
float calcDivision(int a, int b);
int calcFactorial(int number);
int calcPrime(int number);


int findInt(int num, int vec[], int vecSize);

void sortIntVectorByInsertion(int vec[], int size, char order);
void sortIntVector(int vec[],int size, char order);

void strCapitalize(char vec[]);

int validNumber(char str[]);
int validFloat(char str[]);
int validLetter(char str[]);
int validAlphaNumeric(char str[]);

void pause();
