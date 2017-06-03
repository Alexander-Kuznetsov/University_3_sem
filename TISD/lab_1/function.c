#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define ERROR 1

//Функция возведения в степень
int power(int a, int b){
	int q = a;
	for (int z = 1; z < b; z++)
		a *= q;
	if (b == 0)
		a = 1;
	return a;
}

//Функция которя возвращает количество нулей в начале массива
int zero_count(int num[], int lenNum)
{
    int zero_c = 0;
    for (int i = 0; i < lenNum; i++){
        if (num[i] == 0)
            zero_c++;
        else
            break;
    }
    return zero_c;
}

int GetPosE(char num[]){
    int size = strlen(num);
    int pos_e = size;
    for (int i = 0; i < size; i++)
        if (num[i] == 'e' || num[i] == 'E')
            pos_e = i;
    return pos_e;
}

int GetPosPoint(char num[]){
    int size = strlen(num);
    int pos_point = -1;
    for (int i = 0; i < size; i++)
        if (num[i] == '.')
            pos_point = i;
    return pos_point;
}

int* GetPosZnak(char num[]){
    int size = strlen(num);
    int* arr;                          //Первый элемент массива - кол-во элементов в нем
    int count_znak = 0;

    for (int i = 0; i < size; i++){
        if (num[i] == '+' || num[i] == '-')
            count_znak++;
    }   

    if (count_znak == 0){
        arr = malloc(2 * sizeof(int));
        arr[0] = 1;
        arr[1] = -1;                              //Если в числе нет знака, -1
    }
    if (count_znak > 0)
    {
        arr = malloc((count_znak + 1) * sizeof(int));
        int ind = 1;
        arr[0] = count_znak;
        for (int i = 0; i <= size; i++){
            if (num[i] == '+' || num[i] == '-'){
                arr[ind] = i;
                ind++;
            }
            if (ind > count_znak)
                break;
        }
    }
    return arr;
} 

int GetCountPoint(char num[]){
    int point_count = 0;
    int size = strlen(num);
    for (int i = 0; i < size; i++)
        if (num[i] == '.')
            point_count += 1;
    return point_count;   
}

int GetCountE(char num[]){
    int count_e = 0;
    int size = strlen(num);
    for (int i = 0; i < size; i++)
        if (num[i] == 'E' || num[i] == 'e')
            count_e++;
    return count_e;
}

//кол-во точек
bool CountPoint(char num[]){
    int point_count = GetCountPoint(num);
    if (point_count <= 1)
        return true;
    else{ 
        return false;
    } 
}
//Проверка на количество ESS
bool CountE(char num[]){
    int count_e = GetCountE(num);
    if (count_e <= 1)
        return true;
    else{ 
        return false;
    }
}
//проверка на недопустимые значения
bool isDigit(char num[]){
   char elems[] = "0123456789+-.eE";
   int sizeNum = strlen(num);
   int sizeElems = strlen(elems);
   bool z;
   bool a = true;
   for (int i = 0; i < sizeNum; i++){
       z  = false;
       for (int k = 0; k < sizeElems; k++){
            if (num[i] == elems[k])
                z = true;
       }
       a *= z;
       if (a ==  false)
           return a;
   }

   return a;
}
bool isIntDigit(char num[]){
   char elems[] = "0123456789+-";
   int sizeNum = strlen(num);
   int sizeElems = strlen(elems);
   bool z;
   bool a = true;
   for (int i = 0; i < sizeNum; i++){
       z  = false;
       for (int k = 0; k < sizeElems; k++){
            if (num[i] == elems[k])
                z = true;
       }
       a *= z;
       if (a ==  false)
           return a;
   }

   return a;
}

