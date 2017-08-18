// Project Euler Problems

#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

void Multiples3and5();
void EvenFibonacciNumbers();
void LargestPrimeFactor();
void SumSquareDifference();
void SmallestMultiple();
void NthPrime();
void LargestProductInSeries();
void LargestPalindromeProductTwo();
void LargestPalindromeProductThree();

bool IsPrimeNumber(double number);
bool IsPalindrome(double number);
string to_string(double i);

int main()
{	
	int choice;
	do
	{
		cout << "\nProject Euler Problems:\n" << endl;
		cout << "1. Multiples of 3 and 5" << endl;
		cout << "2. Even Fibonacci numbers" << endl;
		cout << "3. Largest prime factor" << endl;
		cout << "4. Largest palindrome product" << endl;
		cout << "5. Smallest multiple" << endl;
		cout << "6. Sum square difference" << endl;
		cout << "7. 10001st prime" << endl;
		cout << "8. Largest product in a series" << endl;
		cout << "0. Quit" << endl;
		
		cout << "\nChoice: ";
		cin >> choice;
		switch(choice)
		{
			case 1: Multiples3and5(); break;
			case 2: EvenFibonacciNumbers(); break;
			case 3: LargestPrimeFactor(); break;
			case 4: LargestPalindromeProductTwo(); break;
			case 5: SmallestMultiple(); break;
			case 6: SumSquareDifference(); break;
			case 7: NthPrime(); break;
			case 8: LargestProductInSeries(); break;
		}
	} while (choice != 0);
	
	return 0;
}

void Multiples3and5()
{
	cout << "\nMultiples of 3 and 5\n" << endl;
	
	vector<int> multiples;
	
	int number;
	cout << "Number: ";
	cin >> number;
	cout << endl;
	
	for (int i = 1; i < number; ++i)
	{
		if ( (i % 3 == 0) || (i % 5 == 0) )
		{
			multiples.push_back(i);
		}
	}
	
	int sum;
	vector<int>::const_iterator iter;
	for (iter = multiples.begin(); iter != multiples.end(); ++iter)
	{
		sum += *iter;
	}
	
	cout << "Sum: " << sum << endl;
}

void EvenFibonacciNumbers()
{
	cout << "\nEven Fibonacci numbers\n" << endl;
	
	int i = 1;
	int j = 2;
	int temp = 0;
	int number;
	cout << "Number: ";
	cin >> number;
	cout << endl;
	
	int sum = 0;
	while (j < number)
	{	
		if ((j % 2) == 0)
		{
			sum += j;
		}
		
		temp = i;
		i = j;
		j += temp;
	}
	
	cout << "Sum: " << sum << endl;
}

void LargestPrimeFactor()
{
	cout << "\nLargest prime factor\n" << endl;
	
	double number;
	cout << "Number: ";
	cin >> number;
	cout << endl;
	
	bool isPrimeFactor = true;
	double largestPrime = 0;
	
	for (double i = 2; i < number; ++i)
	{
//		cout << "i: " << i;
//		cout << "\tlargestPrime: " << largestPrime;
//		cout << "\tPrime Number? " << IsPrimeNumber(i) << endl;
		
		if ( (fmod(number,i) == 0) && IsPrimeNumber(i) )
		{
			largestPrime = i;
			cout << "Largest Prime SoFar: " << i << endl;
		}
		if (fmod(i,1.0e9) == 0)
		{
			cout << "Current Progress: " << i << endl;
		}
	}
	cout << "Largest prime factor: " << largestPrime << endl;
}

bool IsPrimeNumber(double number)
{
	if (number > 2)
	{
		if (fmod(number,2) == 0)
		{
			return false;
		}
		
		for (double i = 3; i < number; i+=2)
		{
			if (fmod(number,i) == 0)
			{
				return false;
			}
		}
		
		return true;
	}
	else if (number = 2)
	{
		return true;
	}
}

void SumSquareDifference()
{
	cout << "\nSum square difference\n" << endl;
	
	unsigned long int number;
	cout << "First n natural numbers: n = ";
	cin >> number;
	cout << endl;
	
	unsigned long int sumSquare = 0;
	unsigned long int squareSum = 0;
	
	for (unsigned long int i = 1; i <= number; ++i)
	{
		sumSquare += pow(i,2);
		squareSum += i;
	}
	squareSum = pow(squareSum,2);
	
	unsigned long int difference = squareSum - sumSquare;
	
	cout << "Sum square difference = " << difference << endl;
}

