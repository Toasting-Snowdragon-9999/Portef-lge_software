#ifndef game_control_H
#define GAME_CONTROL_H

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <unistd.h> 
#include <stdexcept>
#include <stdlib.h>  //    system("CLS")
#include <algorithm>  // For max_element and transform

#include "database_handler.h"
#include "hero.h"
#include "enemy.h"
#include "area.h"
#include "exit.h"

class Game_Control {
    private: 
        Hero _hero; 
        DB_Handler db;
        std::vector <Biome> _biome;  
        std::vector <Enemy> _enemies; 
        std::vector <std::string> _current_enemies;
        std::vector <int> _current_enemies_xp;
    public: 
        Game_Control(){
            db.set_up_db();
            set_up_biome();
            set_up_enemy();

        }

        ~Game_Control(){
            db.update_hero(_hero); 
        }

        void test(){


        }
//      
        void set_up_biome(){
            //INSERT IGNORE INTO biome (name, type, enemy_count, level, gold)
            Biome forest;
            forest.biome_init("Forest", "normal", 5, 1, 1000);
            db.create_biome("Forest", "normal", 5, 1, 1000);
            _biome.push_back(forest);

            Biome mountain;
            mountain.biome_init("Mountain", "normal", 5, 2, 2000);
            db.create_biome("Mountain", "normal", 5, 2, 2000);
            _biome.push_back(mountain);

            Biome cave;
            cave.biome_init("Cave", "dark", 5, 5, 5000);
            db.create_biome("Cave", "dark", 5, 5, 5000);
            _biome.push_back(cave);

            Biome dragonLair;
            dragonLair.biome_init("DragonLair", "dragon", 7, 6, 6000);
            db.create_biome("DragonLair", "dragon", 7, 6, 6000);
            _biome.push_back(dragonLair);

            // Biome city("Suzail", "City", 5, 1, 1000);
            // forest.add_to_enemy(city_list);

            // Biome castle ("Castle", "normal", 5, 3, 3000);
            // forest.add_to_enemy(castle_list);


            // Biome desert("Desert", "normal", 6, 4, 4000);
            // forest.add_to_enemy(desert_list);

            // Biome abyss("Abyss", "demon", 5, 10, 10000);
            // forest.add_to_enemy(abyss_list);
        }

