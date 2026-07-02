#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include "MyMenu.h"

#define DEFAULT_PRECISION 8
#define MIN_DRAWABLE_RECT_LENGTH 3
#define MIN_DRAWABLE_LENGTH_FOR_RECT_CORNER 5

bool markRectCenter         = false;
bool markRectCorner         = false;
char charForRectCenter      = 'X';
char charForRectCorner      = 'c';
char charForRectPerimeter   = '#';

int field1_width = 15;
int field2_width = 15;
int field3_width = 30;
int field4_width = 15;

int rect_length, rect_breadth, perimeter, area, c;
int defaultPrecision = DEFAULT_PRECISION;
int float_point = defaultPrecision;
double num_info;

//Functions
void printWelcomeMsg();
void drawRectangleOptions();
void printNumberOptions();
void RectPerimeter();
void printNumInfo(const char *labels,  double input, const char *emptyspace,  const char *is, double output);
void NumInfo();
double enteredNum();

//Main Program
int main() 
{
    printWelcomeMsg ();	

    int userEnteredNumber, drawRectangleNumber, printNumber;
    char input[10];
    
    do
    {
        printMainMenuOptions ();         
        printf("Please enter your choice (1 - 5) : ");

        fgets(input, sizeof(input), stdin); 
        
        char *endptr;
        userEnteredNumber = strtol(input, &endptr, 10);  
        
 		// Combined check for input validity and range
        if ((*endptr != '\n') || userEnteredNumber < 1 || userEnteredNumber > 5) 
        {
            printf("! INVALID INPUT OR OUT OF RANGE (1 - 5) !\n\n");
            continue;
        }

        switch (userEnteredNumber)
        {
            case 1 :
            {	
            	do
            	{
		        	drawRectangleOptions();
		        	fgets(input, sizeof(input), stdin); 
        
					char *endptr;
					drawRectangleNumber = strtol(input, &endptr, 10);  
					
			 		// Combined check for input validity and range
					if ((*endptr != '\n') || drawRectangleNumber < 1 || drawRectangleNumber > 5) 
					{
						printf("! INVALID INPUT OR OUT OF RANGE (1 - 5) !\n\n");
						continue;
					}
		          	
		        	switch (drawRectangleNumber)
		        	{
		        		case 0:
		        		{
		        			printf("Returning to main menu...\n");
		        			while ((c = getchar()) != '\n' && c != EOF);		//flush the input buffer								
		        			break;
		        		}
		        		case 1:
		        		{
				    		markRectCenter = !markRectCenter;  // Toggle the marking state
							printf("Done! Marking of rectangle center switched to: '%s'\n\n", markRectCenter ? "on" : "off");
							break;
				    	}
				    	case 2:
				    	{	
				    		markRectCorner =! markRectCorner;
				    		printf("Done! Marking of rectangle conrner switched to: '%s'\n\n", markRectCorner ? "on" : "off");
				    		break;
				    	}
				    	case 3:
				    	{
				    		printf("Enter a char for rectangle center: ");
							scanf(" %c", &charForRectCenter);
							printf("Done! char for rectangle center now set to: '%c'\n\n", charForRectCenter);
							while ((c = getchar()) != '\n' && c != EOF);
							break;		    		
				    	}
				    	case 4:
				    	{
				    		printf("Enter a char for rectangle corner: ");
							scanf(" %c", &charForRectCorner);
							printf("Done! char for rectangle corner now set to: '%c'\n\n", charForRectCorner);
							while ((c = getchar()) != '\n' && c != EOF);
							break;	
				    	}
				    	case 5:
				    	{
				    		printf("Enter a char for rectangle perimeter: ");
							scanf(" %c", &charForRectPerimeter);
							printf("Done! char for rectangle perimeter now set to: '%c'\n\n", charForRectPerimeter);
							while ((c = getchar()) != '\n' && c != EOF);
							break;	
						}
				    }	   
				} while (drawRectangleNumber != 0);
				
				break;
		    }	
		    	   
			case 2 :
			{
				do
				{
					printNumberOptions();
					fgets(input, sizeof(input), stdin); 
        
					char *endptr;
					printNumber = strtol(input, &endptr, 10);  
					
			 		// Combined check for input validity and range
					if ((*endptr != '\n') || printNumber < 1 || printNumber > 5) 
					{
						printf("! INVALID INPUT OR OUT OF RANGE (1 - 5) !\n\n");
						continue;
					}
				  	
					switch (printNumber)
					{
						case 0:
						{
							printf("Returning to main menu...");
							while ((c = getchar()) != '\n' && c != EOF);								
							break;
						}
						case 1:
						{
							printf("Enter a (whole number) value for width of field 1: ");
							scanf(" %d", &field1_width);
							
							if(field1_width <= 8 || field1_width >= 32)
							{
								printf("Out of range try again!\n\n");
							}
							else
							{							
								printf("New value for width of field 1 = %d\n\n", field1_width);
							}
							while ((c = getchar()) != '\n' && c != EOF);
							break;
						}
						case 2:
						{
							printf("Enter a (whole number) value for width of field 2: ");
							scanf(" %d", &field2_width);
							
							if(field2_width <= 8 || field2_width >= 32)
							{
								printf("Out of range try again!\n\n");
							}
							else
							{							
								printf("New value for width of field 2 = %d\n\n", field2_width);
							}
							while ((c = getchar()) != '\n' && c != EOF);
							break;
						}
						case 3:
						{
							printf("Enter a (whole number) value for width of field 3: ");
							scanf(" %d", &field3_width);
							
							if(field3_width <= 15 || field3_width >= 60)
							{
								printf("Out of range try again!\n\n");
							}
							else
							{							
								printf("New value for width of field 3 = %d\n\n", field3_width);
							}
							while ((c = getchar()) != '\n' && c != EOF);
							break;
						}
						case 4:
						{
							printf("Enter a (whole number) value for width of field 4: ");
							scanf(" %d", &field4_width);
							
							if(field4_width <= 8 || field4_width >= 32)
							{
								printf("Out of range try again!\n\n");
							}
							else
							{							
								printf("New value for width of field 4 = %d\n\n", field4_width);
							}
							while ((c = getchar()) != '\n' && c != EOF);
							break;
						}
						case 5:
						{
							printf("Enter floating point number: ");
							scanf(" %d", &float_point);
							
							if(float_point < 0 || float_point > 15)
							{
								printf("Out of range try again!\n\n");
							}
							else
							{							
								printf("New value for floating point number = %d\n\n", float_point);
							}
							while ((c = getchar()) != '\n' && c != EOF);
						}
					}	   
				} while (printNumber != 0);
				
				break;
			}
			case 3:
    		{	    			    				
				RectPerimeter();
                while ((c = getchar()) != '\n' && c != EOF);								
				break;	
			}
			case 4:
			{
				NumInfo();
                while ((c = getchar()) != '\n' && c != EOF);
				break;
			}

        }

        printf("\n");
        
    } while (userEnteredNumber != 5);
    
    printf("\n");
    printf("Thank you for using this program, have a nice day! \n");
    printf("\n");

    return 0;   
}
//---------------------------------------------------------------------------------------------------------------------------
void printWelcomeMsg()
{
    printf("\n");
    printf("------------------------------------------------------ \n");
    printf("- Welcome to My Assn P1 Program! - \n");
    printf("------------------------------------------------------ \n");
    printf("- Student Number : 2401708 \n");
    printf("- Student Name   : Glenda Chong Yi Xuan \n");
    printf("------------------------------------------------------ \n");
    printf("\n");  
}

