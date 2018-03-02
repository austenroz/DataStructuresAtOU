/* 
Authors: Austen Rozanski (OU ID: 113371188)
Date Created: 02/04/2017
Last Modified: 02/06/2017

Program: Project 1 (BagOfItems)
For Data Structures
*/

#include <iostream>

using namespace std;

/* Item Class
   Attributes: int code(1:Pens, 2:Printer, 3:SafeBox), 
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
	public:
		//Getters and Setters
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

		//Methods
		void Display() {
			cout << "Code: " << code << ", Color: " << color << ", Brand: " << brand << ", Height: " << height <<
				", Length: " << length << ", Width: " << width << ", Weight: " << weight << ", Price: " << price << ", Type: "
				<< type << endl;
		}

		//Constructors and Destructors
		Item() {
			///cout << "Creating object" << endl;
			code = color = brand = type = 0;
			height = length = width = weight = price = 0.0;
		}
		Item(int code, int color, int brand, double height, double length, double width, double weight, double price, int type) {
			///cout << "Creating object" << endl;

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

	protected:
		//Attributes
		int code;
		int color;
		int brand;
		double height;
		double length;
		double width;
		double weight;
		double price;
		int type;
};

/* Pens class
   Attributes: Item attributes,
               bool assortedInk,
			   int packetSize

	Methods: Item methods,
	         getters and setters for Pens attributes
			 void Display()
*/
class Pens :  public Item {
	public:
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

		//Constructors
		Pens() :Item(1, 0, 0, 0.0, 0.0, 0.0, 0.0, 0.0, 0) {
			assortedInk = false;
			packetSize = 0;
		}
		Pens(int color, int brand, double height, double length, double width, double weight, double price, int type, 
				bool assortedInk, int packetSize) :Item(1, color, brand, height, length, width, weight, price, type) {
			this->assortedInk = assortedInk;
			this->packetSize = packetSize;
		}

	protected:
		//Attributes
		bool assortedInk;
		int packetSize;
};

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
		Printer() :Item(2, 0, 0, 0.0, 0.0, 0.0, 0.0, 0.0, 0) {
			network = false;
			trayCapacity = 0;
		}
		Printer(int color, int brand, double height, double length, double width, double weight, double price, int type,
				bool network, int trayCapacity) :Item(2, color, brand, height, length, width, weight, price, type) {
			this->network = network;
			this->trayCapacity = trayCapacity;
		}

	protected:
		//Attributes
		bool network;
		int trayCapacity;
};

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
		SafeBox() :Item(3, 0, 0, 0.0, 0.0, 0.0, 0.0, 0.0, 0) {
			fireResistant = false;
			electronicLock = false;
		}
		SafeBox(int color, int brand, double height, double length, double width, double weight, double price, int type,
				bool fireResistant, int electronicLock) :Item(3, color, brand, height, length, width, weight, price, type) {
			this->fireResistant = fireResistant;
			this->electronicLock = electronicLock;
		}

	protected:
		//Attributes
		bool fireResistant;
		bool electronicLock;
};


//METHOD: Null Termination Method
//DESC: Used to replace default char variable values with null terminators
void NullTerminate(char* str, int size) {
	for (int i = 0; i < size; i++) {
		str[i] = '\0';
	}
}

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
//Main Method

int main()
{
	//Bag for holding all item variables
	Item* bag[256];
	int bagPos = 0;

	//Initial output
	cout << "Enter commands and enter the eof when finished. (ctrl+z on windows)" << endl << endl;

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
				int quantity, code, color, brand, type;
				double height, length, width, weight, price;
				cin >> quantity >> code >> color >> brand >> height >> length >> width >> weight >> price >> type;

				//Use the code input to determine what class to use
				switch (code) {
					case 1: {//Pens
						//Store remaining input into variables
						bool assortedInk;
						int packetSize;
						cin >> assortedInk >> packetSize;
						//Create new pens objects based on quantity input
						for (int i = 0; i < quantity; i++) {
							bag[bagPos] = new Pens(color, brand, height, length, width, weight, price, type, assortedInk, packetSize);
							bagPos++;
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
							bag[bagPos] = new Printer(color, brand, height, length, width, weight, price, type, network, trayCapacity);
							bagPos++;
						}
						break;
					}
					case 3: {//Safe Box
						//Store remaining input into variables
						bool fireResistant, electronicLock;
						cin >> fireResistant >> electronicLock;
						//Create new safeBox objects based on quantity input
						for (int i = 0; i < quantity; i++) {
							bag[bagPos] = new SafeBox(color, brand, height, length, width, weight, price, type, fireResistant, electronicLock);
							bagPos++;
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
			else {
				cout << "Invalid Command." << endl;
				//Clear the previous input
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}
	}

	//Output all objects in the bag
	for (int i = 0; i < bagPos; i++) {
		cout << "Item " << (i + 1) << ":" << endl;
		if (bag[i]->getCode() == 0)
			bag[i]->Display();
		else if (bag[i]->getCode() == 1)
			(static_cast<Pens*>(bag[i]))->Display();
		else if (bag[i]->getCode() == 2)
			(static_cast<Printer*>(bag[i]))->Display();
		else if (bag[i]->getCode() == 3)
			(static_cast<SafeBox*>(bag[i]))->Display();
		cout << endl;
	}

	//Delete all objects in the bag from memory
	for (int i = 0; i < bagPos; i++) {
		delete bag[i];
	}

	return 0;
}