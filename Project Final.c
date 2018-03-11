#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>

//Function Declarations
void newGame();
void checknum();
void enter();
void new_game();
void WhoAmI();
int randomnumber();
void drink();
void mainGame2();
void test();

//Global Variables
int secret_number;
int chances =10;
int guess;
int option;

//Main Section: It is the Beginning of the Program Execution
void main()
{
    system("cls"); // Clears the Screen
    newGame(); //Calls the Function 'newGame'
    getch();
}

void newGame()
{
    // This function is the main interface for the program
    int option;
    system("cls");
    printf("\n \n Welcome To FunZone\n");
    printf("********************\n");
    printf("Developed By : SURYA KANDIKONDA & MAHESH ALLAM\n");
    printf("*****************************************************\n");
    printf("\nExplore the Game\n");
    printf("1. WHO AM I? \t 2. Guess The Number \t 3. Change This World\n");
    //Gives the Choices available for the user in the game
    printf("\nEnter your Choice\n");
    scanf("%d",&option);
    switch(option)
    {
        case 1: WhoAmI();
                break;
        case 2: //Call the Function
                mainGame2();
                break;
        case 3: ctw();
                break;
        default: printf("Enter Correct Option\n");
                    newGame();
                    break;
    }
}


//This Function generates random number in the range 0 to n
int randomnumber(lower,upper)
{
    int r;
    srand(time(NULL));
    r = rand()%(upper+1);
    return r;
}

void WhoAmI()
{
    char name[100];
    char dev1[100]= "suryavsbr";
    char dev2[100]= "maheshstr";
    FILE *filepointer;
    int linenumber, count = 0;
    int op;
    char line[250];
    system("cls");
    filepointer = fopen("names.txt", "r");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("Enter Your Name: (With No Spaces) \n");
    scanf("%s",&name);
    if(strcmp(name,dev1)==0 || strcmp(name,dev2)==0)
    {
        printf("\n OMG!!! You Developed Me... You are a True Genius \n");
    }
    else
    {
        //Prints the random line of the file 'names.txt'
        linenumber = randomnumber(0,151);
        if(filepointer!=NULL)
        {
            while(fgets(line, sizeof line, filepointer)!=NULL)
            {
                if(count==linenumber)
                {
                    printf("\nHey %s , You are",name);
                    printf(" %s",line);
                    fclose(filepointer);
                }
                else
                {
                    count++;
                }
            }
            fclose(filepointer);
        }

    }
    printf("\n");
    printf("\n");
    printf("1. Main Menu   2. Play Again\n");
    scanf("%d",&op);
    switch(op)
    {
        case 1: newGame();
                break;
        case 2: WhoAmI();
                break;
        default: printf("Enter Correct Option\n");
                    break;
    }
}

void ctw()
{
    int choice,op;
    system("cls");
    printf("\n");
    printf("\n");
    printf("Woow!! You really want to change this world?\n");
    printf("1. Yes  2. No\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: printf("*****************************\n");
                printf("You Funny !!! First Complete your Graduation!!\n");
                break;
        case 2: printf("Thank God!! You saved me... \n");
                break;
        default: printf("Enter Correct Option\n");
    }
    printf("\n");
    printf("\n");
    printf("1. Main Menu   2. Play Again\n");
    scanf("%d",&op);
    switch(op)
    {
        case 1: newGame();
                break;
        case 2: ctw();
                break;
        default: printf("Enter Correct Option\n");
                    break;
    }

}

void mainGame2()
{
    new_game();
}


void enter()
{
    printf("Enter your guess :\n");
    scanf("%d",&guess);
    checknum();
}
void new_game()
{
    system("cls");
    secret_number = randomnumber(0,100);
    chances = 10;
    printf("\n\n GUESS THE NUMBER!!\n");
    printf("Range from 0 to 100\n");
    printf("Total Chances = 10\n");
    printf("*******************************************\n");
    printf("*******************************************\n\n");
    printf("New Game \n");
    enter();
}
void checknum()
{
    if (guess < secret_number && chances!=1)
    {
        chances=chances-1;
        printf("Remaining Chances are : %d \n",chances);
        printf("Lower!! \n\n\n");
        enter();
    }
    else if(guess>secret_number && chances!=1)
    {
        chances = chances-1;
        printf("Chances are : %d \n",chances);
        printf("Higher!! \n\n\n");
        enter();
    }
    else if(guess == secret_number && chances!=1)
    {
        chances=chances-1;
        printf("Remaining chances are : %d \n",chances);
        printf("Correct!!\n\n\n");
        printf("1. Main Menu    2. Play Again\n");
        scanf("%d",&option);
        switch(option)
        {
            case 1: newGame();
                    break;

            case 2: system("cls");
                    new_game();
                    break;
            default:printf("Enter correct option");
                    break;

        }
    }
    else
    {
        printf("Sorry!!.. Chances Completed \n");
        printf("Secret Number is : %d\n\n\n",secret_number);
        printf("1. Main Menu    2. Play Again\n");
        scanf("%d",&option);
        switch(option)
        {
            case 1: newGame();
                    break;

            case 2: system("cls");
                    new_game();
                    break;
            default:printf("Enter correct option");
                    break;

        }
    }
}
