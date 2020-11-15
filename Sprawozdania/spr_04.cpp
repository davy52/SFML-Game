
/*------------------------------------------------------------

Temat projektu: Gra platformowa 

Zakres projektu: (chyba zle zinterpretowalem ten punkt, jezeli maja to byc juz zrealizowane czesci projektu ro ma byc tak)
    1.	Tworzenie okna z tytulem i o odpowiedniej wielkosci
	2.	Wyswietlanie obiektu gracza (bez tekstury)
	3.	Wstepne poruszanie graczem (bez grawitacji, w tej chwili nie dziala to tak jak w planie)
	4.	klasa Menu (choc wciaz jest nie dokonczona)


Co zrealizowalem w biezacym tygodniu?

	Pojawilo sie jeszcze wiecej bledow ktore pojawiaja sie w dziwnych sytuacjach 
	z jakiegos powodu jest problem z wywolaniem funkcji delete na tablicy typu sf::Text
	a jezeli tablice zamienie na pojedynczy obiekt sf::Text program nawet nie dochodzi do punktu usuwania tekstu z pamieci HEAP
	tylko zatrzymuje sie na probie rysowania obiektu Player ktory dziedziczy z sf::RectangleShape (z czym nie ma problemu gdy istnieje tablica sf::Text)
		
		
   
Co planuje na kolejny tydzien?
	
	Jedyne rozwiazanie tych problemow jakie znalazlem na internecie, a ktorego jeszcze nie probowalem to
	zbudowanie biblioteki na nowo czego podejme sie w nastepnym tygodniu 
	
	Jezeli to nie zadziala chyba bede zmuszony pisac program od poczatku  
	
	
Kod źródłowy gry opublikowany jest na stronie github.com pod adresem https://github.com/davy52/SFML-Game
	zmiany z ostatnich 2 tygodni w galezi developement
------------------------------------------------------------*/
























