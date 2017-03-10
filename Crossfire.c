#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/*Program by Sam Bates and Alen Thomas*/
/*Crossfire board game*/

void player_abilities(int num_players);					//Function prototype
void slot_sorting(int num_slots, int rand_num, int num_players);
void move_player(int num_slots, int num_players, int k);
void attack_player(int num_slots, int num_players, int k);


struct players						//Struct containing player data(name, type, abilities, life points and their position)
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



struct slots			//Struct to store slot terrain and store players in their slots
{
	char terrain[100];
	char player_inf[100];
	char type_inf[100];
};

int num_players, i, j;
int num_slots = 0;
struct players players_array[100];	//Array of struct players
struct slots array2[100];	//Array of struct slots

int main(void)
{
	int rand_num;
	int n, k;
	
	num_players = 0;
	
	while(num_players<1 || num_players>6)	//while loop which only ends when there are 2 or more players and less than or equal to 6 
	{
		printf("enter number of players(max 6): ");
		scanf("%d", &num_players);	//takes amount of players and stores it in variable
	}
	
	for(i=0; i<num_players; i++)	//for loop to take player information(name and type)
	{
		printf("\nenter player %d name: ", i+1);
		scanf("%s", &players_array[i].player_name);	//stores players name in stuct array
		
		//while loop that means type can only be elf, ogre, human or wizard
		while(strcmp(players_array[i].type, "elf" )!=0 && strcmp(players_array[i].type, "human" )!=0 && strcmp(players_array[i].type, "ogre" )!=0 && strcmp(players_array[i].type, "wizard" )!=0)
		{
			printf("%s enter your player type (elf, human, ogre, wizard) : ", &players_array[i].player_name);
			scanf("%s", &players_array[i].type); //stores players type in stuct array
		}
	}
	
	while(num_slots<num_players || num_slots>20)	//while loop so there are enough slots for players but less than 20
	{
		printf("\nenter number of slots(max 20): ");
		scanf("%d", &num_slots);	//takes amount of slots and stores it in variable
	}
	
	player_abilities(num_players);	//calls to function that creates player abilities and takes number of players 
	
	printf("\n");
	
	slot_sorting(num_slots, rand_num, num_players);	//calls to function that creates player abilities and takes number of players and slots aswell as an integer variable 
	
	printf("Move player/Attack Player \n\n"); //asks player what they would like to do
	printf("1 - Move player \n");
	printf("2 - Attack nearest Player \n\n");
	
	for( k = 0 ; k < num_players ; k++ )	//for loop that ends after each player has made a move
	{
		printf("Player: %s \n", players_array[k].player_name);
		printf("Please enter what you would like to do with your %s:", players_array[k].type);
		
		scanf("%d", &n);
		
		if( n == 1 )
		{
			move_player(num_slots, num_players, k);	//calls to function that moves the player
		}
		if( n == 2 )
		{
			attack_player(num_slots, num_players, k);	//calls to function that allows the player to attack
		}
		
	}
	
	for( i = 0; i < num_players; i++ )	//for loop that prints out the result at the end and ends after each player has been printed out
	{
		printf("%s (%s, %d)\n", players_array[i].player_name, players_array[i].type, players_array[i].Life_pts);	//prints out player name there type and there remaining life points
	}

}

void slot_sorting(int num_slots, int rand_num, int num_players)	//function for inputting terrain into slots
{
	srand(time(NULL));//makes rand random
	char m;
	
	printf("Slots: \n\n");
	
	for(i=0; i<num_slots; i++)//for loop that goes through each slot individually and ends when all slots have been used
	{
		rand_num = ((rand() %3)+1);// makes a random number between 1 and 3
		//player and type remain empty as no players in slots yet
		if(rand_num == 1) //if the random number is equal to 1 puts terrain level ground into slot.
		{
			strcpy(array2[i].terrain, "Level Ground");
			strcpy(array2[i].player_inf, "empty");
			strcpy(array2[i].type_inf, "empty");
		}
		else if(rand_num == 2) //if the random number is equal to 2 puts terrain hill into slot
		{
			strcpy(array2[i].terrain, "Hill");
			strcpy(array2[i].player_inf, "empty");
			strcpy(array2[i].type_inf, "empty");
		}
		else	//if the random number is equal to 3 puts terrain city into slot
		{
			strcpy(array2[i].terrain, "City");
			strcpy(array2[i].player_inf, "empty");
			strcpy(array2[i].type_inf, "empty");
		}
	}
	
	for( i = 0; i < num_players; i++ )//for loop to get players into slots
	{
		j = (rand() % num_slots);//makes j a random numberbetween 0 and amount of random slots
		if(strcmp(array2[j].player_inf, "empty")==0)//if statement that makes sure the slot is empty
		{
			strcpy(array2[j].player_inf, players_array[i].player_name);//copys player name into slot
			strcpy(array2[j].type_inf, players_array[i].type);	//copys player type into slot
			players_array[i].position = j; //assigns j to player position
		}
		
		else
		{
			i--;
		}
	}

	for(i=0; i<num_slots; i++)//for loop to print slots and players position
	{
		printf("%d: %s\n", i + 1, array2[i].terrain);
		printf("Player: %s\n", array2[i].player_inf);
		printf("Type: %s\n", array2[i].type_inf);
		puts("");
		
	}
	
}

