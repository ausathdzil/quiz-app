#include <ctype.h> // functions used: tolower()
#include <stdio.h> // functions used: printf(), scanf(), fgets(), fopen(), fclose(), fscanf(), fprintf(), perror()
#include <stdlib.h> // functions used: exit(), srand(), rand(), strtof()
#include <string.h> // functions used: strncpy()
#include <stdbool.h> // data type used: bool
#include <time.h> // functions used: time(), clock()

#define NUM_QUESTIONS 15
#define QUIZ_QUESTIONS 5

// program functions
void displayMenu();
void startQuiz();
void writeScore(char playerName[20], float score);
void displayScore();
void displayHelp();

int cmpScores(const void *a, const void *b);

// misc functions
void backToMenu();
void clearInputBuffer();
void clearScreen();
void delay(int number_of_seconds);

enum menu {
    start = 1,
    scores,
    help,
    quit
};

typedef struct {
    char name[20];
    float score;
} player;

int main() {
    enum menu choice;
    char input[2];

    // Infinite loop to display menu, only exits when user chooses to quit
    while (1) {
        displayMenu();

        printf("Input your choice: ");
        fgets(input, sizeof(input), stdin);
        choice = (enum menu)strtol(input, NULL, 10);

        if (choice >= start && choice <= quit) {
            clearInputBuffer();

            switch (choice) {
                case start:
                    printf("\nStarting Quiz...\n");
                    delay(1);
                    clearScreen();
                    startQuiz();
                    break;
                case scores:
                    clearScreen();
                    displayScore();
                    break;
                case help:
                    clearScreen();
                    displayHelp();
                    break;
                case quit:
                    printf("Goodbye");
                    delay(1);
                    return 0;
            }
        } else {
            clearInputBuffer();
            printf("Invalid choice!\n");
            delay(1);
            clearScreen();
        }
    }
}

void displayMenu() {
    printf("\nWELCOME TO C PROGRAMMING QUIZ\n");
    printf("----------------------------\n");
    printf("1. Start Quiz\n");
    printf("2. Scoreboard\n");
    printf("3. Help\n");
    printf("4. Quit\n");
    printf("----------------------------\n\n");
}

