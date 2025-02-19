#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "control.h"
#include "visualization.h"

// Funcao para criar a matrix
void create_matrix(char matrix[25][80]){
    for(int x = 0; x < 25; x++) {
        for(int y = 0; y < 80; y++){
            matrix[x][y] = ' ';
        }
    }
}

// Funcao para adicionar um retangulo ao array
Rectangle* add_rectangle(Rectangle *rectangles, int *size, Rectangle newRectangle, int *error){
    Rectangle *temp = realloc(rectangles, (*size + 1) * sizeof(Rectangle));
    if(temp == NULL){
        *error = 5; // Erro a alocar memoria
        return rectangles;
    }
    rectangles = temp;
    rectangles[*size] = newRectangle;
    (*size)++;
    *error = 0; // Sucesso
    return rectangles;
}

// Funcao para aplicar gravidade ao retangulo
void gravity(char matrix[25][80], Rectangle *rect){
    int drop = 1;
    while(drop && rect->y > 1){
        int y = 25 - rect->y; // Verifica a linha logo abaixo do retangulo
        for(int i = 0; i < rect->w; i++){
            int x = rect->x + i - 1;
            if(y < 0 || y >= 25 || x < 0 || x >= 80 || matrix[y + 1][x] == 'X'){ // Verifica se ha um retangulo abaixo
                drop = 0;
                break;
            }
        }
        if(drop){
            rect->y -= 1; // Desce o retangulo uma linha
        }
    }
}

// Funcao para verificar se as coordenadas introduzidas pertencem a determinado retangulo (parte interior tambem)
int coord_belong_rectangle(int x, int y, Rectangle rect){
    return(x >= rect.x && x < rect.x + rect.w && y >= rect.y && y < rect.y + rect.h);
}

// Funcao para mover um retangulo para a direita
int moveright(Rectangle *rectangles, int size, int x, int y, int p, char matrix[25][80]){
    for(int i = 0; i < size; i++){
        if(coord_belong_rectangle(x, y, rectangles[i])){
            // Verificar se pode mover para a direita
            for(int j = 0; j < rectangles[i].h; j++){
                int novo_x = rectangles[i].x + rectangles[i].w + p - 2; // -1 para ajustar devido a matriz estar indexada a partir de 0 e outro -1 para logica da soma entre numeros
                if(novo_x >= 80 || matrix[25 - (rectangles[i].y + j)][novo_x] != ' '){
                    return 7; // Nao pode mover para a direita
                }
            }
            // Atualizar a matrix removendo o retangulo da posicao antiga
            for(int j = 0; j < rectangles[i].h; j++){
                for(int k = 0; k < rectangles[i].w; k++){
                    int y_pos = 25 - (rectangles[i].y + j);
                    int x_pos = rectangles[i].x + k - 1;
                    matrix[y_pos][x_pos] = ' ';
                }
            }
            // Atualizar a posicao do retangulo
            rectangles[i].x += p;
            // Desenhar o retangulo na nova posicao
            gravity(matrix, &rectangles[i]); // Aplica a gravidade ao retangulo apos o movimento
            print_rectangle(matrix, rectangles[i]); // Imprimir retangulo na matriz
            return 0; // Sucesso 
        }
    }
    return 3; // coordenadas ou dimencoes invalidas
}

// Funcao para mover um retangulo para a esquerda
int moveleft(Rectangle *rectangles, int size, int x, int y, int p, char matrix[25][80]){
    for (int i = 0; i < size; i++){
        if (coord_belong_rectangle(x, y, rectangles[i])){
            // Verificar se pode mover para a esquerda
            for(int j = 0; j < rectangles[i].h; j++){
                int novo_x = rectangles[i].x - p - 1; // -1 para ajustar devido a matriz estar indexada a partir de 0
                if(novo_x < 0 || matrix[25 - (rectangles[i].y + j)][novo_x] != ' '){
                    return 7; // Nao pode mover para a esquerda
                }
            }
            // Atualizar a matrix removendo o retangulo da posicao antiga
            for(int j = 0; j < rectangles[i].h; j++){
                for(int k = 0; k < rectangles[i].w; k++){
                    int y_pos = 25 - (rectangles[i].y + j);
                    int x_pos = rectangles[i].x + k - 1;
                    matrix[y_pos][x_pos] = ' ';
                }
            }
            // Atualizar a posicao do retangulo
            rectangles[i].x -= p;
            // Desenhar o retangulo na nova posicao
            gravity(matrix, &rectangles[i]); // Aplica a gravidade ao retangulo apos o movimento
            print_rectangle(matrix, rectangles[i]); // Imprimir retangulo na matriz
            return 0; // Sucesso
        }
    }
    return 3; // coordenadas ou dimencoes invalidas
}

// Funcao para procurar possiveis merge
int search_merge_poss(Rectangle *rectangles, int size, int *r1_index, int *r2_index){
    for(int i = 0; i < size; i++){
        for(int j = i + 1; j < size; j++){
            if(rectangles[i].x == rectangles[j].x && rectangles[i].w == rectangles[j].w){
                *r1_index = i;
                *r2_index = j;
                return 1; //encontrou dois rectangles possiveis de merge

            }
        }
    }
    return 0; // Nenhum merge possivel
}

// Funcao para fundir de dois retangulos
void merge(Rectangle *rectangles, int *size, int r1_x, int r1_y, int r2_x, int r2_y, int *error){
    int r1_index = -1, r2_index = -1;
    for(int i = 0; i < *size; i++){
        if(coord_belong_rectangle(r1_x, r1_y, rectangles[i])){
            r1_index = i;
        }
        if(coord_belong_rectangle(r2_x, r2_y, rectangles[i])){
            r2_index = i;
        }
    }
    if(r1_index != -1 && r2_index != -1 && r1_index != r2_index){
        rectangles[r1_index].h += rectangles[r2_index].h;  // Funde os dois retangulos
        // Remove r2 da lista
        for(int i = r2_index; i < *size - 1; i++){
            rectangles[i] = rectangles[i + 1];
        }
        (*size)--;
        *error = 0;  // Sucesso
    } else{
        *error = 6;  // merge invalido
    }
}  

// Funcao para certificar se nao estamos a fazer merge do mesmo retangulo
int itself_rectangle(Rectangle r1, Rectangle r2){
    return(r1.x == r2.x && r1.y == r2.y && r1.w == r2.w && r1.h == r2.h);
}
