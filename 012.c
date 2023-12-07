#include <stdio.h>

// Function to check if the given string matches the pattern "0*1*2*"
int matchPattern(char *str) {
    // Initialize the state variable to keep track of the current state in the automaton
    int state = 0;

    // Loop through each character in the string
    while (*str) {
        // State transitions based on the current state and the current character
        switch (state) {
            // State 0: Expecting '0'
            case 0:
                if (*str == '0') {
                    // Transition to state 1 upon encountering '0'
                    state = 1;
                } else {
                    // Invalid input if '0' is not encountered in state 0
                    printf("Invalid input\n");
                    return 0;  // Not accepted
                }
                break;

            // State 1: Expecting '1' with optional '0'
            case 1:
                if (*str == '1') {
                    // Transition to state 2 upon encountering '1'
                    state = 2;
                } else if (*str == '0') {
                    // Stay in the same state if '0' is encountered
                    // This allows for zero or more '0's after '0' in the pattern
                } else {
                    // Invalid input if neither '1' nor '0' is encountered in state 1
                    printf("Invalid input\n");
                    return 0;  // Not accepted
                }
                break;

            // State 2: Expecting '2' with optional '1'
            case 2:
                if (*str == '2') {
                    // Transition to state 0 upon encountering '2'
                    state = 0;
                } else if (*str == '1') {
                    // Stay in the same state if '1' is encountered
                    // This allows for zero or more '1's after '1' in the pattern
                } else {
                    // Invalid input if neither '2' nor '1' is encountered in state 2
                    printf("Invalid input\n");
                    return 0;  // Not accepted
                }
                break;
        }

        // Move to the next character in the string
        str++;
    }

    // Check if the final state is the accepting state (state 0)
    return state == 0;
}

int main() {
    char str[100];

    // Prompt the user to enter a string
    printf("Enter a string: ");
    
    // Read the input string from the user
    scanf("%s", str);

    // Check if the input string matches the pattern and print the result
    if (matchPattern(str)) {
        printf("Accepted\n");
    } else {
        printf("Not accepted\n");
    }

    return 0;
}