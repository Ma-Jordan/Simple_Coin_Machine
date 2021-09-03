//Jordan Ma
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	int quarters = 25,
		nickels = 25,
		dimes = 25,
		ones = 0,
		fives = 0,
		cQuarters = 0,
		cNickels = 0,
		cDimes = 0,
		cFives = 0,
		cOnes = 0,
		dollars,
		cents;
	//These bools control my while loops
	bool run = true,
		runMenu = true,
		cancel = true;
	//i had to initial some of my doubles for my algorithms to run
	double total, manager, sum, user, payment, refund = 0, withdraw = 0;
	//i used these char in my switch case options
	char q, Q, n, N, d, D, o, O, f, F, c, C, choice, y, userC,use;

	while (run == true)
	{
		//Checks for user input for char 
		cout << "Welcome to the vending machine change maker program\n"
			<< "Change maker initialized.\n"
			<< "Stock contains:\n";
		cout << quarters << " Quarters\n"
			<< dimes << " Dimes\n"
			<< nickels << " Nickels\n"
			<< fives << " Fives\n"
			<< ones << " Ones\n\n";
		cout << "Do you want to quit or proceed? (q to quit or press enter to proceed) \n";
		cin.get(userC);

		if (userC == 'q'|| userC=='Q')
		{
			cout << "The Program has terminated.\n";
			run = false;
		}
		else
		{
			while (runMenu == true)
			{
				while (cancel == true)
				{
					cout << "\nEnter the purchase price(xx.xx): ";
					//This if statement is used to ask for user input and check to see if 
					//the user entry is a double
					if (cin >> user)
					{
						cancel = false;
						break;
					}
					else
					{
						//This clear is to clear the cin stream
						//This is required or else the program goes in an infinite loop
						cin.clear();
						//This conditional statement checks to see if user input is a non-number
						//If so it displays invalid
						if (cin >> use)
						{
							cout << "\nInvalid input, please try again.\n\n";
						}
					}
				}
				cancel = true;
				//this checks to see if the amount is a positive multiple of 5
				if ((user > 0) && (static_cast<int>((user * 100)) % 5 == 0))
				{
					cout << "\t Menu for deposits:\n"
						<< "\t 'q' - deposit a Quater\n"
						<< "\t 'd' - deposit a Dime\n"
						<< "\t 'n' - deposit a Nickel\n"
						<< "\t 'o' - deposit a Dollar Bill\n"
						<< "\t 'f' - deposit a Five Dollar Bill\n"
						<< "\t 'c' - cancel the purchase\n\n";
					payment = user * 100;
					//i converted the user input into cents for easier manipulation
					//if payment is less than 0, a refund loop starts up
					while (payment > 0)
					{
						cout << "Payment due: " << static_cast<int>((payment / 100)) << " dollars and " << static_cast<int>((payment)) % 100 << " cents.\n";
						cout << "Indicate your deposit: ";
						cin >> choice;
						cin.ignore();

						//each case increments and decrements coins and payment accordingly
						//default case checks for valid input
						//the upper case just falls through to next case
						switch (choice)
						{
						case 'F':
						case 'f': payment -= 500;
							refund += 500;
							fives++;
							break;
						case 'O':
						case 'o': payment -= 100;
							refund += 100;
							ones++;
							break;
						case 'Q':
						case 'q': payment -= 25;
							refund += 25;
							quarters++;
							break;
						case 'D':
						case 'd': payment -= 10;
							refund += 10;
							dimes++;
							break;
						case 'N':
						case 'n': payment -= 5;
							refund += 5;
							nickels++;
							break;
						case 'C':
						case 'c': cout << "\nTerminating transaction. " << "Please take the change below.\n\n";
							payment = 0;
							withdraw = refund;
							runMenu = false;
							break;
						default: cout << "Thats an invalid choice. Try again or enter c to Cancel transaction.\n";

						}
					}
					//if payment is perfect, no refund is required
					cout << "\nThank you for your payment.\n\n";
					runMenu = false;
				}
				else
				{
					cout << "Illegal price: Must be a non-negative multiple of 5 cents.";
				}
			}
			if (payment < 0)
			{
				withdraw = (-1) * payment;
				payment = 0;
			}
			//I designed this series of nested loops to
			//go through each denomination and see
			//if I have the coins and if amount owed
			//is at least equal to the amount of each coin
			while (withdraw > 0)
			{
				//Uncomment the following while loops to dispense bills
				/*while (withdraw >= 500 && fives > 0)
				{
					withdraw -= 500;
					fives--;
					cFives++;
				}
				while (withdraw >= 100 && ones > 0)
				{
					withdraw -= 100;
					ones--;
					cOnes++;
				}*/
				while (withdraw >= 25 && quarters > 0)
				{
					withdraw -= 25;
					quarters--;
					cQuarters++;
				}
				while (withdraw >= 10 && dimes > 0)
				{
					withdraw -= 10;
					dimes--;
					cDimes++;
				}
				while (withdraw >= 5 && nickels > 0)
				{
					withdraw -= 5;
					nickels--;
					cNickels++;
				}
				//if there is still a withdraw amount, the manager will have to deal with it
				//this if else section must reset withdraw to 0 for the loop to end
				//reset refund to 0 for next transaction
				if (withdraw > 0)
				{
					manager = withdraw;
					cout << "This machine is out of change. Please go see the manager about your "
						<< static_cast<int>((manager / 100))
						<< " dollars and "
						<< (static_cast<int>(manager) % 100)
						<< " cents.\n\n";
					withdraw = 0;
					refund = 0;
				}
				else
				{
					withdraw = 0;
					refund = 0;
				}
			}
			//this runMenu is very important
			//it resets the state of runMenu so that 
			//my loop will iterate inside the display loop 
			//after the transaction is complete
			runMenu = true;
			//I created 4 unique if statements to test each individual case
			//I did not use else if because i want to check for each coin denomination
			//NOTE ALL REFUND COINS LIKE cQuarters MUST BE RESET TO 0 FOR THE NEXT
			//LOOP OF TRANSACTIONS
			if ((cQuarters + cDimes + cNickels) > 0)
			{
				cout << "\nPlease take your change.\n";
			}
			if (cQuarters > 0)
			{
				cout << cQuarters << "\tQuarters\n";
				cQuarters = 0;
			}
			if (cDimes > 0)
			{
				cout << cDimes << "\tDimes\n";
				cDimes = 0;
			}
			if (cNickels > 0)
			{
				cout << cNickels << "\tNickels\n";
				cNickels = 0;
			}
			cout << "\n--------------------------\n\n\n";
			//Uncomment the following condition to allow bills feature to run
			/*if ((cFives + cOnes + cQuarters + cDimes + cNickels) > 0)
			{
				cout << "\nPlease take your change.\n"
					<< cFives << "\tFives\n"
					<< cOnes << "\tOnes\n"
					<< cQuarters << "\tQuarters\n"
					<< cDimes << "\tDimes\n"
					<< cNickels << "\tNickels\n\n"
					<< "--------------------------\n\n\n";

				cFives = 0;
				cOnes = 0;
				cQuarters = 0;
				cDimes = 0;
				cNickels = 0;
			}*/
		}
	}
	//The final display once the user terminates the loops 
	//the modulus is used to display cents
	dollars = (((fives * 5) + (ones * 1) + (quarters * .25) + (dimes * .10) + (nickels * .05)));
	cents = (((fives * 5) + (ones * 1) + (quarters * .25) + (dimes * .10) + (nickels * .05))) * 100;
	cents = cents % 100;

	cout << "\n\nTotal: " << dollars << " dollars and " << cents << " cents\n\n";

	return 0;

}
