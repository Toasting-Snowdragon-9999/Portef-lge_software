#ifndef AREA_H
#define AREA_H

#include <iostream>
#include <vector>
#include <string>
#include <QtSql>
#include <QSqlDatabase>
#include <stdlib.h>  //    system("CLS");
#include <unistd.h>               // for linux

#include "database_handler.h"
#include "enemy.h"

class Biome{
    private: 
        std::string _name;                  //name of the biome
        std::string _type;                  //type of the biome
        int _enemy_count;               //number of enemies in the biome
        std::vector<Enemy> _enemies;    //vector of enemies in the biome
        int _level;                     //difficulty level of the biome
        double _gold;

    public:  

    void biome_init(std::string name, std::string type, int enemy_count, int level, double gold){
        this -> _name = name;
        this -> _type = type;
        this -> _enemy_count = enemy_count;
        this -> _level = level;
        this -> _gold = gold; 
    }

    void add_enemy(Enemy enemy){
        _enemies.push_back(enemy);
    }

    void remove_enemy(Enemy enemy){
        for (int i = 0; i < _enemies.size(); i++){
            if (_enemies[i].get_name() == enemy.get_name()){
                _enemies.erase(_enemies.begin() + i);
            }
        }
    }

    std::string get_type(){
        return this->_type;
    }

    std::string get_name(){
        return this->_name;
    }   

    double get_gold(){
        return this -> _gold; 
    }

    void add_to_enemy(std::vector <Enemy> list){
        int i = 0; 
        for (Enemy e_list : list){
            _enemies.push_back(e_list);
        }
    }

    void print_enemy_names (){
        int i = 1; 
        for (Enemy list : _enemies){
            std::cout << i << ": "<< list.get_name()<< " -- "<< list.get_xp_worth() <<" xp"<< std::endl;
            i++; 
        }

    }

    Enemy combat_list(){
        std::cout << "Here is a list of monsters you can fight!" << std::endl;
        print_enemy_names();
        std::cout << "Choose the monster you want to fight!" << std::endl;
            int monster;
            std::cin >> monster;
        return _enemies[monster]; 
    }

    void biome_description(){
        if (get_name()== "Forest"){
            sleep(2);
            system("clear");
            sleep(1);
            std::cout << "You have entered a large forest " << std::endl;
            sleep(2);
            std::cout << "The forest is vast and spand miles in every direction" << std::endl;
            sleep(2);
            std::cout << "You cant even get the faintes idea of how big it is" << std::endl;
            sleep(2);
            std::cout << "This forest is filled with " << _enemy_count << " enemies" << std::endl;
            sleep(2);

        }
        else if (get_name()=="Desert"){
            sleep(2);
            system("clear");
            sleep(1);
            std::cout << "You have entered a very hot desert" << std::endl;
            sleep(2);
            std::cout << "There is not water in sight" << std::endl;
            sleep(2);
            std::cout << "How did you even get here? how are you gonna find your way out?" << std::endl;
            sleep(2);
            std::cout << "The desert is filled with " << _enemy_count << " enemies" << std::endl;
            sleep(2);
        }
        else if (get_name()=="Mountain"){
            sleep(2);
            system("clear");
            sleep(1);
            std::cout << "You have arrived at foot of the tallest mountain in ISSLE" << std::endl;
            sleep(2);
            std::cout << "The mountain is so tall that you cant even see the top" << std::endl;
            sleep(2);
            std::cout << "Maybe, juuuust maybe, you can find treasure here for Nothic ... " << std::endl;
            sleep(2);
            std::cout << "This mountain is filled with " << _enemy_count << " enemies" << std::endl;
            sleep(2);

        }
        else if (get_name()=="Cave"){
            sleep(2);
            system("clear");
            sleep(1);
            std::cout << "You have entered the a cave"  << std::endl;
            sleep(2);
            std::cout << "It is very dark in here"  << std::endl;
            sleep(2);
            std::cout << "I wonder if you will be able to spot a faul creature..."  << std::endl;
            sleep(2);
            std::cout << "This cave is filled with " << _enemy_count << " enemies" << std::endl;
            sleep(2);
            std::cout << "The enemies in this cave are level " << _level << std::endl;
            sleep(2);
        }
        else if (get_name()=="Castle"){
            sleep(2);
            system("clear");
            sleep(1);
            std::cout << "You have entered the castle of " << get_name()  << std::endl;
            sleep(2);
            std::cout << "This castle is filled with " << _enemy_count << " enemies" << std::endl;
            sleep(2);
            std::cout << "The enemies in this castle are level " << _level << std::endl;
            sleep(2);
        }
        else if (get_name()=="City"){
            sleep(2);
            system("clear");
            sleep(1);
            std::cout << "You have entered the city of " << get_name() << std::endl;
            sleep(2);
            std::cout << "The greate capital of ISSLE" << std::endl;
            sleep(2);
            std::cout << "This city is filled with maybe you should talk the inhabitants" << std::endl;
            sleep(2);
        } 
        else {
            std::cout << "No biome with that type!"<< std::endl;
        }
    }

}; 

#endif 
