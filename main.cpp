#include "iostream"
#include "task1.h"
#include <iomanip>
#include <string>
using namespace std;

void menu() {
  while (true) {
    cout << string(30, '=') << endl;
    cout << setw(10) << " " << "Main Menu" << endl;
    cout << string(30, '=') << endl;

    // question 1
    cout << "1. Display All Parcel" << endl;
    // question 2
    cout << "2. Search Parcel" << endl;
    cout << "3. View Parcel Detail" << endl;
    cout << "4. Sort & Process Incoming Parcel " << endl;
    // TODO: havent do 5
    cout << "5. Update Parcel Record " << endl;
    cout << "0. Exit" << endl;

    int selection;
    cout << "Enter selection: ";
    cin >> selection;

    switch (selection) {
    case 1:
      displayAllParcel();
      break;

      // Search parcel (question 2)
    case 2: {
      int searchSelection;

      while (true) {
        cout << "Search By:" << endl;
        cout << "1. Parcel ID" << endl;
        cout << "2. Recipient ID" << endl;
        cout << "3. Recipient Name" << endl;
        cout << "4. Delivery Company" << endl;
        cout << "5. Parcel Type" << endl;
        cout << "6. Status" << endl;
        cout << "0. Back to menu" << endl;

        cout << "Enter selection: ";
        cin >> searchSelection;

        if (searchSelection >= 0 && searchSelection <= 5) {
          break;
        }

        cout << "Invalid selection. Please try again.\n";
      }

      if (searchSelection == 0) {
        break;
      }

      string searchTerm;
      cout << "Enter search term to be search: ";
      cin >> searchTerm;

      switch (searchSelection) {
      case 1:
        searchAllMatchingParcel(searchTerm, 1);
        break;
      case 2:
        searchAllMatchingParcel(searchTerm, 2);
        break;
      case 3:
        searchAllMatchingParcel(searchTerm, 3);
        break;
      case 4:
        searchAllMatchingParcel(searchTerm, 4);
        break;
      case 5:
        searchAllMatchingParcel(searchTerm, 5);
        break;
      }
      break;
    }

    // View parcel detail (question 2)
    case 3: {
      cout << "Enter parcel ID: ";

      int parcelID;
      cin >> parcelID;

      viewParcelDetail(parcelID);
      break;
    }

    case 4: {
      processParcel();
      break;
    }

    case 0:
      return;

    default:
      cout << "Invalid selection. Please try again.\n";
      break;
    }
  }
}

int main() { menu(); };
