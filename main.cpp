#include <iostream>
#include "game.cpp"

int main(int, char**){
        Game game; 
        while (1){
                try{
                        game.run();
                }
                catch (const ExitGameException& e){
                        std::cerr << e.what() << std::endl;
                        std::cout << "Saving game";
                        sleep(1);
                        std::cout << ".";
                        sleep(1);
                        std::cout << ".";
                        sleep(1);
                        std::cout << "." << std::endl;
                        sleep(1);
                        return 0; 
                        break;
                }
                catch (const std::exception& e) {
                        std::cout << "An error occurred: " << e.what() << std::endl;
                        break; 
                }
        }
        return 0; 
}       
