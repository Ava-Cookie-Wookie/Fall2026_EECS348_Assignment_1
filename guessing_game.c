/*
Program: EECS 348
Description: 
     - This program has a fixed number the user is trying to guess.
     if they guess to high or low  a message will appear indicating the user to go 
     up or down in there guessing. They get three attempts.
Inputs: User is asked to guess a number till they get it right or their guesses are up.
Outputs: The terminal will give feedback like indicating it's too high or low. If they lose a message will appear same if they win.
Collaborators: None
Sources: Claude and ChatGPt were used in the draft raw code.
Author: Ava Kohlmeier
Creation date: 9/8/26
Revision Date: 9/8/26
Revisions: Adding a precaution to the ChatGPT code that prevents none numbers from crashing the program
*/

#include <stdio.h> //The standard input/output library

int main(void) { //Opens the code and says this function takes no parameters/arguments
    int secret = 7; // the sercret number is 7 an int
    int guess; //The users guess for the number (an int) 
    int correct = 0; // If this number changes to 1 (win) before the code is over than the user wins. But if it staeys the same then that tells the program the user lost.

    printf("Guess a number between 1 and 10.\n"); //Asking for the users input for the guess

    for (int attempt = 1; attempt <= 3; attempt++) { //A loop the goes 3 times that adds to attempt. Once the attempts are filled or you guess right the program ends
        printf("Attempt %d/3. Enter your guess: ", attempt); //Ask for another guess if user fals at the start. Also it shows how many more attempts the user has

        if (scanf("%d", &guess) != 1) {// scanf returns 1 only if a number was read. Also, saves the guess
            printf("Invalid input. Please enter a number.\n");  // tell the user their input didn't count
            
            while (getchar() != '\n');// clear the bad character(s) out of the input buffer
            
            attempt--;// undo the increment so this attempt isn't wasted
            
            continue;// skip the rest of this iteration, go to next attempt
        }


        if (guess == secret) { //If the user guess right (opens if statement)
            printf("Correct! You win!\n"); //Prints "Correct! You win!"
            correct = 1; //Changes correct to 1 so the if !correct can't run
            break;//Ends the program
        } else if (guess < secret) { //if the guess is less than the guess
            printf("Too low! Try again.\n"); //Prints "Too low! Try again."
        } else { //if the guess is higher than the guess 
            printf("Too high! Try again.\n"); //Print "Too high! Try again."
        } //Ends if 
    } //End for loop

    if (!correct) { //
        printf("You lose! The secret number was %d.\n", secret); //Print "You lose! The secret number was %d. " along with the secret number
    } // End if

    return 0; //means the program ran successfully
} //End of program