bool inspectionPoint(char num[]){
    int pos_point = GetPosPoint(num);
    int pos_e = GetPosE(num);
    int* arr_znaks = GetPosZnak(num);    //первый элемент массива - длина массива

    if (pos_point == -1)
        return true;
    
    if (pos_point > pos_e)
        return false;

    free(arr_znaks);
    return true;
}
bool inspectionZnak(char num[]){
    int pos_e = GetPosE(num);
    int* arr_znaks = GetPosZnak(num);    //первый элемент массива - длина массива

    if (arr_znaks[1] == (-1)){
        free(arr_znaks);
        return true;
    }
    if (arr_znaks[0] > 2){
        free(arr_znaks);
        return false; 
    }
    if (arr_znaks[0] == 2){
        if (arr_znaks[1] == 0 && (arr_znaks[2] - 1) == pos_e){  
             free(arr_znaks);
             return true;
        }  
        else{ 
            free(arr_znaks);
            return false;
        }
    }
    if (arr_znaks[0] == 1){
        if (arr_znaks[1] == 0 || (arr_znaks[1] - 1) == pos_e){
            free(arr_znaks);
            return true;
        }
        else{
            free(arr_znaks);
            return false;
        }
    }
    free(arr_znaks);
    return false;
}

bool lenMantissa(char num[]){
    int pos_e = GetPosE(num);
    int count_point = GetCountPoint(num);
    int count_znak = 0;
    int* arr_znaks = GetPosZnak(num);
    
    if (arr_znaks[1] == 0)
        count_znak++;
    free(arr_znaks);
    
    if ((pos_e - count_znak - count_point - 1) >= 30){
        printf("%s\n\n","Overflow of digits in mantissa");
        return false;
    }
    else
        return true;
}

bool lenPower(char num[]){
    int size = strlen(num);
    int pos_e = GetPosE(num);
    int count_e = GetCountE(num);
    int count_znak = 0;    

    if (count_e == 0)
        return true;

    if (num[pos_e + 1] == '+' || num[pos_e + 1] == '-')
        count_znak++;
    
    if (size - pos_e - count_znak > 6){
        printf("%s\n\n","Overflow of digits in Power");
        return false;
    }
    else
        return true;  
}

bool isNumber(char num[]){
    
    int pos_e = GetPosE(num);
    char elems[] = "0123456789";
    int sizeElems = 10;
    for (int i = 0; i < pos_e; i++)
        for (int k = 0; k < sizeElems; k++)
            if (num[i] == elems[k])
                return true;
    return false;
}
bool checkIntNum(char num[]){
    bool q = isNumber(num);
    q *= CountPoint(num);
    q *= CountE(num);
    q *= isIntDigit(num);
    q *= inspectionPoint(num);
    q *= inspectionZnak(num);
    q *= lenMantissa(num);
    q *= lenPower(num);

    return q;
}

bool checkNum(char num[]){
    bool q = isNumber(num);
    q *= CountPoint(num);
    q *= CountE(num);
    q *= isDigit(num);
    q *= inspectionPoint(num);
    q *= inspectionZnak(num);
    q *= lenMantissa(num);
    q *= lenPower(num);

    return q; 
}


