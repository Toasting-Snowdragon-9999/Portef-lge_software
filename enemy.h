#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>
#include <vector>
#include <string>
#include <QtSql>
#include <QSqlDatabase>
#include "setup.h"

class Enemy {
    private:
        int _health;
        QString _type;
        QString _name;
        int _strength; 
        double _xp_worth; 
        QSqlQuery query;

    public:
        Enemy(QString name, QString type, int health, int strength, double xp_worth){
            this -> _type = type;
            this -> _name = "NULL";
            this -> _health = health;
            this -> _strength = strength;
            this -> _xp_worth = xp_worth;
            
            query.prepare("INSERT IGNORE INTO enemy (name, type, health, strength, xp_worth) VALUES (?,?,?,?,?)");
            query.addBindValue(name);
            query.addBindValue(type); 
            query.addBindValue(health); 
            query.addBindValue(strength);
            query.addBindValue(xp_worth);
            query.exec(); 

        }

        void dmg_taken(int dmg){
            this -> _health = _health-dmg;
        }

        void heal(int heal){
            this -> _health = _health + heal;
        }

        void set_name(QString name){
            this -> _name = name;
        }

        void set_xp_worth(double xp){
            this -> _xp_worth = xp;
        }

        int get_health(){
            return this->_health;
        }

        QString get_type(){
            return this->_type;
        }

        QString get_name(){
            return this->_name;
        }

        int get_strength(){
            return this->_strength;
        }

        double get_xp_worth(){
            return this->_xp_worth;
        }



}; 

#endif
// Path: enemy.h