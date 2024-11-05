#ifndef __GAME__
    #define __GAME__

    void draw_grid(int grid[7][6]);

    bool victory(int grid[7][6], int player);

    bool egality(int grid[7][6]);

    void p_turn(int grid[7][6], int player, int positionnement);

    int ai_turn(int grille[7][6]);

    int alea (int grid[7][6]);
#endif