#include<iostream>
#include<cstring>
#include <string.h>
	/*
	 *   Game: Battleship
			 The game is played on four 10x10 grids by 2 players, with each player having 2 grids each.
			 The rows of the grid go from A to J in the rows and 1 to 10 in the columns. Each player will arrange their ships on
			 their respective ship board before the main game starts. Each ship occupies a number of consecutive squares on the
			 grid, arranged either horizontally or vertically. The number of squares for each ship is determined by the type
			 of the ship. The ships cannot overlap.

			 The ships are as follows:

			 Ship type       		Size
			 --------------------+----------
			 Aircraft carrier    |    5
			 Battleship          |    4
			 Cruiser             |    3
			 Destroyer           |    3
			 Submarine           |    2

			 After the ships have been positioned, the game proceeds in a series of rounds. In each round, each player takes a turn
			 to announce a target square in the opponent's grid which is to be shot at. The opponent announces whether or not
			 the square is occupied by a ship, and if it is a miss, the player marks their guess board as a miss; if it is a hit
			 they mark it as a hit. This is to build up a picture of the opponent's fleet. If the guess was a hit, the attacked
			 player will mark their ship as hit in the guessed location. That will end the turn.

			 When all of the squares of a ship have been hit, the ship is sunk and there is output about what ship was sunk.
			 If all the player's ship have been sunk, the game is over and their opponent wins.

			The Inputs :  
				Ships
				2 Grids
				Player
				Guess

			Ships Behaviour
			---------
			Ship Types , defined above
			Ship Sizes
			Ship Position
			Ship Orientation
			Can be Damaged in a specific spot
		
			Player Behaviour
			----------
			Name
			All The ships
			Remaining Ships
			Guessing board
			Ship board

			Grids Behaviour
			--------
			Board for ship
			2 Different Board
			Grid States ( hit, miss, none )

			Guess Behaviour
			--------
			Input, position of the board
				Input must be at ROW [ A- J ] to COLUMN [ 1 - 10]
	 *
	 *
			 Aircraft carrier    |    5
			 Battleship          |    4
			 Cruiser             |    3
			 Destroyer           |    3
			 Submarine           |    2
	 * */
	/* Step by Step understanding 
	 *
	 * High Level Game
	 *
	 *	InitializePlayer(player 1 )
	 *	InitializePlayer(player 2)
	 *
	 *	do  {
	 *		
	 *		PlayGame(player1, player2);
	 *	
	 *	}	while(WantToPlayAgain());
	 *
	 * PlayGame
	 * ---------
	 *
	 *   -- Player only able to guess Once per turn--
	 *	SetupBoard(player1)
	 *	SetupBoard(player2)
	 *   
	 *  do {
		 *	Drawboard(currentPlayer)
		 *	
		 *	do {
		 *		Prompt the player to Guess Enemy Board
		 *		guess = Get Current Player Guess -> GetGuess(currentPlayer)
		 *		
		 *	}while(!IsValidGuess(...))
		 *
		 *	Updateboard(guess, currentPlayer, otherPlayer);
		 *	Drawboard(currentPlayer);
		 *
		 *	if( a ship was sunk on current player ) {
		 *		Output info that current player sunk that ship
		 *		
		 *		Output the remaining ships
		 *	} 
		 *
		 *	WaitForKeyInput(...)
		 *	SwitchPlayer(...); 
	 *	} while(!IsGameOver())
		 * DisplayWinner(...)
	 *		
	 *	InitializePlayer 
	 *	----------------
	 *	
	 *	initialize Player name  <-- System Generated
	 *	initialize the Ships with max NUM_SHIPS <-- System generated
	 *
	 *	SetupBoard
	 *	----------
	 *	ClearBoards(player)
	 *
	 *	for ( all the ships from the current player) {
	 *		Drawboard(player)
	 *		currentShip = Get The CurrentShip
	 *		do {
						position = Get the ship position for the head of the ship
						orientation = Get the ship orientation
	 *				
	 *				if(!IsValidPlacement()) {
	 *					output the position is not valid placement
	 *				}
	 *
	 *		}	while(!IsValidPlacement())
	 *		
	 *
	 *		PlaceShipOnBoard(player, currentShip, position, orientation);
	 *	}
	 *
	 *	IsValidPlacement
	 *	-----------------
	 *	if(orientation == HORIZONTAL) {
	 *		
	 *		for (all the size of the ship taken) {
	 *			if(current position is not overlap OR the ship will be off the board HORIZONTALLY ) {
	 *				return false
	 *			} 
	 *		}
	 *
	 *	} else {
	 *
	 *		for (all the size of the ship taken) {
	 *			if(current position is not overlap OR the ship will be off the board Vertically ) {
	 *				return false
	 *			} 
	 *		}
	 *
	 *	}
	 *	return true
	 *
	 *
	 *
	 *	PlaceShipOnBoard(player, currentShip, position, orientation)
	 *	---------------------- --------------------------- ----------
	 *	
	 *	if(orientation == HORIZONTAL) {
	 *		
	 *		for(all the colums that the ship would take ) {
	 *				
	 *				Set it to the ship part at position.row with current col value
	 *			
	 *		}
	 *
	 *	} else {
	 *		for(all the rows that the ship would take) {
	 *			
	 *			Set it to the ship part at position.column with current ROW value
	 *			
	 *		}
	 *		
	 *	}
	 *
	 *	IsGameOver(Player1, player2) 
	 *	---------------------------
	 *	return IsAllShipSunk(player1) || IsAllShipSunk(player2)
	 *
	 *
	 *	IsAllShipSunk(Player) 
	 *	---------------------
	 *	for (players ships ) {
	 *
	 *		currentShip = ship
	 *		if(IsSunk(currentShip)) {
	 *			return false
	 *		}
	 *	}
	 *
	 *	return true
	 *
	 *	IsSunk(ship) {
	 *		
	 *		if(ship.orientation == HORIZONTAL ) {
	 *			
	 *			for ( column that ship is take) {
	 *				if(currentColumn on the shipBoard is not hit) {
	 *					return false
	 *				}
	 *			}
	 *
	 *		} else {
	 *
	 *			for ( rows that ship is take) {
	 *				if(currentRow on the shipBoard is not hit) {
	 *					return false
	 *				}
	 *			}
	 *
	 *		}
	 *
	 *		return true
	 *	
	 *	}
	 *
	 *
	 * */
