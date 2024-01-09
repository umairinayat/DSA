
//-------------Question 1---------------------//
// #include <iostream>
// using namespace std;
// int main()
// {
//     for (int i = 1; i <= 5; ++i)
//     {
//         for (int j = 1; j <= i; ++j)
//         {
//             cout << i;
//         }
//         cout << endl;
//     }
//     return 0;
// }

//-------------Question 2---------------------//

// #include <iostream>
// using namespace std;
// int main() {
//     int dividend, divisor;

//     cout << "Enter dividend: ";
//     cin >> dividend;
//     cout << "Enter divisor: ";
//     cin >> divisor;

//     // Find the remainder without using %
//     int quotient = dividend / divisor;
//     int remainder = dividend - (quotient * divisor);

//     cout << "Remainder: " << remainder << endl;

//     return 0;
// }

//-------------Question 3---------------------//

// #include <iostream>
// using namespace std;
// int main()
// {
//     int loopStart, loopEnd;
//     int sum = 0;

//     cout << "Enter loop start value: ";
//     cin >> loopStart;
//     cout << "Enter loop end value: ";
//     cin >> loopEnd;

//     for (int i = loopStart; i <= loopEnd; ++i)
//     {
//         sum += i;
//         sum = sum + i;
//     }

//     cout << "Sum of numbers between " << loopStart << " and " << loopEnd << " is: " << sum << endl;

//     return 0;
// }

//-------------Question 4---------------------//

// #include <iostream>

// using namespace std;

// int main() {
//     float AIR_SPEED = 1100;   // Speed of sound in air in feet per second
//     float WATER_SPEED = 4900; // Speed of sound in water in feet per second
//     float STEEL_SPEED = 16400; // Speed of sound in steel in feet per second

//     char choice;
//     float distance, time;

//     cout << "Select a medium:\n";
//     cout << "A - Air\n";
//     cout << "W - Water\n";
//     cout << "S - Steel\n";
//     cin >> choice;

//     // Validate
//     while (choice != 'A' && choice != 'a' && choice != 'W' && choice != 'w' && choice != 'S' && choice != 's') {
//         cout << "Invalid choice. Please select A, W, or S: ";
//         cin >> choice;
//     }

//     cout << "Enter the distance in feet: ";
//     cin >> distance;

//     // Validate distance input
//     while (distance < 0) {
//         cout << "Distance cannot be negative. Enter a valid distance in feet: ";
//         cin >> distance;
//     }

//     // Calculate time based on user's choice
//     if (choice == 'A' || choice == 'a') {
//         time = distance / AIR_SPEED;
//     } else if (choice == 'W' || choice == 'w') {
//         time = distance / WATER_SPEED;
//     } else {
//         time = distance / STEEL_SPEED;
//     }

//     // Display
//     cout << "Time taken: "  << time << " seconds" << endl;

//     return 0;
// }

//-------------Question 5---------------------//

// #include <iostream>
// using namespace std;

// int main() {
//     char package;
//     int hours;
//      float pack_A_cost = 9.95;
//      float pack_B_cost = 14.95;
//      float pack_C_cost = 19.95;
//      int PACKAGE_A_HOURS = 10;
//      int PACKAGE_B_HOURS = 20;
//      int MAX_HOURS = 744;
//     double totalAmount;

//     cout << "Enter the package (A, B, or C): ";
//     cin >> package;

//     // Validate
//     while (package != 'A' && package != 'a' && package != 'B' && package != 'b' && package != 'C' && package != 'c') {
//         cout << "Invalid choice. Please enter A, B, or C: ";
//         cin >> package;
//     }

//     // Ask for the number of hours used
//     cout << "Enter the number of hours used: ";
//     cin >> hours;

//     // Validate the number of hours used
//     while (hours < 0 || hours > MAX_HOURS) {
//         cout << "Invalid number of hours. Please enter a valid number between 0 and 744: ";
//         cin >> hours;
//     }

