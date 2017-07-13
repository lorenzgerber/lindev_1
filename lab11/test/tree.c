#include <gtk/gtk.h>

enum {
  COLUMN_TITLE,
  COLUMN_ARTIST,
  COLUMN_CATALOGUE,
  N_COLUMNS
};

struct newRow {
  GtkTreeStore *store;
  GtkTreeIter *parent_iter;
};

static int count = 0;

void closeApp ( GtkWidget *window, gpointer data){
  gtk_main_quit();
}

void button_clicked ( GtkWidget *button, gpointer data){
  printf("pressed %d times(s) \n", ++count);

  gtk_tree_store_append(((struct newRow*)data)->store, ((struct newRow*)data)->parent_iter, NULL);
  gtk_tree_store_set(((struct newRow*)data)->store, ((struct newRow*)data)->parent_iter, COLUMN_TITLE, "Side of the Moon", COLUMN_ARTIST, "Fink Floyd", COLUMN_CATALOGUE, "B000024D4P", -1);

}


int main (int argc, char *argv[]) {
  GtkWidget *window;
  GtkTreeStore *store;
  GtkWidget *view;
  GtkWidget *button;
  GtkWidget *hbox;
  GtkWidget *vbox;



  GtkTreeIter parent_iter, child_iter;
  GtkCellRenderer *renderer;
  gtk_init(&argc, &argv);


  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);
  g_signal_connect(GTK_OBJECT(window), "destroy", GTK_SIGNAL_FUNC(closeApp), NULL);

  store = gtk_tree_store_new(N_COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

  gtk_tree_store_append(store, &parent_iter, NULL);
  gtk_tree_store_set(store, &parent_iter, COLUMN_TITLE, "Dark Side of the Moon",
    COLUMN_ARTIST, "Pink Floyd", COLUMN_CATALOGUE, "B000024D4P", -1);

  gtk_tree_store_append(store, &parent_iter, NULL);
  gtk_tree_store_set(store, &parent_iter, COLUMN_TITLE, "Side of the Moon",
      COLUMN_ARTIST, "Fink Floyd", COLUMN_CATALOGUE, "B000024D4P", -1);

  gtk_tree_store_append(store, &parent_iter, NULL);
  gtk_tree_store_set(store, &parent_iter, COLUMN_TITLE, "the Moon",
        COLUMN_ARTIST, "Stink Floyd", COLUMN_CATALOGUE, "B000024D4P", -1);



  view = gtk_tree_view_new_with_model(GTK_TREE_MODEL(store));
  renderer = gtk_cell_renderer_text_new();
  g_object_set(renderer, "editable", TRUE, NULL);
  gtk_tree_view_insert_column_with_attributes(GTK_TREE_VIEW(view),
    COLUMN_TITLE, "Title", renderer, "text", COLUMN_TITLE, NULL);
  gtk_tree_view_insert_column_with_attributes(GTK_TREE_VIEW(view),
    COLUMN_ARTIST, "Artist", renderer, "text", COLUMN_ARTIST, NULL);
  gtk_tree_view_insert_column_with_attributes(GTK_TREE_VIEW(view),
    COLUMN_CATALOGUE, "Catalogue", renderer, "text", COLUMN_CATALOGUE, NULL);

struct newRow nr;
nr.store = store;
nr.parent_iter = &parent_iter;
struct newRow *ptr;
ptr = &nr;

button = gtk_button_new_with_label("Super Button");
g_signal_connect(GTK_OBJECT(button), "clicked",
  GTK_SIGNAL_FUNC(button_clicked), ptr);

hbox = gtk_hbox_new(TRUE, 5);
vbox = gtk_vbox_new(TRUE, 5);

gtk_box_pack_start(GTK_BOX(hbox), view, TRUE, FALSE, 5);
gtk_box_pack_start(GTK_BOX(vbox), button, TRUE, FALSE, 5);
gtk_box_pack_start(GTK_BOX(hbox), vbox, FALSE, FALSE, 5);

gtk_container_add(GTK_CONTAINER(window), hbox);

gtk_widget_show_all(window);

gtk_main();

return 0;
}