void ReadNum(int arr1[], char num[], int* num_power, int* znak_number, int* lenarr){
    int arr[35];
    int LenInputNumber = strlen(num);              //будет хранится длина строки
    int count_point = 0;
    int count_e = 0;
    int count_znak_num = 0;                              //есть ли перед числом знак
    int pos_e = LenInputNumber;
    int pos_point = -1;  
    int Size_arr;
    for (int i = 0; i < LenInputNumber; i++){
         //определение позиции '.'
         if (num[i] == '.'){
            pos_point = i;
            count_point++;
         }
          //Определение позиции e   
         if (num[i] == 'E' || num[i] == 'e'){
            pos_e = i;
            count_e++;
         }
    }
    //проверка на наличие знака перед числом
    if (num[0] == '-' || num[0] == '+')
        count_znak_num++;
    //если знак перед число отрицательный Znak_num = 0; (по умолчанию он  = 1) 
    if (num[0] == '-')
        *znak_number = 0;
    Size_arr = pos_e - count_point - count_znak_num; //определение размера массивa
    
    int z = 0;                               // Переменная которая через пару строк пригодится        
    
    // Перевод чисел до E в int  и заполнение их в массив;
    for (int i = 0; i < (Size_arr + count_point + count_znak_num); i++){
        if (num[i + count_znak_num] != '.')
            arr[i-z] = num[i + count_znak_num] - 48;            //Перводим char в int
        else
           z++; 
    }
    //Подсчет количества в
    int count_ved_zero = 0;
    for (int i = 0; i < Size_arr; i++){
        if (arr[i] == 0)
            count_ved_zero++;
        else
            break;
    }

    //Подсчет количества замыкающих нулей
    int count_zam_zero = 0;
    for (int i = Size_arr - 1; i >= 0; i--){
        if (arr[i] == 0)
            count_zam_zero++;
        else
            break;
    }

    int Size_arr1 = Size_arr - count_ved_zero - count_zam_zero;
    if (Size_arr1 <= 0){
        Size_arr1 = 1;
        count_zam_zero = 0;
        count_ved_zero--;
    }

    for (int i = 0; i < Size_arr1; i++)
        arr1[i] = arr[i + count_ved_zero];
    *lenarr = Size_arr1;
    
    //Определение степени числа (e+iiii)
    if (pos_e != LenInputNumber){
        int prov_znak = 0;
        //проверка на наличие занака после E
        if (num[pos_e + 1] == '-' || num[pos_e + 1] == '+')
            prov_znak = 1;
    
         // перевод степенной части в int
        for (int i = pos_e + 1 + prov_znak; i < LenInputNumber; i++){
            int k = (num[i] - 48);
            k *= power(10, LenInputNumber - i - 1);
            *num_power += k;
        } 
        //Определение знака степени
        if (num[pos_e + 1] == '-')
            *num_power *= -1;
    }
    //Дробную часть переносим в целую, при этом отнимаем от степенной части
    if (pos_point != -1)
        *num_power -= (pos_e - pos_point - 1);
    *num_power += count_zam_zero;
}

//Функция сравнения двух чисел
//Возвращает:
// 0 - num1 = num2
// 1 - num1 > num2
// 2 - num1 < num2 

int Comparison(int num1[], int num2[], int lenNum1, int lenNum2){
    int zero_count1 = 0;
    int zero_count2 = 0;


    //Проверка на наличие нулей в начале массива и их подсчет
    for (int i = 0; i < lenNum1; i++){
        if (num1[i] == 0)
            zero_count1++;
        else
            break;
    }

    for (int i = 0; i < lenNum2; i++){
        if (num2[i] == 0)
            zero_count2++;
        else 
            break;
    }

    //Сравнение на количество элементов в массивах
    if ((lenNum1 - zero_count1) > (lenNum2 - zero_count2))
        return 1;
    else if ((lenNum1 - zero_count1) < (lenNum2 - zero_count2))
        return 2;
    //случай когда количество значимых чисел равны
    else
    {
        int k = zero_count1 - zero_count2;            //не учитываем нули в начале
        for (int i = zero_count1; i < lenNum1; i++){
            if (num1[i] > num2[i-k])                   //Сравниваем поразрядно   
                return 1;
            else if (num1[i] < num2[i - k])
                return 2;
        }
    }    
    return 0;                                          //Случай когда числа равны
}

//Умножение длинного числа на короткое
//Возвращает массив 

int* Multiplication(int num[], int multiplier, int lenNum)
{
    int* arr_multiplication = malloc((lenNum + 1) * sizeof(int));
    int vrem_result;                                              //Переменная для хранения результата поразрядного умножения
    int dop_razryad = 0;                                          //Для хранения лишнего разряда 

    for (int i = lenNum - 1; i >= 0; i--){
         vrem_result = num[i] * multiplier + dop_razryad;         // Умножение столбиком
         arr_multiplication[i + 1] = (vrem_result % 10);          //Заполняем массив с конца                  

         dop_razryad = vrem_result / 10;                          //Значение которое нужно суммировать со следующим разрядом
    }
    arr_multiplication[0] = dop_razryad; 

    return arr_multiplication;
}


