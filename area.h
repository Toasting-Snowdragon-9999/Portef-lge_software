#ifndef AREA_H
#define AREA_H

#include <iostream>
#include <vector>
#include <string>
#include <QtSql>
#include <QSqlDatabase>
#include "setup.h"
#include "enemy.h"

class   Biome{
    private: 
        QString _name;                  //name of the biome
        QString _type;                  //type of the biome
        int _enemy_count;               //number of enemies in the biome
        std::vector<Enemy> _enemies;    //vector of enemies in the biome
        int _level;                     //difficulty level of the biome
        QSqlQuery query;
    public:  

    Biome(QString name, QString type, int enemy_count, int level){
        this -> _name = name;
        this -> _type = type;
        this -> _enemy_count = enemy_count;
        this -> _level = level;

        query.prepare("INSERT IGNORE INTO biome (name, type, enemy_count, level) VALUES (?,?,?,?)");
        query.addBindValue(name);
        query.addBindValue(type);
        query.addBindValue(enemy_count);
        query.addBindValue(level);
        query.exec();
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

    QString get_type(){
        return this->_type;
    }

    std::string get_name(){
        return this->_name.toStdString();
    }   

    void biome_description(){
        if (get_type()== "forest"){
        sleep(1);
        std::cout << "You have entered a large forest " << std::endl;
        sleep(1);
        std::cout << "The forest is vast and spand miles in every direction" << std::endl;
        sleep(1);
        std::cout << "You cant even get the faintes idea of how big it is" << std::endl;
        sleep(1);
        std::cout << "This forest is filled with " << _enemy_count << " enemies" << std::endl;

        }
        else if (get_type()=="desert"){
        std::cout << "You have entered a very hot desert" << std::endl;
        std::cout << "There is not water in sight" << std::endl;
        std::cout << "How did you even get here? how are you gonna find your way out?" << std::endl;
        std::cout << "The desert is filled with " << _enemy_count << " enemies" << std::endl;
        }
        else if (get_type()=="mountain"){
        std::cout << "You have entered the tallest mountain in ISSLE" << std::endl;
        std::cout << "The mountain is so tall that you cant even see the top" << std::endl;
        std::cout << "Maybe, juuuust maybe, you can fiend treasure here for Nothic ... " << std::endl;
        std::cout << "This mountain is filled with " << _enemy_count << " enemies" << std::endl;
        
        }
        else if (get_type()=="cave"){
        std::cout << "You have entered the cave of " << get_name()  << std::endl;
        std::cout << "This cave is filled with " << _enemy_count << " enemies" << std::endl;
        std::cout << "The enemies in this cave are level " << _level << std::endl;
        }
        else if (get_type()=="castle"){
        std::cout << "You have entered the castle of " << get_name()  << std::endl;
        std::cout << "This castle is filled with " << _enemy_count << " enemies" << std::endl;
        std::cout << "The enemies in this castle are level " << _level << std::endl;
        }
        else if (get_type()=="city"){
        std::cout << "You have entered the city of " << get_name() << std::endl; 
        std::cout << "The greate capital of ISSLE" << std::endl;
        std::cout << "This city is filled with maybe you should talk the inhabitants" << std::endl;
        } 
    }
}; 

#endif 