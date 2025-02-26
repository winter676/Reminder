#include <stdio.h>
#include <stdlib.h>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

#define BLOCK_SIZE 30   // 方块大小
#define WINDOW_WIDTH 800 // 窗口宽度
#define WINDOW_HEIGHT 600 // 窗口高度

// 游戏区域的行列数
#define FIELD_WIDTH 10
#define FIELD_HEIGHT 20

// 方块的颜色
typedef enum {
    RED,
    GREEN,
    BLUE,
    YELLOW,
    CYAN,
    MAGENTA,
    WHITE,
} Color;

// 方块的形状
const int shapes[7][4][2] = { // 每种方块包含4个坐标点，每个坐标点为dx和dy（相对左上角的位置）
    {{0, 0}, {1, 0}, {0, 1}, {1, 1}},   // I
    {{0, 0}, {0, 1}, {1, 0}, {1, 1}},   // O
    {{0, 0}, {1, 0}, {2, 0}, {3, 0}},   // T
    {{0, 0}, {0, 1}, {1, 0}, {1, 1}},   // S
    {{0, 0}, {-1, 0}, {-1, 1}, {0, 1}}, // Z
    {{0, 0}, {0, 1}, {0, -1}, {1, 1}},  // L
    {{0, 0}, {0, 1}, {0, 2}, {1, 1}}   // J
};

int main() {
    // 初始化 SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "Failed to initialize SDL\n");
        return EXIT_FAILURE;
    }

    // 创建窗口
    SDL_Window *window = NULL;
    window = SDL_CreateWindow(
        "俄罗斯方块",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
        0
    );

    if (!window) {
        fprintf(stderr, "Failed to create window\n");
        SDL_Quit();
        return EXIT_FAILURE;
    }

    // 创建图像表面
    SDL_Renderer *renderer = NULL;
    renderer = SDL_CreateRenderer(window, -1,SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        fprintf(stderr, "Failed to create renderer\n");
        SDL_DestroyWindow(window);
        SDL_Quit();
        return EXIT_FAILURE;
    }

    // 游戏区域，用来记录每个方块的颜色
    Color field[FIELD_HEIGHT][FIELD_WIDTH];
    for (int i = 0; i < FIELD_HEIGHT; ++i) {
        for (int j = 0; j < FIELD_WIDTH; ++j) {
            field[i][j] = WHITE;
        }
    }

    // 当前下落的方块信息
    Color current_color;
    int shape_index, pos_x, pos_y;

    // 初始化游戏区域
    void draw_field() {
        for (int i = 0; i < FIELD_HEIGHT; ++i) {
            for (int j = 0; j < FIELD_WIDTH; ++j) {
                if (field[i][j] != WHITE) {
                    // 绘制方块
                    SDL_Rect rect;
                    rect.x = j * BLOCK_SIZE;
                    rect.y = i * BLOCK_SIZE;
                    rect.w = BLOCK_SIZE - 1;
                    rect.h = BLOCK_SIZE - 1;

                    switch(field[i][j]) {
                        case RED: SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); break;
                        case GREEN:SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); break;
                        case BLUE:SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); break;
                        case YELLOW:SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255); break;
                        case CYAN: SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255); break;
                        case MAGENTA:SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255); break;
                        default:SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                    }
                    SDL_RenderFillRect(renderer, &rect);
                }
            }
        }
    }

    // 绘制当前方块
    void draw_current() {
        for (int i = 0; i < 4; ++i) {
            int dx = shapes[shape_index][i][0];
            int dy = shapes[shape_index][i][1];
            int x = pos_x + dx;
            int y = pos_y + dy;

            if (x >= 0 && x < FIELD_WIDTH && y >= 0 && y < FIELD_HEIGHT) {
                SDL_Rect rect;
                rect.x = (pos_x + dx) * BLOCK_SIZE;
                rect.y = (pos_y + dy) * BLOCK_SIZE;
                rect.w = BLOCK_SIZE - 1;
                rect.h = BLOCK_SIZE - 1;

                switch(current_color) {
                    case RED:SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); break;
                    case GREEN:SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); break;
                    case BLUE:SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); break;
                    case YELLOW:SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255); break;
                    case CYAN: SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255); break;
                    case MAGENTA:SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255); break;
                    default:SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                }
                SDL_RenderFillRect(renderer, &rect);
            }
        }
    }

    // 检测碰撞
    bool collision() {
        for (int i = 0; i < 4; ++i) {
            int dx = shapes[shape_index][i][0];
            int dy = shapes[shape_index][i][1];
            int x = pos_x + dx;
            int y = pos_y + dy;

            if (x < 0 || x >= FIELD_WIDTH || y >= FIELD_HEIGHT) return true;
            if (field[y][x] != WHITE) return true;
        }
        return false;
    }

    // 消除行
    void remove_row() {
        int row = pos_y;
        for (; row >= 0; --row) {
            bool full = true;
            for (int j = 0; j < FIELD_WIDTH; ++j) {
                if (field[row][j] == WHITE) {
                    full = false;
                    break;
                }
            }
            if (full) {
                // 消除该行
                for (int j = 0; j < FIELD_WIDTH; ++j) {
                    field[row][j] = WHITE;
                }
                pos_y--;
                row++;
            }
        }
    }

    // 初始化当前方块
    void new_shape() {
        current_color = (Color)(rand() % 6);
        shape_index = rand() % 6;

        pos_x = FIELD_WIDTH / 2 - 1;
        pos_y = 0;

        for (int i = 0; i < 4; ++i) {
            int dx = shapes[shape_index][i][0];
            int dy = shapes[shape_index][i][1];
            if (pos_x + dx < 0 || pos_x + dx >= FIELD_WIDTH || pos_y + dy >= FIELD_HEIGHT ||
                field[pos_y + dy][pos_x + dx] != WHITE) {
                pos_x += 2;
                if (pos_x >= FIELD_WIDTH) {
                    // 游戏结束
                    return;
                }
            }
        }
    }

    bool game_over = false;

    new_shape();

    while (!game_over) {
        SDL_RenderClear(renderer);
        draw_field();
        draw_current();

        // 处理事件
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_KEYDOWN) {
                switch(event.key.keysym.sym) {
                    case SDLK_LEFT:
                        pos_x--;
                        if (collision()) pos_x++;
                        break;
                    case SDLK_RIGHT:
                        pos_x++;
                        if (collision()) pos_x--;
                        break;
                    case SDLK_DOWN:
                        pos_y++;
                        if (collision()) pos_y--;
                        break;
                    case SDLK_UP:
                        // 旋转方块
                        shape_index = (shape_index + 1) % 6;
                        if (collision()) shape_index = (shape_index - 1) % 6;
                        break;
                }
            }
        }

        // 自动下落
        pos_y++;
        if (collision()) {
            pos_y--;
            remove_row();
            new_shape();
            if (!new_shape()) {
                game_over = true;
            }
        }

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    return 0;
}