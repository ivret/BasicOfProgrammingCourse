#include "lab_19.h"
#include <string.h>
#include <math.h>



void fileModifiesAnEntryRowOnCol(const char file[]){
        FILE *f = fopen(file, "r");

        int n;
        matrix *ms = createMatrixFromArrayFile(f, &n);
        fclose(f);

        for (int i = 0; i < n; ++i) {
            transposeSquareMatrix(&ms[i]);
        }

        f = fopen(file, "w");

    outputMatricesSquareFiles(ms, n, f);

        fclose(f);
    }

void write(const char* filename, const char* data){
    FILE* f = fopen(filename, "w");
    fprintf(f, "%s" ,data);
    fclose(f);
}

long getFileSize(const char* filename) {
    FILE *f = fopen(filename, "rb");
    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    fclose(f);
    return size;
}

bool cmpStrFile(const char *s, const char *filename) {
    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        perror("Error opening file");
        return false;
    }

    int index = 0;
    char ch;
    while ((ch = fgetc(f)) != EOF && *s != '\0') {
        if (ch != *s) {
            fclose(f);
            return false;
        }
        s++;
        index++;
    }

    fclose(f);

    // Проверяем, что файл и строка закончились одновременно
    if (ch != EOF || *s != '\0') {
        return false;
    }

    return true;
}

void test_lab19_01(){
    char lab19_task01_str[] = "2\n"
                              "3\n"
                              "1 2 3\n"
                              "4 5 6\n"
                              "7 8 9\n"
                              "4\n"
                              "10 11 12 13\n"
                              "14 15 16 17\n"
                              "18 19 20 21\n"
                              "22 23 24 25";

    char lab19_task01_out_str[] = "2\n"
                                  "3\n"
                                  "1 4 7\n"
                                  "2 5 8\n"
                                  "3 6 9\n"
                                  "4\n"
                                  "10 14 18 22\n"
                                  "11 15 19 23\n"
                                  "12 16 20 24\n"
                                  "13 17 21 25\n";

    const char filename[] = "1.txt";
    write("1.txt", lab19_task01_str);
    assert(cmpStrFile(lab19_task01_str,"1.txt"));
    fileModifiesAnEntryRowOnCol(filename);
    assert(cmpStrFile(lab19_task01_out_str, filename));
}

void lab19_task02(const char *filename){
    FILE *f = fopen(filename, "r");

    vectorVoid v = createVectorV(10, sizeof (float));

    float x;
    while (fscanf(f, "%f", &x) == 1)
        pushBackV(&v, &x);

    fclose(f);

    f = fopen(filename, "w");
    for (int i = 0; i < v.size; i++){
        getVectorValueV(&v, i, &x);
        fprintf(f, "%.2e ", x);
    }

    deleteVectorV(&v);
    fclose(f);
}
void testTransformFloat(){
    char lab19_task02_str[] = "1.123 20.232 0.45948 6.524";
    char lab19_task02_out_str[] = "1.12e+00 2.02e+01 4.59e-01 6.52e+00 ";
    const char filename[] = "2.txt";
    write(filename, lab19_task02_str);

    lab19_task02(filename);

    assert(cmpStrFile(lab19_task02_out_str, filename));
}

int calculateExpression(int x, int y, char op){
    switch (op) {
        case '+': return x + y;
        case '-': return x - y;
        case '*': return x * y;
        case '/': return x / y;
        default: return 0;
    }
}

int isOperation(char c){
    return c == '*' || c == '+' || c == '-' || c == '/';
}

void lab19_task03(const char *filename){
    FILE *f = fopen(filename, "r");

    char operations[2];
    int values[3];
    int values_amount = 0;

    int c;
    while ((c = fgetc(f)) != EOF){
        if (isdigit(c))
            values[values_amount++] = c - '0';
        else if (isOperation((char) c))
            operations[values_amount - 1] = (char) c;
    }
    fclose(f);

    int result;
    if (values_amount == 2)
        result = calculateExpression(values[0], values[1], operations[0]);
    else{
        if ((operations[1] == '*' || operations[1] == '/') &&
            (operations[0] == '+' || operations[0] == '-'))
            result = calculateExpression(
                    values[0],
                    calculateExpression(values[1], values[2], operations[1]),
                    operations[0]);
        else
            result = calculateExpression(
                    calculateExpression(values[0], values[1], operations[0]),
                    values[2],
                    operations[1]);
    }

    f = fopen(filename, "a");
    fprintf(f, "%d", result);
    fclose(f);
}