//Функция вычитания, Ожидает на вход num1 и num2; num1 >= num2
int* Subtraction(int num1[], int num2[], int lenNum1, int lenNum2, int* len_arr_sub)
{
    int* arr_subtraction;                         //Массив где будет храниться результат вычитания
    int zero_count1 = 0;                          //Количество нулей в массивах
    int zero_count2 = 0;
    //Проверка на наличие нулей в начале массива и их подсчет 
    arr_subtraction = malloc(lenNum1*sizeof(int));

    int k;                       // k - индекс по второму числу
    int i_subtract = 0;               // длина массива, где хранится результат вычитания
    
    for (int i = lenNum1 - 1; i >= zero_count1; i--)       //Идем с конца массива
    {
        k = i - (lenNum1 - lenNum2);                       // k = индексу второго числа для приравнения разрядов
        arr_subtraction[i_subtract] = num1[i] - num2[k];   // вычитаем с первого второе 

        i_subtract++;

        if (k == zero_count2){                             // в случае когда кол-во разрядов не совпадают (например: 12345 123)
            for (int q = lenNum1 - 1 - i_subtract; q >= zero_count1; q--){    // Переносим лишние разряды в результирующий массив    
                arr_subtraction[i_subtract] = num1[q];
                i_subtract++;
            }
            break;
        }
    }
        //Проход по массиву
    for (int i = 0 ; i < i_subtract; i++){
        if (arr_subtraction[i] < 0){                      //если число меньше 0         
            arr_subtraction[i] += 10;                     //из старшего разряда передаем младшему
            arr_subtraction[i + 1] -= 1;
        }

    }

    int q;
    for (int i = 0; i < i_subtract / 2 ; i++){
        q = arr_subtraction[i];
        arr_subtraction[i] = arr_subtraction[i_subtract - i - 1];
        arr_subtraction[i_subtract - i - 1] = q;
    }

    *len_arr_sub = i_subtract;
    return arr_subtraction;
}

