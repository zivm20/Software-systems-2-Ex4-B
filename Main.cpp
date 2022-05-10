

#include "Player.hpp"
#include "Duke.hpp"
#include "Assassin.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"
#include "Game.hpp"
#include <time.h>

#include <exception>

using namespace coup;

#include <iostream>
#include <stdexcept>
#include <vector>
#include <map>
using namespace std;

int main() {
	srand(time(NULL));
	Game game{};
	int player_num;
	cout<<"How many players will be playing? (2-6)"<<endl;
	cin>>player_num;
	while(player_num<2 || player_num > 6){
		cout<<"Invalid amount of players please input a number between 2 and 6"<<endl;
		cin>>player_num;
	}

	map<string,Player*> players;
	for(int i=0; i<player_num; i++){
		string playerName;
		string role;
		cout<<"Name of player "<<i+1<<": ";
		cin>>playerName;
		int playerClass = rand()%4;
		switch (playerClass){
			case 0:
				players.insert(pair<string,Player*>(playerName,new Ambassador(game,playerName)));
				role = "Ambassador";
				break;
			case 1:
				players.insert(pair<string,Player*>(playerName,new Assassin(game,playerName)));
				role = "Assassin";
				break;
			case 2:
				players.insert(pair<string,Player*>(playerName,new Captain(game,playerName)));
				role = "Captain";
				break;
			case 3:
				players.insert(pair<string,Player*>(playerName,new Contessa(game,playerName)));
				role = "Contessa";
				break;
			default:
				players.insert(pair<string,Player*>(playerName,new Duke(game,playerName)));
				role = "Duke";
				break;
		}
		cout<<"Added "<<playerName<<" as "<<role<<endl;
	}
	cout<<endl<<endl;
	cout<<"----------Game start!----------"<<endl;
	cout<<endl;
	bool game_active = true;
	string winner;

	while(game_active){
		string currTurn = game.turn();
		cout<<endl;
		cout<<"-----"<<currTurn<<"'s turn-----"<<endl;
		cout<<endl;
		while(game_active && currTurn == game.turn()){
			string command;
			getline(cin,command);

			if(command == "income"){
				try{
					players.at(currTurn)->income();
				}
				catch (const exception &e){
					cerr << e.what() << endl<<endl;
				}
			}
			else if(command == "foreign aid"){
				try{
					players.at(currTurn)->foreign_aid();
				}
				catch (const exception &e){
					cerr << e.what() << endl<<endl;
				}
			}
			else if(command == "coins"){
				cout<<currTurn<<" has "<<players.at(currTurn)->coins()<<" coins"<<endl<<endl;
			}
			else if(command == "role"){
				
				cout<<players.at(currTurn)->role()<<endl<<endl;
			}
			else if(command == "players"){
				vector<string> activePlayers = game.players();
				for (string name : activePlayers){
					cout<<players.at(name)->role()<<" "<<name<<endl;
				}
			}
			else if(command == "tax"){
				try{
					players.at(currTurn)->tax();
				}
				catch (const exception &e){
					cerr<<e.what()<<endl<<endl;
				}
			}
			else{
				size_t pos = command.find(" ");
				string temp = command.substr(0,pos);
				command.erase(0,pos+1);
				string args = command;
				command = temp;

				if(command == "block"){
					try{
						players.at(currTurn)->block(*players.at(args));
					}
					catch (const exception &e){
						cerr<<e.what()<<endl<<endl;
					}
				}
				else if(command == "coup"){
					try{
						players.at(currTurn)->coup(*players.at(args));
						try{
							winner = game.winner();
							game_active = false;

						}catch(const exception &e2){
							
						}
					}
					catch (const exception &e){
						cerr<<e.what()<<endl<<endl;
					}
				}
				else if(command == "steal"){
					try{
						players.at(currTurn)->steal(*players.at(args));
					}
					catch (const exception &e){
						cerr<<e.what()<<endl<<endl;
					}
				}
				else if(command == "transfer"){
					size_t pos = args.find(" ");
					string player1 = args.substr(0,pos);
					args.erase(0,pos+1);
					string player2 = args;
					try{
						players.at(currTurn)->transfer(*players.at(player1),*players.at(player2));
					}
					catch(const exception &e){
						cerr<<e.what()<<endl<<endl;
					}
				}
			}
		}
		
	}

	cout<<endl<<endl<<"The Winner is "<<winner<<"!"<<endl;
	
}

