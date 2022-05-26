/*Copyright 2022 Mandar Kapadia */
#include "Triangle.h"

Triangle::Triangle(int _xPosition , int _yPosition ,
 int _xLength , int _yLength , int _depth) {
    this->depth = _depth;
    xLength = _xLength;
    yLength = _yLength;
    xPosition = _xPosition;
    yPosition = _yPosition;
}
double Triangle::getXlength()const {
    return(xLength);
}
double Triangle::getYlength()const {
    return(yLength);
}
int Triangle::getDepth()const {
    return(depth);
}
int Triangle::getXposition()const {
    return(xPosition);
}
int Triangle::getYposition()const {
    return(yPosition);
}

void Triangle::setXlength(const double xLength) {
    this->xLength = xLength;
}
void Triangle::setYlength(const double yLength) {
    this->yLength = yLength;
}
void Triangle::setDepth(const int depth) {
    this->depth = depth;
}
void Triangle::setXposition(const int xPosition) {
    this->xPosition = xPosition;
}
void Triangle::setYposition(const int xPosition) {
    this->yPosition = xPosition;
}
void Triangle::draw(sf::RenderTarget& target, sf::RenderStates states)const {
    if (this->depth > 0) {
        sf::VertexArray line(sf::Lines , 2);
        line[0].position = sf::Vector2f(xPosition , yPosition);
        line[1].position = sf::Vector2f(xPosition+xLength , yPosition+yLength);
        line[1].color = sf::Color::Blue;
        line[0].color = sf::Color::White;
        target.draw(line , states);
        return;
    }
    sf::VertexArray triangle(sf::LineStrip , 4);
    triangle[0].position = sf::Vector2f(xPosition , yPosition);
    triangle[0].color = sf::Color::Red;
    triangle[1].position = sf::Vector2f(xPosition+xLength
    , yPosition+yLength);
    triangle[1].color = sf::Color::Cyan;
    triangle[2].position = sf::Vector2f(xPosition+xLength/2
    , yPosition+xLength/2+(xLength/2/sqrt(3)));
    triangle[2].color = sf::Color::Green;
    triangle[3].position = sf::Vector2f(xPosition , yPosition);
    triangle[3].color = sf::Color::Yellow;
    target.draw(triangle , states);
    return;
}
