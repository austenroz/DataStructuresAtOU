/*
Authors: Austen Rozanski (OU ID: 113371188)
Date Created: 02/04/2017
Last Modified: 03/02/2017

Program: Project 2 (BagOfItems)
For Data Structures
*/

#include <iostream>

using namespace std;

/////////////////////////////////////////////////////////////////////////////////////
//ITEM CLASS
/////////////////////////////////////////////////////////////////////////////////////
/* Item Class
Attributes: int itemID
int code(1:Pens, 2:Printer, 3:SafeBox),
int color( Pens(1:Red, 2:Blue, 3:Green, 4:Black), Printer(1:Black, 2:White), Safe Box(1:Black, 2:Red)),
int brand( Pens(1:Pilot, 2:PaperMate, 3:UniBall, 4:Sharpie), Printer(1:Dell, 2:HP, 3:Cannon, 4:Brother),
SafeBox(1:SentrySafe, 2:FirstAlert, 3:Honeywell)),
double height, double length, double width, double weight, double price,
int type( Pens(1:BallPoint, 2:RollerBall, 3:Fountain, 4:Calligraphy), Printer(1:AllInOne, 2:Laser, 3:InkJet),
Safe Box(1:WaterProof, 2:WallMountable, 3:Desktop))

Methods: getters and setters for each attribute.
void Display()
*/
class Item {
	protected:
		//Attributes
		int itemID;
		int code;
		int color;
		int brand;
		double height;
		double length;
		double width;
		double weight;
		double price;
		int type;
	public:
		//Constructors and Destructors
		Item() {
			///cout << "Creating object" << endl;
			code = color = brand = type = 0;
			height = length = width = weight = price = 0.0;
		}
		Item(int itemID, int code, int color, int brand, double height, double length, double width, double weight, double price, int type) {
			///cout << "Creating object" << endl;
			this->itemID = itemID;
			this->code = code;
			this->color = color;
			this->brand = brand;
			this->height = height;
			this->length = length;
			this->width = width;
			this->weight = weight;
			this->price = price;
			this->type = type;
		}
		~Item() {
			///cout << "Deconstructing object." << endl;
		}

		//Methods
		virtual void Display() {
			cout << "Item ID: " << itemID << endl;
		}

		//Getters and Setters
		void setItemID(int itemID) {
			this->itemID = itemID;
		}
		int getItemID() {
			return itemID;
		}
		void setCode(int code) {
			this->code = code;
		}
		int getCode() {
			return code;
		}
		void setColor(int color) {
			this->color = color;
		}
		int getColor() {
			return color;
		}
		void setBrand(int brand) {
			this->brand = brand;
		}
		int getBrand() {
			return brand;
		}
		void setHeight(double height) {
			this->height = height;
		}
		double getHeight() {
			return height;
		}
		void setLength(double length) {
			this->length = length;
		}
		double getLength() {
			return length;
		}
		void setWidth(double width) {
			this->width = width;
		}
		double getWidth() {
			return width;
		}
		void setWeight(double weight) {
			this->weight = weight;
		}
		double getWeight() {
			return weight;
		}
		void setPrice(double price) {
			this->price = price;
		}
		double getPrice() {
			return price;
		}
		void setType(int type) {
			this->type = type;
		}
		int getType() {
			return type;
		}
};

/////////////////////////////////////////////////////////////////////////////////////
//PENS CLASS
/////////////////////////////////////////////////////////////////////////////////////
/* Pens class
Attributes: Item attributes,
bool assortedInk,
int packetSize

Methods: Item methods,
getters and setters for Pens attributes
void Display()
*/
class Pens : public Item {
	protected:
		//Attributes
		bool assortedInk;
		int packetSize;
	public:
		//Constructors and Destructors
		Pens() : Item(0, 1, 0, 0, 0.0, 0.0, 0.0, 0.0, 0.0, 0) {
			assortedInk = false;
			packetSize = 0;
		}
		Pens(int itemID, int color, int brand, double height, double length, double width, double weight, double price, int type,
			 bool assortedInk, int packetSize) :Item(itemID, 1, color, brand, height, length, width, weight, price, type) {
			this->assortedInk = assortedInk;
			this->packetSize = packetSize;
		}
		~Pens(){

		}

