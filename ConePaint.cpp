//******************************************************************************
// ConePaint program
// This program computes the cost of painting traffice cones in
// each of three different colors, given the height and diameter
// of a cone in inches, and the cost per square foot of each of
// the paints
//******************************************************************************
#include <iostream>
#include <iomanip>			// For setw() and setprecision()
#include <math.h>			// For sqrt()

const float INCH_HEIGHT = 30.0;		// Height of a typical cone
const float INCH_DIAMETER = 8.0;	// Diameter of base of cone

const float RED_PRICE = 0.10;		// Price per square foot of red paint
const float BLUE_PRICE = 0.15;		// Price per square foot of blue paint
const float GREEN_PRICE = 0.18;		// Price per square foot of green paint

const float INCHES_PER_FOOT = 12.0;	// Inches in 1 foot
const float PI = 3.14159265;		// Ratio of circumference to diameter

int main()
{
	float heightInFeet;		// Height of the cone in feet
	float diameterInFeet;		// Diameter of the cone in feet
	float radius;			// Radius of the cone in feet
	float surfaceArea;		// Surface area in square feet
	float redCost;			// Cost to paint a cone red
	float blueCost;			// Cost to paint a cone blue
	float greenCost;		// Cost to paint a cone green

	std::cout.setf(std::ios::fixed, std::ios::floatfield);	// Set up floating pt.
	std::cout.setf(std::ios::showpoint);	// output format

	// Convert dimensions to feet
	heightInFeet = INCH_HEIGHT / INCHES_PER_FOOT;
	diameterInFeet = INCH_DIAMETER / INCHES_PER_FOOT;
	radius = diameterInFeet / 2.0;

	// Compute surface area of the cone
	surfaceArea = PI * radius
		* sqrt(radius*radius + heightInFeet*heightInFeet);

	// Compute cost for each color
	redCost = surfaceArea * RED_PRICE;
	blueCost = surfaceArea * BLUE_PRICE;
	greenCost = surfaceArea * GREEN_PRICE;

	// Print results
	std::cout << "The surface area is "
		<< std::setprecision(3) << surfaceArea << " sq. ft." << std::endl;
	std::cout << "The paint cost for" << std::endl;
	std::cout << "   Red is   " << std::setw(7) << redCost << " dollars" << std::endl;
	std::cout << "  Blue is   " << std::setw(7) << blueCost << " dollars" << std::endl;
	std::cout << " Green is   " << std::setw(7) << greenCost << " dollars" << std::endl;
	return 0;
}
