#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <array_list.h>

class TextCircle
{
private:
	sf::Text my_text;		// This MUST have a font when created.
	sf::CircleShape my_circle;
	sf::Vector2f my_position;
public:
	TextCircle(sf::Font& the_font) : my_text(the_font),   // <- this : syntax passes the value to
		my_circle(100.0f)
	{													// the c'tor.
		my_position = sf::Vector2f(100.0f, 100.0f);
		my_circle.setFillColor(sf::Color(124, 124, 124));
	}

	void set_text(std::string s)
	{
		my_text.setString(s);
		sf::FloatRect fr = my_text.getLocalBounds();
		sf::Vector2f size = fr.size;
		float width = size.x;
		float height = size.y;
		float x = my_circle.getPosition().x;
		float y = my_circle.getPosition().y;
		my_text.setOrigin(sf::Vector2f(width / 2, height / 2));
		my_text.setPosition(sf::Vector2f(x + my_circle.getRadius(), y + my_circle.getRadius()));
	}

	void set_position(float x, float y)
	{
		my_text.setPosition(sf::Vector2f(x, y));
		my_circle.setPosition(sf::Vector2f(x, y));
		my_text.setPosition(sf::Vector2f(x + my_circle.getRadius(), y + my_circle.getRadius()));
	}

	sf::Text get_text()
	{
		return my_text;
	}

	sf::CircleShape get_circle()
	{
		return my_circle;
	}
};


int main(int argc, char** argv)
{
	// This code is run before the game starts.  Note how SFML is very object-oriented (creating
	// objects and calling methods) rather than SDL, which is very C based (mostly calling functions
	// and passing around structs)
	sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "JasonW Lab4 Solution");
	sf::CircleShape test_circle(100.0f);
	test_circle.setFillColor(sf::Color(255, 200, 100, 255));
	test_circle.setPosition(sf::Vector2f(10.0f, 10.0f));
	test_circle.setOrigin(sf::Vector2f(100.0f, 100.0f));

	sf::Texture my_hand_image("..\\..\\..\\media\\hand.png");
	sf::Sprite my_hand_sprite(my_hand_image);
	my_hand_sprite.setRotation(sf::degrees(45.0f));
	my_hand_sprite.setOrigin(sf::Vector2f());

	sf::Font my_font("..\\..\\..\\media\\Oswald\\static\\Oswald-Regular.ttf");
	sf::Text test_text(my_font);
	test_text.setString("Hello!");
	test_text.setCharacterSize(24);
	test_text.setFillColor(sf::Color(100, 255, 0, 128));
	test_text.setPosition(sf::Vector2f(75, 50));

	// Suggestion: make a collection of "parallel" arrays to hold all 
	// data about falling circles.  When you spawn a circle, add a data item to
	// each list
	ssuds::ArrayList<float> circle_xvalues;
	ssuds::ArrayList<float> circle_yvalues;
	ssuds::ArrayList<std::string> circle_text;
	TextCircle only_text_circle(my_font);


	// This is the "GAME LOOP" -- it runs as long as the window is open.  The two main
	// parts of a game loop are input-handling and drawing.  You might want to add a third
	// section that does other (non-input-related) updates.
	while (window.isOpen())
	{
		// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
		// @ UPDATES                                 @
		// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
		for (unsigned int i = 0; i < circle_xvalues.size(); i++)
		{
			circle_yvalues[i] += 0.1f;
		}


		// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
		// @ Input-handling (keyboard and mouse)     @
		// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
		// std::optional is a new C++-17+ thing -- it's kind of like
		// in python, if a function doesn't return anything useful, None is
		// returned.
		// Normally you would use == like this in a while loop -- this is assigning a result to event
		// AND THEN using that value as the "truth-test" for the while condition
		while (const std::optional event = window.pollEvent())
		{
			// We use event to see if it's something we care about
			if (event->is<sf::Event::Closed>())
			{
				// The quit button was pressed.
				window.close();
			}
			// We'll resume @ 12:25pm
			else if (const sf::Event::KeyPressed* keyEvt = event->getIf<sf::Event::KeyPressed>())
			{
				// We get here if a key is pressed.  Now see if it's a key we care about
				if (keyEvt->code == sf::Keyboard::Key::Escape)
				{
					window.close();
				}
				if (keyEvt->code == sf::Keyboard::Key::Space)
				{
					// Spawn a circle (eventually at a random spot -- here at a fixed location)
					circle_xvalues.append(142);
					circle_yvalues.append(414);
					circle_text.append("ItWorks!");
				}
			}
			else if (const sf::Event::MouseButtonPressed* buttonEvt =
				event->getIf<sf::Event::MouseButtonPressed>())
			{
				// We get here if any mouse button is pressed.  Now see if it's
				// a button press that we care about
				if (buttonEvt->button == sf::Mouse::Button::Left)
				{
					// We get here if it's a left-mouse button pressed.  Move green circle
					// here
					//sf::Vector2f temp_pos(buttonEvt->position.x, buttonEvt->position.y);
					//test_circle.setPosition(temp_pos);

					// Spawn another circle (eventually at a random spot -- here at a fixed location)
					circle_xvalues.append(buttonEvt->position.x);
					circle_yvalues.append(buttonEvt->position.y);
					circle_text.append("Clicky");
				}
			}
		}

		// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
		// @ Drawing (to the window)     @
		// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
		window.clear();
		window.draw(test_circle);
		window.draw(my_hand_sprite);
		window.draw(test_text);
		for (int i = 0; i < circle_xvalues.size(); i++)
		{
			only_text_circle.set_position(circle_xvalues[i], circle_yvalues[i]);
			only_text_circle.set_text(circle_text[i]);
			window.draw(only_text_circle.get_circle());
			window.draw(only_text_circle.get_text());
		}
		window.display();// Shows our drawings
	}
	return 0;
}