#include <iostream>
#include <stdlib.h>  //    system("clear");
#include <vector>
#include <string>


#include "GameControl.h"
#include "exit.h"

class Game {
    private: 
        Game_Control longvein; 
        Biome _biome;

    public: 
        Game(std::string username, std::string password) : longvein(username, password){
            info();
            system("clear");
            if (start_game()){
                welcome_back();
            }
            else {welcome();}
        }

        
        void run(){
           stats:
            show_stats();
           biome:
            try {
               choose_biome();
            }  catch (const BiomeErrorException& e) {
                std::cout << "Try choosing another biome" << std::endl;
                goto biome;
            }
            if (!fight_enemy()){
                goto stats;
            }
            
        }
        void info(){
                int skip;
                std::cout << "For the best experience put the terminal in fullscreen." << std::endl;

                // Prompt user to skip or continue with the introductory sequence
                std::cout << "Would you like to skip introductory sequence?"<<std::endl;

                std::cout << "Press 1 to continues or press 0 to skip: ";
                std::cin >> skip;
                std::cout << std::endl;

                // Check if the user chose to skip
                if (skip == 0) {
                    return; // Exit if user chooses to skip
                }

                // Display elements information with sleep for readability
                std::cout << "There are 5 elements: Fire, Earth, Metal, Water, and Wood" << std::endl;
                sleep(1);

                std::cout << "Fire is strong against Metal but weak against Earth." << std::endl;
                sleep(1);

                std::cout << "Earth is strong against Water but weak against Metal." << std::endl;
                sleep(1);

                std::cout << "Metal is strong against Wood but weak against Water." << std::endl;
                sleep(1);

                std::cout << "Water is strong against Fire but weak against Wood." << std::endl;
                sleep(1);

                std::cout << "Wood is strong against Earth but weak against Fire." << std::endl;
                sleep(1);

                key_press();
        }

        bool start_game(){
                system("clear");  
                std::cout << "Game has started!" << std::endl;
                std::cout << "Do you want to start a new game or load a saved game?" << std::endl;
            try_again: 
                std::cout << "1. New Game ----- 2. Load Game" << std::endl;
                int game; 
                std::cin >> game;
                if(game>2 || game <1){
                    std::cout << "Try again..."<<std::endl;
                    goto try_again; 
                    }
                longvein.initialize_hero(game);
//                key_press();
                system("clear");  
                return game-1;       
        }

        void key_press() {
            std::cout << "\nPress Enter to continue..." << std::endl;

            // Clear any existing contents from the input buffer
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            // Wait for the user to press Enter
            std::cin.get();
        }

        void welcome(){
            std::cout << "Welcome " << longvein.hero_name() << " to the land of ISSLE!" << std::endl;
            std::cout << "You are a brave warrior who has been tasked with defeating the dragon LongVein!" << std::endl;
            std::cout << "But be careful!" << std::endl;
            std::cout << "Foul creatures are hidding!" << std::endl;
            std::cout << "You must defeat them if you want a chance against the GREAT LongVein!" << std::endl;

            key_press();
            system("clear");
        }
        void welcome_back(){
            std::cout << "Welcome back " << longvein.hero_name() << "!" << std::endl;
            std::cout << "Lets continue your journey!" << std::endl;
            key_press();
            system("clear");
        }

        void show_stats(){
            std::cout << "Do you want to check your stats?" << std::endl;
            std::cout << "1. Yes ----- 2. No  ---- Q. Save and Exit : ";
            char stats;
            std::cin >> stats;
            if (stats=='1'){
            longvein.stats();
            }
            else if (stats == 'q' || stats == 'Q'){
                throw ExitGameException();
            }
            std::cout << std::endl;
            key_press();
        }

        void choose_biome(){
            choose_biome:
            std::cout << "1. Choose biome ---- Q. Save and Exit : " << std::endl;
            char stats;
            std::cin >> stats;
            if (stats=='1'){
                _biome = longvein.choose_biome();
                if (_biome.get_name() == "City"){
                    visit_city();
                    std::cout << std::endl;
                    show_stats();
                    std::cout << std::endl;
                    goto choose_biome;
                }
                longvein.set_enemy_for_biome(_biome);
                key_press();
            }
            else {
                throw ExitGameException();
            }
        }

        int fight_enemy(){
           choice:
            std::cout << "You can now choose if you want to fight or run away!." << std::endl;
            sleep(1);
            std::cout << "1. Fight ---- 2. Choose another biome ----- Q. Save and Exit : ";
            char choice;

                std::cin >> choice;
                if (choice == '1') {
                    try {
                        Enemy enemy = longvein.choose_enemy();
                        system("clear");
                        longvein.combat(enemy, _biome);
                        goto choice;
                        std::cout << std::endl;
                    }  catch (const BiomeDoneException& e) {
                        std::cout << "You can try another biome!" << std::endl;
                        return 0;
                    }


                }

                if (choice == '2' || choice == '2') {
                        return 0;
                }

                if (choice == 'q' || choice == 'Q') {

                    throw ExitGameException();  // Throw to signal game exit
                }
                else {
                    std::cout << "You must have made a mistake, try again." << std::endl;
                    goto choice;
                }
            return 1;
        }


        void visit_city(){
            longvein.visit_city();
        }

}; 
