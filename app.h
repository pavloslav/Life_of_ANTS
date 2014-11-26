#ifndef APP_H
#define APP_H

#include <memory>

#include "graphics.h"
#include "scene.h"

#define VERSION "0.013"
#define DELAY   20

class App
{
public:
    static const std::shared_ptr<App> &getApp();
    void init();
    void mainCycle();
    void processEvents();
    void action();
    void draw();
    bool isQuiting;
    const std::shared_ptr<Graphics>& getGraphics() { return graphics; }
    const std::shared_ptr<Scene>& getScene() { return scene; }

private:
    App();
    static std::shared_ptr<App> instance;
    std::shared_ptr<Graphics> graphics;
    std::shared_ptr<Scene> scene;
};

#endif // APP_H
