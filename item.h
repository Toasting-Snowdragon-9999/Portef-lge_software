#ifndef ITEM_H
#define ITEM_H
#include <vector>
#include <string>

class Item{
    private:
        std::string _name;
        int _strength;
        int _self_harm;
        double _price;
        int _mana;
        std::string _element;
        int _requirement;

    public:
        Item(std::string name, int strength, int self, double price, int mana, int element, int req) : _name(name), _strength(strength), _self_harm(self), _price(price), _mana(mana), _requirement(req) {
            if (element > 0 && element < 6){
                if (element == 1){
                    _element = "fire";
                }
                if (element == 2){
                    _element = "earth";
                }
                if (element == 3){
                    _element = "metal";
                }
                if (element == 4){
                    _element = "water";
                }
                if (element == 5){
                    _element = "wood";
                }
            }
            else {
                _element = "none";
            }

        }
        std::string get_name() const{
            return this -> _name;
        }

        int get_dmg() const{
            return this->_strength;
        }

        int get_self_dmg() const{
            return this->_self_harm;
        }

        double get_price() const{
            return this->_price;
        }

        int get_req() const{
            return this->_requirement;
        }

        int get_mana_cost() const{
            return this->_mana;
        }
        std::string get_element() const{
            return this -> _element;
        }


};

#endif // ITEM_H