        void set_up_enemy(){
            Enemy boar(  "boar", 4, 1, 100, db.get_biome_id(_biome[0]));
            db.create_enemy("boar", boar.get_health(), boar.get_strength(), boar.get_xp_worth(), db.get_biome_id(_biome[0]));
            _enemies.push_back(boar);

            Enemy wolf(  "wolf", 2, 2, 100, db.get_biome_id(_biome[0]));
            db.create_enemy(  "wolf", 2, 2, 100, db.get_biome_id(_biome[0]));
            _enemies.push_back(wolf);

            Enemy bear(  "bear", 5, 2, 200, db.get_biome_id(_biome[0]));
            db.create_enemy(  "bear", 5, 2, 200, db.get_biome_id(_biome[1]));
            _enemies.push_back(bear);

            Enemy goblin(  "goblin", 6, 3, 400, db.get_biome_id(_biome[1]));
            db.create_enemy(  "goblin", 6, 3, 400, db.get_biome_id(_biome[1]));
            _enemies.push_back(goblin);

            Enemy orc(  "orc", 8, 4, 600, db.get_biome_id(_biome[1]));
            db.create_enemy(  "orc", 8, 4, 600, db.get_biome_id(_biome[1]));
            _enemies.push_back(orc);

            Enemy MightyGoblin(  "Mighty Goblin", 10, 5, 700, db.get_biome_id(_biome[1]));
            db.create_enemy(  "Mighty Goblin", 10, 5, 700, db.get_biome_id(_biome[1]));
            _enemies.push_back(MightyGoblin);

            Enemy troll(  "troll", 10, 5, 900, db.get_biome_id(_biome[2]));
            db.create_enemy(  "troll", 10, 5, 900, db.get_biome_id(_biome[2]));
            _enemies.push_back(troll);

            Enemy giant(  "giant", 12, 6, 1000, db.get_biome_id(_biome[2]));
            db.create_enemy(  "giant", 12, 6, 1000, db.get_biome_id(_biome[2]));
            _enemies.push_back(giant);

            Enemy basilisk (  "basilisk", 12, 6, 1200, db.get_biome_id(_biome[2]));
            db.create_enemy(  "basilisk", 12, 6, 1200, db.get_biome_id(_biome[2]));
            _enemies.push_back(basilisk);

            Enemy GoblingKing("Goblin King", 15, 7, 2000, db.get_biome_id(_biome[1])); //Gurp the goblin king
            db.create_enemy("Goblin King", 15, 7, 2000, db.get_biome_id(_biome[1]));
            _enemies.push_back(GoblingKing);

            Enemy kobold(  "Kobold", 8, 3, 600, db.get_biome_id(_biome[3]));
            db.create_enemy(  "Kobold", 8, 3, 600, db.get_biome_id(_biome[3]));
            _enemies.push_back(kobold);

            Enemy wyrmling (  "Wyrmling", 10, 5, 900, db.get_biome_id(_biome[3]));
            db.create_enemy(  "Wyrmling", 10, 5, 900, db.get_biome_id(_biome[3]));
            _enemies.push_back(wyrmling);

            Enemy small_dragon (  "SmallDragon", 14, 6, 1800, db.get_biome_id(_biome[3]));
            db.create_enemy(  "SmallDragon", 14, 6, 1800, db.get_biome_id(_biome[3]));
            _enemies.push_back(small_dragon);

            Enemy dragon("Dragon", 28, 7, 3000, db.get_biome_id(_biome[3]));
            db.create_enemy("Dragon", 28, 7, 3000, db.get_biome_id(_biome[3]));
            _enemies.push_back(dragon);

            //ENEMY LIST!!! --------------------------------------------------------------------------------

            std::vector <Enemy> forest_list {boar, boar, wolf, wolf, bear};
            _biome[0].add_to_enemy(forest_list);

            std::vector <Enemy> mountain_list{orc, orc, orc, troll, troll};
            _biome[1].add_to_enemy(mountain_list);

            std::vector <Enemy> cave_list{goblin, goblin, goblin, MightyGoblin, MightyGoblin, GoblingKing};
            _biome[2].add_to_enemy(cave_list);

            std::vector <Enemy> dragonLair_list{kobold, kobold, kobold, wyrmling, wyrmling, small_dragon, dragon};
            _biome[3].add_to_enemy(dragonLair_list);

            // std::vector <Enemy> desert_list{NULL};      //not being used jut here for future stuff
            // std::vector <Enemy> city_list {NULL};       //not being used, just here for future stuff
            // std::vector <Enemy> castle_list {NULL};      //not being used jut here for future stuff
            //std::vector <Enemy> abyss_list{NULL};      //not being used jut here for future stuff

        }


// MAKE OR LOAD HERO -----------------------------------------------------------------
        void initialize_hero(int game){
            Hero hero;
             // Declare the Hero object outside the switch statement
            std::string name;
            std::string name2;
                switch(game){
                        case 1:
                                std::cout << "Enter your name: ";
                                std::cin >> name;
                                hero.New_Hero(name); // Initialize the Hero object inside the case
                                db.create_hero(name);
                                break;
                        case 2:
                               
                                std::cout << "Here is a list of characters: " << std::endl;
                                print_hero_names();
                                std::cout << "" << std::endl;
                            tryAgain:
                                std::cout << "Enter the name of the character you want to load: ";
                                try{
                                std::cin >> name2;
                                if (db.check_for_hero(name2)==false){
                                    throw std::invalid_argument("No hero by that name try again!"); 
                                    }
                                
                                hero.Load_Hero(db.find_hero(name2)); // Initialize the Hero object inside the case
                                }catch (const std::invalid_argument& e){
                                    std::cout << "Caught exception: " << e.what() << std::endl; 
                                    std::cout << std::endl; 
                                    goto tryAgain;
                                }
                                break;
                        default:
                                std::cout << "Invalid input!" << std::endl;
                                break;
                }
                this-> _hero = hero;
        }

//GET STUFF FROM HERO AND ENEMY ----------------------------------------------------
        std::string hero_name(){
            return _hero.get_Sname(); 
        }

