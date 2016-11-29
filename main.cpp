// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Fraction.h"
#include <string.h>
#include <stdio.h>

void main()
{
	int numerator;
	int denominator;
	CFraction vFraction;
	if(vFraction.inputData(numerator, denominator))
		std::cout << "\t\t" << numerator << std::endl << "result: " << "\t--" << std::endl << "\t\t" << denominator << std::endl;
    return;
}


/*Реализуйте класс Дробь. Необходимо хранить числитель
и знаменатель в качестве переменных-членов. Реализуйте
функции-члены для ввода данных в переменные-члены,
для выполнения арифметических операций (сложение,
вычитание, умножение, деление, и т.д.).*/