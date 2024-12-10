#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>

void drawGrid(int grid[7][6]);
bool playTurn(int grid[7][6], int column, int player);
bool checkvictory ( int grid[7][6], int player);
int computerchoice( int grid[7][6]);
int prevision ( int grid[7][6], int player);


int main(int argc, char** argv){
    int grid[7][6] = {};
    std::string choix;

    srand(time(0));
    int player = 1;
    int a ;


std :: cout << " 1 . Mode Multijoueur joueur1 VS joueur2   " << std :: endl;
std :: cout << " 2 . Mode solo joueur1 VS ordinateur " << std :: endl;
std :: cout << " Faites votre choix" << std :: endl;
std :: cin >> a;


    if ( a == 1){

        drawGrid(grid);

            while (true){
                std::cout << "player_" << player << " -> col :";
                std::cin >> choix;

                if (choix == "exit"){
                    system("CLS");
                    break;
                }

                    bool success = false;
                    bool check = false;
                   

                if (choix.size() == 1){
                    if (choix[0] >= '0' && choix[0] <= '7'){
                    int col = choix[0]  - '0';
                
                    success = playTurn(grid, col, player);
                    check = checkvictory ( grid, player );

                    }
                }

                system("CLS");

                if (!success){
                std::cout << "votre choix est incorrect\n";
                } else{
                    if (player == 1) player = 2;
                else player = 1;
                }

                if ( check == true ){
                    if ( player == 1) {
                    std :: cout << "le joueur "<< player + 1 << " a gagne"<< std :: endl;
                    } else {
                    std :: cout << "le joueur "<< player - 1 << " a gagne"<< std :: endl;
                    }
                    drawGrid(grid);
                    break;
                }


                drawGrid(grid);
            }
            
               
            } else if ( a == 2){

        while (true){

            //drawGrid (grid);
            bool checking = false ;
            bool checker = false;
            int player1 = 1 ;
            int decision = prevision ( grid , player1 );

            std :: cout << "joueur " << player << " -> col : "<< std :: endl;

            if ( player == 2){

                if ( decision != 6 ) {

                    int col_c = decision;
                    std :: cout << col_c << std :: endl;
                    checking = playTurn(grid , col_c , player );

                } else {
                    
                    int col_c = computerchoice ( grid );                
                    std :: cout << col_c << std :: endl;
                    checking = playTurn(grid, col_c , player) ;

                }
                
                if (player == 1) player = 2;
                else player = 1;
                
                }else {

                std :: cin >> choix;

                if (choix == "exit"){
                    system("CLS");
                    break;
                }

                    bool success = false;
                    
                   

                if (choix.size() == 1){
                    if (choix[0] >= '0' && choix[0] <= '7'){
                    int col = choix[0]  - '0';
                
                    success = playTurn(grid, col, player);
                    checker = checkvictory (grid , player);

                    }
                }

                system("CLS");

                if (!success){
                std::cout << "votre choix est incorrect\n";
                } else{
                    if (player == 1) player = 2;
                else player = 1;
                }

            }

            if ( checker == true ){
                    if ( player == 1) {
                    std :: cout << "le joueur "<< player + 1 << " a gagne"<< std :: endl;
                    } else {
                    std :: cout << "le joueur "<< player - 1 << " a gagne"<< std :: endl;
                    }
                    drawGrid(grid);
                    break;
                }
        
            drawGrid(grid);

        }
    }


    return 0;
}




// 0, 1, 2
void drawGrid(int grid[7][6]){
    for (int ligne = 0; ligne < 6; ligne++){
        std::cout << "|";
        for (int col = 0; col < 7; col++){
            if (grid[col][ligne] == 1){
                std::cout << "\033[31m*\033[37m";
            } else 
            if (grid[col][ligne] == 2){
                std::cout << "\033[32m*\033[37m";
            }
            else {
                std::cout << "\033[37m*\033[37m";
            }
            std::cout << "|";
        }
        std::cout << "\n";
    }
}

