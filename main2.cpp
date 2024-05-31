#include <iostream>

#include "hero.h"
#include "enemy.h"
#include "GameControl.h"

int main(int, char**){
    QSqlDatabase db;
    QSqlQuery query;

    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
//            db.setDatabaseName("longvein");
    db.setUserName("christopher");  // Change to username
    db.setPassword("0221");  // Change to password
    db.open();

    if (!db.isOpen()) {
    std::cerr << "Error: Unable to open database\n";

    }

    db.exec("CREATE DATABASE IF NOT EXISTS longvein2");
    db.setDatabaseName("longvein2");
    db.exec("USE longvein2");
    query = QSqlQuery(db);


    QString createTableQueryEnemy = "CREATE TABLE IF NOT EXISTS enemy ("
                                    "id INT AUTO_INCREMENT PRIMARY KEY, "
                                    "name VARCHAR(255) UNIQUE NOT NULL, "
                                    "health INT, strength INT NOT NULL, "
                                    "xp_worth double NOT NULL "
                                    ");";
    query.exec(createTableQueryEnemy);
//CREATE TABLE IF NOT EXISTS enemy (id INT AUTO_INCREMENT PRIMARY KEY, name VARCHAR(255) UNIQUE NOT NULL, health INT, strength INT NOT NULL, xp_worth double NOT NULL, biome_id INT,)


    QString createTableQueryHero = "CREATE TABLE IF NOT EXISTS hero ("
                                "id INT AUTO_INCREMENT PRIMARY KEY,"
                                "name VARCHAR(255) UNIQUE NOT NULL,"
                                "level INT NOT NULL,"
                                "currentHP double,"
                                "maxHP double NOT NULL,"
                                "strength INT NOT NULL,"
                                "xp double NOT NULL"
                                ");";
    query.exec(createTableQueryHero);


        std::cout << "hello world" << std::endl;
        return 1;
}
