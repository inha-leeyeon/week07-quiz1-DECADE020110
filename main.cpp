#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>

#include "Point.h"
#include "Square.h"

using namespace std;

Point::Point(int px, int py)
{
    setX(px);
    setY(py);
}

int Point::getX() const { return x; }
int Point::getY() const { return y; }
void Point::setX(int x) { this->x = x; }
void Point::setY(int y) { this->y = y; }

Square::Square(const string name, int px, int py, unsigned int side)
    : Point(px, py)
{
    setName(name);
    setSide(side);
    setArea(side);
}

unsigned int Square::getSide() const { return side; }
unsigned int Square::getArea() const { return area; }
string Square::getName() const { return name; }

void Square::setSide(unsigned int side)
{
    this->side = side;
}

void Square::setArea(unsigned int side)
{
    area = side * side;
}

void Square::setName(string name) { this->name = name; }

int main(void)
{
    int input, px, py;
    unsigned int side;
    string name;
    vector<Square> squares;

    if (!(cin >> input)) return 0;

    for (int i = 0; i < input; ++i)
    {
        cin >> name >> px >> py >> side;
        squares.emplace_back(Square(name, px, py, side));
    }

    sort(squares.begin(), squares.end(),
        [](const Square& a, const Square& b) {
            return a.getArea() < b.getArea();
        });

    cout << "Squares in increasing order of area\n";
    for (const auto& sq : squares)
    {
        cout << sq.getName() << "(" << sq.getX() << ", " << sq.getY() << ") side="
            << sq.getSide() << ", area=" << sq.getArea() << '\n';
    }

    sort(squares.begin(), squares.end(),
        [](const Square& a, const Square& b) {
            int aMaxX = a.getX() + static_cast<int>(a.getSide());
            int bMaxX = b.getX() + static_cast<int>(b.getSide());
            if (aMaxX != bMaxX) return aMaxX < bMaxX;
            if (a.getArea() != b.getArea()) return a.getArea() < b.getArea();
            if (a.getX() != b.getX()) return a.getX() < b.getX();
            return a.getY() < b.getY();
        });

    cout << "\nSquares in increasing order of max x-coordinate\n";
    for (const auto& sq : squares)
    {
        int maxX = sq.getX() + static_cast<int>(sq.getSide());
        cout << sq.getName() << "(" << maxX << ", " << sq.getY() << ") side="
            << sq.getSide() << ", area=" << sq.getArea() << '\n';
    }

    sort(squares.begin(), squares.end(),
        [](const Square& a, const Square& b) {
            int aMaxY = a.getY() + static_cast<int>(a.getSide());
            int bMaxY = b.getY() + static_cast<int>(b.getSide());
            if (aMaxY != bMaxY) return aMaxY < bMaxY;
            if (a.getArea() != b.getArea()) return a.getArea() < b.getArea();
            if (a.getY() != b.getY()) return a.getY() < b.getY();
            return a.getX() < b.getX();
        });

    cout << "\nSquares in increasing order of max y-coordinate\n";
    for (const auto& sq : squares)
    {
        int maxY = sq.getY() + static_cast<int>(sq.getSide());
        
        cout << sq.getName() << "(" << sq.getX() << ", " << maxY << ") side="
            << sq.getSide() << ", area=" << sq.getArea() << '\n';
    }

    return 0;
}
