#ifndef HERO_H
#define HERO_H 

#include <iostream>
#include <vector>
#include <string>
#include <QtSql>
#include <QSqlDatabase>

class Hero {   
    private:
        std::string _name; 
        double _current_hp;
        double _max_hp;
        double _xp; 
        int _level;
        int _strength;  
        double _gold;

    public:
        Hero(){}

        void Load_Hero(std::vector <std::string> hero_data){
            this -> _name = hero_data[1];
            this -> _level = stoi(hero_data[2]); //query.value(2).toInt();
            this -> _current_hp = stod(hero_data[3]); //query.value(3).toDouble();
            this -> _max_hp = stod(hero_data[4]);   //query.value(4).toDouble();
            this -> _strength =  stod(hero_data[5]);       //query.value(5).toInt();
            this ->_xp = stod(hero_data[6]);       //query.value(6).toDouble();
            this -> _gold = stod(hero_data[7]);

        }

        void New_Hero(std::string name){
            this -> _name = name;
            this-> _current_hp = 10.0;
            this -> _max_hp = 10.0;
            this -> _xp = 0.0;
            this -> _level = 1;
            this -> _strength = 2;
            this -> _gold = 0;

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
        double get_gold(){
            return this -> _gold;
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

            QString Qname = QString::fromUtf8(_name.c_str());
            return Qname;
        }

        std::string get_Sname(){
            return this-> _name;
        }

        void update_gold(double gold){
            this -> _gold += gold;
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
            if(this -> _level > 10){
            std::cout << "-------------------------------" << std::endl;
            std::cout << "| HOORAY! You have leveled up!|" << std::endl;
            std::cout << "| You are now lvl "<< this -> _level << "           |"<< std::endl;
            std::cout << "-------------------------------" << std::endl;
            }
            else {
                std::cout << "-------------------------------" << std::endl;
                std::cout << "| HOORAY! You have leveled up!|" << std::endl;
                std::cout << "| You are now lvl "<< this -> _level << "          |"<< std::endl;
                std::cout << "-------------------------------" << std::endl;
            }

        }

        void get_stats(){


            std::vector<std::string> lines;
            lines.push_back("| HP: " + std::to_string(int(_current_hp)) + "/ " + std::to_string(int(_max_hp)) + " ");
            lines.push_back("| Strength: " + std::to_string(int(_strength)) + " ");
            lines.push_back("| LVL: " + std::to_string(_level) + " ");
            lines.push_back("| XP: " + std::to_string(long(_xp)) + "/" + std::to_string(_level) + "000 "); // Assuming this->_level + "000" is a concatenation in string format
            lines.push_back("| GOLD: " + std::to_string(long(_xp)) + " ");
            // Determine the longest line
            size_t max_length = 0;
            for (const auto& line : lines) {
                max_length = std::max(max_length, line.size());
            }

            // Print each line with the right amount of padding to align the '|'
            std::cout << std::string(max_length, '-') << std::endl;
            for (const auto& line : lines) {
                std::cout << line.substr(0, line.find_last_of(' ') + 1)
                          << std::string(max_length - line.size(), ' ') << '|' << std::endl;
            }
            std::cout << std::string(max_length, '-') << std::endl;

        }

    

}; 

#endif
// Path: hero.cpp   


