#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>
#include <vector>
#include <string>
#include <QtSql>
#include <QSqlDatabase>
#include<unistd.h>               // for sleep

class Enemy {
    private:
        int _health;
        std::string _name;
        int _strength; 
        double _xp_worth;
        int _biome_id;
        int _element_id;

    public:
        Enemy(std::string name, int health, int strength, double xp_worth, int biome_id, int element_id){

            this -> _name = name;
            this -> _health = health;
            this -> _strength = strength;
            this -> _xp_worth = xp_worth;
            this -> _biome_id = biome_id;
            this -> _element_id = element_id;
        }

        void dmg_taken(int dmg){
            this -> _health = _health-dmg;
        }

        void heal(int heal){
            this -> _health = _health + heal;
        }

        void set_name(std::string name){
            this -> _name = name;
        }

        void set_xp_worth(double xp){
            this -> _xp_worth = xp;
        }

        int get_health(){
            return this->_health;
        }

        std::string get_name(){
            
            return _name;
        }

        int get_strength(){
            return this->_strength;
        }

        double get_xp_worth(){
            return this->_xp_worth;
        }

        void set_hp(int hp){
            this -> _health = hp;
        }

        std::string get_element(){
            if (_element_id == 1){
                return "fire";
            }
            if (_element_id == 2){
                return "earth";
            }
            if (_element_id == 3){
                return "metal";
            }
            if (_element_id == 4){
                return "water";
            }
            if (_element_id == 5){
                return "wood";
            }

        }


        void boss_fight(){

            if (get_name() == "Dragon"){
                sleep(2);
                std::cout << "BEHOLD THE GREAT GREEN DRAGON!!!" << std::endl;
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
            }
            else if (get_name() == "GoblinKing"){

            }

            else {std::cout << std::endl;}
        }

}; 

#endif
// Path: enemy.h
