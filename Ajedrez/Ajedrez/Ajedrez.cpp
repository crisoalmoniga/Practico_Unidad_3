#include <SFML/Graphics.hpp>
int main() {
	sf::RenderWindow window(sf::VideoMode(800, 800), "Tablero de Ajedrez");
	// Carga las texturas para casillas negras y blancas, se actualiza según la ruta de cada uno.
	sf::Texture chessbTexture;
	if (!chessbTexture.loadFromFile("D:\\Universidad - Cris\\Videojuegos\\Universidad del Litoral\\MAVI\\Practico_Unidad_3\\Unidad3_Assets\\Unidad3_Assets\\chessb.png")) {
		return 1;
	}
	sf::Texture chesswTexture;
	if (!chesswTexture.loadFromFile("D:\\Universidad - Cris\\Videojuegos\\Universidad del Litoral\\MAVI\\Practico_Unidad_3\\Unidad3_Assets\\Unidad3_Assets\\chessw.png")) {
		return 1;
	}
	// Tamaño de cada casilla (ajuste para un tablero de 8x8)
	const int tileSize = 100;
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		window.clear(); // Limpiar la ventana
		// Dibuja el tablero de ajedrez
		for (int row = 0; row < 8; row++) {
			for (int col = 0; col < 8; col++) {
				sf::Sprite square;
				square.setTexture((row + col) % 2 == 0 ? chesswTexture : chessbTexture);
				square.setPosition(col * tileSize, row * tileSize);
				window.draw(square);
			}
		}
		window.display(); // Mostrar los cambios en la ventana
	}
	return 0;
}