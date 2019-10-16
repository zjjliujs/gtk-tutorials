#include <gtk/gtk.h>

GdkPixbuf *create_pixbuf(const gchar * filename) {
	GdkPixbuf *pixbuf = NULL;
	GError *error = NULL;
	pixbuf = gdk_pixbuf_new_from_file(filename, &error);
	if (!pixbuf)
	{
		fprintf(stderr, "%s\n", error->message);
		g_error_free(error);
	}

	return pixbuf;
}

int main(int argc, char *argv[])
{
	GtkWidget *window;   
	GdkPixbuf *icon;
	//初始化系统
	gtk_init(&argc, &argv);
	//创建window
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	//设置window
	gtk_window_set_title(GTK_WINDOW(window), "Icon");
	gtk_window_set_default_size(GTK_WINDOW(window), 230, 150);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	//载入icon
	icon = create_pixbuf("drawable/demo.png");
	if (icon != NULL){
		gtk_window_set_icon(GTK_WINDOW(window), icon);
		//释放icon
		g_object_unref(icon);
	}
	//显示window
	gtk_widget_show(window);
	//设置属于反应
	g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
	//主循环
	gtk_main();
}
