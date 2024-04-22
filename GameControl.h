#ifndef game_control_H
#define GAME_CONTROL_H

#include <iostream>
#include <vector>
#include <string>
#include <QtSql>
#include <QSqlDatabase>
#include <iomanip>
#include <unistd.h> 
#include <stdexcept>


#include "hero.h"
#include "enemy.h"
#include "setup.h"
#include "area.h"

class Game_Control {
    private: 
        QSqlQuery query;
        Hero _hero; 
        std::vector <Biome> _biome;  
    public: 
        Game_Control(){  
            //INSERT IGNORE INTO enemy (name, type, health, strength, xp_worth)
            Enemy boar("NULL", "boar", 4, 1, 100);
            Enemy wolf("NULL", "wolf", 2, 2, 100);
            Enemy bear("NULL", "bear", 5, 2, 200);
            Enemy goblin("NULL", "goblin", 6, 3, 400);
            Enemy orc("NULL", "orc", 8, 4, 600);
            Enemy MightyGoblin("NULL", "Mighty Goblin", 10, 5, 700);
            Enemy troll("NULL", "troll", 10, 5, 900);
            Enemy giant("NULL", "giant", 12, 6, 1000);
            Enemy basilisk ("NULL", "basilisk", 12, 6, 1200);
            Enemy GoblingKing("Gurp", "Goblin King", 15, 7, 2000);
            Enemy dragon("LongVein", "Dragon", 28, 5, 3000);
            //INSERT IGNORE INTO biome (name, type, enemy_count, level)
            Biome forest("Forest", "normal", 5, 1);
            Biome city("Suzail", "City", 5, 1);
            Biome castle ("Castle", "normal", 5, 3);
            Biome mountain("Mountain", "normal", 5, 2);
            Biome cave("Cave", "dark", 5, 5);
            Biome desert("Desert", "normal", 5, 4);
            Biome dragonLair("Dragon Lair", "dragon", 5, 6);
            Biome abyss("Abyss", "demon", 5, 10);
            
        }

        ~Game_Control(){
            query.prepare("UPDATE hero SET level = ?, currentHP = ?, maxHP = ?, strength = ?, xp = ? where NAME = ?;");
            query.addBindValue(_hero.get_level());
            query.addBindValue(_hero.get_hp());
            query.addBindValue(_hero.get_max_hp());
            query.addBindValue(_hero.get_strength());
            query.addBindValue(_hero.get_xp());
            query.addBindValue(_hero.get_Qname());
            query.exec();
        }

