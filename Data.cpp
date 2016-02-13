#include "Data.h"

#include "Type.h"
#include "Category.h"

//Life,Attack,Defense,SpecialAttack,SpecialDefense,Speed,Type1,Type2
int Data::PokemonData[PokemonDataRange][8] = {
	{ 50, 50, 50, 50, 50, 50, Normal, NUL },//Missingno
	{ 45, 49, 49, 65, 65, 45, Grass, Poison },//Bulbasaur
	{ 60, 62, 63, 80, 80, 60, Grass, Poison },//Ivysaur
	{ 80, 82, 83, 100, 100, 80, Grass, Poison },//Venusaur
	{ 39, 52, 43, 60, 50, 65, Fire, NUL },//Charmander
	{ 58, 64, 58, 80, 65, 80, Fire, NUL },//Charmeleon
	{ 78, 84, 78, 109, 85, 100, Fire, Flying },//Charizard
	{ 44, 48, 65, 50, 44, 43, Water, NUL },//Squirtle
	{ 59, 63, 80, 65, 80, 58, Water, NUL },//Wartortle
	{ 79, 83, 100, 85, 105, 78, Water, NUL },//Blastoise
	{ 45, 30, 35, 20, 20, 45, Bug, NUL },//Caterpie
	{ 50, 20, 55, 25, 25, 30, Bug, NUL },//Metapod
	{ 60, 45, 50, 90, 80, 70, Bug, Flying },//Butterfree
	{ 40, 35, 30, 20, 20, 50, Bug, Poison },//Weedle
	{ 45, 25, 50, 25, 25, 35, Bug, Poison },//Kakuna
	{ 65, 90, 40, 45, 80, 75, Bug, Poison },//Beedrill
	{ 40, 45, 40, 35, 35, 56, Normal, Flying },//Pidgey
	{ 63, 60, 55, 50, 50, 71, Normal, Flying },//Pidgeotto
	{ 83, 80, 75, 70, 70, 101, Normal, Flying },//Pidgeot
	{ 30, 56, 35, 25, 35, 72, Normal, NUL },//Rattata
	{ 55, 81, 60, 50, 70, 97, Normal, NUL },//Raticate
	{ 40, 60, 30, 31, 31, 70, Normal, Flying },//Spearow
	{ 65, 90, 65, 61, 61, 100, Normal, Flying },//Fearow
	{ 35, 60, 44, 40, 54, 55, Poison, NUL },//Ekans
	{ 60, 85, 69, 65, 79, 80, Poison, NUL },//Arbok
	{ 35, 55, 40, 50, 50, 90, Electric, NUL },//Pikachu
	{ 60, 90, 55, 90, 80, 110, Electric, NUL },//Raichu
	{ 50, 70, 85, 20, 30, 40, Ground, NUL },//Sandshrew
	{ 75, 100, 110, 45, 55, 65, Ground, NUL },//Sandslash
	{ 55, 47, 52, 40, 40, 41, Poison, NUL },//Nidoran¡â
	{ 70, 62, 67, 55, 55, 56, Poison, NUL },//Nidorina
	{ 90, 92, 87, 75, 85, 76, Poison, Ground },//Nidoqueen
	{ 46, 57, 40, 40, 40, 50, Poison, NUL },//Nidoran¡á
	{ 61, 72, 57, 55, 55, 65, Poison, NUL },//Nidorino
	{ 81, 102, 77, 85, 75, 85, Poison, Ground },//Nidoking
	{ 70, 45, 48, 60, 65, 35, Fairy, NUL },//Clefairy
	{ 95, 70, 73, 95, 90, 65, Fairy, NUL },//Clefable
	{ 38, 41, 40, 50, 65, 65, Fire, NUL },//Vulpix
	{ 73, 76, 75, 81, 100, 100, Fire, NUL },//Ninetales
	{ 115, 45, 20, 45, 25, 20, Normal, Fairy },//Jigglypuff
	{ 140, 70, 45, 80, 50, 45, Normal, Fairy },//Wigglytuff
	{ 40, 45, 35, 30, 40, 55, Poison, Flying },//Zubat
	{ 75, 80, 70, 65, 75, 90, Poison, Flying },//Golbat
	{ 45, 50, 55, 75, 65, 30, Grass, Poison },//Oddish
	{ 60, 65, 70, 85, 75, 40, Grass, Poison },//Gloom
	{ 75, 80, 85, 110, 90, 50, Grass, Poison },//Vileplume
	{ 35, 70, 55, 45, 55, 25, Bug, Grass },//Paras
	{ 60, 95, 80, 60, 80, 30, Bug, Grass },//Parasect
	{ 60, 55, 50, 40, 55, 45, Bug, Poison },//Venonat
	{ 70, 65, 60, 90, 75, 90, Bug, Poison },//Venomoth
	{ 10, 55, 25, 35, 45, 95, Ground, NUL },//Diglett
	{ 35, 80, 50, 50, 70, 120, Ground, NUL },//Dugtrio
	{ 40, 45, 35, 40, 40, 90, Normal, NUL },//Meowth
	{ 65, 70, 60, 65, 65, 115, Normal, NUL },//Persian
	{ 50, 52, 48, 65, 50, 55, Water, NUL },//Psyduck
	{ 80, 82, 78, 95, 80, 85, Water, NUL },//Golduck
	{ 40, 80, 35, 35, 45, 70, Fighting, NUL },//Mankey
	{ 65, 105, 60, 60, 70, 95, Fighting, NUL },//Primeape
	{ 55, 70, 45, 70, 50, 60, Fire, NUL },//Growlithe
	{ 90, 110, 80, 100, 80, 95, Fire, NUL },//Arcanine
	{ 40, 50, 40, 40, 40, 90, Water, NUL },//Poliwag
	{ 65, 65, 65, 50, 50, 90, Water, NUL },//Poliwhirl
	{ 90, 95, 95, 70, 90, 70, Water, Fighting },//Poliwrath
	{ 25, 20, 15, 105, 55, 95, Psychic, NUL },//Abra
	{ 40, 35, 30, 120, 76, 105, Psychic, NUL },//Kadabra
	{ 55, 50, 45, 135, 95, 120, Psychic, NUL },//Alakazam
	{ 70, 80, 50, 35, 35, 35, Fighting, NUL },//Machop
	{ 80, 100, 70, 50, 60, 45, Fighting, NUL },//Machoke
	{ 90, 130, 80, 65, 85, 55, Fighting, NUL },//Machamp
	{ 50, 75, 35, 70, 30, 40, Grass, Poison },//Bellsprout
	{ 65, 90, 50, 85, 45, 55, Grass, Poison },//Weepinbell
	{ 80, 105, 65, 100, 70, 70, Grass, Poison },//Victreebel
	{ 40, 40, 35, 50, 100, 70, Water, Poison },//Tentacool
	{ 80, 70, 65, 80, 120, 100, Water, Poison },//Tentacruel
	{ 40, 80, 100, 30, 30, 20, Rock, Ground },//Geodude
	{ 55, 95, 115, 45, 45, 35, Rock, Ground },//Graveler
	{ 80, 120, 130, 55, 65, 45, Rock, Ground },//Golem
	{ 50, 85, 55, 65, 65, 90, Fire, NUL },//Ponyta
	{ 65, 100, 70, 80, 80, 105, Fire, NUL },//Rapidash
	{ 90, 65, 65, 40, 40, 15, Water, Psychic },//Slowpoke
	{ 95, 75, 110, 100, 80, 30, Water, Psychic },//Slowbro
	{ 25, 35, 70, 95, 55, 45, Electric, Steel },//Magnemite
	{ 50, 60, 95, 120, 70, 70, Electric, Steel },//Magneton
	{ 52, 65, 55, 58, 62, 60, Normal, Flying },//Farfetch'd
	{ 35, 85, 45, 35, 35, 75, Normal, Flying },//Doduo
	{ 60, 110, 70, 60, 60, 100, Normal, Flying },//Dodrio
	{ 65, 45, 55, 45, 70, 45, Water, NUL },//Seel
	{ 90, 70, 80, 70, 95, 70, Water, Ice },//Dewgong
	{ 80, 80, 50, 40, 50, 25, Poison, NUL },//Grimer
	{ 105, 105, 75, 65, 100, 50, Poison, NUL },//Muk
	{ 30, 65, 100, 45, 25, 40, Water, NUL },//Shellder
	{ 50, 95, 180, 85, 45, 70, Water, Ice },//Cloyster
	{ 30, 35, 30, 100, 35, 80, Ghost, Poison },//Gastly
	{ 45, 50, 45, 115, 55, 95, Ghost, Poison },//Haunter
	{ 60, 65, 60, 130, 75, 110, Ghost, Poison },//Gengar
	{ 35, 45, 160, 30, 45, 70, Rock, Ground },//Onix
	{ 60, 48, 45, 43, 90, 42, Psychic, NUL },//Drowzee
	{ 85, 73, 70, 73, 115, 67, Psychic, NUL },//Hypno
	{ 30, 105, 90, 25, 25, 50, Water, NUL },//Krabby
	{ 55, 130, 115, 50, 50, 75, Water, NUL },//Kingler
	{ 40, 30, 50, 55, 55, 100, Electric, NUL },//Voltorb
	{ 60, 50, 70, 80, 80, 140, Electric, NUL },//Electrobe
	{ 60, 40, 80, 60, 45, 40, Grass, Psychic },//Exeggcute
	{ 95, 95, 85, 125, 65, 55, Grass, Psychic },//Exeggutor
	{ 50, 50, 95, 40, 50, 35, Ground, NUL },//Cubone
	{ 60, 80, 110, 50, 80, 45, Ground, NUL },//Marowak
	{ 50, 120, 53, 35, 110, 87, Fighting, NUL },//Hitmonlee
	{ 50, 105, 79, 35, 110, 76, Fighting, NUL },//Hitmonchan
	{ 90, 55, 75, 60, 75, 30, Normal, NUL },//Lickitung
	{ 40, 65, 95, 60, 45, 35, Poison, NUL },//Koffing
	{ 65, 90, 120, 85, 70, 60, Poison, NUL },//Weezing
	{ 80, 85, 95, 30, 30, 25, Ground, Rock },//Rhyhorn
	{ 105, 130, 120, 45, 45, 40, Ground, Rock },//Rhydon
	{ 250, 5, 5, 35, 105, 50, Normal, NUL },//Chansey
	{ 65, 55, 115, 100, 40, 60, Grass, NUL },//Tangela
	{ 105, 95, 80, 40, 80, 90, Normal, NUL },//Kangaskhan
	{ 30, 40, 70, 70, 25, 60, Water, NUL },//Horsea
	{ 55, 65, 95, 95, 45, 85, Water, NUL },//Seadra
	{ 45, 67, 60, 35, 50, 63, Water, NUL },//Goldeen
	{ 80, 92, 65, 65, 80, 68, Water, NUL },//Seaking
	{ 30, 45, 55, 70, 55, 85, Water, NUL },//Staryu
	{ 60, 75, 85, 100, 85, 115, Water, NUL },//Starmie
	{ 40, 45, 65, 100, 120, 90, Psychic, Fairy },//Mr.Mine
	{ 70, 110, 80, 55, 80, 105, Bug, Flying },//Scyther
	{ 65, 50, 35, 115, 95, 95, Ice, Psychic },//Jynx
	{ 65, 83, 57, 95, 85, 105, Electric, NUL },//Electabuzz
	{ 65, 95, 57, 100, 85, 93, Fire, NUL },//Magmar
	{ 65, 125, 100, 55, 70, 85, Bug, NUL },//Pinsir
	{ 75, 100, 95, 40, 70, 110, Normal, NUL },//Tauros
	{ 20, 10, 55, 15, 20, 80, Water, NUL },//Magikarp
	{ 95, 125, 79, 60, 100, 81, Water, NUL },//Gyarados
	{ 130, 85, 80, 85, 95, 60, Water, Ice },//Lapras
	{ 48, 48, 48, 48, 48, 48, Normal, NUL },//Ditto
	{ 55, 55, 50, 45, 65, 55, Normal, NUL },//Eevee
	{ 130, 65, 60, 110, 95, 65, Water, NUL },//Vaporeon
	{ 65, 65, 60, 110, 95, 130, Electric, NUL },//Jolteon
	{ 65, 130, 60, 95, 110, 65, Fire, NUL },//Flareon
	{ 65, 60, 70, 85, 75, 40, Normal, NUL },//Polygon
	{ 35, 40, 100, 90, 55, 35, Rock, Water },//Omanyte
	{ 70, 60, 125, 115, 70, 55, Rock, Water },//Omastar
	{ 30, 80, 90, 55, 45, 55, Rock, Water },//Kabuto
	{ 60, 115, 105, 65, 70, 80, Rock, Water },//Kabutops
	{ 80, 105, 65, 60, 75, 130, Rock, Flying },//Aerodactyl
	{ 160, 110, 65, 65, 110, 30, Normal, NUL },//Snorlax
	{ 90, 85, 100, 95, 125, 85, Ice, Flying },//Articuno
	{ 90, 90, 85, 125, 90, 100, Electric, Flying },//Zapdos
	{ 90, 100, 90, 125, 85, 90, Fire, Flying },//Moltres
	{ 41, 64, 45, 50, 50, 50, Dragon, NUL },//Dratini
	{ 61, 84, 65, 70, 70, 70, Dragon, NUL },//Dragonair
	{ 91, 134, 95, 100, 100, 80, Dragon, Flying },//Dragonite
	{ 106, 110, 90, 154, 90, 130, Psychic, NUL },//Mewtwo
	{ 100, 100, 100, 100, 100, 100, Psychic, NUL },//Mew

	//-------------------Generation II--------------------------

	{ 45, 49, 65, 49, 65, 45, Grass, NUL },//Chikorita
	{ 60, 62, 80, 63, 80, 60, Grass, NUL },//Bayleef
	{ 80, 82, 100, 83, 100, 80, Grass, NUL },//Meganium
	{ 39, 52, 43, 60, 50, 65, Fire, NUL },//Cyndaquil
	{ 58, 64, 58, 80, 65, 80, Fire, NUL },//Quilava
	{ 78, 84, 78, 109, 85, 100, Fire, NUL },//Typelosion
	{ 50, 65, 64, 44, 48, 43, Water, NUL },//Totodile
	{ 65, 80, 80, 59, 63, 58, Water, NUL },//Croconaw
	{ 85, 105, 100, 79, 83, 78, Water, NUL },//Feraligatr
	{ 35, 46, 34, 35, 45, 20, Normal, NUL },//Sentret
	{ 85, 76, 64, 45, 55, 90, Normal, NUL },//Furret
	{ 60, 30, 30, 36, 56, 50, Normal, Flying },//Hoothoot
	{ 100, 50, 50, 76, 96, 70, Normal, Flying },//Noctowl
	{ 40, 20, 30, 40, 80, 55, Bug, Flying },//Ledyba
	{ 55, 50, 35, 55, 110, 85, Bug, Flying },//Ledian
	{ 40, 60, 40, 40, 40, 30, Bug, Poison },//Spinarak
	{ 70, 90, 70, 60, 60, 40, Bug, Poison },//Ariados
	{ 85, 90, 80, 70, 80, 130, Poison, Flying },//Crobat
	{ 75, 38, 38, 56, 56, 67, Water, Electric },//Chinchou
	{ 125, 58, 58, 76, 76, 67, Water, Electric },//Lanturn
	{ 20, 40, 15, 35, 35, 60, Electric, NUL },//Pichu
	{ 50, 25, 28, 45, 55, 15, Fairy, NUL },//Cleffa
	{ 90, 30, 15, 40, 20, 15, Normal, Fairy },//Lgglybuff
	{ 35, 20, 65, 40, 65, 20, Fairy, NUL },//Togepi
	{ 55, 40, 85, 80, 105, 40, Fairy, Flying },//Togetic
	{ 40, 50, 45, 70, 45, 70, Psychic, Flying },//Natu
	{ 65, 75, 70, 95, 70, 95, Psychic, Flying },//Xatu
	{ 55, 40, 30, 65, 45, 35, Electric, NUL },//Mareep
	{ 70, 55, 55, 80, 60, 45, Electric, NUL },//Flaaffy
	{ 90, 75, 85, 115, 90, 55, Electric, NUL },//Ampharos
	{ 75, 80, 95, 90, 100, 50, Grass, NUL },//Bellossom
	{ 70, 20, 50, 20, 50, 40, Water, NUL },//Marill
	{ 100, 50, 80, 60, 80, 50, Water, NUL },//Azumarill
	{ 70, 100, 115, 30, 65, 30, Rock, NUL },//Sudowoodo
	{ 90, 75, 75, 90, 100, 70, Water, NUL },//Politoed
	{ 35, 35, 40, 35, 55, 40, Grass, Flying },//Hoppip
	{ 55, 45, 50, 45, 65, 80, Grass, Flying },//Skiploom
	{ 75, 55, 70, 55, 95, 110, Grass, Flying },//Jumploff
	{ 55, 70, 55, 40, 55, 85, Normal, NUL },//Aipom
	{ 30, 30, 30, 30, 30, 30, Grass, NUL },//Sunkern
	{ 75, 75, 55, 105, 80, 30, Grass, NUL },//Sunflora
	{ 65, 65, 45, 75, 45, 95, Bug, Flying },//Yanma
	{ 55, 45, 45, 25, 25, 15, Water, Ground },//Wooper
	{ 95, 85, 85, 65, 65, 35, Water, Ground },//Quagsire
	{ 65, 65, 60, 130, 95, 110, Psychic, NUL },//Espeon
	{ 95, 65, 110, 60, 130, 65, Dark, NUL },//Umbreon
	{ 60, 85, 42, 85, 42, 91, Dark, Flying },//Murkrow
	{ 95, 75, 80, 100, 110, 30, Water, Psychic },//Slowking
	{ 60, 60, 60, 85, 85, 85, Ghost, NUL },//Misdreavus
	{ 48, 72, 48, 72, 48, 48, Psychic, NUL },//Unown
	{ 190, 33, 58, 33, 58, 33, Psychic, NUL },//Wobbuffet
	{ 70, 80, 65, 90, 65, 85, Normal, Psychic },//Girafarig
	{ 50, 65, 90, 35, 35, 15, Bug, NUL },//Pineco
	{ 75, 90, 140, 60, 60, 40, Bug, Steel },//Forretress
	{ 100, 70, 70, 65, 65, 45, Normal, NUL },//Dunsparce
	{ 65, 75, 105, 35, 65, 85, Ground, Flying },//Gligar
	{ 75, 85, 200, 55, 65, 30, Steel, Ground },//Steelix
	{ 60, 80, 50, 40, 40, 30, Fairy, NUL },//Snubbull
	{ 90, 120, 75, 60, 60, 45, Fairy, NUL },//Granbull
	{ 65, 95, 75, 55, 55, 85, Water, Poison },//Qwilfish
	{ 70, 130, 100, 55, 80, 65, Bug, Steel },//Scizor
	{ 20, 10, 230, 10, 230, 5, Bug, Rock },//Shuckle
	{ 80, 125, 75, 40, 95, 85, Bug, Fighting },//Heracross
	{ 55, 95, 55, 35, 75, 115, Dark, Ice },//Sneasel
	{ 60, 80, 50, 50, 50, 40, Normal, NUL },//Teddiursa
	{ 90, 130, 75, 75, 75, 55, Normal, NUL },//Ursaring
	{ 40, 40, 40, 70, 40, 20, Fire, NUL },//Slugma
	{ 50, 50, 120, 80, 80, 30, Fire, Rock },//Magcargo
	{ 50, 50, 40, 30, 30, 50, Ice, Ground },//Swinub
	{ 100, 100, 80, 60, 60, 50, Ice, Ground },//Piloswine
	{ 55, 55, 85, 65, 85, 35, Water, Rock },//Corsola
	{ 35, 65, 35, 65, 35, 65, Water, NUL },//Remoraid
	{ 75, 105, 75, 105, 75, 45, Water, NUL },//Octillery
	{ 45, 55, 45, 65, 45, 75, Ice, Flying },//Delibird
	{ 65, 40, 70, 80, 140, 70, Water, Flying },//Mantine
	{ 65, 80, 140, 40, 70, 70, Steel, Flying },//Skarmory
	{ 45, 60, 30, 80, 50, 65, Dark, Fire },//Houndour
	{ 75, 90, 50, 110, 80, 95, Dark, Fire },//Houndoom
	{ 75, 95, 95, 95, 95, 85, Water, Dragon },//Kingdra
	{ 90, 60, 60, 40, 40, 40, Ground, NUL },//Phanpy
	{ 90, 120, 120, 60, 60, 50, Ground, NUL },//Donphan
	{ 85, 80, 90, 105, 95, 60, Normal, NUL },//Porygon2
	{ 73, 95, 62, 85, 65, 85, Normal, NUL },//Stantler
	{ 55, 20, 35, 20, 45, 75, Normal, NUL },//Smeargle
	{ 35, 35, 35, 35, 35, 35, Fighting, NUL },//Tyrogue
	{ 50, 95, 95, 35, 110, 70, Fighting, NUL },//Hitmontop
	{ 45, 35, 10, 85, 85, 65, Ice, Psychic },//Smoochun
	{ 45, 63, 37, 65, 55, 95, Electric, NUL },//Elekid
	{ 45, 75, 37, 70, 55, 83, Fire, NUL },//Magby
	{ 95, 80, 105, 40, 70, 100, Normal, NUL },//Miltank
	{ 255, 10, 10, 75, 135, 55, Normal, NUL },//Blissey
	{ 90, 85, 75, 115, 110, 115, Electric, NUL },//Raikou
	{ 115, 115, 85, 90, 75, 100, Fire, NUL },//Entei
	{ 100, 75, 115, 90, 115, 85, Water, NUL },//Suicune
	{ 50, 64, 50, 45, 50, 41, Rock, Ground },//Larvitar
	{ 70, 84, 70, 65, 70, 51, Rock, Ground },//Pupitar
	{ 100, 134, 110, 95, 100, 61, Rock, Dark },//Tyranitar
	{ 106, 90, 130, 90, 154, 110, Psychic, Flying },//Lugia
	{ 106, 130, 90, 110, 154, 90, Fire, Flying },//Ho-oh
	{ 100, 100, 100, 100, 100, 100, Psychic, Grass },//Celebi

	//-------------------------Generation III------------------------

	{ 40, 45, 35, 65, 55, 70, Grass, NUL },//Treecko
	{ 50, 65, 45, 85, 65, 95, Grass, NUL },//Grovyle
	{ 70, 85, 65, 105, 85, 120, Grass, NUL },//Sceptile
	{ 45, 60, 40, 70, 50, 45, Fire, NUL },//Torchic
	{ 60, 85, 60, 85, 60, 55, Fire, Fighting },//Combusken
	{ 80, 120, 70, 110, 70, 80, Fire, Fighting },//Blaziken
	{ 50, 70, 50, 50, 50, 40, Water, NUL },//Mudkip
	{ 70, 85, 70, 60, 70, 50, Water, NUL },//Marshtomp
	{ 100, 110, 90, 85, 90, 60, Water, Ground },//Swampert
	{ 35, 55, 35, 30, 30, 35, Dark, NUL },//Poochyena
	{ 70, 90, 70, 60, 60, 70, Dark, NUL },//Mightyena
	{ 38, 30, 41, 30, 41, 60, Normal, NUL },//Zigzagoon
	{ 78, 70, 61, 50, 61, 100, Normal, NUL },//Linoone
	{ 45, 45, 35, 20, 30, 20, Bug, NUL },//Wurmple
	{ 50, 35, 55, 25, 25, 15, Bug, NUL },//Silcoon
	{ 60, 70, 50, 100, 50, 65, Bug, Flying },//Beautifly
	{ 50, 35, 55, 25, 25, 15, Bug, NUL },//Cascoon
	{ 60, 50, 70, 50, 90, 65, Bug, Poison },//Dustox
	{ 40, 30, 30, 40, 50, 30, Water, Grass },//Lotad
	{ 60, 50, 50, 60, 70, 50, Water, Grass },//Lombre
	{ 80, 70, 70, 90, 100, 70, Water, Grass },//Ludicolo
	{ 40, 40, 50, 30, 30, 30, Grass, NUL },//Seedot
	{ 70, 70, 40, 60, 40, 60, Grass, Dark },//Nuzleaf
	{ 90, 100, 60, 90, 60, 80, Grass, Dark },//Shiftry
	{ 40, 55, 30, 30, 30, 85, Normal, Dark },//Taillow
	{ 60, 85, 60, 50, 50, 125, Normal, Dark },//Swellow
	{ 40, 30, 30, 55, 30, 85, Water, Flying },//Wingull
	{ 60, 50, 100, 85, 70, 65, Water, Flying },//Pelipper
	{ 28, 25, 25, 45, 35, 40, Psychic, Fairy },//Ralts
	{ 38, 35, 35, 65, 55, 50, Psychic, Fairy },//Kirlia
	{ 68, 65, 65, 125, 115, 80, Psychic, Fairy },//Gardevoir
	{ 40, 30, 32, 50, 52, 65, Bug, Water },//Surskit
	{ 70, 60, 62, 80, 82, 60, Bug, Water },//Masquerain
	{ 60, 40, 60, 40, 60, 35, Grass, NUL },//Shroomish
	{ 60, 130, 80, 60, 60, 70, Grass, Fighting },//Breloom
	{ 60, 60, 60, 35, 35, 30, Normal, NUL },//Slakoth
	{ 80, 80, 80, 55, 55, 90, Normal, NUL },//Vigoroth
	{ 150, 160, 100, 55, 65, 100, Normal, NUL },//Slaking
	{ 31, 45, 90, 30, 30, 40, Bug, Ground },//Nincada
	{ 61, 90, 45, 50, 50, 160, Bug, Flying },//Ninjask
	{ 1, 90, 45, 30, 30, 40, Bug, Ghost },//Shedinja
	{ 64, 51, 23, 51, 23, 28, Normal, NUL },//Whismur
	{ 84, 71, 43, 71, 43, 48, Normal, NUL },//Loudred
	{ 104, 91, 63, 91, 73, 68, Normal, NUL },//Exploud
	{ 72, 60, 30, 20, 30, 25, Fighting, NUL },//Makuhita
	{ 144, 120, 60, 40, 60, 50, Fighting, NUL },//Hariyama
	{ 50, 20, 40, 20, 40, 20, Normal, Fairy },//Azurill
	{ 30, 45, 135, 45, 90, 30, Rock, NUL },//Nosepass
	{ 50, 45, 45, 35, 35, 50, Normal, NUL },//Skitty
	{ 70, 65, 65, 55, 55, 70, Normal, NUL },//Delcatty
	{ 50, 75, 75, 65, 65, 50, Dark, Ghost },//Sableye
	{ 50, 85, 85, 55, 55, 50, Steel, Fairy },//Mawile
	{ 50, 70, 100, 40, 40, 30, Steel, Rock },//Aron
	{ 60, 90, 140, 50, 50, 40, Steel, Rock },//Lairon
	{ 70, 110, 180, 60, 60, 40, Steel, Rock },//Aggron
	{ 30, 40, 55, 40, 55, 60, Fighting, Psychic },//Meditite
	{ 60, 60, 75, 60, 75, 80, Fighting, Psychic },//Medicham
	{ 40, 45, 40, 65, 40, 65, Electric, NUL },//Electrike
	{ 70, 75, 60, 105, 60, 105, Electric, NUL },//Manectric
	{ 60, 50, 40, 85, 75, 95, Electric, NUL },//Plusle
	{ 60, 40, 50, 75, 85, 95, Electric, NUL },//Minun
	{ 65, 73, 55, 47, 75, 85, Electric, NUL },//Volbeat
	{ 65, 47, 55, 73, 75, 85, Bug, NUL },//Illumise
	{ 50, 60, 45, 100, 80, 65, Grass, Poison },//Roselia
	{ 70, 43, 53, 43, 53, 40, Poison, NUL },//Gulpin
	{ 100, 73, 83, 73, 83, 53, Poison, NUL },//Swalot
	{ 45, 90, 20, 65, 20, 65, Dark, Water },//Carvanha
	{ 70, 120, 40, 95, 40, 95, Dark, Water },//Sharpedo
	{ 130, 70, 35, 70, 35, 60, Dark, Water },//Wailmer
	{ 170, 90, 45, 90, 45, 60, Water, NUL },//Wailord
	{ 60, 60, 40, 65, 45, 35, Fire, Ground },//Numel
	{ 70, 100, 70, 105, 75, 40, Fire, Ground },//Camerupt
	{ 70, 85, 140, 85, 70, 20, Fire, NUL },//Torkal
	{ 60, 25, 35, 70, 80, 60, Psychic, NUL },//Spoink
	{ 80, 45, 65, 90, 110, 80, Psychic, NUL },//Grumpig
	{ 60, 60, 60, 60, 60, 60, Normal, NUL },//Spinda
	{ 45, 100, 45, 45, 45, 10, Ground, NUL },//Trapinch
	{ 50, 70, 50, 50, 50, 70, Ground, Dragon },//Vibrava
	{ 80, 100, 80, 80, 80, 100, Ground, Dragon },//Flygon
	{ 50, 85, 40, 85, 40, 35, Grass, NUL },//Cacnea
	{ 70, 115, 60, 115, 60, 55, Grass, NUL },//Cacturne
	{ 45, 40, 60, 40, 75, 50, Normal, Flying },//Swablu
	{ 75, 70, 90, 70, 105, 80, Dragon, Flying },//Altaria
	{ 73, 115, 60, 60, 60, 90, Normal, NUL },//Zangoose
	{ 73, 100, 60, 100, 60, 65, Poison, NUL },//Seviper
	{ 70, 55, 65, 95, 85, 70, Rock, Psychic },//Lunatone
	{ 70, 95, 85, 55, 65, 70, Rock, Psychic },//Solrock
	{ 50, 48, 43, 46, 41, 60, Water, Ground },//Barboach
	{ 110, 78, 73, 76, 71, 60, Water, Ground },//Whiscash
	{ 43, 80, 65, 50, 35, 35, Water, NUL },//Corphish
	{ 63, 120, 85, 90, 55, 55, Water, NUL },//Crawdaunt
	{ 40, 40, 55, 40, 70, 55, Ground, Psychic },//Baltoy
	{ 60, 70, 105, 70, 120, 75, Ground, Psychic },//Claydol
	{ 66, 41, 77, 61, 87, 23, Rock, Grass },//Lileep
	{ 86, 81, 97, 81, 107, 43, Rock, Grass },//Cradily
	{ 45, 95, 50, 40, 50, 75, Rock, Bug },//Anorith
	{ 75, 125, 100, 70, 80, 45, Rock, Bug },//Armaldo
	{ 20, 15, 20, 10, 55, 80, Water, NUL },//Feebas
	{ 95, 60, 79, 100, 125, 81, Water, NUL },//Milotic
	{ 70, 70, 70, 70, 70, 70, Normal, NUL },//Castform
	{ 60, 90, 70, 60, 120, 40, Normal, NUL },//Kecleon
	{ 44, 75, 35, 63, 33, 45, Ghost, NUL },//Shuppet
	{ 64, 115, 65, 83, 63, 65, Ghost, NUL },//Banette
	{ 20, 40, 90, 30, 90, 25, Ghost, NUL },//Duskull
	{ 40, 70, 130, 60, 130, 25, Ghost, NUL },//Dusclops
	{ 99, 68, 83, 72, 87, 51, Grass, Dragon },//Tropius
	{ 65, 50, 70, 95, 80, 65, Psychic, NUL },//Chimecho
	{ 65, 130, 60, 75, 60, 75, Dark, NUL },//Absol
	{ 95, 23, 48, 23, 48, 23, Psychic, NUL },//Wynaut
	{ 50, 50, 50, 50, 50, 50, Ice, NUL },//Snorunt
	{ 80, 80, 80, 80, 80, 80, Ice, NUL },//Glalie
	{ 70, 40, 50, 55, 50, 25, Ice, Water },//Spheal
	{ 90, 60, 70, 75, 70, 45, Ice, Water },//Sealeo
	{ 110, 80, 90, 95, 90, 65, Ice, Water },//Walrein
	{ 35, 64, 85, 74, 55, 32, Water, NUL },//Clamperl
	{ 55, 104, 105, 94, 75, 52, Water, NUL },//Huntail
	{ 55, 84, 105, 114, 75, 52, Water, NUL },//Gorebyss
	{ 100, 90, 130, 45, 65, 55, Water, NUL },//Relicanth
	{ 43, 30, 55, 40, 65, 97, Water, NUL },//Luvdisc
	{ 45, 75, 60, 40, 30, 50, Dragon, NUL },//Bagon
	{ 65, 95, 100, 60, 50, 50, Dragon, NUL },//Shelgon
	{ 95, 135, 80, 110, 80, 100, Dragon, Flying },//Salamence
	{ 40, 55, 80, 35, 60, 30, Steel, Psychic },//Beldum
	{ 60, 75, 100, 55, 80, 50, Steel, Psychic },//Metang
	{ 80, 135, 130, 95, 90, 70, Steel, Psychic },//Metagros
	{ 80, 100, 200, 50, 100, 50, Rock, NUL },//Regirock
	{ 80, 50, 100, 100, 200, 50, Ice, NUL },//Regice
	{ 80, 75, 150, 75, 150, 50, Steel, NUL },//Registeel
	{ 80, 80, 90, 110, 130, 110, Dragon, Psychic },//Latias
	{ 80, 90, 80, 130, 110, 110, Dragon, Psychic },//Latios
	{ 100, 100, 90, 150, 140, 90, Water, NUL },//Kyogre
	{ 100, 150, 140, 100, 90, 90, Ground, NUL },//Groundo
	{ 105, 150, 90, 150, 90, 95, Dragon, Flying },//Rayquaza
	{ 100, 100, 100, 100, 100, 100, Steel, Psychic },//Jirachi
	{ 50, 150, 50, 150, 50, 150, Psychic, NUL },//Deoxys
};