void test_calculate_the_value_end(){
    char lab19_task03_str[] = "9 - 2 * 2 ";
    char lab19_task03_out_str[] = "9 - 2 * 2 5";
    const char filename[] = "3.txt";
    write(filename, lab19_task03_str);

    lab19_task03(filename);

    assert(cmpStrFile(lab19_task03_out_str, filename));
}

void saves_str_Word(const char *filename, const char *seq){
    long filesize = getFileSize(filename) + 1;
    char *buffer = malloc(filesize);

    FILE *f = fopen(filename, "r");

    char *current_word = buffer;
    while (fscanf(f, "%s", current_word) == 1) {
        if (strstr(current_word, seq)) {
            current_word += strlen(current_word);
            *current_word = ' ';
            current_word++;
        }
    }
    *current_word = 0;

    fclose(f);

    write(filename, buffer);

    free(buffer);
}

void test_saves_str_Word(){
    char lab19_task04_str[] = "adf ceab rgds asabend gthabrr dendroid adbt";
    char lab19_task04_out_str[] = "asabend dendroid ";
    const char filename[] = "4.txt";
    write(filename, lab19_task04_str);

    saves_str_Word(filename, "end");

    assert(cmpStrFile(lab19_task04_out_str, filename));
}

int wordLen(WordDescriptor wd){
    return wd.end - wd.begin;
}

void ConvertsStrLongWord(const char *filename){
    long filesize = getFileSize(filename) + 1;
    char *buffer = malloc(filesize);

    FILE *f = fopen(filename, "r");

    char *current_word = buffer;

    while (fgets(current_word, filesize, f) != NULL) {
        WordDescriptor wd, longest_wd;
        wd.begin = wd.end = longest_wd.begin = longest_wd.end = current_word;

        int max_len = 0;
        while (getWord(wd.end, &wd)) {
            int cur_len = wordLen(wd);
            if (cur_len > max_len) {
                longest_wd = wd;
                max_len = cur_len;
            }
        }

        memcpy(current_word, longest_wd.begin, max_len);
        current_word += max_len;
        *current_word = '\n';
        current_word++;
    }
    *current_word = 0;

    fclose(f);

    write(filename, buffer);

    free(buffer);
}

void test_ConvertsStrLongWord(){
    char lab19_task05_str[] = "asd adfrgb asdv sd ca dfe\n"
                              "trewerwerwge dfa asdfvdf asdv adf\n"
                              "fhasdh sdfaab iejff sadjfhugwfihf\n";
    char lab19_task05_out_str[] = "adfrgb\n"
                                  "trewerwerwge\n"
                                  "sadjfhugwfihf\n";
    const char filename[] = "5.txt";
    write(filename, lab19_task05_str);

    ConvertsStrLongWord(filename);

    assert(cmpStrFile(lab19_task05_out_str, filename));
}

void lab19_task06_deletePolinomXRoot(const char *filename){
    double lab19_task06_factors[] = {1.0, -7.0, 10.0, 1.0, -2.0, 1.0};
    int lab19_task06_powers[] = {3, 2, 0, 2, 1, 0};
    int lab19_task06_mon_amounts[] = {3, 3};
    int lab19_task06_pol_amount = 2;

    polynomial *ps = createPolynomialsFromArray(
            lab19_task06_powers,
            lab19_task06_factors,
            lab19_task06_mon_amounts,
            lab19_task06_pol_amount);

    FILE *f = fopen(filename, "wb");

    savePolynomials(ps, f, lab19_task06_pol_amount);

    fclose(f);
}

void lab19_deletePolinomXRoot(const char *filename, double x){
    FILE *f = fopen(filename, "rb");

    int pol_amount;
    polynomial *ps = loadPolynomials(f, &pol_amount);
    fclose(f);

    int i = 0;
    while (i < pol_amount)
        if (fabs(calculatePolynomial(ps[i], x)) < 0.00001) {
            freePolynomial(ps + i);
            ps[i] = ps[--pol_amount];
        }
        else
            i++;

    f = fopen(filename, "wb");
    savePolynomials(ps, f, pol_amount);
    fclose(f);
}

