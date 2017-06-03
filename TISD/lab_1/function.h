#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define ERROR 1

bool checkNum(char num[]);
bool checkIntNum(char num[]);
void ReadNum(int arr1[], char num[], int* num_power, int* znak_number, int* lenarr);
void Division(int num1[], int num2[], int lenNum1, int lenNum2,int* lenarr, int* res_power, int result_div[]);
void printResult(int* res_div, int len_arr_res, int znak_result, int res_power);
