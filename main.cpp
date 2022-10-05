#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
using namespace sf;

class Img : public Sprite
{
public:
    std::string name;
};

int main()
{

    RenderWindow window(VideoMode(900, 630), "Slot machine");
    Clock clock;

    Image machineImage;
    machineImage.loadFromFile("images/machine.png");
    Texture machineTexture;
    machineTexture.loadFromImage(machineImage);
    Sprite machineSprite;
    machineSprite.setTexture(machineTexture);
    machineSprite.setPosition(20, 15);

    Image startImage;
    startImage.loadFromFile("images/start.png");
    Texture startTexture;
    startTexture.loadFromImage(startImage);
    Sprite startSprite;
    startSprite.setTexture(startTexture);
    startSprite.setPosition(580, 250);

    Image stopImage;
    stopImage.loadFromFile("images/stop.png");
    Texture stopTexture;
    stopTexture.loadFromImage(stopImage);
    Sprite stopSprite;
    stopSprite.setTexture(stopTexture);
    stopSprite.setPosition(580, 480);

    Image starImage;
    starImage.loadFromFile("images/star.png");
    Texture starTexture;
    starTexture.loadFromImage(starImage);
    Img starSprite;
    starSprite.setTexture(starTexture);
    starSprite.setPosition(30, 25);
    starSprite.name = "star";

    Image arrowImage;
    arrowImage.loadFromFile("images/arrow.png");
    Texture arrowTexture;
    arrowTexture.loadFromImage(arrowImage);
    Img arrowSprite;
    arrowSprite.setTexture(arrowTexture);
    arrowSprite.setPosition(30, 175);
    arrowSprite.name = "arrow";

    Image cloudImage;
    cloudImage.loadFromFile("images/cloud.png");
    Texture cloudTexture;
    cloudTexture.loadFromImage(cloudImage);
    Img cloudSprite;
    cloudSprite.setTexture(cloudTexture);
    cloudSprite.setPosition(30, 325);
    cloudSprite.name = "cloud";

    Image triangleImage;
    triangleImage.loadFromFile("images/triangle.png");
    Texture triangleTexture;
    triangleTexture.loadFromImage(triangleImage);
    Img triangleSprite;
    triangleSprite.setTexture(triangleTexture);
    triangleSprite.setPosition(30, 475);
    triangleSprite.name = "triangle";

    //Картинки на втором барабане
    Texture triangleTexture2;
    triangleTexture2.loadFromImage(triangleImage);
    Img triangleSprite2;
    triangleSprite2.setTexture(triangleTexture2);
    triangleSprite2.setPosition(202, 25);
    triangleSprite2.name = "triangle";

    Texture cloudTexture2;
    cloudTexture2.loadFromImage(cloudImage);
    Img cloudSprite2;
    cloudSprite2.setTexture(cloudTexture2);
    cloudSprite2.setPosition(202, 175);
    cloudSprite2.name = "cloud";

    Texture starTexture2;
    starTexture2.loadFromImage(starImage);
    Img starSprite2;
    starSprite2.setTexture(starTexture2);
    starSprite2.setPosition(202, 325);
    starSprite2.name = "star";

    Texture arrowTexture2;
    arrowTexture2.loadFromImage(arrowImage);
    Img arrowSprite2;
    arrowSprite2.setTexture(arrowTexture2);
    arrowSprite2.setPosition(202, 475);
    arrowSprite2.name = "arrow";

    //Картинки на 3 барабане
    Texture arrowTexture3;
    arrowTexture3.loadFromImage(arrowImage);
    Img arrowSprite3;
    arrowSprite3.setTexture(arrowTexture3);
    arrowSprite3.setPosition(373, 25);
    arrowSprite3.name = "arrow";

    Texture starTexture3;
    starTexture3.loadFromImage(starImage);
    Img starSprite3;
    starSprite3.setTexture(starTexture3);
    starSprite3.setPosition(373, 175);
    starSprite3.name ="star";

    Texture triangleTexture3;
    triangleTexture3.loadFromImage(triangleImage);
    Img triangleSprite3;
    triangleSprite3.setTexture(triangleTexture3);
    triangleSprite3.setPosition(373, 325);
    triangleSprite3.name = "triangle";

    Texture cloudTexture3;
    cloudTexture3.loadFromImage(cloudImage);
    Img cloudSprite3;
    cloudSprite3.setTexture(cloudTexture3);
    cloudSprite3.setPosition(373, 475);
    cloudSprite3.name = "cloud";

    bool isStart = false;
    bool isStopClicked = false;
    bool isRotated = false;
    bool isRotated2 = false;
    bool isRotated3 = false;
    bool calculated = false;
    bool ended = true;
    std::string resultBarrel = "";
    std::string resultBarrel2 = "";
    std::string resultBarrel3 = "";
    float time;
    time = clock.getElapsedTime().asSeconds();
    clock.restart();
    time = time / 800;
    float timeS = clock.getElapsedTime().asMicroseconds();
    Clock clckOverdue;
    float overdueTime;
    Clock clckStop;
    float stopTime;
    int score = 0;

    Font font;
    font.loadFromFile("verdana.ttf");
    Text text("", font, 40);
    text.setColor(Color::White);
    text.setString("Score: ");
    text.setPosition(580, 50);


    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();

            if(Mouse::isButtonPressed(Mouse::Left))
            {
                Vector2f mouse = window.mapPixelToCoords(Mouse::getPosition(window));
                FloatRect boundsStart = startSprite.getGlobalBounds();
                FloatRect boundsStop = stopSprite.getGlobalBounds();

                if (boundsStart.contains(mouse) && ended)
                {
                    isStart = true;
                    calculated = false;
                    ended = false;
                    isStopClicked = false;
                    clckStop.restart();
                    clckOverdue.restart();
                }
                if (boundsStop.contains(mouse) && isStart)
                {
                    isStart = false;
                    isStopClicked = true;
                    isRotated = false;
                    isRotated2 = false;
                    isRotated3 = false;
                    calculated = false;
                    clckStop.restart();
                }
            }
        }



        overdueTime = clckOverdue.getElapsedTime().asSeconds();
        if (overdueTime > 5 && !isStopClicked)
        {
            isStart = false;
            isStopClicked = true;
            isRotated = false;
            isRotated2 = false;
            isRotated3 = false;
            calculated = false;
            clckStop.restart();
        }

        stopTime = clckStop.getElapsedTime().asSeconds();
        window.clear();

        window.draw(startSprite);
        window.draw(stopSprite);
        window.draw(starSprite);
        window.draw(arrowSprite);
        window.draw(cloudSprite);
        window.draw(triangleSprite);

        window.draw(triangleSprite2);
        window.draw(cloudSprite2);
        window.draw(starSprite2);
        window.draw(arrowSprite2);

        window.draw(arrowSprite3);
        window.draw(starSprite3);
        window.draw(triangleSprite3);
        window.draw(cloudSprite3);

        window.draw(machineSprite);
        window.draw(text);
        window.display();
        if(isStart)
        {
            starSprite.move(0, 6200 * time);
            arrowSprite.move(0, 6200 * time);
            cloudSprite.move(0, 6200 * time);
            triangleSprite.move(0, 6200 * time);

            triangleSprite2.move(0, 4000 * time);
            cloudSprite2.move(0, 4000 * time);
            starSprite2.move(0, 4000 * time);
            arrowSprite2.move(0, 4000 * time);

            arrowSprite3.move(0, 5800 * time);
            starSprite3.move(0, 5800 * time);
            triangleSprite3.move(0, 5800 * time);
            cloudSprite3.move(0, 5800 * time);
        }

        if (!isStart)
        {
            if (isStopClicked & !isRotated)
            {
                starSprite.move(0, 2100 * time);
                arrowSprite.move(0, 2100 * time);
                cloudSprite.move(0, 2100 * time);
                triangleSprite.move(0, 2100 * time);

                if (stopTime >= 3 && cloudSprite.getPosition().y >= 325 && cloudSprite.getPosition().y <= 325.9)
                {
                    resultBarrel = cloudSprite.name;
                    isRotated = true;
                }
                if(stopTime >= 3 &&starSprite.getPosition().y >= 325 && starSprite.getPosition().y <= 325.9)
                {
                    resultBarrel = starSprite.name;
                    isRotated = true;
                }
                if(stopTime >= 3 &&arrowSprite.getPosition().y >= 325 && arrowSprite.getPosition().y <= 325.9)
                {
                    resultBarrel = arrowSprite.name;
                    isRotated = true;
                }
                if(stopTime >= 3 &&triangleSprite.getPosition().y >= 325 && triangleSprite.getPosition().y <= 325.9)
                {
                    resultBarrel = triangleSprite.name;
                    isRotated = true;
                }
            }

            if (isStopClicked & !isRotated2)
            {
                starSprite2.move(0, 1100 * time);
                arrowSprite2.move(0, 1100 * time);
                cloudSprite2.move(0, 1100 * time);
                triangleSprite2.move(0, 1100 * time);

                if (stopTime >= 4 && cloudSprite2.getPosition().y >= 325 && cloudSprite2.getPosition().y <= 325.9)
                {
                    resultBarrel2 = cloudSprite2.name;
                    isRotated2 = true;
                }
                if(stopTime >= 4 &&starSprite2.getPosition().y >= 325 && starSprite2.getPosition().y <= 325.9)
                {
                    resultBarrel2 = starSprite2.name;
                    isRotated2 = true;
                }
                if(stopTime >= 4 &&arrowSprite2.getPosition().y >= 325 && arrowSprite2.getPosition().y <= 325.9)
                {
                    resultBarrel2 = arrowSprite2.name;
                    isRotated2 = true;
                }
                if(stopTime >= 4 &&triangleSprite2.getPosition().y >= 325 && triangleSprite2.getPosition().y <= 325.9)
                {
                    resultBarrel2 = triangleSprite2.name;
                    isRotated2 = true;
                }
            }

            if (isStopClicked & !isRotated3)
            {
                starSprite3.move(0, 1900 * time);
                arrowSprite3.move(0, 1900 * time);
                cloudSprite3.move(0, 1900 * time);
                triangleSprite3.move(0, 1900 * time);

                if (stopTime >= 5 && cloudSprite3.getPosition().y >= 325 && cloudSprite3.getPosition().y <= 325.9)
                {
                    resultBarrel3 = cloudSprite3.name;
                    isRotated3 = true;
                }
                if(stopTime >= 5 &&starSprite3.getPosition().y >= 325 && starSprite3.getPosition().y <= 325.9)
                {
                    resultBarrel3 = starSprite3.name;
                    isRotated3 = true;
                }
                if(stopTime >= 5 &&arrowSprite3.getPosition().y >= 325 && arrowSprite3.getPosition().y <= 325.9)
                {
                    resultBarrel3 = arrowSprite3.name;
                    isRotated3 = true;
                }
                if(stopTime >= 5 &&triangleSprite3.getPosition().y >= 325 && triangleSprite3.getPosition().y <= 325.9)
                {
                    resultBarrel3 = triangleSprite3.name;
                    isRotated3 = true;
                }
            }

            if (isStopClicked & isRotated && isRotated2 && isRotated3)
            {
                if (!calculated)
                {
                    if (resultBarrel == resultBarrel2 && resultBarrel == resultBarrel3 && resultBarrel2 == resultBarrel3)
                    {
                        score += 10;
                    }
                    else if (resultBarrel == resultBarrel2 || resultBarrel2 == resultBarrel3 || resultBarrel == resultBarrel3)
                    {
                        score += 5;
                    }
                    else
                    {
                        score += -5;
                    }
                    calculated = true;
                }
                std::ostringstream scoreString;
                scoreString << score;
                text.setString("Score:" + scoreString.str());
                ended = true;
            }
        }

        if (starSprite.getPosition().y > 625)
            starSprite.setPosition(30, 25);
        if (arrowSprite.getPosition().y > 625)
            arrowSprite.setPosition(30, 25);
        if (cloudSprite.getPosition().y > 625)
            cloudSprite.setPosition(30, 25);
        if (triangleSprite.getPosition().y > 625)
            triangleSprite.setPosition(30, 25);

        if (starSprite2.getPosition().y > 625)
            starSprite2.setPosition(202, 25);
        if (arrowSprite2.getPosition().y > 625)
            arrowSprite2.setPosition(202, 25);
        if (cloudSprite2.getPosition().y > 625)
            cloudSprite2.setPosition(202, 25);
        if (triangleSprite2.getPosition().y > 625)
            triangleSprite2.setPosition(202, 25);

        if (starSprite3.getPosition().y > 625)
            starSprite3.setPosition(373, 25);
        if (arrowSprite3.getPosition().y > 625)
            arrowSprite3.setPosition(373, 25);
        if (cloudSprite3.getPosition().y > 625)
            cloudSprite3.setPosition(373, 25);
        if (triangleSprite3.getPosition().y > 625)
            triangleSprite3.setPosition(373, 25);
    }

    return 0;
}
