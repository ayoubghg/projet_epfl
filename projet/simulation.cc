#include <fstream>
#include "simulation.h"
#include "lifeform.h"
#include "message.h"
#include "constantes.h"
#include "shape.h"
void simulation:: lecture (ifstream& f){
    int p,o,i;
f >> p;
nb_alg=p;
algue* alg = new algue[nb_alg];
double x,y;
 int  age;
    for (int i = 0; i < nb_alg; ++i) {
        f >> x >> y >> age;
        algue a(x,y,age);
        alg[i]=a;
    }
f >> p;
nbr_cor=p;  
   corail* cor = new corail [nbr_cor];
   double x1,y1;
   int age1,nbr_seg;
   double id ;
   int stt_cor,rott_cor,dev_stt;
   for(int i=0 ;i<nbr_cor;i++){
    f>> x1 >> y1 >> age1 >> id >> stt_cor >> rott_cor >> dev_stt >>nbr_seg;
            corail k(x1,y1,age1, id,stt_cor,rott_cor,dev_stt,nbr_seg);
            double *l=new double[nbr_seg];
            double *a=new double[nbr_seg];
            for(int n=0;n<nbr_seg;n++){
                
                f >> a[n];
                f >> l[n];
            }
            k.creation_segment(a,l);
        cor[i]=k;
    }

    
f >> p;
nbr_scav=p;     
scavenger* scav = new scavenger [nbr_scav];
    double x2,y2,r;
    int age2,stt,id_;
    for(int k=0;k<nbr_scav;k++){
        f>> x2 >> y2 >> age2 >>r >> stt >>id_;
        scavenger s (x2,y2,age2,r,stt,id_);
        scav[k]=s;
    }


////////////////////
for(int i=0 ;i<nb_alg;i++){
    alg[i].age_ver();
    alg[i].center_ver();
}
/////////////////////
for( int i=0 ;i<nbr_cor;i++)
{
          cor[i].age_ver();
          cor[i].pos_ver();
          cor[i].long_ver();
          cor[i].angle_ver();
          cor[i].dup_ver();
          segment *s=cor[i].get_tab_seg();

        for(int k=0;k<cor[i].get_nb_seg()-1;k++)
        {
          super_exist(s[k],s[k+1],cor[i]._id());
        }
            
        for (int j = 0; j < cor[i].get_nb_seg(); j++)
        {
            segment *s=cor[i].get_tab_seg();
            for (int k = 0; k < nbr_cor; k++)
            {
                segment *se = cor[k].get_tab_seg();

                for (int n = 0; n < cor[k].get_nb_seg(); n++)
                {
                    //  if (cor[k].get_idtab() != cor[i].get_idtab() || s[n].indice != se[n].indice)
                        inters_exi(cor[i].get_id(), cor[k].get_id(), s[j], s[n]);
   
                }
            }
        }

}
     /////////////////
     double ra;
for (int i=0 ;i<nbr_scav;i++){
        scav[i].age_ver();
        scav[i].center_ver();
        ra=scav[i].get_r();
        scav[1].radius_ver(ra);
        scav[i].invalid_ver();
     } 
     cout << message::success()<<endl;
     }
    