char Data::PokemonName[PokemonDataRange][PokemonNameLength] = {
	"Missingno",
	"Bulbasaur",
	"Ivysaur",
	"Venusaur",
	"Charmander",
	"Charmeleon",
	"Charizard",
	"Squirtle",
	"Wartortle",
	"Blastoise",
	"Caterpie",
	"Metapod",
	"Butterfree",
	"Weedle",
	"Kakuna",
	"Beedrill",
	"Pidgey",
	"Pidgeotto",
	"Pidgeot",
	"Rattata",
	"Raticate",
	"Spearow",
	"Fearow",
	"Ekans",
	"Arboks",
	"Pikachu",
	"Raichu",
	"Sandshrew",
	"Sandslash",
	"Nidoran¡â",
	"Nidorina",
	"Nidoqueen",
	"Nidoran¡â",
	"Nidorino",
	"Nidoking",
	"Clefairy",
	"Clefable",
	"Vulpux",
	"Ninetales",
	"Jigglypuff",
	"Wigglytuff",
	"Zubat",
	"Golbat",
	"Oddish",
	"Gloom",
	"Vileplume",
	"Paras",
	"Parasect",
	"Venonat",
	"Venomoth",
	"Diglett",
	"Dugtrio",
	"Meowth",
	"Persian",
	"Psyduck",
	"Golduck",
	"Mankey",
	"Primeape",
	"Growlithe",
	"Arcanine",
	"Poliwag",
	"Poliwhirl",
	"Poliwrath",
	"Abra",
	"Kadabra",
	"Alakazam",
	"Machop",
	"Machoke",
	"Machamp",
	"Bellsprout",
	"Weepinbell",
	"Victreebel",
	"Tentacool",
	"Tentacruel",
	"Geodude",
	"Graveler",
	"Golem",
	"Ponyta",
	"Rapidash",
	"Slowpoke",
	"Slowbro",
	"Magnemite",
	"Magneton",
	"Farfetch'd",
	"Doduo",
	"Dodrio",
	"Seel",
	"Dewgong",
	"Grimer",
	"Muk",
	"Shellder",
	"Cloyster",
	"Gastly",
	"Haunter",
	"Genger",
	"Onix",
	"Drowzee",
	"Hypono",
	"Krabby",
	"Kingler",
	"Voltorb",
	"Electrobe",
	"Exeggcute",
	"Exeggutor",
	"Cubone",
	"Marowak",
	"Hitmonlee",
	"Hitmonchan",
	"Lickiytung",
	"Koffing",
	"Weezing",
	"Rhyhorn",
	"Rhydon",
	"Chansey",
	"Tangela",
	"Kangaskhan",
	"Horsea",
	"Seadra",
	"Goldeen",
	"Seaking",
	"Staryu",
	"Starmie",
	"Mr.Mine",
	"Scyther",
	"Jynx",
	"Electabuzz",
	"Magmar",
	"Pinsir",
	"Tauros",
	"Magikarp",
	"Gyarados",
	"Lapras",
	"Ditto",
	"Eevee",
	"Vaporeon",
	"Jolteon",
	"Flareon",
	"Polygon",
	"Omanyte",
	"Omastar",
	"Kabuto",
	"Kabutops",
	"Aerodactyl",
	"Snorlax",
	"Articuno",
	"Zapdos",
	"Moltres",
	"Dratini",
	"Dragonair",
	"Dragonite",
	"Mewtwo",
	"Mew",

	//---------------Generation II----------------

	"Chikorita",
	"Bayleef",
	"Meganium",
	"Cyndaquil",
	"Quilava",
	"Typhlosion",
	"Totodile",
	"Croconaw",
	"Feraligatr",
	"Sentret",
	"Furret",
	"Hoothoot",
	"Noctowl",
	"Ledyba",
	"Ledian",
	"Spinarak",
	"Ariados",
	"Crobat",
	"Chinchou",
	"Lanturn",
	"Pichu",
	"Cleffa",
	"Lgglybuff",
	"Togepi",
	"Togetic",
	"Natu",
	"Xatu",
	"Mareep",
	"Flaaffy",
	"Ampharos",
	"Bellossom",
	"Marill",
	"Azumarill",
	"Sudowoodo",
	"Politoed",
	"Hoppip",
	"Skiploom",
	"Jumpluff",
	"Aipom",
	"Sunkern",
	"Sunflora",
	"Yanman",
	"Wooper",
	"Quagsire",
	"Espeon",
	"Umbreon",
	"Murkrow",
	"Slowking",
	"Misdreavus",
	"Unown",
	"Wobbuffet",
	"Girafarig",
	"Pineco",
	"Forretress",
	"Dunsparce",
	"Gligar",
	"Steelix",
	"Snubbull",
	"Granbull",
	"Qwilfish",
	"Scizor",
	"Shuckle",
	"Heracross",
	"Sneasel",
	"Teddiursa",
	"Ursaring",
	"Slugma",
	"Magcargo",
	"Swinub",
	"Piloswine",
	"Corsola",
	"Remoraid",
	"Octillery",
	"Delibird",
	"Mantine",
	"Skarmory",
	"Houndour",
	"Houndoom",
	"Kingdra",
	"Phanpy",
	"Donphan",
	"Porygon2",
	"Stantler",
	"Smeargle",
	"Tyrogue",
	"Hitmontop",
	"Smoochun",
	"Elekid",
	"Magby",
	"Miltank",
	"Blissey",
	"Raikou",
	"Entei",
	"Suicune",
	"Larvitar",
	"Pupitar",
	"Tyranitar",
	"Lugia",
	"Ho-oh",
	"Celebi",

	//-----------------Generation III----------------------

	"Treecko",
	"Grovyle",
	"Sceptile",
	"Torchic",
	"Combusken",
	"Blaziken",
	"Mudkip",
	"Marshtomp",
	"Swampert",
	"Poochyena",
	"Mightyena",
	"Zigzagoon",
	"Linoone",
	"Wurmple",
	"Silcoon",
	"Beautifly",
	"Cascoon",
	"Dustox",
	"Lotad",
	"Lombre",
	"Ludicolo",
	"Seedot",
	"Nuzleaf",
	"Shiftry",
	"Taillow",
	"Swellow",
	"Wingull",
	"Pelipper",
	"Ralts",
	"Kirlia",
	"Gardevoir",
	"Surskit",
	"Masquerain",
	"Shroomish",
	"Breloom",
	"Slakoth",
	"Vigoroth",
	"Slaking",
	"Nincada",
	"Ninjask",
	"Shedinja",
	"Whismur",
	"Loudred",
	"Exploud",
	"Makuhita",
	"Hariyama",
	"Azurill",
	"Nosepass",
	"Skitty",
	"Delcatty",
	"Sableye",
	"Mawile",
	"Aron",
	"Lairon",
	"Aggron",
	"Meditite",
	"Medicham",
	"Electrike",
	"Manectric",
	"Plusle",
	"Minun",
	"Volbeat",
	"Illumise",
	"Roselia",
	"Gulpin",
	"Swalot",
	"Carvanha",
	"Sharpedo",
	"Wailmer",
	"Wailord",
	"Numel",
	"Camerupt",
	"Torkoal",
	"Spoink",
	"Grumpig",
	"Spinda",
	"Trapinch",
	"Vibrava",
	"Flygon",
	"Cacnea",
	"Cacturne",
	"Swablu",
	"Altaria",
	"Zangoose",
	"Seviper",
	"Lunatone",
	"Solrock",
	"Barboach",
	"Whiscash",
	"Corphish",
	"Crawdaunt",
	"Baltoy",
	"Claydol",
	"Lileep",
	"Cradily",
	"Anorith",
	"Armaldo",
	"Feebas",
	"Milotic",
	"Castform",
	"Kecleon",
	"Shuppet",
	"Banette",
	"Duskull",
	"Dusclops",
	"Tropius",
	"Chimecho",
	"Absol",
	"Wynaut",
	"Snorunt",
	"Glalie",
	"Spheal",
	"Sealeo",
	"Walrein",
	"Clamperl",
	"Huntail",
	"Gorebyss",
	"Relicanth",
	"Luvdisc",
	"Bagon",
	"Shelgon",
	"Salamerce",
	"Beldum",
	"Metang",
	"Metagross",
	"Regirock",
	"Regice",
	"Registeel",
	"Latias",
	"Latios",
	"Kyogre",
	"Groundo",
	"Rayquaza",
	"Jirachi",
	"Deoxys"
};

