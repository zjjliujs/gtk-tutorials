#include <gtk/gtk.h>

#include "exampleapp.h"

	int
main (int argc, char *argv[]){
	g_message("main entry!");

	return g_application_run (G_APPLICATION (example_app_new ()), argc, argv);
}
