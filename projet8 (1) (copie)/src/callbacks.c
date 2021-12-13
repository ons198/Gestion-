#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include <stdio.h>
#include "etudiant.h"
#include <string.h>


int x,y,niveau;
void on_button_ajout_clicked (GtkWidget *objet_graphique, gpointer user_data)
{GtkWidget
*fenetre_afficher,*fenetre_ajouter, *treeview1;
fenetre_afficher=lookup_widget(button,"fenetre_afficher");
fenetre_ajouter=lookup_widget(button,"fenetre_ajouter");
gtk_widget_destroy(fenetre_afficher);
fenetre_ajouter=create_fenetre_ajouter();
gtk_widget_show(fenetre_ajouter);
}


void on_checkbutton_ing_toggled (GtkToggleButton *togglebutton, gpointer user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
  y=0;
}


void on_checkbutton_prepa_toggled (GtkToggleButton *togglebutton, gpointer user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
  y=1;
}


void on_checkbutton_business_toggled (GtkToggleButton *togglebutton, gpointer user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
  y=2;
}

void on_radiobutton_mme_toggled (GtkToggleButton *togglebutton, gpointer user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{x=0;} 
}
void on_radiobutton_mr_toggled (GtkToggleButton *togglebutton, gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{x=1;}
}


void on_button2_clicked (GtkWidget *objet_graphique,
gpointer user_data)
{
Etudiant etd;
char Bloc[20];
GtkWidget *nom, *prenom, *age, *niveau, *cin, *mdp, *jour, *mois, *annee, *label23, *combobox ;
nom = lookup_widget (objet_graphique,"entry_nom");
prenom = lookup_widget (objet_graphique,"entry_prenom");
age = lookup_widget (objet_graphique, "entry_age");
niveau = lookup_widget (objet_graphique, "entry_niveau");
mdp = lookup_widget (objet_graphique, "entry_mdp");
cin = lookup_widget (objet_graphique, "entry_cin");
jour = lookup_widget (objet_graphique, "spinbutton_jour");
mois = lookup_widget (objet_graphique, "spinbutton_mois");
annee = lookup_widget (objet_graphique, "spinbutton_annee");
combobox2=lookup_widget(objet_graphique,"combobox2");
strcpy(etd.nom, gtk_entry_get_text(GTK_ENTRY(nom))); //faire une copie mta nom fel etd.nom
strcpy(etd.prenom, gtk_entry_get_text(GTK_ENTRY(prenom)));
strcpy(etd.age, gtk_entry_get_text(GTK_ENTRY(age)));
strcpy(etd.niveau, gtk_entry_get_text(GTK_ENTRY(niveau)));
strcpy(etd.mdp, gtk_entry_get_text(GTK_ENTRY(mdp)));
strcpy(etd.cin, gtk_entry_get_text(GTK_ENTRY(cin)));

etd.d.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
etd.d.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
etd.d.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
 
if(strcmp("1",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)))==0)
 etd.niveau=1;
if(strcmp("2",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)))==0)
 etd.niveau=2;
if(strcmp("3",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)))==0)
 etd.niveau=3;
if(strcmp("4",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)))==0)
 etd.niveau=4;
if(strcmp("5",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)))==0)
 etd.niveau=5;

etd.sexe=x;

etd.education=y;

ajouter(etd);
}

void on_button_afficher_clicked (GtkWidget *objet_graphique, gpointer user_data)
{
    GtkWidget *fenetre_ajouter;
    GtkWidget *fenetre_afficher;
    GtkWidget *treeview;

fenetre_ajouter=lookup_widget(objet_graphique,"fenetre_ajouter");
fenetre_afficher=lookup_widget(objet_graphique,"fenetre_afficher");
fenetre_afficher=create_fenetre_afficher();
gtk_widget_destroy(fenetre_ajouter);
gtk_widget_show(fenetre_afficher);

treeview=lookup_widget(fenetre_afficher,"treeview1");
afficher(treeview,"Etudiant1.txt");

    }