//Type,Category,Power,Accuracy,PP,HitTimes,CriticalHit,Priority,touch,voice,protectMode
int Data::SkillData[SkillDataRange][11] = {
	{ NUL, Physical, 30, 10000, 1000, 1, 1, 0, 1, 0, 0 },//拼命
	{ Normal, Physical, 40, 100, 56, 1, 1, 0, 1, 0, 0 },//Pound
	{ Fighting, Physical, 50, 100, 40, 1, 1, 0, 1, 0, 0 },//Karate Chop
	{ Normal, Physical, 15, 85, 16, 5, 1, 0, 1, 0, 0 },//Double Slap
	{ Normal, Physical, 18, 85, 24, 5, 1, 0, 1, 0, 0 },//Comet Punch
	{ Normal, Physical, 80, 85, 32, 1, 1, 0, 1, 0, 0 },//Mega Punch
	{ Normal, Physical, 40, 100, 32, 1, 1, 0, 1, 0, 0 },//Pay Day
	{ Fire, Physical, 75, 100, 24, 1, 1, 0, 1, 0, 0 },//Fire Punch
	{ Ice, Physical, 75, 100, 24, 1, 1, 0, 1, 0, 0 },//Ice Punch
	{ Electric, Physical, 75, 100, 24, 1, 1, 0, 1, 0, 0 },//Thunder Punch
	{ Normal, Physical, 40, 100, 56, 1, 1, 0, 1, 0, 0 },//Scratch
	{ Normal, Physical, 55, 100, 48, 1, 1, 0, 1, 0, 0 },//Vice Grip
	{ Normal, Physical, 50000, 100, 8, 1, 1, 0, 1, 0, 0 },//Guillotine
	{ Normal, Special, 80, 100, 16, 1, 2, 0, 0, 0, 0 },//Razor Wind
	{ Normal, Other, 0, 100, 32, 1, 1, 0, 0, 0, 0 },//Sword Dance
	{ Normal, Physical, 50, 95, 48, 1, 1, 0, 1, 0, 0 },//cut
	{ Flying, Special, 40, 100, 56, 1, 1, 0, 0, 0, 0 },//Gust
	{ Flying, Physical, 60, 100, 56, 1, 1, 0, 1, 0, 0 },//Wing Attack
	{ Normal, Other, 0, 100, 32, 1, 1, -6, 0, 0, 0 },//Whirlwind
	{ Flying, Physical, 90, 95, 24, 1, 1, 0, 1, 0, 0 },//Fly
	{ Normal, Physical, 15, 85, 32, 1, 1, 0, 1, 0, 0 },//Bind
	{ Normal, Physical, 80, 75, 32, 1, 1, 0, 1, 0, 0 },//Slam
	{ Grass, Physical, 45, 100, 40, 1, 1, 0, 1, 0, 0 },//Vine Whip
	{ Normal, Physical, 65, 100, 32, 1, 1, 0, 1, 0, 0 },//Stomp
	{ Fighting, Physical, 30, 100, 48, 2, 1, 0, 1, 0, 0 },//Double Kick
	{ Normal, Physical, 120, 75, 8, 1, 1, 0, 1, 0, 0 },//Mega Kick
	{ Fighting, Physical, 100, 95, 16, 1, 1, 0, 1, 0, 0 },//Jump Kick
	{ Fighting, Physical, 60, 85, 24, 1, 1, 0, 1, 0, 0 },//Rolling Kick
	{ Ground, Other, 0, 100, 24, 1, 1, 0, 0, 0, 0 },//Sand Attack
	{ Normal, Physical, 70, 100, 24, 1, 1, 0, 1, 0, 0 },//Headbutt
	{ Normal, Physical, 65, 100, 40, 1, 1, 0, 1, 0, 0 },//Horn Attack
	{ Normal, Physical, 15, 85, 32, 5, 1, 0, 1, 0, 0 },//Fury Attack
	{ Normal, Physical, 50000, 100, 8, 1, 1, 0, 1, 0, 0 },//Horn Drill
	{ Normal, Physical, 50, 100, 56, 1, 1, 0, 1, 0, 0 },//Tackle
	{ Normal, Physical, 85, 100, 24, 1, 1, 0, 1, 0, 0 },//Body Slam
	{ Normal, Physical, 15, 90, 32, 1, 1, 0, 1, 0, 0 },//Wrap
	{ Normal, Physical, 90, 85, 32, 1, 1, 0, 1, 0, 0 },//Take Down
	{ Normal, Physical, 120, 100, 16, 1, 1, 0, 1, 0, 0 },//Thrash
	{ Normal, Physical, 120, 100, 24, 1, 1, 0, 1, 0, 0 },//Double-Edge
	{ Normal, Other, 0, 100, 48, 1, 1, 0, 0, 0, 0 },//Tail Whip
	{ Poison, Physical, 15, 100, 56, 1, 1, 0, 0, 0, 0 },//Poison Sting
	//Type,Category,Power,Accuracy,PP,HitTimes,CriticalHit,Priority,touch,voice,protectMode
	{ Bug, Physical, 25, 100, 32, 2, 1, 0, 1, 0, 0 },//Twineedle
	{ Bug, Physical, 25, 95, 32, 5, 1, 0, 0, 0, 0 },//Pin Missile
	{ Normal, Other, 0, 100, 48, 1, 1, 0, 0, 0, 0 },//Leer
	{ Dark, Physical, 60, 100, 40, 1, 1, 0, 1, 0, 0 },//Bite
	{ Normal, Other, 0, 100, 64, 1, 1, 0, 0, 1, 0 },//Growl
	{ Normal, Other, 0, 100, 32, 1, 1, -6, 0, 1, 0 },//Roar
	{ Normal, Other, 0, 55, 24, 1, 1, 0, 0, 1, 0 },//Sing
	{ Normal, Other, 0, 55, 32, 1, 1, 0, 0, 1, 0 },//Supersonic
	{ Normal, Special, 20, 90, 32, 1, 1, 0, 0, 1, 0 },//Sonic Boom
	{ Normal, Other, 0, 100, 32, 1, 1, 0, 0, 1, 0 },//Disable
	{ Poison, Special, 40, 100, 48, 1, 1, 0, 0, 0, 0 },//Acid
	{ Fire, Special, 40, 100, 40, 1, 1, 0, 0, 0, 0 },//Ember
	{ Fire, Special, 90, 100, 24, 1, 1, 0, 0, 0, 0 },//Flamethrower
	{ Ice, Other, 0, 10000, 48, 1, 1, 0, 0, 0, 0 },//Mist
	{ Water, Special, 40, 100, 40, 1, 1, 0, 0, 0, 0 },//Water Gun
	{ Water, Special, 110, 80, 8, 1, 1, 0, 0, 0, 0 },//Hydro Pump
	{ Water, Special, 90, 100, 24, 1, 1, 0, 0, 0, 0 },//Surf
	{ Ice, Special, 90, 100, 16, 1, 1, 0, 0, 0, 0 },//Ice Beam
	{ Ice, Special, 110, 70, 8, 1, 1, 0, 0, 0, 0 },//Blizzard
};

