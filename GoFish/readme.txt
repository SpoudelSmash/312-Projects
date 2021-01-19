//readme.txt
Project GoFish:
A simple card game played with 2+ players

Included files: goFish_driver.cpp, Card.h/cpp, Deck.h/cpp, Player.h.cpp makefile

Compile & Run(can be done in a Linux environment):
	1. Unzip the files into the same directory.
	2. Execute "make" command. This will create a executable named "gofish".
	3. Run the executable with "./gofish". You are now running the program.

How to Play:
	-- Setup --
	* Players draw to see who goes first.
	* Deck is shuffled with 52 cards.
	* Deal cards to players (7 each for 2players, 5 each for 2+player).

	-- Gameplay --
	* If a player has 2 cards of the same rank in their hand, they can add that pair of cards to their book immediately.
	* On their turn, players choose a rank to ask for.
		- If the next player has that rank, they hand that card over.
		- If not, the next player tells the current to draw a card ("Go Fish").

	* Players take turns in order until the entire deck is used and each player's hand is empty.
	* The player with the most books at the end of the game wins.

--NOTE--
* Game currently only works for 2 players
* The results of each game are stored in "gofish_results.txt" located in the same directory as the main files.

--
11/13/2020
Samip Poudel (sp47257)
UT Class of 23'
