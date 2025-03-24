#include <stdio.h>
#include <string.h>

void graphics();
void win();
void loose();
void game();


int num,i,j,length,mistake=0,h=10,m=10,x,l=10,H=10,play_again;
char word[100],given,guess[100];

static char words[200][200] ={"adventure", "apartment", 
	"beautiful", "celebration", "character", "classical", "community", "condition", "contribute", 
	"creativity", "dangerous", "definition", "democratic", "department", "difference", "difficulty", 
	"direction", "discussion", "education", "emergency", "employment", "enthusiasm", "environment", 
	"expression", "foundation", "friendship", "government", "happiness", "historical", "important", 
	"innovation", "inspiration", "intelligent", "interesting", "investment", "knowledge", 
	"leadership", "literature", "management", "motivation", "negotiation", "opportunity", 
	"performance", "philosophy", "population", "practical", "preference", "president", "protection",
	 "reflection", "relationship", "reputation", "responsible", "satisfaction", "scientific", 
	 "situation", "technology", "television", "understand", "volunteer", "wonderful", "abundance", 
	 "advertising", "assignment", "atmosphere", "attraction", "basketball", "breakfast", "challenging",
	"chemistry", "confidence", "consistent", "continuous", "convenience", "corporation", "curriculum",
	"decoration", "dependency", "depression", "determined", "disadvantage", "discipline", "evaluation",
	"experience", "experiment", "exploration", "expression", "fascinating", "foundation", "imagination",
	 "independent", "information", "inspiration", "introduction", "journalist", "leadership", 
	 "mathematics", "negotiation", "observatory", "opportunity", "population", "preparation", 
	"productive", "programming", "reliability", "restaurant", "sustainable", "technology", 
	"university", "visibility", "volunteering", "willingness", "xylophone", "youthfulness", 
	"zoological"};

static char excess[5][35]=
{
	"   *********************",
	"   **                  *",
	"   **                  *"
};

static char head[5][35]=
	{
	"   **               *******",
	"   **               *     *",
	"   **               *     *",
	"   **               *******"
	};
	static char hand[5][35]=
	{
	"   **            *     *     *",
	"   **              *   *   *",
	"   **                * * *"
	};
	static char mid[5][35]={
	"   **                  *",
	"   **                  *",
	"   **                  *",
	"   **                  *"
	};
	static char leg[5][35]=
	{
	"   **                * * *",
	"   **              *       *",
	"   **            *           *",
	"   **          *               *"
	};
	int choose_Word();
int main()
{
	printf("\t------Welcome to Hang Man-------\n");
	graphics();
retreat:
	   	printf("\nEnter any number between 1-115: ");
    	scanf("%d",&num);
	   	num = num-1;
	if(num<=115)
	{
		for(i=0;i<20;i++)
		{
			word[i]=words[num][i];
		}
	}
		
	else{
		goto retreat;
	}
    length=strlen(word);
    given=word[0];
    for (i=0;i<strlen(word);i++)
    {
       if(given==word[i] || word[length-1]==word[i])
       {
          guess[i]=word[i];
       }
       else
       {
          guess[i]='_';
       }
       
    }
	game();
    
}


void graphics()
{
	for(i=0;i<3;i++)
	{
		for(j=0;j<=35;j++)
		{
			printf("%c",excess[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<4;i++)
	{
		for(j=0;j<=H;j++)
		{
			printf("%c",head[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<=h;j++)
		{
			printf("%c",hand[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<4;i++)
	{
		for(j=0;j<=m;j++)
		{
			printf("%c",mid[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<4;i++)
	{
		for(j=0;j<=l;j++)
		{
			printf("%c",leg[i][j]);
		}
		printf("\n");
	}
}

void win()
{
	printf("\n\n--------YOU WIN!--------\n\n ANSWER: '%s'",word);
}
void loose()
{
	printf("\n\n--------YOU LOST!--------\n\n THE ACTUAL WORD WAS '%s'",word);
    exit(0);
}
void game()
{

reguess:
    x=0;
    
    for (i=0;i<length;i++)
    {
    printf("%c ",guess[i]);
    }
    getchar();
    printf("\nEnter your guess: ");
    scanf("%c",&given);
    printf("\n");
    for(i=0;i<length;i++)
    {
        if(word[i]==given)
        {
        guess[i]=word[i];
        x=1;
        }
    }
    if(x==0){
        mistake++;
        if(mistake==1){H=30;}
        else if(mistake==2){h=24;}
        else if(mistake==3){h=30;}
        else if(mistake==4){m=30;}
        else if(mistake==5){l=24;}
        else if(mistake==6){l=34;}
        graphics();
        if(mistake==6){loose();}
        }
    
    for (i=0;i<length;i++)
    {
    if(guess[i]=='_')
    {
    goto reguess;
    }
    }
    for (i=0;i<length;i++)
    {
    if(guess[i]!='_')
    {
    win();
    exit(0);
    } 
    }
    
}