bool playTurn(int grid[7][6], int column, int player){
    for (int line = 5 ; line >= 0; line--){
        if (grid[column - 1][line] == 0){
            grid[column - 1][line] = player;
            return true;
        }
    }
    return false;
}

bool checkvictory ( int grid[7][6], int player){

     for ( int line = 0 ; line < 6 ; line++){
        for ( int column = 0 ;column < 4 ; column++){
            //permet la verification horizontale
            if ( grid[line][column] == player && grid[line][column+1] == player && grid[line][column+2] == player && grid[line][column+3] == player ){
                return true;
            }
        }
     }
     for ( int line = 0 ; line < 3 ; line++){
        for ( int column = 0 ;column < 7 ; column++){
            //on verifie l'alignement des points à la verticale
            if ( grid[line][column] == player && grid[line+1][column] == player && grid[line+2][column] == player && grid[line+3][column] == player ){
                return true;
            }
        }
    }
    for ( int line = 0 ; line < 3 ; line++){
        for ( int column = 0 ;column < 4 ; column++){
            //on verifie l'alignement des points sur la diagonale ascendante
            if ( grid[line][column] == player && grid[line+1][column+1] == player && grid[line+2][column+2] == player && grid[line+3][column+3] == player ){
                return true;
            }
        }
    }
    for ( int line = 0 ; line < 4 ; line++){
        for ( int column = 5 ; column > 2 ; column--){
            //on verifie l'alignement des points sur la diagonale descendante
            if ( grid[line][column] == player && grid[line+1][column-1] == player && grid[line+2][column-2] == player && grid[line+3][column-3] == player ){
                    return true;
            }
        }
    }
    return false;
}

int computerchoice( int grid[7][6]){
    int col_computer ; 
    do {
        col_computer = rand() % 8 ;
        if ( col_computer == 0){
            col_computer = col_computer + 1 ;
        }

    } while ( grid[col_computer][0] != 0) ; //on verifie si la colonne n'est pas deja rempli
    return col_computer;
}



int prevision ( int grid[7][6], int player){

    for ( int line = 0 ; line < 6 ; line++){
        for ( int column = 1 ;column < 4 ; column++){
            //permet la verification horizontale
            if ( grid[line][column] == player && grid[line][column+1] == player && grid[line][column+2] == player && grid[line][column+3] == 0 ){
                return column + 3 ;
            }
            if ( grid[line][column] == player && grid[line][column+1] == player && grid[line][column+2] == 0 && grid[line][column+3] == player){
                return column + 2;
            }
            if ( grid[line][column] == player && grid[line][column+1] == 0 && grid[line][column+2] == player && grid[line][column+3] == player){
                return column + 1;
            }
            if (grid[line][column] == player && grid[line][column-1] == 0 && grid[line][column+2] == player && grid[line][column+3] == player){
                return column - 1;
            }
        }
    }
    for ( int line = 1 ; line < 3 ; line++){
        for ( int column = 1 ;column < 4 ; column++){
            //on verifie l'alignement des points sur la diagonale ascendante
            if ( grid[line][column] == player && grid[line+1][column+1] == player && grid[line+2][column+2] == player && grid[line+3][column+3] == 0 && grid[line+2][column+3] != 0){
                return column+3;
            }
            if ( grid[line][column] == player && grid[line+1][column+1] == player && grid[line+2][column+2] == 0 && grid[line+3][column+3] == player && grid[line+1][column+2] != 0){
                return column+2;
            }
            if ( grid[line][column] == player && grid[line+1][column+1] == 0 && grid[line+2][column+2] == player && grid[line+3][column+3] == player && grid[line][column+1] != 0){
                return column+1;
            }
            if ( grid[line][column] == player && grid[line-1][column+1] == 0 && grid[line+2][column+2] == player && grid[line+3][column+3] == player && grid[line-1][column-1] != 0 ){
                return column-1;
            }
        }
    }
    return 6;

}

