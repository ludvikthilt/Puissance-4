#include "game.h"
#include <iostream>
#include <string>


void draw_grid(int grid[7][6]){
    for (int ligne = 0; ligne < 6; ligne++){
        std::cout << "|";
        for (int col = 0; col < 7; col++){
            if (grid[col][ligne] == 1){
                std::cout << "\033[31mX\033[37m";
            } else 
            if (grid[col][ligne] == 2){
                std::cout << "\033[32mO\033[37m";
            }
            else {
                std::cout << "\033[37m*\033[37m";
            }
            std::cout << "|";
        }
        std::cout << "\n";
    }
}

bool victory(int grid[7][6], int player) {

    
    for (int col = 0; col < 7; col++) {
        int count = 0;
        for (int ligne = 0; ligne < 6; ligne++) {
            if (grid[col][ligne] == player) {
                count++;
                if (count >= 4) {
                    return true;
                }
            } else {
                count = 0; 
            }
        }
    }


    for (int ligne = 0; ligne < 6; ligne++) {
        int count = 0;
        for (int col = 0; col < 7; col++) {
            if (grid[col][ligne] == player) {
                count++;
                if (count >= 4) {
                    return true;
                }
            } else {
                count = 0;
            }
        }
    }

   
    for (int col = 0; col < 7; col++) {
        for (int ligne = 0; ligne < 6; ligne++) {
            if (col + 3 < 7 && ligne + 3 < 6) {
                if (grid[col][ligne] == player &&
                    grid[col + 1][ligne + 1] == player &&
                    grid[col + 2][ligne + 2] == player &&
                    grid[col + 3][ligne + 3] == player) {
                    return true;
                }
            }
        }
    }

    for (int col = 0; col < 7; col++) {
        for (int ligne = 0; ligne < 6; ligne++) {
            if (col - 3 >= 0 && ligne + 3 < 6) {
                if (grid[col][ligne] == player &&
                    grid[col - 1][ligne + 1] == player &&
                    grid[col - 2][ligne + 2] == player &&
                    grid[col - 3][ligne + 3] == player) {
                    return true;
                }
            }
        }
    }

    return false; 
}

bool egality(int grid[7][6]){
    for (int col = 0; col < 7; col++){
        if (grid[col][0] == 0){
            return false;
        }
    }
    return true;

}

void p_turn(int grid[7][6],int player, int positionnement){
    int col = 0 ;
    int ligne  = 5 ;
    

    std::cout<<"Joueur "<< player<<" veuillez entrer votre placement(numero de colonne)"<<"-> col : "<<std::endl;
    std::cin >> positionnement;
    if (positionnement >= 1 && positionnement <= 7){
        while (grid[positionnement - 1][ligne] == 1 ||grid[positionnement - 1][ligne] == 2 ){
            ligne -- ;
        }
        grid[positionnement - 1][ligne] = player;
        system("CLS");
        draw_grid(grid);
        
    }else{
        std::cout<<"veuillez entrer un nombre compris entre 1 et 7"<<std::endl;
        system("CLS");
        draw_grid(grid);
    }
}

int ai_turn(int grid[7][6]){

 alea(grid);

}


int alea (int grid[7][6]){
    int aicol = rand()%7;
    int ailine = 5;

    while (grid[aicol][ailine] != 0 ){
            ailine -- ;
    }
    return grid[aicol][ailine] = 2;

}