void startQuiz() {
    player p;
    char playerName[20], answer;
    float score;
    int n;

    printf("\n");

    printf("Enter your name: ");
    scanf("%s", p.name);
    clearInputBuffer();

    strncpy(playerName, p.name, sizeof(playerName));

    printf("\n");

    printf("Welcome %s! let's start the quiz.\n", p.name);
    delay(1);
    clearScreen();
    printf("----------------------------\n");

    // Array to keep track of questions
    bool question[NUM_QUESTIONS] = {false};

    // Setting the seed for rand() function
    srand((unsigned int)time(NULL));

    // Looping through 5 questions randomly to ask the user
    for (int i = 0; i < QUIZ_QUESTIONS; i++) {
        printf("Question %d\n", i + 1);

        // Generating random number between 1 and 15
        do {
            n = (rand() % NUM_QUESTIONS) + 1;
        } while (question[n - 1]);

        // Setting the question to true to avoid repetition
        question[n - 1] = true;

        switch (n) {
            case 1:
                printf("When was the C programming language developed?\n");
                printf("a. 1970\n");
                printf("b. 1972\n");
                printf("c. 1974\n");
                printf("d. 1976\n");
                printf("---------------------------\n");
                printf("Answer: ");
                scanf(" %c", &answer);
                clearInputBuffer();

                if (tolower(answer) == 'b') {
                    printf("Correct!\n");
                    p.score++;
                    delay(1);
                    clearScreen();
                    printf("---------------------------\n");
                } else {
                    printf("Wrong!\n");
                    delay(1);
                    clearScreen();
                    printf("---------------------------\n");
                }
                break;

            case 2:
                printf("Who developed the C programming language?\n");
                printf("a. Ken Thompson\n");
                printf("b. Dennis Ritchie\n");
                printf("c. Bill Gates\n");
                printf("d. Steve Jobs\n");
                printf("---------------------------\n");
                printf("Answer: ");
                scanf(" %c", &answer);
                clearInputBuffer();

                if (tolower(answer) == 'b') {
                    printf("Correct!\n");
                    p.score++;
                    delay(1);
                    clearScreen();
                    printf("---------------------------\n");
                } else {
                    printf("Wrong!\n");
                    delay(1);
                    clearScreen();
                    printf("---------------------------\n");
                }
                break;

            case 3:
                printf("What is the extension of C file?\n");
                printf("a. .cpp\n");
                printf("b. .c\n");
                printf("c. .html\n");
                printf("d. .java\n");
                printf("---------------------------\n");
                printf("Answer: ");
                scanf(" %c", &answer);
                clearInputBuffer();

                if (tolower(answer) == 'b') {
                    printf("Correct!\n");
                    p.score++;
                    delay(1);
                    clearScreen();
                    printf("---------------------------\n");
                } else {
                    printf("Wrong!\n");
                    delay(1);
                    clearScreen();
                    printf("---------------------------\n");
                }
                break;

            case 4:
                printf("Which one is not a data type in C?\n");
                printf("a. int\n");
                printf("b. float\n");
                printf("c. char\n");
                printf("d. string\n");
                printf("---------------------------\n");
                printf("Answer: ");
                scanf(" %c", &answer);
                clearInputBuffer();

                if (tolower(answer) == 'd') {
                    printf("Correct!\n");
                    p.score++;
                    delay(1);
                    clearScreen();
                    printf("---------------------------\n");
                } else {
                    printf("Wrong!\n");
                    delay(1);
                    clearScreen();
                    printf("---------------------------\n");
                }
                break;

            case 5:
                printf("Which one is not a valid variable name in C?\n");
                printf("a. name\n");
                printf("b. Name\n");
                printf("c. NAME\n");
                printf("d. 1name\n");
                printf("---------------------------\n");
                printf("Answer: ");
                scanf(" %c", &answer);
                clearInputBuffer();

                if (tolower(answer) == 'd') {
                    printf("Correct!\n");
                    p.score++;
                    delay(1);
                    clearScreen();
                    printf("---------------------------\n");
                } else {
                    printf("Wrong!\n");
                    delay(1);
                    clearScreen();
                    printf("---------------------------\n");
                }
                break;

            case 6:
                printf("Which one is not a valid function name in C?\n");
                printf("a. function1\n");
                printf("b. function_1\n");
                printf("c. 1function\n");
                printf("d. FUNCTION1\n");
                printf("---------------------------\n");
                printf("Answer: ");
                scanf(" %c", &answer);
                clearInputBuffer();

                if (tolower(answer) == 'c') {
                    printf("Correct!\n");
                    p.score++;
                    delay(1);
                    clearScreen();
                    printf("---------------------------\n");
                } else {
                    printf("Wrong!\n");
                    delay(1);
                    clearScreen();
                    printf("---------------------------\n");
                }
                break;

            case 7:
                printf("Which one is not a valid header file in C?\n");
                printf("a. stdio.h\n");
                printf("b. stdlib.h\n");
                printf("c. string.c\n");
                printf("d. math.h\n");
                printf("---------------------------\n");
                printf("Answer: ");
                scanf(" %c", &answer);
                clearInputBuffer();

                if (tolower(answer) == 'c') {
                    printf("Correct!\n");
                    p.score++;
                    delay(1);
                    clearScreen();
                    printf("---------------------------\n");
                } else {
                    printf("Wrong!\n");
                    delay(1);
                    clearScreen();
                    printf("---------------------------\n");
                }
                break;

            case 8:
                printf("Which one is not a valid operator in C?\n");
                printf("a. +\n");
                printf("b. *\n");
                printf("c. /\n");
                printf("d. x\n");
                printf("---------------------------\n");
                printf("Answer: ");
                scanf(" %c", &answer);
                clearInputBuffer();

                if (tolower(answer) == 'd') {
                    printf("Correct!\n");
                    p.score++;
                    delay(1);
                    clearScreen();
                    printf("---------------------------\n");
                } else {
                    printf("Wrong!\n");
                    delay(1);
                    clearScreen();
                    printf("---------------------------\n");
                }
                break;

            case 9:
                printf("Which one is not a valid keyword in C?\n");
                printf("a. if\n");
                printf("b. else\n");
                printf("c. do\n");
                printf("d. loop\n");
                printf("---------------------------\n");
                printf("Answer: ");
                scanf(" %c", &answer);
                clearInputBuffer();

                if (tolower(answer) == 'd') {
                    printf("Correct!\n");
                    p.score++;
                    delay(1);
                    clearScreen();
                    printf("---------------------------\n");
                } else {
                    printf("Wrong!\n");
                    delay(1);
                    clearScreen();
                    printf("---------------------------\n");
                }
                break;

            case 10:
                printf("Which one is not a valid function in C?\n");
                printf("a. gets()\n");
                printf("b. scan()\n");
                printf("c. printf()\n");
                printf("d. main()\n");
                printf("---------------------------\n");
                printf("Answer: ");
                scanf(" %c", &answer);
                clearInputBuffer();

                if (tolower(answer) == 'b') {
                    printf("Correct!\n");
                    p.score++;
                    delay(1);
                    clearScreen();
                    printf("---------------------------\n");
                } else {
                    printf("Wrong!\n");
                    delay(1);
                    clearScreen();
                    printf("---------------------------\n");
                }
                break;

            case 11:
                printf("What is the extension of C header file?\n");
                printf("a. .cpp\n");
                printf("b. .c\n");
                printf("c. .h\n");
                printf("d. .java\n");
                printf("---------------------------\n");
                printf("Answer: ");
                scanf(" %c", &answer);
                clearInputBuffer();

                if (tolower(answer) == 'c') {
                    printf("Correct!\n");
                    p.score++;
                    delay(1);
                    clearScreen();
                    printf("---------------------------\n");
                } else {
                    printf("Wrong!\n");
                    delay(1);
                    clearScreen();
                    printf("---------------------------\n");
                }
                break;

            case 12:
                printf("What programming language is most similar to C?\n");
                printf("a. C++\n");
                printf("b. Python\n");
                printf("c. Java\n");
                printf("d. JavaScript\n");
                printf("---------------------------\n");
                printf("Answer: ");
                scanf(" %c", &answer);
                clearInputBuffer();

                if (tolower(answer) == 'a') {
                    printf("Correct!\n");
                    p.score++;
                    delay(1);
                    clearScreen();
                    printf("---------------------------\n");
                } else {
                    printf("Wrong!\n");
                    delay(1);
                    clearScreen();
                    printf("---------------------------\n");
                }
                break;

            case 13:
                printf("What can C be used for?\n");
                printf("a. Web Development\n");
                printf("b. Machine Learning\n");
                printf("c. Database Management\n");
                printf("d. All of the above\n");
                printf("---------------------------\n");
                printf("Answer: ");
                scanf(" %c", &answer);
                clearInputBuffer();

                if (tolower(answer) == 'd') {
                    printf("Correct!\n");
                    p.score++;
                    delay(1);
                    clearScreen();
                    printf("---------------------------\n");
                } else {
                    printf("Wrong!\n");
                    delay(1);
                    clearScreen();
                    printf("---------------------------\n");
                }
                break;

            case 14:
                printf("Which one is a valid integer constant?\n");
                printf("a. 123\n");
                printf("b. 123.45\n");
                printf("c. 123,45\n");
                printf("d. 123e-2\n");
                printf("---------------------------\n");
                printf("Answer: ");
                scanf(" %c", &answer);
                clearInputBuffer();

                if (tolower(answer) == 'a') {
                    printf("Correct!\n");
                    p.score++;
                    delay(1);
                    clearScreen();
                    printf("---------------------------\n");
                } else {
                    printf("Wrong!\n");
                    delay(1);
                    clearScreen();
                    printf("---------------------------\n");
                }
                break;

            case 15:
                printf("Which one is a valid floating point constant?\n");
                printf("a. 123\n");
                printf("b. 123.45\n");
                printf("c. 123,45\n");
                printf("d. 123e-2\n");
                printf("---------------------------\n");
                printf("Answer: ");
                scanf(" %c", &answer);
                clearInputBuffer();

                if (tolower(answer) == 'b') {
                    printf("Correct!\n");
                    p.score++;
                    delay(1);
                    clearScreen();
                    printf("---------------------------\n");
                } else {
                    printf("Wrong!\n");
                    delay(1);
                    clearScreen();
                    printf("---------------------------\n");
                }
                break;

            default:
                break;
        }
    }

    // Score formula
    score = ((p.score / 5) * 100);

    clearScreen();

    printf("----------------------------\n");
    printf("Your score is %.2f\n", score);
    if (score == 100) {
        printf("Excellent!\n");
    } else if (score >= 80) {
        printf("Good Job!\n");
    } else if (score >= 60) {
        printf("Well Done!\n");
    } else if (score >= 40) {
        printf("Try Again!\n");
    } else {
        printf("You Failed!\n");
    }
    printf("----------------------------\n\n");

    // Calls writeScore function to save player name and score to file
    writeScore(playerName, score);

    backToMenu();
}