void player_abilities(int num_players)//function to assign values to players abilities takes in number of players
{
	printf("\nPlayer Capabilities: \n");

	for(i=0; i<num_players; i++)//for loop that goes through each player and ends when all players have been passed through
	{
		if(strcmp(players_array[i].type,"ogre")==0)//checks if player type is ogre
		{
			players_array[i].Life_pts = 100;
			players_array[i].Luck = 60;
			players_array[i].Magic_Skills=0;
			players_array[i].Smartness = (rand() %21);
			players_array[i].Strength = ((rand() %21)+80);
			players_array[i].Dexterity = ((rand() %21)+80);
			while(players_array[i].Luck+players_array[i].Smartness>50)//makes sure that luck and smartness combined are less than 50
			{
				players_array[i].Luck = (rand() %51);
			}
			//prints out the result
			printf("\nPlayer %s, Type: %s ", players_array[i].player_name, players_array[i].type);
			printf("\nMagic skills: %d\n", players_array[i].Magic_Skills);
			printf("Smartness: %d\n", players_array[i].Smartness);
			printf("Strength: %d\n", players_array[i].Strength);
			printf("Dexterity: %d\n", players_array[i].Dexterity);
			printf("Luck: %d\n", players_array[i].Luck);
		}

		if(strcmp(players_array[i].type,"human")==0)//checks if player type is human
		{
			players_array[i].Magic_Skills = 100;
			players_array[i].Smartness = 100;
			players_array[i].Strength = 100;
			players_array[i].Dexterity = 100;
			players_array[i].Luck = 100;
			players_array[i].Life_pts = 100;
			
			//while loop that ends when combined abilities are less than or equal to 300
			while(players_array[i].Magic_Skills+players_array[i].Smartness+players_array[i].Strength+players_array[i].Dexterity+players_array[i].Luck>=300)
			{
				players_array[i].Magic_Skills = ((rand() %100)+1);
				players_array[i].Smartness = ((rand() %100)+1);
				players_array[i].Strength = ((rand() %100)+1);
				players_array[i].Dexterity = ((rand() %100)+1);
				players_array[i].Luck = ((rand() %100)+1);
			}
			//prints out the result
			printf("\nPlayer %s, Type: %s", players_array[i].player_name, players_array[i].type);
			printf("\nMagic skills: %d\n", players_array[i].Magic_Skills);
			printf("Smartness: %d\n", players_array[i].Smartness);
			printf("Strength: %d\n", players_array[i].Strength);
			printf("Dexterity: %d\n", players_array[i].Dexterity);
			printf("Luck: %d\n", players_array[i].Luck);
		}

		if(strcmp(players_array[i].type,"wizard")==0)//checks if player type is a wizard
		{
			players_array[i].Magic_Skills = ((rand() %21)+80);
			players_array[i].Smartness = ((rand() %11)+90);
			players_array[i].Strength = ((rand() %20)+1);
			players_array[i].Dexterity = ((rand() %100)+1);
			players_array[i].Luck = ((rand() %51)+50);
			players_array[i].Life_pts = 100;
			
			//prints out the result
			printf("\nPlayer %s, Type: %s ", players_array[i].player_name, players_array[i].type);
			printf("\nMagic skills: %d\n", players_array[i].Magic_Skills);
			printf("Smartness: %d\n", players_array[i].Smartness);
			printf("Strength: %d\n", players_array[i].Strength);
			printf("Dexterity: %d\n", players_array[i].Dexterity);
			printf("Luck: %d\n", players_array[i].Luck);

		}

		if(strcmp(players_array[i].type,"elf")==0)//checks if player type is elf

		{

			players_array[i].Magic_Skills = 0;
			players_array[i].Smartness = ((rand() %31)+70);
			players_array[i].Strength = ((rand() %50)+1);
			players_array[i].Dexterity = ((rand() %100)+1);
			players_array[i].Luck = ((rand() %41)+60);
			players_array[i].Life_pts = 100;

			while(players_array[i].Magic_Skills<=50)//while loop that ends when magic skills are greater than 50

			{
				players_array[i].Magic_Skills = ((rand() %30)+50);
			}
			//prints out the result
			printf("\nPlayer %s, Type: %s ", players_array[i].player_name, players_array[i].type);
			printf("\nMagic skills: %d\n", players_array[i].Magic_Skills);
			printf("Smartness: %d\n", players_array[i].Smartness);
			printf("Strength: %d\n", players_array[i].Strength);
			printf("Dexterity: %d\n", players_array[i].Dexterity);
			printf("Luck: %d\n", players_array[i].Luck);

		}
	}
}

