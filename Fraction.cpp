#include "stdafx.h"
#include "Fraction.h"
#include <iostream>

CFraction::CFraction()
	: slash('/'), 
	operation(NULL)
{
}

CFraction::~CFraction()
{
	operation = NULL;
	numerator1 = NULL;
	numerator2 = NULL;
	denominator1 = NULL;
	denominator2 = NULL;
}

bool CFraction::inputData(const char operation, const int numerator1, const int denominator1,
	const int numerator2, const int denominator2, int& numerator, int& denominator)
{
	///check data & input
	auto verification = Verification();
	if (verification) //if does not undergo testing the truth objects
		return false;

	this->operation = operation;
	this->numerator1 = numerator1;
	this->numerator2 = numerator2;
	this->denominator1 = denominator1;
	this->denominator2 = denominator2;
	Fraction();
	numerator = returnNumerator;
	denominator = returnDenominator;
	return true;
}

bool CFraction::inputData(int& numerator, int& denominator)
{
	std::cout << "enter fraction: number slash number operator number slash number" << std::endl
		<< "enter: ";
	std::cin >> numerator1 >> slash >> denominator1
		>> operation >> numerator2 >> slash >> denominator2; 
	slash = '/'; 
	///check data & input
	auto verification = Verification();
	if (verification) //if does not undergo testing the truth objects
		return false;

	Fraction();
	numerator = returnNumerator;
	denominator = returnDenominator;
	return true;
}

bool CFraction::inputData(int & numerator, int & denominator, const char operation)
{
	if (operation == '+' || operation == '-' ||
		operation == '*' || operation == '/')
		return false;
		std::cout << "enter numerator 1: ";
		std::cin >> numerator1;
		std::cout << "enter denominator 1: ";
		std::cin >> denominator1;
		std::cout << "enter numerator 2: ";
		std::cin >> numerator2;
		std::cout << "enter denominator 2: ";
		std::cin >> denominator2;
		this->operation = operation;

		///check data & input
		auto verification = Verification();
		if (verification) //if does not undergo testing the truth objects
			return false;

		Fraction();
		numerator = returnNumerator;
		denominator = returnDenominator;
		return true;
}

void CFraction::Fraction()
{
	switch (operation)
	{
	case '+': AdditionFraction();
		break;
	case '-': SubtractionFraction();
		break;
	case '*': MultiplicationFraction();
		break;
	case '/': DivisionFraction();
		break;
	default:
		break;
	}
}

bool CFraction::Verification()
{
	if (operation == '+' || operation == '-' ||
		operation == '*' || operation == '/')
	{
		if (denominator1 > 0 && denominator1 < INT_MAX &&
			denominator2 > 0 && denominator2 < INT_MAX &&
			numerator1 > 0 && numerator1 < INT_MAX &&
			numerator2 > 0 && numerator2 < INT_MAX)
		{
			return false;
		}
		else
		{
			std::cout << "number "; 
		}
	}
	else
	{
		std::cout << "operator ";
	}
	std::cout << "don't verification !!!" << std::endl;
	return true;
}

void CFraction::AdditionFraction()
{
	if (denominator1 != denominator2)
		EquatingChoice();
	returnNumerator = numerator1 + numerator2;
	returnDenominator = denominator1;
}

void CFraction::MultiplicationFraction()
{
	returnNumerator = numerator1 * numerator2;
	returnDenominator = numerator1 * numerator2;
}

void CFraction::SubtractionFraction()
{
	if (denominator1 != denominator2)
		EquatingChoice();
	returnNumerator = numerator1 - numerator2;
	returnDenominator = denominator1;
}

void CFraction::DivisionFraction()
{
	returnNumerator = numerator1 * denominator2;
	returnDenominator = denominator1 * numerator2;
}

void CFraction::EquatingChoice()
{
	if (denominator1 > denominator2)
		EquateDenominator(numerator1, numerator2, denominator1, denominator2);
	else
		EquateDenominator( numerator2, numerator1, denominator2, denominator1);
}

void CFraction::EquateDenominator(int& numMax, int& numMin,  int& denMax, int& denMin)
{
	for (int i = 1; true; i++)
	{
		int temp = (denMax * i) / denMin;
		if (denMax * i == denMin * temp)
		{
			numMax *= i;
			numMin *= temp;
			denMax *= i;
			denMin *= temp;
			return;
		}
	}
}