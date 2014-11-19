#ifndef BLOCK_H
#define BLOCK_H

class Scene;

class Block {
public:
    static Scene *mainScene;
        int x;
        int y;
        Block( );

void draw();
};

#endif // BLOCK_H
