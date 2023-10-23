
#include <SFML/Graphics.hpp>

int main() {

	sf::RenderWindow window(sf::VideoMode(800, 800), "Imágenes de Colores");

	// Cargar las texturas desde las rutas específicas
	sf::Texture redTexture;

	if (!redTexture.loadFromFile("D:\\Universidad - Cris\\Videojuegos\\Universidad del Litoral\\MAVI\\Practico_Unidad_3\\Unidad3_Assets\\Unidad3_Assets\\cuad_red.png")) {
		return 1; // Si no carga tirar este error
	}

	sf::Texture yellowTexture;

	if (!yellowTexture.loadFromFile("D:\\Universidad - Cris\\Videojuegos\\Universidad del Litoral\\MAVI\\Practico_Unidad_3\\Unidad3_Assets\\Unidad3_Assets\\cuad_yellow.png")) {
		return 1; // Si no carga tirar este error
	}

	sf::Texture blueTexture;

	if (!blueTexture.loadFromFile("D:\\Universidad - Cris\\Videojuegos\\Universidad del Litoral\\MAVI\\Practico_Unidad_3\\Unidad3_Assets\\Unidad3_Assets\\cuad_blue.png")) {
		return 1; // Si no carga tirar este error
	}

	sf::Texture blackTexture;

	if (!blackTexture.loadFromFile("D:\\Universidad - Cris\\Videojuegos\\Universidad del Litoral\\MAVI\\Practico_Unidad_3\\Unidad3_Assets\\Unidad3_Assets\\chessb.png")) {
		return 1; // Si no carga tirar este error
	}

	// Establecer el mismo tamaño para todas las texturas (ajustado al tamaño deseado)

	int imageSize = 400; // Tamaño deseado para todas las imágenes
	redTexture.setSmooth(true);
	redTexture.setRepeated(true);
	yellowTexture.setSmooth(true);
	yellowTexture.setRepeated(true);
	blueTexture.setSmooth(true);
	blueTexture.setRepeated(true);
	blackTexture.setSmooth(true);
	blackTexture.setRepeated(true);
	sf::Sprite redSprite(redTexture);
	redSprite.setScale(imageSize / static_cast<float>(redTexture.getSize().x), imageSize / static_cast<float>(redTexture.getSize().y));
	sf::Sprite yellowSprite(yellowTexture);
	yellowSprite.setScale(imageSize / static_cast<float>(yellowTexture.getSize().x), imageSize / static_cast<float>(yellowTexture.getSize().y));
	sf::Sprite blueSprite(blueTexture);
	blueSprite.setScale(imageSize / static_cast<float>(blueTexture.getSize().x), imageSize / static_cast<float>(blueTexture.getSize().y));
	sf::Sprite blackSprite(blackTexture);
	blackSprite.setScale(imageSize / static_cast<float>(blackTexture.getSize().x), imageSize / static_cast<float>(blackTexture.getSize().y));

	// Establecer la posición de cada sprite
	redSprite.setPosition(0, 0); // Esquina superior izquierda
	yellowSprite.setPosition(800 - imageSize, 0); // Esquina superior derecha
	blueSprite.setPosition(0, 600 - imageSize); // Esquina inferior izquierda
	blackSprite.setPosition(800 - imageSize, 600 - imageSize); // Esquina inferior derecha

	while (window.isOpen()) {

		sf::Event event;

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		window.clear();

		// Dibujar los sprites en la ventana
		window.draw(redSprite);
		window.draw(yellowSprite);
		window.draw(blueSprite);
		window.draw(blackSprite);
		window.display();
	}

	return 0;

}