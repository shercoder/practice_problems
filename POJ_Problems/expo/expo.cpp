#include <iostream>
#include <cmath>
#include <iomanip>

int main()
{
	double R = 0.0;
	double n = 0.0;
	double result = 0.0;

	while(std::cin>>R>>n)
	{
		result = pow(R, n);
	std::cout << std::setprecision(9) << std::fixed << std::showpoint <<  result <<  std::endl;		
	}
}
