#ifndef __BASICELEMENT_H
#define __BASICELEMENT_H

//A defination of coordinate, a vector describe position, velosity or acceleration.
class coordinate{
 public:
  //3D system with 3 independent component
  double x;
  double y;
  double z;

  coordinate(){};
  coordinate(int,int,int){};
  ~coordinate(){};

  //operator overloading
  //vector equality
  bool operator==(coordinate);
  //vector addition
  coordinate operator+(coordinate);
  //vector subtraction
  coordinate operator-();
  coordinate operator-(coordinate);
  //vector scalar multiplication
  coordinate operator*(double);
  //vector dot product
  double operator*(coordinate);
  //vector cross product
  coordinate operator^(coordinate);
  //vector parrallel
  bool operator||(coordinate);
  //vector vertical
  bool operator &&(coordinate);
  //vector length
  double operator&();
  double length();
  bool ifNULL();//double-type length may not be judged whether NULL,which may lead to zero-divide error
  //vector angle
  double operator|(coordinate);
}

// A defination of area, a cube in 3D-system
class area{
 private:
  coordinate corner;//the corner point in this area with least x & y & z
  double x;//length by x-axis
  double y;//length by y-axis
  double y;//length by z-axis
 public:
  //determine whether a point is in this area
  bool contain(coordinate);
}

// A defination of point, a basic object with position, vector and accleration.
class point{
 private:
  coordinate position;
  coordinate velosity;
  coordinate acceleration;
 public:
  point();
  ~point();

  coordinate ask_position();
  coordinate ask_velosity();
  coordinate ask_acceleration();
  //move point by certain distance
  void move(coordinate);
  //move point to certain position
  void moveto(coordinate);
}

// A defination of mass point, a basic object in physics model
class mass_point:public point
{
 private:
  double mass;
 public:
  //return the force this mass point is applied
  coordinate ask_force();
}

// A defination of point charge, a basic object in electromagnetic model
class charge_point:public mass_point
{
 private:
  double charge;
 public:
  double ask_charge();
}

// A defination of gravity field, a basic area which practise gravity force, as well as non-inertial force
class gravity_field:public area
{
 private:
  coordinate g;//Gravitation acceleration
}
//A defination of electromagnetic field, a basic area which practise electromagnetic force
class electromagnetic_field:public area
{
 private:
  coordinate E;//electric field intensity
  coordinate B;//magnetic field intensity
}
