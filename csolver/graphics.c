#include <gtk/gtk.h> 
  
static int counter = 0; 
  
void greet(GtkWidget* widget, gpointer data) 
{ 
    // printf equivalent in GTK+ 
    g_print("Welcome to GTK\n"); 
    g_print("%s clicked %d times\n", 
            (char*)data, ++counter); 
} 

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
        //open_file (filename);
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

static void activate(GtkApplication* app, gpointer user_data)
{
    
    GtkWidget* window;
    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Hi");
    gtk_window_set_default_size(GTK_WINDOW(window), 500,500 );
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);
    
    GtkWidget* grid;
    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid); 

    //GtkWidget* button_box;
    //button_box = gtk_button_box_new (GTK_ORIENTATION_HORIZONTAL);
    //gtk_container_add (GTK_CONTAINER (window), button_box);
    
    GtkWidget* updateButton;
    updateButton = gtk_button_new_with_label ("update");
    g_signal_connect (updateButton, "clicked", G_CALLBACK (print_hello), NULL);
    gtk_grid_attach(GTK_GRID(grid), updateButton, 0,0,1,1);
    //gtk_container_add (GTK_CONTAINER (button_box), updateButton);
    
    GtkWidget* openButton;
    openButton = gtk_button_new_with_label ("Open puzzle");
    g_signal_connect (openButton, "clicked", G_CALLBACK (open_puzzle), NULL);
    gtk_grid_attach(GTK_GRID(grid), openButton, 0,1,1,1);


    GtkWidget* closeButton;
    closeButton = gtk_button_new_with_label ("Close");
    g_signal_connect (closeButton, "clicked", G_CALLBACK (destroy), NULL);
    gtk_grid_attach(GTK_GRID(grid), closeButton, 0,2,1,1);

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

    // mainWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL); 
  
    // g_signal_connect(mainWindow, "destroy", G_CALLBACK(destroy), NULL); 
    // /* Let's set the border width of the window to 20. 
    // * You may play with the value and see the 
    // * difference. */
    // gtk_container_set_border_width(GTK_CONTAINER(mainWindow), 20); 
  
    // updateButton = gtk_button_new_with_label("Update!"); 
    
  
    // g_signal_connect(ATK_OBJECT(updateButton), 
    //                  "clicked", G_CALLBACK(greet), 
    //                  "button"); 

    // closeButton = gtk_button_new_with_label("Close"); 
    // g_signal_connect(ATK_OBJECT(closeButton), "clicked", 
    //                  G_CALLBACK(destroy), NULL); 
  
    // gtk_container_add(GTK_CONTAINER(mainWindow), updateButton);
    // gtk_container_add(GTK_CONTAINER(mainWindow), closeButton);
     
  
    // gtk_widget_show_all(mainWindow); 
  
    // gtk_main(); 
  
    return ret; 
} 