void on_button_supprimer_clicked (GtkWidget *objet_graphique, gpointer user_data)
{
 GtkWidget *fenetre_ajouter , *fenetre_afficher;
 GtkTreeModel  *model;
 GtkTreeSelection  *selection;
 GtkTreeIter  iter;
 GtkWidget* treeview;


  gchar* cin;
 
fenetre_afficher=lookup_widget(objet_graphique,"fenetre_afficher");
treeview=lookup_widget(fenetre_afficher,"treeview1");
selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(treeview));
if(gtk_tree_selection_get_selected(selection,&model, &iter))
   {
    gtk_tree_model_get (model,&iter,0,&cin,-1);
    supprimer(cin);
    afficher(treeview,"Etudiant1.txt");
   } 
}



void on_button_modifiier_clicked (GtkWidget *objet_graphique, gpointer user_data)
{
 *GtkWidget *fenetre_ajouter, *fenetre_afficher;
    GtkTreeModel        *model;
    GtkTreeSelection  *selection;
    GtkTreeIter iter;
    GtkWidget* treeview;
    
    Etudiant etd ;

    gchar* nom;
    gchar* prenom;
    gchar* age;
    gchar* mdp;
    gint niveau;
    gchar* cin;
    gint sexe;
    gint education;
    gint jour;
    gint mois;
    gint annee;
    gint bloc; 
fenetre_afficher=lookup_widget(objet_graphique,"fenetre_afficher");

treeview=lookup_widget(fenetre_afficher,"treeview1");
   selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(treeview));
   if(gtk_tree_selection_get_selected(selection, &model, &iter))
   {
        gtk_tree_model_get (model, &iter,0,&nom,1,&prenom,2,&age,3,&mdp,4,&niveau,5,&cin,6,&sexe,7,&education,8,&jour,9,&mois,10,&annee,-1);
        gtk_widget_destroy(fenetre_afficher);

fenetre_ajouter=lookup(button,"fenetre_ajouter");
        fenetre_ajouter=create_fenetre_ajouter();
        gtk_widget_show(fenetre_ajouter);
   

      nom=lookup_widget(button,"entry_nom");
      strcpy(etd.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
      gtk_entry_set_text(GTK_ENTRY("entry_nom"));
      

      prenom=lookup_widget(button,"entry_prenom");
      strcpy(etd.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));
      gtk_entry_set_text(GTK_ENTRY("entry_prenom"));

     age=lookup_widget(button,"entry_age");
      strcpy(etd.age,gtk_entry_get_text(GTK_ENTRY(age)));
      gtk_entry_set_text(GTK_ENTRY("entry_age")); 

     niveau=lookup_widget(button,"entry_niveau");
      strcpy(etd.niveau,gtk_entry_get_text(GTK_ENTRY(niveau)));
      gtk_entry_set_text(GTK_ENTRY("entry_niveau"));

     cin=lookup_widget(button,"entry_cin");
      strcpy(etd.cin,gtk_entry_get_text(GTK_ENTRY(cin)));
      gtk_entry_set_text(GTK_ENTRY("entry_cin"));

     mdp=lookup_widget(button,"entry_mdp");
      strcpy(etd.mdp,gtk_entry_get_text(GTK_ENTRY(mdp)));
      gtk_entry_set_text(GTK_ENTRY("entry_mdp"));

gtk_spin_button_set_value(GTK_SPIN_BUTTON(lookup_widget(fenetre_ajouter,"spinbutton_jour")));

gtk_spin_button_set_value(GTK_SPIN_BUTTON(lookup_widget(fenetre_ajouter,"spinbutton_mois")));

gtk_spin_button_set_value(GTK_SPIN_BUTTON(lookup_widget(fenetre_ajouter,"spinbutton_annee")));

gtk_combo_box_set_active(GTK_COMBO_BOX(lookup_widget(fenetre_ajouter,"combobox1")));
gtk_combo_box_set_active(GTK_COMBO_BOX(lookup_widget(fenetre_ajouter,"combobox2")));
}


