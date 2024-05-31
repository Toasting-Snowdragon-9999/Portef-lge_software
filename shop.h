#ifndef SHOP_H
#define SHOP_H
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>

#include <unistd.h>               // for linux

#include "item.h"
#include "database_handler.h"
#include "exit.h"

class Shop{
    private:
        std::string _name;
        std::vector <Item> _itemList;
        DB_Handler _db;
    public:
        Shop(std::string username, std::string password) : _db(username, password){};

        void add_item(Item item){
            _itemList.push_back(item);
        }

        void set_up_items(){
            _db.create_item("Mana Exchange", 0, -2, 0, 2, 4, 0);
            Item mana_exchange("Mana Exchange", 0, -2, 0, 2, 4, 0);
            add_item(mana_exchange);

            _db.create_item("Health Exchange", 0, 2, 0, -2, 4, 0);
            Item hp_exchange("Health Exchange", 0, 2, 0, -2, 4, 0);
            add_item(hp_exchange);

            _db.create_item("Health Potion", 0, -2, 200, 0, 4, 0);
            Item hp_potion("Health Potion", 0, -2, 200, 0, 4, 0);
            add_item(hp_potion);
            _db.add_item_inventory("Admin", "Health Potion");

            _db.create_item("Better Health Potion", 0, -5, 500, 0, 4, 0);
            Item bhp_potion("Better Health Potion", 0, -5, 500, 0, 4, 0);
            add_item(bhp_potion);

            _db.create_item("Great Health Potion", 0, -10, 900, 0, 4, 0);
            Item ghp_potion("Great Health Potion", 0, -10, 900, 0, 4, 0);
            add_item(ghp_potion);

            _db.create_item("Mana Potion", 0, 0, 200, -2, 4, 0);
            Item mana_potion("Mana Potion", 0, 0, 200, -2, 4, 0);
            add_item(mana_potion);
            _db.add_item_inventory("Admin", "Mana Potion");

            _db.create_item("Better Mana Potion", 0, 0, 500, -5, 4, 0);
            Item bmana_potion("Better Mana Potion", 0, 0, 500, -5, 4, 0);
            add_item(bmana_potion);

            _db.create_item("Great Mana Potion", 0, 0, 900, -10, 4, 0);
            Item gmana_potion("Great Mana Potion", 0, 0, 900, -10, 4, 0);
            add_item(gmana_potion);

            _db.create_item("Knife",1,0,200, 0, 3, 0);
            Item knife("Knife", 1, 0, 200, 0 , 3 ,0);
            add_item(knife);
            _db.add_item_inventory("Admin", "Knife");

            _db.create_item("Sword",2,0,500, 0, 3, 9);
            Item sword("Sword", 2, 0, 500, 0, 3, 9);
            _db.add_item_inventory("Admin", "Sword");
            add_item(sword);

            _db.create_item("Flaming Sword", 3, 1, 1000, 5, 1, 10);
            Item flamming_sword("Flaming Sword", 3, 1, 1000, 5, 1, 10);
            add_item(flamming_sword);
            _db.add_item_inventory("Admin", "Flaming Sword");

            _db.create_item("Blood Spear", 3, 1, 2000, 3, 4, 11);
            Item blood_spear("Blood Spear", 3, 1, 2000, 3, 4, 11);
            add_item(blood_spear);
            _db.add_item_inventory("Admin", "Blood Spear");

            _db.create_item("Beserker Axe", 4, 2, 3500, 3, 2, 12);
            Item beserker_axe("Beserker Axe", 4, 2, 3500, 3, 2, 12);
            add_item(beserker_axe);
            _db.add_item_inventory("Admin", "Beserker Axe");

            _db.create_item("Eye of Medusa", 6, 2, 5000, 5, 2, 13);
            Item eye_medusa("Eye of Medusa", 6, 2, 5000, 5, 2, 13);
            add_item(eye_medusa);
            _db.add_item_inventory("Admin", "Eye of Medusa");

            _db.create_item("Molten Great Axe", 7, 3, 7000, 3, 1, 14);
            Item molten_great_axe("Molten Great Axe", 7, 3, 7000, 3, 1, 14);
            add_item(molten_great_axe);


            _db.create_item("Vampiric Scepter", 5, -3, 8000, 3, 4, 14);
            Item vampiric_scepter("Vampiric Scepter", 5, -3, 8000, 3, 4, 14);
            add_item(vampiric_scepter);

            _db.create_item("Dragon Slayer Sword", 10, 4, 10000, 5, 4, 14);
            Item dragon_slayer("Dragon Slayer Sword", 10, 4, 10000, 5, 4, 14);
            add_item(dragon_slayer);

            }

