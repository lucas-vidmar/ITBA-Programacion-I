#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h> //manejo de fonts
#include <allegro5/allegro_ttf.h> //Manejo de ttfs
#include "portlib.h"
#include "leds.h"


#define DISPLAYW    800
#define DISPLAYH    350
#define FPS 60.0
#define LEDW    DISPLAYW/8


//Esta funcion imprime el estado del puerto en el display.
void printdisplay(int puerto,ALLEGRO_BITMAP *leds);
//Esta funcion imprime los pasos de ejecucion.
void printfont(ALLEGRO_FONT * font);


int main(void) {

        ALLEGRO_DISPLAY * display = NULL;
        ALLEGRO_EVENT_QUEUE * event_queue = NULL;
        ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_BITMAP *leds = NULL;
        ALLEGRO_FONT *font = NULL;
        
        int  mask, puerto=PORTA, blink=false, blinkstatus, flagtime;
	bool close_display = false; 
	

	
	if(!al_init()) { //Primera funcion a llamar antes de empezar a usar allegro.
		fprintf(stderr, "failed to initialize allegro!\n");
		return -1;
	}
        
        if(!al_install_mouse()) {//initialize mouse.
		fprintf(stderr, "failed to initialize the mouse!\n");
		return -1;
	}

        if(!al_install_keyboard()) {//initialize keyboard.
		fprintf(stderr, "failed to initialize the keyboard!\n");
		return -1;
	}

        timer = al_create_timer(10.0 / FPS); //crea el timer pero NO empieza a correr
	if(!timer) {
		fprintf(stderr, "failed to create timer!\n");
		return -1;
	}

 	 
	event_queue = al_create_event_queue();//create event queue.
	if(!event_queue) {
		fprintf(stderr, "failed to create event_queue!\n");
                al_destroy_timer(timer);
		return -1;
	}
        
        al_init_font_addon(); // initialize the font addon
        al_init_ttf_addon();// initialize the ttf (True Type Font) addon

        font = al_load_ttf_font("disney.ttf",15,0 ); //HAY CREAR UN FONT PARA CADA TAMAÑO DE LETRA :( 
 
        if (!font){
            fprintf(stderr, "Could not load 'disney.ttf'.\n");
            return -1;
        }
        
        
	display = al_create_display(DISPLAYW,DISPLAYH); // Intenta crear display de 800x350 de fallar devuelve NULL
	if(!display) {
		fprintf(stderr, "failed to create display!\n");
                al_destroy_timer(timer);
                al_destroy_event_queue(event_queue);
		return -1;
	}
 
        leds = al_create_bitmap(LEDW, LEDW); //create leds bitmap.
	if(!leds) {
		fprintf(stderr, "failed to create leds bitmap!\n");
		al_destroy_display(display);
		al_destroy_timer(timer);
                al_destroy_event_queue(event_queue);
		return -1;
	}

        
        
        al_set_target_bitmap(leds); //Setea el bitmap a dibujar
 
	al_clear_to_color(al_map_rgb(255, 255, 255)); //Rellena el bitmap del led de blanco
 
	al_set_target_bitmap(al_get_backbuffer(display)); //Setea el bitmap a dibujar nuevamente en el display


 	//Registra el display a la cola de eventos, los eventos del display se iran guardando en la cola 
	// a medida que vayan sucediendo 
	al_register_event_source(event_queue, al_get_display_event_source(display)); //REGISTRAMOS LE DISPLAY
	al_register_event_source(event_queue, al_get_timer_event_source(timer)); //REGISTRAMOS EL TIMER
	al_register_event_source(event_queue, al_get_mouse_event_source()); //REGISTRAMOS EL MOUSE
  	al_register_event_source(event_queue, al_get_keyboard_event_source()); //REGISTRAMOS EL TECLADO
      
        
        
     
        
        
        al_clear_to_color(al_map_rgb(0,0,0)); //Hace clear del backbuffer del diplay al color RGB 0,0,0 (negro)
        printfont(font);
        
        init();
        output();//funciones leds.h
        
        al_start_timer(timer); //Recien aca EMPIEZA el timer
        
     	while(!close_display)
	{
		ALLEGRO_EVENT ev;
                
		if( al_get_next_event(event_queue, &ev) ) //Toma un evento de la cola.
		{
			switch(ev.type){    //analiza que tipo de evento es.
                            case ALLEGRO_EVENT_DISPLAY_CLOSE: //si se cerro el display, termina el programa.
				close_display = true;
                                break;
                            case ALLEGRO_EVENT_KEY_DOWN:    //evalua que tecla se presiono
                               
                                switch(ev.keyboard.keycode){
                                    case ALLEGRO_KEY_0: case ALLEGRO_KEY_PAD_0: //puede ingresar el numero de ambas maneras
                                        bitToggle(0, puerto);       //apaga o enciende el led dependiento de su estado 1->0, 0->1.
                                        set(1,true); //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
                                        blink= false;
                                        break;
                                    case ALLEGRO_KEY_1: case ALLEGRO_KEY_PAD_1:
                                        bitToggle(1, puerto);
                                        blink= false;
                                        break;
                                    case ALLEGRO_KEY_2: case ALLEGRO_KEY_PAD_2:
                                        bitToggle(2, puerto);
                                        blink= false;
                                        break;
                                    case ALLEGRO_KEY_3: case ALLEGRO_KEY_PAD_3:
                                        bitToggle(3, puerto);
                                        blink= false;
                                        break;
                                    case ALLEGRO_KEY_4: case ALLEGRO_KEY_PAD_4:
                                        bitToggle(4, puerto);
                                        blink= false;
                                        break;
                                    case ALLEGRO_KEY_5: case ALLEGRO_KEY_PAD_5:
                                        bitToggle(5, puerto);
                                        blink= false;
                                        break;
                                    case ALLEGRO_KEY_6: case ALLEGRO_KEY_PAD_6:
                                        bitToggle(6, puerto);
                                        blink= false;
                                        break;
                                    case ALLEGRO_KEY_7: case ALLEGRO_KEY_PAD_7:
                                        bitToggle(7, puerto);
                                        blink= false;
                                        break;
                                    case  ALLEGRO_KEY_B:    //empieza a parpadear
                                        blink = true;
                                        blinkstatus = true;
                                        break;
                                    case  ALLEGRO_KEY_T:    //se invierten todos los bits con la mascara 0xff.
                                        mask=0xFF;
					maskToggle(puerto,mask);
                                        blink= false;
                                        break;
                                    case  ALLEGRO_KEY_C:    //se borran todos los bits.
                                        mask=0xFF;
					maskOff(puerto,mask);
                                        blink= false;
                                        break;
                                    case  ALLEGRO_KEY_S:
                                        mask=0xFF;	//se prenden todos los bits. 
					maskOn(puerto,mask);
                                        blink= false;
                                        break;
                                    case  ALLEGRO_KEY_Q:    //cierra el programa.
                                        close_display = true;
                                        break;
                                }
                                break;
                            
                            case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:   //evalua que bit se presiono para encender o apagar.
                                if(ev.mouse.y<=100){
                                    switch((int)((ev.mouse.x)/(LEDW))){     //se hace una division para ver en que lugar esta.
                                        case 0:
                                            bitToggle(7, puerto);
                                            blink= false;
                                            break;
                                        case 1:
                                            bitToggle(6, puerto);
                                            blink= false;
                                            break;
                                        case 2:
                                            bitToggle(5, puerto);
                                            blink= false;
                                            break;
                                        case 3:
                                            bitToggle(4, puerto);
                                            blink= false;
                                            break;
                                        case 4:
                                            bitToggle(3, puerto);
                                            blink= false;
                                            break;
                                        case 5:
                                            bitToggle(2, puerto);
                                            blink= false;
                                            break;
                                        case 6:
                                            bitToggle(1, puerto);
                                            blink= false;
                                            break;
                                        case 7:
                                            bitToggle(0, puerto);
                                            blink= false;
                                            break;
                                    }      
                                }
                                break;    
                            case ALLEGRO_EVENT_TIMER: 
				flagtime = true;
                                break;
                        }
                        printdisplay(puerto, leds);
                        printfont(font);
                        al_flip_display();
		}
                
                if(flagtime && blink && al_is_event_queue_empty(event_queue)){ //si se presiono 'b' y no hay ningun evento, parpadea dependiendo del timer
                    flagtime = false;
                    if(!blinkstatus){   //si estaba prendido, se apaga, si estaba apagado, vuelve a prenderse.
                        al_clear_to_color(al_map_rgb(0,0,0));
                        printfont(font);
                        al_flip_display();
                        blinkstatus=true;
                    }
                    else{
                        printdisplay(puerto, leds);
                        printfont(font);
                        al_flip_display();
                        blinkstatus=false;
                    }
                    
                }        
	}
   
	
        //destruir recursos.
	al_destroy_display(display);
        al_destroy_timer(timer);
        al_destroy_event_queue(event_queue);
        al_destroy_bitmap(leds);
	
        
	return 0;
}


