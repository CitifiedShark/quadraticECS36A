
#include <stdio.h>
#include <math.h>

/*
This program helps find the real solutions of a quadratic equation

We first ask the user for input
1. Asking for a quadratic equation in the form of a*x^2 + b * x + c
    - Ask for the a value
    - Ask for the b value
    - Ask for the c value

We use the inputs to calculate for real solutions
1. Solve for the + real solution
2. Solve for the - real solution

Display the real solutions
1. Check if there are two real solutions
    - if so, display those two solutions
2. if not, check if solution 1 has a solution
    - if so, say that there is only one solution and display it
3. if not, check if solution 2 has a solution
    - if so, say that there is only one solution and display it
4. if all conditions fail, then display that there are no real solutions to the user
    
*/

//Asks for user input for the value of a
double askUserInputA() {
    double a;

    printf("Please enter a: ");
    scanf(" %lf", &a);

    return a; //returns value of a
}

//Asks for the user input for the value of b
double askUserInputB() {
    double b;

    printf("Please enter b: ");
    scanf(" %lf", &b);

    return b; //returns value of b
}

//Asks for the user input for the value of c
double askUserInputC() {
    double c;

    printf("Please enter c: ");
    scanf(" %lf", &c);

    return c; //returns value of c
}

//Solves for the positive real solution
double calculateSol1(double a, double b, double c) { //a, b, c are inputs from user used for calculations
    double solution1;
    double numerator, denominator;

    numerator = ( (-b) + sqrt( pow(b, 2.0) - (4.0*a*c))); // find the numerator
    denominator = (2.0*a); // find the denominator

    solution1 = numerator / denominator; //solution is numerator divided by denominator

    return solution1; //returns value of solution 1 calculated
}

//Solves for the negative real solution
double calculateSol2(double a, double b, double c) { //a, b, c are inputs from user used for calculations
    double solution2;
    double numerator, denominator;

    numerator = ( (-b) - sqrt( pow(b, 2.0) - (4.0*a*c)));
    denominator = (2.0*a);

    solution2 = numerator / denominator;

    return solution2; //return value of solution 2 calculated
}

//Checks how many real solutions there are, and displays the solutions according to how many solutions there are
double checkSolution(double solution1, double solution2) { //solutions 1 and 2 that were just calculated
    if (((solution1 >= 0) || (solution1 <= 0)) && ((solution2 >= 0) || (solution2 <= 0))) { //if there are two solutions
        if (solution1 == solution2) { //If the solutions are equal to each other, there truly is only one solution
            printf("There is one real solution: %.2lf", solution1);
        } else { //if not, print the two different solutions
            printf("There are 2 real solutions\n");
            printf("Solution 1: %.2lf\n", solution1);
            printf("Solution 2: %.2lf\n", solution2);
        }
    } else if ((solution1 >= 0) || (solution1 <= 0)) { //if only solution 1 has a number
        printf("There is one real solution: %.2lf\n", solution1);
    } else if ((solution2 >= 0) || (solution2 <= 0)) { //if only solution 2 has a number
        printf("There is one real solution: %.2lf\n", solution2);
    } else { //if there are no solutions
        printf("There are no real solutions\n");
    }

    return 0; //just exits
}

int main(void) {
    double a, b, c; //Values for user input
    double solution1, solution2; //Solution values to be displayed to user after program completion

    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n"); //Asks for a quadratic equation
    a = askUserInputA(); //ask for a
    b = askUserInputB(); //ask for b
    c = askUserInputC(); //ask for c

    solution1 = calculateSol1(a, b, c); //calculate solution 1
    solution2 = calculateSol2(a, b, c); //calculate solution 2

    checkSolution(solution1, solution2); //check how many solutions there are, and display

    return 0; //just exit
}