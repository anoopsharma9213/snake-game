#ifndef GAME_H
#define GAME_H

class CGame
{
public:
    CGame();
    ~CGame();

	void mainPage();

	void mainPageUpdate();

	void reset();

    // update will be called a fixed number of times per second
    // regardless of visual framerate
    void Update();
    // render will be called as fast as possible (but not faster
    // than the update rate)
    void Render();

private:
    CIwFVec2 f_Position;
    CIwFVec2 f_Size;
};

#endif
