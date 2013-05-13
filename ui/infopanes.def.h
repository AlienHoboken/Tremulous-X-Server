#include "/home/tma/tremulous/src/game/tremulous.h"

#define CREDITS(X) text "Credits: " text X
#define HUMAN_BCOST(X) text "Power: " text X
#define ALIEN_BCOST(X) text "Sentience: " text X

//team menu

{
  name alienteam
  text "The Alien Team\n\n"
  text "The Aliens' strengths are in movement "
  text "and the ability to quickly construct new bases quickly. They possess a "
  text "range of abilities including basic melee attacks, movement-"
  text "crippling poisons and more."
  align left
}

{
  name humanteam
  text "The Human Team\n\n"
  text "The humans are the masters of technology. Although their bases take "
  text "long to construct, their automated defense ensures they stay built. "
  text "A wide range of upgrades and weapons are available to the humans, each "
  text "contributing to eradicate the alien threat."
  align left
}

{
  name spectateteam
  text "Watch the game without playing."
}

{
  name autoteam
  text "Join the team with the least players."
}


//human items

{
  name rifleitem
  text "Rifle\n\n"
  text "Basic weapon. Cased projectile weapon, with a slow clip based "
  text "reload system.\n\n"
  text "Credits: Free"
}

{
  name ckititem
  text "Construction kit\n\n"
  text "Used for building all basic structures. This includes "
  text "spawns, power and basic defense.\n\n"
  text "Credits: Free"
}

{
  name ackititem
  text "Advanced Construction kit\n\n"
  text "Used for building advanced structures. This includes "
  text "combat computers and advanced defense.\n\n"
  text "Credits: Free"
}

{
  name shotgunitem
  text "Shotgun\n\n"
  text "Close range weapon that is useful against larger foes. "
  text "It has a slow repeat rate, but can be devastatingly "
  text "effective.\n\n"
  CREDITS( SHOTGUN_PRICE )
}

{
  name chaingunitem
  text "Chain Gun\n\n"
  text "Belt drive, cased projectile weapon. It has a high "
  text "repeat rate but a wide firing angle and is therefore relatively "
  text "inaccurate.\n\n"
  CREDITS( CHAINGUN_PRICE )
}

{
  name flameritem
  text "Flamethrower\n\n"
  text "Sprays fire at its target. It is powered by compressed "
  text "gas. The relatively low rate of fire means this weapon is most "
  text "effective against static targets.\n\n"
  CREDITS( FLAMER_PRICE )
}

{
  name mdriveritem
  text "Mass Driver\n\n"
  text "A portable particle accelerator which causes minor "
  text "nuclear reactions at the point of impact. It has a very large "
  text "payload, but fires slowly.\n\n"
  CREDITS( MDRIVER_PRICE )
}

{
  name prifleitem
  text "Pulse Rifle\n\n"
  text "An energy weapon that fires pulses of concentrated energy at a fast "
  text "rate. It requires re-energising every 50 pulses.\n\n"
  CREDITS( PRIFLE_PRICE )
}

{
  name lcannonitem
  text "Lucifer Cannon\n\n"
  text "Similar to the pulse rifle, but more powerful. "
  text "Additionally, it has a secondary attack where energy can be charged "
  text "up to shoot a devastating ball of energy.\n\n"
  CREDITS( LCANNON_PRICE )
}

{
  name lgunitem
  text "Las Gun\n\n"
  text "Slightly more powerful than the basic rifle, but "
  text "instead of bullets it fires small packets of energy.\n\n"
  CREDITS( LASGUN_PRICE )
}

{
  name psawitem
  text "Pain Saw\n\n"
  text "Similar to a chainsaw, but instead of a chain "
  text "it has an electric arc capable of dealing a great deal of damage at "
  text "close range.\n\n"
  CREDITS( PAINSAW_PRICE )
}

{
  name grenitem
  text "Grenade\n\n"
  text "A small incendinary device ideal for damaging tightly packed "
  text "alien structures. Has a five second timer.\n\n"
  CREDITS( GRENADE_PRICE )
}

