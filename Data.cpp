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
	{ 79, 83, 100, 85, 105, 78, Water, NUL }//Blastoise
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
	"Blastoise"
};

//Type,Category,Power,Accuracy,PP,HitTimes,CriticalHit,Priority,touch
int Data::SkillData[SkillDataRange][9] = {
	{ NUL, Physical, 30, 10000, 1000, 1, 1, 0, 1 },//Æ´Ãü
	{ Normal, Physical, 40, 100, 56, 1, 1, 0, 1 },//Pound
	{ Fighting, Physical, 50, 100, 40, 1, 1, 0, 1 },//Karate Chop
	{ Normal, Physical, 15, 85, 16, 5, 1, 0, 1 },//Double Slap
	{ Normal, Physical, 18, 85, 24, 5, 1, 0, 1 },//Comet Punch
	{ Normal, Physical, 80, 85, 20, 1, 1, 0, 1 }//Mega Punch
};

char Data::SkillName[SkillDataRange][SkillNameLength] = {
	"Missingno",
	"Pound",
	"Karate Chop",
	"Double Slap",
	"Comet Punch",
	"Mega Punch"
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
	"Huge Power"
};