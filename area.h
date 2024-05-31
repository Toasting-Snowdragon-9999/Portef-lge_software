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
        if (get_name() == "Forest") {
            sleep(2);
            system("clear");
            sleep(1);
            std::cout << "You have entered a sprawling ancient forest." << std::endl;
            sleep(2);
            std::cout << "The trees tower like giants, their canopies blotting out the sky." << std::endl;
            sleep(2);
            std::cout << "Moss carpets the ground, and a dense mist swirls around your ankles." << std::endl;
            sleep(2);
            std::cout << "Distant howls and the rustling of leaves suggest you are not alone." << std::endl;
            sleep(2);
            std::cout << "The air is filled with the earthy scent of pine and wet foliage, heavy and cold." << std::endl;
            sleep(2);
            std::cout << "You sense the forest is vast and spans miles in every direction, a realm of endless mystery." << std::endl;
            sleep(2);
        }
        else if (get_name() == "Desert") {
            sleep(2);
            system("clear");
            sleep(1);
            std::cout << "You have stepped into the scorching expanse of a vast desert." << std::endl;
            sleep(2);
            std::cout << "The sun beats down mercilessly on the endless sea of sand." << std::endl;
            sleep(2);
            std::cout << "Mirages dance on the horizon, and the heat shimmers in waves." << std::endl;
            sleep(2);
            std::cout << "There is not a single drop of water in sight, only barren dunes." << std::endl;
            sleep(2);
            std::cout << "Your footsteps leave fleeting marks on the soft sands, quickly swallowed by the wind." << std::endl;
            sleep(2);
            std::cout << "You wonder how you arrived here and how you might ever find your way out." << std::endl;
            sleep(2);
        }
        else if (get_name() == "Mountain") {
            sleep(2);
            system("clear");
            sleep(1);
            std::cout << "You have arrived at the base of the tallest mountain known to ISSLE." << std::endl;
            sleep(2);
            std::cout << "The mountain's peak pierces the clouds, lost to the heavens above." << std::endl;
            sleep(2);
            std::cout << "Its slopes are steep and treacherous, cloaked in snow and mystery." << std::endl;
            sleep(2);
            std::cout << "Echoes of avalanches and the cries of distant eagles fill the air." << std::endl;
            sleep(2);
            std::cout << "Legends speak of ancient treasures hidden within its frozen caves." << std::endl;
            sleep(2);
            std::cout << "Perhaps, just perhaps, your fortunes lie hidden somewhere above." << std::endl;
            sleep(2);
        }
        else if (get_name() == "Cave") {
            sleep(2);
            system("clear");
            sleep(1);
            std::cout << "You have entered the depths of a dark, foreboding cave." << std::endl;
            sleep(2);
            std::cout << "The air is cool and damp, filled with the scent of mold and decay." << std::endl;
            sleep(2);
            std::cout << "Stalactites and stalagmites form eerie shapes in the dim light." << std::endl;
            sleep(2);
            std::cout << "The echo of dripping water is punctuated by distant, unknown sounds." << std::endl;
            sleep(2);
            std::cout << "You sense that something malevolent watches from the shadows." << std::endl;
            sleep(2);
            std::cout << "Your heart beats faster as you wonder what foul creatures lurk within." << std::endl;
            sleep(2);
        }
        else if (get_name() == "Castle") {
            sleep(2);
            system("clear");
            sleep(1);
            std::cout << "You have entered the grand castle of " << get_name() << "." << std::endl;
            sleep(2);
            std::cout << "The towering walls are lined with battle scars and ancient banners." << std::endl;
            sleep(2);
            std::cout << "Majestic halls echo the footsteps of kings and knights long past." << std::endl;
            sleep(2);
            std::cout << "The air holds a chill, and the stone beneath your feet whispers of secrets." << std::endl;
            sleep(2);
            std::cout << "Every corner offers stories of glory, intrigue, and betrayal." << std::endl;
            sleep(2);
            std::cout << "As you wander the corridors, you feel the weight of history surrounding you." << std::endl;
            sleep(2);
        }

        else if (get_name()=="City"){
            sleep(2);
            system("clear");
            sleep(1);
            std::cout << "You have entered the city of " << get_type() << std::endl;
            sleep(4);
            std::cout << "Nestled in the heart of the fantastical realm of Issle" << std::endl;
            sleep(4);
            std::cout << "the illustrious city of Suzail stands as a beacon of prosperity and architectural grandeur." << std::endl;
            sleep(4);
            std::cout << "Suzail is not just a city but a vibrant tapestry woven from the threads of magic, tradition, and intrigue." << std::endl;
            sleep(4);
            std::cout << "This ancient capital, bordered by the shimmering waters of Lake Luminis and shielded by the mystical Verdant Peaks," << std::endl;
            sleep(4);
            std::cout << "thrives under the rule of a wise and benevolent monarchy." << std::endl;
            sleep(4);
            std::cout << "You can talk to the wicked lich named Rumpelstiltskin, in his magical shop for ...";
            sleep(2);
            std::cout << ".. stuff "<< std::endl;
            sleep(2);
        }
        else if (get_name()=="DragonLair"){
            int carl;
            system("clear");
            sleep(3);
            std::cout << "The Verdant Grotto:" << std::endl;
            sleep(3);
            std::cout << "Tucked away in a secluded valley surrounded by towering cliffs and dense," << std::endl;
            sleep(3);
            std::cout << "evergreen forests, lies the lair of Longvein, the great green dragon." << std::endl;
            std::cout << "You want to hear more or skip intro? press 1 to continues - press 2 to skip" << std::endl;
            std::cin >> carl;
            if (carl == 1){
            system("clear");
            std::cout << "The Verdant Grotto:" << std::endl;
            std::cout << "Tucked away in a secluded valley surrounded by towering cliffs and dense," << std::endl;
            std::cout << "evergreen forests, lies the lair of Longvein, the great green dragon." << std::endl;
            sleep(3);
            std::cout << "Known as the Verdant Grotto, this hidden sanctuary is a marvel of nature," << std::endl;
            sleep(3);
            std::cout << "where the cave's interior bursts with lush, vibrant vegetation, thriving" << std::endl;
            sleep(3);
            std::cout << "in an otherworldly manner despite the lack of sunlight." << std::endl;
            sleep(3);
            std::cout << "Moss and climbing vines cover the cave walls, and small, bright flowers" << std::endl;
            sleep(3);
            std::cout << "pepper the landscape, giving off a gentle, luminescent glow that lights" << std::endl;
            sleep(3);
            std::cout << "the cavern with a soft, green hue." << std::endl;
            sleep(3);
            std::cout << "The entrance to Longvein’s lair is a wide, gaping maw in a cliff face," << std::endl;
            sleep(3);
            std::cout << "obscured by thick foliage and draped with curtains of ivy, making it almost" << std::endl;
            sleep(3);
            std::cout << "invisible to the untrained eye." << std::endl;
            sleep(3);
            std::cout << "The air here is humid and carries a mix of earthy and floral scents," << std::endl;
            sleep(3);
            std::cout << "occasionally cut by the acrid tang of dragon musk." << std::endl;
            sleep(3);
            std::cout << "What lies beyond this lush threshold is a realm of ancient mystery," << std::endl;
            sleep(3);
            std::cout << "where the echoes of Longvein's mighty roars mingle with the whispering" << std::endl;
            sleep(3);
            std::cout << "winds that speak of forgotten magic and hidden secrets." << std::endl;
            sleep(3);
            std::cout << "The path narrows and twists deeper into the heart of the grotto, leading" << std::endl;
            sleep(3);
            std::cout << "brave souls into a world where the boundary between the natural and" << std::endl;
            sleep(3);
            std::cout << "the supernatural blurs." << std::endl;
            sleep(3);
            std::cout << "Each step taken is a step into the unknown, where the very air pulses" << std::endl;
            sleep(3);
            std::cout << "with potent arcane energy, hinting at the powerful guardian that dwells" << std::endl;
            sleep(3);
            std::cout << "within." << std::endl;
            sleep(3);
            std::cout << "Here, in the verdant embrace of the grotto, legend and reality intertwine," << std::endl;
            sleep(3);
            std::cout << "promising either unparalleled discovery or unimaginable peril." << std::endl;
            sleep(3);
            }
            else {return; }

        }

        else {
            std::cout << "No biome with that type!"<< std::endl;
        }
    }

}; 

#endif 