        void shop_detail(){
            std::cout << "Welcome to the enchanted alleyways of Suzail's Arcane District," << std::endl;
            sleep (3);
            std::cout << "home to Rumpelstiltskin's Magical World of Sizzling Zazzle. " << std::endl;
            sleep (3);
            std::cout << "This legendary shop, managed by the enigmatic and" << std::endl;
            sleep (3);
            std::cout << "somewhat notorious Rumpelstiltskin," << std::endl;
            sleep (3);
            std::cout << "a lich known for his greed yet, fairness, offers a trove of magical" << std::endl;
            sleep (3);
            std::cout << "weapons, potent potions, and enigmatic amulets." << std::endl;
            sleep (3);
            std::cout << "Step inside and discover a world where every item has its own tale and power." << std::endl;
            sleep (3);
        }

        Item get_item(std::string item_name){
            for (Item item : _itemList){
                if (item.get_name() == item_name){
                    return item;
                }
            }
            Item hand("Hand", 0, 0, 0, 0, 0, 0);
            return hand;
        }


        Item buy_item(double gold, int req, int item){
            if (req >= _itemList[item-1].get_req()){
//                std::cout << "You have the correct req" << std::endl;
                if (gold >= _itemList[item-1].get_price()){

                    std::cout << "You have enough gold" << std::endl;

                    return _itemList[item-1];
                }
                else {
                    throw ShopCostException();
                }

            }
            else{
                throw ShopReqException();
            }
        }

        void list_item() {
            int index = 1;
            std::vector<std::string> lines;
            std::cout << "Here is a list of available items for purchase: " << std::endl;

            // Determine maximum width for each column
            int max_name_length = 0, max_strength_length = 0, max_price_length = 0;
            int max_requirement_length = 0, max_mana_cost_length = 0, max_health_cost_length = 0;
            // Better way to determin and set spaces, this method needs const method.
            for (const Item& i : _itemList) {
                // Returns the larger value, max length or the length of the element.
                max_name_length = std::max(max_name_length, static_cast<int>(i.get_name().length()));
                max_strength_length = std::max(max_strength_length, static_cast<int>(std::to_string(i.get_dmg()).length()));
                max_price_length = std::max(max_price_length, static_cast<int>(std::to_string(i.get_price()).length()));
                max_requirement_length = std::max(max_requirement_length, static_cast<int>(std::to_string(i.get_req()).length()));
                max_mana_cost_length = std::max(max_mana_cost_length, static_cast<int>(std::to_string(i.get_mana_cost()).length()));
                max_health_cost_length = std::max(max_health_cost_length, static_cast<int>(std::to_string(i.get_self_dmg()).length()));
            }

            for (const Item& i : _itemList) {
                std::string weapon;
                if (i.get_req() > 0 || i.get_name() == "Knife") {weapon = " | Weapon: ";}
                else {weapon = " | Potion: ";}

                std::cout << "| " << std::left << std::setw(5) << index
                          << weapon  << std::left << std::setw(max_name_length + 2) << i.get_name()
                          << " | Strength: " << std::left << std::setw(max_strength_length + 2) << i.get_dmg()
                          << " | Price: $" << std::left << std::setw(max_price_length + 2) << i.get_price()
                          << " | Requirement: " << std::left << std::setw(max_requirement_length + 2) << i.get_req()
                          << " | Mana Cost: " << std::left << std::setw(max_mana_cost_length + 2) << i.get_mana_cost()
                          << " | Health Cost: " << std::left << std::setw(max_health_cost_length + 2) << i.get_self_dmg()
                          << " |" << std::endl;
                index++;
            }
        }

};

#endif // SHOP_H
