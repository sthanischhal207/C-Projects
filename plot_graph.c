// Function to print the graph
void print_graph(int m, int n) {
    // Loop through each row and column of the graph
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%c ", arr[i][j]); // Print each character with a space
        }
        printf("\n"); // Move to the next line after finishing a row
    }
}

// Function to initialize the graph with axes
void initiate_graph(int m, int n) {
    int halfx = m / 2; // Middle row (Y-axis)
    int halfy = n / 2; // Middle column (X-axis)

    // Fill the graph with spaces and draw the axes
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == halfx) {
                arr[i][j] = '-'; // Draw the X-axis
            } else if (j == halfy) {
                arr[i][j] = '|'; // Draw the Y-axis
            } else {
                arr[i][j] = ' '; // Fill the rest with spaces
            }
        }
    }
}

// Function to update the graph with user input
void user_update(int a, int b, int m, int n) {
    char buffer[10]; // Buffer to store the string representation of the marker

    // Create a string in the format "*(x,y)" for the marker
    sprintf(buffer, "*(%d,%d)", b - (int)(n / 2), (int)(m / 2) - a);

    // Place the marker on the graph starting at position (a, b)
    for (int i = 0; buffer[i] != '\0'; i++) {
        arr[a][b + i] = buffer[i]; // Place each character of the marker in the graph
    }
}
