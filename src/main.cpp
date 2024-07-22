#include <gtk/gtk.h>

static void activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window;
    GtkWidget *grid;
    GtkWidget *label;
    char text[10];

    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Network Monitor");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);

    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    for (int row = 0; row < 10; row++) {
        for (int col = 0; col < 10; col++) {
            snprintf(text, sizeof(text), "%d,%d", row, col);
            label = gtk_label_new(text);
            gtk_grid_attach(GTK_GRID(grid), label, col, row, 1, 1);
        }
    }

    gtk_widget_show_all(window);
}

int main(int argc, char **argv) {
    GtkApplication *app;
    int status;

    app = gtk_application_new("com.example.NetworkMonitor", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);

    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}
