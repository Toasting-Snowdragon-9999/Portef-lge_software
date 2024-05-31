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
#include "shop.h"

class Game_Control {
    private: 
        Hero _hero; 
        DB_Handler _db;
        Shop _shop;
        std::vector <Biome> _biome;  
        std::vector <Enemy> _enemies; 
        std::vector <std::string> _current_enemies;
        std::vector <int> _current_enemies_xp;

    public: 
        Game_Control(std::string username, std::string password) : _db(username, password), _shop(username, password){
            set_up_element();
            set_up_biome();
            set_up_enemy();
            set_up_element();
            _shop.set_up_items();
        }

        ~Game_Control(){
            _db.update_hero(_hero);
        }

        void test(){


        }
        void set_up_element(){
            _db.create_element("Fire",2,3);
            _db.create_element("Earth",3,4);
            _db.create_element("Metal",4,5);
            _db.create_element("Water",5,1);
            _db.create_element("Wood",1,2);

        }


//      
        void set_up_biome(){
            //INSERT IGNORE INTO biome (name, type, enemy_count, level, gold)
            Biome forest;
            forest.biome_init("Forest", "normal", 5, 1, 1000);
            _db.create_biome("Forest", "normal", 5, 1, 1000);
            _biome.push_back(forest);

            Biome mountain;
            mountain.biome_init("Mountain", "normal", 5, 3, 2000);
            _db.create_biome("Mountain", "normal", 5, 3, 2000);
            _biome.push_back(mountain);

            Biome cave;
            cave.biome_init("Cave", "dark", 5, 5, 5000);
            _db.create_biome("Cave", "dark", 5, 5, 5000);
            _biome.push_back(cave);

            Biome dragonLair;
            dragonLair.biome_init("DragonLair", "dragon", 7, 6, 6000);
            _db.create_biome("DragonLair", "dragon", 7, 6, 6000);
            _biome.push_back(dragonLair);

             Biome city;
             city.biome_init("City", "Suzail", 0, 1, 0);
             _db.create_biome("City", "Suzail", 0, 1, 0);
             _biome.push_back(city);
//             forest.add_to_enemy(city_list);

            // Biome castle ("Castle", "normal", 5, 3, 3000);
            // forest.add_to_enemy(castle_list);


            // Biome desert("Desert", "normal", 6, 4, 4000);
            // forest.add_to_enemy(desert_list);

            // Biome abyss("Abyss", "demon", 5, 10, 10000);
            // forest.add_to_enemy(abyss_list);
        }

