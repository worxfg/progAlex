#include<iostream>
#include<cmath>
#include "champpotentiels.h"

using namespace std;

std::ostream& operator<<(std::ostream& sortie, ChampPotentiels const& a_afficher)
{
    sortie<<"un champ de potentiels :"<<endl;
    sortie<<"Nx="<<a_afficher.getLx()/a_afficher.getlambda() +1<<" Ny="<<a_afficher.getLy()/a_afficher.getlambda() +1;
    sortie<<" Nz="<<a_afficher.getLz()/a_afficher.getlambda() +1<<endl;
    sortie<<"Lx="<<a_afficher.getLx()<<" Ly="<<a_afficher.getLy()<<" Lz="<<a_afficher.getLz()<<endl;
    sortie<<"lambda = "<<a_afficher.getlambda()<<endl;
    sortie<<"valeurs :"<<endl;
    for(int i(0); i<a_afficher.getLx()/a_afficher.getlambda()+1; ++i)
    {
        for(int j(0); j<a_afficher.getLy()/a_afficher.getlambda()+1; ++j)
        {
            for(int k(0); k<a_afficher.getLz()/a_afficher.getlambda()+1; ++k)
            {
                sortie<<i<<" "<<j<<" "<<k<<" "<<a_afficher.gettabPotentiels(i,j,k).getPotentiel()<<endl;
            }
        }
    }
    return sortie;
}
void ChampPotentiels :: initialise(double vinf, const Montagne& montt)
{
    Vecteur2D b;    //déclaration d'un vecteur nul
    Potentiel p(b,b);   //déclaration d'un Potentiel avec potentiel et laplacien nul
    tableau3D champ;
    for(int i(0); i<Lx/lambda+1; ++i)
    {
        std::vector<std::vector<Potentiel>> taby; //tableau avec les données parcourant les y pour x fixé
        for(int j(0); j<Ly/lambda+1; ++j)
        {
            std::vector<Potentiel> tabz;    //tableau avec les données parcourant les z pour x et y fixés
            for(int k(0); k<Lz/lambda+1; ++k)
            {
                if((k*lambda>=montt.altitude(i*lambda,j*lambda-Ly/2)) or (i==0) or abs(i-Lx/lambda)<1e-10 or (j==0) or abs(j-Ly/lambda)<1e-10) //au dessus de la montagne et aux
                                                                                                                    //bords initalisés selon les formules
                {
                    double e=(-vinf/2)*lambda*k;
                    double f=(vinf/2)*(j*lambda -Ly/2);
                    Vecteur2D u(e,f);
                    p.setPotentiel(u);
                    tabz.push_back(p);
                }
                else    //potentiel et laplacien inialisés à 0 en dessous de la montagne et pas aux bords
                {
                    Potentiel p(b,b);
                    tabz.push_back(p);
                }
            }
            taby.push_back(tabz);
        }
        champ.push_back(taby);
        tabPotentiels=champ;
    }

}




void ChampPotentiels :: calcule_laplaciens(const Montagne& montt)
{
    Vecteur2D b;
    for(int i(1); i<Lx/lambda; ++i)
    {
        for(int j(1); j<Ly/lambda; ++j)
        {
            for(int k(1); k<Lz/lambda; ++k)
            {
                if((k*lambda<montt.altitude(i*lambda,j*lambda-Ly/2)) or (i==0) or abs(i-Lx/lambda)<1e-10 or (j==0) or abs(j-Ly/lambda)<1e-10)
                {
                    tabPotentiels[i][j][k].setLaplacien(b);
                }
                else
                {
                    tabPotentiels[i][j][k].setLaplacien(tabPotentiels[i-1][j][k].getPotentiel()+tabPotentiels[i][j-1][k].getPotentiel()+tabPotentiels[i][j][k-1].getPotentiel()-6*tabPotentiels[i][j][k].getPotentiel()+tabPotentiels[i+1][j][k].getPotentiel()+tabPotentiels[i][j+1][k].getPotentiel()+tabPotentiels[i][j][k+1].getPotentiel());
                 }
            }
            }
        }

    }