enum {
	AIRCRAFT_CARRIER_SIZE = 5,
	BATTLESHIP_SIZE = 4 ,
	CRUISER_SIZE = 3,
	DESTROYER_SIZE = 3,
	SUBMARINE_SIZE = 2,

	PLAYER_NAME_SIZE = 10,
	BOARD_SIZE = 10,
	NUM_SHIPS = 5,
	MAX_SHIP_SIZE = AIRCRAFT_CARRIER_SIZE,

};

enum ShipType {
	ST_NONE = 0,
	ST_AIRCRAFT_CARRIER,
	ST_BATTLESHIP,
	ST_CRUISER,
	ST_DESTROYER,
	ST_SUBMARINE
};

enum ShipOrientation {
	SO_HORIZONTAL= 0,
	SO_VERTICAL = 1
};

struct ShipPositionType {
	int row;
	int col;
	//Enough for 2D arr
	// For example BattleShip, occupies 4, with vertical orientation 
	// arr[1][0] , therefore, arr[1 - 5 ][0] will be occupied by the Battleship
};

struct Ship {
	ShipType shipType;
	ShipOrientation orientation;
	ShipPositionType position;
	int shipSize;
};

struct ShipPartType {
	// Contain the 
	// Hit status of the ships 
	ShipType shipType;
	bool isHit;
};

enum GuessType {
	GT_NONE = 0,
	GT_MISSED,
	GT_HIT,
};

enum PlayerType {
	PT_Human = 0,
	PT_AI
};


struct Player {
	PlayerType playerType;
	char name[PLAYER_NAME_SIZE];
	Ship ships[NUM_SHIPS];
	GuessType guessBoard[BOARD_SIZE][BOARD_SIZE]; // For enemy board
	ShipPartType shipBoard[BOARD_SIZE][BOARD_SIZE]; // For your ship board
};

void InitializePlayer(Player &player, const char * playerName);
void InitializeShip(Ship &ship, ShipType shipType, int shipSize );
int main() {
	Player player1;
	Player player2;

	InitializePlayer(player1, "Mamang");
	InitializePlayer(player2, "Yoman");
	
	return 0;
}

void InitializePlayer(Player &player, const char * playerName) {
	if(playerName != nullptr || strlen(playerName) > 0) {
			strcpy_s(player.name, playerName);
	}
	
	// Initialize Ships
	InitializeShip(player.ships[0], ST_AIRCRAFT_CARRIER, AIRCRAFT_CARRIER_SIZE );
	InitializeShip(player.ships[1], ST_BATTLESHIP, BATTLESHIP_SIZE);
	InitializeShip(player.ships[2], ST_CRUISER, CRUISER_SIZE);
	InitializeShip(player.ships[3], ST_DESTROYER, DESTROYER_SIZE);
	InitializeShip(player.ships[4], ST_SUBMARINE, SUBMARINE_SIZE);

}

void InitializeShip(Ship &ship, ShipType shipType, int shipSize) {
	ship.shipType = shipType;
	ship.shipSize = shipSize;
	ship.orientation = SO_HORIZONTAL;
	ship.position.row = 0;
	ship.position.col = 0;
}
