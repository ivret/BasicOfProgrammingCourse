//
// Created by Иван on 18.05.2024.
//

#ifndef BASICSOFPROGRAMMINGCOURSE_DATA_H
#define BASICSOFPROGRAMMINGCOURSE_DATA_H
#include <stdio.h>
#include <stdbool.h>

typedef struct productInfo{
    char *name;
    int amount;
} productInfo;

typedef struct productExInfo {
    productInfo base_info;
    double cost;
    double total_cost;
} productExInfo;

typedef struct storehouse{
    productExInfo * records;
    int records_amount;
} storehouse;

productExInfo createProductExInfo(const char *name, int amount, double cost);
productExInfo loadProductExInfo(FILE *f);
void saveProductExInfo(const productExInfo *info, FILE *f);
void freeProductExInfo(productExInfo *info);
void printProductExInfo(productExInfo *info);

productInfo createProductInfo(const char *name, int amount);
productInfo loadProductInfo(FILE *f);
void saveProductInfo(const productInfo *info, FILE *f);
void freeProductInfo(productInfo *info);
void printProductInfo(productInfo *info);

storehouse loadStorehouse(FILE *f);
void saveStorehouse(const storehouse *sh, FILE *f);
void freeStorehouse(storehouse *sh);

void updateStorehouse(storehouse *sh, FILE *f);

void printStorehouse(storehouse *sh);
bool cmpProductInfo(productInfo *info1, productInfo *info2);
bool cmpProductExInfo(productExInfo *info1, productExInfo *info2);

#endif //BASICSOFPROGRAMMINGCOURSE_DATA_H
