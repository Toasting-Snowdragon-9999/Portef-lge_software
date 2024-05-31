#ifndef DATABASE_HANDLER_H
#define DATABASE_HANDLER_H

#include <QtSql>
#include <QSqlDatabase>
#include <iostream>
#include <vector>
#include <string>

#include "hero.h"
#include "area.h"

class DB_Handler{
    private: 
        QSqlDatabase db; 
        QSqlQuery query;
        QString _password;
        QString _username;
    public: 
        DB_Handler(std::string username, std::string password) : _username(QString::fromStdString(username)), _password(QString::fromStdString(password)){}

        void set_up_db(){

            db = QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("localhost");
//            db.setDatabaseName("longvein");
            db.setUserName(_username);  // Change to username
            db.setPassword(_password);  // Change to password
            db.open();

            if (!db.isOpen()) {
            std::cerr << "Error: Unable to open database\n";
            
            }

            db.exec("CREATE DATABASE IF NOT EXISTS longvein");
            db.setDatabaseName("longvein");
            db.exec("USE longvein");
            query = QSqlQuery(db);

            QString createTableElement = "CREATE TABLE IF NOT EXISTS elements ("
                                        "id INT AUTO_INCREMENT PRIMARY KEY,"
                                        "type VARCHAR(255) UNIQUE NOT NULL,"
                                        "weak int NOT NULL,"
                                        "strong double NOT NULL"
                                        ");";
            query.exec(createTableElement);

            QString createTableQueryBiome = "CREATE TABLE IF NOT EXISTS biome ("
                                        "id INT AUTO_INCREMENT PRIMARY KEY,"
                                        "name VARCHAR(255) UNIQUE NOT NULL,"
                                        "type VARCHAR(255) NOT NULL,"
                                        "enemy_count double NOT NULL,"
                                        "level int NOT NULL,"
                                        "gold double NOT NULL"
                                        ");";
            query.exec(createTableQueryBiome);

            QString createTableQueryEnemy = "CREATE TABLE IF NOT EXISTS enemy ("
                                            "id INT AUTO_INCREMENT PRIMARY KEY, "
                                            "name VARCHAR(255) UNIQUE NOT NULL, "
                                            "health INT, strength INT NOT NULL, "
                                            "xp_worth double NOT NULL, "
                                            "biome_id INT, "
                                            "FOREIGN KEY (biome_id) REFERENCES biome(id),"
                                            "element_id INT, "
                                            "FOREIGN KEY (element_id) REFERENCES elements(id)"
                                            ");";
            query.exec(createTableQueryEnemy);
//CREATE TABLE IF NOT EXISTS enemy (id INT AUTO_INCREMENT PRIMARY KEY, name VARCHAR(255) UNIQUE NOT NULL, health INT, strength INT NOT NULL, xp_worth double NOT NULL, biome_id INT,)
            QString createTableItems = "CREATE TABLE IF NOT EXISTS items ("
                                        "id INT AUTO_INCREMENT PRIMARY KEY,"
                                        "name VARCHAR(255) UNIQUE NOT NULL,"
                                        "strength int NOT NULL,"
                                        "self_harm int NOT NULL,"
                                        "price double NOT NULL,"
                                        "mana int NOT NULL,"
                                        "requirement int NOT NULL,"
                                        "element_id int not null,"
                                        "FOREIGN KEY (element_id) REFERENCES elements(id)"
                                        ");";
            query.exec(createTableItems);

            QString createTableQueryHero = "CREATE TABLE IF NOT EXISTS hero ("
                                        "id INT AUTO_INCREMENT PRIMARY KEY,"
                                        "name VARCHAR(255) UNIQUE NOT NULL,"
                                        "level INT NOT NULL,"
                                        "currentHP double,"
                                        "maxHP double NOT NULL,"
                                        "strength INT NOT NULL,"
                                        "xp double NOT NULL,"
                                        "gold double not NULL,"
                                        "mana double not NULL"
                                        ");";
            query.exec(createTableQueryHero);

            //CREATE TABLE IF NOT EXISTS inventory(id INT AUTO_INCREMENT PRIMARY KEY,hero_id int NOT NULL, FOREIGN KEY (hero_id) REFERENCES hero(id), item_id int NOT NULL, FOREIGN KEY (item_id) REFERENCES item(id));
            QString createTableInventory = "CREATE TABLE IF NOT EXISTS inventory("
                                           "id INT AUTO_INCREMENT PRIMARY KEY,"
                                           "hero_id INT NOT NULL,"
                                           "item_id INT NOT NULL,"
                                           "FOREIGN KEY (hero_id) REFERENCES hero(id) ON DELETE CASCADE,"
                                           "FOREIGN KEY (item_id) REFERENCES items(id),"
                                           "UNIQUE(hero_id, item_id)"
                                           ");";
            query.exec(createTableInventory);


            create_admin();

        }