char Data::SkillName[SkillDataRange][SkillNameLength] = {
	"Struggle",
	"Pound",
	"Karate Chop",
	"Double Slap",
	"Comet Punch",
	"Mega Punch",
	"Pay Day",
	"Fire Punch",
	"Ice Punch",
	"Thunder Punch",
	"Scratch",
	"Vice Grip",
	"Guillotine",
	"Razor Wind",
	"Sword Dance",
	"Cut",
	"Gust",
	"Wing Attack",
	"Whirlwind",
	"Fly",
	"Bind",
	"Slam",
	"Vine Whip",
	"Stomp",
	"Double Kick",
	"Mega Kick",
	"Jump Kick",
	"Rolling Kick",
	"Sand Attack",
	"Headbutt",
	"Horn Attack",
	"Fury Attack",
	"Horn Drill",
	"Tackle",
	"Body Slam",
	"Wrap",
	"Take Down",
	"Thrash",
	"Double-Edge",
	"Tail Whip",
	"Poison Sting",
	"Twineedle",
	"Pin Missile",
	"Leer",
	"Bite",
	"Growl",
	"Roar",
	"Sing",
	"Supersonic",
	"Sonic Boom",
	"Disable",
	"Acid",
	"Ember",
	"Flamethrower",
	"Mist",
	"Water Gun",
	"Hydro Pump",
	"Surf",
	"Ice Beam",
	"Blizzard"
};

