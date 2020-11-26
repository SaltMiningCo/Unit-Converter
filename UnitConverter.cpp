// Author: Grant Dillard
// Date: November 10, 2020
// Author's Note: I wish C++ allowed strings for switch cases
// Author's Note: Remove IF/Else blocks and replace it with file search...allows for expansions

// TODOLIST:	Finish Distance Block
#include <iostream>
using namespace std;

//Temperature
double convertFahrenheit(double entry, string unit);
double convertCelsius(double entry, string unit);
double convertKelvin(double entry, string unit);
//Distance
double convertInches(double entry, string unit);
double convertFeet(double entry, string unit);
double convertYards(double entry, string unit);
double convertMiles(double entry, string unit);
double convertCM(double entry, string unit);
double convertM(double entry, string unit);
double convertKM(double entry, string unit);
//Mass
double convertOunces(double entry, string unit);
double convertPounds(double entry, string unit);
double convertTons(double entry, string unit);
double convertGrams(double entry, string unit);
double convertKG(double entry, string unit);
//Volume
double convertFLOZ(double entry, string unit);
double convertPints(double entry, string unit);
double convertQuarts(double entry, string unit);
double convertGallons(double entry, string unit);
double convertML(double entry, string unit);
double convertLiters(double entry, string unit);

//
int main() {
	//Variable declaration
	double data;
	string units;
	bool exit = false;
	string confirm = "";
	string unitType = "";
	string targetUnits = "";
	//Greeting
	cout << "Welcome!\n";
	//Main Loop
	while(!exit) {
		//Prompt
		//Should include error for data != double											<-------------Note
		cout << "Enter value: ";
		cin >> data;
		cout << "Enter units (abbreviated): ";
		cin >> units;
		transform(units.begin(), units.end(), units.begin(), ::tolower);
		if (units == "in" || units == "ft" || units == "yd" || units == "mi" || units == "cm" || units == "m" || units == "km") {
			unitType = "distance";
		}
		else if (units == "f" || units == "c" || units == "k") {
			unitType = "temperature";
		}
		else if (units == "oz" || units == "lb" || units == "t" || units == "g" || units == "kg") {
			unitType = "mass";
		}
		else if (units == "fl oz" || units == "pt" || units == "qt" || units == "gal" || units == "ml" || units == "l") {
			unitType = "volume";
		}
		else {
			cout << "Invalid Units";
			return 0;
		}
		cout << "Conversion units (abbreviated): ";
		cin >> targetUnits;
		transform(targetUnits.begin(), targetUnits.end(), targetUnits.begin(), ::tolower);

		if (unitType == "distance") {
			if (targetUnits == "in") {
				cout << convertInches(data, units)
					 << " inches"
					 << endl;
			}
			else if (targetUnits == "ft") {
				cout << convertFeet(data, units) 
					 << " feet"
					 << endl;
			}
			else if (targetUnits == "yd") {
				cout << convertYards(data, units)
					 << " yards"
					 << endl;
			}
			else if (targetUnits == "mi") {
				cout << convertMiles(data, units)
					 << " miles"
					 << endl;
			}
			else if (targetUnits == "cm") {
				cout << convertCM(data, units)
					 << " centimeters"
					 << endl;
			}
			else if (targetUnits == "m") {
				cout << convertM(data, units)
					 << " meters"
					 << endl;
			}
			else if (targetUnits == "km") {
				cout << convertKM(data, units)
					 << " kilometers"
					 << endl;
			}
		}
		
		else if (unitType == "temperature") {
			if (targetUnits == "k") {
				cout << convertFahrenheit(data, units) 
					 << " degrees Fahrenheit"
					 << endl;
			}
			else if (targetUnits == "c") {
				cout << convertCelsius(data, units) 
					 << " degrees Celsius"
					 << endl;
			}
			else if (targetUnits == "k") {
				cout << convertKelvin(data, units)
					 << " degrees Kelvin"
					 << endl;
			}
		}
		
		else if (unitType == "mass") {
			if (targetUnits == "oz") {
				cout << convertOunces(data, units)
					 << " ounces"
					 << endl;
			}
			else if (targetUnits == "lb") {
				cout << convertPounds(data, units)
					 << " pounds"
					 << endl;
			}
			else if (targetUnits == "t") {
				cout << convertTons(data, units)
					 << " tons"
					 << endl;
			}
			else if (targetUnits == "g") {
				cout << convertGrams(data, units)
					 << " grams"
					 << endl;
			}
			else if (targetUnits == "kg") {
				cout << convertKG(data, units)
					 << " kilograms"
					 << endl;
			}
		}
		
		else if (unitType == "volume") {
			if (targetUnits == "fl oz") {
				cout << convertFLOZ(data, units)
					 << " fluid ounces"
					 << endl;
			}
			else if (targetUnits == "pt") {
				cout << convertPints(data, units) 
					 << " pints"
					 << endl;
			}
			else if (targetUnits == "qt") {
				cout << convertQuarts(data, units) 
					 << " quarts"
					 << endl;
			}
			else if (targetUnits == "gal") {
				cout << convertGallons(data, units)
					 << " gallons"
					 << endl;
			}
			else if (targetUnits == "ml") {
				cout << convertML(data, units)
					 << " milliliters";
			}
			else if (targetUnits == "l") {
				cout << convertLiters(data, units)
					 << " liters"
					 << endl;
			}
		}
		
		cout << "Continue? ";
		cin >> confirm;
		cout << endl;
		if (confirm != "yes") {
			exit = true;
		}
	}
	return 0;
}