        void create_admin(){
            query.prepare("INSERT IGNORE INTO hero (name, level, currentHP, maxHP, strength, xp, gold, mana) VALUES ('Admin',10,28,28,12,9999,10000,28)");
            query.exec();
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

        std::vector <std::string> find_hero(std::string name){
            QString Qname = QString::fromUtf8(name.c_str());
            std::vector <std::string> hero; 
            int hero_colums =1;
            query.prepare("SELECT count(*) as No_of_Column FROM information_schema.columns WHERE table_name ='hero';");
            query.exec();
            while (query.next())
            {
                hero_colums = query.value(0).toString().toInt();
            }
            query.prepare("SELECT * FROM hero where name = ?;");
            query.addBindValue(Qname);
            query.exec();
            while(query.next()){
                for (int i = 0; i <= hero_colums-1 ; i++){
                hero.push_back(query.value(i).toString().toStdString()); 
                }
            }
            return hero; 
        }

        void create_hero(std::string name){
            QString Qname = QString::fromUtf8(name.c_str());
            query.prepare("INSERT IGNORE INTO hero (name, level, currentHP, maxHP, strength, xp, gold, mana) VALUES (?,1,10,10,2,0,0,10)");
            query.addBindValue(Qname); 
            query.exec();
        }
        
        void update_hero(Hero hero){
            query.prepare("UPDATE hero SET level = ?, currentHP = ?, maxHP = ?, strength = ?, xp = ?, gold = ?, mana = ? where NAME = ?;");
            query.addBindValue(hero.get_level());
            query.addBindValue(hero.get_hp());
            query.addBindValue(hero.get_max_hp());
            query.addBindValue(hero.get_strength());
            query.addBindValue(hero.get_xp());
            query.addBindValue(hero.get_gold());
            query.addBindValue(hero.get_mana());

            query.addBindValue(hero.get_Qname());
            query.exec();
        }

        std::vector <std::vector <std::string> > all_heroes(){
            std::vector <std::string> hero_level;
            std::vector <std::string> hero_name;
            std::vector <std::vector <std::string> > hero ;

            query.prepare("select name, level from hero ORDER BY level ASC;");
            query.exec();
            while (query.next()){
                hero_name.push_back(query.value(0).toString().toStdString());
                hero_level.push_back(query.value(1).toString().toStdString());
            }
            hero.push_back(hero_name);
            hero.push_back(hero_level);
            return hero; 
        }

        void create_enemy(std::string Sname, int health, int strength, double xp_worth, int biome_id, int element_id){
            QString Qname = QString::fromUtf8(Sname.c_str());
            query.prepare("INSERT IGNORE INTO enemy (name, health, strength, xp_worth, biome_id, element_id) VALUES (?,?,?,?,?,?)");
            query.addBindValue(Qname);
            query.addBindValue(health); 
            query.addBindValue(strength);
            query.addBindValue(xp_worth);
            query.addBindValue(biome_id);
            query.addBindValue(element_id);
            query.exec();
        }



        

        void create_biome(std::string Sname, std::string Stype, int enemy_count, int level, double gold){
            QString Qname = QString::fromUtf8(Sname.c_str());
            QString Qtype = QString::fromUtf8(Stype.c_str());
            query.prepare("INSERT IGNORE INTO biome (name, type, enemy_count, level, gold) VALUES (?,?,?,?,?)");
            query.addBindValue(Qname);
            query.addBindValue(Qtype);
            query.addBindValue(enemy_count);
            query.addBindValue(level);
            query.addBindValue(gold);
            query.exec();   
        }

        void create_element(std::string type, int weak, int strong){
            QString Qtype = QString::fromUtf8(type.c_str());
            query.prepare("INSERT IGNORE INTO elements (type, weak, strong) VALUES (?,?,?)");
            query.addBindValue(Qtype);
            query.addBindValue(weak);
            query.addBindValue(strong);
            query.exec();
        }

        void create_item(std::string name, int strength, int self_harm, double price, int mana, int element_id, int requirement){
            QString Qname = QString::fromUtf8(name.c_str());
            query.prepare("INSERT IGNORE INTO items (name, strength, self_harm, price, mana, element_id, requirement) VALUES (?,?,?,?,?,?,?)");
            query.addBindValue(Qname);
            query.addBindValue(strength);
            query.addBindValue(self_harm);
            query.addBindValue(price);
            query.addBindValue(mana);
            query.addBindValue(element_id);
            query.addBindValue(requirement);
            query.exec();
        }

        void add_item_inventory(std::string hero_name, std::string item){
            int hero_id = 0;
            int item_id = 0;
            QString Qname = QString::fromUtf8(hero_name.c_str());
            query.prepare("select id from hero WHERE name = ?;");
            query.addBindValue(Qname);
            query.exec();
            while(query.next()){
                hero_id = query.value(0).toInt();
            }
            QString Qitem = QString::fromUtf8(item.c_str());
            query.prepare("select id from items WHERE name = ?;");
            query.addBindValue(Qitem);
            query.exec();
            while(query.next()){
                item_id = query.value(0).toInt();
            }
            query.prepare("INSERT IGNORE INTO inventory (hero_id, item_id) VALUES (?,?)");
            query.addBindValue(hero_id);
            query.addBindValue(item_id);
            query.exec();

        }

//        std::vector<std::string> item_id_inventory(std::string hero_name){
//            int hero_id = 0;
//            int item_id = 0;
//            QString Qname = QString::fromUtf8(hero_name.c_str());
//            query.prepare("select id from hero WHERE name = ?;");
//            query.addBindValue(Qname);
//            query.exec();
//            while(query.next()){
//                hero_id = query.value(0).toInt();
//            }
//            QString Qitem = QString::fromUtf8(item.c_str());
//            query.prepare("select id from items WHERE name = ?;");
//            query.addBindValue(Qitem);
//            query.exec();
//            while(query.next()){
//                item_id = query.value(0).toInt();
//            }
//            query.prepare("INSERT IGNORE INTO inventory (hero_id, item_id) VALUES (?,?)");
//            query.addBindValue(hero_id);
//            query.addBindValue(item_id);
//            query.exec();


        int get_biome_id(Biome biome){
            int id = 0;
            query.prepare("select id from biome WHERE name = ?;");
            query.addBindValue (QString::fromStdString(biome.get_name()));
            query.exec();
            while(query.next()){
                id = query.value(0).toInt();
            }
            return id;
        }

        std::vector < std::vector <std::string> > get_biome_list(){
            std::vector <std::string> biome_name;
            std::vector <std::string> biome_level;
            query.prepare("select name, level from biome ORDER BY level ASC;");
            query.exec();
            while(query.next()){
                biome_name.push_back(query.value(0).toString().toStdString());
                biome_level.push_back(query.value(1).toString().toStdString());
            }
            std::vector <std::vector <std::string> > biome = {biome_name, biome_level};
            return biome; 
        }

        void game_over(QString name){
            query.prepare("DELETE FROM hero where name = ?;");
            query.addBindValue (name); 
            query.exec();
        } 


        std::vector <std::vector <std::string> > get_enemy_in_biome(){
            std::vector <std::vector <std::string> > enemy_list;
            std::vector <int> id_count;
            query.prepare("select id from biome order by id asc;");
            query.exec();
            while(query.next()){
                id_count.push_back(query.value(0).toInt());
            }
            for(int i : id_count){
                std::vector <std::string> biome;
                query.prepare("SELECT name FROM enemy where biome_id = ?;");
                query.addBindValue (i);
                query.exec();
                    while (query.next()){
                        biome.push_back(query.value(0).toString().toStdString());
                    }
                enemy_list.push_back(biome);
            }
           return enemy_list;
        }

        std::vector <std::vector <int> > get_enemy_xp_in_biome(){
            std::vector <std::vector <int> > enemy_xp;
            std::vector <int> id_count;
            query.prepare("select id from biome order by id asc;");
            query.exec();
            while(query.next()){
                id_count.push_back(query.value(0).toInt());
            }
            for(int i : id_count){
                std::vector <int> level;
                query.prepare("SELECT xp_worth FROM enemy where biome_id = ?;");
                query.addBindValue (i);
                query.exec();
                    while (query.next()){
                        level.push_back(query.value(0).toInt());
                    }
                enemy_xp.push_back(level);
            }
           return enemy_xp;
        }

        std::vector < int > get_inventory(std::string hero_name){
            int hero_id = 1;
            std::vector <int> item_id;
            QString Qname = QString::fromUtf8(hero_name.c_str());
            query.prepare("select id from hero WHERE name = ?");
            query.addBindValue(Qname);
            query.exec();
            while(query.next()){
                hero_id = query.value(0).toInt();

            }
            query.prepare("select item_id from inventory WHERE hero_id = ?");
            query.addBindValue(hero_id);
            query.exec();
            while(query.next()){
                    item_id.push_back(query.value(0).toInt());

            }
            return item_id;
        }

        std::string get_item(int item_id){

            std::string item;
            query.prepare("select name from items WHERE id = ?");
            query.addBindValue(item_id);
            query.exec();
            while(query.next()){
                item = query.value(0).toString().toStdString();
            }
            return item;

        }

        std::string get_item_element(int i){
            std::string element;
            int element_id = 1;
            query.prepare("select element_id from items WHERE id = ?");
            query.addBindValue(i);
            query.exec();
            while(query.next()){
                element_id = query.value(0).toInt();
            }

            query.prepare("select type from elements WHERE id = ?");
            query.addBindValue(element_id);
            query.exec();
            while(query.next()){
                element = query.value(0).toString().toStdString();
            }

            return element;
        }

        int fetch_req_hero(std::string hero_name){

            int hero_id = 1;
            std::vector <int> item_id;
            QString Qname = QString::fromUtf8(hero_name.c_str());
            query.prepare("select id from hero WHERE name = ?");
            query.addBindValue(Qname);
            query.exec();
            while(query.next()){
                hero_id = query.value(0).toInt();

            }
            query.prepare("SELECT item_id FROM inventory WHERE hero_id = ? ORDER BY item_id DESC");
            query.addBindValue(hero_id);
            query.exec();
            while(query.next()){
                    item_id.push_back(query.value(0).toInt());
            }
            return item_id[0];
        }

        int inventory_count(std::string hero_name){
            int hero_id = 1;
            int item_id = 1;
            QString Qname = QString::fromUtf8(hero_name.c_str());
            query.prepare("select id from hero WHERE name = ?");
            query.addBindValue(Qname);
            query.exec();
            while(query.next()){
                hero_id = query.value(0).toInt();

            }
            query.prepare("select count(*) from inventory where hero_id = ? AND item_id > 8");
            query.addBindValue(hero_id);
            query.exec();
            while(query.next()){
                    item_id = query.value(0).toInt();
            }
            return item_id;
        }
        int inventory_count_potion(std::string hero_name){
            int hero_id = 1;
            int item_id = 1;
            QString Qname = QString::fromUtf8(hero_name.c_str());
            query.prepare("select id from hero WHERE name = ?");
            query.addBindValue(Qname);
            query.exec();
            while(query.next()){
                hero_id = query.value(0).toInt();

            }
            query.prepare("SELECT COUNT(*) FROM inventory WHERE hero_id = ? AND item_id < 9;");
            query.addBindValue(hero_id);
            query.exec();
            while(query.next()){
                    item_id = query.value(0).toInt();
            }
            return item_id;
        }

        void remove_item_inventory(std::string hero_name, std::string item){
            int hero_id = 0;
            int item_id = 0;
            QString Qname = QString::fromUtf8(hero_name.c_str());
            query.prepare("select id from hero WHERE name = ?;");
            query.addBindValue(Qname);
            query.exec();
            while(query.next()){
                hero_id = query.value(0).toInt();
            }
            QString Qitem = QString::fromUtf8(item.c_str());
            query.prepare("select id from items WHERE name = ?;");
            query.addBindValue(Qitem);
            query.exec();
            while(query.next()){
                item_id = query.value(0).toInt();
            }
            query.prepare("DELETE FROM inventory WHERE hero_id = ? AND item_id = ?");
            query.addBindValue(hero_id);
            query.addBindValue(item_id);
            query.exec();

        }

}; 

#endif



