# Comp10050
Software engineering project
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/*Program by Alen Thomas 16333003 and Sam Bates*/

void player_abilities(int num_players);					//Function prototypes
void slot_sorting(int num_slots, int rand_num, int num_players);
void move_player(int num_slots, int num_players, int k);
void attack_player(int num_slots, int num_players, int k);


struct players				//Struct containing different variables for the player
{
	char player_name[100];
	char type [100];
	int Life_pts;
	int Smartness;
	int Strength;
	int Magic_Skills;
	int Luck;
	int Dexterity;
	int position;
};


struct slots			//Slot structure to sort players
{
	char terrain[100];
	char player_inf[100];
	char type_inf[100];
};

int num_players, i, j;		//Global variable declaration
int num_slots = 0;
struct players players_array[100];	//Arrays of structs
struct slots array2[100];

int main(void)
{
	int rand_num;
	int n, k;
	
	num_players = 0;
	
	while(num_players<1 || num_players>6)			//While loop where user inputs number of players
	{							//If user inputs less than 1 or more than 6 it keeps asking the user
		printf("enter number of players(max 6): ");
		scanf("%d", &num_players);
	}
	
	for(i=0; i<num_players; i++)				//User inputs name
	{
		printf("\nenter player %d name: ", i+1);
		scanf("%s", &players_array[i].player_name);
		
		//User chooses the type of character they want to be
		
		while(strcmp(players_array[i].type, "elf" )!=0 && strcmp(players_array[i].type, "human" )!=0 &&			 strcmp(players_array[i].type, "ogre" )!=0 && strcmp(players_array[i].type, "wizard" )!=0)
		{
			printf("%s enter your player type (elf, human, ogre, wizard) : ", &players_array[i].player_name);
			scanf("%s", &players_array[i].type);
		}
	}
	
	while(num_slots<num_players || num_slots>20)
	{
		printf("\nenter number of slots(max 20): ");	//User chooses number of slots
		scanf("%d", &num_slots);
	}
	
	player_abilities(num_players);		//Call function to sort abilities based on the character type they choose
	
	printf("\n");
	
	slot_sorting(num_slots, rand_num, num_players);	//Call function to sort players into slots and generate slots
	
	printf("Move player/Attack Player \n\n");	//User asked wht type of step they want to take 
	printf("1 - Move player \n");
	printf("2 - Attack nearest Player \n\n");
	
	for( k = 0 ; k < num_players ; k++ )
	{
		printf("Player: %s \n", players_array[k].player_name);
		printf("Please enter what you would like to do with your %s:", players_array[k].type);
		
		scanf("%d", &n);
		
		if( n == 1 )
		{
			move_player(num_slots, num_players, k);
		}
		if( n == 2 )
		{
			attack_player(num_slots, num_players, k);
		}
		
	}
	
	for( i = 0; i < num_players; i++ )
	{
		printf("%s (%s, %d)\n", players_array[i].player_name, players_array[i].type, players_array[i].Life_pts);
	}

}

void slot_sorting(int num_slots, int rand_num, int num_players)
{
	srand(time(NULL));//makes rand random
	char m;
	
	printf("Slots: \n\n");
	
	for(i=0; i<num_slots; i++)
	{
		rand_num = ((rand() %3)+1);
		
		if(rand_num == 1) 
		{
			strcpy(array2[i].terrain, "Level Ground");
			strcpy(array2[i].player_inf, "empty");
			strcpy(array2[i].type_inf, "empty");
		}
		else if(rand_num == 2) 
		{
			strcpy(array2[i].terrain, "Hill");
			strcpy(array2[i].player_inf, "empty");
			strcpy(array2[i].type_inf, "empty");
		}
		else
		{
			strcpy(array2[i].terrain, "City");
			strcpy(array2[i].player_inf, "empty");
			strcpy(array2[i].type_inf, "empty");
		}
	}
	
	for( i = 0; i < num_players; i++ )
	{
		j = (rand() % num_slots);
		
		strcpy(array2[j].player_inf, players_array[i].player_name);
		strcpy(array2[j].type_inf, players_array[i].type);	
		players_array[i].position = j;
	}

	for(i=0; i<num_slots; i++)
	{
		printf("%d: %s\n", i + 1, array2[i].terrain);
		printf("Player: %s\n", array2[i].player_inf);
		printf("Type: %s\n", array2[i].type_inf);
		puts("");
		
	}
	
}