void test_deletePolinomXRoot(){
    const char filename[] = "6.txt";
    lab19_task06_deletePolinomXRoot(filename);

    lab19_deletePolinomXRoot(filename, 1);

    double factors[] = {1.0, -2.0, 1.0};
    int powers[] = {2, 1, 0};
    int mon_amounts[] = {3};
    int pol_amount = 1;
    polynomial *res = createPolynomialsFromArray(
            powers,
            factors,
            mon_amounts,
            pol_amount);

    FILE *f = fopen(filename, "rb");
    int f_pol_amount;
    polynomial *ps = loadPolynomials(f, &f_pol_amount);
    fclose(f);

    assert(pol_amount == f_pol_amount);
    assert(!memcmp(res, ps, pol_amount));
}

int readInt(FILE *f){
    int x;
    fread(&x, sizeof (int), 1, f);

    return x;
}

void writeInt(int x, FILE *f){
    fwrite(&x, sizeof (int), 1, f);
}

void separatePositiveNegativeInFile(const char *fileName) {
    int size = (int) (getFileSize(fileName) / sizeof (int));

    FILE *f = fopen(fileName, "rb");
    int positiveArray[size / 2];
    int negativeArray[size / 2];
    int sizeP = 0;
    int sizeN = 0;
    for (int i = 0; i < size; ++i) {
        int x = readInt(f);
        if(x > 0)
            positiveArray[sizeP++] = x;
        if(x < 0)
            negativeArray[sizeN++] = x;
    }
    fclose(f);
    f = fopen(fileName, "wb");
    fwrite(positiveArray, sizeof(int), sizeP, f);
    fwrite(negativeArray, sizeof(int), sizeN, f);
    fclose(f);
}

void generateFileTask7(const char *fileName){
    FILE *f = fopen(fileName, "wb");

    int a[] = {2, -4, 6, 7, -9, -10,11,-12};
    fwrite(a,1,sizeof(a),f);
    fclose(f);
}
void task_separatePositiveNegativeInFile(){
    const char filename[] = "7.txt";

    generateFileTask7(filename);

    separatePositiveNegativeInFile(filename);
    int a[8];
    int a1[] = {2,6, 7, 11, -4, -9, -10, -12};
    FILE *f = fopen(filename,"rb");

    fread(a,sizeof(int),8,f);
    fclose(f);
    assert(memcmp(a, a1, sizeof(int) *8) == 0);
}

void lab19_task08_generate_file(const char *filename){
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    0, 5, 4,
                    -1, 0, 0,
                    1, 3, 0
            },
            3, 3
    );

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    0, 5, 4, 3,
                    5, 1, 3, 2,
                    4, 3, 0, 1,
                    3, 2, 1, 7
            },
            4, 4
    );

    matrix ms[] = {m1, m2};

    FILE *f = fopen(filename, "wb");
    outputMatricesSquareFBin(ms, 2, f);

    fclose(f);

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void lab19_replaceMatrixSymmetricTheTransposed(const char *filename){
    FILE *f = fopen(filename, "rb");

    int n;
    matrix *ms = createArrayOfMatricesSquareFBin(f, &n);

    fclose(f);

    for (int i = 0; i < n; ++i) {
        if (!isSymmetricMatrix(&ms[i]))
            transposeSquareMatrix(&ms[i]);
    }

    f = fopen(filename, "wb");
    outputMatricesSquareFBin(ms, n, f);
    fclose(f);

    freeMemMatrices(ms, n);
}

void test_replaceMatrixSymmetricTheTransposed(){
    const char filename[] = "8.txt";
    lab19_task08_generate_file(filename);

    lab19_replaceMatrixSymmetricTheTransposed(filename);

    matrix m1 = createMatrixFromArray(
            (int[]) {
                    0, -1, 1,
                    5, 0, 3,
                    4, 0, 0
            },
            3, 3
    );


    matrix m2 = createMatrixFromArray(
            (int[]) {
                    0, 5, 4, 3,
                    5, 1, 3, 2,
                    4, 3, 0, 1,
                    3, 2, 1, 7
            },
            4, 4
    );

    FILE *f = fopen(filename, "rb");
    int n;
    matrix *ms = createArrayOfMatricesSquareFBin(f, &n);
    fclose(f);

    assert(areTwoMatricesEqual(&m1, ms));
    assert(areTwoMatricesEqual(&m2, ms + 1));

    freeMemMatrices(ms, n);
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}



char* loadStrBin(FILE* f){
    size_t len;
    fread(&len, sizeof(size_t), 1, f);

    char *s = (char*) malloc(len + 1);
    fread(s, 1, len, f);
    s[len] = 0;

    return s;
}

char *createCopyStr(const char *s){
    size_t len = strlen_(s) + 1;
    char *result = (char *) malloc(len);
    memcpy(result, s, len);
    return result;
}

