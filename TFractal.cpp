/*Copyright 2022 Mandar Kapadia */
#include"Triangle.h"
void fTree(Triangle t , sf::RenderWindow& window);
int main(int argc , char* argv[]) {
    int depth = atol(argv[2]);
    double length  = atol(argv[1]);
    int size = (length*depth)+500;
    sf::RenderWindow window(sf::VideoMode(size, size), "window");
    Triangle t((size/4) , (size/4) , length , 0 , depth);
    sf::Music music;
    // if (!music.openFromFile("Rocky_theme_song.wav"))
    //    return(-1);
    // music.setLoop(1);
    // music.play();
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        fTree(t , window);
        window.display();
        }

    return 0;
}


void fTree(Triangle t , sf::RenderWindow& window) {
    if (t.getDepth() == 0) {
       window.draw(t);
       return;
    } else {
        int xPos = t.getXposition();
        int yPos = t.getYposition();
        int xlength = t.getXlength();
        int ylength = t.getYlength();

        fTree(Triangle(t.getXposition()-t.getXlength()/4 , t.getYposition()
        -t.getXlength()/2.5 -(ylength/2/sqrt(3)/2), t.getXlength()/2
        , t.getYlength()/2 , t.getDepth()-1),
        window);

        window.draw(t);
        t.setXposition(xPos+t.getXlength());

        fTree(Triangle(t.getXposition() , t.getYposition(),
        t.getXlength()/2 , t.getYlength()/2 , t.getDepth()-1) , window);

        t.setXlength(-xlength/2);
        t.setYlength(xlength/2+(xlength/2/sqrt(3)/2));

        window.draw(t);

        t.setXlength(xlength);
        t.setYlength(ylength);
        t.setXposition(t.getXposition()-xlength- xlength/4);
        t.setYposition(t.getYposition()+xlength/2+(xlength/2/sqrt(3)/2));

         fTree(Triangle(t.getXposition()+xlength/4, t.getYposition()
         , t.getXlength()/2 , t.getYlength()/2 , t.getDepth()-1) , window);


         t.setXposition(xPos+xlength/2);
         t.setYposition(yPos+xlength/2+(xlength/2/sqrt(3)/2));
         t.setXlength(-xlength/2);
         t.setYlength(-1*(xlength/2+(xlength/2/sqrt(3)/2)));
         window.draw(t);
        return;
    }
}
