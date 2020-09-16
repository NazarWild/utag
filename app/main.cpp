#include "src/main_lib.h"

int main(int argc, char **argv) {
	GtkWidget *window, *vbox;

    gtk_init (&argc, &argv);

    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    vbox = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);

    gtk_container_add (GTK_CONTAINER (window), vbox);

    gtk_widget_show_all (window);
    gtk_main ();

    return 0;
	return 0;
}