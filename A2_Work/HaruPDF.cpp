// Jonathan Beutler
// CS 3505
// A2

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "HaruPDF.h"

using namespace std;


HaruPDF::HaruPDF()
{
    strcpy (fname, "spiral.pdf");


    pdf = HPDF_New (NULL, NULL);

    page = HPDF_AddPage (pdf);
    HPDF_Page_SetSize (page, HPDF_PAGE_SIZE_A5, HPDF_PAGE_PORTRAIT);

    font = HPDF_GetFont (pdf, "Helvetica", NULL);
    HPDF_Page_SetTextLeading (page, 20);
    HPDF_Page_SetGrayStroke (page, 0);
}

void HaruPDF::beginWrite()
{
    HPDF_Page_BeginText (page);
    font = HPDF_GetFont (pdf, "Courier-Bold", NULL);
    HPDF_Page_SetFontAndSize (page, font, 30);
}

void HaruPDF::writeCharAtPosition(char c, float x, float y, float rad1)
{
    char buf[2];

    HPDF_Page_SetTextMatrix(page,
                            cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                            x, y);

    // C-style strings are null-terminated. The last character must a 0.
    buf[0] = c; // The character to display
    buf[1] = 0;
    HPDF_Page_ShowText (page, buf);
}

void HaruPDF::endWrite()
{
    HPDF_Page_EndText (page);
}

void HaruPDF::saveToFile()
{
  /* save the document to a file */
  HPDF_SaveToFile (pdf, fname);

  /* clean up */
  HPDF_Free (pdf);
}
