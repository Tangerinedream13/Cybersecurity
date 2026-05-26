#include <stdio.h>

void get_input(char stuff[], int len);

int main(void)
{
    char username[10];
    char password[10];

    char secret[] = "I like pickleball!";

    printf("Please enter your username: ");
    get_input(username, 10);

    printf("Please enter your password: ");
    get_input(password, 10);

    printf("Welcome, %s\n", username);

    if (secret[0] == '\0') {
        puts("Try again.");
    }

    return 0;
}