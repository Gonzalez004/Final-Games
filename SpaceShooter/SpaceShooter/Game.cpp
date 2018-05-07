#include <allegro5/allegro.h>//
#include <allegro5\allegro_primitives.h>//
#include <allegro5\allegro_image.h>//
#include <allegro5\allegro_font.h>//
#include <allegro5\allegro_ttf.h>//
#include <allegro5\allegro_audio.h>//
#include <allegro5\allegro_acodec.h>//
#include <list>//
#include<iostream>
#include "GameObject.h"//
#include"SpaceShip.h"//
#include "Global.h"

using namespace std;

bool Key[5] = { false, false, false, false, false };
enum KEYS { Up, Down, Left, Right, Space };

SpaceShip *ship;


int main() {
	bool redraw = true;
	bool doexit = false;

	bool Done = false;
	bool Render = false;
	float GameTime = 0;
	int Frames = 0;
	int GameFPS = 0;


	ship = new SpaceShip();
	ALLEGRO_BITMAP *shipImage = NULL;

	al_init();
	al_init_font_addon();
	al_init_ttf_addon();
	al_install_keyboard();
	al_init_primitives_addon();
	al_init_image_addon();
	al_install_audio();
	al_init_acodec_addon();

	ALLEGRO_DISPLAY *Display = al_create_display(Width, Height);
	ALLEGRO_EVENT_QUEUE *Event_Queue = al_create_event_queue();
	ALLEGRO_TIMER *Timer = al_create_timer(1 / 60);
	ALLEGRO_FONT *Font = NULL;

	shipImage = al_load_bitmap("ship.jpg");
	al_convert_mask_to_alpha(shipImage, al_map_rgb(255, 0, 255));
	ship->Init(shipImage);


	al_register_event_source(Event_Queue, al_get_display_event_source(Display));
	al_register_event_source(Event_Queue, al_get_timer_event_source(Timer));
	al_register_event_source(Event_Queue, al_get_keyboard_event_source());

	al_start_timer(Timer);
	GameTime = al_current_time();

	while (!doexit)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(Event_Queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER) {

			redraw = true;
		}

		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			doexit = true;
			break;
		}

		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {

			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_UP:
				Key[Up] = true;
				break;
			case ALLEGRO_KEY_DOWN:
				Key[Down] = true;
				break;
			case ALLEGRO_KEY_LEFT:
				Key[Left] = true;
				break;
			case ALLEGRO_KEY_RIGHT:
				Key[Right] = true;
				break;
			case ALLEGRO_KEY_SPACE:
				Key[Space] = true;
				break;
			case ALLEGRO_KEY_ESCAPE:
				doexit = true;
				break;
			}
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_UP:
				Key[Up] = false;
				break;
			case ALLEGRO_KEY_DOWN:
				Key[Down] = false;
				break;
			case ALLEGRO_KEY_LEFT:
				Key[Left] = false;
				break;
			case ALLEGRO_KEY_RIGHT:
				Key[Right] = false;
				break;
			case ALLEGRO_KEY_SPACE:
				Key[Space] = false;
				break;


			}
		}

		else if (ev.type == ALLEGRO_EVENT_TIMER) {
			Render = true;
			Frames++;
			if (al_current_time() - GameTime >= 1) {
				GameTime = al_current_time();
				GameFPS = Frames;
				Frames = 0;
			}
			if (Key[Up])
				ship->MoveUp();
			else if (Key[Down])
				ship->MoveDown();
			else
				ship->ResetAnimation(1);
			if (Key[Left])
				ship->MoveLeft();
			else if (Key[Right])
				ship->MoveRight;
			else
				ship->ResetAnimation(0);
		}


		if (redraw && al_is_event_queue_empty(Event_Queue)) {
			redraw = false;
			al_clear_to_color(al_map_rgb(0, 0, 0));


			al_flip_display();
		}
	}
	al_destroy_timer(Timer);
	al_destroy_display(Display);
	al_destroy_event_queue(Event_Queue);

	return 0;
}