/** FAMURE TOYIN
// 11201494, OMF436.
*/ THE PURPOSE OF THIS IS TO CHECK AND CONFIRM IF A SQUARE IS A MAGIC SQUARE OR NOT

#include <iostream>  // cin and cout
#include <cstdlib> 

using namespace std;

// Note iplementation of stated algorithms are not sequenial

/* Algorithm 2: checkSum(array, N, sum)
   Pre: given an array of N integers, and a value in sum
   Post: nothing
   Return: true if the values in the array add up to sum
           false otherwise
 
  1. Add up all the values in the array.
  2. Return true if the result is equal to sum; false otherwise
*/

bool checkSum(int array[], int N, int sum) {//function which takes an array, the array size and required value total
	int total = 0;
	for (int i = 0; i < N; i++) {
		total = total + array[i];//total is given the value of the summation of all the values in the array
	}
	if (total == sum) {//a boolean comparison of the required summation to the actual sum
		return true;
	}
	else {
		return false;
	}
}


/* Algorithm 1.2.2: checkRows(square)
   Pre: given a 3x3 array of integers
   Post: nothing
   Return: true if all the rows sum to 15
           false otherwise

  1. call function checkSum() with values from first row
  2. call function checkSum() with values from second row
  3. call function checkSum() with values from third row
  4. if any call to checkSum() returned false, return false
     otherwise, return true
*/

bool checkRows(int square[3][3]) {//a function that takes in a 2d array of 3 values each
	int firstRow[3];//declares 3 1d array of 3 values 
	int secondRow[3];
	int thirdRow[3];

for (int i = 0; i < 3; i++)//initializes the three declared array to be each row of the 2d array
	{
firstRow[i] = square[0][i];
secondRow[i] = square[1][i];
thirdRow[i] = square[2][i];

}
if (checkSum(firstRow, 3, 15)==true && checkSum(secondRow, 3, 15)==true && checkSum(thirdRow, 3, 15)==true) {//calls  the checkSum function 
	return true;//and makes a boolean comparison for each called function
}
else {
	return false;
}

}


/* Algorithm 1.2.3: checkColumns(square)
   Pre: given a 3x3 array of integers
   Post: nothing
   Return: true if all the columns sum to 15
           false otherwise

  1. call function checkSum() with values from first column
  2. call function checkSum() with values from second column
  3. call function checkSum() with values from third column
  4. if any call to checkSum() returned false, return false
*/     otherwise, return true

bool checkColumns(int square[3][3]) {//a function that takes in a 2d array of 3 values each
	int firstColumn[3];//declares 3 1d array of 3 values
	int secondColumn[3];
	int thirdColumn[3];
	for (int i = 0; i < 3; i++)//initializes the three declared array to be each column of the 2d array
	{
		firstColumn[i] = square[i][0];
		secondColumn[i] = square[i][1];
		thirdColumn[i] = square[i][2];

	}

	if (checkSum(firstColumn, 3, 15) == true && checkSum(secondColumn, 3, 15) == true && checkSum(thirdColumn, 3, 15) == true) {//calls  the checkSum function 
		return true;//and makes a boolean comparison for each called function
	}
	else {
		return false;
	}

}


/* Algorithm 1.2.4: checkDiagonals(square)
   Pre: given a 3x3 array of integers
   Post: nothing
   Return: true if all the diagonals sum to 15
           false otherwise

  1. call function checkSum() with values from upward diagonal
  2. call function checkSum() with values from downward diagonal
  4. if any call to checkSum() returned false, return false
     otherwise, return true
*/

bool checkDiagonals(int square[3][3]) {// a function that takes in a 2d array of 3 values each
	int firstDiagonal[3];//declares 2 1d array of 3 values
	int secondDiagonal[3];
	int num = 2;
	for (int i = 0; i < 3; i++)//initializes the three declared array to be each column of the 2d array
	{
		firstDiagonal[i] = square[i][i];
		secondDiagonal[i] = square[i][num-i];

	}
	if (checkSum(firstDiagonal, 3, 15) == true && checkSum(secondDiagonal, 3, 15) == true) {//calls  the checkSum function
		return true;//and makes a boolean comparison for each called function
	}
	else {
		return false;
	}

}//a function that takes in a 2d array of 3 values each


/* Algorithm 1.2.1: checkRange(square)
   Pre: given a 3x3 array of integers
   Post: nothing
   Return: true if the square contains all the integers 1 .. 9
           false otherwise

   1. Declare an array of 9 boolean values, called seen
      Initialize every value in seen to false
   2. for every value in the square
   2.1   seen[value-1] = true     // mark it as seen
   3. if any value in seen is still false, return false
      otherwise, return true
*/

// Known Bug: checkRange() fails badly if square contains integers out of range!

