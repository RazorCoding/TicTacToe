#include<iostream>
#include<vector>
#include<cstdlib>
#include<array>
std::array<char, 10> board = {'0','1','2','3','4','5','6','7','8','9'};
class Tic{	
	public:
	int HumanMove(unsigned int pos, char X){
		if(board[pos] == 'X' || board[pos] == 'Y'){
			std::cout << "Postion is already filled" << std::endl;
			return -1;
		}
		else{
			board[char(pos)] = X;
			std::cout << "You made your move"  << std::endl;
			return 0;
		}
		
	}
	
	void ComputerMove(char Y){
		if(board[5] != '5'){
			if((board[1] == '1' || board[2] == '2') && (board[3] == '3' || board[4] == '4') && (board[7] == '7' || board[4] == '4') && (board[8] == '8' || board[9] == '9')
			&& (board[6] == '6' || board[4] == '4')){	
				board[rand() % 9 ] = Y;
				if( int T = board[rand() % 9 ] == '5'){
					board[rand() % 9 ] = Y;
				}
			}
		}
		for(int i=1;i<10;i++){
			if(board[i]-0x30 == i){
				board[i] = Y;
				break;
			}
			if(i==5)
				i++;
		}
		WinFunc(Y);
	}
	void Board(){
		std::cout << board[1] << "|" << board[2] << "|" << board[3] << std::endl;
		std::cout << board[4] << "|" << board[5] << "|" << board[6] << std::endl;
		std::cout << board[7] << "|" << board[8] << "|" << board[9] << std::endl;
	}
	void WinFunc(char mark)
	{
		char win[8][4] = { {'0','1','2','3'},{'1','4','5','6'},
			    	   {'2','7','8','9'},{'3','1','4','7'},
				   {'4','2','5','8'},{'5','3','6','9'},
				   {'6','1','5','9'},{'7','3','5','7'} };
		for(int i=0;i<=3;i++)
		{
			if(mark == win[0][0])
			{
				std::cout << "First Match" << std::endl;
			}
			else if(mark == win[1][3])
			{
				std::cout << "Second Match" << std::endl;
			}
			else if(mark == win[3][4])
			{
				std::cout << "Thrid Match" << std::endl;
				std::cout << "You Win "    << std::endl;
			}
		}
	}
};	
int main(){
	char X = 'X';
	char Y = 'Y';
	for(int i;i<=5;i++){
		Tic T;
		T.Board();
		std::cout << "On which postion: 1-9" << std::endl;
		unsigned int pos;
		std::cin >> pos;
        	while(T.HumanMove(pos,X)){
        		std::cout << "On which postion: 1-9" << std::endl;
        		std::cin >> pos;
			if(pos!='0')
			{
				for(int y=0;y<=3;y++)
				{
					T.WinFunc(X);
				}
			}
		}
		T.ComputerMove(Y);
	}
	return 0;
}
