#ifndef SQUARE_H
#define SQUARE_H

#include <string>
#include "Point.h"

class Square : public Point 
{
public:
    Square(const std::string, int, int, unsigned int = 0);
    unsigned int getSide() const;
    unsigned int getArea() const;
    std::string getName() const;
    void setSide(unsigned int);
    void setArea(unsigned int);
    void setName(std::string);
    void printAll();
private:
    unsigned int side;
    unsigned int area{ 0 };
    std::string name;
};

#endif // !SQUARE_H