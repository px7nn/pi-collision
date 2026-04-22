#include "raylib.h"
#include <stdio.h>

#define WIDTH 1080
#define HEIGHT 420
#define BASE_Y HEIGHT*0.75


typedef struct { // { size, mass, posX, velocityX }
    const unsigned int s, m;
    float x;
    float vx;
}Block; 


Block a = {50, 1, 170, 0.0f}, b = {100, 100000000, 420, -100.0f};

int col_count;

void init(){
    col_count = 0;
}

const char *text_to_string(){
    static char str[64];
    sprintf(str, "Collisions: %d", col_count);
    return str;
}


void draw_wall(){
    DrawLine(50, 50, 50, BASE_Y, RED); // Vertical 
    DrawLine(50, BASE_Y, WIDTH, BASE_Y, RED); // Horizontal
}

void draw_blocks(Block *block, Color col){
    int y = BASE_Y - block->s;
    int x = block->x;
    DrawRectangle(x, y, block->s, block->s, col);
}

void collision(){
    if(b.x <= a.x + a.s && a.vx > b.vx){ // block collision
        col_count++;
        float u1 = a.vx, u2 = b.vx;
        a.vx = ((((float)a.m - b.m)/(a.m + b.m)) * u1) + (((2.0f * b.m)/(a.m + b.m)) * u2);
        b.vx = (((2.0f * a.m)/(a.m + b.m)) * u1) + ((((float)b.m - a.m)/(a.m + b.m)) * u2);
    }

    if(a.x <= 50 && a.vx < 0) { // wall collision
        col_count++;
        a.x = 50;
        a.vx = -a.vx;
    }
}

void move_blocks(float dt){
    a.x += dt * a.vx;
    b.x += dt * b.vx;
}

int main(){
    init();

    InitWindow(WIDTH, HEIGHT, "PI-Collision");
    SetTargetFPS(60);
    
    while(!WindowShouldClose()){

        int steps = 20000;
        float steps_dt = GetFrameTime()/steps;

        for(int i=0; i < steps; i++){
            collision();
            move_blocks(steps_dt);
        }

        BeginDrawing();
            ClearBackground(BLACK);

            draw_wall();
            draw_blocks(&a, GRAY); draw_blocks(&b, WHITE);
            DrawText(text_to_string(), 150, 60, 24, WHITE);

        EndDrawing();

    }

    CloseWindow();

    return 0;
}