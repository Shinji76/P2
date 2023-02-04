#include <iostream>
#include "vector_template.h"
#include "album.h"

using std::cout;
using std::endl;

int main() {
	Fixed_vector<int> prova;
	Fixed_vector<int> prova2(5);
	//Album nuovo;

	cout << prova.getSize() << endl;
	cout << prova2.getSize() << endl;

	cout << prova.checkIfNull() << endl;
	cout << prova2.checkIfNull() << endl;

	cout << prova2[3];
}
/*
	//ID - Nome - Effetto - Costo - Rarita - Classe
	Mostro(1, "Murloc Tinyfin", "", 0, AbstractCard::Comune, AbstractCard::Neutrale, Mostro::Murloc, 1, 1);
	Mostro(2, "Snowflipper Penguin", "", 0, AbstractCard::Comune, AbstractCard::Neutrale, Mostro::Bestia, 1, 1);
	Mostro(3, "Wisp", "", 0, AbstractCard::Comune, AbstractCard::Neutrale, Mostro::Comune, 1, 1);
	Mostro(4, "Elven Archer", "Battlecry: Deal 1 damage.", 1, AbstractCard::Comune, AbstractCard::Neutrale, Mostro::Comune, 1, 1);
	Mostro(5, "Helmet Hermit", "Can't attack.", 1, AbstractCard::Rara, AbstractCard::Neutrale, Mostro::Bestia, 4, 3);
	Mostro(6, "Sir Finley Mrrgglton", "Battlecry: Discover a new basic Hero Power", 1, AbstractCard::Leggendaria, AbstractCard::Neutrale, Mostro::Murloc, 1, 3);
	Mostro(7, "Acidic Swamp Ooze", "Battlecry: Destroy your opponent weapon.", 2, AbstractCard::Rara, AbstractCard::Neutrale, Mostro::Comune, 3, 2);
	Mostro(8, "Bloodmage Thalnos", "effetto", 2, AbstractCard::Leggendaria, AbstractCard::Neutrale, Mostro::Comune, 1, 1);
	Mostro(9, "Doomsayer", "effetto", 2, AbstractCard::Epica, AbstractCard::Neutrale, Mostro::Comune, 0, 7);
	Mostro(10, "Acolyte of Pain", "effetto", 3, AbstractCard::Comune, AbstractCard::Neutrale, Mostro::Comune, 1, 3);
	Mostro(11, "Brann BronzeBeard", "effetto", 3, AbstractCard::Leggendaria, AbstractCard::Neutrale, Mostro::Comune, 2, 4);
	Mostro(12, "Ironbeak Owl", "effetto", 3, AbstractCard::Comune, AbstractCard::Neutrale, Mostro::Bestia, 2, 1);
	Mostro(13, "Southsea Captain", "effetto", 3, AbstractCard::Epica, AbstractCard::Neutrale, Mostro::Pirata, 3, 3);
	Mostro(14, "Sneaky Devil", "effetto", 4, AbstractCard::Comune, AbstractCard::Neutrale, Mostro::Demone, 2, 2);
	Mostro(15, "Big Game Hunter", "effetto", 4, AbstractCard::Epica, AbstractCard::Neutrale, Mostro::Comune, 4, 2);
	Mostro(16, "Defender of Argus", "effetto", 4, AbstractCard::Rara, AbstractCard::Neutrale, Mostro::Comune, 3, 3);
	Mostro(17, "Old Murk-Eye", "effetto", 4, AbstractCard::Leggendaria, AbstractCard::Neutrale, Mostro::Murloc, 2, 4);
	Mostro(18, "Azure Drake", "effetto", 5, AbstractCard::Rara, AbstractCard::Neutrale, Mostro::Drago, 4, 5);
	Mostro(19, "Burning Blade Acolyte", "effetto", 5, AbstractCard::Rara, AbstractCard::Neutrale, Mostro::Comune, 1, 1);
	Mostro(20, "Prince Malchezaar", "effetto", 5, AbstractCard::Leggendaria, AbstractCard::Neutrale, Mostro::Demone, 4, 5);
	Mostro(21, "Faceless Manipulator", "effetto", 5, AbstractCard::Epica, AbstractCard::Neutrale, Mostro::Comune, 3, 3);
	Mostro(22, "Leeeeroyyy Jenkinssss", "effetto", 5, AbstractCard::Leggendaria, AbstractCard::Neutrale, Mostro::Comune, 6, 2);
	Mostro(23, "Maexxna", "effetto", 6, AbstractCard::Leggendaria, AbstractCard::Neutrale, Mostro::Bestia, 2, 8);
	Mostro(24, "Reno Jackson", "effetto", 6, AbstractCard::Leggendaria, AbstractCard::Neutrale, Mostro::Comune, 4, 6);
	Mostro(25, "Sabeartooth Stalker", "effetto", 6, AbstractCard::Comune, AbstractCard::Neutrale, Mostro::Bestia, 8, 2);
	Mostro(26, "Baron Geddon", "effetto", 7, AbstractCard::Leggendaria, AbstractCard::Neutrale, Mostro::Elementale, 7, 7);
	Mostro(27, "Primordial Drake", "effetto", 8, AbstractCard::Epica, AbstractCard::Neutrale, Mostro::Drago, 4, 8);
	Mostro(28, "Majordomo ExeQTus", "effetto", 9, AbstractCard::Leggendaria, AbstractCard::Neutrale, Mostro::Comune, 9, 7);
	Mostro(29, "Deathwing", "effetto", 10, AbstractCard::Leggendaria, AbstractCard::Neutrale, Mostro::Drago, 12, 12);
	Mostro(30, "Lokholar the Ice Lord", "effetto", 10, AbstractCard::Leggendaria, AbstractCard::Neutrale, Mostro::Elementale, 8, 8);

	Mostro(31, "Alleycat", "effetto", 1, AbstractCard::Comune, AbstractCard::Cacciatore, Mostro::Bestia, 1, 1);
	Mostro(32, "Armorsmith", "effetto", 2, AbstractCard::Rara, AbstractCard::Guerriero, Mostro::Comune, 1, 4);
	Mostro(33, "Defias Cannoneer", "effetto", 3, AbstractCard::Comune, AbstractCard::Guerriero, Mostro::Pirata, 3, 3);
	Mostro(34, "Tidal Revenant", "effetto", 8, AbstractCard::Comune, AbstractCard::Guerriero, Mostro::Elementale, 5, 8);
	Mostro(35, "Edwin VanCleef", "effetto", 3, AbstractCard::Leggendaria, AbstractCard::Ladro, Mostro::Comune, 2, 2);
	Mostro(36, "SIU:7 Agent", "effetto", 3, AbstractCard::Rara, AbstractCard::Ladro, Mostro::Comune, 3, 3);
	Mostro(37, "Hullbreaker", "effetto", 4, AbstractCard::Rara, AbstractCard::Stregone, Mostro::Demone, 4, 3);
	Mostro(48, "Voidwalker", "effetto", 1, AbstractCard::Comune, AbstractCard::Stregone, Mostro::Demone, 1, 3);

	Segreto(39, "Snake Trap", "effetto", 2, AbstractCard::Epica, AbstractCard::Cacciatore);
	Segreto(40, "Bear Trap", "effetto", 2, AbstractCard::Comune, AbstractCard::Cacciatore);
	Segreto(41, "Ice Block", "effetto", 3, AbstractCard::Epica, AbstractCard::Mago);

	Magia(42, "Animal Companion", "effetto", 3, AbstractCard::Comune, AbstractCard::Cacciatore);
	Magia(43, "Brawl", "effetto", 5, AbstractCard::Epica, AbstractCard::Guerriero);
	Magia(44, "Backstab", "effetto", 0, AbstractCard::Comune, AbstractCard::Ladro);
	Magia(45, "Sprint", "effetto", 5, AbstractCard::Rara, AbstractCard::Ladro);
	Magia(46, "Arcane Intellect", "effetto", 3, AbstractCard::Comune, AbstractCard::Mago);
	Magia(47, "Shattering Blast", "effetto", 3, AbstractCard::Rara, AbstractCard::Mago);
	Magia(48, "Fireball", "effetto", 4, AbstractCard::Comune, AbstractCard::Mago);
	Magia(49, "Mortal Coil", "effetto", 1, AbstractCard::Comune, AbstractCard::Stregone);
	Magia(50, "Drain Soul", "effetto", 2, AbstractCard::Comune, AbstractCard::Stregone);
*/