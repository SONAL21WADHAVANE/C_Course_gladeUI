#include<sys/types.h>
#include<signal.h>
#include<unistd.h>
#include<gtk/gtk.h>
#include<sys/mman.h>
GtkWidget *Main_window;
GtkWidget *Container;
GtkWidget *Check_button;
GtkWidget *Display;
GtkBuilder *Cproject;
void on_destroy();
int main(int argc, char *argv[])
{
	gtk_init(&argc,&argv);
	Cproject=gtk_builder_new_from_file("Demo.glade");
	Main_window=GTK_WIDGET(gtk_builder_get_object(Cproject,"Main_window"));
	g_signal_connect(Main_window,"destroy",G_CALLBACK(gtk_main_quit),NULL);
	gtk_builder_connect_signals(Cproject,NULL);
	Container = GTK_WIDGET(gtk_builder_get_object(Cproject,"Container"));
	Check_button = GTK_WIDGET(gtk_builder_get_object(Cproject,"Check_button"));
	Display = GTK_WIDGET(gtk_builder_get_object(Cproject,"Display"));
	gtk_widget_show(Main_window);
	gtk_main();
	return EXIT_SUCCESS;
}

void on_Check_button_clicked(GtkButton *b)
{
	printf("OK\n");
	gtk_label_set_text(GTK_LABEL(Display),(const gchar*) "HELLO WORLD");
}


void on_destroy()
{
	gtk_main_quit();
}




