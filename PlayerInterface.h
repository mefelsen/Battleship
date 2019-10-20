#ifndef PLAYER_INTERFACE
#define PLAYER_INTERFACE

class PlayerInterface //Interface class for both HumanPlayer and AI to implement from.
{
  public:
    virtual ~PlayerInterface() {}

   /**
    *@pre takes in a integer x
    *@post set up # of ships and set those ships are unmark
    *@param None.
    *@return None. */
    virtual void setNum(int x) = 0;

   /**
    *@pre take in three integers x is row, y is col, z is the direction(1~4)
    *@post throw a error when the direction is wrong and catch a error when placment fails
    *@param None.
    *@return None. */
    virtual void placement(int x, int y, int z) = 0;

   /**
    *@pre None
    *@post None.
    *@param None.
    *@return True if all ships marked, false otherwise. */
    virtual bool isAllMarked() = 0;

   /**
    *@pre Gets the number of times a player has hit the enemies's ships
    *@post None.
    *@param None.
    *@return # of ship parts remaining */
    virtual int getHits() = 0;

   /**
    *@pre calls the board class to compare char and attck if match is found
    *@post handles the attack/comparison
    *@param  takes in the x and y coordiinate of where the player would like to attack
    *@return True if can attack at [row][col], false otherwise. */
    virtual bool attack(int x, int y) = 0;

   /**
    *@pre calls the board class to compare char and update the board
    *@post handles the attack/comparison
    *@param  takes in the x and y coordiinate of where the player would like to attack
      the bool is for determining if it was a success or not -- "x" or "o"
    *@return None. */
    virtual void update(int, int, bool) = 0;

   /** retry if you've already shot at the same location twice
    *@pre none
    *@post checks to see if a space has already been hit or not.
    *@param  takes in the x and y coordiinate of where the player would like to attack
    *@return true if spot has been hit before, false otherwise */
    virtual bool hitRetry(int x, int y) = 0;
};
#endif
