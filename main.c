#include <stdio.h>
#include<conio.h>
#include <stdlib.h>
#include<math.h>
#include <stdbool.h>


const long int p_no = 1234;
double balance = 1000;

// function that checks if a number is positive or not
bool checkPos(double num){
    if(num < 0){
        return false;
    }
    else{
        return true;
    }

}

// function that verifies the pin
bool verifyPin(long int pin_no_to_be_checked){
    if(pin_no_to_be_checked == p_no){
        return true;
    }
    else
        return false;
}

// function that checks the balance:
void checkBalance(){
    printf(" Current Balance : $ %.2lf", balance);
}

//function that withdraws money
void withdrawMoney(double amn){
    if(balance<amn){
        printf("Insufficient Balance!\n");
    }
    else if(checkPos(amn) == false){
        printf("Enter only positive amount!\n");
    }
    else{
        printf("Amount %.2lf withdrawn successfully.\n", amn);
        balance = balance - amn;
    }
}

//function that deposits money
void depositMoney(double amn){
    if(checkPos(amn) == false){
        printf("Enter only positive amount!\n");
    }
    else if (amn > 5000){
        printf("The deposit amount doesn't exceed a daily limit of $5000.\n");
    }
    else{
        printf("Amount %.2lf deposited successfully.\n", amn);
        balance = balance + amn;
    }
}

int main()
{
    long int pin_number;
    bool verify_status; // catches the bool value thrown from the verifyPin function
    int sw;

    printf("ATM MACHINE\n");
    printf("Enter you pin:");
    scanf("%ld", &pin_number);
    //Verify pin
    verify_status = verifyPin(pin_number);
    if(verify_status == false){
        printf("Incorrect pin. Try again.\n");
        return 0; // terminates program. Can also use exit(0);
    }
    //if the pin is correct, proceed forward.
    else{
        //Access granted to ATM functionalities
        system("cls");
        double amount;
        printf("ATM Menu");
        printf("\n \n") ;

        printf("1. Check Balance\n2. Withdraw Money\n3. Deposit Money\n4. Exit\n");
        scanf("%d", &sw);
        switch(sw){
            case 1:
                checkBalance();
                break;
//                return 0;
            case 2:
                printf("Enter the amount to be withdrawn:");
                scanf("%lf", &amount );
                withdrawMoney(amount);
                checkBalance();
                return 0;
            case 3:
                printf("Enter the amount to be deposited:");
                scanf("%lf", &amount );
                depositMoney(amount);
                checkBalance();
                return 0;
            case 4:
                 return 0;
            default:

                printf("Invalid selection !");
                return 0;

        }
    }

return 0 ;
}
