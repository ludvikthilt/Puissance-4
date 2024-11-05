#include <iostream>
#include "game.h"
#include <string>




int main(int argc, char** argv){
    
    bool start = true ;
    while(start){
        std::string choix ;

        int grille[7][6] = {}, mode_de_jeu, placement,joueur = (rand() % 2) + 1;

        bool victoire = false;

        std::cout << "Choisissez le mode de jeu :"<<std::endl;
        std::cout << "1. Joueur vs Joueur \t"
                  << "2. Joueur vs IA \t"
                  << "3. Quitter \t"<<std::endl;
        std::cin >> mode_de_jeu;
         
        draw_grid(grille);

        if (mode_de_jeu == 1){
            while (!victory(grille,joueur) || egality(grille)){
                p_turn(grille,joueur,placement);
                joueur = (joueur == 1) ? 2 : 1;
            }
            if (egality(grille)){
                std::cout<< "MATCH NUL"<<std::endl;
            }else{
                std::cout<<"victoire du joueur "<< joueur<<std::endl;
            }
   
        }else if(mode_de_jeu == 3){
            system("CLS");
            return 0;
        }else if(mode_de_jeu == 2){
            while (!victory(grille,joueur) || egality(grille)){
                while(joueur == 1){
                    p_turn(grille,joueur,placement);
                    joueur = (joueur == 1) ? 2 : 1;
                }
                while(joueur == 2){
                    ai_turn(grille);
                    joueur = (joueur == 1) ? 2 : 1;
                }
            }
           

            if (egality(grille)){
                std::cout<< "MATCH NUL"<<std::endl;
            }else{
                std::cout<<"victoire du joueur "<< joueur<<std::endl;
            }
    
        }
        
        std::cout<< "nouvelle partie oui (o) / non (n)?:> "<<std::endl;
        std::cin>> choix ;
        if (choix == "n" ){
            system("CLS");
            break;
        }else if(choix == "o"){
            system("CLS");
            continue;
        }else{
            system("CLS");
            break;
        }
        
    }
    start = false ;
    return 0;
}