void player_abilities(int num_players)
{
	printf("\nPlayer Capabilities: \n");

	for(i=0; i<num_players; i++)
	{
		if(strcmp(players_array[i].type,"ogre")==0)
		{
			players_array[i].Life_pts = 100;
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
			players_array[i].Life_pts = 100;
			

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
			players_array[i].Life_pts = 100;
			

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
			players_array[i].Life_pts = 100;

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

void move_player(int num_slots, int num_players, int k)
{
	int a;
	
	if(strcmp(array2[(players_array[k].position) + 1].player_inf,"empty")!=0 && strcmp(array2[(players_array[k].position) - 1].player_inf,"empty")!=0)
	{
		printf("You cannot move to any position \n\n");
	}
	else if(strcmp(array2[(players_array[k].position) + 1].player_inf,"empty")!=0)
	{
		printf("You can only move backwards \n\n");
		players_array[k].position = players_array[k].position - 1;
		strcpy(array2[(players_array[k].position) - 1].player_inf, array2[(players_array[k].position)].player_inf);
		strcpy(array2[(players_array[k].position) - 1].type_inf, array2[(players_array[k].position)].type_inf);
		strcpy(array2[(players_array[k].position)].player_inf, "");
		strcpy(array2[(players_array[k].position)].type_inf, "");
		
		if(strcmp(array2[(players_array[k].position) - 1].player_inf,"Hill") == 0)
			{
				if( players_array[k].Dexterity < 50  )
				{
					players_array[k].Strength = players_array[k].Strength - 10;
				}
				else if( players_array[k].Dexterity >= 60)
				{
					players_array[k].Strength = players_array[k].Strength + 10;
				}
			}
			
			if(strcmp(array2[(players_array[k].position) - 1].player_inf,"City") == 0)
			{
				if( players_array[k].Smartness > 60  )
				{
					players_array[k].Magic_Skills = players_array[k].Magic_Skills + 10;
				}
				else if( players_array[k].Smartness	<= 50)
				{
					players_array[k].Dexterity = players_array[k].Dexterity + 10;
				}
			}
			
		printf("");
	}
	else if(strcmp(array2[(players_array[k].position) - 1].player_inf,"empty")!=0 )
	{
		printf("You can only move forwards \n\n");
		players_array[k].position = players_array[k].position + 1;
		strcpy(array2[(players_array[k].position) + 1].player_inf, array2[(players_array[k].position)].player_inf);
		strcpy(array2[(players_array[k].position) + 1].type_inf, array2[(players_array[k].position)].type_inf);
		strcpy(array2[(players_array[k].position)].player_inf, "");
		strcpy(array2[(players_array[k].position)].type_inf, "");
		
		if(strcmp(array2[(players_array[k].position) + 1].terrain,"Hill") == 0)
			{
				if( players_array[k].Dexterity < 50  )
				{
					players_array[k].Strength = players_array[k].Strength - 10;
				}
				else if( players_array[k].Dexterity >= 60)
				{
					players_array[k].Strength = players_array[k].Strength + 10;
				}
			}
			
			if(strcmp(array2[(players_array[k].position) + 1].terrain,"City") == 0)
			{
				if( players_array[k].Smartness > 60  )
				{
					players_array[k].Magic_Skills = players_array[k].Magic_Skills + 10;
				}
				else if( players_array[k].Smartness	<= 50)
				{
					players_array[k].Dexterity = players_array[k].Dexterity + 10;
				}
			}
	}
	else
	{
		printf("You are able to move backwards or forwards\n");
		printf("Would you like to move back or forward?? \n (1 - Forward, 2 - backward) \n\n");
		scanf("%d", &a);
		
		if(a == 1)
		{
		players_array[k].position = players_array[k].position + 1;
		strcpy(array2[(players_array[k].position) + 1].player_inf, array2[(players_array[k].position)].player_inf);
		strcpy(array2[(players_array[k].position) + 1].type_inf, array2[(players_array[k].position)].type_inf);
		strcpy(array2[(players_array[k].position)].player_inf, "");
		strcpy(array2[(players_array[k].position)].type_inf, "");
		
		if(strcmp(array2[(players_array[k].position) + 1].terrain,"Hill") == 0)
			{
				if( players_array[k].Dexterity < 50  )
				{
					players_array[k].Strength = players_array[k].Strength - 10;
				}
				else if( players_array[k].Dexterity >= 60)
				{
					players_array[k].Strength = players_array[k].Strength + 10;
				}
			}
			
			if(strcmp(array2[(players_array[k].position) + 1].terrain,"City") == 0)
			{
				if( players_array[k].Smartness > 60  )
				{
					players_array[k].Magic_Skills = players_array[k].Magic_Skills + 10;
				}
				else if( players_array[k].Smartness	<= 50)
				{
					players_array[k].Dexterity = players_array[k].Dexterity + 10;
				}
			}
		}
		else if( a == 2)
		{
		players_array[k].position = players_array[k].position - 1;
		strcpy(array2[(players_array[k].position) - 1].player_inf, array2[(players_array[k].position)].player_inf);
		strcpy(array2[(players_array[k].position) - 1].type_inf, array2[(players_array[k].position)].type_inf);
		strcpy(array2[(players_array[k].position)].player_inf, "");
		strcpy(array2[(players_array[k].position)].type_inf, "");
		
		if(strcmp(array2[(players_array[k].position) - 1].terrain,"Hill") == 0)
			{
				if( players_array[k].Dexterity < 50  )
				{
					players_array[k].Strength = players_array[k].Strength - 10;
				}
				else if( players_array[k].Dexterity >= 60)
				{
					players_array[k].Strength = players_array[k].Strength + 10;
				}
			}
			
			if(strcmp(array2[(players_array[k].position) - 1].terrain,"City") == 0)
			{
				if( players_array[k].Smartness > 60  )
				{
					players_array[k].Magic_Skills = players_array[k].Magic_Skills + 10;
				}
				else if( players_array[k].Smartness	<= 50)
				{
					players_array[k].Dexterity = players_array[k].Dexterity + 10;
				}
			}
			
		}
		else
		{
			printf("\n");
		}
	}
}

void attack_player(int num_slots, int num_players, int k)
{
	int b, c, p;
	b = k;
	c = k;
	b++;
	c--;
	
	while(b < num_slots)
	{
		if(strcmp(array2[(players_array[b].position)].player_inf,"empty") == 0)
		{
			b++;
		}
		else
		{
			break;
		}
	}
			
	while(c >= 0)
	{
		if(strcmp(array2[(players_array[c].position)].player_inf,"empty") == 0)
		{
			c--;
		}
		else
		{
			break;
		}
	}
		
	if((b - k) > (k - c))
	{
		printf("Your nearest player is %s", array2[(players_array[c].position)].player_inf);
		if (players_array[c].Strength <= 70)
			{
				players_array[c].Life_pts = players_array[c].Life_pts - (0.5*(players_array[c].Strength));
			}
			else
			{
				players_array[k].Life_pts = players_array[k].Life_pts - (0.3*(players_array[c].Strength));
			}
	}	
	else if((b - k) < (k - c))
	{
		printf("Your nearest player is %s", array2[(players_array[b].position)].player_inf);
		if (players_array[b].Strength <= 70)
			{
				players_array[b].Life_pts = players_array[b].Life_pts - (0.5*(players_array[b].Strength));
			}
			else
			{
				players_array[k].Life_pts = players_array[k].Life_pts - (0.3*(players_array[b].Strength));
			}
	}		
	else
	{
		printf("Your nearest players are %s and %s", array2[(players_array[b].position)].player_inf, array2[(players_array[c].position)].player_inf);
		printf("Please choose which player you would like to attack: \n");
		printf("1 - %s \n", array2[(players_array[b].position)].player_inf);
		printf("2 - %s \n", array2[(players_array[c].position)].player_inf);
		scanf("%d", &p);
		if(p == 1)
		{
			printf("You are attacking player %s", array2[(players_array[b].position)].player_inf);
			if (players_array[b].Strength <= 70)
			{
				players_array[b].Life_pts = players_array[b].Life_pts - (0.5*(players_array[b].Strength));
			}
			else
			{
				players_array[k].Life_pts = players_array[k].Life_pts - (0.3*(players_array[b].Strength));
			}
		}
		else if(p == 2)
		{
			printf("You are attacking player %s", array2[(players_array[c].position)].player_inf);
			if (players_array[c].Strength <= 70)
			{
				players_array[c].Life_pts = players_array[c].Life_pts - (0.5*(players_array[c].Strength));
			}
			else
			{
				players_array[k].Life_pts = players_array[k].Life_pts - (0.3*(players_array[c].Strength));
			}
		}
	}
		
	
}