		//Methods
		void Display() {

			//Output code and color
			cout << "Code: 1 (Pens), Color: ";
			switch (color) {
			case 1: {//Red
				cout << "Red, ";
				break;
			}
			case 2: {//Blue
				cout << "Blue, ";
				break;
			}
			case 3: {//Green
				cout << "Green, ";
				break;
			}
			case 4: {//Black
				cout << "Black, ";
				break;
			}
			default: cout << "Invalid Color Code: " << color << ", ";
			}

			//Output brand
			cout << "Brand: ";
			switch (brand) {
			case 1: {//Pilot
				cout << "Pilot, ";
				break;
			}
			case 2: {//Papermate
				cout << "Papermate, ";
				break;
			}
			case 3: {//UniBall
				cout << "UniBall, ";
				break;
			}
			case 4: {//Sharpie
				cout << "Sharpie, ";
				break;
			}
			default: cout << "Invalid Brand Code: " << brand << ", ";
			}

			//Output height, length, width, weight, and price
			cout << "Height: " << height << ", Length: " << length << ", Width: " << width <<
				", Weight: " << weight << ", Price: " << price << ", ";

			//Output Type
			cout << "Type: ";
			switch (type) {
			case 1: {//Ballpoint
				cout << "Ballpoint, ";
				break;
			}
			case 2: {//Rollerball
				cout << "Rollerball, ";
				break;
			}
			case 3: {//Fountain
				cout << "Fountain, ";
				break;
			}
			case 4: {//Calligraphy
				cout << "Calligraphy, ";
				break;
			}
			default: cout << "Invalid Type Code: " << type << ", ";
			}
			//Output Assorted Ink
			cout << "Assorted Ink: ";
			if (assortedInk) {
				cout << "Yes, ";
			}
			else {
				cout << "No, ";
			}

			//Output Packet Size
			cout << "Packet Size: " << packetSize << endl;
		}

		//Getters and Setters
		void setAssortedInk(bool assortedInk) {
			this->assortedInk = assortedInk;
		}
		bool getAssortedInk() {
			return assortedInk;
		}
		void setPacketSize(int packetSize) {
			this->packetSize = packetSize;
		}
		int getPacketSize() {
			return packetSize;
		}
};

/////////////////////////////////////////////////////////////////////////////////////
//PRINTER CLASS
/////////////////////////////////////////////////////////////////////////////////////
/* Printer class
Attributes: Item attributes,
bool network,
int trayCapacity

Methods: Item methods,
getters and setters for Printer attributes
void Display()
*/
class Printer : public Item {
public:
	//Getters and Setters
	void setNetwork(bool network) {
		this->network = network;
	}
	bool getNetwork() {
		return network;
	}
	void setTrayCapacity(int trayCapacity) {
		this->trayCapacity = trayCapacity;
	}
	int getTrayCapacity() {
		return trayCapacity;
	}

