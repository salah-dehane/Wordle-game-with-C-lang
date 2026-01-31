

/* Copyright (c) 2026 Salah eddine Dehane. All rights reserved.
 This code is for educational purposes only.
 No redistribution or commercial use allowed.
*/


/*    if you have a problem with the color in the console of windows

    watch this video " https://youtu.be/NU1O3ENTfgY?si=vjE4TM2P3B6fCX6t "     */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define  green  "\033[1;42m"
#define  yellow "\033[1;43m"
#define  gray   "\033[97;100m"
#define  res  "\033[0m"

int main() {

    char *words[12] = { "apple", "bread", "chair", "glass", "green",
    "happy", "plant", "house", "water", "world",
    "today", "smile" };
    int N=5;  //الثابت لي نديروه شرط أو مقياس نقيسو عليه
    int F;  //المتغير تع ارسال الرسائل اذا جاب الكلمة ولا نقولولو عاود المحاولة
    char word[6];  //الكلمة العشوائية لي خيرها البرنامج
    char input[6];  //الكلمة لي يدخلها المستخدم
    char inputs[30][70];  //المصفوفة لي نخبيو فاها الكلمات لي كتبهم المستخدم باه مبعد نظهروهم كمحاولات سابقة
    int i;  //خاص بمقارنة الحروف
    int j;  //خاص بمقارنة الحروف الغير صحيحة ولا اللي في غير بلاصتها
    int k=-1;  //متغير تع المصفوفة تع الكلمات السابقة باه مايبقاش يتعود اي في بلاصة i
    int Y1G0;  //النتغير تع اذا كان الرف أصفر او لا باه نكتبوه بالرمادي
    int y=5;  //المتغير تع الكلمات لي كتبهم اللاعب باه نظهروهم
    int y1=0;  //المتغير تع الحروف تع الكلمات لي دخلهم من قبل اللاعب من اجل طباعتهم
    int y2=y1;  // يأخذ قيمة تع y1
    int y3=0; //باش نعودو الكلمات لي كتبهم من الصفر
    int z;  //متغير باش نطبعو الكاريات الرمادية وكذلك الرسائل ورا ما يدخل اللاعب الكلمة
    int turn=5;  //المتغير تع عدد المحاولات

    srand(time(NULL));
    int randomword = rand() % 12;

    for(i=0;i<N;i++){
        word[i]=words[randomword][i];
    }

    for(i=0;i<N;i++){
        word[i] = toupper(word[i]);
    }

   // printf("    the word : %s\n\n",word); // من هنا نقدر نحبس أنو البرنامج يعطيني الكلمة لي راح نحوس علاها فقط نديرو كومونتار

    printf(res"=========={"green"Welcome to Wordle!"res"}==========\n");
    printf("\n        "yellow"Guess the 5-letter word.\n"res);
    printf("\n          "yellow"You have 5 attempts.\n"res);
    printf("\n      Enter your guess (5 letters): ");

    while(turn>0){
        scanf("%s",&input);
        for(i=0;i<N;i++){
            input[i] = toupper(input[i]);
        }
        if(strlen(input)!=N){ // درت إذا كان عدد أحرف الكلمة أكبر أو أقل من خمسة أحرف مايقبلهاش و يقلك دير كلمة فاها 5 حروف
            printf("\n    Error! your word is not 5 letters. Please enter exactly 5 letters : ");
        }else{
            for(y=turn;y<N;y++){ // هذا باه يعطيني الكلمات لي كتبتهم من قبل كمحاولات سابقة
                printf("\n      ");
                while(y1<y2+N){
                    printf("%s",inputs[y3]);
                    y1++;
                    y3++;
                }
                y2=y1;
            }
            y3=0;
            printf("\n      ");
            for(i=0;i<N;i++){
                k++;
                if(word[i]==input[i]){ // يطبع بلخضر
                    printf(green" %c "res,input[i]);
                    snprintf(inputs[k],70,"\033[1;42m %c \033[0m",input[i]);
                }else{
                    Y1G0=0;
                    for(j=0;j<N;j++){
                        if(Y1G0==0){ // يطبع بالأصفر
                            if(toupper(word[j])==toupper(input[i])){
                                printf(yellow" %c "res,toupper(input[i]));
                                snprintf(inputs[k],70,"\033[1;43m %c \033[0m",input[i]);
                                Y1G0=1;
                            }
                        }
                    }
                    if(Y1G0==0){ // يطبع رمادي
                        printf(gray" %c "res,toupper(input[i]));
                        snprintf(inputs[k],70,"\033[97;100m %c \033[0m",input[i]);
                    }
                }
            }
            F=0;
            for(i=0;i<N;i++){ // كونتار باه الكود لي من ورا هذا يطبع أنو جاب الكلمة أو أنو ماجابهاش و يقولو عاود ألعب
                if(word[i]==input[i]){
                    F++;
                }
            }
            if(F==N){
                for(z=turn-1;z>0;z--){
                    printf("\n      "gray"               "res);
                }
                printf("\n\n     Congratulations! You guessed the correct word.\n");
                break;
            }else{
                for(z=turn-1;z>0;z--){
                    printf("\n      "gray"               "res);
                }
                printf("\n\n     Sorry, the word is incorrect.");
                if(turn>1){
                    printf(" Try again. You have %d attempts left : ",turn-1);
                }
            }
            turn--; // كونتار بدا بقيمة 5 و ينقص كل محاولة
        }
    }
    if(turn==0 && F!=N){ // إذا فضو المحاولات و ماجابش الكلمة يقولو كملت اللعبة و حض أوفر
        printf("\n\n     the word is : %s",word);
        printf("\n\n     Game Over! Thanks for playing. See you soon. \n");
    }
    return 0;
}
