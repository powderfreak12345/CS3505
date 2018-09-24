// Jonathan Beutler
// CS 3505
// A2

#include "hpdf.h"

class HaruPDF{

private:
  HPDF_Doc pdf;
  HPDF_Page page;
  HPDF_Font font;
  char fname[256];

public:

  HaruPDF();  // Default constructor.  Returns a PDF document to write in

  void beginWrite();  // Makes the pdf available to start writing in

  void endWrite();  // Makes the pdf unavailable to write in

  void writeCharAtPosition(char c, float x, float y, float rad1); // Places a character at the specified position

  void saveToFile();  // Saves the pdf under its designated name
};