void
on_button_rechercher_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{  
    
 GtkWidget *cinr,*lcin ,*lnom, *lprenom; *lage; *lniveau; *lmdp; *lsexe; *leducation;
    char cin[20];
    Etudiant etd;
    int x=-1;
    int sexe, education ,niveau;
     cinr=lookup_widget(objet_graphique,"cinr");

     lcin=lookup_widget(objet_graphique,"lcin");
     lnom=lookup_widget(objet_graphique,"lnom");
     lprenom=lookup_widget(objet_graphique,"lprenom");
     lage=lookup_widget(objet_graphique,"lage");
     lniveau=lookup_widget(objet_graphique,"lniveau");
     lmdp=lookup_widget(objet_graphique,"lmdp");
     lsexe=lookup_widget(objet_graphique,"sexe");
     leducation=lookup_widget(objet_graphique,"leducation");
     

  f=fopen("Etudiant1.txt","r");

  if(f!=NULL)
{ 
  while (fscanf(f,"%s %s %s %s %s %d %d %d  %d %d %d  \n",etd.nom,etd.prenom,etd.cin,etd.mdp,etd.age,&etd.niveau,&etd.sexe,&etd.education,&etd.d.jour, &etd.d.mois,&etd.d.annee)!=EOF)
 {
   if ((strcmp(cin,etd.cin)==0)
     x=1;
  }
fclose(f);
}

if (x==-1){
gtk_label_set_text(GTK_LABEL(l9)," CIN n'existe pas");
gtk_label_set_text(GTK_LABEL(lnom)," ");
gtk_label_set_text(GTK_LABEL(lprenom)," ");
gtk_label_set_text(GTK_LABEL(lage)," ");
gtk_label_set_text(GTK_LABEL(lniveau)," ");
gtk_label_set_text(GTK_LABEL(leducation)," ");
gtk_label_set_text(GTK_LABEL(lsexe)," ");
     
} 
else {
 fflush(stdin);
 gtk_label_set_text(GTK_LABEL(lnom),etd.nom);
 gtk_label_set_text(GTK_LABEL(lprenom),etd.prenom);
 gtk_label_set_text(GTK_LABEL(lage),etd.age);
 gtk_label_set_text(GTK_LABEL(lmdp),etd.mdp);
 gtk_label_set_text(GTK_LABEL(lniveau),etd.niveau);
sprintf(niveau,"%d",etd.niveau);
 gtk_label_set_text(GTK_LABEL(lsexe),etd.sexe);
sprintf(sexe,"%d",etd.sexe);
 gtk_label_set_text(GTK_LABEL(leducation),etd.education);
sprintf(education,"%d",etd.education);


}}






void
on_button_modifier1_clicked            (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{

 Etudiant etd;
 GtkWidget *nom, *prenom, *age, *niveau, *cin, *mdp, *jour, *mois, *annee,*bloc, *combobox1, *combobox2; 
      nom=lookup_widget(objet_graphique,"entry_nom");
      prenom=lookup_widget(objet_graphique,"entry_prenom");
      age=lookup_widget(objet_graphique,"entry_age");
      niveau=lookup_widget(objet_graphique,"entry_niveau");
      cin=lookup_widget(objet_graphique,"entry_cin");
      mdp=lookup_widget(objet_graphique,"entry_mdp");
      jour=lookup_widget(objet_graphique,"spinbutton_jour");
      mois=lookup_widget(objet_graphique,"spinbutton_mois");
      annee=lookup_widget(objet_graphique,"spinbutton_annee");
      bloc=lookup_widget(objet_graphique,"combobox1");

   strcpy(etd.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
   strcpy(etd.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));
   strcpy(etd.age,gtk_entry_get_text(GTK_ENTRY(age)));
   strcpy(etd.niveau,gtk_entry_get_text(GTK_ENTRY(niveau)));
   strcpy(etd.cin,gtk_entry_get_text(GTK_ENTRY(cin)));
   strcpy(etd.mdp,gtk_entry_get_text(GTK_ENTRY(mdp)));
   
  etd.d.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
  etd.d.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
  etd.d.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));


   if(strcmp("A1==>A10",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)))==0)
 etd.bloc=1;
else
 etd.bloc=2;

if(strcmp("1",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)))==0)
 etd.niveau=1;
if(strcmp("2",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)))==0)
 etd.niveau=2;
if(strcmp("3",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)))==0)
 etd.niveau=3;
if(strcmp("4",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)))==0)
 etd.niveau=4;
if(strcmp("5",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)))==0)
 etd.niveau=5;

  etd.sexe=x ;
  

 etd.education=y;

modifier(etd);
  
  
}
}





  



void
on_button_aff_tree_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
  GtkWidget *liste,*file;
liste=lookup_widget(objet_graphique,"treeview1");
afficher(liste,file);


}


