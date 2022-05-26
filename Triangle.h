/*Copyright 2022 Mandar Kapadia */
#ifndef _USERS_MANDARKAPADIA_PROGRAMMING_C_C___COMPUTING_4_PS3_TRIANGLE_H_
#define _USERS_MANDARKAPADIA_PROGRAMMING_C_C___COMPUTING_4_PS3_TRIANGLE_H_

#include <SFML/System.hpp>//NOLINT
#include <SFML/Window.hpp>//NOLINT
#include <SFML/Graphics.hpp>//NOLINT
#include <SFML/Audio.hpp>//NOLINT
#include<iostream>//NOLINT
#include<string>//NOLINT
#include<memory>//NOLINT
#include<vector>//NOLINT
#include<math.h>//NOLINT

class Triangle:public sf::Drawable{
 public:
        Triangle(int _xPostion , int _yPosition , int _xLength
        , int _yLength , int _depth);
        int getDepth()const;
        double getXlength()const;
        double getYlength()const;
        int getXposition()const;
        int getYposition()const;

        void setDepth(const int depth);
        void setXlength(const double xLength);
        void setYlength(const double yLength);
        void setXposition(const int xPosition);
        void setYposition(const int yPositsion);

 private:
        int depth;
        double xLength;
        double yLength;
        int xPosition;
        int yPosition;
        void draw(sf::RenderTarget& target , sf::RenderStates states)
        const override;
};
#endif  // _USERS_MANDARKAPADIA_PROGRAMMING_C_C___COMPUTING_4_PS3_TRIANGLE_H_"