sportsMan createSportsMan(
        const char *firstname,
        const char *lastname,
        const char *surname,
        int best_result){
    sportsMan sm;
    sm.firstname = createCopyStr(firstname);
    sm.lastname = createCopyStr(lastname);
    sm.surname = createCopyStr(surname);
    sm.best_result = best_result;

    return sm;
}

sportsMan createSportsManF(FILE *f){
    sportsMan sm;
    sm.firstname = loadStrBin(f);
    sm.lastname = loadStrBin(f);
    sm.surname = loadStrBin(f);
    sm.best_result = readInt(f);

    return sm;
}

void saveStrBin(const char *s, FILE* f){
    size_t len = strlen_(s);
    fwrite(&len, sizeof(size_t), 1, f);
    fwrite(s, 1, len, f);
}

void saveSportsMan(sportsMan sm, FILE *f){
    saveStrBin(sm.firstname, f);
    saveStrBin(sm.lastname, f);
    saveStrBin(sm.surname, f);
    writeInt(sm.best_result, f);
}

void freeSportsMan(sportsMan *sm){
    free(sm->firstname);
    free(sm->lastname);
    free(sm->surname);
    memset(sm, 0, sizeof(sportsMan));
}

void freeSportsManV(void *sm){
    freeSportsMan(sm);
}

void lab19_generate_file(const char *filename){
    FILE *f = fopen(filename, "wb");

    sportsMan sm1 = createSportsMan("Денис", "Денисов", "Денисович", 7);
    sportsMan sm2 = createSportsMan("Фёдор", "Фёдоров", "Фёдорович", 10);
    sportsMan sm3 = createSportsMan("Иван", "Иванов", "Иванович", 8);
    sportsMan sm4 = createSportsMan("Максим", "Максимов", "Максимович", 6);
    sportsMan sm5 = createSportsMan("Егор", "Егоров", "Егорович", 4);

    writeInt(5, f);
    saveSportsMan(sm1, f);
    saveSportsMan(sm2, f);
    saveSportsMan(sm3, f);
    saveSportsMan(sm4, f);
    saveSportsMan(sm5, f);

    fclose(f);

    freeSportsMan(&sm1);
    freeSportsMan(&sm2);
    freeSportsMan(&sm3);
    freeSportsMan(&sm4);
    freeSportsMan(&sm5);
}

int sportsmanCmp(const void * val1, const void * val2){
    sportsMan *sm1 = (sportsMan*) val1;
    sportsMan *sm2 = (sportsMan*) val2;
    if (sm1->best_result < sm2->best_result)
        return -1;
    else if (sm1->best_result == sm2->best_result)
        return 0;
    else
        return 1;
}

void lab19_team(const char *filename, int n){
    lab19_generate_file(filename);

    FILE *f = fopen(filename, "rb");

    int sports_mans_amount = readInt(f);

    if (sports_mans_amount <= n) {
        fclose(f);
        return;
    }

    sportsMan *sms = (sportsMan*) malloc(sports_mans_amount * sizeof(sportsMan));
    for (int i = 0; i < sports_mans_amount; ++i) {
        sms[i] = createSportsManF(f);
    }
    fclose(f);

    qsort(sms, sports_mans_amount, sizeof (sportsMan), sportsmanCmp);

    f = fopen(filename, "wb");
    writeInt(n, f);
    for (int i = sports_mans_amount - n; i < sports_mans_amount; ++i) {
        saveSportsMan(sms[i], f);
    }
    fclose(f);

    for (int i = 0; i < sports_mans_amount; ++i) {
        freeSportsMan(sms + i);
    }

    free(sms);
}

bool sportsmanAllCmp(const sportsMan *sm1, const sportsMan *sm2){
    return sm1->best_result == sm2->best_result &&
           !strcmp(sm1->firstname, sm2->firstname) &&
           !strcmp(sm1->surname, sm2->surname) &&
           !strcmp(sm1->lastname, sm2->lastname);
}

