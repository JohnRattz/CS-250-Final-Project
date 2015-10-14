#include <ctime>
#include <iostream>

#include "gate.h"
#include "utilities.h"

using namespace std;

Lots* gate::parkingLots = new Lots;
bool gate::lotPriceFirstIncrease = false;
bool gate::lotPriceSecondIncrease = false;

void gate::displayGateStatus() const
{
    printHorizontalLine();
    cout << endl
         << "Gate " << gateLetter << ": Lot Information" << endl;
    printHorizontalLine();
    cout << endl
         << setw(15) << "Lot ID" << " | " << setw(15) << "Max Capacity" << " | "
         << setw(15) << "Available Spots" << " | " << "Cost" << " | "
         << setw(15) << "Distance" << endl;
    printHorizontalLine();
    cout << endl;

    for (int i = 0; i < parkingLots->getTotalLots(); i++)
    {
        parkingLots->printLot(lotOrder[i]); //Print each row of lots in the proper order for this gate
        cout << setw(15) << distancesFromLots[lotOrder[i]] << endl;
    }

    cout << endl
         << setw(15) << "Total" << " | " << setw(15) << parkingLots->getTotalSpots() << " | "
         << setw(15) << parkingLots->getTotalAvailableSpots() << " | "; timestamp();
         cout << endl << endl;
}
