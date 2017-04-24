#include<iostream>

#include"BatteryCharge.h"

int main(int argc, char* argv[])
{
	BatteryCharge<double> bc{};

	std::cout << "The current percentage is: " << bc.getCurrentPercentage() << "%"<< std::endl;

	return 0;
}
