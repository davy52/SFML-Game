#include "MainMenu.h"

//PRIVATE

void MainMenu::initTexts()
{

	textMain.push_back(menuText(&MainMenu::text_level, "Levels", this->font, 30));
	textMain.push_back(menuText(&MainMenu::text_char, "Change Name", this->font, 30));
	textMain.push_back(menuText(&MainMenu::gameClose, "Exit", this->font, 30));

	

	textLevel.push_back(menuText(nullptr, "Level1", this->font, 30));
	textLevel.push_back(menuText(nullptr, "Back", this->font, 30));
	
	textProfile.push_back(menuText(&MainMenu::text_main, "Back", this->font, 30));
	

	textActual = &textMain;
}

//CONSTRUCTOR

MainMenu::MainMenu(sf::View& view, GAME_STATE gState, MenuState menuState): menuState(menuState), view(view), gameState(gState)
{
	//font
	if (!this->font.loadFromFile("Resources/Fonts/SyneMono-Regular.ttf")) {
		std::cout << "[ERROR]: Could not load font1 (Resources/Fonts/SyneMono-Regular.ttf)\n";
	}

	//body init
	this->body_size = sf::Vector2f(view.getSize().x, view.getSize().y);
	this->body_size *= 8.f / 10.f;

	//this->body_pos = view.getCenter();
	this->body_pos = sf::Vector2f((view.getSize().x / 2.f) / 5.f, (view.getSize().y / 2.f) / 5.f);
	 
	body = new sf::RectangleShape(this->body_size);
	body->setPosition(this->body_pos);
	body->setFillColor(sf::Color(50, 120, 200, 200));

	//Text innit
	initTexts();
	//selector position init
	switch (this->menuState)
	{
	case MenuState::main:
		this->SelectorPos = textMain.begin();
		break;
	case MenuState::settings:
		this->SelectorPos = textSettings.begin();
			break;
	default:
		break;
	}
	textUpdate();
}

MainMenu::~MainMenu()
{
	delete body;
}

void MainMenu::draw(sf::RenderTarget& target)
{
	target.draw(*this->body);
	for (sf::Text line : *this->textActual) {
		target.draw(line);
	}
}

void MainMenu::SelectorMove(SelDir dir)
{
	switch (dir)
	{
	case SelDir::UP:
		if (SelectorPos != textActual->begin()) {
			SelectorPos--;
			textUpdate();
		}
		break;
	case SelDir::DOWN:
		if (SelectorPos != textActual->end()) {
			SelectorPos++;
			textUpdate();
		}
		break;
	default:
		break;
	}
	
}

void MainMenu::SelectorEnter()
{
	(this->*SelectorPos->func)(); //fucktion call from pointer
}

void MainMenu::textUpdate()
{
	for (auto line : *textActual) {
		if (line == *SelectorPos) {
			line.setStyle(sf::Text::Style::Underlined);
		}
		else {
			line.setStyle(sf::Text::Style::Regular);
		}
	}

	int i = 0;
	sf::Vector2f bodyPos = body->getPosition();
	float viewCenterX = view.getCenter().x;

	for (menuText t : textMain) {
		t.setFillColor(sf::Color::Black);
		t.setOrigin(t.getLocalBounds().width / 2, t.getLocalBounds().height / 2);
		t.setPosition(viewCenterX, bodyPos.y + 30 + 50 * i);
		i++;
	}
	i = 0;
	for (menuText t : textLevel) {
		t.setFillColor(sf::Color::Black);
		t.setOrigin(t.getLocalBounds().width / 2, t.getLocalBounds().height / 2);
		t.setPosition(viewCenterX, bodyPos.y + 30 + 50 * i);
		i++;
	}
	i = 0;
	for (menuText t : textProfile) {
		t.setFillColor(sf::Color::Black);
		t.setOrigin(t.getLocalBounds().width / 2, t.getLocalBounds().height / 2);
		t.setPosition(viewCenterX, bodyPos.y + 30 + 50 * i);
		i++;
	}
}




void MainMenu::text_main()
{

}

void MainMenu::text_level()
{
	//std::string arr[] = { "Level 1" };

	//for (int i = 0; i < 1; i++) { //od razu ddo wyboru wielu poziomow
	//	sf::Text* temp = new sf::Text;
	//	temp->setFont(this->font);
	//	temp->setCharacterSize(30);
	//}

	textActual = &textLevel;
}

void MainMenu::text_char()
{

}

void GameSave()
{
	return;
}

void MainMenu::gameClose()
{
	//GameSave();
	gameState = GAME_STATE::EXIT;
	
}


