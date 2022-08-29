#include <ncurses.h>
#include <string.h>

int main()
{
	char word[20] = "hello";
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
		for(int i = 1; i < len - 1; i++)
		{
			addch('_');
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
