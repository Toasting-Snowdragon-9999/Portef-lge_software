#ifndef HERO_H
#define HERO_H 

#include <iostream>
#include <vector>
#include <string>
#include <QtSql>
#include <QSqlDatabase>
#include "setup.h"

class Hero {   
    private:
        QString _name; 
        double _current_hp;
        double _max_hp;
        double _xp; 
        int _level;
        int _strength;  

        QSqlQuery query;

    public:
        Hero(){}

        void Load_Hero(std::string name){
            this->_name = QString::fromUtf8(name.c_str());
            query.prepare("SELECT * FROM hero where name = ?;");
            query.addBindValue (this->_name); 
            query.exec();
            while(query.next()){
                this -> _level = query.value(2).toInt();
                this -> _current_hp = query.value(3).toDouble();
                this -> _max_hp = query.value(4).toDouble();
                this -> _strength = query.value(5).toInt();
                this ->_xp = query.value(6).toDouble();
            }
        }

        void New_Hero(std::string name){
            this -> _name = QString::fromUtf8(name.c_str());
            this-> _current_hp = 10.0;
            this -> _max_hp = 10.0;
            this -> _xp = 0.0;
            this -> _level = 1;
            this -> _strength = 2;

            query.prepare("INSERT IGNORE INTO hero (name, level, currentHP, maxHP, strength, xp) VALUES (?,1,10,10,2,0)");
            query.addBindValue(this->_name); 
            query.exec(); 

        }

        void dmg_taken(int dmg){
            this -> _current_hp = this->_current_hp-dmg;
        }

        void heal(int heal){
 
            this -> _current_hp = this->_current_hp + heal;
        }

        void heal_max(){

            this -> _current_hp = this->_max_hp;
        }

        double get_hp(){
            return this-> _current_hp;
        }

        double get_max_hp(){
            return this-> _max_hp;
        }

        int get_level(){
            return this-> _level;
        }

        int get_strength(){
            return this-> _strength;
        }

        double get_xp(){
            return this-> _xp;
        }

        QString get_Qname(){
            return this-> _name;
        }

        std::string get_Sname(){
            return _name.toStdString();
        }

        void set_xp(double xp){
            this -> _xp = this-> _xp+xp;
            if (this->_xp >= this->_level*1000){
                level_up();
            }
            
        }

        void level_up(){
            this -> _level++;
            this -> _strength++;
            this -> _max_hp++;
            this -> _max_hp++;
            this -> _xp=0; 
            heal_max(); 
        }

        void get_stats(){
            std::cout << "------------------" << std::endl;
            std::cout << "| " << "HP: " << this ->_current_hp << "/ "<< this -> _max_hp << "     |" << std::endl;
            std::cout << "| " << "Strength: " << this -> _strength << "   |" << std::endl;
            std::cout << "| " << "LVL: " << this ->_level << "        |" << std::endl;

            std::cout << "| " << "XP: " << this ->_xp << "/" << 1000*this-> _level << " |" << std::endl;
            std::cout << "------------------" << std::endl;
        }

    

}; 

#endif
// Path: hero.cpp   