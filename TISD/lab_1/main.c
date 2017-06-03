#include "function.h"

int main()
{
	char num1[50];
    char num2[50];
	int num_power1 = 0;
    int num_power2 = 0;
    int znak_number1 = 1;                         //1 - "+" 0 - '-'
    int znak_number2 = 1;
    int lenarr1 = 0;                              //Будем хранить длину массива
    int lenarr2 = 0;
    
     
    printf("Input the first INT number\n");    //Ввод первого числа
    printf("123456789-123456789-123456789-____len(1 number)\n");
	scanf("%40s", num1);
    
    bool checknum1 = checkIntNum(num1);
    if (checknum1 == false){
        printf("\nInput incorrect!\n");
        return ERROR;
    }
    printf("\nInput the second FLOAT number\n");  //Ввод второго числа
    printf("123456789-123456789-123456789-____len(2 number)\n");
    scanf("%40s", num2);
    
    bool checknum2 = checkNum(num2);
    if (checknum2 == false){
        printf("\nInput incorrect!\n");
        return ERROR;
    }
    int arr_num1[35];
    int arr_num2[35];
    ReadNum(arr_num1, num1, &num_power1, &znak_number1, &lenarr1);
    ReadNum(arr_num2,  num2, &num_power2, &znak_number2, &lenarr2);

    if (arr_num2[0] == 0){
        printf("ERROR! Division by 0 is not allowed!\n");
        return 1;
    }
    if (arr_num1[0] == 0){
        int result = 0;
        printf("Result:\n");
        printf("%d\n", result);
        return 1;
    }
    int lenarr_res = 0;
    int res_power = 0;
    int arr_div[35];    
    Division(arr_num1, arr_num2, lenarr1, lenarr2, &lenarr_res, &res_power, arr_div);
    int znak_result = znak_number1 ^ znak_number2;
    int res_power_a = num_power1 - num_power2 + res_power + lenarr_res;
    printResult(arr_div, lenarr_res, znak_result, res_power_a);
 
 return 0;
}