        void initialize_hero(int game){
            Hero hero;
             // Declare the Hero object outside the switch statement
            std::string name; 
                switch(game){
                        case 1:
                                std::cout << "Enter your name: ";
                                std::cin >> name;
                                hero.New_Hero(name); // Initialize the Hero object inside the case
                                break;
                        case 2:
                               
                                std::cout << "Here is a list of characters: " << std::endl;
                                print_hero_names();
                                std::cout << "" << std::endl;
                            tryAgain:
                                std::cout << "Enter the name of the character you want to load: ";
                                try{
                                std::cin >> name;
                                if (check_for_hero(name)==false){throw std::invalid_argument("No hero by that name try again!"); }
                                hero.Load_Hero(name); // Initialize the Hero object inside the case
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


        std::string hero_name(){
            return _hero.get_Sname(); 
        }

        bool check_for_hero(std::string name){
            QString test = QString::fromStdString(name);
            query.prepare("SELECT COUNT(*) FROM hero WHERE name = ?;");
            query.addBindValue(test);
            query.exec();
            bool i = false; 
            while (query.next()){
                if (query.value(0).toInt()==0)
                    {i = false; }
                if (query.value(0).toInt()==1)
                   { i = true; }
            }
            return i; 
        }

        void stats(){
            std::cout << "Do you want to check your stats?" << std::endl;
            std::cout << "1. Yes ----- 2. No ";
            int stats;
            int exit = 0;
            std::cin >> stats;
            if(stats == 1){
                std::cout << "" << std::endl;
                _hero.get_stats(); 
                std::cout << "" << std::endl;
             
            }
        }


        Enemy get_enemy(int id){
            query.prepare("SELECT * FROM enemy WHERE id = ?");
            query.addBindValue(id);
            query.exec();
            while(query.next()){
                return Enemy(query.value(1).toString(), query.value(2).toString(), query.value(3).toInt(), query.value(4).toInt(), query.value(5).toInt());
            }
            // throw std::runtime_error("no enemy found!");

        }

        void print_hero_names(){
            query.prepare("select name, id, level from hero ORDER BY id ASC;");
            query.exec();
            std::cout << "--------------------------------" << std::endl; 
            while(query.next()){
                std::cout << "| " << query.value(0).toString().toStdString() << " LEVEL: "<< query.value(2).toString().toStdString() << " |" << std::endl;
                
            }
            std::cout << "--------------------------------" << std::endl; 

        }

         void print_enemies_name(){
            query.prepare("select type, id, xp_worth from enemy ORDER BY id ASC;");
            query.exec();
            int i = 1;
            while(query.next()){
                std::cout << query.value(0).toString().toStdString() << "  --  Xp: " << query.value(2).toString().toStdString()  << std::endl;
                i++;
            }
        }

        int combat(Enemy enemy){
            std::cin.get();
            while(_hero.get_hp() > 0 && enemy.get_health() > 0){
                std::cout << "" << std::endl;
                std::cout << "Press Enter to attack!" << std::endl;
                std::cin.get();
                _hero.dmg_taken(enemy.get_strength());
                enemy.dmg_taken(_hero.get_strength());
                std::cout << "--------------------------------------------------------------------" << std::endl;
                std::cout << "You have dealt " << _hero.get_strength() << " damage to the enemy!" << std::endl;
                std::cout << "Your health: " << _hero.get_hp() << "          "<< std::right << "Enemy health: "  << enemy.Enemy::get_health() << std::endl;
                

                if(_hero.get_hp() <= 0){
                    std::cout << "You have died!" << std::endl;
                    std::cout << "This is unfortunatly game over for you!" << std::endl;
                    std::cout << "Try Again and create a new character!" << std::endl;
                    Game_Over(); 
                    return 0; 
                }
                else if(enemy.get_health() <= 0){
                    std::cout << "" << std::endl; 
                    std::cout << "You have defeated the enemy!" << std::endl;
                    _hero.heal_max();
                    _hero.set_xp(enemy.get_xp_worth());
                    std::cout << "You have gained " << enemy.get_xp_worth() << " experience points!" << std::endl;
                    std::cout << "You have " << _hero.get_xp() << " experience points!" << std::endl;

                    break;
                }
            }
            return 1; 
        }

        int fight(){
            std::cout << "Here is a list of monsters you can fight!" << std::endl;
            print_enemies_name();
            std::cout << "Choose the monster you want to fight!" << std::endl;
                int monster;
                std::cin >> monster;
                    switch(monster){    
                        case 1:
                            return combat(get_enemy(1));
                            
                        case 2:
                            return combat(get_enemy(2));
                            
                        case 3:
                            return combat(get_enemy(3));
                        case 4:
                            return combat(get_enemy(4));
                        case 5:
                            return combat(get_enemy(5));
                        case 6: 
                            return combat(get_enemy(6));
                        case 7: 
                            return combat(get_enemy(7));
                        case 8:
                            return combat(get_enemy(8));
                        case 9:
                            return combat(get_enemy(9));
                        case 10:
                            return combat(get_enemy(10));
                        case 11:
                            return BOSS_combat(get_enemy(11));
                    }
                    return 0; 
        }

        int BOSS_combat(Enemy enemy){
            sleep(2);
            std::cout << "BEHOLD THE GREAT WHITE DRAGON!!!" << std::endl;
            sleep(2);
            std::cout << "/ /   **THUNDER**   / /" << std::endl;
            std::cout << "- -   **THUNDER**   - -" << std::endl;
            std::cout << " / /   **THUNDER**   / /" << std::endl;
            sleep(2);
            std::cout << std::endl; 
            std::cout << std::endl; 
            std::cout << "/ /   **THUNDER**   / /" << std::endl;
            std::cout << "- -   **THUNDER**   - -" << std::endl;
            std::cout << " / /   **THUNDER**   / /" << std::endl;
            std::cout << std::endl; 
            std::cout << std::endl; 
            sleep(2); 
            std::cout << "--------------------" << std::endl;
            std::cout << "--------------------" << std::endl;
            std::cout << "--------------------" << std::endl;
            std::cout << "LONGVEIN THE DESROYER" << std::endl;
            std::cout << "SECOND TO HIS NAME!!" << std::endl;
            std::cout << "--------------------" << std::endl;
            std::cout << "--------------------" << std::endl;
            std::cout << "--------------------" << std::endl;
             sleep(2);
            std::cout << "/ /   **THUNDER**   / /" << std::endl;
            std::cout << "- -   **THUNDER**   - -" << std::endl;
            std::cout << " / /   **THUNDER**   / /" << std::endl;
            sleep(2);
            std::cout << std::endl; 
            std::cout << std::endl; 
            std::cout << "/ /   **THUNDER**   / /" << std::endl;
            std::cout << "- -   **THUNDER**   - -" << std::endl;
            std::cout << " / /   **THUNDER**   / /" << std::endl;
            std::cout << std::endl; 
            std::cout << std::endl; 
            sleep(2); 

            std::cin.get();
            while(_hero.get_hp() > 0 && enemy.get_health() > 0){
                std::cout << "" << std::endl;
                std::cout << "Press Enter to attack!" << std::endl;
                std::cin.get();
                _hero.dmg_taken(enemy.get_strength());
                enemy.dmg_taken(_hero.get_strength());
                std::cout << "--------------------------------------------------------------------" << std::endl;
                std::cout << "You have dealt " << _hero.get_strength() << " damage to the enemy!" << std::endl;
                std::cout << "Your health: " << _hero.get_hp() << "          "<< std::right << "Enemy health: "  << enemy.Enemy::get_health() << std::endl;
                

                if(_hero.get_hp() <= 0){
                    std::cout << "You have died!" << std::endl;
                    std::cout << "This is unfortunatly game over for you!" << std::endl;
                    std::cout << "Try Again and create a new character!" << std::endl;
                    Game_Over(); 
                    return 0; 
                }
                else if(enemy.get_health() <= 0){
                    std::cout << "" << std::endl; 
                    std::cout << "You have defeated the enemy!" << std::endl;
                    _hero.heal_max();
                    _hero.set_xp(enemy.get_xp_worth());
                    std::cout << "You have gained " << enemy.get_xp_worth() << " experience points!" << std::endl;
                    std::cout << "You have " << _hero.get_xp() << " experience points!" << std::endl;

                    break;
                }
            }
            return 1; 
        }


        void Game_Over(){
            query.prepare("DELETE FROM hero where name = ?;");
            query.addBindValue (_hero.get_Qname()); 
            query.exec();
        }
}; 

#endif
// Path: enemy.h