void SmallestMultiple()
{
	cout << "\nSmallest multiple\n" << endl;
	
	typedef unsigned long int ulong;
	ulong number;
	cout << "Smallest number that can be divided by each number from 1 to n: n = ";
	cin >> number;
	cout << endl;
	
	ulong smallestMultiple = 0;
	ulong tempNumber = 2;
	
	while (!smallestMultiple)
	{
		for (ulong i = 1; i <= number; ++i)
		{
			if (tempNumber % i != 0)
			{
				break;
			}
			if (i == number)
			{
				smallestMultiple = tempNumber;
			}
		}
		tempNumber+=2;	
	}
	
	cout << "Smallest positive number that is evenly divisible " << endl;
	cout << "by all of the numbers from 1 to " << number;
	cout << " is " << smallestMultiple << endl;
}

void NthPrime()
{
	cout << "\n10001st prime\n" << endl;
	
	double number;
	cout << "What is the nth prime number? n = ";
	cin >> number;
	cout << endl;
	
	double n = 0;
	double temp = 2;
	while (n != number)
	{
		if (IsPrimeNumber(temp))
		{
			++n;
		}
		if (n != number)
		{
			if (temp == 2)
			{
				++temp;
			}
			else
			{
				temp+=2;
			}
		}
	}
	
	cout << "The " << number << " prime number is " << temp << endl;
}

void LargestProductInSeries()
{
	cout << "\nLargest product in a series" << endl;
	
	
}

void LargestPalindromeProductTwo()
{
	cout << "\nLargest palindrome product\n" << endl;
	
	double number;
	cout << "Largest palindrome made from product of two n-digit number" << endl;
	cout << "n = ";
	cin >> number;
	cout << endl;
	
	const double MAX_NUMBER =  pow(10,number) - 1;
	const double MIN_NUMBER = pow(10,number-1);
	double maxProduct = 0;
	double first;
	double second;
	double firstTemp;
	double secondTemp;
	for (first = MIN_NUMBER; first <= MAX_NUMBER; ++first)
	{
		for (second = MIN_NUMBER; second <= MAX_NUMBER; ++second)
		{
			if (IsPalindrome(first*second))
			{
				if (maxProduct < first*second)
				{
					maxProduct = first*second;
					firstTemp = first;
					secondTemp = second;
				}
			}
		}
	}
	
	cout << "The largest palindrome made from the product of two " << number;
	cout << "-digit numbers is " << endl;
	cout << maxProduct << " = " << firstTemp << " X " << secondTemp << endl;
	
//	number = 906609;
//	string str = "NOT";
//	if (IsPalindrome(number))
//	{
//		str = "";
//	}
//	cout << "The number " << number << " is " << str << " a palindrome" << endl;
}

void LargestPalindromeProductThree()
{
	cout << "\nLargest palindrome product\n" << endl;
	
	double number = 3;
	cout << "Largest palindrome made from product of two 3-digit number:" << endl;
	
	const double MAX_NUMBER =  pow(10,number) - 1;
	double maxProduct;
	bool maxProductFound = false;
	double first;
	double second;
	double third;
	while (!maxProductFound)
	{
		for (first = MAX_NUMBER; first > 0 ; --first)
		{	
			for (second = MAX_NUMBER; second > 0; --second)
			{
				for (third = MAX_NUMBER; third > 0; --third)
				{
					if (IsPalindrome(first*second*third))
					{
						maxProduct = first*second*third;
						maxProductFound = true;
						break;
					}
				}
			}
		}
	}
	
	cout << "The largest palindrome made from the product of two " << number;
	cout << "-digit numbers is " << maxProduct << " = " << first;
	cout << " X " << second << " X " << third << endl;
}

bool IsPalindrome(double number)
{
	string str = to_string(number);
	string reverseStr = str;
	reverse(reverseStr.begin(), reverseStr.end());
	if (str == reverseStr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

string to_string(double i)
{
	stringstream ss;
	ss << i;
	return ss.str();
}