void writeScore(char playerName[20], float score) {
    FILE *fptr;

    fptr = fopen("scoreboard.txt", "a");

    if (fptr == NULL) {
        perror("Error opening file!");
        exit(1);
    }

    // Saving player name and score to file
    fprintf(fptr, "%s %.2f\n", playerName, score);

    fclose(fptr);
}

void displayScore() {
    player p[10];
    int numPlayers = 0;

    FILE *fptr;
    fptr = fopen("scoreboard.txt", "r");

    if (fptr == NULL) {
        printf("No player has played the game yet!\n\n");
        backToMenu();
    } else {
        char scoreStr[20];

        // Tracking number of players
        while (fscanf(fptr, "%19s %19s", p[numPlayers].name, scoreStr) != EOF) {
            p[numPlayers].score = strtof(scoreStr, NULL);
            numPlayers++;
        }

        fclose(fptr);

        // Sorting the players by score
        qsort(p, numPlayers, sizeof(player), cmpScores);

        // Setting the maximum number of players to display
        int numToDisplay = numPlayers < 5 ? numPlayers : 5;

        printf("\nSCOREBOARD\n");
        printf("----------------------------\n");

        // Displaying top 5 players
        for (int i = 0; i < numToDisplay; i++) {
            printf("%d. %s %.2f\n", i + 1, p[i].name, p[i].score);
        }

        printf("----------------------------\n\n");

        backToMenu();
    }
}

