// Randomly generate numbers between a min and max for user to guess.


//adding in all the extras
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//creating variables for min and max
#define MIN 1
#define MAX 1000

//initializing functions
void guessGame(void);
bool isCorrect(int guess, int answer); 

int main(void) {
    //random number based on current time
   //srand(time(0));

   //runs guessGame function
   guessGame();
} // end main



//guessGame function, returns nothing and takes nothing
void guessGame(void) {
    
    //initialize variables
   int response =0;
   int guess = 0;

    printf("Hello Deb");
   //do while loop
   do {

      //Creates answer variables that is 1 + a random val
      int answer = 1 + rand() % MAX;

      //Displays rules to user
      printf("I have a number between %d and %d.\n", MIN, MAX);

      // Prompts user
      puts("Can you guess my number?\n"
           "Please type your first guess.");

      //Adds question mark
      printf("%s", "? ");
      

      //takes user input in
      scanf("%d", &guess);

      // while user input doesnt equal answer using isCorrect function
      while (!isCorrect(guess, answer)) {
         scanf("%d", &guess);
      }


      puts("\nExcellent! You guessed the number!\n"
         "Would you like to play again?");
      printf("%s", "Please type (1=yes, 2=no)? ");
      scanf("%d", &response);
      puts("");

   } while (response == 1);
} // end function guessGame

// isCorrect function, returns boolean and takes two ints
bool isCorrect(int guess, int answer) {

    //initialize return as false
    bool correct = false;

   // change return to true if guess equals answer
   if (guess == answer) {
      correct = true;
   }

   // if guess is less than answer print Too Low, else print Too High
   if (guess < answer) {
      printf( "%s", "Too low. Try again.\n? " );
   }
   else {
      printf( "%s", "Too high. Try again.\n? " );
   }

   return correct;
} // end function isCorrect



/**************************************************************************
 * (C) Copyright 1992-2012 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 **************************************************************************/