        void set_up_enemy(){
            Enemy boar(  "Boar", 4, 1, 100, _db.get_biome_id(_biome[0]), 5);
            _db.create_enemy("Boar", boar.get_health(), boar.get_strength(), boar.get_xp_worth(), _db.get_biome_id(_biome[0]), 5);
            _enemies.push_back(boar);

            Enemy wolf(  "Wolf", 2, 2, 100, _db.get_biome_id(_biome[0]), 1);
            _db.create_enemy(  "Wolf", 2, 2, 100, _db.get_biome_id(_biome[0]), 1);
            _enemies.push_back(wolf);

            Enemy bear( "Bear", 5, 2, 200, _db.get_biome_id(_biome[0]), 5);
            _db.create_enemy(  "Bear", 5, 2, 200, _db.get_biome_id(_biome[0]), 5);
            _enemies.push_back(bear);

            Enemy goblin(  "Goblin", 6, 3, 400, _db.get_biome_id(_biome[1]), 3);
            _db.create_enemy(  "Goblin", 6, 3, 400, _db.get_biome_id(_biome[1]), 3);
            _enemies.push_back(goblin);

            Enemy orc("Orc", 8, 4, 600, _db.get_biome_id(_biome[1]), 3);
            _db.create_enemy(  "Orc", 8, 4, 600, _db.get_biome_id(_biome[1]), 3);
            _enemies.push_back(orc);

            Enemy MightyGoblin("Mighty Goblin", 10, 5, 700, _db.get_biome_id(_biome[1]), 3);
            _db.create_enemy("Mighty Goblin", 10, 5, 700, _db.get_biome_id(_biome[1]), 3);
            _enemies.push_back(MightyGoblin);

            Enemy troll("Troll", 10, 5, 900, _db.get_biome_id(_biome[2]), 2);
            _db.create_enemy("Troll", 10, 5, 900, _db.get_biome_id(_biome[2]), 2);
            _enemies.push_back(troll);

            Enemy giant("Giant", 12, 6, 1000, _db.get_biome_id(_biome[2]), 2);
            _db.create_enemy("Giant", 12, 6, 1000, _db.get_biome_id(_biome[2]), 2);
            _enemies.push_back(giant);

            Enemy basilisk ("Basilisk", 12, 6, 1200, _db.get_biome_id(_biome[2]), 4);
            _db.create_enemy("Basilisk", 12, 6, 1200, _db.get_biome_id(_biome[2]), 4);
            _enemies.push_back(basilisk);

            Enemy GoblingKing("Goblin King", 15, 7, 2000, _db.get_biome_id(_biome[1]), 3); //Gurp the goblin king
            _db.create_enemy("Goblin King", 15, 7, 2000, _db.get_biome_id(_biome[1]), 3);
            _enemies.push_back(GoblingKing);

            Enemy kobold("Kobold", 8, 3, 600, _db.get_biome_id(_biome[3]), 1);
            _db.create_enemy("Kobold", 8, 3, 600, _db.get_biome_id(_biome[3]), 1);
            _enemies.push_back(kobold);

            Enemy wyrmling ("Wyrmling", 10, 5, 900, _db.get_biome_id(_biome[3]), 4);
            _db.create_enemy("Wyrmling", 10, 5, 900, _db.get_biome_id(_biome[3]), 4);
            _enemies.push_back(wyrmling);

            Enemy small_dragon ("SmallDragon", 14, 6, 1800, _db.get_biome_id(_biome[3]), 5);
            _db.create_enemy("SmallDragon", 14, 6, 1800, _db.get_biome_id(_biome[3]), 5);
            _enemies.push_back(small_dragon);

            Enemy dragon("Dragon", 28, 7, 3000, _db.get_biome_id(_biome[3]), 1);
            _db.create_enemy("Dragon", 28, 7, 3000, _db.get_biome_id(_biome[3]), 1);
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
//             std::vector <Enemy> city_list {NULL};       //not being used, just here for future stuff
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
                                _db.create_hero(name);

                                std::cout << "Here is starting gift for your adventure!" << std::endl;
                                std::cout << "          +1 Health Potion" << std::endl;
                                sleep(3);
                                _db.add_item_inventory(name, "Health Potion");
                                break;
                        case 2:
                               
                                std::cout << "Here is a list of characters: " << std::endl;
                                print_hero_names();
                                std::cout << "" << std::endl;
                            tryAgain:
                                std::cout << "Enter the name of the character you want to load: ";
                                try{
                                std::cin >> name2;
                                if (_db.check_for_hero(name2)==false){
                                    throw std::invalid_argument("No hero by that name try again!"); 
                                    }
                                
                                hero.Load_Hero(_db.find_hero(name2)); // Initialize the Hero object inside the case
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

        void set_up_items_hero(){

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
            std::vector <std::string> length = _db.all_heroes()[0];
            std::vector <std::vector <std::string>> AH = _db.all_heroes();
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
            int stats;
            std::cout << "You have chosen " << enemy.get_name() << " - their element type is: " << enemy.get_element() << std::endl;
            std::cin.get();
            int enemy_max_hp = enemy.get_health();
            int weapon;
            print_inventory();
            _hero.get_weapon_stats();

//            std::cin.get();
            enemy.boss_fight();
            while(_hero.get_hp() > 0 && enemy.get_health() > 0){
                std::cout << "Would you like to check your stats?"<< std::endl;
                std::cout << "Press 1 to show stats -- Press 0 to continues" << std::endl;
                std::cin >>stats;
                if (stats == 1){
                    _hero.get_stats();
                }
                std::cout << "Press 1 to attack with " << _hero.get_item() <<" - Press 0 for changing attack!"<< std::endl;
                std::cin >> weapon;
                if (weapon == 0){
                    print_inventory();
                    std::cout << std::endl;
                    _hero.get_weapon_stats();
                }
//                std::cin.get();
                int element_rel = element_relation(enemy.get_element());
                std::cout << "-------------------------------------------------------------------------" << std::endl;

                switch(element_rel) {
                    case 0:  // Disadvantage
                        std::cout << "Oh no, you have a disadvantage in this battle!" << std::endl;
                        _hero.dmg_taken(enemy.get_strength()+_hero.weapon_self_dmg());
                        if (_hero.current_mana() >= _hero.weapon_mana()){
                            enemy.dmg_taken(_hero.get_strength()/2);
                            _hero.mana_use(_hero.weapon_mana());
                        }
                        break;
                    case 1:  // Advantage
                        std::cout << "Fortune favors you, hero! You have an advantage over your enemy!" << std::endl;
                        _hero.dmg_taken(enemy.get_strength()+_hero.weapon_self_dmg());
                        if (_hero.current_mana() >= _hero.weapon_mana()){
                            enemy.dmg_taken(_hero.get_strength()*2);
                            _hero.mana_use(_hero.weapon_mana());
                        }
                        break;
                    case 2:  // Neutral
                        std::cout << "The scales are balanced. Neither you nor your enemy has the upper hand!" << std::endl;
                        _hero.dmg_taken(enemy.get_strength()+_hero.weapon_self_dmg());
                        if (_hero.current_mana() >= _hero.weapon_mana()){
                            enemy.dmg_taken(_hero.get_strength());
                            _hero.mana_use(_hero.weapon_mana());
                        }
                        break;
                    case 3:  // Enemy Advantage
                        std::cout << "Beware! The enemy has the upper hand in this encounter!" << std::endl;
                        _hero.dmg_taken((enemy.get_strength()*2)+_hero.weapon_self_dmg());
                        if (_hero.current_mana() >= _hero.weapon_mana()){
                            enemy.dmg_taken(_hero.get_strength());
                            _hero.mana_use(_hero.weapon_mana());
                        }
                        break;
                    case 4:  // Enemy Disadvantage
                        std::cout << "The enemy falters! They are at a disadvantage!" << std::endl;
                        _hero.dmg_taken((enemy.get_strength()/2)+_hero.weapon_self_dmg());
                        if (_hero.current_mana() >= _hero.weapon_mana()){
                            enemy.dmg_taken(_hero.get_strength());
                            _hero.mana_use(_hero.weapon_mana());
                        }
                        break;
                }

                std::cout << "-------------------------------------------------------------------------" << std::endl;
                sleep(2);
                if (enemy.get_health() < 0){enemy.set_hp(0);}
                std::cout << "Your health: " << _hero.get_hp() << "          " << std::right << "Enemy health: " << enemy.get_health() << std::endl;
                sleep(1);
                int potion;
                std::cout << std::endl;
                std::cout << "-------------------------------------------------------------------------" << std::endl;
                std::cout << "Do you wish to use a potion?" << std::endl;
                std::cout << "Press 1 for Yes  --  Press 2 for no" << std::endl;
                std::cin >> potion;
                if (potion == 1 ){
                    use_potion();
                }

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
                    std::cout << "You defeated the enemy!" << std::endl;
                    sleep(1);
                    _hero.set_xp(enemy.get_xp_worth());
                    std::cout << "You gained " << enemy.get_xp_worth() << " experience points!" << std::endl;
                    sleep(1);
                    std::cout << "You have " << _hero.get_xp() << " experience points!" << std::endl;
                    std::cout << std::endl;

                    //remove enemy from list.
                    std::string elementToRemove = enemy.get_name();
                    auto it = std::find(_current_enemies.begin(), _current_enemies.end(),elementToRemove);

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

        int element_relation(std::string enemy_element){
            int hero_win = 1;
            int hero_lose = 0;
            int neutral = 2;

            int enemy_win = 3;
            int enemy_lose = 4;
            //HERO
            if (_hero.weapong_element() == "fire" && enemy_element == "metal"){return hero_win;}
            if (_hero.weapong_element() == "fire" && enemy_element == "earth"){return hero_lose;}
            if (_hero.weapong_element() == "earth" && enemy_element == "water"){return hero_win;}
            if (_hero.weapong_element() == "earth" && enemy_element == "metal"){return hero_lose;}
            if (_hero.weapong_element() == "metal" && enemy_element == "wood"){return hero_win;}
            if (_hero.weapong_element() == "metal" && enemy_element == "water"){return hero_lose;}
            if (_hero.weapong_element() == "water" && enemy_element == "fire"){return hero_win;}
            if (_hero.weapong_element() == "water" && enemy_element == "wood"){return hero_lose;}
            if (_hero.weapong_element() == "wood" && enemy_element == "earth"){return hero_win;}
            if (_hero.weapong_element() == "wood" && enemy_element == "fire"){return hero_lose;}

            //EMEMY
            if (_hero.weapong_element() == "fire" && enemy_element == "wood"){return enemy_lose;}
            if (_hero.weapong_element() == "fire" && enemy_element == "water"){return enemy_win;}
            if (_hero.weapong_element() == "earth" && enemy_element == "fire"){return enemy_lose;}
            if (_hero.weapong_element() == "earth" && enemy_element == "wood"){return enemy_win;}
            if (_hero.weapong_element() == "metal" && enemy_element == "earth"){return enemy_lose;}
            if (_hero.weapong_element() == "metal" && enemy_element == "fire"){return enemy_win;}
            if (_hero.weapong_element() == "water" && enemy_element == "metal"){return enemy_lose;}
            if (_hero.weapong_element() == "water" && enemy_element == "earth"){return enemy_win;}
            if (_hero.weapong_element() == "wood" && enemy_element == "water"){return enemy_lose;}
            if (_hero.weapong_element() == "wood" && enemy_element == "metal"){return enemy_win;}

            return neutral;
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

        void print_inventory(){
            if(_db.inventory_count(_hero.get_Sname()) < 1){
                std::cout << "Your hands is your only weapon" << std::endl;
                sleep(1);
                return;
            }
            int i;
            hmm:
            std::cout << "Equip an item from your inventory: " << std::endl;
            for (int inv : _db.get_inventory(_hero.get_Sname())){
                std::cout << "| " << inv << " : " << _db.get_item(inv) << " - element: " << _db.get_item_element(inv) << " |" << std::endl;

            }

            std::cin >> i;
            std::cout << "" << std::endl;
            for (int inv : _db.get_inventory(_hero.get_Sname())){
                if(i == inv){
                    if (_shop.get_item(_db.get_item(i)).get_req() > 0 || _shop.get_item(_db.get_item(i)).get_name() == "Knife"){
                        _hero.equip_item(_shop.get_item(_db.get_item(i)));
                        std::cout << "You equipped: " << _hero.get_item() << std::endl;
                        return;
                    }
                    else{
                        std::cout << "That looks like a potion and is not suitable for combat " << std::endl;
                        std::cout << "Try again: " << std::endl;
                        goto hmm;
                    }
                }
            }
            std::cout << "You did not equip a weapon try again"<< std::endl;
            goto hmm;
        }

        void use_potion(){
            if(_db.inventory_count_potion(_hero.get_Sname()) < 1){
                std::cout << "You have no potions"<< std::endl;
                sleep(1);
                return;
            }
            pot:
            std::vector <int> check;
            for (int inv : _db.get_inventory(_hero.get_Sname())){
                if (_shop.get_item(_db.get_item(inv)).get_req() == 0 && _shop.get_item(_db.get_item(inv)).get_name() != "Knife"){
                    std::cout << "| " << inv << " : " << _db.get_item(inv) << " - element: " << _db.get_item_element(inv) << " |" << std::endl;
                    check.push_back(inv);
                }

            }
            int i;
            std::cin >> i;
            for (int k : check){
                if (k == i && _hero.current_mana() >= _shop.get_item(_db.get_item(i)).get_mana_cost()){
                    _hero.heal(_shop.get_item(_db.get_item(i)).get_self_dmg()*(-1));
                    _hero.mana_up(_shop.get_item(_db.get_item(i)).get_mana_cost()*(-1));
                    _db.remove_item_inventory(_hero.get_Sname(), _db.get_item(i));
                    std::cout << "|----------------------|" << std::endl;
                    std::cout << "|Your hp is now :   "<< _hero.get_hp() <<"  |" << std::endl;
                    std::cout << "|Your mana is now :  "<< _hero.current_mana() <<" |" << std::endl;
                    std::cout << "|----------------------|" << std::endl;
                    return;

                }

            }
            std::cout << "That doesnt look like a potion, wouldnt drinkt that...." << std::endl;
            std::cout << "Try again: " << std::endl;
            goto pot;


        }



// BIOME STUFF ---------------------------------------------------------------------

    Biome choose_biome(){
        std::cout << "choose a biome you want to explore!" << std::endl; 
        std::vector <std::string> biome_name = _db.get_biome_list()[0];
        std::vector <std::string> difficulty = _db.get_biome_list()[1];

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
                std::cout << "You arrived!" << std::endl;
                sleep(2);
                _biome[i].biome_description();
                return _biome[i];
            }
            else if(i == _biome.size()) {
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
        if (check_string == "city"){return "City";}
        else return check_string;

    }

    void set_enemy_for_biome(Biome biome){
        int id = _db.get_biome_id(biome)-1;  //biome id is from 1-4 but the get_enemy_in_biome uses 0 indexing.
        this -> _current_enemies_xp = _db.get_enemy_xp_in_biome()[id];
        this -> _current_enemies = _db.get_enemy_in_biome()[id];

    }


    void biome_defeated(Biome biome){
        std::cout << std::endl;
        std::cout << "Congrats you have defeated every fool who dared to stand in your way!!" << std::endl;
        sleep(1);
        std::cout << "For that you are rewarded with " << biome.get_gold() << " gold" << std::endl;
        sleep(2);
        std::cout << "Now dont spent it all at once.. " << std::endl;
        if (_hero.get_hp() < _hero.get_max_hp()/3){
            std::cout << "You might want to visit Rumpelstiltskin for some health potions." << std::endl;
            std::cout << "He is located in the City" << std::endl;
        }
        _hero.update_gold(biome.get_gold());
        throw BiomeDoneException();
    }

    void visit_city(){
        int place;
        visit:
        std::cout << "Where do you want to go? " << std::endl;
        std::cout << "| 1 : Lake Luminis                                       |" << std::endl;
        std::cout << "| 2 : Rumpelstiltskin's Magical World of Sizzling Zazzle |" << std::endl;
        std::cout << "| 3 : The Royal Palace of Dawnspire                      |" << std::endl;
        std::cout << "| 4 : The Golden Market                                  |" << std::endl;
        std::cout << "| 5 : The Docks of Mistral                               |" << std::endl;
        std::cout << "| 6 : The Weeping Willow Tavern                          |" << std::endl;
        std::cout << "| 9 : Choose Another Biome                               |" << std::endl;



        std::cin >> place;
        char i;
        int buy;
        char choice;
        char new_place;
        switch(place) {
          case 1:
                system("clear");

                lake_discription();
                goto visit;
            break;

          case 2:
            system("clear");
            _shop.shop_detail();
            shop2:

            try {
            std::cout << "Press 1 for buying an item -- press Q for exit" << std::endl;
            std::cin >> choice;
            int req = 8;
            if (choice == '1'){
            shop:
                if (_db.inventory_count(_hero.get_Sname()) == 0){
                    req = 8;
                }
                else{
                    req = _db.fetch_req_hero(_hero.get_Sname());
                }
                system("clear");
                std::cout << "You can acquired up to item: " << req+1 << " -- You have this much gold to spend: " << _hero.get_gold()<< std::endl;
                _shop.list_item();
                std::cin >> buy;
                Item item = _shop.buy_item(_hero.get_gold(), req, buy);
                _hero.use_gold(item.get_price());
                _hero.add_to_inventory(item);
                _db.add_item_inventory(_hero.get_Sname(), item.get_name());
                std::cout << "This is you current inventory: " << std::endl;
                print_inventory();
                std::cout << "press 1 for buying more item - press Q for exiting shop." << std::endl;
                std::cin >> new_place;
                if (new_place == '1'){
                    goto shop;
                }

                else{goto visit;}
            }

            else {break;}
        }  catch (const ShopReqException& e) {
            std::cout << "Press 1 for try again -- Press Q for Exit " << std::endl;
            std::cin >> i;
            if (i == '1'){
                goto shop2;
            }
            else {break;}

        } catch (const ShopCostException& e) {
            std::cout << "Press 1 for try again -- Press Q for Exit " << std::endl;
            std::cin >> i;
            if (i == '1'){
                goto shop2;
            }
            else {break;}
        }
            break;

          case 3:
                system("clear");

                palace_discription();

                goto visit;
           break;

          case 5:
                system("clear");

                dock_discription();

                goto visit;
            break;

            case 6:
              system("clear");

              tavern_discription();

              goto visit;
          break;

          case 9:

            break;
          default:
            system("clear");

            std::cout << "Under contruction come back later .. " << std::endl;
            goto visit;
        }

    }

    void lake_discription(){
            std::cout << "Lake Luminis, a vast and serene body of water, serves as a majestic" << std::endl;
            sleep(2);
            std::cout << "gateway to the bustling city of Suzail. Its waters, shimmering with the" << std::endl;
            sleep(2);
            std::cout << "reflection of dawn and dusk, transition from a grand lake outside the city" << std::endl;
            sleep(2);
            std::cout << "into a meandering channel that cuts through Suzail, inviting the mysteries" << std::endl;
            sleep(2);
            std::cout << "of the ocean deep into the heart of the kingdom." << std::endl;
            sleep(2);
            std::cout << std::endl;
            int i;
            std::cout << "Want to hear more about the lake? 1 - Yes     2 - NO " << std::endl;
            std::cin >> i;
            if (i == 1) {
                std::cout << "The Lake and its Natural Splendor:" << std::endl;
                sleep(2);
                std::cout << "Outside the city, Lake Luminis stretches wide, bordered by lush forests" << std::endl;
                sleep(2);
                std::cout << "and rugged hills. Its surface mirrors the sky, catching the fire of sunsets" << std::endl;
                sleep(2);
                std::cout << "and the calm of early mornings. Here, the lake is alive with biodiversity;" << std::endl;
                sleep(2);
                std::cout << "schools of silver fish flash beneath the surface, and birds of prey circle" << std::endl;
                sleep(2);
                std::cout << "overhead." << std::endl;
                sleep(2);
                std::cout << std::endl;
            }
            else {return;}
            int k;
            std::cout << "Want to hear more about the lake? 1 - Yes     2 - NO " << std::endl;
            std::cin >> k;
            if (k == 1) {
                sleep(2);
                std::cout << "Transition to the Channel:" << std::endl;
                sleep(2);
                std::cout << "As the lake approaches Suzail, it narrows into a tranquil channel. This" << std::endl;
                sleep(2);
                std::cout << "channel, known as the \"Suzail Vein,\" is bordered by high stone walls" << std::endl;
                sleep(2);
                std::cout << "that have been aged and softened by time and water. Small boats and" << std::endl;
                sleep(2);
                std::cout << "barges navigate this waterway, their hulls loaded with goods from the" << std::endl;
                sleep(2);
                std::cout << "distant ocean, bringing spices, textiles, and exotic wares to the city’s" << std::endl;
                sleep(2);
                std::cout << "markets." << std::endl;
                sleep(2);
            }
            else {return;}

    }

    void palace_discription(){
        std::cout << "Located at the pinnacle of Suzail, the Royal Palace of Dawnspire is an" << std::endl;
        sleep(2);
            std::cout << "awe-inspiring architectural masterpiece and the most iconic symbol of" << std::endl;
            sleep(2);
            std::cout << "the city's heritage and power. This grand palace not only dominates the" << std::endl;
            sleep(2);
            std::cout << "skyline but also serves as the political and magical hub of the kingdom" << std::endl;
            sleep(2);
            std::cout << "of Issle." << std::endl;
            sleep(2);
            std::cout << std::endl;
            int i;
            std::cout << "Want to hear more about the palace? 1 - Yes     2 - NO " << std::endl;
            std::cin >> i;
            sleep(2);
            if (i == 1){
            std::cout << "Architectural Grandeur:" << std::endl;
            sleep(2);
            std::cout << "The Dawnspire rises majestically above the urban sprawl, its towers" << std::endl;
            sleep(2);
            std::cout << "designed to mimic the natural tapering of mountain spires. Constructed" << std::endl;
            sleep(2);
            std::cout << "from the legendary Whitestone—known for its luminescent properties" << std::endl;
            sleep(2);
            std::cout << "under moonlight—each block has been enchanted to resist the ravages of" << std::endl;
            sleep(2);
            std::cout << "time and war. The central tower, the tallest and most magnificent, is" << std::endl;
            sleep(2);
            std::cout << "crowned with a gigantic crystalline orb that captures the first light" << std::endl;
            sleep(2);
            std::cout << "of dawn and the last light of dusk, bathing the palace in an ethereal" << std::endl;
            sleep(2);
            std::cout << "glow." << std::endl;
            sleep(2);
            std::cout << std::endl;
            }

            else{return;}
            int k;
            std::cout << "Want to hear more about the palace? 1 - Yes     2 - NO " << std::endl;
            std::cin >> k;
            if (k == 1){
            sleep(2);
            std::cout << "The Throne Room:" << std::endl;
            sleep(2);
            std::cout << "The heart of the Dawnspire is the Throne Room, a vast space with walls" << std::endl;
            sleep(2);
            std::cout << "draped in silk tapestries depicting the realm's diverse landscapes." << std::endl;
            sleep(2);
            std::cout << "The throne itself is a masterpiece, crafted from gold and elderwood," << std::endl;
            sleep(2);
            std::cout << "and is said to have been enchanted by the first queen of Issle. It" << std::endl;
            sleep(2);
            std::cout << "grants the sitting monarch the ability to commune with the spirits of" << std::endl;
            sleep(2);
            std::cout << "their ancestors, seeking guidance in times of need." << std::endl;
            sleep(2);
            }
            else{return;}

    }

    void dock_discription(){
        std::cout << "These busy docks are where the lake meets the city, filled with" << std::endl;
        sleep(2);
        std::cout << "fishermen, traders, and ships from distant lands. The air here is" << std::endl;
        sleep(2);
        std::cout << "salty and carries tales of the sea, pirates, and distant shores laden" << std::endl;
        sleep(2);
        std::cout << "with spices and silks." << std::endl;
        sleep(2);

    }

    void tavern_discription(){
        int in;
            std::cout << "Nestled close to the Suzail Vein, where the tranquil waters of" << std::endl;
            sleep(3);
            std::cout << "Lake Luminis narrow into the lifeblood channel of Suzail, sits The Weeping Willow Tavern." << std::endl;
            std::cout << std::endl;
            std::cout << "Would you like to skip the introduction?" << std::endl;
            std::cout << " Press 1 for Yes -- Press 0 for No" << std::endl;
            std::cin >> in;
            if (in == 1){goto willow;}
            if (in == 0){
                system("clear");
                std::cout << "Nestled close to the Suzail Vein, where the tranquil waters of" << std::endl;
                std::cout << "Lake Luminis narrow into the lifeblood channel of Suzail, sits The Weeping Willow Tavern." << std::endl;
            }

            std::cout << "This charming establishment, housed within a pair of ancient," << std::endl;
            sleep(3);
            std::cout << "timber-framed buildings linked by a" << std::endl;
            sleep(3);
            std::cout << "sturdy stone bridge, offers a welcoming beacon to weary" << std::endl;
            sleep(3);
            std::cout << "travelers and local adventurers alike. The Weeping Willow is a" << std::endl;
            sleep(3);
            std::cout << "picturesque sight, its structures seemingly bending to whisper" << std::endl;
            sleep(3);
            std::cout << "secrets into the flowing waters below. The tavern’s exterior is" << std::endl;
            sleep(3);
            std::cout << "clad in weathered wood and rough stones, with ivy and moss" << std::endl;
            sleep(3);
            std::cout << "climbing the walls, giving it an enchanted, almost organic" << std::endl;
            sleep(3);
            std::cout << "appearance. Quaint windows peek out under sharply pitched" << std::endl;
            sleep(3);
            std::cout << "roofs, and lanterns hang by the doors, casting a warm glow in" << std::endl;
            sleep(3);
            std::cout << "the evening twilight." << std::endl;
            sleep(3);
            std::cout << std::endl;
            std::cout << "Inside, the tavern is alive with the crackle of the hearth and" << std::endl;
            sleep(3);
            std::cout << "the merry din of patrons' chatter. The main room is a cozy" << std::endl;
            sleep(3);
            std::cout << "congregation of rough-hewn tables and benches, lit by candles" << std::endl;
            sleep(3);
            std::cout << "and the occasional magical orb floating lazily under the" << std::endl;
            sleep(3);
            std::cout << "exposed wooden beams. Banners and tapestries hang from the" << std::endl;
            sleep(3);
            std::cout << "walls, depicting scenes of legendary heroes and past" << std::endl;
            sleep(3);
            std::cout << "festivities, adding a touch of history and pride to the rustic charm." << std::endl;
            willow:
            int choice;
                std::cout << "Select an option to learn more about The Weeping Willow Tavern:" << std::endl;
                std::cout << "|_____________________________|" << std::endl;
                std::cout << "| 1 - Menu and Offerings      |" << std::endl;
                std::cout << "| 2 - Patrons and Atmosphere  |" << std::endl;
                std::cout << "| 3 - Accommodations          |" << std::endl;
                std::cout << "| 4 - Exit the tavern         |" << std::endl;
                std::cout << "|_____________________________|" << std::endl;
                std::cin >> choice;

                switch(choice) {
                case 1:
                    std::cout << "Menu and Offerings:" << std::endl;
                    sleep(2);
                    std::cout << "The Weeping Willow is famed not just for its idyllic location but also" << std::endl;
                    sleep(2);
                    std::cout << "for its hearty fare. The kitchen serves a robust selection of local dishes:" << std::endl;
                    sleep(2);
                    std::cout << "spiced lake fish, venison pies, and platters of grilled root vegetables," << std::endl;
                    sleep(2);
                    std::cout << "all sourced from the surrounding countryside. Their ale selection includes" << std::endl;
                    sleep(2);
                    std::cout << "brews from local artisans and a special ‘Willow Wisps’ brew, a light beer" << std::endl;
                    sleep(2);
                    std::cout << "with hints of apple and cinnamon, crafted in small batches by the innkeeper himself." << std::endl;
                    sleep(2);
                    break;
                case 2:
                    std::cout << "Patrons and Atmosphere:" << std::endl;
                    sleep(2);
                    std::cout << "A typical evening sees a diverse mix of clientele, from muddy-booted" << std::endl;
                    sleep(2);
                    std::cout << "farmers ending their day to cloaked travelers stopping by to rest their" << std::endl;
                    sleep(2);
                    std::cout << "bones and share tales of the road. Occasionally, a bard might grace the" << std::endl;
                    sleep(2);
                    std::cout << "tavern, their songs rising above the din, spinning tales of distant lands" << std::endl;
                    sleep(2);
                    std::cout << "or ancient battles, much to the delight of the patrons." << std::endl;
                    sleep(2);
                    goto willow;
                    break;
                case 3:
                    std::cout << "Accommodations:" << std::endl;
                    sleep(2);
                    std::cout << "For those seeking rest, The Weeping Willow offers several modest rooms" << std::endl;
                    sleep(2);
                    std::cout << "upstairs, each furnished with simple comforts aimed at providing a good" << std::endl;
                    sleep(2);
                    std::cout << "night’s sleep. The rooms overlook either the bustling street leading into" << std::endl;
                    sleep(2);
                    std::cout << "the heart of Suzail or the serene Suzail Vein, where the gentle sounds of" << std::endl;
                    sleep(2);
                    std::cout << "water help lull travelers to sleep." << std::endl;
                    sleep(2);
                    double price = 500+(150*(_hero.get_level()-1));
                    int rent;
                    std::cout << "Would you like rent a bed for the night? price "<< price << " gold"<< std::endl;
                    std::cout << "You will recover lost health and mana during a sleep in the tavern" << std::endl;
                    std::cout << "Press 1 for Yes  -- Press 2 for No : ";
                    std::cin >> rent;
                    std::cout << std::endl;
                    if(rent == 2) {goto willow; }
                    if (rent == 1 && _hero.get_gold() > price){
                        show_moon();
                        sleep(3);
                        _hero.update_gold(-price);
                        _hero.heal_max();
                        _hero.mana_max();
                        _hero.get_stats();
                    }
                    else{
                        std::cout << "You dont have enough money ... " << std::endl;
                        std::cout << "Come back another time" << std::endl;
                        goto willow;
                    }
                    break;

                }

    }
    void show_moon(){
            system("clear");
            std::cout << "          ______            \\'/" << std::endl;
            sleep(1); // Sleep after second line
            std::cout << "      .-'` .    `'-.      -= * =-" << std::endl;
            std::cout << "    .'  '    .---.  '.      /.\\ " << std::endl;
            sleep(1); // Sleep after second line
            std::cout << "   /  '    .'       `'. \\ " << std::endl;
            std::cout << "  ;  '    /             \\|" << std::endl;
            sleep(1); // Sleep after second line
            std::cout << " :  '  _ ;               `" << std::endl;
            std::cout << " ;  :  /(\\ \\ " << std::endl;
            sleep(1); // Sleep after second line
            std::cout << " |  .       '." << std::endl;
            std::cout << " |  ' /     --'" << std::endl;
            sleep(1); // Sleep after second line
            std::cout << " |  .   '.__\\" << std::endl;
            std::cout << " ;  :       /" << std::endl;
            sleep(1); // Sleep after second line
            std::cout << "  ;  .     |              ," << std::endl;
            std::cout << "   ;  .    \\            /|" << std::endl;
            sleep(1); // Sleep after second line
            std::cout << "    \\  .    '.        .'/" << std::endl;
            std::cout << "     '.  '  . `'---'`.'" << std::endl;
            sleep(1); // Sleep after second line
            std::cout << "       `'-..._____.-`" << std::endl;
            sleep(5);
            system("clear");
    }
//GAME OVER --------------------------------------------------------------
        void Game_Over(){
            _db.game_over(_hero.get_Qname());
            throw ExitGameException();  // Throw to signal game exit
        }
}; 

#endif
// Path: enemy.h
