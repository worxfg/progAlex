#pragma once
#include <vector>
#include "array"

class Boite
{
public:
    Boite(std::array<double,3>longueur1, std::array<int,3> nb_cube1 ):longueur(longueur1), nb_cube(nb_cube1){
        lambda=longueur[0]/(nb_cube[0]-1);
        for (int i(0);i<3;++i){
            longueur[i]=longueur1[i];
            nb_cube[i]=nb_cube1[i];

        }};/*initialise les longueurs des côtés et le pas d'échantillonage*/

        Boite(double Lx, double Ly, double Lz, double lambda):Lx(Lx),Ly(Ly),Lz(Lz),lambda(lambda){}

   std::array<double,3>getlongueur() const{
       return longueur;
   }

   std::array<int,3>getnb_cube() const{
   return nb_cube;
   }
   double getLx() const{
       return Lx;
   }
   double getLy() const{
       return Ly;
   }
   double getLz() const{
       return Lz;
   }

    void setlambda(double nlambda)
    {
        lambda=nlambda;
    }
    double getlambda() const
    {
        return lambda;
    }


bool bord(int, int) const; //return true si le premier arguement est au bord du champ dans la direction du deuxieme arguement



    protected:
  std::array<double,3>longueur;
  std::array<int,3>nb_cube;
   double Lx;
   double Ly;
   double Lz;
   double lambda;


};