void drawRectangleOptions()
{
	printf("------------------------------------------------------\n");
	printf("------ Configure Draw Rectangle Options Sub Menu -----\n");
	printf("------------------------------------------------------\n");
	printf("0) Back to Main Menu\n");
	printf("1) Toggle marking of rectangle center	(currently: '%s')\n", markRectCenter ? "on" : "off");
	printf("2) Toggle marking of rectangle corner	(currently: '%s')\n", markRectCorner ? "on" : "off");
	printf("3) Change char for rectangle center	(current: '%c')\n", charForRectCenter);
	printf("4) Change char for rectangle corner	(current: '%c')\n", charForRectCorner);
	printf("5) Change char for rectangle perimeter	(current: '%c')\n", charForRectPerimeter);
	printf("------------------------------------------------------\n");
	printf("Please enter your choice (0 - 5): ");
}

void printNumberOptions()
{
	printf("------------------------------------------------------\n");
	printf("------ Configure Print Number Options Sub Menu -------\n");
	printf("------------------------------------------------------\n");
	printf("0) Back to Main Menu\n");
	printf("1) Adjust width of field 1		(current: %d spacing allocated)\n", field1_width);
	printf("2) Adjust width of field 2		(current: %d spacing allocated)\n", field2_width);
	printf("3) Adjust width of field 3		(current: %d spacing allocated)\n", field3_width);
	printf("4) Adjust width of field 4		(current: %d spacing allocated)\n", field4_width);
	printf("5) Adjust floating point number		(current: %d decimal places)\n", float_point);
	printf("------------------------------------------------------\n");
	printf("Please enter your choice (0 - 5): ");
}

