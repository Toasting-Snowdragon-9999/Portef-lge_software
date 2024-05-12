// #ifndef SET_UP_DB_H
// #define  SET_UP_DB_H

// #include <iostream>
// #include <vector>
// #include <string>
// #include <QtSql>
// #include <QSqlDatabase>

// void set_up_db(){
//         QSqlDatabase db; 
//         QSqlQuery query;

//         db = QSqlDatabase::addDatabase("QMYSQL");
//         db.setHostName("localhost");
//         db.setDatabaseName("longvein");
//         db.setUserName("christopher");  // Change to username
//         db.setPassword("0221");  // Change to password
//         db.open();
//         query = QSqlQuery(db);

//         if (!db.isOpen()) {
//         std::cerr << "Error: Unable to open database\n";
        
//         }

//         QString createTableQueryEnemy = "CREATE TABLE IF NOT EXISTS enemy ("
//                                       "id INT AUTO_INCREMENT PRIMARY KEY,"
//                                       "type VARCHAR(255) UNIQUE NOT NULL,"
//                                       "name VARCHAR(255),"
//                                       "health INT,"
//                                       "strength INT NOT NULL,"
//                                       "xp_worth double NOT NULL"
//                                       ");";
//         query.exec(createTableQueryEnemy);

//         QString createTableQueryHero = "CREATE TABLE IF NOT EXISTS hero ("
//                                       "id INT AUTO_INCREMENT PRIMARY KEY,"
//                                       "name VARCHAR(255) UNIQUE NOT NULL,"
//                                       "level INT NOT NULL,"
//                                       "currentHP double,"
//                                       "maxHP double NOT NULL,"
//                                       "strength INT NOT NULL,"
//                                       "xp double NOT NULL"
//                                       ");";
//         query.exec(createTableQueryHero);

//         QString createTableQueryBiome = "CREATE TABLE IF NOT EXISTS biome ("
//                                       "id INT AUTO_INCREMENT PRIMARY KEY,"
//                                       "name VARCHAR(255) UNIQUE NOT NULL,"
//                                       "type VARCHAR(255) NOT NULL,"
//                                       "enemy_count double NOT NULL,"
//                                       "level int NOT NULL,"
//                                       "gold double NOT NULL"
//                                       ");";
//         query.exec(createTableQueryBiome);
        
// }; 

// #endif