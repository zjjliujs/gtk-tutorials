#include <gtk/gtk.h>

#include "exampleapp.h"
#include "exampleappwin.h"

struct _ExampleAppWindow {
  GtkApplicationWindow parent;
};

G_DEFINE_TYPE(ExampleAppWindow, example_app_window, GTK_TYPE_APPLICATION_WINDOW);

static void example_app_window_init (ExampleAppWindow *app) {
	g_message("example_app_window_init entry");
}

static void example_app_window_class_init (ExampleAppWindowClass *class) {
	g_message("example_app_window_class_init entry");
}

ExampleAppWindow * example_app_window_new (ExampleApp *app) {
	g_message("example_app_window_new entry");
	return g_object_new (EXAMPLE_APP_WINDOW_TYPE, "application", app, NULL);
}

void
example_app_window_open (ExampleAppWindow *win,GFile *file) {
	g_message("example_app_window_open, file path:%s", g_file_get_path(file)); 
}
