// fig02_01.c
// A first program in C.
#include <stdio.h>

// function main begins program execution 
int main(void) {
    int length = 0;
    int width = 0;
    int area = 0;
    
    double averageLengthWidth = 0;
    
    puts("Enter the length");
    scanf("%d", &length);
    
    
    puts("Enter the width\n");
    scanf("%d", &width);
    
    averageLengthWidth = (double)(length + width) / 2;
    
    printf("%f" , averageLengthWidth);
    
    //area = length * width;
    
     area = calculateArea((double)length, (double)width);
    
    printf("Length: %d Width: %d Area %f\n", length, width, area);
    
    return(0);
   //printf("Welcome to C!\n");
} // end function main

double calculateArea(double length, double width){
    double area = 0.0;
    
    area = length * width;
    
    return area;
}



/**************************************************************************
 * (C) Copyright 1992-2021 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                   *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 *************************************************************************/