	//Methods
	void Display() {

		//Output code and color
		cout << "Code: 2 (Printer), Color: ";
		switch (color) {
		case 1: {//Black
			cout << "Black, ";
			break;
		}
		case 2: {//White
			cout << "White, ";
			break;
		}
		default: cout << "Invalid Color Code: " << color << ", ";
		}

		//Output brand
		cout << "Brand: ";
		switch (brand) {
		case 1: {//Dell
			cout << "Dell, ";
			break;
		}
		case 2: {//Cannon
			cout << "Cannon, ";
			break;
		}
		case 3: {//HP
			cout << "HP, ";
			break;
		}
		case 4: {//Brother
			cout << "Brother, ";
			break;
		}
		default: cout << "Invalid Brand Code: " << brand << ", ";
		}

		//Output height, length, width, weight, and price
		cout << "Height: " << height << ", Length: " << length << ", Width: " << width <<
			", Weight: " << weight << ", Price: " << price << ", ";

		//Output Type
		cout << "Type: ";
		switch (type) {
		case 1: {//All-In-One
			cout << "All-In-One, ";
			break;
		}
		case 2: {//Laser
			cout << "Laser, ";
			break;
		}
		case 3: {//Ink Jet
			cout << "Ink Jet, ";
			break;
		}
		default: cout << "Invalid Type Code: " << type << ", ";
		}

		//Output Network
		cout << "Network: ";
		if (network) {
			cout << "Yes, ";
		}
		else {
			cout << "No, ";
		}

		//Output Tray Capacity
		cout << "Tray Capacity: " << trayCapacity << endl;
	}

	//Constructors
	Printer() :Item(0, 2, 0, 0, 0.0, 0.0, 0.0, 0.0, 0.0, 0) {
		network = false;
		trayCapacity = 0;
	}
	Printer(int itemID, int color, int brand, double height, double length, double width, double weight, double price, int type,
		bool network, int trayCapacity) :Item(itemID, 2, color, brand, height, length, width, weight, price, type) {
		this->network = network;
		this->trayCapacity = trayCapacity;
	}

protected:
	//Attributes
	bool network;
	int trayCapacity;
};

/////////////////////////////////////////////////////////////////////////////////////
//SAFEBOX CLASS
/////////////////////////////////////////////////////////////////////////////////////
/* SafeBox class
Attributes: Item attributes,
bool fireResistant,
bool electronicLock

Methods: Item methods,
getters and setters for SafeBox attributes
void Display()
*/
class SafeBox : public Item {
public:
	//Getters and Setters
	void setFireResistant(bool fireResistant) {
		this->fireResistant = fireResistant;
	}
	bool getFireResistant() {
		return fireResistant;
	}
	void setElectronicLock(bool electronicLock) {
		this->electronicLock = electronicLock;
	}
	bool getElectronicLock() {
		return electronicLock;
	}

	//Methods
	void Display() {

		//Output code and color
		cout << "Code: 3 (Safe Box), Color: ";
		switch (color) {
		case 1: {//Black
			cout << "Black, ";
			break;
		}
		case 2: {//Red
			cout << "Red, ";
			break;
		}
		default: cout << "Invalid Color Code: " << color << ", ";
		}

		//Output brand
		cout << "Brand: ";
		switch (brand) {
		case 1: {//Sentry Safe
			cout << "Sentry Safe, ";
			break;
		}
		case 2: {//First Alert
			cout << "First Alert, ";
			break;
		}
		case 3: {//Honeywell
			cout << "Honeywell, ";
			break;
		}
		default: cout << "Invalid Brand Code: " << brand << ", ";
		}

		//Output height, length, width, weight, and price
		cout << "Height: " << height << ", Length: " << length << ", Width: " << width <<
			", Weight: " << weight << ", Price: " << price << ", ";

		//Output Type
		cout << "Type: ";
		switch (type) {
		case 1: {//Waterproof
			cout << "Waterproof, ";
			break;
		}
		case 2: {//Wall Mountable
			cout << "Wall Mountable, ";
			break;
		}
		case 3: {//Desktop
			cout << "Desktop, ";
			break;
		}
		default: cout << "Invalid Type Code: " << type << ", ";
		}

		//Output Fire Resistant
		cout << "Fire Resistant: ";
		if (fireResistant) {
			cout << "Yes, ";
		}
		else {
			cout << "No, ";
		}

		//Output Electronic Lock
		cout << "Electronic Lock: ";
		if (electronicLock) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}

