#include <gtk/gtk.h>

int main(int argc, char *argv[]){

  // declare window to be a pointer to GtkWidget
  GtkWidget *window;

  // initialize the GTK+ libriaries with a call to
  // gtk_init 
  gtk_init(&argc, &argv);

  // the core of the example: a new gtk window is setup
  // in memory and assigned to window. now the window can
  // be populated
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

  // after finished the configuration, the window
  // is set for viewing on the screen
  gtk_widget_show(window);

  // starting the main gtk loop
  gtk_main();
  return 0;
}
  
