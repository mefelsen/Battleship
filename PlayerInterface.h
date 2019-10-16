#ifndef PLAYER_INTERFACE
#define PLAYER_INTERFACE

class PlayerInterface
{
  public:
    virtual ~PlayerInterface() {}

    virtual void setNum(int x) = 0;

    virtual void placement(int x, int y, int z) = 0;

    virtual void print() = 0;

    virtual bool isAllMarked() = 0;

    virtual int getHits() = 0;

    virtual void printHidden() = 0;

    virtual void update(int, int, bool) = 0;

    virtual int getMarks() = 0;

    virtual bool hitRetry(int x, int y) = 0;
};
#endif