{
  name larmouritem
  text "Light Armour\n\n"
  text "Protective armour that helps to defend against light alien melee "
  text "attacks.\n\n"
  CREDITS( LIGHTARMOUR_PRICE )
}

{
  name helmetitem
  text "Helmet\n\n"
  text "In addition to protecting your head, the helmet provides a "
  text "scanner indicating the presence of any non-human lifeforms in your "
  text "immediate vicinity.\n\n"
  CREDITS( HELMET_PRICE )
}

{
  name battpackitem
  text "Battery Pack\n\n"
  text "Back-mounted battery pack that permits storage of one and a half "
  text "times the normal energy capacity for energy weapons.\n\n"
  CREDITS( BATTPACK_PRICE )
}

{
  name jetpackitem
  text "Jet Pack\n\n"
  text "Back-mounted jet pack that enables the user to fly to remote "
  text "locations. It is very useful against alien spawns in hard to reach "
  text "spots.\n\n"
  CREDITS( JETPACK_PRICE )
}

{
  name bsuititem
  text "Battle Suit\n\n"
  text "A full body armour that is highly effective at repelling alien attacks. "
  text "It allows the user to enter hostile situations with a greater degree "
  text "of confidence.\n\n"
  CREDITS( BSUIT_PRICE )
}

{
  name ammoitem
  text "Ammunition\n\n"
  text "Ammunition for the currently held weapon.\n\n"
  text "Credits: Free"
}


//human structures

{
  name telenodebuild
  text "Telenode\n\n"
  text "The most basic human structure. It provides a means for "
  text "humans to enter the battle arena. Without any of these the humans "
  text "cannot spawn and defeat is imminent.\n\n"
  HUMAN_BCOST( HSPAWN_BP )
}

{
  name mgturretbuild
  text "Machine Gun Turret\n\n"
  text "Automated base defense that is effective against fast moving targets, but "
  text "does not cause much damage on its own and should "
  text "always be backed up by physical support.\n\n"
  HUMAN_BCOST( MGTURRET_BP )
}

{
  name armbuild
  text "Armoury\n\n"
  text "An essential part of the human base, providing a means "
  text "to upgrade the basic human. A range of upgrades and weapons are "
  text "available from the armoury, each with a price.\n\n"
  HUMAN_BCOST( ARMOURY_BP )
}

{
  name medistatbuild
  text "Medistation\n\n"
  text "A structure providing an automated healing energy that restores "
  text "the health of any human that stands inside it. It may only be used "
  text "by one person at a time.\n\n"
  HUMAN_BCOST( MEDISTAT_BP )
}

{
  name reactorbuild
  text "Reactor\n\n"
  text "All structures except the telenode rely on a reactor to operate."
  text "The reactor provides power for all the human structures either "
  text "directly or via repeaters. There can only be a single reactor.\n\n"
}

{
  name dccbuild
  text "Defense Computer\n\n"
  text "A structure coordinating the action of base defense so that "
  text "defense is distributed evenly among the enemy. "
  text "This structure is required for building the Tesla Generator.\n\n"
  HUMAN_BCOST( DC_BP )
}

{
  name teslabuild
  text "Tesla Generator\n\n"
  text "A structure equipped with a strong electrical attack that always "
  text "hits its target. It is useful against larger aliens "
  text "and for consolidating basic defense.\n\n"
  HUMAN_BCOST( TESLAGEN_BP )
}

{
  name repeaterbuild
  text "Repeater\n\n"
  text "A power distributor that transmits power from the reactor "
  text "to remote locations, so that bases may be built far from the reactor.\n\n"
}

//alien structures

{
  name eggpodbuild
  text "Egg\n\n"
  text "The most basic alien structure. It allows aliens to spawn "
  text "and protect the Overmind. Without any of these, the Overmind is left "
  text "nearly defenseless and defeat is imminent.\n\n"
  ALIEN_BCOST( ASPAWN_BP )
}

