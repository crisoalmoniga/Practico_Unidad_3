#include <SFML/Graphics.hpp>

int main() {

	sf::RenderWindow window(sf::VideoMode(800, 600), "Fondo de Videojuego");

	// Carga la textura del fondo desde la ruta específica
	sf::Texture fondoTexture;

	if (!fondoTexture.loadFromFile("D:\\Universidad - Cris\\Videojuegos\\Universidad del Litoral\\MAVI\\Practico_Unidad_3\\Unidad3_Assets\\Unidad3_Assets\\fondo_plataforma.png")) {
		return 1; // Si la ruta falla, tira error 1.
	}

	// Crear un sprite para el fondo
	sf::Sprite fondoSprite(fondoTexture);

	// Escalar el fondo para que se ajuste a la ventana
	fondoSprite.setScale(
		static_cast<float>(window.getSize().x) / fondoTexture.getSize().x,
		static_cast<float>(window.getSize().y) / fondoTexture.getSize().y
	);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		window.clear();

		// Dibujar el fondo en toda la ventana
		window.draw(fondoSprite);
		window.display();
	}
	return 0;
}