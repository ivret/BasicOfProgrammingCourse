#include "lab_19.h"
#include <string.h>


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
