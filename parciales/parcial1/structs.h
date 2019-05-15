
typedef struct{
    int day;
    int month;
    int year;
} eDate;

typedef struct{
    int id;
    char description[21];
    int isEmpty;
} eBrand;

typedef struct{
    int id;
    char nombreColor[21];
    int isEmpty;
} eColor;

typedef struct{
    int id;
    char patent[8];
    int idBrand;
    int idColor;
    int modelYear;
    int isEmpty;
} eCar;

typedef struct{
    int id;
    char description[26];
    int price;
    int isEmpty;
} eService;

typedef struct{
    int id;
    char patent[8];
    int idService;
    eDate date;
    int isEmpty;
} eWork;
