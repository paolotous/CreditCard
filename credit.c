#include <stdio.h>
#include <cs50.h>
#include <math.h>

void check(void);

int main(void){

check();


}



void check(void){

     long num = get_long("Num : ");


    //int modulus = round(num /= 10);
    //int resultmod = modulus % 100;

    int a; // we are gonna use this to get the digits from the first set
    int sumfirst = 0; // use this to ge the sum of the first set
    int num2; // use this for the digit separation after squaring for the first set

    int sumsecond = 0; // use this to get the sum of the second set
    long numsecond = num; // use this to get a copy of the original input value
    int b;  // use this to get the digits from the second set
    int num3; // use this like num2 but for the second set

    bool isValid = false; //check if the card is valid
    string type = " ";  // use this for the card type

    long numfinal = num; //use this to get a copy of the original input but to use to determine the card type
    long first = num; // use this to get the first digit of the input value
    int counter = 0; //use this to count the amount of digits in the original value


    //looping to get the sum of the second set of numbers
    while(numsecond > 0){

    b = numsecond % 10;
     numsecond = numsecond / 100;

      if((b / 10) > 0){
       num3 = b;

       while(num3 > 0){

        b = num3 % 10;
        sumsecond = sumsecond + b;

        num3 = num3 / 10;

       }
      }

      else {
       sumsecond = sumsecond + b;
      }
    }

//-----------------------------------------------------------------------------------------------



    //looping to get the sum of the first set
    num = num/10;

     while(num > 0){

     a = num % 10;

     num = num / 100;

     a = a * 2;

     if( (a / 10) > 0 ){

         num2 = a;
         while(num2 > 0){

         a = num2 % 10;

         sumfirst = sumfirst + a;

         num2 = num2/10;
         }
     }

     else{
         sumfirst = sumfirst + a;
     }

     }

    //---------------------------------------------------------------------------------------------------

    //add the two sums to validate the card
    if((sumfirst + sumsecond) % 10 == 0 ){
     isValid = true;
    }

//find out how many digits are in the original value
     while(numfinal > 0){

     numfinal = numfinal / 10;
     counter++;
    }


//------------------------------------------------------------------------------------------------------------

//Begin validation ------ fix the if statements -- checked for counter and first. they are working fine.

  if(isValid == true){

  while(first > 100){

  first = first / 10;

 }

 //int test = first;
//printf("%i", test);
 //printf("\n");

if((first == 34 || first == 37 ) && counter == 15 ){

 type = "AMEX\n";

 printf("AMEX\n");
 //printf("%s", type);
 //printf("\n");

}

else if((first >= 51 && first <= 55) && counter == 16){


   type = "MASTERCARD";

   printf("MASTERCARD\n");
   //printf("%s", type);
   //printf("\n");

}


else if((first/10) == 4 && (counter == 13 || counter == 16)){


     type = "VISA";

      printf("VISA\n");
     //printf("%s", type);
     //printf("\n");

}

else{
 printf("INVALID\n");
}

}

else {
 printf("INVALID\n");
 //check();
}
}
