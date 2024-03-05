#include <ncurses.h>
#include <string>
using namespace std;

int main() {

    /*NCURSES START*/
    initscr();
    noecho();
    cbreak();

    // get screen size
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    //create window for our input
    WINDOW *menuwin = newwin(8, xMax - 12, yMax - 10, 5);

    box(menuwin, 0, 0);
    refresh();
    wrefresh(menuwin);

    // make it so that we can use arrow keys
    keypad(menuwin, true);

    string choices[3] = {"PLAY", "PAUSE", "RESUME"};
    int choice;
    int highlight = 0;

    while(1){
        for (size_t i = 0; i < 3; i++)
        {
            if (i == highlight)
            {
                wattron(menuwin, A_REVERSE);
            }
            mvwprintw(menuwin, i + 1, 1, choices[i].c_str());
            wattroff(menuwin, A_REVERSE);
        }

        wrefresh(menuwin); // refresh the menuwin to show the highlighted choice

        choice = wgetch(menuwin);

        switch(choice){
            case KEY_UP:
                highlight--;
                if (highlight == -1)
                {
                    highlight = 2;
                }
                break;
            case KEY_DOWN:
                highlight++;
                if (highlight == 3)
                {
                    highlight = 0;
                }
                break;
            default:
                break;
        }

        if(choice == 10){ // Check for enter key press inside the loop
            break;
        }
    }

    printw("Your choice was: %s", choices[highlight].c_str());
    getch();
    endwin();
    /*NCURSES END*/
    return 0;
}
