#include <stdio.h>
#include <math.h>

// Declare variables globally for easy access across functions
int hp, i, j, k, variable[100]; // hp: highest power, variable[]: coefficients of polynomial
float a, b, f, sum, avg;        // a, b: initial guesses, f: temporary value, sum: function result, avg: midpoint

// Function to input and store initial data (highest power, coefficients, and initial guesses)
void initial_data_storing() {
    printf("Enter the greatest power in the equation: ");
    scanf("%d", &hp); // Input highest power of the polynomial

    j = 0;
    for (i = hp; i > -1; i--) { // Loop to get coefficients of x^i
        printf("Coefficient of x^%d: ", i);
        scanf("%d", &variable[j]);
        j++;
    }

    printf("\nEnter the first initial guess: "); // Input first initial guess
    scanf("%f", &a);

    printf("\nEnter the second initial guess: "); // Input second initial guess
    scanf("%f", &b);
}

// Function to evaluate the polynomial at given points 'a' and 'b'
float suma, sumb, fa, fb; // suma: f(a), sumb: f(b), fa/fb: temporary values
void checking() {
    j = 0;
    suma = 0;
    for (i = hp; i >= 0; i--) { // Evaluate f(a)
        fa = variable[j] * pow(a, i);
        suma = fa + suma;
        j++;
    }

    j = 0;
    sumb = 0;
    for (i = hp; i >= 0; i--) { // Evaluate f(b)
        fb = variable[j] * pow(b, i);
        sumb = fb + sumb;
        j++;
    }
}

// Function to display the table header and current iteration values
void table() {
    printf("\n%.8f ", a);   // Print current 'a'
    printf("     ");
    printf("%.8f ", b);     // Print current 'b'
    printf("     ");
    printf("%.8f ", avg);   // Print current midpoint (avg)
    printf("     ");
    printf("%.8f ", sum);   // Print f(avg)
}

// Function to perform the bisection method for finding the root
void calculation() {
    for (k = 1; k <= 30; k++) { // Perform up to 30 iterations
        avg = (a + b) / 2;      // Calculate midpoint (avg)

        // Evaluate f(avg)
        j = 0;
        sum = 0;
        for (i = hp; i >= 0; i--) {
            f = variable[j] * pow(avg, i);
            sum = f + sum;
            j++;
        }

        table(); // Display current iteration values

        // Update interval based on the sign of f(avg)
        if (sum > 0) {
            b = avg; // Root lies in [a, avg]
        } else if (sum < 0) {
            a = avg; // Root lies in [avg, b]
        }
    }
}

int main() {
    // Step 1: Input data (polynomial degree, coefficients, and initial guesses)
    initial_data_storing();

    // Step 2: Evaluate the polynomial at initial guesses 'a' and 'b'
    checking();

    // Step 3: Display f(a), f(b), and their product
    printf("\nf(a) = %f", suma);
    printf("\nf(b) = %f", sumb);
    printf("\nf(a) * f(b) = %f", suma * sumb);

    // Step 4: Check if root lies between 'a' and 'b'
    if (suma * sumb < 0) {
        // If true, proceed with the bisection method
        printf("\na");
        for (i = 1; i <= 14; i++) printf(" "); // Formatting spaces
        printf("b");
        for (i = 1; i <= 14; i++) printf(" "); // Formatting spaces
        printf("avg");
        for (i = 1; i <= 14; i++) printf(" "); // Formatting spaces
        printf("f(avg)");
        for (i = 1; i <= 10; i++) printf(" "); // Formatting spaces

        calculation(); // Perform bisection method
        printf("\nYour required root is: %f", avg); // Display final root
    } else {
        // If false, inform the user that the root does not lie in the interval
        printf("\n\nRoot doesn't lie between %f & %f", a, b);
    }

    return 0;
}
