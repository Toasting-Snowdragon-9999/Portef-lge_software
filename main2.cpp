#include <iostream>

#include "hero.h"
#include "enemy.h"
#include "GameControl.h"
#include "setup.h"
int main(int, char**){
        set_up_db();
        Game_Control longvein; 
        std::cout << "Game has started!" << std::endl;
        std::cout << "Do you want to start a new game or load a saved game?" << std::endl;
        std::cout << "1. New Game ----- 2. Load Game" << std::endl;    

                int game; 
                std::cin >> game;
                Hero hero; // Declare the Hero object outside the switch statement
                std::string name;
        again: 
                switch(game){
                        case 1:
                                std::cout << "Enter your name: ";
                                std::cin >> name;
                                hero.New_Hero(name); // Initialize the Hero object inside the case
                                break;
                        case 2:
        
                                std::cout << "Here is a list of characters: " << std::endl;
                                longvein.print_hero_names();
                                std::cout << "" << std::endl;
                                std::cout << "Enter the name of the character you want to load: ";
                                std::cin >> name;
                                hero.Load_Hero(name); // Initialize the Hero object inside the case
                                break;
                        default:
                                std::cout << "Invalid input!" << std::endl;
                                goto again; 
                                break;
                }
        hero.heal_max();
        std::cout << "xp = " <<hero.Hero::get_xp() << std::endl; 
        std::cout << "hp = " << hero.Hero::get_hp() << hero.get_max_hp() << std::endl; 
        longvein.fight(hero); 
        std::cout << "xp = " <<hero.Hero::get_xp() << std::endl; 
        std::cout << "hp = " << hero.Hero::get_hp() << hero.get_max_hp() << std::endl; 
        
        return 0;  
}