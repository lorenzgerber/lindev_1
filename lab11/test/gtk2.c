#include <gtk/gtk.h>
#include <stdio.h>

static int count = 0;

// this is the callback function
void button_clicked(GtkWidget *button, gpointer data) {
  printf("%s pressed %d times(s) \n", (char *) data, ++count);
}

int main(int argc, char *argv[]){

  /* 
   * declare window and button to
   * be a pointer to GtkWidget 
   */
  GtkWidget *window;
  GtkWidget *button;

  /* 
   * initialize the GTK+ libriaries 
   * with a call to gtk_init
   */ 
  gtk_init(&argc, &argv);

  /* 
   * the core of the example: a new gtk 
   * window is setup in memory and 
   * assigned to window. now the window can
   * be populated
   */
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);


  /*
   * Here a button with label is set up and assigned
   * to it's container, the window. Then the signal
   * of the button is connected to the callback
   * function button_clicked
   */
  button = gtk_button_new_with_label("Hello World!");
  gtk_container_add(GTK_CONTAINER(window), button);


  /*
   * Then the signal of the button is connected to the
   * callback function button_clicked
   */
  g_signal_connect(GTK_OBJECT (button), "clicked",
		   GTK_SIGNAL_FUNC(button_clicked),
		   "Button1");

  /*
   * after finishing configurations of the widgets
   * button and window, they are set for viewing
   */
  gtk_widget_show(button);
  gtk_widget_show(window);

  // starting the main gtk loop
  gtk_main();
  return 0;
}
  
