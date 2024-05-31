#ifndef HERO_H
#define HERO_H 

#include <iostream>
#include <vector>
#include <string>
#include <QtSql>
#include <QSqlDatabase>
#include "item.h"

class Hero {   
    private:
        std::string _name; 
        double _current_hp;
        double _max_hp;
        double _xp; 
        int _level;
        int _strength;  
        double _gold;
        double _current_mana;
        double _mana;
        Item _equiped_item;
        int _highest_req;
        std::vector <Item> _inventory;

    public:
        Hero() : _equiped_item("Hands", 0, 0, 0, 0, 0, 0){

        }

        void Load_Hero(std::vector <std::string> hero_data){
            this -> _name = hero_data[1];
            this -> _level = stoi(hero_data[2]); //query.value(2).toInt();
            this -> _current_hp = stod(hero_data[3]); //query.value(3).toDouble();
            this -> _max_hp = stod(hero_data[4]);   //query.value(4).toDouble();
            this -> _strength =  stod(hero_data[5]);       //query.value(5).toInt();
            this ->_xp = stod(hero_data[6]);       //query.value(6).toDouble();
            this -> _gold = stod(hero_data[7]);
            this -> _mana = stod(hero_data[8]);
            this -> _current_mana = _mana;
        }

        void New_Hero(std::string name){
            this -> _name = name;
            this-> _current_hp = 10.0;
            this -> _max_hp = 10.0;
            this -> _xp = 0.0;
            this -> _level = 1;
            this -> _strength = 2;
            this -> _gold = 0;
            this -> _mana = 10;
            this -> _current_mana = 10;

        }

        void dmg_taken(int dmg){
            this -> _current_hp = this->_current_hp-dmg;
        }

        void heal(int heal){
            if (_max_hp < _current_hp+heal){
                heal_max();
                return;
            }
            else{
                this -> _current_hp += heal;
            }        }



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

        double get_mana(){
            return this -> _mana;
        }

        void mana_max(){
            this -> _current_mana = this->_mana;
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

        void equip_item(Item item){
            this -> _equiped_item = item;
        }

        void add_to_inventory(Item item){
            for (Item i : _inventory){
                if (i.get_name() == item.get_name()){
                    std::cout << "this item is added: " << std::endl;
                    return;
                }
            }
            this ->_inventory.push_back(item);
        }

        void start_add_to_inv(std::vector <Item> db_items){
                this->_inventory = db_items;
        }

        std::string get_item(){
            return _equiped_item.get_name();
        }

        int weapon_dmg(){
            return _equiped_item.get_dmg();
        }

        int weapon_self_dmg(){
            return _equiped_item.get_self_dmg();
        }

        std::string weapong_element(){
            return _equiped_item.get_element();
        }

        void mana_use(double used){
            this -> _current_mana -= used;
        }

        void mana_up(double gain){
                if (_mana < _current_mana+gain){
                    this -> _current_mana = _mana;
                    return;
                }

            else{
                    this -> _current_mana += gain;
                    return;
                }
        }

        double current_mana(){
            return this->_current_mana;
        }

        int weapon_mana(){
            return this->_equiped_item.get_mana_cost();
        }

        void level_up(){
            this -> _level++;
            this -> _strength++;
            this -> _max_hp+=2;
            this -> _mana+=2;
            this -> _xp=0; 
            heal_max();
            mana_max();
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
            lines.push_back("| GOLD: " + std::to_string(long(_gold)) + " ");
            lines.push_back("| MANA: " + std::to_string(long(_current_mana)) + " ");
            lines.push_back("| Weapon: " + _equiped_item.get_name() + " ");
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

        void get_weapon_stats(){
            std::vector<std::string> lines;
            lines.push_back("| Weapon: " + _equiped_item.get_name() + " ");
            lines.push_back("| Strength: " + std::to_string(int(weapon_dmg())) + " ");
            lines.push_back("| Self Inflicted dmg: " + std::to_string(_equiped_item.get_self_dmg()) + " ");
            lines.push_back("| Mana Cost: " + std::to_string(long(_equiped_item.get_mana_cost())) + " ");
            lines.push_back("| Element type: " + _equiped_item.get_element() + " ");

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

        void get_highest_req(){
            this->_highest_req = 1;
            for (Item i : _inventory){
                if (i.get_req() > _highest_req){
                    this->_highest_req = i.get_req();
                }
            }

        }

        int get_req(){
            return this -> _highest_req;
        }

        void use_gold(double spend){
            this ->_gold -= spend;
        }


}; 

#endif
// Path: hero.cpp   