        void stats(){
                _hero.get_stats(); 
        }

        Enemy get_enemy(std::string name){
            for(Enemy e : _enemies){
                if(name == e.get_name()){
                    return e;
                }
            }
            // throw std::runtime_error("no enemy found!");
        
        }

        void print_hero_names(){
            std::vector <std::string> length = db.all_heroes()[0];
            std::vector <std::vector <std::string>> AH = db.all_heroes(); 
            if (AH.empty() || AH[0].empty()) {
                    std::cerr << "Error: No heroes available." << std::endl;

                }

                // Determine the maximum length of any string in the output
                int max_length = 0;
                for (int i = 0; i < length.size(); i++) {
                    int current_length = static_cast<int>(AH[0][i].length() + AH[1][i].length());
                    max_length = std::max(max_length, current_length);
                }

                // Adding space for " LEVEL: " and the final "|" and spaces
                int fixed_width = std::string(" LEVEL:  |").length();

                std::cout << std::string(max_length*3, '-') << std::endl;
                //std::cout << "------------------------------------" << std::endl;
                for (int i = 0; i < length.size(); i++) {
                    std::string name_section = AH[0][i];
                    std::string level_section = " LEVEL: " + AH[1][i];

                    // Total current length of the output for this line
                    int current_line_length = static_cast<int>(name_section.length() + level_section.length());

                    // Calculate how much padding is needed
                    int padding_needed = max_length - current_line_length + fixed_width;

                    // Print the line with right alignment
                    std::cout << "| " << name_section << level_section << std::string(padding_needed, ' ') << "|" << std::endl;
                }
                std::cout << std::string(max_length*3, '-') << std::endl;

        }

//COMBATE ----------------------------------------------------------------
        int combat(Enemy enemy, Biome biome){
            std::cin.get();
            enemy.boss_fight();
            while(_hero.get_hp() > 0 && enemy.get_health() > 0){
                std::cout << "" << std::endl;
                std::cout << "Press Enter to attack!" << std::endl;
                std::cin.get();
                _hero.dmg_taken(enemy.get_strength());
                enemy.dmg_taken(_hero.get_strength());
                std::cout << "--------------------------------------------------------------------" << std::endl;
                sleep(2);
                std::cout << "You have dealt " << _hero.get_strength() << " damage to the "<< enemy.get_name() << "!" << std::endl;
                sleep(1);
                std::cout << "Your health: " << _hero.get_hp() << "          "<< std::right << "Enemy health: "  << enemy.Enemy::get_health() << std::endl;
                sleep(1);
                

                if(_hero.get_hp() <= 0){
                    sleep(1);
                    std::cout << "You have died!" << std::endl;
                    sleep(1);
                    std::cout << "This is unfortunatly game over for you!" << std::endl;
                    sleep(1);
                    std::cout << "Try Again and create a new character!" << std::endl;
                    Game_Over(); 
                    return 0; 
                }
                else if(enemy.get_health() <= 0){
                    std::cout << "" << std::endl;
                    sleep(1);
                    std::cout << "You have defeated the enemy!" << std::endl;
                    sleep(1);
                    _hero.heal_max();
                    _hero.set_xp(enemy.get_xp_worth());
                    std::cout << "You have gained " << enemy.get_xp_worth() << " experience points!" << std::endl;
                    sleep(1);
                    std::cout << "You have " << _hero.get_xp() << " experience points!" << std::endl;
                    std::cout << std::endl;

                    //remove enemy from list.
                    std::string elementToRemove = enemy.get_name();
                    auto it = std::find(_current_enemies.begin(), _current_enemies.end(),
                                            elementToRemove);

                        // If element is found found, erase it
                        if (it != _current_enemies.end()) {
                            _current_enemies.erase(it);
                        }
                    if (_current_enemies.empty()){
                        biome_defeated(biome);
                        return 2;
                    }

                    break;
                }
            }
            return 1; 
        }

