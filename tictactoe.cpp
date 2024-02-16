#include <iostream>
#include <array>
#include <stdlib.h> 
using namespace std;
int computer_move_count = 0;

void display_tic(char tictaetoe[3][3], int size_of_arr){
    for(int i=0; i<size_of_arr; i++){
        for(int j=0; j<size_of_arr; j++){
            cout << tictaetoe[i][j] << " ";
        }   
        cout << endl;
    }
}

bool game_not_over(char tictaetoe[3][3], int size_of_arr){

return true;
}

void update_tictatoe(char tictaetoe[3][3], int m, int n){
    tictaetoe[m][n] = 'X';
}

bool is_valid_move(char tictaetoe[3][3], int m, int n){
    if(m <= 3 && m > 0 && n <= 3 && n > 0){
        if(tictaetoe[m][n] == '-'){
            return true;
        }
        return false;
    }
    return false;
}

void computer_move(char tictaetoe[3][3], int size_of_arr, int m, int n){
    if(computer_move_count == 0) {
        int random_row = rand() % 3;
        int random_col = rand() % 3;
        while(random_row == m || random_col == n){
            random_row = rand() % 3;
            random_col = rand() % 3;
        }
        tictaetoe[random_row][random_col] = 'O';
    }
    else {
        //logic
    }
    display_tic(tictaetoe, size_of_arr);
}

int main(){
    char tictaetoe[3][3] = {{'-', '-', '-'}, {'-', '-', '-'}, {'-', '-', '-'}};    
    int size_of_arr = 3;
    int m, n;

    while(game_not_over(tictaetoe, size_of_arr)){
        cout << "enter your move: ";
        cin >> m >> n;
        cout << "\n";
        if(is_valid_move(tictaetoe, m, n)){
            update_tictatoe(tictaetoe, m-1, n-1);
        }else{
            cout << "enter vals within range" << endl;
        }
        display_tic(tictaetoe, size_of_arr);
        cout << "\n\n" << "computer's move: " << "\n" << endl;
        computer_move(tictaetoe, size_of_arr, m, n);
    }

return 0;
}