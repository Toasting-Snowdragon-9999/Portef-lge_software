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
                
                longvein.initialize_hero(game); 
                
        std::cout << "--------------------------------------------------------------------" << std::endl;

        if (game == 1){
                std::cout << "Welcome " << longvein.hero_name() << " to the land of ISSLE!" << std::endl;
                std::cout << "You are a brave warrior who has been tasked with defeating the dragon LongVein!" << std::endl;

        }
        else if (game==2){ 
                std::cout << "Welcome back " << longvein.hero_name() << "!" << std::endl;
                std::cout << "Lets continue your journey!" << std::endl;
                std::cout << "" << std::endl; 
        }
while (1){
        longvein.stats();
                std::cout << "" << std::endl; 
                std::cout << "--------------------------------------------------------------------" << std::endl;

                std::cout << "You can now choose if you want to fight or run away!." << std::endl;
                std::cout << "1. Fight ----- 2. Save and Exit ";
                int choice;
                std::cin >> choice;
                switch(choice){
                        case 1:
                                if (longvein.fight()==0){goto exit;}
                                std::cout << "" << std::endl;
                                break;
                        case 2:
                                //hero.save_hero();      

                                goto exit; 
                                break;
                        default:
                                std::cout << "Invalid input!" << std::endl;
                                goto exit;  
                                break;
                }
      
          
        }

        exit:  
        return 0;
}
