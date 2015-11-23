#include<iostream>
#include<string>
#include<ctime>
#include<fstream>
#include <stdio.h>
#include <stdlib.h>
#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5\allegro_native_dialog.h>
using namespace std;

int MenuGlowne()
{
	string sWyborMenuGlowne;
	short siWybor = 0;



	do
	{

		cout << "\n\n\n\n\n\n\t\tWitaj w Into the darkness" << endl;
		cout << "\n\n\t1.Zagraj" << endl;
		cout << "\t2.Pomoc" << endl;
		cout << "\t3.Informacje" << endl;
		cout << "\t4.Wyjscie" << endl;

		cin >> sWyborMenuGlowne;
		system("cls");

	} while (!(sWyborMenuGlowne == "1" || sWyborMenuGlowne == "2" || sWyborMenuGlowne == "3" || sWyborMenuGlowne == "4"));
	siWybor = stoi(sWyborMenuGlowne);
	//cout << siWybor;
	return siWybor;
}
void Pozegnanie()
{
	system("cls");
	cout << "\n\n\n\n\n\n\t\tMilego Dnia\n\n\n\n\n\n";
	system("timeout 5");
}



int main(){

	for (;;)
	{
		switch (MenuGlowne())
		{
		case 1:
		{
			int width = 640;
			int height = 480;
			bool done = false;

			int pos_x = width / 2;
			int pos_y = height / 2;

			ALLEGRO_DISPLAY *display = NULL;
			ALLEGRO_EVENT_QUEUE *event_queue = NULL;



			if (!al_init()){
				al_show_native_message_box(NULL, NULL, NULL, "failed to initialize allegro!", NULL, NULL);
				return -1;
			}

			display = al_create_display(width, height);

			if (!display){
				al_show_native_message_box(NULL, NULL, NULL, "failed to initialize allegro!", NULL, NULL);
				return -1;
			}

			al_init_font_addon();
			al_init_ttf_addon();
			al_init_primitives_addon();
			al_install_keyboard();

			event_queue = al_create_event_queue();
			al_register_event_source(event_queue, al_get_keyboard_event_source());

			while (!done)
			{
				al_draw_filled_rectangle(pos_x, pos_y, pos_x + 30, pos_y + 30, al_map_rgb(255, 0, 0));
				al_flip_display();
				al_clear_to_color(al_map_rgb(0, 0, 0));

				ALLEGRO_EVENT ev;
				al_wait_for_event(event_queue, &ev);

				if (ev.type == ALLEGRO_EVENT_KEY_UP&&ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
					done = true;
				if (ev.type == ALLEGRO_EVENT_KEY_DOWN && ev.keyboard.keycode == ALLEGRO_KEY_RIGHT)
					pos_x += 30;
				if (ev.type == ALLEGRO_EVENT_KEY_DOWN && ev.keyboard.keycode == ALLEGRO_KEY_LEFT)
					pos_x -= 30;
				if (ev.type == ALLEGRO_EVENT_KEY_DOWN && ev.keyboard.keycode == ALLEGRO_KEY_UP)
					pos_y -= 30;
				if (ev.type == ALLEGRO_EVENT_KEY_DOWN && ev.keyboard.keycode == ALLEGRO_KEY_DOWN)
					pos_y += 30;
			}


			return 0;
		}


			break;
		case 2:

			break;
		case 3:

			break;
		case 4:
			Pozegnanie();
			return EXIT_SUCCESS;
		}
	}
}


