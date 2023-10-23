#include <SFML/Graphics.hpp>

int main() {

	sf::RenderWindow window(sf::VideoMode(800, 600), "Rotaci�n de Sprite");

	// Carga la textura del sprite desde la ruta espec�fica
	sf::Texture spriteTexture;

	if (!spriteTexture.loadFromFile("D:\\Universidad - Cris\\Videojuegos\\Universidad del Litoral\\MAVI\\Practico_Unidad_3\\Unidad3_Assets\\Unidad3_Assets\\cuad_red.png")) {
		return 1; // Aviso de error de carga
	}

	// Crea un sprite con la textura del sprite
	sf::Sprite sprite(spriteTexture);

	// Establecer la posici�n inicial del sprite
	sprite.setPosition(400, 300);

	// Velocidad de rotaci�n en grados por segundo
	float rotationSpeed = 5.0f; // grados por segundo

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}

		}
		window.clear();

		// Cambiar el �ngulo de rotaci�n del sprite
		float deltaTime = 0.016f; // Aproximadamente 60 fotogramas por segundo (Se ajusta seg�n la necesidad)
		float rotation = sprite.getRotation();
		rotation += rotationSpeed * deltaTime;
		sprite.setRotation(rotation);

		// Dibujar el sprite rotado
		window.draw(sprite);
		window.display();
	}
	return 0;
}