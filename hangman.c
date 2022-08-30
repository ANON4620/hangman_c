#define MAX_WORD_LEN 20

#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int count_words(FILE *);
	void load_words(char [][MAX_WORD_LEN], FILE *);

	FILE *fp = fopen("words.txt", "r");
	int row = count_words(fp);
	char words[row][MAX_WORD_LEN];
	fseek(fp, 0, SEEK_SET);
	load_words(words, fp);
	fclose(fp);

	srand(time(NULL));

	char word[20];
	strcpy(word, words[rand() % row]);
	int len = strlen(word);
	char inp[len];
        int attempts = 10;

	initscr();
	curs_set(0);

	while(attempts > 0)
	{
		clear();
		printw("%d attempts left.\n\n", attempts);

		addch(word[0]);
		addch(' ');
		for(int i = 1; i < len - 1; i++)
		{
			addstr("_ ");
		}
		addch(word[len - 1]);
		addstr("\n\n");

		addstr("Your guess: ");
		getnstr(inp, len);
		if (strcmp(inp, word) == 0)
		{
			break;
		}

		--attempts;
	}

	if (attempts == 0)
	{
		addstr("\nYou lose! \n");
	}
	else
	{
		addstr("\nYou won! \n");
	}

	addstr("\n[Press any key to quit] \n");
	getch();
	endwin();

	return 0;
}

int count_words(FILE *fp)
{
	char buf[MAX_WORD_LEN];
        int words = 0;

        while(fgets(buf, MAX_WORD_LEN, fp))
        { ++words; }

	return words;
}

void load_words(char words[][MAX_WORD_LEN], FILE *fp)
{
	int i = 0;

        while(fgets(words[i], MAX_WORD_LEN,
fp))
        {
		words[i][strlen(words[i]) -
1] = '\0';
                ++i;
        }
}
