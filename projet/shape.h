#ifndef SHAPE_H
#define SHAPE_H
#include "message.h"
#include <cmath>
#include<iostream>
#include"constantes.h"
using namespace std;
const double EPSILON_ZERO = 1e-5;

struct s2d {
    double x, y;
    };

struct segment {
    s2d    base;
    double alpha;
    double longeure;
    int    indice;
    s2d    extr;
};

double norm(s2d v);
double ecart(segment a, segment b);
int orientation(s2d p, s2d q, s2d r);
bool onsegment(s2d p, s2d q, s2d r);
bool intersection(segment a, segment b);
void inters_exi(int d1 , int d2,segment a, segment b);
void super_exist(segment a, segment b,int id);


#endif 
