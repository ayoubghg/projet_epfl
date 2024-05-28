#include "shape.h"
#include "constantes.h"



double ecart(segment A, segment B) {
    s2d vecA = {A.extr.x - A.base.x, A.extr.y - A.base.y};
    s2d vecB = {B.extr.x - B.base.x, B.extr.y - B.base.y};
    


    double dotProduct = vecA.x * vecB.x + vecA.y * vecB.y;
    double magA = sqrt(vecA.x * vecA.x + vecA.y * vecA.y);
    double magB = sqrt(vecB.x * vecB.x + vecB.y * vecB.y);

    double cosAngle = dotProduct / (magA * magB);
    double angle = acos(cosAngle);
    return angle;
}

void super_exist(segment a, segment b,int d1){
if(ecart(a,  b) < epsil_zero){
    cout << message::segment_superposition(d1,a.indice, b.indice);
    exit(EXIT_FAILURE);
}
}

bool OnSegment( s2d p1,  s2d p2,  s2d q) {
    s2d pr = {p2.x - p1.x, p2.y - p1.y};
    s2d pq = {q.x - p1.x, q.y - p1.y};
    double p_s = pr.x * pr.x + pr.y * pr.y;
    double pq_nor = pq.x * pr.x + pq.y * pr.y;
    double x = pq_nor / p_s;

    return (x >= -epsil_zero && x <= pq_nor + epsil_zero);
}


int orientation(s2d p, s2d q, s2d r) 
{ 
	s2d pr = {p.x - q.x, p.y - q.y};
    s2d pq = {q.x - q.x, q.y - q.y};
    double val = ((q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y)) / (pq.x * pq.x + pq.y * pq.y);
       
    if (val <= epsil_zero )
        return 0;
    
    return 1;
}


bool doIntersect(s2d p1, s2d q1, s2d p2, s2d q2) 
{ 
    int o1 = orientation(p1, q1, p2); 
    int o2 = orientation(p1, q1, q2); 
    int o3 = orientation(p2, q2, p1); 
    int o4 = orientation(p2, q2, q1); 
  
    if (o1 != o2 && o3 != o4) return true; 
  
    if (o1 == 0  && OnSegment(p1, p2, q1)) return true; 
  
    if (o2 == 0  && OnSegment(p1, q2, q1)) return true; 
  
    if (o3 == 0  && OnSegment(p2, p1, q2)) return true; 
  
    if (o4 == 0  && OnSegment(p2, q1, q2)) return true; 
  
    return false;  
} 



void inters_exi(int id1, int id2, segment A, segment B)
{
	if (doIntersect(A.base, A.extr, B.base, B.extr) == true)
	{
        if(id2== 299)
        B.indice=0;
		cout << message::segment_collision(id1, A.indice, id2, B.indice) << endl;
		exit(EXIT_FAILURE);
	}
}