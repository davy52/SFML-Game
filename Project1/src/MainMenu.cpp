#include "MainMenu.h"

//CONSTRUCTOR

MainMenu::MainMenu(sf::View& view, MenuState menuState): menuState(menuState)
{
	//font
	if (!this->font.loadFromFile("Resources/Fonts/SyneMono-Regular.ttf")) {
		std::cout << "[ERROR]: Could not load font1 (Resources/Fonts/SyneMono-Regular.ttf)\n";
	}

	//body init
	this->body_size = sf::Vector2f(view.getSize().x, view.getSize().y);
	this->body_size *= 8.f / 10.f;

	this->body_pos = view.getCenter();
	this->body_pos -= sf::Vector2f((view.getSize().x / 2.f) / 5.f, (view.getSize().y / 2.f) / 5.f);
	 
	body = new sf::RectangleShape(this->body_size);
	body->setPosition(this->body_pos);
	body->setFillColor(sf::Color(50, 120, 200, 200));

	//selector position init
	switch (this->menuState)
	{
	case MenuState::main:
		this->SelectorPos = SelPos::level_select;
		break;
	case MenuState::settings:
			//this->SelectorPos =  opcji na razie nie ma
			break;
	default:
		break;
	}
	textUpdate();
}

MainMenu::~MainMenu()
{
}

void MainMenu::draw(sf::RenderTarget& target)
{
	target.draw(*this->body);
	for (sf::Text* line : this->text) {
		target.draw(*line);
	}
}

void MainMenu::SelectorMove(SelDir dir)
{
	switch (menuState)
	{
	case MenuState::main:
		switch (dir)
		{
		case SelDir::UP:
			switch (SelectorPos)
			{
			case SelPos::level_select:
				break;
			case SelPos::character:
				this->SelectorPos = SelPos::level_select;
				break;
			case SelPos::settings:
				this->SelectorPos = ::SelPos::character;
				break;
			case SelPos::help:
				this->SelectorPos = ::SelPos::settings;
				break;
			case SelPos::exit:
				this->SelectorPos = ::SelPos::help;
				break;
			default:
				break;
			}
			break;
		case SelDir::DOWN:
			switch (SelectorPos)
			{
			case SelPos::level_select:
				this->SelectorPos = ::SelPos::character;
				break;
			case SelPos::character:
				this->SelectorPos = ::SelPos::settings;
				break;
			case SelPos::settings:
				this->SelectorPos = ::SelPos::help;
				break;
			case SelPos::help:
				this->SelectorPos = ::SelPos::exit;
				break;
			case SelPos::exit:
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
		break;
	case MenuState::level:	//choose level
		break;
	case MenuState::character:
		break;
	case MenuState::profile:
		break;
	case MenuState::skin:
		break;
	case MenuState::settings: 
		break;
	default:
		break;
	}
	
}

void MainMenu::SelectorEnter()
{
}

void MainMenu::textUpdate()
{
	for (auto* t : text) {
		delete t;
	}
	text.clear();
	switch (menuState)
	{
	case MenuState::main:
		break;
	case MenuState::level:
		this->text_level();
		break;
	case MenuState::character:
		break;
	case MenuState::profile:
		break;
	case MenuState::skin:
		break;
	case MenuState::settings:
		break;
	default:
		break;
	}
}

void MainMenu::text_main()
{
}

void MainMenu::text_level()
{
	std::string arr[] = { "Level 1" };

	for (int i = 0; i < 1; i++) { //od razu ddo wyboru wielu poziomow
		sf::Text* temp = new sf::Text;
		temp->setFont(this->font);
		temp->setCharacterSize(30);
	}
}

void MainMenu::text_char()
{
}

void MainMenu::text_settings()
{
}

