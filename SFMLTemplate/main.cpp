#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

int main()
{
    // Ana pencereyi olustur
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Ornek Pencere");

    // Gosterilecek resmi yukle
    sf::Texture texture;
    if (!texture.loadFromFile("cute_image.jpg"))
        return EXIT_FAILURE;
    sf::Sprite sprite(texture);

    // Calinacak muzigi yukle
    sf::Music music;
    if (!music.openFromFile("nice_music.ogg"))
        return EXIT_FAILURE;

    // Muzigi calmaya basla
    music.play();

    // Gosterilecek olan metne iliskin ilklendirmeleri yap
    sf::Font font;
    if (!font.loadFromFile("arial.ttf"))
        return EXIT_FAILURE;
    sf::Text text("Merhaba SFML", font, 50);
    text.setPosition(300, 200);
    text.setFillColor(sf::Color::Green);

    // Oyun dongusunu baslat
    while (window.isOpen())
    {
        // Olaylari isle
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Uygulama/pencere kapama
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Ekrani temizle
        window.clear();

        // Imaji cizdir
        window.draw(sprite);

        // Metni cizdir
        window.draw(text);

        // Pencereyi guncelle
        window.display();
    }
    return EXIT_SUCCESS;
}