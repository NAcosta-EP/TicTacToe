#include <iostream>

void Board();
void NewGame();
int CheckWin(char* spaceArray);

char newspace[9] = { '0','1','2','3','4','5','6','7','8'};
char spaces[9];
char symbol;

int turn = 1;
int player = 1;
int status = 1;

std::string msg = "NULL";

bool running = true;

int main()
{	
	int choice = 0;
	while (running)
	{
		NewGame();
		Board();
		while (status == 1)
		{
			Board();
			player = (turn % 2) ? 1 : 2;
			symbol = (player == 1) ? 'X' : 'O';
			std::cout << "Player " << player << ", your move, enter space number: ";
			std::cin >> choice;

			if (spaces[choice] == newspace[choice]) {
				spaces[choice] = symbol;
				turn++;
			}
			else {
				std::cout << "Invalid Move";
				std::cin.ignore();
				std::cin.get();
			}
			status = CheckWin(spaces);
		}
		Board();
		if (status == 0) {
			std::cout << "Player " << player << " WINS!" << std::endl;
		}
		else if (status == 2) {
			std::cout << "DRAW" << std::endl;
		}

		std::cout << "New Game? (1/0): ";
		std::cin >> choice;
		if (!choice) {
			break;
		}
	}
}

void NewGame()
{
	player = 1;
	turn = 1;
	status = 1;
	std::copy(std::begin(newspace), std::end(newspace), std::begin(spaces));
}

/*void GameState() {
	messageBuffer = "Player 1 Wins";
}*/

int CheckWin(char* spaceArray)
{
	if (spaceArray[0] == spaceArray[1] && spaceArray[1] == spaceArray[2]){
		return 0;
	}
	else if (spaceArray[3] == spaceArray[4] && spaceArray[4] == spaceArray[5]){
		return 0;
	}
	else if (spaceArray[6] == spaceArray[7] && spaceArray[7] == spaceArray[8]) {
		return 0;
	}
	else if (spaceArray[0] == spaceArray[3] && spaceArray[3] == spaceArray[6]) {
		return 0;
	}
	else if (spaceArray[1] == spaceArray[4] && spaceArray[4] == spaceArray[7]) {
		return 0;
	}
	else if (spaceArray[2] == spaceArray[5] && spaceArray[5] == spaceArray[8]) {
		return 0;
	}
	else if (spaceArray[0] == spaceArray[4] && spaceArray[4] == spaceArray[8]) {
		return 0;
	}
	else if (spaceArray[2] == spaceArray[4] && spaceArray[4] == spaceArray[6]) {
		return 0;
	}
	else if (spaceArray[0] != '0' && spaceArray[1] != '1' && spaceArray[2] != '2' && spaceArray[3] != '3'
		&& spaceArray[4] != '4' && spaceArray[5] != '5' && spaceArray[6] != '6'
		&& spaceArray[7] != '7' && spaceArray[8] != '8') {
		return 2;
	} 
	else {
		return 1;
	}
}
void Board()
{
	std::system("cls");
	std::cout << "TicTacToe - Build 0.1.0" << std::endl;
	std::cout << "     |     |     " << std::endl;
	std::cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "  " << std::endl;
	std::cout << "_____|_____|_____" << std::endl;
	std::cout << "     |     |     " << std::endl;
	std::cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "  " << std::endl;
	std::cout << "_____|_____|_____" << std::endl;
	std::cout << "     |     |     " << std::endl;
	std::cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "  " << std::endl;
	std::cout << "     |     |     " << std::endl;
}