void Division(int num1[], int num2[], int lenNum1, int lenNum2, int *lenarr, int *res_power, int result_div[]){
   int vrem_result[lenNum2 + 1];                        //Массив для хранения промежуточного делимого числа
   int ind_num1 = 0;                                    //индекс делимого
   int END = 0;                                         //Выход из цикла
   int result_comparison;                               //Переменная для хранения результата сравнения
   int ind_result_div = 0;                              //Индекс массива результат деления
   int count_dop_razryad = 0;                           // количество лишних разрядов для достижения необходимой точности 
   vrem_result[0] = 0;                                 // Первый элемент нулевой 
   
   for (int i = 1; i <= lenNum2; i++){                  // заполняем массив первыми lennum2 элементами
       if (ind_num1 < lenNum1){                         
            vrem_result[i] = num1[i - 1];               
            ind_num1++;
        }
        else{
            vrem_result[i] = 0;                         //Если закончились разряды делимого, добавляем 0 
            count_dop_razryad++;                        //Увеличиваем счет дополнительных разрядов 
        }
   }

   int count_added_razr = 0;                              //Количество добавленных разрядов за один цикл  
   while (END != 1)
   { 
        result_comparison = Comparison(vrem_result, num2, lenNum2 + 1, lenNum2);             //Сравниваем промежуточное делимое число с делителем        
        count_added_razr = 0;

        while (result_comparison == 2){                                                     // Пока второе делимое больше делителя 
            //printf("%s\n","aaaa" );
            for (int i = 1; i <= lenNum2; i++){                                             // добавляем в конец массива новый разряд 
                vrem_result[i- 1] = vrem_result[i];                                  
            }
            if (ind_num1 < lenNum1){                                                                 
                  vrem_result[lenNum2] = num1[ind_num1];
                  ind_num1++;
                  count_added_razr++;                                                       
            }
            else                                                                            // В случае, если разядов не хватило
            {
                vrem_result[lenNum2] = 0;                                                   // Добавляем 0
                count_dop_razryad++;
                count_added_razr++;
            }
            result_comparison = Comparison(vrem_result, num2, lenNum2 + 1, lenNum2);        //для выхода из цикла сравниваем временное делимое и делитель           
        }

        if (ind_result_div != 0 && count_added_razr > 1){                                  //Если было добавлено больше одного разряда
            for (int i = 0; i < count_added_razr - 1; i++){                                
                result_div[ind_result_div] = 0;
                ind_result_div++;
            }
        }
        
        int vrem_razryad = 0;                                                           //результат деления промежуточного делимого на делитель
        for (int i = 1; i <= 9; i++){                                                   // подставляем числа от 1 до 9
            int* arr_mult = Multiplication(num2, i, lenNum2);                           //Умножаем
            result_comparison = Comparison(arr_mult, vrem_result, lenNum2 + 1, lenNum2 + 1); //Сравниваем
            free(arr_mult);
            if (result_comparison == 0){                                                     //В случае равенства 
                vrem_razryad = i;
                break; 
            }
            if (result_comparison == 1){                        // В случае если при умножении результат > промежуточного делимого 
                vrem_razryad = i - 1;                                                         
                break;
            }
        }
        if (vrem_razryad == 0)                                 
            vrem_razryad = 9;

        int* arr_mult = Multiplication(num2, vrem_razryad, lenNum2);         // Умножаем на полученное число                                                          
        result_div[ind_result_div] = vrem_razryad;                            //запишем в результирующий массив
        ind_result_div++;                                                     
        int len_arr_sub = 0;                                                        
        int* arr_subtraction = Subtraction(vrem_result, arr_mult, lenNum2 + 1, lenNum2 + 1, &len_arr_sub);    //Вычитаем 

        for (int i = 0; i < len_arr_sub; i++)                                       //Запишем результат вычитания во временное делимое
            vrem_result[i] = arr_subtraction[i];
        free(arr_mult);
        free(arr_subtraction);
        //END++;
        int counter = 0;                                           //Индекс для выхода из цикла

        if (ind_num1 >= lenNum1){                                  
            for (int i = 0; i < lenNum2 + 1; i++){                 //Если временное делимое равен 0, и нет разрядов у делимого числа
                  if (vrem_result[i] == 0)
                      counter = 1;
                  else{
                    counter = 0;
                    break;
                  }
            }
        }
        END = counter;                                                // При END = 1 цикл завершается

        if (ind_result_div >= 31){                                    // При достижении необходимой точности завершаем цикл
            END = 1;
            if (ind_num1 < lenNum1)
                count_dop_razryad -= (lenNum1 - ind_num1);
        }

   }
   
    if (ind_result_div  == 31){

      /*  if (result_div[30] >= 5 && result_div[29] != 9)
            result_div[29] += 1;
        ind_result_div--;
        count_dop_razryad--;*/
        if (result_div[30] >= 5)
        {
            result_div[29] += 1;
            ind_result_div--;
            count_dop_razryad--;
            for (int d = 29; d>=1; d--)
            {
                if (result_div[d] >= 9)
                {
                    result_div[d-1]+=1;
                    ind_result_div--;
                    count_dop_razryad--;
                }
                else
                    break;
            }
        }
    }

    *lenarr = ind_result_div;
    *res_power = (-1) * count_dop_razryad;   
}

void printResult(int* res_div, int len_arr_res, int znak_result, int res_power){
    char znak_power;
    char znak_res;

    if (znak_result == 0)
        znak_res = '+';
    else 
        znak_res = '-';
    
    if (res_power >= 0)
        znak_power = '+';



    if((res_power > 99999) || (res_power < -99999))
    {
        printf("ERROR: Overflow the digit of result");
    }
    else
    {
    printf("\n%s\n", "Result:");
    printf("%c", znak_res);
    printf("%s","0.");
    for (int i = 0; i < len_arr_res; i++)
        printf("%d", res_div[i]);
    if /*(res_power != 0)*/(1){
        printf("%s","E");
        if (znak_power == '+') 
            printf("%c",znak_power);
        printf("%d",res_power);
    }


   /* printf("%s","E");
    if (znak_power == '+')
        printf("%c",znak_power);
    printf("%d",res_power);
*/
    }
}