void printdisplay(int puerto,ALLEGRO_BITMAP *leds){     //evalua en el puerto que bits estan prendidos y los muestra en el display.
    int counter, ledcounter;
    al_clear_to_color(al_map_rgb(0,0,0));
    for(counter=7,ledcounter=0;counter>=0;counter--,ledcounter++){
        if(bitGet(counter,puerto)){
            al_draw_bitmap(leds,ledcounter*LEDW, 0, 0);
        }
    }
   
    //al_flip_display();
}
        
void printfont(ALLEGRO_FONT * font){
    al_draw_text(font, al_map_rgb(0,255,0), 0, 100,ALLEGRO_ALIGN_LEFT, "*****************************************************************************************************");
    al_draw_text(font, al_map_rgb(0,255,0), 0, 125,ALLEGRO_ALIGN_LEFT, "                   SIMULACION DEL PUERTO A");
    al_draw_text(font, al_map_rgb(0,255,0), 0, 150,ALLEGRO_ALIGN_LEFT, "Ingrese el número (del 0 al 7) del LED que se desea prender");
    al_draw_text(font, al_map_rgb(0,255,0), 0, 175,ALLEGRO_ALIGN_LEFT,"Ingrese 't' para cambiar todos los LEDs al estado opuesto");
    al_draw_text(font, al_map_rgb(0,255,0), 0, 200,ALLEGRO_ALIGN_LEFT, "Ingrese 'c' para apagar todos los LEDs");
    al_draw_text(font, al_map_rgb(0,255,0), 0, 225,ALLEGRO_ALIGN_LEFT, "Ingrese 's' para prender todos los LEDs");
    al_draw_text(font, al_map_rgb(0,255,0), 0, 250,ALLEGRO_ALIGN_LEFT, "Ingrese 'b' para que parpadeen los LEDs");
    al_draw_text(font, al_map_rgb(0,255,0), 0, 275,ALLEGRO_ALIGN_LEFT, "Ingrese 'q' para salir del programa");
    al_draw_text(font, al_map_rgb(0,255,0), 0, 300,ALLEGRO_ALIGN_LEFT, "*****************************************************************************************************");
    //al_flip_display();
}

