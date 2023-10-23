

#include <SFML/Graphics.hpp>

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "Imagen Suavizada en el Centro con Puntos en las Esquinas");

	// Cargar la textura del círculo azul desde la ruta específica
	sf::Texture blueCircleTexture;

	if (!blueCircleTexture.loadFromFile("D:\\Universidad - Cris\\Videojuegos\\Universidad del Litoral\\MAVI\\Practico_Unidad_3\\Unidad3_Assets\\Unidad3_Assets\\bcircle.png")) {

		return 1; // Aviso de error de carga

	}

	// Habilitar el suavizado en la textura del círculo azul
	blueCircleTexture.setSmooth(true);

	// Crear un sprite para el círculo azul
	sf::Sprite blueCircleSprite(blueCircleTexture);

	// Establecer el origen del sprite en el centro
	blueCircleSprite.setOrigin(blueCircleTexture.getSize().x / 2, blueCircleTexture.getSize().y / 2);

	// Posicionar el sprite en el centro de la ventana
	blueCircleSprite.setPosition(400, 300); // El centro de la ventana (800x600)

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

		window.clear(sf::Color::Black);

		// Dibujar el círculo azul suavizado en el centro de la ventana
		window.draw(blueCircleSprite);

		// Dibujar los puntos rojos en las esquinas
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