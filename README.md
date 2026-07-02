# 1. Introduction
This will cover how to compile and run the program and also an explanation of the functions.

# 2. Compilation and Execution
The compilation and execution are the same as the one provided.
To compile:
cd Desktop/AssnP1_Pkg/
g++ StuAssnP1Main.c MyMenu.c -o AssnPart1.run
To run:
./AssnPart1.run

# 3. Function Prototypes
Below are the function prototypes that I used:
● void printWelcomeMsg()
● void drawRectangleOptions()
● void printNumberOptions()
● void RectPerimeter()
● void printNumInfo(const char *labels, double input, const char *emptyspace, const char *is,
double output)
● void NumInfo()

# 4. Main Function
Start: Begins the function executable
Display WelcomeMsg: Initial Message to user. This function displays a welcome message to the user
when the program starts.
Display MainMenuOptions: Show menu choices.
Prompt user input (1-5): Requests a numeric choice.
Input Validation Check:
● Yes (Valid Input): Executes the chosen case.
● No (Invalid Input): Loops back to prompt the user again.

## 4.1. Case 1
1. Print drawRectangleOptions():
- This function displays the instructions and options related to drawing a rectangle.
------------------------------------------------------
------ Configure Draw Rectangle Options Sub Menu -----
------------------------------------------------------
0) Back to Main Menu
1) Toggle marking of rectangle center (currently: 'off')
2) Toggle marking of rectangle corner (currently: 'off')
3) Change char for rectangle center (current: 'X')
4) Change char for rectangle corner (current: 'c')
5) Change char for rectangle perimeter (current: '#')
------------------------------------------------------
Please enter your choice (0 - 5):
2. Prompts user input (0-5) and checks if its within the range
3. Option 0 returns user back to the main menu
4. Option 1 & 2 toggles the marking of the rectangle center and corner
5. Option 3, 4 & 5 prompts user to enter a char before changing
## 4.2. Case 2
1. Print printNumberOptions():
- This function displays the instructions and options related to printing numeric
properties of a given number.
------------------------------------------------------
------ Configure Print Number Options Sub Menu -------
------------------------------------------------------
0) Back to Main Menu
1) Adjust width of field 1 (current: 15 spacing allocated)
2) Adjust width of field 2 (current: 15 spacing allocated)
3) Adjust width of field 3 (current: 30 spacing allocated)
4) Adjust width of field 4 (current: 15 spacing allocated)
5) Adjust floating point number (current: 8 decimal places)
------------------------------------------------------
Please enter your choice (0 - 5):
2. Prompts user input (0-5) and checks if its within the range
3. Option 1,2 and 4 checks if it's between 8-30 and adjusts the width of the respectives field
4. Option 3 checks if it's between 15-60 and adjusts the width of the respectives field
5. Option 5 checks if it's between 0-15 and adjusts the floating point number for case 4

## 4.3. Case 3
Print RectPerimeter():
- This function prompts the user for the length and breadth of the rectangle and if the
user inputs the length of more than 100 OR the breadth of more than 20, it will be
invalid and it will prompt the user to enter the values again.
- Prints out the rectangle
- Prints out perimeter and area

## 4.4. Case 4
Print NumInfo():
- This function prompts the user to enter a number and then displays the respective
information on the number.

## 4.5. Case 5
End of program