char Data::ItemName[ItemRange][ItemNameLength] = {
	"Empty",
	"Cherry No.11",
	"Cherry No.12",
	"Cherry No.13",	
	"Absorb Bulb",
	"Adamant Orb",
	"Aguav Berry",
	"Air Balloon",
	"Apicot Berry",
	"Aspear Berry",
	"Assault Vest",
	
	"Babiri Berry",	
	"Berry Juice",
	"Big Root",
	"Binding Band",
	"Black Belt",
	"Black Glasses",
	"Black Sludge",
	"Blue Orb",
	"Bright Powder",
	"Bug Gem",
	"Burn Drive",
	"Cell Battery",
	"Charcoal",
	"Charti Berry",
	"Cheri Berry",
	"Chesto Berry",
	"Chilan Berry",
	"Chill Drive",
	"Choice Band",
	"Choice Scarf",
	"Choice Specs",
	"Coba Berry",
	"Colbur Berry",
	"Custap Berry",

	"Abomasite",
	"Absolite",
	"Aerodactylite",
	"Aggronite",
	"Alakazite",
	"Altarianite",
	"Ampharosite",
	"Audinite",
	"Banettite",
	"Beedrillite",
	"Blastoisinite",
	"Blazikenite",
	"Cameruptite",
	"CharizarditeX",
	"CharizarditeY"
};