double convertFahrenheit(double entry, string unit) {
	if (unit == "c" || unit == "celsius")
		return (entry * 1.8) + 32;								// C to F
	else
		return (1.8*(entry - 273.15)) + 32;						// K to F
}
double convertCelsius(double entry, string unit) {
	if (unit == "f" || unit == "fahrenheit") {
		return (entry - 32)/1.8;								// F to C
	}
	else {
		return entry - 273.15;									// K to C
	}
}
double convertKelvin(double entry, string unit) {
	if (unit == "f" || unit == "fahrenheit")
		return ((entry - 32)/1.8) + 273.15;						// F to K
	else
		return entry + 273.15;									// C to K
}
//Distance
double convertInches(double entry, string unit) {
		//Imperial Units
	if (unit == "ft" || unit == "feet") {
		return (entry*12);
	}
	else if (unit == "yd" || unit == "yards") {
		return (entry*36);
	}
		//Metric Umits
	else if (unit == "cm" || unit == "centimeters") {
		return (entry*0.393701);
	}
	else if (unit == "m" || unit == "meters") {
		return (entry*39.3701);
	}
	else {
		return 0;
	}
	
}
double convertFeet(double entry, string unit) {
	if (unit == "in" || unit == "inches") {
		return (entry/12);
	}
	else if (unit == "yd" || unit == "yards") {
		return (entry*3);
	}
	else if (unit == "mi" || unit == "miles") {
		return (entry*5280);
	}
	//Metric Umits
	else if (unit == "cm" || unit == "centimeters") {
		return (entry*0.0328084);
	}
	else if (unit == "m" || unit == "meters") {
		return (entry*3.28084);
	}
	else if (unit == "km" || unit == "kilometers") {
		return (entry*3280.84);
	}
	else {
		return 0;
	}
}
double convertYards(double entry, string unit) {
	if (unit == "in" || unit == "inches") {
		return (entry/36);
	}
	else if (unit == "ft" || unit == "feet") {
		return (entry/3);
	}
	else if (unit == "mi" || unit == "miles") {
		return (entry*1760);
	}
	//Metric Umits
	else if (unit == "cm" || unit == "centimeters") {
		return (entry/91.44);
	}
	else if (unit == "m" || unit == "meters") {
		return (entry*1.09361);
	}
	else if (unit == "km" || unit == "kilometers") {
		return (entry*1093.61);
	}
	else {
		return 0;
	}

}
double convertMiles(double entry, string unit) {
	if (unit == "in" || unit == "inches") {
		return (entry/63360);
	}
	else if (unit == "ft" || unit == "feet") {
		return (entry/5280);
	}
	else if (unit == "yd" || unit == "yd") {
		return (entry/1760);
	}
	//Metric Units
	else if (unit == "cm" || unit == "centimeters") {
		return (entry*160934);
	}
	else if (unit == "m" || unit == "meters") {
		return (entry*1609.34);
	}
	else if (unit == "km" || unit == "kilometers") {
		return (entry*1.60934);
	}
	return 0;
}
double convertCM(double entry, string unit) {
	if (unit == "in" || unit == "inches") {
		return (entry*2.54);
	}
	else if (unit == "ft" || unit == "feet") {
		return (entry*30.48);
	}
	else if (unit == "yd" || unit == "yards") {
		return (entry*91.44);
	}
	else if (unit == "mi" || unit == "miles") {
		return (entry*160934);
	}
	//Metric Units
	else if (unit == "m" || unit == "meters") {
		return (entry*100);
	}
	else if (unit == "km" || unit == "kilometers") {
		return (entry*100000);
	}
	return 0;
}
double convertM(double entry, string unit) {
	if (unit == "in" || unit == "inches") {
		return (entry/39.3701);
	}
	else if (unit == "ft" || unit == "feet") {
		return (entry/3.28084);
	}
	else if (unit == "yd" || unit == "yards") {
		return (entry/1.09361);
	}
	else if (unit == "mi" || unit == "miles") {
		return (entry*1609.34);
	}
	//Metric Units
	else if (unit == "cm" || unit == "centimeters") {
		return (entry/100);
	}
	else if (unit == "km" || unit == "kilometers") {
		return (entry*1000);
	}
	return 0;
}
double convertKM(double entry, string unit) {
	if (unit == "in" || unit == "inches") {
		return (entry/39370.1);
	}
	else if (unit == "ft" || unit == "feet") {
		return (entry/3280.84);
	}
	else if (unit == "yd" || unit == "yards") {
		return (entry/1093.61);
	}
	else if (unit == "mi" || unit == "miles") {
		return (entry*1.60934);
	}
	//Metric Units
	else if (unit == "cm" || unit == "centimeters") {
		return (entry/100000);
	}
	else if (unit == "m" || unit == "meters") {
		return (entry/1000);
	}
	return 0;
}

//Mass
double convertOunces(double entry, string unit) {
	if (unit == "lb") {
		return (entry*16);
	}
	else if (unit == "t") {
		return (entry*32000);
	}
	else if (unit == "g") {
		return (entry*0.035274);
	}
	else if (unit == "kg") {
		return (entry*35.274);
	}
	return 0;
}
double convertPounds(double entry, string unit) {
	if ()
}
double convertTons(double entry, string unit) {
	return 0;
}
double convertGrams(double entry, string unit) {
	return 0;
}
double convertKG(double entry, string unit) {
	return 0;
}

//Volume
double convertFLOZ(double entry, string unit) {
	return 0;
}
double convertPints(double entry, string unit) {
	return 0;
}
double convertQuarts(double entry, string unit) {
	return 0;
}
double convertGallons(double entry, string unit) {
	return 0;
}
double convertML(double entry, string unit) {
	return 0;
}
double convertLiters(double entry, string unit) {
	return 0;
}
