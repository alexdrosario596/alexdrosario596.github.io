#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

class ItemTracker {
public:
    void readDataFile();    // function to read the input file and populate the map
    void displayMenu();     // function to display menu
    void backupDataFile(); // function to backup the item frequency data to a file
private:
    map<string, int> itemFrequency;    // map to store item frequencies
    void searchItem();
    void printFrequencyList();
    void printHistogram();
};

void ItemTracker::readDataFile() {          
    ifstream dataFile("CS210_Project_Three_Input_File.txt");     //open the input file
    string item;
    while (dataFile >> item) {                                  //read the file line by line
        itemFrequency[item]++;                                  // increment frequency
    }
    dataFile.close();                                           //close file
}

void ItemTracker::displayMenu() {              //Menu display
    int choice;
    do {
        cout << "\nMenu\n";
        cout << "1. Search for an item\n";
        cout << "2. Print the frequency list\n";
        cout << "3. Print a histogram\n";
        cout << "4. Backup the data file\n"; // add an option to backup the item frequency data to a file
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            searchItem();
            break;
        case 2:
            printFrequencyList();
            break;
        case 3:
            printHistogram();
            break;
        case 4:
            backupDataFile(); // call the backupDataFile function to backup the item frequency data to a file
            break;
        case 5:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);
}

void ItemTracker::searchItem() {               //Menu option 1
    string item;
    cout << "Enter the item to search for: ";
    cin >> item;
    if (itemFrequency.find(item) == itemFrequency.end()) {  // check if item is in the map
        cout << item << " not found.\n";
    }
    else {
        cout << "Frequency of " << item << " = " << itemFrequency[item] << endl;
    }
}

void ItemTracker::printFrequencyList() {          //Menu option 2
    cout << "Frequency list:\n";
    for (auto const& item : itemFrequency) {
        cout << item.first << " " << item.second << endl;
    }
}

void ItemTracker::printHistogram() {                 //Menu option 3
    cout << "Histogram:\n";
    for (auto const& item : itemFrequency) {
        cout << item.first << " ";
        for (int i = 0; i < item.second; i++) {
            cout << "#";
        }
        cout << endl;
    }
}

void ItemTracker::backupDataFile() {        //Menu option 4
    ofstream backupFile("frequency.dat"); // create a new output file for backing up the item frequency data
    for (auto const& item : itemFrequency) {
        backupFile << item.first << " " << item.second << endl; // write each item and its frequency to the output file
    }
    backupFile.close(); // close the output file
    cout << "Data file backed up to frequency.dat\n";
}

int main() {
    ItemTracker itemTracker;
    itemTracker.readDataFile();
    itemTracker.displayMenu();
    return 0;
}