	//Constructors
	SafeBox() :Item(0, 3, 0, 0, 0.0, 0.0, 0.0, 0.0, 0.0, 0) {
		fireResistant = false;
		electronicLock = false;
	}
	SafeBox(int itemID, int color, int brand, double height, double length, double width, double weight, double price, int type,
		bool fireResistant, int electronicLock) :Item(itemID, 3, color, brand, height, length, width, weight, price, type) {
		this->fireResistant = fireResistant;
		this->electronicLock = electronicLock;
	}

protected:
	//Attributes
	bool fireResistant;
	bool electronicLock;
};

/////////////////////////////////////////////////////////////////////////////////////
//BAG CLASS
/////////////////////////////////////////////////////////////////////////////////////
class Bag {
private:
	//Instance Variables
	int numItems;
	Item** myItems;
public:
	//Constructors and Destructors
	Bag() {
		numItems = 0;
		myItems = new Item*[0];
	}
	~Bag() {
		delete[] myItems;
	}

	//Methods

	//Method to add an Item to the bag
	void AddItem(Item* newItem) {
		//Increase the size of the array by creating a new array and duplicating pointers over
		numItems++;
		Item** temp = myItems;
		myItems = new Item*[numItems];

		for (int i = 0; i < numItems - 1; i++) {
			myItems[i] = temp[i];
		}

		//Delete temporary array
		delete[] temp;
		//Add new item into the array
		myItems[numItems - 1] = newItem;
	}

	//Method for deleting items with a specific ID from the bag
	void DelItem(int itemID) {

		//Loop through all items to find item with correct itemID
		for (int i = 0; i < numItems; i++) {
			if (myItems[i]->getItemID() == itemID) {
				//Decrease the size of the array and remove the previous object from it
				int indexToDelete = i;
				i--;
				numItems--;
				Item** temp = myItems;
				myItems = new Item*[numItems];

				for (int ii = 0; ii < indexToDelete; ii++) {
					myItems[ii] = temp[ii];
				}
				for (int ii = indexToDelete; ii < numItems; ii++) {
					myItems[ii] = temp[ii + 1];
				}

				//delete the temporary array
				delete[] temp;
			}
		}
	}

	//Method for displaying all the items within the bag
	void DisplayItems() {

		for (int i = 0; i < numItems; i++) {
			myItems[i]->Display();
		}
		cout << endl << "SUMMARY OF USER: " << endl;

		//Variables to store summary info
		int totalPens = 0;
		double totalPenCost = 0.0;
		int totalPrinters = 0;
		double totalPrinterCost = 0.0;
		int totalSafeboxes = 0;
		double totalSafeboxCost = 0.0;

		//Loop through all items and add values to the summary variables
		for (int i = 0; i < numItems; i++) {
			if (myItems[i]->getCode() == 1) {
				//Item is a pen
				totalPens++;
				totalPenCost += myItems[i]->getPrice();
			}
			else if (myItems[i]->getCode() == 2) {
				//Item is a printer
				totalPrinters++;
				totalPrinterCost += myItems[i]->getPrice();
			}
			else if (myItems[i]->getCode() == 3) {
				//Item is a safebox
				totalSafeboxes++;
				totalSafeboxCost += myItems[i]->getPrice();
			}
		}

		//output pens summary
		cout << "Total Pens: " << totalPens << ", Total Pen Cost: $" << totalPenCost << endl;
		//output printer summary
		cout << "Total Printers: " << totalPrinters << ", Total Printer Cost: $" << totalPrinterCost << endl;
		//output safebox summary
		cout << "Total Safeboxes: " << totalSafeboxes << ", Total Safebox Cost: $" << totalSafeboxCost << endl;
		//output total value
		cout << "Total Value: $" << (totalPenCost + totalPrinterCost + totalSafeboxCost) << endl;
	}
};


/////////////////////////////////////////////////////////////////////////////////////
//NULL TERMINATION METHOD
/////////////////////////////////////////////////////////////////////////////////////
//METHOD: Null Termination Method
//DESC: Used to replace default char variable values with null terminators
void NullTerminate(char* str, int size) {
	for (int i = 0; i < size; i++) {
		str[i] = '\0';
	}
}

