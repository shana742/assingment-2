#include <stdio.h>
#include <string.h>
#include<ctype.h>

void reverseString(char *input);
void concatenateStrings(char *str1, char *str2);
void checkPalindrome(char *input);
void copyString(char *input);
void getStringLength(char *input);
void countCharFrequency(char *input, char character);
void countVowelsConsonants(char *input);
void askToContinue();

int main() {
    char userInput[100];

    do {
        printf("\nString Operations Menu:\n");
        printf("1. Reverse a string\n");
        printf("2. Concatenate strings\n");
        printf("3. Check palindrome\n");
        printf("4. Copy a string\n");
        printf("5. Length of the string\n");
        printf("6. Frequency of a character\n");
        printf("7. Vowels and consonants count\n");
        printf("8. Exit\n");

       
        int choice;
        printf("Enter your choice (1-8): ");
        scanf("%d", &choice);

        
        switch (choice) {
            case 1:
                reverseString(userInput);
                break;
            case 2:
                printf("Enter the second string to concatenate: ");
                char secondString[100];
                scanf("%s", secondString);
                concatenateStrings(userInput, secondString);
                break;
            case 3:
                checkPalindrome(userInput);
                break;
            case 4:
                copyString(userInput);
                break;
            case 5:
                getStringLength(userInput);
                break;
            case 6:
                printf("Enter the character to find frequency: ");
                char character;
                scanf(" %c", &character);  
                countCharFrequency(userInput, character);
                break;
            case 7:
                countVowelsConsonants(userInput);
                break;
            case 8:
                printf("Exiting program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please enter a number between 1 and 8.\n");
        }
        askToContinue();

    } while (1);

    return 0;
}
void reverseString(char *input) {
    printf("Enter a string: ");
    scanf("%s", input);
    strrev(input);
    
    printf("Reversed string: %s\n");
}

void concatenateStrings(char *str1, char *str2) {
    strcat(str1, str2);
    
    printf("Concatenated string: %s\n", str1);
}

void checkPalindrome(char *input) {
    printf("Enter a string: ");
    scanf("%s", input);
    if (strcmp(input, strrev(strdup(input))) == 0) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }
}

void copyString(char *input) {
    printf("Enter a string: ");
    scanf("%s", input);
    char copiedString[100];
    strcpy(copiedString, input);
    
    printf("Copied string: %s\n", copiedString);
}

void getStringLength(char *input) {
    printf("Enter a string: ");
    scanf("%s", input);
    int length = strlen(input);
    
    printf("Length of the string: %d\n", length);
}

void countCharFrequency(char *input, char character) {
    printf("Enter a string: ");
    scanf("%s", input);
    int frequency = 0;
    for (int i = 0; input[i] != '\0'; ++i) {
        if (input[i] == character) {
            frequency++;
        }
    }
    
    printf("Frequency of '%c' in the string: %d\n", character, frequency);
}

void countVowelsConsonants(char *input) {
    printf("Enter a string: ");
    scanf("%s", input);
    int vowels = 0, consonants = 0;
    for (int i = 0; input[i] != '\0'; ++i) {
        if (isalpha(input[i])) {
            if (strchr("AEIOUaeiou", input[i]) != NULL) {
                vowels++;
            } else {
                consonants++;
            }
        }
    }
    
    printf("Number of vowels: %d\n", vowels);
    printf("Number of consonants: %d\n", consonants);
}

void askToContinue() {
    char choice;
    printf("Do you want to continue? (y/n): ");
    scanf(" %c", &choice);  

    if (choice != 'y' && choice != 'Y') {
        printf("Exiting program. Goodbye!\n");
        exit(0);
    }
}

