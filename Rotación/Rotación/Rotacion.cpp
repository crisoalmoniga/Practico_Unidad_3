#include <SFML/Graphics.hpp>

int main() {

	sf::RenderWindow window(sf::VideoMode(800, 600), "Rotación de Sprite");

	// Carga la textura del sprite desde la ruta específica
	sf::Texture spriteTexture;

	if (!spriteTexture.loadFromFile("D:\\Universidad - Cris\\Videojuegos\\Universidad del Litoral\\MAVI\\Practico_Unidad_3\\Unidad3_Assets\\Unidad3_Assets\\cuad_red.png")) {
		return 1; // Aviso de error de carga
	}

	// Crea un sprite con la textura del sprite
	sf::Sprite sprite(spriteTexture);

	// Establecer la posición inicial del sprite
	sprite.setPosition(400, 300);

	// Velocidad de rotación en grados por segundo
	float rotationSpeed = 5.0f; // grados por segundo

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}

		}
		window.clear();

		// Cambiar el ángulo de rotación del sprite
		float deltaTime = 0.016f; // Aproximadamente 60 fotogramas por segundo (Se ajusta según la necesidad)
		float rotation = sprite.getRotation();
		rotation += rotationSpeed * deltaTime;
		sprite.setRotation(rotation);

		// Dibujar el sprite rotado
		window.draw(sprite);
		window.display();
	}
	return 0;
}