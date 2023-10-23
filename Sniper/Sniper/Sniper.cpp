#include <SFML/Graphics.hpp>

int main() {
	
	sf::RenderWindow window(sf::VideoMode(800, 600), "Puntos en las Esquinas");
	// Crear un círculo rojo (punto) con el origen en el centro
	
	sf::CircleShape redPoint(5); // Radio del círculo, se puede modificar
	redPoint.setFillColor(sf::Color::Red);
	
	redPoint.setOrigin(5, 5); // Debe ser igual al radio, sino quedan corridos
	
	// Posiciones de las esquinas
	sf::Vector2f topLeft(0, 0);
	sf::Vector2f topRight(800, 0);
	sf::Vector2f bottomLeft(0, 600);
	sf::Vector2f bottomRight(800, 600);
	
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		
		// Dibujar los puntos en las esquinas
		window.clear(sf::Color::Black);
		redPoint.setPosition(topLeft);
		
		window.draw(redPoint); // Punto superior izquierdo
		redPoint.setPosition(topRight);
		
		window.draw(redPoint); // Punto superior derecho
		redPoint.setPosition(bottomLeft);
		
		window.draw(redPoint); // Punto inferior izquierdo
		redPoint.setPosition(bottomRight);
		
		window.draw(redPoint); // Punto inferior derecho
		window.display();
	}
	return 0;
}