//     // Calculate total amount based on the package and additional hours
//     if (package == 'A' || package == 'a') {
//         totalAmount = pack_A_cost;
//         if (hours > PACKAGE_A_HOURS) {
//             totalAmount += (hours - PACKAGE_A_HOURS) * 2.00;
//         }
//     } else if (package == 'B' || package == 'b') {
//         totalAmount = pack_B_cost;
//         if (hours > PACKAGE_B_HOURS) {
//             totalAmount += (hours - PACKAGE_B_HOURS) * 1.00;
//         }
//     } else {
//         totalAmount = pack_C_cost; // Package C has unlimited access
//     }

//     cout << "Total amount due: $" << totalAmount << endl;

//     return 0;
// }

//-------------Question 6---------------------//

// #include <iostream>
// #include <string>
// using namespace std;
// int main() {
//     int temperature;
//     string freezingSubstances = "";
//     string boilingSubstances = "";

//     // Ask the user to enter a temperature
//     cout << "Enter the temperature in Fahrenheit: ";
//     cin >> temperature;

//     // Check substances based on the given temperature
//     if (temperature <= 32) {
//         freezingSubstances += "Water ";
//         boilingSubstances += " ";
//     }
//     if (temperature <= -173) {
//         freezingSubstances += "Ethyl alcohol ";
//         boilingSubstances += " ";
//     }
//     if (temperature <= -38) {
//         freezingSubstances += "Mercury ";
//         boilingSubstances += " ";
//     }
//     if (temperature <= -362) {
//         freezingSubstances += "Oxygen ";
//         boilingSubstances += " ";
//     }
//     if (temperature >= 172) {
//         freezingSubstances += " ";
//         boilingSubstances += "Ethyl alcohol ";
//     }
//     if (temperature >= 676) {
//         freezingSubstances += " ";
//         boilingSubstances += "Mercury ";
//     }
//     if (temperature >= -306) {
//         freezingSubstances += " ";
//         boilingSubstances += "Oxygen ";
//     }
//     if (temperature >= 212) {
//         freezingSubstances += " ";
//         boilingSubstances += "Water ";
//     }

//     // Output the substances
//     cout << "Substances that will freeze at " << temperature << "°F: " << freezingSubstances << endl;
//     cout << "Substances that will boil at " << temperature << "°F: " << boilingSubstances << endl;

//     return 0;
// }

//-------------Question 7---------------------//

// #include <iostream>
// using namespace std;
// int main() {
//     int speed, hours;

//     cout << "What is the speed of the vehicle in mph? ";
//     cin >> speed;

//     while (speed < 0) {
//         cout << "Speed cannot be negative. Please enter a valid speed: ";
//         cin >> speed;
//     }

//     cout << "How many hours has it traveled? ";
//     cin >> hours;

//     while (hours < 1) {
//         cout << "Number of hours must be at least 1. Please enter a valid number of hours: ";
//         cin >> hours;
//     }

//     cout << "Hour  Distance Traveled\n";
//     for (int i = 1; i <= hours; ++i) {
//         int distance = speed * i;
//         cout << i << "  " << distance << endl;
//     }

//     return 0;
// }

//-------------Question 8---------------------//

// #include <iostream>
// using namespace std;
// int main() {
//     int numFloors, totalRooms = 0, totalOccupiedRooms = 0;

//     cout << "How many floors does the hotel have? ";
//     cin >> numFloors;

//     // Validate
//     while (numFloors < 1) {
//         cout << "Number of floors must be at least 1. Please enter a valid number of floors: ";
//         cin >> numFloors;
//     }

//     for (int floor = 1; floor <= numFloors; ++floor) {
//         int numRooms, occupiedRooms;

//         cout << "Enter the number of rooms on floor " << floor << ": ";
//         cin >> numRooms;

//         // Validate
//         while (numRooms < 1) {
//             cout << "Number of rooms must be at least 1. Please enter a valid number of rooms: ";
//             cin >> numRooms;
//         }

//         cout << "Enter the number of occupied rooms on floor " << floor << ": ";
//         cin >> occupiedRooms;

//         // Validate
//         while (occupiedRooms < 0 || occupiedRooms > numRooms) {
//             cout << "Invalid number of occupied rooms. Please enter a valid number: ";
//             cin >> occupiedRooms;
//         }

//         totalRooms += numRooms;
//         totalOccupiedRooms += occupiedRooms;
//     }