        Enemy choose_enemy (){
            std::cout << std::endl;
            for (int i = 0; i < this ->_current_enemies.size(); i++){
                std::cout << "| " << i << ": "<< this -> _current_enemies[i] << " is worth : " << this -> _current_enemies_xp[i] << " xp |" << std::endl;;
            }
            std::cout << std::endl;
            std::cout << "Choose an enemy på index to fight!" << std::endl;
            int enemy_choice;
            std::cin >> enemy_choice;
            for (int i = 0; i < _enemies.size(); i++){
                if (_enemies[i].get_name() == _current_enemies[enemy_choice]){
                    return _enemies[i];
                }
            }
            return _enemies[1];
        }

// BIOME STUFF ---------------------------------------------------------------------

    Biome choose_biome(){
        std::cout << "choose a biome you want to explore!" << std::endl; 
        std::vector <std::string> biome_name = db.get_biome_list()[0];
        std::vector <std::string> difficulty = db.get_biome_list()[1];

        //THIS ALIGNED THE TERMINAL SO THAT IT LOOKS GOOD, IT ALIGNES BY CALCULATING THE DIFFERENCE IN STRING SIZE AND THEN ADDING PADDING
        if (biome_name.size() != difficulty.size()) {
            std::cerr << "Error: Biome names and difficulty levels do not match in size." << std::endl;

        }

        // Calculate maximum biome name length
        int max_biome_length = 0;
        for (const std::string& name : biome_name) {
            max_biome_length = std::max(max_biome_length, static_cast<int>(name.length()));
        }

        // Determine how much space is needed before "Difficulty"
        int prefix_length = 5;

        // Print each biome with adjusted padding for alignment
        for (size_t i = 0; i < biome_name.size(); ++i) {
            std::string biome_section = biome_name[i] + std::string(max_biome_length - biome_name[i].length(), ' ');
            std::string difficulty_section = ". " + std::string(prefix_length, ' ') + "Difficulty: " + difficulty[i];
            std::string line = "| " + biome_section + difficulty_section;

            // Calculate total line length dynamically if needed
            //int max_line_length = max_biome_length + 30;  // Adjust the total line length to fit your specific output needs
            std::cout << line + " |" << std::endl;
        }

        std::string biome; 
        std::cout << std::endl;
        std::cout << "Type the name of the biome you want to visit!: "<<std::endl;
        std::cin >> biome;
        biome = case_sensitive(biome);

        std::cout << std::endl; 
        for (int i = 0; i <= _biome.size(); i++){
            if (_biome[i].get_name() == biome){
                std::cout << "Great! You chose " << _biome[i].get_name() << std::endl;
                sleep(1);
                std::cout << "Traveling to destination ..." << std::endl;
                sleep(3);
                std::cout << "You have arrived!" << std::endl;
                sleep(2);
                _biome[i].biome_description();
                return _biome[i];
            }
            else {
                throw BiomeErrorException();
            }
        }
       return _biome[1];
    }

    std::string case_sensitive (std::string check_string){
        if (check_string == "forest"){return "Forest";}
        if (check_string == "cave"){return "Cave";}
        if (check_string == "mountain"){return "Mountain";}
        if (check_string == "dragonlair" || check_string == "Dragonlair" || check_string == "dragonLair"){return "DragonLair";}
        else return check_string;

    }

    void set_enemy_for_biome(Biome biome){
        int id = db.get_biome_id(biome)-1;  //biome id is from 1-4 but the get_enemy_in_biome uses 0 indexing.
        this -> _current_enemies_xp = db.get_enemy_xp_in_biome()[id];
        this -> _current_enemies = db.get_enemy_in_biome()[id];

    }


    void biome_defeated(Biome biome){
        std::cout << std::endl;
        std::cout << "Congrats you have defeated every fool who dared to stand in your way!!" << std::endl;
        sleep(1);
        std::cout << "For that you are rewarded with " << biome.get_gold() << " gold" << std::endl;
        sleep(2);
        std::cout << "Now dont spent it all at once.. " << std::endl;
        _hero.update_gold(biome.get_gold());
        throw BiomeDoneException();
    }


//GAME OVER --------------------------------------------------------------
        void Game_Over(){
            db.game_over(_hero.get_Qname());
            throw ExitGameException();  // Throw to signal game exit
        }
}; 

#endif
// Path: enemy.h