int cmpScores(const void *a, const void *b) {
    // Typecasting
    const player *p1 = (const player *) a;
    const player *p2 = (const player *) b;

    // Sorting scores in descending order
    if (p1->score < p2->score) {
        // p1 comes after p2
        return 1;
    } else if (p1->score > p2->score) {
        // p1 comes before p2
        return -1;
    } else {
        return 0;
    }
}

void displayHelp() {
    // Displaying help
    printf("\nThis is a simple Quiz program using C programming language.\n");
    printf("-------------------------------------------------------------------\n");
    printf("You will be asked 5 questions.\n");
    printf("You can choose the correct answer from the given options.\n");
    printf("Input the alphabet of the correct answer. Eg: a\n");
    printf("At the end of the Quiz, you will get the score.\n");
    printf("Your score will be calculated and displayed at the scoreboard menu.\n");
    printf("-------------------------------------------------------------------\n\n");

    backToMenu();
}

void backToMenu() {
    printf("Input any key to go back to main menu\n");
    getchar();
    getchar();
    clearScreen();
}

void clearInputBuffer() {
    int c;

    // Clearing the input buffer after every input
    while ((c = getchar()) != '\n' && c != EOF);
}

void clearScreen() {
    // Clearing the screen for better user experience
    printf("\033[2J\033[H");
}

void delay(int number_of_seconds) {
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // Looping till required time is not achieved
    while (clock() < start_time + milli_seconds);
}