void ChampPotentiels:: affiche_Potentiels() const
{
    for(int i(0); i<Lx/lambda+1; ++i)
    {
        for(int j(0); j<Ly/lambda+1; ++j)
        {
            for(int k(0); k<Lz/lambda+1; ++k)
            {
                std::cout<<i<<" "<<j<<" "<<k<<" "<<tabPotentiels[i][j][k].getPotentiel()<<endl;
            }
        }
    }
}
void ChampPotentiels:: affiche_Laplaciens()
{
    for(int i(1); i<Lx/lambda; ++i)
    {
        for(int j(1); j<Ly/lambda; ++j)
        {
            for(int k(1); k<Lz/lambda; ++k)
            {
                std::cout<<i<<" "<<j<<" "<<k<<" "<<tabPotentiels[i][j][k].getLaplacien()<<endl;
            }
        }
    }
}

void ChampPotentiels::affiche_potentiels_et_vent(double v){
    for (int i(0); i < Lx/lambda+1; i++){
        for (int j(0); j < Ly/lambda+1; j++){
            for (int k(0); k < Lz/lambda+1; k++){
               cout << i << " " << j << " " << k << " " << tabPotentiels[i][j][k].getPotentiel() << " " << vitesse(i, j, k , v)[0] << " " << vitesse(i, j, k , v)[1] << " " << vitesse(i, j, k , v)[2] << " "  << norme_vent(i, j, k , v) << endl;
            }
        }
    }
}



double ChampPotentiels:: erreur() const{
    double somme(0.0);
    for(size_t i(1); i<Lx/lambda; ++i)
    {
        for(size_t j(1); j<Ly/lambda; ++j)
        {
            for(size_t k(1); k<Lz/lambda; ++k)
            {
                somme=somme+ (tabPotentiels[i][j][k]).getLaplacien().norme2();
            }
         }
    }
        return somme;
}


void ChampPotentiels:: iteration(){
    for(int i(1); i<Lx/lambda; ++i)
    {
        for(int j(1); j<Ly/lambda; ++j)
        {
            for(int k(1); k<Lz/lambda; ++k)
            {
                (tabPotentiels[i][j][k]).setPotentiel((tabPotentiels[i][j][k]).getPotentiel()+0.1*((tabPotentiels[i][j][k]).getLaplacien()));
            }
         }
    }
}

void ChampPotentiels:: resolution(double seuil_erreur, int max_iteration, Montagne const & montagne, bool verbeuse){
    int nb_iteration (0);
    calcule_laplaciens(montagne);

    while ((erreur()>seuil_erreur) and (nb_iteration< max_iteration)){
        calcule_laplaciens(montagne);
        iteration();
        if(verbeuse==true){
        //affiche mais fait boucle infini donc pas besoin
        }
        nb_iteration=nb_iteration+1;
       // cout <<nb_iteration<<" "<<erreur()<<endl;
    }
}



double ChampPotentiels::norme_vent(int i, int j, int k , double v ){
    double x = vitesse(i , j , k , v )[0];
    double y = vitesse(i , j , k , v )[1];
    double z = vitesse(i , j , k , v )[2];

    return pow(x,2)+pow(y,2)+pow(z,2);

}

array<double,3> ChampPotentiels::vitesse(int i, int j, int k , double v)const {
    if (i==0 or j==0 or k==0 or i>=Lx/lambda or j>=Ly/lambda or k>=Lz/lambda){
        return  {v, 0.0, 0.0};;
    }

    else{

        Vecteur2D a = tabPotentiels[i-1][j][k].getPotentiel();
        Vecteur2D b = tabPotentiels[i][j-1][k].getPotentiel();
        Vecteur2D c = tabPotentiels[i][j][k-1].getPotentiel();
        Vecteur2D d = tabPotentiels[i+1][j][k].getPotentiel();
        Vecteur2D e = tabPotentiels[i][j+1][k].getPotentiel();
        Vecteur2D f = tabPotentiels[i][j][k+1].getPotentiel();

        return {
         (1.0 / (2*lambda)) * (e.getY() - b. getY() - f.getX() + c.getX()),
         (1.0 / (2*lambda)) * (-d.getY() + a. getY()),
         (1.0 / (2*lambda)) * (d.getX() - a. getX())
        };
       }


}
