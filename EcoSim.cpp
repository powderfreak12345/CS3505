// Jonathan Beutler u0867480
// A1: C++ Starter
// This is a program that models fox and rabbit populations based on user inputs.
// Methods for exploring pointers are also included, but are unrelated to the modeling.

#include <iostream> // This is something we'll be using in this program
#include <math.h>
using namespace std;

// Using the Lotka-Volterra equation and some provided parameters, calculate the new
//    fox and rabbit populations
void updatePopulations(double g, double p, double c, double m, double K,
                        double& numRabbits, double& numFoxes)
{
  // Do stuff to update the fox and rabbit populations.  Using the reference parameters
  //   provided, update the numbers of rabbits and foxes
  double deltaRabbits = floor((g*numRabbits)*(1-(numRabbits/K))-p*numRabbits*numFoxes);
  double deltaFoxes = floor(c*p*numRabbits*numFoxes - m*numFoxes);

  numRabbits = numRabbits + deltaRabbits;
  numFoxes = numFoxes + deltaFoxes;
}


// Sends to cout the specified number of whitespaces minus one, followed by the
// specified character.  If the specified number of whitespaces is 0 or negative,
// only the character is printed.
void plotCharacterAtPosition(int numWhiteSpaces, char characterToPlot)
{
  if (numWhiteSpaces <= 1)
  {
    cout << characterToPlot;  // Print the character
  }
  else
  {
    for (int spaces = 1; spaces < numWhiteSpaces; spaces++)
    {
      cout << " ";  // Add white spaces until it's time to print the character
    }
    cout << characterToPlot;  // Print the character
  }
}


// Plots the number of rabbits and foxes on a line to cout.  The specified scale
//    is used to scale the rabbits and foxes so that everything fits comfortably
//    on a single line.  Foxes are denoted with an F, rabbits with an r.  If both
//    rabbits and foxes occupy the same character, this is denoted by *
void plotPopulations( int numRabbits, int numFoxes, double scaleFactor)
{
  // Scale the number of foxes, rabbits, and their diffrence
  int scaledFoxes = floor(numFoxes * scaleFactor) + 1;
  int scaledRabbits = floor(numRabbits * scaleFactor) + 1;
  int scaledDiff = scaledFoxes - scaledRabbits;

  if (scaledDiff > 0) // More foxes than rabbits
  {
    plotCharacterAtPosition(scaledRabbits, 'r');
    plotCharacterAtPosition(scaledDiff, 'F');
  }
  else if (scaledDiff < 0)  // More rabbits than foxes
  {
    plotCharacterAtPosition(scaledFoxes, 'F');
    plotCharacterAtPosition(abs(scaledDiff), 'r');
  }
  else  // For plotting purposes, same number of rabbits and foxes
  {
    plotCharacterAtPosition(scaledFoxes, '*');
  }
  cout << endl; // After plotting on a line, move to the next one
}

// Takes a counter (passed by reference) and increments it by one.
void incrementCounter(int* counter)
{
  *counter = *counter + 1;
}


int main()
{
  // Declare parameters that are used by the Lotka-Volterra equation
  double rabbitGrowth = 0.2;
  double predationRate = 0.002;
  double foxPreyConversion = 0.6;
  double foxMortalityRate = 0.2;
  double carryCapacity = 1000.0;

  double foxPop, rabbitPop;

  // Do stuff here like get user input on initial fox and rabbit populations
  cout << "Enter an intial fox count: " << endl;
  if (!(cin >> foxPop) || (foxPop < 0))
  {
    cout << "Invalid input. Terminating program!" << endl;
    return 0;
  }

  cout << "Enter an initial rabbit count: " << endl;
  if (!(cin >> rabbitPop) || (rabbitPop < 0))
  {
    cout << "Invalid input. Terminating program!" << endl;
    return 0;
  }

  cout << endl << endl; // Create some white space betweeen user input and the plot

  plotPopulations(foxPop, rabbitPop, 0.1);  // Plot the initial populations

  int iteration;
  int* pointer = &iteration;

  // For 500 iterations, calculate new population numbers and plot them
  for (iteration = 1; iteration <= 500; incrementCounter(pointer))
  {
    updatePopulations(rabbitGrowth, predationRate, foxPreyConversion, foxMortalityRate, carryCapacity, foxPop, rabbitPop);
    plotPopulations(foxPop, rabbitPop, 0.1);

    // Check if either foxes or rabbits have gone below zero.  If so, break.
    if ((foxPop < 1) | (rabbitPop < 1))
      break;
  }

  return 0; // Signifies end of program and successful exectuion thereof
}
