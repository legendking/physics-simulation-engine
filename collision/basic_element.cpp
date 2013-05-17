include "basic_element.h"

coordinate::coordinate(double px,double py,double pz):x(px),y(py),z(pz){}

double coordinate::length(){
  return std::sqrt(x*x + y*y + z*z);
}

bool coordinate::ifNULL(){
  return (0==x && 0==y && 0==z);
}

coordinate coordinate::unit(){
  if(ifNULL()) return &this;
  else {
    coordinate tmp(x/length(),y/length(),z/length());
    return tmp;
  }
}
bool coordinate::operator==(const coordinate& x,const coordinate& y){
  return (x.x==y.x && x.y==y.y &&z.x==z.y);
}

coordinate coordinate::operator+(const coordinate& x,const coordinate& y){
  coordinate tmp(x.x+y.x,x.y+y.y,x.z+y.z);
  return tmp;
}

coordinate coordinate::operator-(const coordinate& x){
  coordinate tmp(-x.x,-x.y,-x.z);
  return tmp;
}

coordinate coordinate::operator-(const coordinate& x,const coordinate& y){
  coordinate tmp(x.x-y.x,x.y-y.y,x.z-y.z);
  return tmp;
}

coordinate coordinate::operator*(const double& multiple,const coordinate& x){
  coordinate tmp(multiple * x.x,multiple * x.y,multiple * x.z);
  return tmp;
}

coordinate coordinate::operator/(const coordinate& x,coonst double division){
  return coordinate::operator*(1/division,x);
}

coordinate coordinate::operator*(const coordinate &x,const double& multiple){
  return coordinate::operator*(multiple,x);
}

double coordinate::operator**(const coordinate &x,const coordinate &y){
  return x.x*y.x + x.y*y.y + x.z*y.z;
}

coordinate coordinate::operator*(const coordinate &x,const coordinate &y){
  coordinate tmp(x.y*y.z - x.z*y.y,x.z*y.x - x.x*y.z,x.x*y.y - x.y*y.x);
  return tmp;
}

bool coordinate::parrallel(const coordinate& x,const coordinate& y){
  return (x.x*y.y == x.y*y.x && x.z*y.x == x.x*y.z && x.y*y.z == x.z*y.y);
}

bool coordinate::vertical(cosnt coordinate& x,const coordinate& y){
  return (0 == x**y);
}

double coordinate::angle(const coordinate& x,const coordinate& y){
  if(x.ifNULL() || y.ifNULL()) return -1;
  else return std::acos( (x**y)/(x.length()*y.length()));
}
