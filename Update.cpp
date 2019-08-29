#include <array>
#include <iostream>
#include <string>
class Tic {  // Class
       private:
	std::array<char, 9> table = {'0', '1', '2', '3', '4',
				     '5', '6', '7', '8'};  // Char array
       public:
	void board();
	bool mov(char *, int);  // Fucntion prototype
	bool winner();
};

//-------------------------Functions----------------------------------------------//
void Tic::board() {  // Function Board display
	std::cout << table[0] << "|" << table[1] << "|" << table[2]
		  << std::endl;
	std::cout << table[3] << "|" << table[4] << "|" << table[5]
		  << std::endl;
	std::cout << table[6] << "|" << table[7] << "|" << table[8]
		  << std::endl;
}
bool Tic::mov(char *G, int pos) {
	if (*G != 'X' && *G != 'Y') {
		std::cout << "Error != (X or Y)" << std::endl;
		return false;
	} else {
		table[pos] = *G;
		return true;
	}
}
bool Tic::winner() {
	// Right
	if (table[0] == 'X' && table[1] == 'X' && table[2] == 'X') {
		std::cout << "winner is X" << std::endl;
		return true;
	} else if (table[0] == 'Y' && table[1] == 'Y' && table[2] == 'Y') {
		std::cout << "Winner is Y" << std::endl;
		return true;
	} else if (table[3] == 'X' && table[4] == 'X' && table[5] == 'X') {
		std::cout << "Winner is X " << std::endl;
		return true;
	} else if (table[3] == 'Y' && table[4] == 'Y' && table[5] == 'Y') {
		std::cout << "Winner is Y" << std::endl;
		return true;
	} else if (table[6] == 'X' && table[7] == 'X' && table[8] == 'X') {
		std::cout << "Winnner is X" << std::endl;
		return true;
	} else if (table[6] == 'Y' && table[7] == 'Y' && table[8] == 'Y') {
		std::cout << "Winner is Y" << std::endl;
		return true;
	}
	// Down
	else if (table[0] == 'X' && table[3] == 'X' && table[6] == 'X') {
		std::cout << "Winnerr is X" << std::endl;
		return true;
	} else if (table[0] == 'Y' && table[3] == 'Y' && table[6] == 'Y') {
		std::cout << "Winner is Y" << std::endl;
		return true;
	} else if (table[1] == 'X' && table[4] == 'X' && table[7] == 'X') {
		std::cout << "Winner is X" << std::endl;
		return true;
	} else if (table[1] == 'Y' && table[4] == 'Y' && table[7] == 'Y') {
		std::cout << "Winner is Y" << std::endl;
		return true;
	} else if (table[2] == 'X' && table[5] == 'X' && table[8] == 'X') {
		std::cout << "Winner is X" << std::endl;
		return true;
	} else if (table[2] == 'Y' && table[5] == 'Y' && table[8] == 'Y') {
		std::cout << "Winnner is Y" << std::endl;
		return true;
	}
	// Vertical
	else if (table[0] == 'X' && table[4] == 'X' && table[8] == 'X') {
		std::cout << "Winner is X" << std::endl;
	} else if (table[0] == 'Y' && table[4] == 'Y' && table[8] == 'Y') {
		std::cout << "Winner is Y" << std::endl;
		return true;
	} else if (table[2] == 'X' && table[4] == 'X' && table[6] == 'X') {
		std::cout << "Winner is X" << std::endl;
		return true;
	} else if (table[2] == 'Y' && table[4] == 'Y' && table[6] == 'Y') {
		std::cout << "Winner is Y" << std::endl;
		return true;
	}
}

//-----------------------------Functions-end-----------------------------------//
int main()  // Main function
{
	bool flag;
	char p;
	int H;
	Tic T;
	for (;;) {
		T.board();
		std::cout << "Enter (X or Y): ";
		std::cin >> p;
		std::cout << "Enter postion (0,9): ";
		std::cin >> H;
		T.mov(&p, H);
		T.winner();
	}
}