//     // Calculate and display occupancy rate
//     double occupancyRate = (totalOccupiedRooms / totalRooms) * 100;
//     cout << "Total rooms in the hotel: " << totalRooms << endl;
//     cout << "Total occupied rooms: " << totalOccupiedRooms << endl;
//     cout << "Total unoccupied rooms: " << totalRooms - totalOccupiedRooms << endl;
//     cout << "Occupancy rate: " << occupancyRate << "%\n";

//     return 0;
// }

//-------------Question 9---------------------//

// #include <iostream>
// #include <climits>
// using namespace std;
// int main() {
//     int number, largest = INT_MIN, smallest = INT_MAX;

//     cout << "Enter a series of integers (-99 to end):\n";

//     // Loop to input integers until -99 is entered
//     while (true) {
//         cin >> number;

//         if (number == -99) {
//             break;
//         }

//         if (number > largest) {
//             largest = number;
//         }
//         if (number < smallest) {
//             smallest = number;
//         }
//     }

//     // Display the largest and smallest numbers
//     if (largest == INT_MIN && smallest == INT_MAX) {
//         cout << "No valid numbers entered.\n";
//     } else {
//         cout << "Largest number entered: " << largest << endl;
//         cout << "Smallest number entered: " << smallest << endl;
//     }

//     return 0;
// }

//-------------Question 10---------------------//

// #include <iostream>

// using namespace std;
// int main() {
//     int employeeNumber;
//     double grossPay, stateTax, federalTax, ficaWithholdings;
//     double totalGrossPay = 0, totalStateTax = 0, totalFederalTax = 0, totalFicaWithholdings = 0, totalNetPay = 0;

//     while (true) {

//         cout << "Enter employee number (0 to end): ";
//         cin >> employeeNumber;

//         if (employeeNumber == 0) {
//             break;
//         }

//         cout << "Enter gross pay: $";
//         cin >> grossPay;

//         while (grossPay < 0) {
//             cout << "Invalid gross pay. Please enter a non-negative value: $";
//             cin >> grossPay;
//         }

//         cout << "Enter state tax: $";
//         cin >> stateTax;

//         while (stateTax < 0 || stateTax > grossPay) {
//             cout << "Invalid state tax. Please enter a non-negative value less than or equal to gross pay: $";
//             cin >> stateTax;
//         }

//         cout << "Enter federal tax: $";
//         cin >> federalTax;

//         while (federalTax < 0 || federalTax > grossPay) {
//             cout << "Invalid federal tax. Please enter a non-negative value less than or equal to gross pay: $";
//             cin >> federalTax;
//         }

//         cout << "Enter FICA withholdings: $";
//         cin >> ficaWithholdings;

//         while (ficaWithholdings < 0 || ficaWithholdings > grossPay) {
//             cout << "Invalid FICA withholdings. Please enter a non-negative value less than or equal to gross pay: $";
//             cin >> ficaWithholdings;
//         }

//         if (stateTax + federalTax + ficaWithholdings > grossPay) {
//             cout << "Error: The sum of state tax, federal tax, and FICA withholdings cannot exceed gross pay.\n";
//             continue;
//         }

//         double netPay = grossPay - stateTax - federalTax - ficaWithholdings;

//         totalGrossPay += grossPay;
//         totalStateTax += stateTax;
//         totalFederalTax += federalTax;
//         totalFicaWithholdings += ficaWithholdings;
//         totalNetPay += netPay;
//     }

//     cout << "\nWeekly Payroll Report Totals:\n";
//     cout << "Total Gross Pay: $" << totalGrossPay << endl;
//     cout << "Total State Tax: $" << totalStateTax << endl;
//     cout << "Total Federal Tax: $" << totalFederalTax << endl;
//     cout << "Total FICA Withholdings: $" << totalFicaWithholdings << endl;
//     cout << "Total Net Pay: $" << totalNetPay << endl;

//     return 0;
// }

//-------------Question 11---------------------//

#include <iostream>
using namespace std;
int main()
{
    int patternSize = 10;

    // Pattern A
    cout << "Pattern A:\n";
    for (int i = 1; i <= patternSize; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            cout << "*";
        }
        cout << endl;
    }

    // Pattern B
    cout << "\nPattern B:\n";
    for (int i = patternSize; i >= 1; --i)
    {
        for (int j = 1; j <= i; ++j)
        {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}
