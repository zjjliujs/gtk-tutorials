#include <gtk/gtk.h>
#include <glib.h>

static void shutdown (GtkApplication* app, gpointer user_data) {
	g_info("shutdown entry!");
}

static void activate (GtkApplication* app, gpointer user_data)
{
	GtkWidget *window;

	//export G_MESSAGES_DEBUG=activat
	//或者
	//export G_MESSAGES_DEBUG=all
	//g_log("activate", G_LOG_LEVEL_INFO, "entry");
	//g_info("activate entry: user data: %p", user_data); 
	g_info("activate entry: user data: %s", (char *)user_data); 
	window = gtk_application_window_new (app);
	if (user_data)
		gtk_window_set_title (GTK_WINDOW (window), user_data);
	else
		gtk_window_set_title (GTK_WINDOW (window), "Window");
	gtk_window_set_default_size (GTK_WINDOW (window), 200, 200);
	gtk_widget_show_all (window);
}

int main (int argc, char **argv)
{
	GtkApplication *app;
	int status;

	app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
	//g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
	g_signal_connect (app, "activate", G_CALLBACK (activate), "Hello, gtk!");
	g_signal_connect (app, "shutdown", G_CALLBACK (shutdown), "Hello, gtk!");
	status = g_application_run (G_APPLICATION (app), argc, argv);
	g_object_unref (app);

	return status;
}
