#include<gtk-3.0/gtk/gtk.h>

void hello(GtkWidget* widget,gpointer data)
{
	printf("Hello World\n");
}

void destroy(GtkWidget *widget,gpointer data)
{
	gtk_main_quit();
}

int main(int argc,char *argv[]){
	GtkWidget *first_window_button_distroy;
//================================================================
//decaring button pointer
	GtkWidget *button;
//================================================================
	gtk_init(&argc,&argv);
//*****************************************************************
//setting our window at top level
	first_window_button_distroy=gtk_window_new(GTK_WINDOW_TOPLEVEL);
	g_signal_connect(G_OBJECT(first_window_button_distroy),"destroy",G_CALLBACK(destroy),NULL);
//*****************************************************************

//taking container for setting width and button etc.
	gtk_container_set_border_width(GTK_CONTAINER(first_window_button_distroy),250);
//*****************************************************************
//adding button
	button=gtk_button_new_with_label("click here to print hello world");
//click performance
	g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(hello),NULL);

	gtk_container_add(GTK_CONTAINER(first_window_button_distroy),button);
	gtk_widget_show(button);
//showing window
	gtk_widget_show(first_window_button_distroy);
//****************************************************************	
//monitering pointer Eg:click or direction or position etc.
	gtk_main();
	return 0;
}
