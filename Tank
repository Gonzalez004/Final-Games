#include <iostream>
#include <allegro5/allegro.h>
#include<allegro5/allegro_primitives.h>
#include<allegro5/allegro_image.h>

using namespace std;
//Functions
bool WallCollision(int x, int y, int direction, int angle, int size, int Map[50][50]);

//Player 1 keys
bool Key[4] = { false, false, false, false };

//Player 2 keys
bool Key2[4] = { false, false, false, false };

//Constants
const int WallSize = 20;

//Player direction
int Dir = 0;
int Dir2 = 0;

//Player Angle
double Angle = 0;
double Angle2 = 0;

// Starting point of the Players.
int Square_X = 350;
int Square_Y = 350;
int Square2_X = 400;
int Square2_Y = 400;

int main() {

	ALLEGRO_DISPLAY *Display = NULL;
	ALLEGRO_EVENT_QUEUE *Event_Queue = NULL;
	ALLEGRO_TIMER *Timer = NULL;
	ALLEGRO_BITMAP *Square = NULL;
	ALLEGRO_BITMAP *Square2 = NULL;;
	ALLEGRO_BITMAP *Wall = NULL;

	al_init();
	al_init_primitives_addon();
	al_init_image_addon();
	al_install_keyboard();

	//Setting up Map/Matrix
	int Map[50][50];
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			if (i == 0 || i == 49 || j == 0 || j == 49)
				Map[i][j] = 1;
			else if (i == 10 && j < 30)
				Map[i][j] = 1;
			else if (i == 10 && j > 35)
				Map[i][j] = 1;
			else if (i == 40 && j > 35)
				Map[i][j] = 1;
			else if (i == 30 && j > 35)
				Map[i][j] = 1;
			else if (i > 15 && j == 10)
				Map[i][j] = 1;
			else if ( i < 40 && i > 10 && j == 20)
				Map[i][j] = 1;
			else if (i < 31 && i > 15 && j == 35)
				Map[i][j] = 1;
			else if (i < 31 && i > 15 && j == 42)
				Map[i][j] = 1;
			else if (i < 42 && i > 15 && j == 28)
				Map[i][j] = 1;
			else 
				Map[i][j] = 0;
		}
	}
	
	//Prints out Matrix
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++)
			cout << Map[i][j];
		cout << endl; }

	//don't redraw until an event happens
	bool Redraw = true;

	//this controls our game loop
	bool Doexit = false; 

	//set the timer so it "ticks" at 2 milliseconds
	Timer = al_create_timer(.02);

	//Creates the Display and Position its in
	Display = al_create_display(1000, 1000);
	al_set_window_position(Display, 900, 0);
	al_set_window_title(Display, "Tank Trouble"); //Window Title

	//create a little 32x32 square
	//Square = al_load_bitmap("tank1.png");
	Square = al_create_bitmap(20, 20);
	al_set_target_bitmap(Square);
	al_clear_to_color(al_map_rgb(255, 0, 0));
	al_set_target_bitmap(al_get_backbuffer(Display));

	//create a little 32x32 square2
	//Square2 = al_load_bitmap("tank2.png");
	Square2 = al_create_bitmap(20, 20);
	al_set_target_bitmap(Square2);
	al_clear_to_color(al_map_rgb(0, 0, 255));
	al_set_target_bitmap(al_get_backbuffer(Display));

	//creating wall
	Wall = al_create_bitmap(WallSize, WallSize);
	al_set_target_bitmap(Wall);
	al_clear_to_color(al_map_rgb(0, 250, 0));
	al_set_target_bitmap(al_get_backbuffer(Display));

	//register the timer as an event source so it can generate events
	Event_Queue = al_create_event_queue();
	al_register_event_source(Event_Queue, al_get_display_event_source(Display));
	al_register_event_source(Event_Queue, al_get_keyboard_event_source());
	al_register_event_source(Event_Queue, al_get_timer_event_source(Timer));
	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_flip_display();

	//Starts the Timer
	al_start_timer(Timer);

	while (!Doexit)
	{
		ALLEGRO_EVENT ev;
		//this function will wait forever if no events come in
		al_wait_for_event(Event_Queue, &ev);

		//sets this part of the game to run on the clicks of the timer 
		if (ev.type == ALLEGRO_EVENT_TIMER) {
			//Player 1 Angle
			if (Angle < 0) {
				Angle = 360; }
			if (Angle > 360) {
				Angle = 0; }
			//Player 2 Angle
			if (Angle2 < 0) {
				Angle2 = 360;
			}
			if (Angle2 > 360) {
				Angle2 = 0;
			}

			//Player 1 Physics
			if (Key[0] && !WallCollision(Square_X, Square_Y, Dir, Angle, 20, Map)) {  //&& !WallCollision(Square_X, Square_Y, Dir, Angle, 30, Map)
				Square_Y += 4 * sin(3.14*Angle / 180);
				Square_X += 4 * cos(3.14*Angle / 180);
				Dir = 0;
			}
			if (Key[1] && !WallCollision(Square_X, Square_Y, Dir, Angle, 20, Map)) {  //&& !WallCollision(Square_X, Square_Y, Dir, Angle, 30, Map)
				Square_Y -= 4 * sin(3.14*Angle / 180);
				Square_X -= 4 * cos(3.14*Angle / 180);
				Dir = 1;
			}
			if (Key[2]) {
				Angle -= 4;
				Dir = 2;
			}
			if (Key[3]) {
				Angle += 4;
				Dir = 3;
			}

			//Player 2 Physics
			if (Key2[0] && !WallCollision(Square2_X, Square2_Y, Dir, Angle2, 20, Map)) {
				Square2_Y += 4 * sin(3.14*Angle2 / 180);
				Square2_X += 4 * cos(3.14*Angle2 / 180);
				Dir2 = 0;
			}
			if (Key2[1] && !WallCollision(Square2_X, Square2_Y, Dir, Angle2, 20, Map)) {
				Square2_Y -= 4 * sin(3.14*Angle2 / 180);
				Square2_X -= 4 * cos(3.14*Angle2 / 180);
				int Dir2 = 1;
			}
			if (Key2[2]) {
				Angle2 -= 4;
				Dir2 = 2;
			}
			if (Key2[3]) {
				Angle2 += 4;
				Dir2 = 3;
			}
		
			Redraw = true;
		}

		//////////////////////////////////////////////////////////////////
		//kill program if the user clicks the exit button
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}
		//////////////////////////////////////////////////////////////////////////////////////////////////////

		//has something been pressed on the keyboard?
	else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
		//"keycode" holds all the different keys on the keyboard
		switch (ev.keyboard.keycode) {
		//Checks if Keys has been pressed
		case ALLEGRO_KEY_UP:
			Key[0] = true;
			break;
		case ALLEGRO_KEY_DOWN:
			Key[1] = true;
			break;
		case ALLEGRO_KEY_LEFT:
			Key[2] = true;
			break;
		case ALLEGRO_KEY_RIGHT:
			Key[3] = true;
			break;

		case ALLEGRO_KEY_W:
			Key2[0] = true;
			break;
		case ALLEGRO_KEY_S:
			Key2[1] = true;
			break;
		case ALLEGRO_KEY_A:
			Key2[2] = true;
			break;
		case ALLEGRO_KEY_D:
			Key2[3] = true;
			break;
}
		}
		//has something been released on the keyboard?
		else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_UP:
				Key[0] = false;
				break;
			case ALLEGRO_KEY_DOWN:
				Key[1] = false;
				break;
			case ALLEGRO_KEY_LEFT:
				Key[2] = false;
				break;
			case ALLEGRO_KEY_RIGHT:
				Key[3] = false;
				break;

			case ALLEGRO_KEY_W:
				Key2[0] = false;
				break;
			case ALLEGRO_KEY_S:
				Key2[1] = false;
				break;
			case ALLEGRO_KEY_A:
				Key2[2] = false;
				break;
			case ALLEGRO_KEY_D:
				Key2[3] = false;
				break;

				//kill the program if someone presses escape
			case ALLEGRO_KEY_ESCAPE:
				Doexit = true;
				break;
			}
		}
		//render section: draws stuff
		//if you were supposed to redraw but there wasn't an event, don't redraw
		if (Redraw && al_is_event_queue_empty(Event_Queue)) {
			Redraw = false;
			al_clear_to_color(al_map_rgb(0, 0, 0));

			//al_draw_rotated_bitmap(Square, 30, 30, Square_X, Square_Y, ((Angle*3.14) / 100), 0); //drift
			for (int i = 0; i < 50; i++) {
				for (int j = 0; j < 50; j++) {
					//'al_draw_rectangle(i * 20, j * 20, i * 20 + 20, j * 20 + 20, al_map_rgb(50, 80, 90), 3);
					if (Map[i][j] == 1) {
						al_draw_bitmap(Wall, i * 20, j * 20, 0);
					}
				}
			}
			al_draw_rotated_bitmap(Square, 10, 10, Square_X, Square_Y, ((Angle*3.14) / 180), 0);
			al_draw_rotated_bitmap(Square2, 10, 10, Square2_X, Square2_Y, ((Angle2*3.14) / 180), 0);

			al_flip_display();

		}
	}//end game loop
	al_destroy_bitmap(Square);
	al_destroy_bitmap(Square2);
	al_destroy_timer(Timer);
	al_destroy_display(Display);
	al_destroy_bitmap(Wall);
	al_destroy_event_queue(Event_Queue);

	return 0;
}
bool WallCollision(int x, int y, int direction, int angle, int size, int Map[50][50]) {
	int newX;
	int newY;
	if (direction == 0) {
		newX = x + (4 + size) * cos(3.14*angle / 180);
		newY = y + (4 + size) * sin(3.14*angle / 180);
}
	else {
		newX = x - (4 + size) * cos(3.14*angle / 180);
		newY = y - (4 + size) * sin(3.14*angle / 180);
	}
	if (Map[newX / 10][newY / 10] == 1)
		return 1;
	else return false;
}