void test_lab19_team(){
    const char filename[] = "9.txt";
    lab19_generate_file(filename);

    lab19_team(filename, 3);

    sportsMan sm1 = createSportsMan("Денис", "Денисов", "Денисович", 7);
    sportsMan sm2 = createSportsMan("Иван", "Иванов", "Иванович", 8);
    sportsMan sm3 = createSportsMan("Фёдор", "Фёдоров", "Фёдорович", 10);

    FILE *f = fopen(filename, "rb");
    int sports_mans_amount = readInt(f);
    sportsMan *sms = (sportsMan*) malloc(sports_mans_amount * sizeof(sportsMan));
    for (int i = 0; i < sports_mans_amount; ++i) {
        sms[i] = createSportsManF(f);
    }
    fclose(f);

    assert(sportsmanAllCmp(sms, &sm1));
    assert(sportsmanAllCmp(sms + 1, &sm2));
    assert(sportsmanAllCmp(sms + 2, &sm3));

    freeSportsMan(&sm1);
    freeSportsMan(&sm2);
    freeSportsMan(&sm3);
    freeSportsMan(sms);
    freeSportsMan(sms + 1);
    freeSportsMan(sms + 2);
    free(sms);
}

void lab19_task10_generate_storehouse_file(const char *filename){
    FILE *f = fopen(filename, "wb");

    storehouse sh;
    sh.records_amount = 7;
    sh.records = malloc(sh.records_amount * sizeof (productExInfo));

    sh.records[0] = createProductExInfo("Лопата", 200, 1200.0);
    sh.records[1] = createProductExInfo("Тарелка", 1000, 200.0);
    sh.records[2] = createProductExInfo("Стул", 120, 11100.0);
    sh.records[3] = createProductExInfo("Блок бумаги", 1200, 700.0);
    sh.records[4] = createProductExInfo("Лампочка", 3200, 200.0);
    sh.records[5] = createProductExInfo("Футболка", 2200, 1200.0);
    sh.records[6] = createProductExInfo("Космический корабль", 3, 123456789000.0);

    saveStorehouse(&sh, f);
    freeStorehouse(&sh);

    fclose(f);
}

void lab19_task10_generate_records_file(const char *filename){
    FILE *f = fopen(filename, "wb");

    int n = 10;
    productInfo* sh = malloc(n * sizeof(productInfo));

    sh[0] = createProductInfo("Лопата", 100);
    sh[1] = createProductInfo("Лампочка", 1199);
    sh[2] = createProductInfo("Стул", 30);
    sh[3] = createProductInfo("Блок бумаги", 1000);
    sh[4] = createProductInfo("Тарелка", 500);
    sh[5] = createProductInfo("Лампочка", 1000);
    sh[6] = createProductInfo("Футболка", 1200);
    sh[7] = createProductInfo("Лампочка", 1000);
    sh[8] = createProductInfo("Космический корабль", 1);
    sh[9] = createProductInfo("Футболка", 1200);

    fwrite(&n, sizeof(int), 1, f);
    for (int i = 0; i < n; ++i) {
        saveProductInfo(&sh[i], f);
        freeProductInfo(&sh[i]);
    }

    fclose(f);
}

void lab19_task10(const char *sh_filename, const char *rs_filename){
    FILE *sh_f = fopen(sh_filename, "rb");
    storehouse sh = loadStorehouse(sh_f);
    fclose(sh_f);

    FILE *rs_f = fopen(rs_filename, "rb");
    updateStorehouse(&sh, rs_f);
    fclose(rs_f);

    sh_f = fopen(sh_filename, "wb");
    saveStorehouse(&sh, rs_f);
    fclose(rs_f);

    freeStorehouse(&sh);
}

void test_lab19_10(){
    const char sh_filename[] = "10sh.txt";
    const char rs_filename[] = "10rs.txt";
    lab19_task10_generate_storehouse_file(sh_filename);
    lab19_task10_generate_records_file(rs_filename);

    lab19_task10(sh_filename, rs_filename);

    storehouse sh;
    sh.records_amount = 6;
    sh.records = malloc(sh.records_amount * sizeof (productExInfo));

    sh.records[0] = createProductExInfo("Лопата", 100, 1200.0);
    sh.records[1] = createProductExInfo("Тарелка", 500, 200.0);
    sh.records[2] = createProductExInfo("Стул", 90, 11100.0);
    sh.records[3] = createProductExInfo("Блок бумаги", 200, 700.0);
    sh.records[4] = createProductExInfo("Лампочка", 1, 200.0);
    sh.records[5] = createProductExInfo("Космический корабль", 2, 123456789000.0);

    FILE* sh_f = fopen(sh_filename, "rb");
    storehouse sh2 = loadStorehouse(sh_f);
    fclose(sh_f);

    assert(sh.records_amount == sh2.records_amount);
    for (int record_index = 0; record_index < sh.records_amount; ++record_index) {
        assert(cmpProductExInfo(sh.records + record_index, sh2.records + record_index));
    }


    freeStorehouse(&sh2);
    freeStorehouse(&sh);
}