#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void player_abilities(int num_players);
void slot_sorting(int num_slots, int rand_num);

struct players
{
	char player_name[100];
	char type [100];
	int Life_pts;
	int Smartness;
	int Strength;
	int Magic_Skills;
	int	Luck;
	int Dexterity;
	char position;
};

struct slots
{
	char terrain[100];
	int pos_players;
	int curr_pos;
};

int num_players, i;
int num_slots = 0;
struct players players_array[100];
struct slots array2[100];

int main(void)
{
	int rand_num;
	
	num_players = 0;
	
	while(num_players<1 || num_players>6)
	{
		printf("enter number of players(max 6): ");
		scanf("%d", &num_players);
	}
	
	for(i=0; i<num_players; i++)
	{
		printf("\nenter player%d name: ", i+1);
		scanf("%s", &players_array[i].player_name);
		
		while(strcmp(players_array[i].type, "elf" )!=0 && strcmp(players_array[i].type, "human" )!=0 && strcmp(players_array[i].type, "ogre" )!=0 && strcmp(players_array[i].type, "wizard" )!=0)
		{
			printf("%s enter your player type (elf, human, ogre, wizard) : ", &players_array[i].player_name);
			scanf("%s", &players_array[i].type);
		}
	}
	
	while(num_slots<num_players || num_slots>20)
	{
		printf("\nenter number of slots(max 20): ");
		scanf("%d", &num_slots);
	}
	
	slot_sorting(num_slots, rand_num);
	player_abilities(num_players);

}

void slot_sorting(int num_slots, int rand_num)
{
	srand(time(NULL));//makes rand random
	
	for(i=0; i<num_slots; i++)
	{
		rand_num = ((rand() %3)+1);
	
		if(rand_num == 1) 
		{
			strcpy(array2[i].terrain, "Level Ground");
			printf("%s\n", array2[i].terrain);
		}
		else if(rand_num == 2) 
		{
			strcpy(array2[i].terrain, "Hill");
			printf("%s\n", array2[i].terrain);
		}
		else
		{
			strcpy(array2[i].terrain, "City");
			printf("%s\n", array2[i].terrain);
		}
	}
}

void player_abilities(int num_players)
{
	printf("\nPlayer Capabilities: \n");

	for(i=0; i<num_players; i++)
	{
		if(strcmp(players_array[i].type,"ogre")==0)
		{
			players_array[i].Luck = 60;
			players_array[i].Magic_Skills=0;
			players_array[i].Smartness = (rand() %21);
			players_array[i].Strength = ((rand() %21)+80);
			players_array[i].Dexterity = ((rand() %21)+80);
			while(players_array[i].Luck+players_array[i].Smartness>50)
			{
				players_array[i].Luck = (rand() %51);
			}
			printf("\nPlayer %s, Type: %s ", players_array[i].player_name, players_array[i].type);
			printf("\nMagic slots: %d\n", players_array[i].Magic_Skills);
			printf("Smartness: %d\n", players_array[i].Smartness);
			printf("Strength: %d\n", players_array[i].Strength);
			printf("Dexterity: %d\n", players_array[i].Dexterity);
			printf("Luck: %d\n", players_array[i].Luck);
		}

		if(strcmp(players_array[i].type,"human")==0)
		{
			players_array[i].Magic_Skills = 100;
			players_array[i].Smartness = 100;
			players_array[i].Strength = 100;
			players_array[i].Dexterity = 100;
			players_array[i].Luck = 100;

			while(players_array[i].Magic_Skills+players_array[i].Smartness+players_array[i].Strength+players_array[i].Dexterity+players_array[i].Luck>=300)
			{

				players_array[i].Magic_Skills = ((rand() %100)+1);
				players_array[i].Smartness = ((rand() %100)+1);
				players_array[i].Strength = ((rand() %100)+1);
				players_array[i].Dexterity = ((rand() %100)+1);
				players_array[i].Luck = ((rand() %100)+1);
			}

			printf("\nPlayer %s, Type: %s", players_array[i].player_name, players_array[i].type);
			printf("\nMagic slots: %d\n", players_array[i].Magic_Skills);
			printf("Smartness: %d\n", players_array[i].Smartness);
			printf("Strength: %d\n", players_array[i].Strength);
			printf("Dexterity: %d\n", players_array[i].Dexterity);
			printf("Luck: %d\n", players_array[i].Luck);
		}

		if(strcmp(players_array[i].type,"wizard")==0)
		{
			players_array[i].Magic_Skills = ((rand() %21)+80);
			players_array[i].Smartness = ((rand() %11)+90);
			players_array[i].Strength = ((rand() %20)+1);
			players_array[i].Dexterity = ((rand() %100)+1);
			players_array[i].Luck = ((rand() %51)+50);

			

			printf("\nPlayer %s, Type: %s ", players_array[i].player_name, players_array[i].type);
			printf("\nMagic slots: %d\n", players_array[i].Magic_Skills);
			printf("Smartness: %d\n", players_array[i].Smartness);
			printf("Strength: %d\n", players_array[i].Strength);
			printf("Dexterity: %d\n", players_array[i].Dexterity);
			printf("Luck: %d\n", players_array[i].Luck);

		}

		if(strcmp(players_array[i].type,"elf")==0)

		{

			players_array[i].Magic_Skills = 0;
			players_array[i].Smartness = ((rand() %31)+70);
			players_array[i].Strength = ((rand() %50)+1);
			players_array[i].Dexterity = ((rand() %100)+1);
			players_array[i].Luck = ((rand() %41)+60);

			while(players_array[i].Magic_Skills<=50)

			{
				players_array[i].Magic_Skills = ((rand() %30)+50);
			}

			printf("\nPlayer %s, Type: %s ", players_array[i].player_name, players_array[i].type);
			printf("\nMagic slots: %d\n", players_array[i].Magic_Skills);
			printf("Smartness: %d\n", players_array[i].Smartness);
			printf("Strength: %d\n", players_array[i].Strength);
			printf("Dexterity: %d\n", players_array[i].Dexterity);
			printf("Luck: %d\n", players_array[i].Luck);

		}
	}
}