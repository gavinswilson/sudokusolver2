#include <gtk/gtk.h>
#include "file.h"


void open_puzzle(GtkWidget* widget, gpointer data)
{
    GtkWidget *dialog;
    GtkFileChooserAction action = GTK_FILE_CHOOSER_ACTION_OPEN;
    gint res;

    dialog = gtk_file_chooser_dialog_new ("Open File", GTK_WINDOW(widget), action,"Cancel",GTK_RESPONSE_CANCEL,"Open",GTK_RESPONSE_ACCEPT, NULL);

    res = gtk_dialog_run (GTK_DIALOG (dialog));
    if (res == GTK_RESPONSE_ACCEPT)
    {
        char *filename;
        GtkFileChooser *chooser = GTK_FILE_CHOOSER (dialog);
        filename = gtk_file_chooser_get_filename (chooser);
        open_file(filename);
        // open_file();
        g_free (filename);
    }

    gtk_widget_destroy (dialog);
}
void destroy(GtkWidget* widget, gpointer data) 
{ 
    gtk_window_close(GTK_WINDOW(widget)); 
} 

void print_hello(GtkWidget* widget, gpointer data)
{
    printf("Hello");
}

