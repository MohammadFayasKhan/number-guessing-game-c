// Number Guessing Game
// Developed by: @Fayas
// A simple console-based number guessing game in C

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function Declarations
void welcomeMessage();
int generateRandomNumber();
void playGame(int targetNumber);
void thankYouMessage();

int main() {
    // Seed the random number generator
    srand((unsigned int)time(NULL));

    // Display welcome message
    welcomeMessage();

    // Generate a random number between 1 and 100
    int targetNumber = generateRandomNumber();

    // Start the game loop
    playGame(targetNumber);

    // Display closing message
    thankYouMessage();

    return 0;
}

// Displays a welcome message to the user
void welcomeMessage() {
    printf("\n=========================================\n");
    printf("🎯 Welcome to the Number Guessing Game! 🎯\n");
    printf("=========================================\n");
    printf("Try to guess the number between 1 and 100.\n");
    printf("Good luck!\n\n");
}

// Generates a random number between 1 and 100
int generateRandomNumber() {
    return rand() % 100 + 1;
}

// Main game logic
void playGame(int targetNumber) {
    int guess = 0;
    int attempts = 0;

    while (guess != targetNumber) {
        printf("Enter your guess: ");
        if (scanf("%d", &guess) != 1) {
            while (getchar() != '\n'); // Clear invalid input
            printf("⚠️ Please enter a valid number!\n");
            continue;
        }

        attempts++;

        if (guess < targetNumber) {
            printf("🔼 Try a larger number!\n\n");
        } else if (guess > targetNumber) {
            printf("🔽 Try a smaller number!\n\n");
        } else {
            printf("\n🎉 Congratulations! You guessed the number %d in %d attempts.\n\n", targetNumber, attempts);
        }
    }
}

// Displays a thank-you message
void thankYouMessage() {
    printf("=========================================\n");
    printf("Thanks for playing the Number Guessing Game!\n");
    printf("Developed with ❤️ by @Fayas\n");
    printf("=========================================\n\n");
}