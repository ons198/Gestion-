#include <gtk/gtk.h>


void
on_button_ajout_clicked                (GtkWidget       *button,
                                        gpointer         user_data);

void
on_checkbutton_ing_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton_prepa_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton_business_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button2_clicked                     (GtkWidget       *button,
                                        gpointer         user_data);

void
on_button_afficher_clicked             (GtkWidget      *objet_graphique,
                                        gpointer         user_data);

void
on_radiobutton_mme_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_mr_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_supprimer_clicked            (GtkWidget      *objet_graphique,
                                        gpointer         user_data);

void
on_button_modifier_clicked             (GtkWidget       *button,
                                        gpointer         user_data);

void
on_button_rechercher_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button_modifiier_clicked            (GtkWidget       *button,
                                        gpointer         user_data);

void
on_button_rechercher2_clicked          (GtkWidget      *button,
                                        gpointer         user_data);

void
on_button_modifier1_clicked            (GtkWidget      *objet_graphique,
                                        gpointer         user_data);

void
on_button_supprimer2_clicked           (GtkWidget      *button,
                                        gpointer         user_data);

void
on_button_affichertreeview_clicked     (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button_tree_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_button_aff_tree_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data);
