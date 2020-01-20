#include <gtk/gtk.h>

#include "exampleapp.h"
#include "exampleappwin.h"

struct _ExampleApp
{
	GtkApplication parent;
};

G_DEFINE_TYPE(ExampleApp, example_app, GTK_TYPE_APPLICATION);

static void example_app_init (ExampleApp *app) {
	g_message("example_app_init entry!");
}

static void example_app_activate (GApplication *app){
	ExampleAppWindow *win;
	g_message("example_app_activate entry!");

	win = example_app_window_new (EXAMPLE_APP (app));
	gtk_window_present (GTK_WINDOW (win));
}

static void example_app_open (GApplication  *app,
		GFile        **files,
		gint           n_files,
		const gchar   *hint) {
	GList *windows;
	ExampleAppWindow *win;
	int i;
	g_message("example_app_open entry!");

	windows = gtk_application_get_windows (GTK_APPLICATION (app));
	if (windows)
		win = EXAMPLE_APP_WINDOW (windows->data);
	else
		win = example_app_window_new (EXAMPLE_APP (app));

	for (i = 0; i < n_files; i++){
		g_message("example_app_open, to call window open, i=%d", i);
		example_app_window_open (win, files[i]);
	}

	gtk_window_present (GTK_WINDOW (win));
	g_message("example_app_open exit!");
}

ExampleApp * example_app_new (void) {
	g_message("example_app_new entry!");

	return g_object_new (EXAMPLE_APP_TYPE,
			"application-id", "org.gtk.exampleapp",
			"flags", G_APPLICATION_HANDLES_OPEN,
			NULL);
}

static void example_app_class_init (ExampleAppClass *class) {
	g_message("example_app_class_init entry!");

	G_APPLICATION_CLASS (class)->activate = example_app_activate;
	G_APPLICATION_CLASS (class)->open = example_app_open;
}