/////////////////////////////////////////////////////////////////////////////////////
//MAIN METHOD
/////////////////////////////////////////////////////////////////////////////////////
int main() {

	//Array of users 
	int users[50];
	int numUsers = 0;
	//Array of Bags
	Bag* userBag[50];

	//Initial output
	cout << "Enter commands and enter the eof when finished to see the summary of items. (ctrl+z on windows)" << endl << endl;

	//Loop through input until eof is entered
	while (!cin.eof()) {
		//Create array of chars for input command
		char command[10];
		NullTerminate(command, 10);

		//Put input into command
		cin >> command;

		//Check if command is eof, if not continue
		if (!cin.eof()) {

			//If the command is "AddItem"
			if (strcmp(command, "AddItem") == 0) {

				//Store input into variables
				int userID, itemNumber, quantity, code, color, brand, type;
				double height, length, width, weight, price;
				cin >> userID >> itemNumber >> quantity >> code >> color >> brand >> height >> length >> width >> weight >> price >> type;

				//Determine the index for the users and userBag array using userID
				int userIndex = numUsers;
				for (int i = 0; i < numUsers; i++) {
					if (users[i] == userID) {
						userIndex = i;
					}
				}

				//Create new bag for next element in array if user did not previously exist
				//and put userID value in users array
				if (userIndex == numUsers) {
					userBag[userIndex] = new Bag();
					users[userIndex] = userID;
					numUsers++;
				}

				//Use the code input to determine what class to use
				switch (code) {
					case 1: {//Pens
							 //Store remaining input into variables
						bool assortedInk;
						int packetSize;
						cin >> assortedInk >> packetSize;
						//Create new pens objects based on quantity input
						for (int i = 0; i < quantity; i++) {

							userBag[userIndex]->AddItem(new Pens(itemNumber, color, brand, height, length, width, weight, price, type, assortedInk, packetSize));
						}
						break;
					}
					case 2: {//Printer
							 //Store remaining input into variables
						bool network;
						int trayCapacity;
						cin >> network >> trayCapacity;
						//Create new printer objects based on quantity input
						for (int i = 0; i < quantity; i++) {

							userBag[userIndex]->AddItem(new Printer(itemNumber, color, brand, height, length, width, weight, price, type, network, trayCapacity));
						}
						break;
					}
					case 3: {//Safe Box
							 //Store remaining input into variables
						bool fireResistant, electronicLock;
						cin >> fireResistant >> electronicLock;
						//Create new safeBox objects based on quantity input
						for (int i = 0; i < quantity; i++) {

							userBag[userIndex]->AddItem(new SafeBox(itemNumber, color, brand, height, length, width, weight, price, type, fireResistant, electronicLock));
						}
						break;
					}
					default: {
						cout << "Invalid Code." << endl;
						//Clear the previous input
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}
				}
			}

			else if (strcmp(command, "DelItem") == 0) {
				int userID, itemNumber;
				cin >> userID >> itemNumber;

				//Determine the index for the users and userBag array using userID
				int userIndex = numUsers;
				for (int i = 0; i < numUsers; i++) {
					if (users[i] == userID) {
						userIndex = i;
					}
				}

				if (userIndex != numUsers) {
					//UserID found
					userBag[userIndex]->DelItem(itemNumber);
				}
				else {
					//User of userID does not exist
					cout << "User ID is not in the array." << endl;
				}

			}

			else {
				cout << "Invalid Command." << endl;
				//Clear the previous input
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}
	}

	//Output all objects in the userBag array
	for (int i = 0; i < numUsers; i++) {
		cout << endl << endl << "Items for user " << users[i] << endl << endl;
		userBag[i]->DisplayItems();
		cout << endl;
	}

	//Delete all objects in the userBag array
	for (int i = 0; i < numUsers; i++) {
		delete userBag[i];
	}

	return 0;
}