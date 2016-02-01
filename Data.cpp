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

//Type,Category,Power,Accuracy,PP,HitTimes,CriticalHit,Priority,touch,voice,protectMode
int Data::SkillData[SkillDataRange][11] = {
	{ NUL, Physical, 30, 10000, 1000, 1, 1, 0, 1, 0, 0 },//Æ´Ãü
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