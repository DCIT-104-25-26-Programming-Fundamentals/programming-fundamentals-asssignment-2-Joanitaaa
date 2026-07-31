// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 5
// =============================================================================
//
// TASK: Fibonacci Sequence Generator
//
// The Fibonacci sequence is a series of numbers where each number is the sum
// of the two numbers before it:
//
//   0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
//
// Write a C++ program with TWO parts, each implemented as a function.
//
// -----------------------------------------------------------------------------
// PART A — Print the First N Terms
// -----------------------------------------------------------------------------
// - Ask the user how many terms (N) to display.
// - Print the first N numbers of the Fibonacci sequence on one line.
//
// Example:
//   How many terms? 7
//   Fibonacci sequence: 0 1 1 2 3 5 8
//
// -----------------------------------------------------------------------------
// PART B — Check if a Number Belongs to the Sequence
// -----------------------------------------------------------------------------
// - Ask the user to enter a number.
// - Determine whether that number is a Fibonacci number.
// - Print an appropriate message.
//
// Example:
//   Enter a number to check: 13
//   13 is a Fibonacci number.
//
//   Enter a number to check: 20
//   20 is NOT a Fibonacci number.
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use a loop (not recursion) to generate the sequence in both parts.
// - N must be a positive integer. If it is not, print an error message.
// - Each part must be implemented in its own function (see scaffold below).
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

// PART A — Print the first N terms of the Fibonacci sequence
void printFibonacciTerms(int count) {
    if (count <= 0) {
        cout << "Error: Number of terms must be a positive integer." << endl;
        return;
    }

    cout << "Fibonacci sequence: ";

    long long first = 0, second = 1;

    for (int i = 1; i <= count; ++i) {
        if (i == 1) {
            cout << first;
        } else if (i == 2) {
            cout << " " << second;
        } else {
            long long next = first + second;
            cout << " " << next;
            first = second;
            second = next;
        }
    }
    cout << endl;
}

// PART B — Check if a target number is a Fibonacci number
bool isFibonacciNumber(long long num) {
    if (num < 0) {
        return false;
    }

    // Base cases (0 and 1 are Fibonacci numbers)
    if (num == 0 || num == 1) {
        return true;
    }

    long long first = 0, second = 1;
    long long next = first + second;

    // Generate terms iteratively until we reach or exceed the target number
    while (next < num) {
        first = second;
        second = next;
        next = first + second;
    }

    // If next equals num, it is in the sequence
    return (next == num);
}

int main() {
    // -------------------------------------------------------------------------
    // PART A: Generate Sequence
    // -------------------------------------------------------------------------
    cout << "=== PART A: PRINT FIBONACCI TERMS ===" << endl;
    int terms;
    cout << "How many terms? ";
    if (cin >> terms) {
        printFibonacciTerms(terms);
    }

    cout << endl;

    // -------------------------------------------------------------------------
    // PART B: Check Membership
    // -------------------------------------------------------------------------
    cout << "=== PART B: CHECK FIBONACCI NUMBER ===" << endl;
    long long target;
    cout << "Enter a number to check: ";
    if (cin >> target) {
        if (isFibonacciNumber(target)) {
            cout << target << " is a Fibonacci number." << endl;
        } else {
            cout << target << " is NOT a Fibonacci number." << endl;
        }
    }

    return 0;
}