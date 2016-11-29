#pragma once
class CFraction
{
private:
	char slash;
	char operation;
	int numerator1;
	int numerator2;
	int denominator1;
	int denominator2;

	int returnNumerator;
	int returnDenominator;

	void Fraction();
	bool  Verification();
	void AdditionFraction();// +
	void MultiplicationFraction();// *
	void SubtractionFraction();// -
	void DivisionFraction();// /
	void EquateDenominator(int&, int&, int&, int&);
	void EquatingChoice();
public:
	CFraction();
	~CFraction();

	///push data in fraction
	bool inputData(const char operation, const int numerator1, const int denominator1,
		const int numerator2, const int denominator2, int& numerator, int& denominator);
	///enter fraction: ("number slash number" operator "number slash number") = ("3/4" * "6/9")
	bool inputData(int& numerator, int& denominator);
	///enter fraction: ("number slash number" operator "number slash number") = ("3/4" "6/9") push operator
	bool inputData(int& numerator, int& denominator, const char operation);
};

