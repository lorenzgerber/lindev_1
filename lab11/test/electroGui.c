#include <gtk/gtk.h>

enum {
  COLUMN_TITLE,
  COLUMN_RESISTOR,
  COLUMN_REPLACEMENT,
  N_COLUMNS
};

struct newRowEntry {
  GtkTreeStore *store_entry;
  GtkTreeIter *parent_iter_entry;
};

struct newRowResult {
  GtkTreeStore *store_result;
  GtkTreeIter *parent_iter_result;
};

void closeApp ( GtkWidget *window, gpointer data){
  gtk_main_quit();
};

void button_clicked ( GtkWidget *button, gpointer data){
  printf("calculating\n");
};

int main (int argc, char *argv[]){
  GtkWidget *window;
  GtkTreeStore *store_entry;
  GtkTreeStore *store_result;
  GtkWidget *view_entry;
  GtkWidget *view_result;
  GtkWidget *button;
  GtkWidget *hbox;
  GtkWidget *vbox;


  GtkTreeIter parent_iter_entry, child_iter_entry;
  GtkTreeIter parent_iter_result, child_iter_result;
  GtkCellRenderer *renderer_entry;
  GtkCellRenderer *renderer_result;
  gtk_init(&argc, &argv);


  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);
  g_signal_connect(GTK_OBJECT(window), "destroy", GTK_SIGNAL_FUNC(closeApp), NULL);

  store_entry = gtk_tree_store_new(N_COLUMNS, G_TYPE_INT);
  store_result = gtk_tree_store_new(N_COLUMNS, G_TYPE_INT);


  view_entry = gtk_tree_view_new_with_model(GTK_TREE_MODEL(store_entry));
  renderer_entry = gtk_cell_renderer_text_new();
  g_object_set(renderer_entry, "editable", TRUE, NULL);
  gtk_tree_view_insert_column_with_attributes(GTK_TREE_VIEW(view_entry),
    COLUMN_TITLE, "Resistor Ohm", renderer_entry, "text", COLUMN_TITLE, NULL);

  view_result = gtk_tree_view_new_with_model(GTK_TREE_MODEL(store_result));
  renderer_result = gtk_cell_renderer_text_new();
  g_object_set(renderer_result, "editable", TRUE, NULL);
  gtk_tree_view_insert_column_with_attributes(GTK_TREE_VIEW(view_result),
    COLUMN_TITLE, "Series", renderer_result, "text", COLUMN_TITLE, NULL);


  button = gtk_button_new_with_label("Super Button");
  g_signal_connect(GTK_OBJECT(button), "clicked",
    GTK_SIGNAL_FUNC(button_clicked), NULL);

  hbox = gtk_hbox_new(TRUE, 5);
  vbox = gtk_vbox_new(TRUE, 5);

  gtk_box_pack_start(GTK_BOX(hbox), view_entry, TRUE, FALSE, 5);
  gtk_box_pack_start(GTK_BOX(hbox), view_result, TRUE, FALSE, 5);
  gtk_box_pack_start(GTK_BOX(vbox), button, TRUE, FALSE, 5);
  gtk_box_pack_start(GTK_BOX(hbox), vbox, FALSE, FALSE, 5);

  gtk_container_add(GTK_CONTAINER(window), hbox);

  gtk_widget_show_all(window);

  gtk_main();

  return 0;



}
