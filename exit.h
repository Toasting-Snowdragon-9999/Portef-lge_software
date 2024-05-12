#ifndef EXIT_H
#define EXIT_H

#include <exception>

//Makes a simpel exception if the game is to be ended. 
class ExitGameException : public std::exception {
public:
    const char* what() const throw() {
        return "Exiting the game...";
    }
};


class BiomeDoneException : public std::exception {
public:
    const char* what() const throw() {
        return "Biome complete.";
    }
};

class BiomeErrorException : public std::exception {
public:
    const char* what() const throw() {
        return "Not a biome, type a correct biome.";
    }
};

#endif