void move_player(int num_slots, int num_players, int k)//function that moves player  takes number of slots and players
{
	int a;
	
	//if statement that wont allow player to move if both slots beside him are taken
	if(strcmp(array2[(players_array[k].position) + 1].player_inf,"empty")!=0 && strcmp(array2[(players_array[k].position) - 1].player_inf,"empty")!=0)
	{
		printf("You cannot move to any position \n\n");
	}
	//else if statement that wont allow player to move foward if that slot is taken
	else if(strcmp(array2[(players_array[k].position) + 1].player_inf,"empty")!=0)
	{
		printf("You can only move backwards \n\n");
		players_array[k].position = players_array[k].position - 1;
		strcpy(array2[(players_array[k].position)].player_inf, array2[(players_array[k].position) + 1].player_inf);//copys player name to the slot behind him
		strcpy(array2[(players_array[k].position)].type_inf, array2[(players_array[k].position) + 1].type_inf);//copys player type to the slot behind him
		strcpy(array2[(players_array[k].position) + 1].player_inf, "empty");//puts the slot the player was in back to empty
		strcpy(array2[(players_array[k].position) + 1].type_inf, "empty");
		
		//changes player abilities depending on where they are placed
		if(strcmp(array2[(players_array[k].position)].player_inf,"Hill") == 0)
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
			
			if(strcmp(array2[(players_array[k].position)].player_inf,"City") == 0)
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
	//else if statement that wont allow player to move backwards if that slot is taken
	else if(strcmp(array2[(players_array[k].position) - 1].player_inf,"empty")!=0 )
	{
		printf("You can only move forwards \n\n");
		players_array[k].position = players_array[k].position + 1;
		strcpy(array2[(players_array[k].position) + 1].player_inf, array2[(players_array[k].position)].player_inf);//copys player name to the slot ahead of him
		strcpy(array2[(players_array[k].position) + 1].type_inf, array2[(players_array[k].position)].type_inf);//copys player type to the slot ahead of him
		strcpy(array2[(players_array[k].position)].player_inf, "");//puts the slot the player was in back to empty
		strcpy(array2[(players_array[k].position)].type_inf, "");
		
		//changes player abilities depending on where they are placed
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
		scanf("%d", &a);//takes user input to decide where to move to
		
		if(a == 1)
		{
			//same as if you could only move forward
		players_array[k].position = players_array[k].position + 1;
		strcpy(array2[(players_array[k].position) + 1].player_inf, array2[(players_array[k].position)].player_inf);
		strcpy(array2[(players_array[k].position) + 1].type_inf, array2[(players_array[k].position)].type_inf);
		strcpy(array2[(players_array[k].position)].player_inf, "empty");
		strcpy(array2[(players_array[k].position)].type_inf, "empty");
		
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
			//same as if you could only move backwards
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
	
	for(i=0; i<num_slots; i++)//for loop to print the new changed slots
	{
		printf("%d: %s\n", i + 1, array2[i].terrain);
		printf("Player: %s\n", array2[i].player_inf);
		printf("Type: %s\n", array2[i].type_inf);
		puts("");
		
	}
}

void attack_player(int num_slots, int num_players, int k)//attack function takes in number of players and slots 
{
	int b, c, p;
	b = k;
	c = k;
	b++;
	c--;
	
	while(b < num_slots)//while loop to search through all the slots to find the nearest filled on to the player
	{
		if(strcmp(array2[(players_array[b].position)].player_inf,"empty") == 0)//if the slot is empty moves to the next one
		{
			b++;
		}
		else
		{
			break;//if slot is filled exits the loop
		}
	}
			
	while(c >= 0)//same as before but in opposite direction
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
		
	if((b - k) > (k - c))//sees if c is closer than b
	{
		printf("Your nearest player is %s", array2[(players_array[c].position)].player_inf);
		if (players_array[c].Strength <= 70)//checks players strength to see who loses health
			{
				players_array[c].Life_pts = players_array[c].Life_pts - (0.5*(players_array[c].Strength));
			}
			else
			{
				players_array[k].Life_pts = players_array[k].Life_pts - (0.3*(players_array[c].Strength));
			}
	}	
	else if((b - k) < (k - c))//sees if b is closer than c
	{
		printf("Your nearest player is %s", array2[(players_array[b].position)].player_inf);
		if (players_array[b].Strength <= 70)//checks players strength to see who loses health
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
		printf("Your nearest players are %s and %s", array2[(players_array[b].position)].player_inf, array2[(players_array[c].position)].player_inf);//if same distance away player allowed to choose
		printf("Please choose which player you would like to attack: \n");
		printf("1 - %s \n", array2[(players_array[b].position)].player_inf);
		printf("2 - %s \n", array2[(players_array[c].position)].player_inf);
		scanf("%d", &p);
		if(p == 1)
		{
			printf("You are attacking player %s \n", array2[(players_array[b].position)].player_inf);
			if (players_array[b].Strength <= 70)//checks players strength to see how many life to be deducted
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
			printf("You are attacking player %s\n", array2[(players_array[c].position)].player_inf);
			if (players_array[c].Strength <= 70)//checks players strength to see how many life to be deducted
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