bool checkRange(int square[3][3]) {//function to check if the integer input are not repeated and are in range
	bool seen[9];//declares a boolean 1d array
	for (int i = 0; i < 9; i++) {
		 seen[i] = false;//and initializes all values to false
	}
	for (int j = 0; j < 3; j++) {//after which, initializes all the values in it to true using the values of the 3d array
		for (int k = 0; k < 3; k++) {
		
			int value = square[j][k];
			if (value > 0 && value < 10) {//to tackle the problem of robustness, by keeping the range of values between 1 and 9
				seen[value - 1] = true;     // mark it as seen
			}
			else {//returns false if not in range and terminates the function
				return false;
			}
		}
	}
	
	for(int t=0;t<9;t++){//loop to thoroughly check the boolean array for any values still with a false and returns a false value
	if (seen[t]==false){
	return false;
	
	}
	}
	return true;
}

/* Algorithm 1.2: checkSquare(square)
   Pre: given a 3x3 array of integers
   Post: nothing
   Return: true if the square has all the properties of a magic
           square; false otherwise

   1. To check the square has all integers 1 ... 9
      use function checkRange()
   2. To check 3 rows of the square sum to 15
      use function checkRows()
   3. To check 3 columns of the square sum to 15
      use function checkColumns()
   4. To check 2 diagonals of the square sum to 15
      use function checkDiagonals()
   5. If all the checks are positive (true), return true
*/

bool checkSquare(int square [3][3]) {//function  takes in a 2d array as parameters

	if (checkRange(square) == true && checkRows(square) == true && checkDiagonals(square) == true && checkColumns(square)==true) {//and calls all he above functions for a boolean comparison
		return true;
	}
	else {
		return false;
	}
}


/* Algorithm 1.1: getSquare(square)
   Pre: given a 3x3 array to contain integers
   Post: obtains 9 numbers from the console, storing them in the
         given array
   Return: Nothing

   1. Display a friendly prompt 
   2. Obtain 9 integers from the console
*/

void getSquare(int Square[3][3]) {
	int number;
	for (int x = 0; x<3; x++)//loop to initialize all the values of the 2d array
	{
		for (int y = 0; y<3; y++)
		{
			cout << "please enter number in square:";//friendly prompt to input numbers.
			cin >> number;
			Square[x][y] = number;
		}
	}

	// showing the square format on the console
	cout << "the square looks like this: " << endl;
	for (int x = 0; x<3; x++)  // loop 3 times for three lines
	{
		for (int y = 0; y<3; y++)  // loop for the three elements on the line
		{
			cout << Square[x][y]<<",";  // display the current element out of the array
		}
		cout << endl;  // when the inner loop is done, go to a new line
	}
	


}


/* Algorithm 1: main()
   Pre: nothing
   Post: nothing
   Return: 0

   1. Ask for the sequence of numbers ("square")
      call procedure getSquare()

   2. Check that it is magic
      call procedure checkSquare()

   3. Display "Yes!" if it's magic, "No!" otherwise
*/


int main() {
	int Square[3][3];//declares an array for the squares
	int firstArray[9]={1,2,3,4,5,6,7,8,9};
	
	int  Array[3][3] = { { 8,1,6 },{ 3,5,7 },{ 4,9,2 } };
	int  arraySecond[3][3] = { { 5,5,5 },{ 5,5,5 },{ 5,5,5 } };
	int  arrayThird[3][3] = { { -8,-6-4 },{ -3,59,7 },{ 400,900,200 } };
	int  arrayFourth[3][3] = { { 800,67,56},{ 47,59,700 },{ 400,900,200 } };
	
	getSquare(Square);	// Call getSquare with the array Square
	
//	cout << "array is:  array[9]{1,2,3,4,5,6,7,8,9};"<<endl;	// Print debugger
	
	/* Call check functions	*/
	checkSum(firstArray, 9, 45);//to check if the sum of values in the array above equals 45
	checkRows(Array);//to check if the sum of the values in each row equal 45
	checkColumns(Array);//to check if the sum of the values in each column equal 45
	checkDiagonals(Array);//to check if the sum of the values in each diagonal equal 45
	checkRange(Array);//to confirm if the given array has all integers from 1 to 9 and only includes this range
	
	
	/*	Check the validity of each of the created square arrays	*/
	checkSquare(Array);//this checks the correct square by calling all the above functions
	checkSquare(arraySecond);//this checks the all 5s square
	checkSquare(arrayThird);//this checks the square with large and negative numbers
	checkSquare(arrayFourth);//this checks the square with large numbers
	cout << endl;
	if (checkSquare(Square)==true) {
		cout << "Yes the Square is magic"<<endl;
	}
	else {
		cout << "No the Square is not magic"<<endl;
	}
	cout << "Thank you. please input an integer to terminate program: " << endl;
	int toyin;	//	Dummy input to analyze the product on the console
	cin >> toyin;// input value to terminate and close console
	return EXIT_SUCCESS;
}