{
  name overmindbuild
  text "Overmind\n\n"
  text "A collective consciousness that controls all the "
  text "alien structures in its vicinity. It must be protected at all costs, "
  text "since its death will render alien structures defenseless."
}

{
  name barricadebuild
  text "Barricade\n\n"
  text "Used to obstruct corridors and doorways, "
  text "hindering humans from threatening the spawns and Overmind.\n\n"
  ALIEN_BCOST( BARRICADE_BP )
}

{
  name acid_tubebuild
  text "Acid Tube\n\n"
  text "Ejects lethal poisonous "
  text "acid at an approaching human. These are highly effective when used in "
  text "conjunction with a trapper to hold the victim in place.\n\n"
  ALIEN_BCOST( ACIDTUBE_BP )
}

{
  name hivebuild
  text "Hive\n\n"
  text "Houses millions of tiny "
  text "insectoid aliens. When a human approaches this structure, the "
  text "insectoids attack.\n\n"
  ALIEN_BCOST( HIVE_BP )
}

{
  name trapperbuild
  text "Trapper\n\n"
  text "Fires a blob of adhesive spit at any non-alien in its "
  text "line of sight. This hinders their movement, making them an easy target "
  text "for other defensive structures or aliens.\n\n"
  ALIEN_BCOST( TRAPPER_BP )
}

{
  name boosterbuild
  text "Booster\n\n"
  text "Provides any alien with a poison ability on all its "
  text "attacks. In addition to the default attack damage, the victim loses "
  text "health over time unless they heal themselves with a medkit."
  text "The booster also increases the rate of health regeneration for "
  text "any nearby aliens.\n\n"
  ALIEN_BCOST( BOOSTER_BP )
}

{
  name hovelbuild
  text "Hovel\n\n"
  text "An armoured shell used by the builder class to "
  text "hide in, while the alien base is under attack. It may be entered or "
  text "exited at any time."
}

//alien classes

{
  name builderclass
  text "Granger\n\n"
  text "Responsible for building and maintaining all "
  text "the alien structures."
}

{
  name builderupgclass
  text "Advanced Granger\n\n"
  text "Similar to the base Granger, "
  text "except that in addition to being able to build structures it has a "
  text "melee attack and the ability to crawl on walls."
}

{
  name level0class
  text "Dretch\n\n"
  text "Has a lethal bite and the ability to crawl "
  text "on walls and ceilings."
}

{
  name level1class
  text "Basilisk\n\n"
  text "Able to crawl on walls and ceilings. "
  text "Its melee attack is most effective when combined with the ability to "
  text "grab its foe."
}

{
  name level1upgclass
  text "Advanced Basilisk\n\n"
  text "In addition to the basic Basilisk abilities, the Advanced "
  text "Basilisk sprays a poisonous gas which disorientaits any "
  text "nearby humans."
}

{
  name level2class
  text "Marauder\n\n"
  text "Has a melee attack and the ability to jump off walls."
  text "This allows the Marauder to gather great speed in enclosed areas."
}

{
  name level2upgclass
  text "Advanced Marauder\n\n"
  text "The Advanced Marauder has all the abilities of the base Marauder "
  text "including an area effect electric shock attack."
}

{
  name level3class
  text "Dragoon\n\n"
  text "Possesses a melee attack and the pounce ability, which may "
  text "be used as an attack, or a means to reach a remote location inaccessible "
  text "from the ground."
}

{
  name level3upgclass
  text "Advanced Dragoon\n\n"
  text "In addition to the basic Dragoon abilities, the Dragoon Upgrade has "
  text "3 barbs which may be used to attack humans from a distance."
}

{
  name level4class
  text "Tyrant\n\n"
  text "Provides a healing aura in which nearby aliens regenerate health "
  text "faster than usual. As well as a melee attack, this class can charge "
  text "at enemy humans and structures, inflicting great damage."
}

// graphic <top|bottom|left|right> <center|some numerical offset> <shadername> <width> <height>
// graphic left center "gfx/blah" 64 128