void RectPerimeter()
{
	do{
        printf("Please enter the length of a rectangle: ");
        scanf(" %d", &rect_length);
        printf("Please enter the breadth of a rectangle: ");
        scanf(" %d", &rect_breadth);

        if (rect_length > 100 || rect_breadth > 20) {
            printf("Invalid input. Length cannot be more than 100 units, and breadth cannot be more than 20 units.\n\n");            
        }
    } while (rect_length > 100 || rect_breadth > 20);
    
	// Calculate perimeter and area
	perimeter = 2 * (rect_length + rect_breadth);
	area = rect_length * rect_breadth;
	
	int center_row = rect_breadth / 2;
    int center_col = rect_length / 2;
    int isLengthEven = rect_length % 2 != 1;
    int isBreadthEven = rect_breadth % 2 != 1;

    // Print graphical representation of rectangle
    printf("\n");
    for (int i = 0; i < rect_breadth; i++) {
        for (int j = 0; j < rect_length; j++) {
        	 if (rect_length == 1 && rect_breadth == 1) {
            	printf("%c", charForRectPerimeter);
        	}
        	else{
            // Check if it's an inner corner (second and second-last rows/columns)
            bool isCorner = (i == 1 && (j == 1 || j == rect_length - 2)) || (i == rect_breadth - 2 && (j == 1 || j == rect_length - 2));

            // Check if it's the center
            bool isCenter = (i == center_row && j == center_col);
				
				if (isLengthEven && isBreadthEven) {
                // If both length and breadth are even, the center is a 2x2 block
                	isCenter = (i == center_row - 1 || i == center_row) && (j == center_col - 1 || j == center_col);
		        } else if (isLengthEven && !isBreadthEven) {
		            // If only length is even, the center is a 1x2 vertical block
		            isCenter = i == center_row && (j == center_col - 1 || j == center_col);
		        } else if (!isLengthEven && isBreadthEven) {
		            // If only breadth is even, the center is a 2x1 horizontal block
		            isCenter = (i == center_row - 1 || i == center_row) && j == center_col;
		        } else {
		            // If both are odd, the center is a single point
		            isCenter = i == center_row && j == center_col;
		        }
		        
		        if (isCorner) {
		            printf("%c", charForRectCorner);  		// Print inner corner character
		        } else if (isCenter) {
		            printf("%c", charForRectCenter);  		// Print center character
		        } else if (i == 0 || i == rect_breadth - 1) {
		            printf("%c", charForRectPerimeter);  	// Print top/bottom perimeter character
		        } else if (j == 0 || j == rect_length - 1) {
		            printf("%c", charForRectPerimeter);  	// Print left/right perimeter character
		        } else {
		            printf(" ");  							// Print empty space
		        }
        	}
        }
        printf("\n");
    }

    printf("\nPerimeter of rectangle : %d units\n", perimeter);
    printf("Area of rectangle      : %d units square\n", area);
}

double enteredNum()
{
	char input[100];
	char *endptr;
	double value;
	while (1) 
	{	
		printf("Enter a number : ");
		if (fgets(input, sizeof(input), stdin) != NULL)
		{
			// Check if the input is empty or only contains whitespace
			if (input[0] == '\n')
				{
					value = 0;
					return value;
				}				
			value = strtod(input, &endptr);
			if (endptr != input && *endptr == '\n')
			{
				return value;
			}			
			else
			{
				printf("Invalid input. Only numbers allowed!!\n");
			}
		}
	}  
}

void NumInfo()
{	
   	num_info = enteredNum();               
    printf("------------------------------------------------------\n");
    printf("Information on your number: %.*f\n", float_point, num_info); // Use float_point for precision
    printf("------------------------------------------------------\n");
    
    printNumInfo("abs (", num_info, ")", "is: ", fabs(num_info));
    printNumInfo("ceil (", num_info, ")", "is: ", ceil(num_info));
    printNumInfo("floor (", num_info, ")", "is: ", floor(num_info));
    printNumInfo("round (", num_info, ")", "is: ", round(num_info));
	printf("%*s%-*.*f%s%*s%-*.*e\n", field1_width, " ", field2_width, float_point, num_info, " ", field3_width, "in scientific notation: ", field4_width, float_point, num_info);
	printf("%*s%-*.*f%s%*s%-*.1f\n", field1_width, " ", field2_width, float_point, num_info, " ", field3_width, "to 1 decimal place: ", field4_width, num_info);
	printf("%*s%-*.*f%s%*s%-*.2f\n", field1_width, " ", field2_width, float_point, num_info, " ", field3_width, "to 2 decimal place: ", field4_width, num_info);
	printf("%*s%-*.*f%s%*s%-*.3f\n", field1_width, " ", field2_width, float_point, num_info, " ", field3_width, "to 3 decimal place: ", field4_width, num_info);
	printf("%*s%-*.*f%s%*s%-*d\n", field1_width, "casting ", field2_width, float_point, num_info, " ", field3_width, "to int: ", field4_width, (int)num_info);
	printf("%*s%-*.*f%s%*s%-*ld\n", field1_width, "casting ", field2_width, float_point, num_info, " ", field3_width, "to long: ", field4_width, (long)num_info);
	printf("%*s%-*.*f%s%*s%-*Ld\n", field1_width, "casting ", field2_width, float_point, num_info, " ", field3_width, "to long int: ", field4_width, (long long)num_info);
	printNumInfo("casting ", num_info, " ", "to float: ", (float)num_info);
	printNumInfo("casting ", num_info, " ", "to double: ", (double)num_info);
	printNumInfo("casting ", num_info, " ", "to long double: ", (long double)num_info);
}

void printNumInfo(const char *labels,  double input, const char *emptyspace,  const char *is, double output)
{
    printf("%*s%-*.*f%s%*s%-*.*f\n", field1_width, labels, field2_width, float_point, input, emptyspace, field3_width, is, field4_width, float_point, output);
}
