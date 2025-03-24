#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Declare global variables
int i, j, hp, variable[100], k; // hp: highest power, variable[]: coefficients of polynomial
float a, b, da, db, ig;        // ig: initial guess, a/b: temporary variables, da/db: derivatives

// Function to input and store initial data (highest power, coefficients, and initial guess)
void initial_data_storing() {
    printf("Enter the greatest power in the equation: ");
    scanf("%d", &hp); // Input the highest power of the polynomial

    j = 0;
    for (i = hp; i > -1; i--) { // Loop to get coefficients of x^i
        printf("Coefficient of x^%d: ", i);
        scanf("%d", &variable[j]);
        j++;
    }

    printf("\nEnter the initial guess: "); // Input the initial guess for the root
    scanf("%f", &ig);
}

// Function to perform Newton-Raphson method for finding the root
void mathmatical_operation() {
    for (k = 1; k <= 20; k++) { // Perform up to 20 iterations
        // Calculate f(x) (value of the polynomial at the current guess)
        j = 0;
        b = 0; // Reset b to 0 for each iteration
        for (i = hp; i >= 0; i--) {
            a = variable[j] * pow(ig, i); // Compute term: coefficient * (ig)^i
            b = a + b;                   // Accumulate terms to compute f(x)
            j++;
        }

        // Calculate f'(x) (derivative of the polynomial at the current guess)
        j = 0;
        db = 0; // Reset db to 0 for each iteration
        for (i = hp; i >= 0; i--) {
            if (i > 0) { // Derivative term exists only for powers > 0
                da = i * variable[j] * pow(ig, i - 1); // Compute derivative term
                db = da + db;                         // Accumulate terms to compute f'(x)
            }
            j++;
        }

        // Update the guess using the Newton-Raphson formula: x_new = x_old - f(x)/f'(x)
        if (db != 0) { // Ensure the derivative is not zero to avoid division by zero
            ig = ig - (b / db); // Update the guess
            printf("x%d = %.15f\n", k, ig); // Print the updated guess
        } else {
            printf("Error: Division by zero encountered (derivative is zero).\n");
            break; // Exit the loop if derivative is zero
        }
    }
}

int main() {
    // Step 1: Input data (polynomial degree, coefficients, and initial guess)
    initial_data_storing();

    // Step 2: Perform the Newton-Raphson method to find the root
    mathmatical_operation();

    return 0;
}
