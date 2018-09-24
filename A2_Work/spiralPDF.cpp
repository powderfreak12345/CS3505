// Jonathan Beutler
// CS 3505
// A2


#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <string.h>
#include <math.h>
#include "HaruPDF.h"
#include "Spiral.h"


using namespace std;

// argc is the number of arguments. Argv is an array of character arrays, or C-style strings.
// If you call the program like ./pdfExample "Hello", then argv[1] would contain "Hello\0".
// argv[0] would be "pdfExample\0" - the name of the executing program.
int main (int argc, char *argv[])
{
    const char* textToWrite = argv[1];
    float charOrientationAngleRad;  // charOrientationAngleRad determines the angle of the letter on the page.

    HaruPDF myPDF = HaruPDF();
    myPDF.beginWrite();

    Spiral mySpi = Spiral(200, 350, 50, 90);
    unsigned int i;

    // Place characters one at a time on the page.
    for (i = 0; i < strlen (textToWrite); i++) {
        float x = mySpi.getTextX();
        float y = mySpi.getTextY();
        float r = mySpi.getTextAngle();

        charOrientationAngleRad = (r - 90) / 180 * 3.141592;

        myPDF.writeCharAtPosition(textToWrite[i], x, y, charOrientationAngleRad);

        mySpi++;
    }

    myPDF.endWrite();

    myPDF.saveToFile();

    return 0;
}
