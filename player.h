#ifndef PLAYER_H
#define PLAYER_H



class Player
{
public:
    Player();
    static int Getdollar(){return _dollar;}
    static int Getdiamond(){return _diamond;}
    static void dollarMinus();
    static void dollarPlus();
    static void diamondMinus();
    static void diamondPlus();
private:
    static int _dollar,_diamond;
};

#endif // PLAYER_H
