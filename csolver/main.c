
#include <gtk/gtk.h> 

#include "window.h"  
#include "file.h"

int puzzle[9][9];

static void activate(GtkApplication* app, gpointer user_data)
{
    
    GtkWidget* window;
    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Hi");
    gtk_window_set_default_size(GTK_WINDOW(window), 500,500 );
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);
    //c
    GtkWidget* grid;
    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid); 

    //GtkWidget* button_box;
    //button_box = gtk_button_box_new (GTK_ORIENTATION_HORIZONTAL);
    //gtk_container_add (GTK_CONTAINER (window), button_box);
    GtkWidget *label11 = gtk_label_new_with_mnemonic ("-");
    gtk_grid_attach(GTK_GRID(grid), label11, 0,0,1,1);
    GtkWidget *label21 = gtk_label_new_with_mnemonic ("-");
    gtk_grid_attach(GTK_GRID(grid), label21, 1,0,1,1);
    GtkWidget *label31 = gtk_label_new_with_mnemonic ("-");
    gtk_grid_attach(GTK_GRID(grid), label31, 2,0,1,1);
    GtkWidget *label41 = gtk_label_new_with_mnemonic ("-");
    gtk_grid_attach(GTK_GRID(grid), label41, 3,0,1,1);
    GtkWidget *label51 = gtk_label_new_with_mnemonic ("-");
    gtk_grid_attach(GTK_GRID(grid), label51, 4,0,1,1);
    GtkWidget *label61 = gtk_label_new_with_mnemonic ("-");
    gtk_grid_attach(GTK_GRID(grid), label61, 5,0,1,1);
    GtkWidget *label71 = gtk_label_new_with_mnemonic ("-");
    gtk_grid_attach(GTK_GRID(grid), label71, 6,0,1,1);
    GtkWidget *label81 = gtk_label_new_with_mnemonic ("-");
    gtk_grid_attach(GTK_GRID(grid), label81, 7,0,1,1);
    GtkWidget *label91 = gtk_label_new_with_mnemonic ("-");
    gtk_grid_attach(GTK_GRID(grid), label91, 8,0,1,1);
    GtkWidget *label12 = gtk_label_new_with_mnemonic ("-");
    gtk_grid_attach(GTK_GRID(grid), label12, 0,1,1,1);
    GtkWidget *label22 = gtk_label_new_with_mnemonic ("-");
    gtk_grid_attach(GTK_GRID(grid), label22, 1,1,1,1);
    GtkWidget *label32 = gtk_label_new_with_mnemonic ("-");
    gtk_grid_attach(GTK_GRID(grid), label32, 2,1,1,1);
    GtkWidget *label42 = gtk_label_new_with_mnemonic ("-");
    gtk_grid_attach(GTK_GRID(grid), label42, 3,1,1,1);
    GtkWidget *label52 = gtk_label_new_with_mnemonic ("-");
    gtk_grid_attach(GTK_GRID(grid), label52, 4,1,1,1);
    GtkWidget *label62 = gtk_label_new_with_mnemonic ("-");
    gtk_grid_attach(GTK_GRID(grid), label62, 5,1,1,1);
    GtkWidget *label72 = gtk_label_new_with_mnemonic ("-");
    gtk_grid_attach(GTK_GRID(grid), label72, 6,1,1,1);
    GtkWidget *label82 = gtk_label_new_with_mnemonic ("-");
    gtk_grid_attach(GTK_GRID(grid), label82, 7,1,1,1);
    GtkWidget *label92 = gtk_label_new_with_mnemonic ("-");
    gtk_grid_attach(GTK_GRID(grid), label92, 8,1,1,1);
    GtkWidget *label13 = gtk_label_new_with_mnemonic ("-");
    gtk_grid_attach(GTK_GRID(grid), label13, 0,2,1,1);
    GtkWidget *label23 = gtk_label_new_with_mnemonic ("-");
    gtk_grid_attach(GTK_GRID(grid), label23, 1,2,1,1);
    GtkWidget *label33 = gtk_label_new_with_mnemonic ("-");
    gtk_grid_attach(GTK_GRID(grid), label33, 2,2,1,1);
    GtkWidget *label43 = gtk_label_new_with_mnemonic ("-");
    gtk_grid_attach(GTK_GRID(grid), label43, 3,2,1,1);
    GtkWidget *label53 = gtk_label_new_with_mnemonic ("-");
    gtk_grid_attach(GTK_GRID(grid), label53, 4,2,1,1);
    GtkWidget *label63 = gtk_label_new_with_mnemonic ("-");
    gtk_grid_attach(GTK_GRID(grid), label63, 5,2,1,1);
    GtkWidget *label73 = gtk_label_new_with_mnemonic ("-");
    gtk_grid_attach(GTK_GRID(grid), label73, 6,2,1,1);
    GtkWidget *label83 = gtk_label_new_with_mnemonic ("-");
    gtk_grid_attach(GTK_GRID(grid), label83, 7,2,1,1);
    GtkWidget *label93 = gtk_label_new_with_mnemonic ("-");
    gtk_grid_attach(GTK_GRID(grid), label93, 8,2,1,1);


    GtkWidget* updateButton = gtk_button_new_with_label ("update");
    g_signal_connect (updateButton, "clicked", G_CALLBACK (print_hello), NULL);
    gtk_grid_attach(GTK_GRID(grid), updateButton, 11,10,1,1);
    //gtk_container_add (GTK_CONTAINER (button_box), updateButton);
    
    GtkWidget* openButton;
    openButton = gtk_button_new_with_label ("Open puzzle");
    g_signal_connect (openButton, "clicked", G_CALLBACK (open_puzzle), NULL);
    gtk_grid_attach(GTK_GRID(grid), openButton, 11,11,1,1);


    GtkWidget* closeButton;
    closeButton = gtk_button_new_with_label ("Close");
    g_signal_connect (closeButton, "clicked", G_CALLBACK (destroy), NULL);
    gtk_grid_attach(GTK_GRID(grid), closeButton, 11,12,1,1);

    // gtk_container_add (GTK_CONTAINER (button_box), closeButton);
    
    gtk_widget_show_all(window);
}
   


int main(int argc, char* argv[]) 
{ 
  
    GtkApplication* mainApp;
    // GtkWidget* mainWindow; 
    // GtkWidget* updateButton;
    // GtkWidget* closeButton; 
    gtk_init(&argc, &argv); 
    
    int ret;
    mainApp = gtk_application_new("org.gtk.app", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(mainApp, "activate", G_CALLBACK(activate), NULL);

    ret = g_application_run(G_APPLICATION(mainApp), argc, argv );

    g_object_unref(mainApp);

    return ret; 
} 