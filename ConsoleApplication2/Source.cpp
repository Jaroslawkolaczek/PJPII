#include<iostream>
#include<string>
#include<ctime>
#include<fstream>
#include <stdio.h>
#include <stdlib.h>
#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
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

			bool done = false;
			al_init_primitives_addon();
			int poz_x = 400;
			int poz_y = 400;
			int poz_x2 = 300;
			int poz_y2 = 300;
			int counter = 0;
			const int FPS = 60;
			bool redraw = true;
			if (!al_init()){
				fprintf(stderr, "Failed to initialize Allegro.\n");
				return -1;
			}

			al_init_font_addon(); // initialize the font addon
			al_init_ttf_addon();// initialize the ttf (True Type Font) addon
			al_init_image_addon();
			ALLEGRO_DISPLAY *display = al_create_display(800, 600);
			ALLEGRO_EVENT_QUEUE *event_queue = NULL;
			ALLEGRO_BITMAP *czolk = NULL;
			ALLEGRO_BITMAP *czolk2 = NULL;
			ALLEGRO_BITMAP *tlo = NULL;

			if (!display){
				fprintf(stderr, "Failed to create display.\n");
				return -1;
			}
			ALLEGRO_TIMER *czas = al_create_timer(1/60.0);
			czas = al_create_timer(1.0 / FPS);
			ALLEGRO_FONT *font = al_load_ttf_font("comic.ttf", 12, 0);
			if (!font){
				fprintf(stderr, "Could not load 'comic.ttf'.\n");
				return -1;
			}

			al_clear_to_color(al_map_rgb(0, 0, 0));

			al_install_keyboard();


			event_queue = al_create_event_queue();
			al_register_event_source(event_queue, al_get_keyboard_event_source());
			al_register_event_source(event_queue, al_get_timer_event_source(czas));
			al_start_timer(czas);

			czolk = al_load_bitmap("czolk.bmp");
			al_convert_mask_to_alpha(czolk, al_map_rgb(255, 255, 255));
			czolk2 = al_load_bitmap("czolk2.bmp");
			al_convert_mask_to_alpha(czolk2, al_map_rgb(255, 255, 255));
			tlo = al_load_bitmap("tlo.bmp");
			al_convert_mask_to_alpha(tlo, al_map_rgb(255, 255, 255));

			
			

			
			
		
			while (!done)
			{			
				ALLEGRO_EVENT ev;

				
					al_draw_bitmap(tlo, 0, 0, 0);
					al_flip_display();
					al_clear_to_color(al_map_rgb(0, 0, 0));

					al_wait_for_event(event_queue, &ev);

					al_draw_bitmap(czolk, poz_x, poz_y, 0);
					al_flip_display();
					al_clear_to_color(al_map_rgb(0, 0, 0));
					
					
					al_wait_for_event(event_queue, &ev);
					

					
					
					
					if (ALLEGRO_EVENT_KEY_UP && ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
						done = true;
					if (ev.type == ALLEGRO_EVENT_KEY_DOWN){
						switch (ev.keyboard.keycode)
						{

						case ALLEGRO_KEY_RIGHT: poz_x += 25; break;

						case ALLEGRO_KEY_LEFT: poz_x -= 25; break;

						case ALLEGRO_KEY_UP: poz_y -= 25; break;

						case ALLEGRO_KEY_DOWN: poz_y += 25; break;

						}
					}
					al_draw_bitmap(czolk2, poz_x2, poz_y2, 0);
					al_flip_display();
					al_clear_to_color(al_map_rgb(0, 0, 0));
					
					al_wait_for_event(event_queue, &ev);
					al_draw_textf(font, al_map_rgb(0, 255, 0), 50, 5, ALLEGRO_ALIGN_CENTRE, "Odswiezanie: %i", counter);
					if (ALLEGRO_EVENT_KEY_UP && ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
						done = true;
					if (ev.type == ALLEGRO_EVENT_KEY_DOWN){
						switch (ev.keyboard.keycode)
						{

						case ALLEGRO_KEY_D: poz_x2 += 25; break;

						case ALLEGRO_KEY_A: poz_x2 -= 25; break;

						case ALLEGRO_KEY_W: poz_y2 -= 25; break;

						case ALLEGRO_KEY_S: poz_y2 += 25; break;

						}
					}


					counter++;
				}
						
			
			al_flip_display();
			al_destroy_event_queue(event_queue);
			al_destroy_display(display);
			al_destroy_timer(czas);

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


