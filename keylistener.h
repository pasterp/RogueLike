#ifndef KEYLISTENER_H
#define KEYLISTENER_H


class keyListener
{
public:
    keyListener();

    virtual void keyPressed(int key) = 0;
};

#endif // KEYLISTENER_H