char Data::AbilityName[AbilityRange][AbilityNameLength] = {
	"Disabled",
	"Stench",
	"Drizzle",
	"Speed Boost",
	"Battle Armor",
	"Sturdy",
	"Damp",
	"Limber",
	"Sand Veil",
	"Static",
	"Volt Absorb",
	"Water Absorb",
	"Oblivious",
	"Cloud Nine",
	"Compoundeyes",
	"Insomnia",
	"Color Change",
	"Immunity",
	"Flash Fire",
	"Shield Dust",
	"Own Tempo",
	"Suction Cups",
	"Intimidate",
	"Shadow Tag",
	"Rough Skin",
	"Wonder Guard",
	"Levitate",
	"Effect Spore",
	"Synchronize",
	"Clear Body",
	"Natural Cure",
	"Lightningrod",
	"Serene Grace",
	"Swift Swim",
	"Chlorophyll",
	"Illuminate",
	"Trace",
	"Huge Power",
	"Poison Point",
	"Inner Focus",
	"Magma Armor",
	"Water Veil",
	"Magnet Pull",
	"Soundproof",
	"Rain Dish",
	"Sand Stream",
	"Pressure",
	"Thick Fat",
	"Early Bird",
	"Flame Body",
	"Run Away",
	"Keen Eye",
	"Hyper Cutter",
	"Pickup",
	"Truant",
	"Hustle",
	"Cute Charm",
	"Plus",
	"Minus",
	"Forecast",
	"Sticky Hold",
	"Shed Skin",
	"Guts",
	"Marvel Scale",
	"Liquid Ooze",
	"Overgrow",
	"Blaze",
	"Torrent",
	"Swarm",
	"Rock Head",
	"Drought",
	"Arena Trap",
	"Vital Spirit",
	"White Smoke",
	"Pure Power",
	"Shell Armor",
	"Air Lock",
};